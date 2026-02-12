#!/usr/bin/env python3
"""
Generate Markdown report from ruffle-tests/results.json.

Produces two files in the repository root:
  - ruffle-results.md           (from results.json)
  - ruffle-results-filtered.md  (from results_filtered.json)

Sections:
  1. Summary statistics (total/pass/fail, pass rate, breakdown, metadata)
  2. Passing tests table
  3. Near-passing tests table (output_mismatch sorted by match %, "low-hanging fruit")
  4. Failure breakdown: segfaults, runtime errors, timeouts
  5. Full output_mismatch table
"""

import json
import sys
from datetime import datetime
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
INVESTIGATION_DIR = RUFFLE_DIR / "_investigation"


def load_results(path: Path) -> dict:
    with open(path) as f:
        return json.load(f)


def get_investigation_files() -> set[str]:
    """Return set of test names that have investigation .md files."""
    if not INVESTIGATION_DIR.is_dir():
        return set()
    return {p.stem for p in INVESTIGATION_DIR.glob("*.md")}


def match_rate(test: dict) -> float | None:
    """Calculate line match rate for a test. Returns None if no line data."""
    lines = test.get("lines")
    if not lines:
        return None
    total = max(lines["actual_lines"], lines["expected_lines"])
    if total == 0:
        return 100.0
    return lines["matching_lines"] / total * 100


# ---------------------------------------------------------------------------
# Section generators
# ---------------------------------------------------------------------------

def generate_header(data: dict) -> str:
    md = []
    meta = data.get("metadata", {})
    is_filtered = meta.get("filtered", False)

    if is_filtered:
        md.append("# Ruffle Test Results (Filtered)")
    else:
        md.append("# Ruffle Test Results (Unfiltered)")
    md.append("")

    # Metadata
    ts = meta.get("timestamp", "")
    if ts:
        try:
            dt = datetime.fromisoformat(ts)
            md.append(f"**Date**: {dt.strftime('%Y-%m-%d %H:%M UTC')}")
        except ValueError:
            md.append(f"**Date**: {ts}")
    else:
        md.append(f"**Date**: unknown")
    md.append("")

    if meta.get("git_sha"):
        sha = meta["git_sha"][:10]
        md.append(f"**Git SHA**: `{sha}`")
        md.append("")

    if meta.get("duration_seconds"):
        dur = meta["duration_seconds"]
        minutes = int(dur // 60)
        seconds = dur % 60
        md.append(f"**Run Duration**: {minutes}m {seconds:.0f}s")
        md.append("")

    if is_filtered:
        ignored = meta.get("ignored_count", 0)
        total_available = meta.get("total_available", data["total"] + ignored)
        md.append(f"**Filtered**: {ignored} tests ignored out of {total_available} available")
        md.append("")

    return "\n".join(md)


def generate_summary(data: dict) -> str:
    md = []
    total = data["total"]
    passing = data["pass"]
    failing = data["fail"]
    rate = data["pass_rate"]
    breakdown = data.get("breakdown", {})

    # Compute total line-level stats across all tests
    total_expected = 0
    total_matching = 0
    for t in data["tests"]:
        lines = t.get("lines")
        if lines:
            total_expected += lines["expected_lines"]
            total_matching += lines["matching_lines"]
    total_mismatched = total_expected - total_matching
    line_match_pct = total_matching / total_expected * 100 if total_expected > 0 else 0

    md.append("## Summary")
    md.append("")
    md.append(f"| Metric | Value |")
    md.append(f"|--------|-------|")
    md.append(f"| Total tests | {total} |")
    md.append(f"| Passing | **{passing}** ({rate}%) |")
    md.append(f"| Failing | {failing} |")
    md.append(f"| Total expected lines | {total_expected} |")
    md.append(f"| Matching lines | {total_matching} ({line_match_pct:.1f}%) |")
    md.append(f"| Mismatched lines | {total_mismatched} |")
    md.append("")

    if breakdown:
        md.append("### Failure Breakdown")
        md.append("")
        md.append("| Category | Count | % of Failures |")
        md.append("|----------|-------|---------------|")
        for cat in sorted(breakdown.keys(), key=lambda c: -breakdown[c]):
            count = breakdown[cat]
            pct = count / failing * 100 if failing > 0 else 0
            label = cat.replace("_", " ").title()
            md.append(f"| {label} | {count} | {pct:.1f}% |")
        md.append("")

    return "\n".join(md)


def generate_passing_tests(data: dict) -> str:
    md = []
    investigations = get_investigation_files()

    passing = [t for t in data["tests"] if t["status"] == "pass"]
    passing.sort(key=lambda t: t["test"])

    md.append("## Passing Tests")
    md.append("")
    md.append(f"**{len(passing)} tests passing**")
    md.append("")

    if not passing:
        md.append("No passing tests.")
        md.append("")
        return "\n".join(md)

    md.append("| # | Test | Lines | Duration | Notes |")
    md.append("|---|------|-------|----------|-------|")

    for i, t in enumerate(passing, 1):
        name = t["test"]
        lines = t.get("lines", {})
        line_str = str(lines.get("expected_lines", "")) if lines else ""
        dur = f"{t['duration']:.1f}s" if "duration" in t else ""
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {line_str} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_near_passing(data: dict) -> str:
    """Output_mismatch tests sorted by match rate descending — low-hanging fruit."""
    md = []
    investigations = get_investigation_files()

    mismatches = [t for t in data["tests"] if t["status"] == "output_mismatch"]

    # Calculate match rates
    rated = []
    for t in mismatches:
        rate = match_rate(t)
        if rate is not None:
            rated.append((t, rate))

    rated.sort(key=lambda x: -x[1])

    # Show tests with >= 50% match rate
    near = [(t, r) for t, r in rated if r >= 50.0]

    md.append("## Near-Passing Tests")
    md.append("")
    md.append("Tests with output mismatch but >= 50% line match rate (low-hanging fruit).")
    md.append("")
    md.append(f"**{len(near)} tests** within reach")
    md.append("")

    if not near:
        md.append("No tests above 50% match threshold.")
        md.append("")
        return "\n".join(md)

    md.append("| # | Test | Match Rate | Matching | Total | Diff Lines | Notes |")
    md.append("|---|------|------------|----------|-------|------------|-------|")

    for i, (t, rate) in enumerate(near, 1):
        name = t["test"]
        lines = t["lines"]
        matching = lines["matching_lines"]
        total = max(lines["actual_lines"], lines["expected_lines"])
        diff = total - matching
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {rate:.1f}% | {matching} | {total} | {diff} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_segfaults(data: dict) -> str:
    md = []
    investigations = get_investigation_files()

    segfaults = [t for t in data["tests"] if t["status"] == "segfault"]
    segfaults.sort(key=lambda t: t["test"])

    md.append("## Segfaults")
    md.append("")

    if not segfaults:
        md.append("No segfaults.")
        md.append("")
        return "\n".join(md)

    md.append(f"**{len(segfaults)} tests** crash with SIGSEGV")
    md.append("")
    md.append("| # | Test | Duration | Notes |")
    md.append("|---|------|----------|-------|")

    for i, t in enumerate(segfaults, 1):
        name = t["test"]
        dur = f"{t['duration']:.1f}s" if "duration" in t else ""
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_runtime_errors(data: dict) -> str:
    md = []
    investigations = get_investigation_files()

    errors = [t for t in data["tests"] if t["status"] == "runtime_error"]
    errors.sort(key=lambda t: t["test"])

    md.append("## Runtime Errors")
    md.append("")

    if not errors:
        md.append("No runtime errors.")
        md.append("")
        return "\n".join(md)

    md.append(f"**{len(errors)} tests** fail with runtime errors")
    md.append("")
    md.append("| # | Test | Detail | Duration | Notes |")
    md.append("|---|------|--------|----------|-------|")

    for i, t in enumerate(errors, 1):
        name = t["test"]
        detail = t.get("detail", "")
        dur = f"{t['duration']:.1f}s" if "duration" in t else ""
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {detail} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_timeouts(data: dict) -> str:
    md = []
    investigations = get_investigation_files()

    timeouts = [t for t in data["tests"] if t["status"] == "timeout"]
    timeouts.sort(key=lambda t: t["test"])

    md.append("## Timeouts")
    md.append("")

    if not timeouts:
        md.append("No timeouts.")
        md.append("")
        return "\n".join(md)

    md.append(f"**{len(timeouts)} tests** timed out")
    md.append("")
    md.append("| # | Test | Detail | Duration | Notes |")
    md.append("|---|------|--------|----------|-------|")

    for i, t in enumerate(timeouts, 1):
        name = t["test"]
        detail = t.get("detail", "")
        dur = f"{t['duration']:.1f}s" if "duration" in t else ""
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {detail} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_output_mismatches(data: dict) -> str:
    """Full output_mismatch table sorted by match rate descending."""
    md = []
    investigations = get_investigation_files()

    mismatches = [t for t in data["tests"] if t["status"] == "output_mismatch"]

    # Calculate and sort by match rate
    rated = []
    for t in mismatches:
        rate = match_rate(t)
        rated.append((t, rate if rate is not None else -1))

    rated.sort(key=lambda x: -x[1])

    md.append("## All Output Mismatches")
    md.append("")
    md.append(f"**{len(rated)} tests** with output mismatch, sorted by match rate (best first)")
    md.append("")

    if not rated:
        md.append("No output mismatches.")
        md.append("")
        return "\n".join(md)

    md.append("| # | Test | Match Rate | Matching/Total | Actual | Expected | Notes |")
    md.append("|---|------|------------|----------------|--------|----------|-------|")

    for i, (t, rate) in enumerate(rated, 1):
        name = t["test"]
        lines = t.get("lines", {})
        if lines:
            matching = lines["matching_lines"]
            total = max(lines["actual_lines"], lines["expected_lines"])
            rate_str = f"{rate:.1f}%" if rate >= 0 else "N/A"
            match_str = f"{matching}/{total}"
            actual_str = str(lines["actual_lines"])
            expected_str = str(lines["expected_lines"])
        else:
            rate_str = "N/A"
            match_str = "-"
            actual_str = "-"
            expected_str = "-"
        notes = ""
        if name in investigations:
            notes = "[investigation](ruffle-tests/_investigation/{}.md)".format(name)
        md.append(f"| {i} | `{name}` | {rate_str} | {match_str} | {actual_str} | {expected_str} | {notes} |")

    md.append("")
    return "\n".join(md)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def generate_one(results_path: Path, output_path: Path):
    """Generate a single markdown report from a results JSON file."""
    print(f"Loading {results_path}...")
    data = load_results(results_path)

    print(f"Generating {output_path.name}...")

    sections = [
        generate_header(data),
        generate_summary(data),
        generate_passing_tests(data),
        generate_near_passing(data),
        generate_segfaults(data),
        generate_runtime_errors(data),
        generate_timeouts(data),
        generate_output_mismatches(data),
    ]

    markdown = "\n".join(s for s in sections if s)

    with open(output_path, "w") as f:
        f.write(markdown)

    print(f"  Written to {output_path}")


def generate_markdown():
    """Generate both filtered and unfiltered markdown reports."""
    filtered_json = RUFFLE_DIR / "results_filtered.json"
    unfiltered_json = RUFFLE_DIR / "results.json"

    generated = False

    if unfiltered_json.exists():
        generate_one(unfiltered_json, BASE_DIR / "ruffle-results.md")
        generated = True
    else:
        print(f"Skipping unfiltered: {unfiltered_json} not found")

    if filtered_json.exists():
        generate_one(filtered_json, BASE_DIR / "ruffle-results-filtered.md")
        generated = True
    else:
        print(f"Skipping filtered: {filtered_json} not found")

    if not generated:
        print("Error: No results JSON files found in ruffle-tests/", file=sys.stderr)
        sys.exit(1)

    print("\nDone.")


if __name__ == "__main__":
    generate_markdown()
