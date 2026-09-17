#!/usr/bin/env python3
"""Create the bot MR that syncs HDG product lists.

If an MR from the bot branch is already open, do not create another. The
sync job refreshes the .inc files on that branch instead. A closed MR is
left closed: someone declined it, and its branch may no longer match the
target.
"""

from __future__ import annotations

import os
import sys
from datetime import datetime, timezone
from pathlib import Path

import gitlab
from gitlab.exceptions import GitlabCreateError

DEFAULT_BRANCH = "auto-sync-product-lists"
MR_FOOTER = """

---
*This MR was created by the product-list sync pipeline.*
"""


def require_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        raise SystemExit(f"{name} is required")
    return value


def load_summary() -> str:
    path = Path(os.environ.get("SYNC_OUTPUT_FILE", "product_list_sync_output.txt"))
    text = path.read_text(encoding="utf-8").strip()
    if not text:
        raise SystemExit(f"{path} is empty")
    return text


def open_mrs(project, source: str, target: str):
    """List project-wide, then filter, so a slash in the branch name cannot
    drop the match.
    """
    mrs = project.mergerequests.list(state="opened", get_all=True)
    return [
        mr
        for mr in mrs
        if getattr(mr, "source_branch", "") == source
        and getattr(mr, "target_branch", "") == target
    ]


def main() -> int:
    branch_name = os.environ.get("BRANCH_NAME", DEFAULT_BRANCH)
    gitlab_url = require_env("CI_SERVER_URL")
    project_id = require_env("CI_PROJECT_ID")
    token = os.environ.get("CI_PUSH_TOKEN") or os.environ.get("GITLAB_PUSH_TOKEN")
    if not token:
        raise SystemExit("CI_PUSH_TOKEN (or GITLAB_PUSH_TOKEN) is required to create the MR")
    target_branch = os.environ.get("SYNC_TARGET_BRANCH", "master")

    gl = gitlab.Gitlab(url=gitlab_url, private_token=token)
    project = gl.projects.get(project_id)

    opened = open_mrs(project, branch_name, target_branch)
    if opened:
        mr = opened[0]
        print(
            f"Open MR !{mr.iid} already exists ({mr.web_url}). "
            "Not creating another; the branch refresh is enough."
        )
        return 0

    try:
        project.branches.get(branch_name)
    except gitlab.exceptions.GitlabGetError:
        print(f"Branch {branch_name} does not exist; nothing to open an MR from.")
        return 0

    summary = load_summary()
    title = os.environ.get(
        "SYNC_MR_TITLE",
        f"docs: Sync module and development board lists ({datetime.now(timezone.utc).date()})",
    )
    description = "## Product list updates\n\n" + summary + MR_FOOTER

    assignee_id = None
    assignee_username = os.environ.get("SYNC_MR_ASSIGNEE", "").strip().lstrip("@")
    if assignee_username:
        try:
            users = gl.users.list(username=assignee_username)
            if users:
                assignee_id = users[0].id
                print("Found MR assignee from SYNC_MR_ASSIGNEE")
            else:
                print("SYNC_MR_ASSIGNEE did not match a GitLab user; leaving the MR unassigned")
        except Exception as exc:  # pragma: no cover - network lookup
            print(f"Could not look up assignee: {exc}")

    payload = {
        "source_branch": branch_name,
        "target_branch": target_branch,
        "title": title,
        "description": description,
        "remove_source_branch": False,
    }
    if assignee_id:
        payload["assignee_id"] = assignee_id
    try:
        mr = project.mergerequests.create(payload)
    except GitlabCreateError as exc:
        opened = open_mrs(project, branch_name, target_branch)
        if opened:
            print(
                f"Create hit an existing open MR !{opened[0].iid}; "
                "leaving it in place after the branch refresh."
            )
            return 0
        raise SystemExit(f"Failed to create merge request: {exc}") from exc
    print(f"Created merge request !{mr.iid}: {mr.web_url}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
