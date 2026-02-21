#!/usr/bin/env python3
"""Generate a markdown file listing all demos with clickable links,
sorted by when their source code was last updated (newest first).
Graphics demos are listed first, then trace demos.
"""

import json
import os
import subprocess
import sys
from datetime import datetime, timezone

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TESTS_DIR = os.path.join(REPO_ROOT, "SWFRecomp", "tests")
GRAPHICS_DIR = os.path.join(TESTS_DIR, "graphics")
CATALOG_PATH = os.path.join(REPO_ROOT, "docs", "catalog.json")
BASE_URL = "https://peerinfinity.github.io/SWFRecomp-CC"
OUTPUT_PATH = os.path.join(REPO_ROOT, "demo-list.md")


def git_last_modified(path):
    """Get the last commit date for a path, as a datetime."""
    result = subprocess.run(
        ["git", "log", "-1", "--format=%aI", "--", path],
        capture_output=True, text=True, cwd=REPO_ROOT,
    )
    date_str = result.stdout.strip()
    if not date_str:
        return None
    # Parse ISO 8601 with timezone
    return datetime.fromisoformat(date_str)


def git_last_modified_display(path):
    """Get the last commit date as a human-readable string."""
    dt = git_last_modified(path)
    if dt is None:
        return "unknown", datetime.min.replace(tzinfo=timezone.utc)
    return dt.strftime("%Y-%m-%d"), dt


def load_catalog():
    """Load test metadata from catalog.json if available."""
    if not os.path.exists(CATALOG_PATH):
        return {}
    with open(CATALOG_PATH) as f:
        data = json.load(f)
    return {t["id"]: t for t in data.get("tests", [])}


def discover_tests():
    """Find all test directories and their metadata."""
    catalog = load_catalog()
    tests = []

    # Graphics tests
    if os.path.isdir(GRAPHICS_DIR):
        for name in sorted(os.listdir(GRAPHICS_DIR)):
            test_dir = os.path.join(GRAPHICS_DIR, name)
            if not os.path.isdir(test_dir):
                continue
            # Skip the helper module
            if name == "__pycache__":
                continue
            info_path = os.path.join(test_dir, "test_info.json")
            if not os.path.exists(info_path):
                continue

            test_id = f"graphics/{name}"
            rel_path = os.path.relpath(test_dir, REPO_ROOT)
            date_str, date_obj = git_last_modified_display(rel_path)

            # Load test_info.json for description
            with open(info_path) as f:
                info = json.load(f)
            description = info.get("metadata", {}).get("description", "")

            cat_entry = catalog.get(test_id, {})

            tests.append({
                "id": test_id,
                "name": name,
                "type": "graphics",
                "date_str": date_str,
                "date_obj": date_obj,
                "description": description,
                "rel_path": rel_path,
                "demo_url": f"{BASE_URL}/demo.html?test={test_id}",
            })

    # Trace tests (top-level directories in tests/, excluding graphics/)
    for name in sorted(os.listdir(TESTS_DIR)):
        test_dir = os.path.join(TESTS_DIR, name)
        if not os.path.isdir(test_dir):
            continue
        if name in ("graphics", "__pycache__"):
            continue
        info_path = os.path.join(test_dir, "test_info.json")
        if not os.path.exists(info_path):
            continue

        rel_path = os.path.relpath(test_dir, REPO_ROOT)
        date_str, date_obj = git_last_modified_display(rel_path)

        with open(info_path) as f:
            info = json.load(f)
        description = info.get("metadata", {}).get("description", "")

        tests.append({
            "id": name,
            "name": name,
            "type": "trace",
            "date_str": date_str,
            "date_obj": date_obj,
            "description": description,
            "rel_path": rel_path,
            "demo_url": f"{BASE_URL}/demo.html?test={name}",
        })

    return tests


def generate_markdown(tests):
    """Generate the markdown content."""
    graphics = [t for t in tests if t["type"] == "graphics"]
    traces = [t for t in tests if t["type"] == "trace"]

    # Sort each group by date descending (newest first)
    graphics.sort(key=lambda t: t["date_obj"], reverse=True)
    traces.sort(key=lambda t: t["date_obj"], reverse=True)

    lines = []
    now = datetime.now().strftime("%Y-%m-%d")
    lines.append("# Live Demo List")
    lines.append("")
    lines.append(f"**Generated**: {now}")
    lines.append("")
    lines.append(f"**Total demos**: {len(tests)} ({len(graphics)} graphics, {len(traces)} trace)")
    lines.append("")

    # Graphics demos
    lines.append("## Graphics Demos")
    lines.append("")
    lines.append("| Demo | Description | Last Updated |")
    lines.append("|------|-------------|--------------|")
    for t in graphics:
        lines.append(
            f"| [{t['name']}]({t['demo_url']}) | {t['description']} | {t['date_str']} |"
        )
    lines.append("")

    # Trace demos
    lines.append("## Trace Demos")
    lines.append("")
    lines.append("| Demo | Description | Last Updated |")
    lines.append("|------|-------------|--------------|")
    for t in traces:
        lines.append(
            f"| [{t['name']}]({t['demo_url']}) | {t['description']} | {t['date_str']} |"
        )
    lines.append("")

    return "\n".join(lines)


def main():
    tests = discover_tests()
    md = generate_markdown(tests)

    with open(OUTPUT_PATH, "w") as f:
        f.write(md)

    graphics_count = sum(1 for t in tests if t["type"] == "graphics")
    trace_count = sum(1 for t in tests if t["type"] == "trace")
    print(f"Generated {OUTPUT_PATH}")
    print(f"  {graphics_count} graphics demos, {trace_count} trace demos")


if __name__ == "__main__":
    main()
