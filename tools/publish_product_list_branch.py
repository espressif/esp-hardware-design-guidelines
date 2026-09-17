#!/usr/bin/env python3
"""Publish generated product-list includes through the GitLab commits API.

Host runners do not accept git HTTPS credentials from ASKPASS / extraHeader,
even when CI_PUSH_TOKEN is a valid Project Access Token. The same token can
create commits over the API. Files that already match the destination branch
are left unchanged.
"""

from __future__ import annotations

import os
import sys
from pathlib import Path

import gitlab
from gitlab.exceptions import GitlabGetError

DEFAULT_BRANCH = "auto-sync-product-lists"
COMMIT_SUBJECT = "docs: Sync module and development board lists from product catalog"


def require_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        raise SystemExit(f"{name} is required")
    return value


def file_text(project, path: str, ref: str) -> str | None:
    try:
        blob = project.files.get(file_path=path, ref=ref)
    except GitlabGetError:
        return None
    raw = blob.decode()
    if isinstance(raw, bytes):
        return raw.decode("utf-8")
    return raw


def include_paths(root: Path) -> list[Path]:
    paths = sorted(root.glob("docs/*/*/*-modules.inc"))
    paths.extend(sorted(root.glob("docs/*/*/*-devkits.inc")))
    return paths


def commit_actions(
    root: Path,
    project,
    dest_ref: str,
) -> list[dict[str, str]]:
    """Write generated includes that differ from dest_ref. Skip identical files."""
    actions: list[dict[str, str]] = []
    for path in include_paths(root):
        rel = path.as_posix()
        local = path.read_text(encoding="utf-8")
        remote = file_text(project, rel, dest_ref)
        if remote is None:
            actions.append({"action": "create", "file_path": rel, "content": local})
        elif remote != local:
            actions.append({"action": "update", "file_path": rel, "content": local})
    return actions


def has_open_mr(project, source: str, target: str) -> bool:
    for mr in project.mergerequests.list(state="opened", get_all=True):
        if (
            getattr(mr, "source_branch", "") == source
            and getattr(mr, "target_branch", "") == target
        ):
            return True
    return False


def commit_message() -> str:
    summary = Path(
        os.environ.get("SYNC_OUTPUT_FILE", "product_list_sync_output.txt")
    ).read_text(encoding="utf-8").strip()
    if summary:
        return f"{COMMIT_SUBJECT}\n\n{summary}\n"
    return COMMIT_SUBJECT


def main() -> int:
    token = os.environ.get("CI_PUSH_TOKEN") or os.environ.get("GITLAB_PUSH_TOKEN") or ""
    if not token.strip():
        raise SystemExit("CI_PUSH_TOKEN is required to publish the product-list branch")
    gitlab_url = require_env("CI_SERVER_URL")
    project_id = require_env("CI_PROJECT_ID")
    start_sha = require_env("CI_COMMIT_SHA")
    branch_name = os.environ.get("BRANCH_NAME", DEFAULT_BRANCH).strip()
    target_branch = os.environ.get("SYNC_TARGET_BRANCH", "master").strip()

    gl = gitlab.Gitlab(url=gitlab_url, private_token=token.strip())
    project = gl.projects.get(project_id)

    try:
        project.branches.get(branch_name)
        exists = True
    except GitlabGetError:
        exists = False

    # Keep adding commits while a merge request is open so review history
    # survives. Otherwise restart the branch from this pipeline's commit, or
    # it keeps whatever the last run left behind and the diff grows forever.
    if exists and not has_open_mr(project, branch_name, target_branch):
        print(f"No open MR for {branch_name}; recreating it from {start_sha[:8]}")
        project.branches.delete(branch_name)
        exists = False

    dest_ref = branch_name if exists else start_sha
    actions = commit_actions(Path("."), project, dest_ref)
    if not actions:
        print(f"Generated includes already match {dest_ref}. Nothing to publish.")
        return 0
    payload = {
        "branch": branch_name,
        "commit_message": commit_message(),
        "actions": actions,
        "author_name": "GitLab CI Bot",
        "author_email": "gitlab-ci@espressif.com",
    }
    if exists:
        print(f"Updating existing branch {branch_name}")
    else:
        print(f"Creating {branch_name} from {start_sha[:8]}")
        payload["start_sha"] = start_sha

    commit = project.commits.create(payload)
    sha = getattr(commit, "id", None) or getattr(commit, "short_id", commit)
    print(f"Published {len(actions)} file(s) to {branch_name} as {sha}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
