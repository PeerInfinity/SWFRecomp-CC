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
  6. Investigation document reference table
"""

import json
import re
import sys
from datetime import datetime
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
INVESTIGATION_DIR = RUFFLE_DIR / "_investigation"

EXCLUDED_DOCS = {
    "CURRENT_STATUS.md",
    "FAILING_TESTS_BY_FEATURE_FILTERED.md",
    "FAILING_TESTS_BY_FEATURE.md",
    "SESSION_START_GUIDE.md",
}

_TESTS_RE = re.compile(r'<!--\s*TESTS:\s*(.+?)\s*-->')


def load_results(path: Path) -> dict:
    with open(path) as f:
        return json.load(f)


def build_investigation_index() -> tuple[dict[str, list[tuple[int, str]]], list[tuple[str, str, list[str]]]]:
    """Parse investigation docs for <!-- TESTS: ... --> comments.

    Scans _investigation/, _investigation/complete/, _investigation/incomplete/,
    and _investigation/blocked/ for .md files
    (excluding EXCLUDED_DOCS), parses the TESTS comment from each,
    and builds a reverse index from test names to document numbers.

    Returns:
        test_to_docs: mapping test_name -> list of (doc_number, doc_rel_path)
        doc_list: list of (doc_display_name, doc_rel_path, test_names) indexed by doc_number-1
    """
    if not INVESTIGATION_DIR.is_dir():
        return {}, []

    # Collect all candidate docs from both directories
    candidates = []  # list of (display_name, rel_path, abs_path)

    for p in INVESTIGATION_DIR.glob("*.md"):
        if p.name in EXCLUDED_DOCS:
            continue
        rel = f"ruffle-tests/_investigation/{p.name}"
        candidates.append((p.name, rel, p))

    complete_dir = INVESTIGATION_DIR / "complete"
    if complete_dir.is_dir():
        for p in complete_dir.glob("*.md"):
            rel = f"ruffle-tests/_investigation/complete/{p.name}"
            candidates.append((p.name, rel, p))

    incomplete_dir = INVESTIGATION_DIR / "incomplete"
    if incomplete_dir.is_dir():
        for p in incomplete_dir.glob("*.md"):
            rel = f"ruffle-tests/_investigation/incomplete/{p.name}"
            candidates.append((p.name, rel, p))

    blocked_dir = INVESTIGATION_DIR / "blocked"
    if blocked_dir.is_dir():
        for p in blocked_dir.glob("*.md"):
            rel = f"ruffle-tests/_investigation/blocked/{p.name}"
            candidates.append((p.name, rel, p))

    # Sort alphabetically by display name (case-insensitive)
    candidates.sort(key=lambda d: d[0].lower())

    # Parse TESTS comments and build mappings
    test_to_docs: dict[str, list[tuple[int, str]]] = {}
    doc_list: list[tuple[str, str, list[str]]] = []

    for display_name, rel_path, abs_path in candidates:
        with open(abs_path) as f:
            content = f.read()

        m = _TESTS_RE.search(content)
        if not m:
            continue

        test_names = [t.strip() for t in m.group(1).split(",") if t.strip()]
        if not test_names:
            continue

        doc_number = len(doc_list) + 1
        doc_list.append((display_name, rel_path, test_names))

        for test_name in test_names:
            if test_name not in test_to_docs:
                test_to_docs[test_name] = []
            test_to_docs[test_name].append((doc_number, rel_path))

    return test_to_docs, doc_list


def format_notes(test_name: str, test_to_docs: dict[str, list[tuple[int, str]]]) -> str:
    """Format notes column with numbered investigation doc links."""
    docs = test_to_docs.get(test_name, [])
    if not docs:
        return ""
    return " ".join(f"[{num}]({path})" for num, path in docs)


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


def generate_passing_tests(data: dict, test_to_docs: dict) -> str:
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {line_str} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_near_passing(data: dict, test_to_docs: dict) -> str:
    """Output_mismatch tests sorted by match rate descending — low-hanging fruit."""
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {rate:.1f}% | {matching} | {total} | {diff} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_segfaults(data: dict, test_to_docs: dict) -> str:
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_runtime_errors(data: dict, test_to_docs: dict) -> str:
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {detail} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_timeouts(data: dict, test_to_docs: dict) -> str:
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {detail} | {dur} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_output_mismatches(data: dict, test_to_docs: dict) -> str:
    """Full output_mismatch table sorted by match rate descending."""
    md = []

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
        notes = format_notes(name, test_to_docs)
        md.append(f"| {i} | `{name}` | {rate_str} | {match_str} | {actual_str} | {expected_str} | {notes} |")

    md.append("")
    return "\n".join(md)


def generate_investigation_legend(doc_list: list[tuple[str, str, list[str]]], data: dict) -> str:
    """Generate reference table mapping document numbers to file links with test counts."""
    if not doc_list:
        return ""

    passing_tests = {t["test"] for t in data["tests"] if t["status"] == "pass"}

    # Collect all tests referenced by any document
    documented_tests = set()
    for _name, _path, test_names in doc_list:
        documented_tests.update(test_names)

    all_test_names = {t["test"] for t in data["tests"]}
    undocumented = all_test_names - documented_tests
    undoc_total = len(undocumented)
    undoc_passing = sum(1 for t in undocumented if t in passing_tests)
    undoc_failing = undoc_total - undoc_passing

    md = []
    md.append("## Investigation Documents")
    md.append("")
    md.append("| # | Document | Tests | Passing | Failing |")
    md.append("|---|----------|-------|---------|---------|")
    for i, (name, path, test_names) in enumerate(doc_list, 1):
        total = len(test_names)
        passing = sum(1 for t in test_names if t in passing_tests)
        failing = total - passing
        md.append(f"| {i} | [{name}]({path}) | {total} | {passing} | {failing} |")
    md.append(f"| | *(tests not in any document)* | {undoc_total} | {undoc_passing} | {undoc_failing} |")
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

    test_to_docs, doc_list = build_investigation_index()

    sections = [
        generate_header(data),
        generate_summary(data),
        generate_passing_tests(data, test_to_docs),
        generate_near_passing(data, test_to_docs),
        generate_segfaults(data, test_to_docs),
        generate_runtime_errors(data, test_to_docs),
        generate_timeouts(data, test_to_docs),
        generate_output_mismatches(data, test_to_docs),
        generate_investigation_legend(doc_list, data),
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
