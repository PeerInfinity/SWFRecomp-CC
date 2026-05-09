#!/usr/bin/env python3
"""Generate RUFFLE_COMPARISON.md and RUFFLE_COMPARISON_FILTERED.md.

Compares SWFRecomp pass/fail against Ruffle pass/fail across every Ruffle test
suite under ``ruffle-tests/tests/swfs/`` and groups tests into four buckets:

    1. SWFRecomp passes, Ruffle passes
    2. SWFRecomp fails,  Ruffle passes   (← targets to fix)
    3. SWFRecomp passes, Ruffle fails    (← we beat Ruffle here)
    4. SWFRecomp fails,  Ruffle fails

Produces two reports in the project root:

* ``RUFFLE_COMPARISON.md``           — every available test
* ``RUFFLE_COMPARISON_FILTERED.md``  — tests on the relevant ``ignored_tests.txt``
                                       lists are excluded

Detection rules:

* SWFRecomp passes  ⇔ status == ``pass`` in the suite's ``results.json``
* SWFRecomp fails   ⇔ any other status (``output_mismatch`` / ``ruffle_matched``)
* Ruffle fails      ⇔ ``output.ruffle.txt`` exists in the test directory
                       (Ruffle's tooling writes this sidecar when its actual
                       output diverges from the canonical ``output.txt``)
* Ruffle passes     ⇔ no such sidecar exists
"""

import glob
import json
import sys
from datetime import datetime
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
SWF_DIR = RUFFLE_DIR / "tests" / "swfs"
OUTPUT_RAW = BASE_DIR / "RUFFLE_COMPARISON.md"
OUTPUT_FILTERED = BASE_DIR / "RUFFLE_COMPARISON_FILTERED.md"

# Bucket keys (kept stable; used as dict keys and for column ordering)
BUCKETS = ("sr_pass_ru_pass", "sr_fail_ru_pass", "sr_pass_ru_fail", "sr_fail_ru_fail")
BUCKET_LABELS = {
    "sr_pass_ru_pass": "SWFRecomp passes, Ruffle passes",
    "sr_fail_ru_pass": "SWFRecomp fails, Ruffle passes",
    "sr_pass_ru_fail": "SWFRecomp passes, Ruffle fails",
    "sr_fail_ru_fail": "SWFRecomp fails, Ruffle fails",
}
BUCKET_HEADERS = {
    "sr_pass_ru_pass": "SR✓ R✓",
    "sr_fail_ru_pass": "SR✗ R✓",
    "sr_pass_ru_fail": "SR✓ R✗",
    "sr_fail_ru_fail": "SR✗ R✗",
}


def load_json(path):
    try:
        with open(path) as f:
            return json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        return None


def load_ignored_tests(path):
    """Load test names from an ``ignored_tests.txt`` file."""
    ignored = set()
    if not path.exists():
        return ignored
    for line in path.read_text().splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            ignored.add(line)
    return ignored


def format_pct(numerator, denominator):
    if denominator == 0:
        return "0%"
    if numerator == denominator:
        return "100%"
    if numerator == 0:
        return "0%"
    pct = 100 * numerator / denominator
    rounded = round(pct, 1)
    if rounded >= 100.0 or rounded <= 0.0:
        return f"{pct:.2f}%"
    return f"{rounded}%"


def classify_test(test_entry, suite_dir):
    """Return one of the BUCKETS keys for a single test."""
    sr_pass = test_entry["status"] == "pass"
    test_name = test_entry["test"]
    ruffle_sidecar = suite_dir / test_name / "output.ruffle.txt"
    ru_pass = not ruffle_sidecar.exists()

    if sr_pass and ru_pass:
        return "sr_pass_ru_pass"
    if not sr_pass and ru_pass:
        return "sr_fail_ru_pass"
    if sr_pass and not ru_pass:
        return "sr_pass_ru_fail"
    return "sr_fail_ru_fail"


def collect_suites(filtered):
    """Walk the swfs tree and gather classified results per suite.

    Returns a list of dicts, one per suite, each with:
        cat_name, suite_dir, results_rel, metadata, buckets {key: [test_names]}
    """
    results_files = sorted(glob.glob(
        str(SWF_DIR / "**" / "_results" / "results.json"), recursive=True))

    if not results_files:
        print("No _results/results.json files found.", file=sys.stderr)
        sys.exit(1)

    global_ignore = load_ignored_tests(RUFFLE_DIR / "ignored_tests.txt")

    suites = []
    for path_str in results_files:
        results_path = Path(path_str)
        results_dir = results_path.parent
        suite_dir = results_dir.parent  # parent of _results/

        try:
            cat_name = str(suite_dir.relative_to(SWF_DIR))
        except ValueError:
            cat_name = suite_dir.name

        data = load_json(results_path)
        if not data:
            continue

        # Choose the test list (filtered or unfiltered)
        if filtered:
            ignored = global_ignore | load_ignored_tests(suite_dir / "ignored_tests.txt")
            tests = [t for t in data.get("tests", []) if t["test"] not in ignored]
            ignored_count = len(data.get("tests", [])) - len(tests)
        else:
            tests = list(data.get("tests", []))
            ignored_count = 0

        buckets = {b: [] for b in BUCKETS}
        for t in tests:
            buckets[classify_test(t, suite_dir)].append(t["test"])
        for b in buckets:
            buckets[b].sort()

        suites.append({
            "cat_name": cat_name,
            "suite_dir": suite_dir,
            "results_rel": str(results_dir.relative_to(BASE_DIR)),
            "metadata": data.get("metadata", {}),
            "total": len(tests),
            "buckets": buckets,
            "ignored_count": ignored_count,
        })

    return suites


def render_report(suites, filtered):
    md = []
    if filtered:
        md.append("# Ruffle vs SWFRecomp Comparison (Filtered)\n")
        md.append("*Tests on the relevant `ignored_tests.txt` lists are excluded.*  ")
        md.append("*See [RUFFLE_COMPARISON.md](RUFFLE_COMPARISON.md) for unfiltered results.*\n")
    else:
        md.append("# Ruffle vs SWFRecomp Comparison\n")
        md.append("*See [RUFFLE_COMPARISON_FILTERED.md](RUFFLE_COMPARISON_FILTERED.md) "
                  "for results with ignored tests excluded.*\n")

    # Detection methodology
    md.append("Each test is classified using two signals:")
    md.append("")
    md.append("* **SWFRecomp pass** — `status == \"pass\"` in the suite's `results.json` "
              "(other statuses, including `ruffle_matched`, count as fail).")
    md.append("* **Ruffle pass** — no `output.ruffle.txt` sidecar exists in the test "
              "directory (Ruffle's tooling writes that file when its actual output "
              "diverges from the canonical `output.txt`).")
    md.append("")

    # Newest commit/timestamp from any available metadata
    newest_ts = None
    git_sha = None
    for s in suites:
        ts = s["metadata"].get("timestamp")
        if ts and (newest_ts is None or ts > newest_ts):
            newest_ts = ts
            git_sha = s["metadata"].get("git_sha")
    if git_sha:
        md.append(f"**Commit:** `{git_sha[:12]}`  ")
    if newest_ts:
        try:
            dt = datetime.fromisoformat(newest_ts)
            md.append(f"**Date:** {dt.strftime('%Y-%m-%d %H:%M UTC')}")
        except ValueError:
            pass
    md.append("")

    # ----- Summary table -----
    md.append("## Summary\n")
    md.append("| Suite | "
              + " | ".join(BUCKET_HEADERS[b] for b in BUCKETS)
              + " | Total |")
    md.append("|-------|"
              + "|".join("------:" for _ in BUCKETS)
              + "|------:|")

    grand_totals = {b: 0 for b in BUCKETS}
    grand_total = 0
    for s in suites:
        cells = [str(len(s["buckets"][b])) for b in BUCKETS]
        md.append(f"| {s['cat_name']} | " + " | ".join(cells) + f" | {s['total']} |")
        for b in BUCKETS:
            grand_totals[b] += len(s["buckets"][b])
        grand_total += s["total"]

    total_cells = [f"**{grand_totals[b]}**" for b in BUCKETS]
    md.append(f"| **Total** | " + " | ".join(total_cells) + f" | **{grand_total}** |")
    md.append("")

    # Aggregate-level percentages for at-a-glance reading
    md.append("**Bucket totals across all suites:**\n")
    md.append("| Bucket | Tests | Share |")
    md.append("|--------|------:|------:|")
    for b in BUCKETS:
        n = grand_totals[b]
        md.append(f"| {BUCKET_LABELS[b]} | {n} | {format_pct(n, grand_total)} |")
    md.append(f"| **Total** | **{grand_total}** | 100% |")
    md.append("")

    if filtered:
        ignored_total = sum(s["ignored_count"] for s in suites)
        if ignored_total:
            md.append(f"*{ignored_total} tests excluded by `ignored_tests.txt` lists.*\n")

    # ----- Per-suite detail lists -----
    md.append("## Per-Suite Detail\n")
    md.append("Full lists for the three non-trivial buckets are emitted below "
              "(`SR✓ R✓` is omitted to keep these reports tractable).\n")

    detail_buckets = ("sr_fail_ru_pass", "sr_pass_ru_fail", "sr_fail_ru_fail")

    for s in suites:
        md.append(f"### {s['cat_name']}\n")
        line_parts = []
        for b in BUCKETS:
            line_parts.append(f"{BUCKET_HEADERS[b]}: **{len(s['buckets'][b])}**")
        line_parts.append(f"total: **{s['total']}**")
        md.append("- " + " · ".join(line_parts))
        md.append("")

        for b in detail_buckets:
            tests = s["buckets"][b]
            heading = f"#### {BUCKET_LABELS[b]} — {len(tests)} test{'s' if len(tests) != 1 else ''}"
            md.append(heading)
            md.append("")
            if not tests:
                md.append("*(none)*")
                md.append("")
                continue
            for name in tests:
                md.append(f"- `{name}`")
            md.append("")

    return "\n".join(md)


def main():
    for filtered, output_path in ((False, OUTPUT_RAW), (True, OUTPUT_FILTERED)):
        suites = collect_suites(filtered=filtered)
        markdown = render_report(suites, filtered=filtered)
        with open(output_path, "w") as f:
            f.write(markdown)
        print(f"Written {output_path}")
        for s in suites:
            counts = " ".join(f"{BUCKET_HEADERS[b]}={len(s['buckets'][b])}" for b in BUCKETS)
            print(f"  {s['cat_name']}: {counts} (total {s['total']})")


if __name__ == "__main__":
    main()
