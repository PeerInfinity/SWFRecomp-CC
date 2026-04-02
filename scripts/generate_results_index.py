#!/usr/bin/env python3
"""Generate RUFFLE_RESULTS.md and RUFFLE_RESULTS_FILTERED.md in the project root.

Scans for _results/results.json under ruffle-tests/tests/swfs/ and produces
two summary documents: one for unfiltered (raw) results and one for filtered.
"""

import glob
import json
import sys
from datetime import datetime, timezone
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
SWF_DIR = RUFFLE_DIR / "tests" / "swfs"
OUTPUT_RAW = BASE_DIR / "RUFFLE_RESULTS.md"
OUTPUT_FILTERED = BASE_DIR / "RUFFLE_RESULTS_FILTERED.md"


def load_json(path):
    try:
        with open(path) as f:
            return json.load(f)
    except (FileNotFoundError, json.JSONDecodeError):
        return None


def format_pct(numerator, denominator):
    """Format a percentage, avoiding misleading 100.0% or 0.0% when not exact."""
    if denominator == 0:
        return "0%"
    if numerator == denominator:
        return "100%"
    if numerator == 0:
        return "0%"
    pct = 100 * numerator / denominator
    # Use 1 decimal place by default, but add precision if it would round to 0 or 100
    rounded = round(pct, 1)
    if rounded >= 100.0:
        return f"{pct:.2f}%"
    if rounded <= 0.0:
        return f"{pct:.2f}%"
    return f"{rounded}%"


def format_duration(seconds):
    if seconds < 60:
        return f"{seconds:.0f}s"
    m, s = divmod(int(seconds), 60)
    if m < 60:
        return f"{m}m{s:02d}s"
    h, m = divmod(m, 60)
    return f"{h}h{m:02d}m{s:02d}s"


def compute_line_stats(tests):
    """Compute aggregate line-level matching stats from individual test entries."""
    total_expected = 0
    total_matching = 0
    total_actual = 0
    for t in tests:
        lines = t.get("lines")
        if not lines:
            continue
        total_expected += lines.get("expected_lines", 0)
        total_matching += lines.get("matching_lines", 0)
        total_actual += lines.get("actual_lines", 0)
    return total_matching, total_expected, total_actual


def count_near_passing(tests, threshold=0.8):
    """Count output_mismatch tests where match rate >= threshold."""
    near = []
    for t in tests:
        if t.get("status") != "output_mismatch":
            continue
        lines = t.get("lines")
        if not lines or lines.get("expected_lines", 0) == 0:
            continue
        rate = lines["matching_lines"] / lines["expected_lines"]
        if rate >= threshold:
            near.append((t["test"], rate))
    return near


def load_all_suites():
    """Load all test suite data from disk."""
    results_files = sorted(glob.glob(
        str(SWF_DIR / "**" / "_results" / "results.json"), recursive=True))

    if not results_files:
        print("No _results/results.json files found.", file=sys.stderr)
        sys.exit(1)

    rows = []
    for path_str in results_files:
        path = Path(path_str)
        results_dir = path.parent
        category_dir = results_dir.parent

        try:
            cat_name = str(category_dir.relative_to(SWF_DIR))
        except ValueError:
            cat_name = category_dir.name

        data = load_json(path)
        if not data:
            continue

        rows.append({
            "cat_name": cat_name,
            "results_rel": str(results_dir.relative_to(BASE_DIR)),
            "data": data,
            "filtered": load_json(results_dir / "results_filtered.json"),
            "diff": load_json(results_dir / "results_diff.json"),
            "flash": load_json(results_dir / "results_flash.json"),
        })

    return rows


def generate_report(rows, filtered):
    """Generate a markdown report.

    If filtered=True, uses results_filtered.json data and skips suites without it.
    If filtered=False, uses results.json data.
    """
    lines = []

    # Pick the data source for each row
    suite_rows = []
    for row in rows:
        if filtered:
            d = row["filtered"]
            if not d:
                continue
        else:
            d = row["data"]
        suite_rows.append((row, d))

    if not suite_rows:
        return None

    # --- Header ---
    if filtered:
        lines.append("# Ruffle Test Results (Filtered)\n")
        lines.append("*Tests on the [ignored list](ruffle-tests/ignored_tests.txt) are excluded.*  ")
        lines.append("*See [RUFFLE_RESULTS.md](RUFFLE_RESULTS.md) for unfiltered results.*\n")
    else:
        lines.append("# Ruffle Test Results\n")
        lines.append("*See [RUFFLE_RESULTS_FILTERED.md](RUFFLE_RESULTS_FILTERED.md) "
                      "for results with ignored tests excluded.*\n")

    newest_ts = None
    git_sha = None
    total_duration = 0
    for row, d in suite_rows:
        meta = d.get("metadata", {})
        ts = meta.get("timestamp")
        if ts:
            if newest_ts is None or ts > newest_ts:
                newest_ts = ts
                git_sha = meta.get("git_sha")
        total_duration += meta.get("duration_seconds", 0)

    if git_sha:
        lines.append(f"**Commit:** `{git_sha[:12]}`  ")
    if newest_ts:
        try:
            dt = datetime.fromisoformat(newest_ts)
            lines.append(f"**Date:** {dt.strftime('%Y-%m-%d %H:%M UTC')}  ")
        except ValueError:
            pass
    if total_duration:
        lines.append(f"**Total duration:** {format_duration(total_duration)}")
    lines.append("")

    # --- Main results table ---
    lines.append("## Results by Suite\n")
    lines.append("| Suite | Pass | Total | Rate | Report |")
    lines.append("|-------|-----:|------:|-----:|--------|")

    grand_pass = 0
    grand_total = 0
    grand_ignored = 0

    for row, d in suite_rows:
        passed = d.get("pass", 0)
        total = d.get("total", 0)
        grand_pass += passed
        grand_total += total

        rel = row["results_rel"]
        if filtered:
            report_link = f"[details]({rel}/results_filtered.md)"
        else:
            report_link = f"[details]({rel}/results.md)"

        meta = d.get("metadata", {})
        note = ""
        if meta.get("incomplete"):
            note = " ⚠️"
        if filtered:
            grand_ignored += meta.get("ignored_count", 0)

        rate = format_pct(passed, total)
        lines.append(f"| {row['cat_name']} | {passed} | {total} | {rate}{note} | {report_link} |")

    grand_rate = format_pct(grand_pass, grand_total)
    lines.append(f"| **Total** | **{grand_pass}** | **{grand_total}** | **{grand_rate}** | |")
    if filtered and grand_ignored:
        lines.append(f"\n*{grand_ignored} tests ignored.*")
    lines.append("")

    # --- Incomplete run warnings ---
    incomplete = [(row, d) for row, d in suite_rows if d.get("metadata", {}).get("incomplete")]
    if incomplete:
        lines.append("### ⚠️ Incomplete Runs\n")
        for row, d in incomplete:
            meta = d["metadata"]
            ms = meta.get("missing_shards", 0)
            es = meta.get("expected_shards", 0)
            lines.append(f"- **{row['cat_name']}**: {es - ms}/{es} shards produced results ({ms} missing)")
        lines.append("")

    # --- Line-level accuracy ---
    lines.append("## Line-Level Accuracy\n")
    lines.append("| Suite | Matching | Expected | Accuracy |")
    lines.append("|-------|--------:|---------:|---------:|")

    all_matching = 0
    all_expected = 0
    for row, d in suite_rows:
        tests = d.get("tests", [])
        matching, expected, _ = compute_line_stats(tests)
        all_matching += matching
        all_expected += expected
        acc = format_pct(matching, expected)
        lines.append(f"| {row['cat_name']} | {matching:,} | {expected:,} | {acc} |")

    all_acc = format_pct(all_matching, all_expected)
    lines.append(f"| **Total** | **{all_matching:,}** | **{all_expected:,}** | **{all_acc}** |")
    lines.append("")

    # --- Failure breakdown ---
    all_categories = set()
    for _, d in suite_rows:
        for k in d.get("breakdown", {}):
            all_categories.add(k)
    all_categories = sorted(all_categories)

    if all_categories:
        lines.append("## Failure Breakdown\n")
        header = "| Suite | " + " | ".join(all_categories) + " |"
        sep = "|-------|" + "|".join("-" * (len(c) + 2) + ":" for c in all_categories) + "|"
        lines.append(header)
        lines.append(sep)

        totals = {c: 0 for c in all_categories}
        for row, d in suite_rows:
            bd = d.get("breakdown", {})
            cells = []
            for c in all_categories:
                v = bd.get(c, 0)
                totals[c] += v
                cells.append(str(v) if v else "-")
            lines.append(f"| {row['cat_name']} | " + " | ".join(cells) + " |")

        total_cells = [f"**{totals[c]}**" if totals[c] else "-" for c in all_categories]
        lines.append(f"| **Total** | " + " | ".join(total_cells) + " |")
        lines.append("")

    # --- Near-passing tests ---
    all_near = []
    for row, d in suite_rows:
        tests = d.get("tests", [])
        near = count_near_passing(tests, 0.8)
        for test_name, rate in near:
            all_near.append((row["cat_name"], test_name, rate))

    if all_near:
        lines.append("## Near-Passing Tests (≥80% line match)\n")
        lines.append("Tests with `output_mismatch` status but ≥80% of expected lines matching.\n")
        lines.append("| Suite | Test | Match Rate |")
        lines.append("|-------|------|----------:|")
        for cat, test_name, rate in sorted(all_near, key=lambda x: -x[2]):
            lines.append(f"| {cat} | {test_name} | {rate:.0%} |")
        lines.append("")

    # --- Diff since last run (unfiltered only) ---
    if not filtered:
        has_diff = any(r["diff"] for r in rows)
        if has_diff:
            lines.append("## Changes Since Last Run\n")

            any_changes = False
            for row in rows:
                dd = row["diff"]
                if not dd:
                    continue
                summary = dd.get("summary", {})
                newly_passing = summary.get("newly_passing", 0)
                newly_failing = summary.get("newly_failing", 0)
                inc_mismatches = summary.get("increased_mismatches", 0)
                dec_mismatches = summary.get("decreased_mismatches", 0)

                if newly_passing or newly_failing or inc_mismatches or dec_mismatches:
                    if not any_changes:
                        lines.append("| Suite | Newly Passing | Newly Failing | Lines Improved | Lines Regressed |")
                        lines.append("|-------|-------------:|-------------:|--------------:|----------------:|")
                        any_changes = True

                    lines.append(
                        f"| {row['cat_name']} | {newly_passing or '-'} | {newly_failing or '-'} "
                        f"| {dec_mismatches or '-'} | {inc_mismatches or '-'} |")

            if not any_changes:
                lines.append("*No changes since last run.*")

            # List individual newly passing/failing tests
            for row in rows:
                dd = row["diff"]
                if not dd:
                    continue
                changes = dd.get("changes", [])
                newly_passing = [c for c in changes if c.get("change_type") == "changed"
                                 and c.get("new_status") == "pass"
                                 and c.get("old_status") != "pass"]
                newly_failing = [c for c in changes if c.get("change_type") == "changed"
                                 and c.get("old_status") == "pass"
                                 and c.get("new_status") != "pass"]
                if newly_passing:
                    lines.append(f"\n**{row['cat_name']} — newly passing:** "
                                 + ", ".join(f"`{c['test']}`" for c in newly_passing))
                if newly_failing:
                    lines.append(f"\n**{row['cat_name']} — newly failing:** "
                                 + ", ".join(f"`{c['test']}`" for c in newly_failing))

            # Show commit range
            for row in rows:
                dd = row["diff"]
                if not dd:
                    continue
                meta = dd.get("metadata", {})
                old_sha = meta.get("old_git_sha", "")
                new_sha = meta.get("new_git_sha", "")
                if old_sha and new_sha and old_sha != new_sha:
                    lines.append(f"\n*Comparing `{old_sha[:12]}` → `{new_sha[:12]}`*")
                    break

            lines.append("")

    # --- Flash-spec results ---
    flash_rows = [(r["cat_name"], r["flash"]) for r in rows if r["flash"]]
    if flash_rows:
        lines.append("## Flash-Spec Results\n")
        lines.append("Tests verified against Flash's actual output (`output.flash.txt`).\n")
        lines.append("| Suite | Pass | Total | Rate |")
        lines.append("|-------|-----:|------:|-----:|")
        for cat_name, fd in flash_rows:
            f_pass = fd.get("pass", 0)
            f_total = fd.get("total", 0)
            lines.append(f"| {cat_name} | {f_pass} | {f_total} | {format_pct(f_pass, f_total)} |")
        lines.append("")

    # --- Per-suite details ---
    lines.append("## Per-Suite Details\n")
    for row, d in suite_rows:
        meta = d.get("metadata", {})
        tests = d.get("tests", [])

        lines.append(f"### {row['cat_name']}\n")

        lines.append(f"- **Pass:** {d['pass']}/{d['total']} ({format_pct(d['pass'], d['total'])})")

        if filtered:
            ignored = meta.get("ignored_count", 0)
            if ignored:
                lines.append(f"- **Ignored:** {ignored} tests")

        if meta.get("duration_seconds"):
            dur_str = format_duration(meta["duration_seconds"])
            shards = meta.get("shards")
            if shards and shards > 1:
                dur_str += f" across {shards} shards"
            lines.append(f"- **Duration:** {dur_str}")

        matching, expected, actual = compute_line_stats(tests)
        if expected:
            acc = format_pct(matching, expected)
            lines.append(f"- **Lines:** {matching:,}/{expected:,} matching ({acc})")

        durations = [t["duration"] for t in tests if "duration" in t]
        if durations:
            avg_dur = sum(durations) / len(durations)
            max_dur = max(durations)
            max_test = next(t["test"] for t in tests if t.get("duration") == max_dur)
            lines.append(f"- **Avg test duration:** {avg_dur:.1f}s — slowest: `{max_test}` ({max_dur:.1f}s)")

        lines.append("")

    return "\n".join(lines)


def main():
    rows = load_all_suites()

    raw_md = generate_report(rows, filtered=False)
    with open(OUTPUT_RAW, "w") as f:
        f.write(raw_md)
    print(f"Written to {OUTPUT_RAW}")

    filtered_md = generate_report(rows, filtered=True)
    if filtered_md:
        with open(OUTPUT_FILTERED, "w") as f:
            f.write(filtered_md)
        print(f"Written to {OUTPUT_FILTERED}")

    for row in rows:
        d = row["data"]
        fd = row["filtered"]
        f_info = ""
        if fd:
            f_info = f" (filtered: {fd['pass']}/{fd['total']}, {format_pct(fd['pass'], fd['total'])})"
        print(f"  {row['cat_name']}: {d['pass']}/{d['total']} ({format_pct(d['pass'], d['total'])}){f_info}")


if __name__ == "__main__":
    main()
