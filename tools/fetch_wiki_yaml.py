#!/usr/bin/env python3
"""Download wiki catalog YAML via the GitLab API (no git clone)."""

from __future__ import annotations

import os
import sys
import urllib.error
import urllib.parse
import urllib.request
from pathlib import Path

FILES = (
    "docs/en/yaml_data/product_catalog.yaml",
    "docs/en/yaml_data/document_owner.yaml",
)


def require_env(name: str) -> str:
    value = os.environ.get(name, "").strip()
    if not value:
        raise SystemExit(f"{name} is required")
    return value


def main() -> int:
    api = require_env("CI_API_V4_URL").rstrip("/")
    project = urllib.parse.quote(require_env("DOC_TEAM_WIKI_PROJECT"), safe="")
    ref = os.environ.get("WIKI_REF", "master").strip() or "master"
    token = require_env("CI_JOB_TOKEN")
    output = Path(os.environ.get("WIKI_DIR", ".wiki-src"))
    for rel in FILES:
        encoded = urllib.parse.quote(rel, safe="")
        url = f"{api}/projects/{project}/repository/files/{encoded}/raw?ref={urllib.parse.quote(ref)}"
        dest = output / rel
        dest.parent.mkdir(parents=True, exist_ok=True)
        request = urllib.request.Request(url, headers={"JOB-TOKEN": token})
        try:
            with urllib.request.urlopen(request, timeout=60) as response:
                dest.write_bytes(response.read())
        except urllib.error.HTTPError as exc:
            raise SystemExit(f"Failed to fetch {rel} from {ref}: HTTP {exc.code}") from exc
        print(f"Fetched {rel} ({dest.stat().st_size} bytes) from {ref}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
