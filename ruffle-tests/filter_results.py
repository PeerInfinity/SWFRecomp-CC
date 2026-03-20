#!/usr/bin/env python3
"""Filter ruffle test results.json by removing ignored tests.

Reads ignored_tests.txt and produces a filtered copy of results.json
with ignored tests removed and stats recalculated.

Usage:
    python3 filter_results.py results.json [results_filtered.json]

If output path is omitted, writes to results_filtered.json next to the input.
"""

import json
import sys
from pathlib import Path


def load_ignored_tests(path):
    """Load test names from ignored_tests.txt (# comments, blank lines skipped)."""
    ignored = set()
    if not path.exists():
        return ignored
    for line in path.read_text().splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            ignored.add(line)
    return ignored


def filter_results(results, ignored):
    """Return a new results dict with ignored tests removed and stats recalculated."""
    filtered_tests = [t for t in results.get("tests", []) if t["test"] not in ignored]

    pass_count = sum(1 for t in filtered_tests if t["status"] == "pass")
    total = len(filtered_tests)

    # Recalculate breakdown
    breakdown = {}
    for t in filtered_tests:
        if t["status"] != "pass":
            breakdown[t["status"]] = breakdown.get(t["status"], 0) + 1

    # Count how many tests were actually ignored (present in both the ignore list and results)
    ignored_count = sum(1 for t in results.get("tests", []) if t["test"] in ignored)

    filtered = {
        "metadata": {
            **results.get("metadata", {}),
            "ignored_count": ignored_count,
            "filtered": True,
        },
        "total": total,
        "pass": pass_count,
        "fail": total - pass_count,
        "pass_rate": round(100 * pass_count / total, 1) if total else 0,
        "breakdown": {k: v for k, v in breakdown.items() if v},
        "tests": filtered_tests,
    }
    return filtered


def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} results.json [results_filtered.json]")
        sys.exit(1)

    input_path = Path(sys.argv[1])
    if len(sys.argv) >= 3:
        output_path = Path(sys.argv[2])
    else:
        output_path = input_path.parent / "results_filtered.json"

    # Load global ignore list (ruffle-tests/ignored_tests.txt)
    global_ignore_path = Path(__file__).parent / "ignored_tests.txt"

    # Also load per-suite ignore list if it exists.
    # Results live at e.g. .../from_gnash/actionscript.all/_results/results.json
    # Suite ignore list lives at .../from_gnash/actionscript.all/ignored_tests.txt
    # (i.e., the parent of the _results/ directory)
    suite_ignore_path = input_path.parent.parent / "ignored_tests.txt"

    with open(input_path) as f:
        results = json.load(f)

    ignored = load_ignored_tests(global_ignore_path)
    ignored |= load_ignored_tests(suite_ignore_path)

    filtered = filter_results(results, ignored)

    with open(output_path, "w") as f:
        json.dump(filtered, f, indent=2)

    orig_total = results["total"]
    orig_pass = results["pass"]
    print(f"Original:  {orig_pass}/{orig_total} ({results['pass_rate']}%)")
    print(f"Ignored:   {filtered['metadata']['ignored_count']} tests removed")
    print(f"Filtered:  {filtered['pass']}/{filtered['total']} ({filtered['pass_rate']}%)")
    print(f"Written to {output_path}")


if __name__ == "__main__":
    main()
