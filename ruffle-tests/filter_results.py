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
    """Return a new results dict with ignored tests removed and stats recalculated.

    `ruffle_matched` tests (those where our diffs against Flash's output.txt
    are a subset of Ruffle's diffs against the same file) count as pass in
    the filtered `effective_pass` / `effective_pass_rate` totals. The raw
    `pass` / `pass_rate` only count exact Flash matches, so the two views
    are both visible.
    """
    filtered_tests = [t for t in results.get("tests", []) if t["test"] not in ignored]

    pass_count = sum(1 for t in filtered_tests if t["status"] == "pass")
    ruffle_matched_count = sum(1 for t in filtered_tests if t["status"] == "ruffle_matched")
    total = len(filtered_tests)
    effective_pass = pass_count + ruffle_matched_count

    # Recalculate breakdown (pass and ruffle_matched both count as "not a failure")
    breakdown = {}
    for t in filtered_tests:
        s = t["status"]
        if s not in ("pass", "ruffle_matched"):
            breakdown[s] = breakdown.get(s, 0) + 1
    if ruffle_matched_count:
        breakdown["ruffle_matched"] = ruffle_matched_count

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
        "ruffle_matched": ruffle_matched_count,
        "fail": total - effective_pass,
        "pass_rate": round(100 * pass_count / total, 1) if total else 0,
        "effective_pass": effective_pass,
        "effective_pass_rate": round(100 * effective_pass / total, 1) if total else 0,
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
    orig_ruffle = results.get("ruffle_matched", 0)
    print(f"Original:  {orig_pass}/{orig_total} ({results['pass_rate']}%)"
          + (f" [+{orig_ruffle} ruffle_matched]" if orig_ruffle else ""))
    print(f"Ignored:   {filtered['metadata']['ignored_count']} tests removed")
    if filtered.get("ruffle_matched"):
        print(f"Filtered:  {filtered['pass']}/{filtered['total']}"
              f" ({filtered['pass_rate']}%) raw,"
              f" {filtered['effective_pass']}/{filtered['total']}"
              f" ({filtered['effective_pass_rate']}%) effective")
    else:
        print(f"Filtered:  {filtered['pass']}/{filtered['total']} ({filtered['pass_rate']}%)")
    print(f"Written to {output_path}")


if __name__ == "__main__":
    main()
