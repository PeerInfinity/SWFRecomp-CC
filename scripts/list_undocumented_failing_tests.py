#!/usr/bin/env python3
"""
List failing tests that aren't covered by any investigation plan doc's
`<!-- TESTS: ... -->` header.

For each suite with an investigation directory, parse all plan docs, build
a reverse index (test name → [docs]), then enumerate tests in the suite's
results that are failing AND not present in the index.

Usage:
  python3 scripts/list_undocumented_failing_tests.py               # all suites
  python3 scripts/list_undocumented_failing_tests.py --suite=avm1  # one suite
  python3 scripts/list_undocumented_failing_tests.py --filtered    # use results_filtered.json where available

Output: plain-text list, grouped by suite, with match rates and status.
"""

import argparse
import json
import sys
from pathlib import Path

# Reuse the TESTS-comment parser from the results markdown generator.
_SCRIPT_DIR = Path(__file__).parent
sys.path.insert(0, str(_SCRIPT_DIR))
from generate_ruffle_results_markdown import build_investigation_index

BASE_DIR = _SCRIPT_DIR.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"

# Suite registry. Each entry maps to (investigation_dir, results.json, results_filtered.json).
# Paths are relative to RUFFLE_DIR.
SUITES: dict[str, dict] = {
    "avm1": {
        "inv": "tests/swfs/avm1/_investigation",
        "results": "tests/swfs/avm1/_results/results.json",
        "results_filtered": "tests/swfs/avm1/_results/results_filtered.json",
    },
    "gnash/actionscript.all": {
        "inv": "tests/swfs/from_gnash/_investigation",
        "results": "tests/swfs/from_gnash/actionscript.all/_results/results.json",
        "results_filtered": "tests/swfs/from_gnash/actionscript.all/_results/results_filtered.json",
    },
    "gnash/misc-mtasc.all": {
        "inv": "tests/swfs/from_gnash/_investigation",
        "results": "tests/swfs/from_gnash/misc-mtasc.all/_results/results.json",
        "results_filtered": "tests/swfs/from_gnash/misc-mtasc.all/_results/results_filtered.json",
    },
    "gnash/misc-swfmill.all": {
        "inv": "tests/swfs/from_gnash/_investigation",
        "results": "tests/swfs/from_gnash/misc-swfmill.all/_results/results.json",
        "results_filtered": None,
    },
    "gnash/misc-ming.all": {
        "inv": "tests/swfs/from_gnash/_investigation",
        "results": "tests/swfs/from_gnash/misc-ming.all/_results/results.json",
        "results_filtered": None,
    },
    "gnash/misc-swfc.all": {
        "inv": "tests/swfs/from_gnash/_investigation",
        "results": "tests/swfs/from_gnash/misc-swfc.all/_results/results.json",
        "results_filtered": None,
    },
    "shumway/flat": {
        "inv": "tests/swfs/from_shumway/_investigation",
        "results": "tests/swfs/from_shumway/_results/results.json",
        "results_filtered": "tests/swfs/from_shumway/_results/results_filtered.json",
    },
    "shumway/avm1": {
        "inv": "tests/swfs/from_shumway/_investigation",
        "results": "tests/swfs/from_shumway/avm1/_results/results.json",
        "results_filtered": "tests/swfs/from_shumway/avm1/_results/results_filtered.json",
    },
}


def match_rate(test: dict) -> float | None:
    lines = test.get("lines")
    if not lines:
        return None
    total = max(lines["actual_lines"], lines["expected_lines"])
    if total == 0:
        return 100.0
    return lines["matching_lines"] / total * 100


def _FAILING_STATUSES():
    # `ruffle_matched` is effectively passing — exclude it.
    return {"output_mismatch", "compile_fail", "runtime_error", "runtime_segfault", "timeout"}


def list_suite(suite_name: str, cfg: dict, prefer_filtered: bool) -> tuple[list[dict], int, int]:
    """Returns (undocumented_failing_tests, total_failing, total_covered_failing)."""
    inv_dir = RUFFLE_DIR / cfg["inv"]
    results_path = RUFFLE_DIR / cfg["results"]
    filtered_path = (RUFFLE_DIR / cfg["results_filtered"]) if cfg.get("results_filtered") else None

    chosen = filtered_path if (prefer_filtered and filtered_path and filtered_path.exists()) else results_path
    if not chosen.exists():
        return [], 0, 0

    with open(chosen) as f:
        data = json.load(f)

    test_to_docs, _doc_list = build_investigation_index(inv_dir if inv_dir.exists() else None)

    failing_statuses = _FAILING_STATUSES()
    failing = [t for t in data["tests"] if t.get("status") in failing_statuses]

    undocumented = [t for t in failing if t["test"] not in test_to_docs]
    covered = len(failing) - len(undocumented)

    # Sort by match-rate descending (near-passing first; None last).
    def _sort_key(t):
        mr = match_rate(t)
        return (mr if mr is not None else -1, t["test"])

    undocumented.sort(key=_sort_key, reverse=True)
    return undocumented, len(failing), covered


def print_suite(suite_name: str, undocumented: list[dict], total_failing: int, covered: int, results_label: str):
    header = f"{suite_name}  ({results_label})"
    print(f"=== {header} ===")
    print(f"failing: {total_failing}  covered by plan doc: {covered}  undocumented: {len(undocumented)}")
    print()
    if not undocumented:
        print("  (no undocumented failures)")
        print()
        return
    for t in undocumented:
        mr = match_rate(t)
        mr_str = f"{mr:5.1f}%" if mr is not None else "   -- "
        status = t.get("status", "?")
        lines = t.get("lines", {})
        m = lines.get("matching_lines", 0)
        e = lines.get("expected_lines", 0)
        line_str = f"{m}/{e}" if e else ""
        print(f"  {mr_str}  {status:<18} {line_str:<12} {t['test']}")
    print()


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[1])
    ap.add_argument(
        "--suite",
        choices=list(SUITES.keys()) + ["all"],
        default="all",
        help="Which suite to process (default: all).",
    )
    ap.add_argument(
        "--filtered",
        action="store_true",
        help="Prefer results_filtered.json where available.",
    )
    ap.add_argument(
        "--tests-only",
        action="store_true",
        help="Print only the bare test names (one per line), suitable for piping.",
    )
    args = ap.parse_args()

    suites = list(SUITES.items()) if args.suite == "all" else [(args.suite, SUITES[args.suite])]

    all_undocumented: list[tuple[str, dict]] = []
    for suite_name, cfg in suites:
        undoc, total, covered = list_suite(suite_name, cfg, prefer_filtered=args.filtered)
        if args.tests_only:
            for t in undoc:
                all_undocumented.append((suite_name, t))
        else:
            label = "filtered" if (args.filtered and cfg.get("results_filtered")) else "unfiltered"
            print_suite(suite_name, undoc, total, covered, label)

    if args.tests_only:
        for suite_name, t in all_undocumented:
            print(f"{suite_name}\t{t['test']}")


if __name__ == "__main__":
    main()
