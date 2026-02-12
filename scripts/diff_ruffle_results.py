#!/usr/bin/env python3
"""Compare two Ruffle test results JSON files and produce diff reports.

Supports partial/incomplete new results (e.g. from an in-progress run).
Tests only present in old results are ignored when --partial is used.

Can be used as a library:
    from diff_ruffle_results import diff_results, format_summary_line
"""

import argparse
import json
import sys
from pathlib import Path


def load_results(path):
    with open(path) as f:
        return json.load(f)


def build_test_map(results):
    """Build dict of test_name -> test entry."""
    return {t["test"]: t for t in results.get("tests", [])}


def diff_results(old, new, partial=False):
    """Compare old and new results.

    If partial=True, tests in old but not in new are treated as
    "not yet run" and excluded from the diff (instead of "removed").
    """
    old_map = build_test_map(old)
    new_map = build_test_map(new)

    if partial:
        # Only consider tests that appear in the new results
        all_tests = sorted(new_map.keys())
    else:
        all_tests = sorted(set(old_map) | set(new_map))

    changes = []
    for name in all_tests:
        old_t = old_map.get(name)
        new_t = new_map.get(name)

        if old_t is None:
            # Added test
            changes.append({
                "test": name,
                "change_type": "added",
                "old_status": None,
                "new_status": new_t["status"],
                "old_lines": None,
                "new_lines": new_t.get("lines"),
            })
        elif new_t is None:
            # Removed test (only reachable when partial=False)
            changes.append({
                "test": name,
                "change_type": "removed",
                "old_status": old_t["status"],
                "new_status": None,
                "old_lines": old_t.get("lines"),
                "new_lines": None,
            })
        else:
            old_status = old_t["status"]
            new_status = new_t["status"]
            old_lines = old_t.get("lines")
            new_lines = new_t.get("lines")

            status_changed = old_status != new_status
            lines_changed = old_lines != new_lines

            if status_changed or lines_changed:
                changes.append({
                    "test": name,
                    "change_type": "changed",
                    "old_status": old_status,
                    "new_status": new_status,
                    "old_lines": old_lines,
                    "new_lines": new_lines,
                })

    old_meta = old.get("metadata", {})
    new_meta = new.get("metadata", {})

    newly_passing = sum(
        1 for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] != "pass"
        and c["new_status"] == "pass"
    )
    newly_failing = sum(
        1 for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] == "pass"
        and c["new_status"] != "pass"
    )
    added = sum(1 for c in changes if c["change_type"] == "added")
    removed = sum(1 for c in changes if c["change_type"] == "removed")
    status_changed = sum(
        1 for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] != c["new_status"]
    )

    # For partial runs, "unchanged" counts tests present in both with same result
    compared_count = len([n for n in all_tests if n in old_map and n in new_map])
    changed_both = len([c for c in changes if c["change_type"] == "changed"])

    report = {
        "metadata": {
            "old_timestamp": old_meta.get("timestamp"),
            "old_git_sha": old_meta.get("git_sha"),
            "new_timestamp": new_meta.get("timestamp"),
            "new_git_sha": new_meta.get("git_sha"),
            "partial": partial,
        },
        "summary": {
            "old_pass": old.get("pass", 0),
            "old_total": old.get("total", 0),
            "old_pass_rate": old.get("pass_rate", 0),
            "new_pass": new.get("pass", 0),
            "new_total": new.get("total", 0),
            "new_pass_rate": new.get("pass_rate", 0),
            "newly_passing": newly_passing,
            "newly_failing": newly_failing,
            "status_changed": status_changed,
            "unchanged": compared_count - changed_both,
            "added": added,
            "removed": removed,
        },
        "changes": changes,
    }
    return report


def format_summary_line(diff):
    """Return a compact one-line summary string for terminal output."""
    s = diff["summary"]

    result = f"pass: {s['new_pass']}/{s['new_total']}"

    delta_parts = []
    if s["newly_passing"] > 0:
        delta_parts.append(f"+{s['newly_passing']} newly passing")
    if s["newly_failing"] > 0:
        delta_parts.append(f"-{s['newly_failing']} regressed")
    if s["status_changed"] > 0:
        # Count status changes that aren't already covered by newly_passing/failing
        other = s["status_changed"] - s["newly_passing"] - s["newly_failing"]
        if other > 0:
            delta_parts.append(f"{other} other status changes")

    if delta_parts:
        result += f"  |  vs prev: {', '.join(delta_parts)}"
    else:
        result += "  |  vs prev: no changes"

    return result


def format_lines(lines):
    if lines is None:
        return "-"
    return f"{lines['matching_lines']}/{lines['expected_lines']}"


def delta_str(old_val, new_val):
    d = new_val - old_val
    if d > 0:
        return f"+{d}"
    elif d < 0:
        return str(d)
    return "0"


def generate_markdown(diff):
    meta = diff["metadata"]
    s = diff["summary"]
    changes = diff["changes"]

    lines = []
    lines.append("# Ruffle Test Results Diff\n")

    old_sha = meta.get("old_git_sha") or "unknown"
    new_sha = meta.get("new_git_sha") or "unknown"
    old_ts = meta.get("old_timestamp") or "unknown"
    new_ts = meta.get("new_timestamp") or "unknown"

    lines.append(f"**Previous:** `{old_sha[:12]}` ({old_ts})")
    lines.append(f"**Current:** `{new_sha[:12]}` ({new_ts})")
    if meta.get("partial"):
        lines.append(f"*Partial run: {s['new_total']} of {s['old_total']} tests completed*")
    lines.append("")

    # Summary
    pass_delta = delta_str(s["old_pass"], s["new_pass"])
    total_delta = delta_str(s["old_total"], s["new_total"])

    lines.append("## Summary\n")
    lines.append("| Metric | Previous | Current | Delta |")
    lines.append("|--------|----------|---------|-------|")
    lines.append(f"| Passing | {s['old_pass']} | {s['new_pass']} | {pass_delta} |")
    lines.append(f"| Total | {s['old_total']} | {s['new_total']} | {total_delta} |")
    lines.append(f"| Pass rate | {s['old_pass_rate']}% | {s['new_pass_rate']}% | {delta_str(s['old_pass_rate'], s['new_pass_rate'])}% |")
    lines.append("")

    if s["newly_passing"] == 0 and s["newly_failing"] == 0 and s["status_changed"] == 0 and s["added"] == 0 and s["removed"] == 0:
        # Check if only line count changes
        line_only = [c for c in changes if c["change_type"] == "changed" and c["old_status"] == c["new_status"]]
        if not line_only:
            lines.append("No changes detected.\n")
            return "\n".join(lines)

    # Newly passing
    newly_passing = [
        c for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] != "pass"
        and c["new_status"] == "pass"
    ]
    if newly_passing:
        lines.append(f"## Newly Passing ({len(newly_passing)})\n")
        lines.append("| Test | Previous Status | Lines (prev) | Lines (now) |")
        lines.append("|------|----------------|--------------|-------------|")
        for c in sorted(newly_passing, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['old_status']} | {format_lines(c['old_lines'])} | {format_lines(c['new_lines'])} |")
        lines.append("")

    # Newly failing
    newly_failing = [
        c for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] == "pass"
        and c["new_status"] != "pass"
    ]
    if newly_failing:
        lines.append(f"## Newly Failing ({len(newly_failing)})\n")
        lines.append("| Test | New Status | Lines (prev) | Lines (now) |")
        lines.append("|------|-----------|--------------|-------------|")
        for c in sorted(newly_failing, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['new_status']} | {format_lines(c['old_lines'])} | {format_lines(c['new_lines'])} |")
        lines.append("")

    # Status changed (neither old nor new is pass)
    status_changed = [
        c for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] != c["new_status"]
        and c["old_status"] != "pass"
        and c["new_status"] != "pass"
    ]
    if status_changed:
        lines.append(f"## Status Changed ({len(status_changed)})\n")
        lines.append("| Test | Previous | Current | Lines (prev) | Lines (now) |")
        lines.append("|------|----------|---------|--------------|-------------|")
        for c in sorted(status_changed, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['old_status']} | {c['new_status']} | {format_lines(c['old_lines'])} | {format_lines(c['new_lines'])} |")
        lines.append("")

    # Added tests
    added = [c for c in changes if c["change_type"] == "added"]
    if added:
        lines.append(f"## Added Tests ({len(added)})\n")
        lines.append("| Test | Status | Lines |")
        lines.append("|------|--------|-------|")
        for c in sorted(added, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['new_status']} | {format_lines(c['new_lines'])} |")
        lines.append("")

    # Removed tests
    removed = [c for c in changes if c["change_type"] == "removed"]
    if removed:
        lines.append(f"## Removed Tests ({len(removed)})\n")
        lines.append("| Test | Previous Status | Lines |")
        lines.append("|------|----------------|-------|")
        for c in sorted(removed, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['old_status']} | {format_lines(c['old_lines'])} |")
        lines.append("")

    # Line count changes (same status)
    line_changes = [
        c for c in changes
        if c["change_type"] == "changed"
        and c["old_status"] == c["new_status"]
    ]
    if line_changes:
        lines.append(f"## Line Count Changed ({len(line_changes)})\n")
        lines.append("| Test | Status | Lines (prev) | Lines (now) |")
        lines.append("|------|--------|--------------|-------------|")
        for c in sorted(line_changes, key=lambda x: x["test"]):
            lines.append(f"| `{c['test']}` | {c['new_status']} | {format_lines(c['old_lines'])} | {format_lines(c['new_lines'])} |")
        lines.append("")

    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(
        description="Diff two Ruffle test result files.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""\
examples:
  %(prog)s previous.json current.json
  %(prog)s previous.json current.json --partial --summary-only
  %(prog)s old.json new.json --json=diff.json --markdown=diff.md
""",
    )
    parser.add_argument("old", help="Path to previous results JSON")
    parser.add_argument("new", help="Path to current results JSON")
    parser.add_argument("--partial", action="store_true",
                        help="Treat new results as incomplete (ignore tests not yet run)")
    parser.add_argument("--summary-only", action="store_true",
                        help="Print only a one-line summary (for embedding in other tools)")
    parser.add_argument("--json", default="ruffle-tests/results_diff.json",
                        help="Output path for diff JSON (default: ruffle-tests/results_diff.json)")
    parser.add_argument("--markdown", default="ruffle-results-diff.md",
                        help="Output path for diff markdown (default: ruffle-results-diff.md)")
    parser.add_argument("--no-write", action="store_true",
                        help="Don't write JSON/markdown files, only print to stdout")

    args = parser.parse_args()

    old = load_results(args.old)
    new = load_results(args.new)

    diff = diff_results(old, new, partial=args.partial)

    if args.summary_only:
        print(format_summary_line(diff))
        return

    if not args.no_write:
        # Write JSON
        json_path = Path(args.json)
        json_path.parent.mkdir(parents=True, exist_ok=True)
        with open(json_path, "w") as f:
            json.dump(diff, f, indent=2)
        print(f"Wrote diff JSON: {json_path}")

        # Write markdown
        md_path = Path(args.markdown)
        md_path.parent.mkdir(parents=True, exist_ok=True)
        md = generate_markdown(diff)
        with open(md_path, "w") as f:
            f.write(md)
        print(f"Wrote diff markdown: {md_path}")

    # Print summary
    s = diff["summary"]
    print(f"\nPass: {s['old_pass']} -> {s['new_pass']} ({delta_str(s['old_pass'], s['new_pass'])})")
    print(f"Total: {s['old_total']} -> {s['new_total']} ({delta_str(s['old_total'], s['new_total'])})")
    print(f"Newly passing: {s['newly_passing']}")
    print(f"Newly failing: {s['newly_failing']}")
    print(f"Status changed: {s['status_changed']}")
    print(f"Added: {s['added']}, Removed: {s['removed']}")
    print(f"Unchanged: {s['unchanged']}")


if __name__ == "__main__":
    main()
