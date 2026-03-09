#!/usr/bin/env python3
"""
Generate FAILING_TESTS_BY_FEATURE.md and its filtered variant from
feature_categories.json + results.json.

Produces two files in ruffle-tests/_investigation/:
  - FAILING_TESTS_BY_FEATURE.md           (all tests)
  - FAILING_TESTS_BY_FEATURE_FILTERED.md  (ignored tests removed)
"""

import json
import re
import subprocess
import sys
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
INVESTIGATION_DIR = RUFFLE_DIR / "_investigation"
CATEGORIES_PATH = INVESTIGATION_DIR / "feature_categories.json"
RESULTS_PATH = RUFFLE_DIR / "results.json"
RESULTS_FILTERED_PATH = RUFFLE_DIR / "results_filtered.json"
IGNORED_TESTS_PATH = RUFFLE_DIR / "ignored_tests.txt"

NEAR_PASSING_THRESHOLD = 60.0  # percent


# ---------------------------------------------------------------------------
# Data loading
# ---------------------------------------------------------------------------

def load_categories() -> dict:
    with open(CATEGORIES_PATH) as f:
        return json.load(f)


def load_results(path: Path) -> dict:
    with open(path) as f:
        return json.load(f)


def load_ignored_tests() -> set[str]:
    if not IGNORED_TESTS_PATH.exists():
        return set()
    ignored = set()
    with open(IGNORED_TESTS_PATH) as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith("#"):
                ignored.add(line)
    return ignored


def build_test_lookup(data: dict) -> dict[str, dict]:
    """Map test name -> test result dict."""
    return {t["test"]: t for t in data["tests"]}


_EXCLUDED_DOCS = {
    "CURRENT_STATUS.md",
    "FAILING_TESTS_BY_FEATURE_FILTERED.md",
    "FAILING_TESTS_BY_FEATURE.md",
    "SESSION_START_GUIDE.md",
}
_TESTS_RE = re.compile(r'<!--\s*TESTS:\s*(.+?)\s*-->')


def build_investigation_index() -> dict[str, list[tuple[str, str]]]:
    """Scan investigation docs for <!-- TESTS: ... --> comments.

    Returns a mapping: test_name -> list of (doc_display_name, relative_path).
    """
    test_to_docs: dict[str, list[tuple[str, str]]] = {}

    if not INVESTIGATION_DIR.is_dir():
        return test_to_docs

    candidates: list[tuple[str, str, Path]] = []

    for p in INVESTIGATION_DIR.glob("*.md"):
        if p.name in _EXCLUDED_DOCS:
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

    for display_name, rel_path, abs_path in candidates:
        with open(abs_path) as f:
            content = f.read()
        m = _TESTS_RE.search(content)
        if not m:
            continue
        test_names = [t.strip() for t in m.group(1).split(",") if t.strip()]
        for test_name in test_names:
            if test_name not in test_to_docs:
                test_to_docs[test_name] = []
            test_to_docs[test_name].append((display_name, rel_path))

    return test_to_docs


def get_git_sha() -> str:
    try:
        return subprocess.check_output(
            ["git", "rev-parse", "HEAD"], cwd=BASE_DIR, text=True
        ).strip()[:10]
    except Exception:
        return "unknown"


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def match_rate(test: dict) -> float | None:
    """Calculate line match rate for a test. Returns None if no line data."""
    lines = test.get("lines")
    if not lines:
        return None
    total = max(lines["actual_lines"], lines["expected_lines"])
    if total == 0:
        return 100.0
    return lines["matching_lines"] / total * 100


def match_rate_str(test: dict) -> str:
    """Format match rate as 'matching/total (pct%)'."""
    lines = test.get("lines")
    if not lines:
        return "N/A"
    matching = lines["matching_lines"]
    total = max(lines["actual_lines"], lines["expected_lines"])
    if total == 0:
        return "0/0"
    pct = matching / total * 100
    return f"{matching}/{total} ({pct:.0f}%)"


def test_annotation(test_name: str, lookup: dict[str, dict]) -> str:
    """Return inline annotation like (PASS), (SEGFAULT), (TIMEOUT), or empty."""
    t = lookup.get(test_name)
    if not t:
        return " (NOT IN RESULTS)"
    status = t["status"]
    if status == "pass":
        return " (PASS)"
    elif status in ("segfault", "runtime_segfault"):
        return " (SEGFAULT)"
    elif status == "timeout":
        return " (TIMEOUT)"
    return ""


def format_test_list(tests: list[str], lookup: dict[str, dict]) -> str:
    """Format a test list with inline annotations."""
    parts = []
    for t in sorted(tests):
        ann = test_annotation(t, lookup)
        parts.append(f"{t}{ann}")
    return ", ".join(parts)


def count_by_status(tests: list[str], lookup: dict[str, dict]) -> tuple[int, int, int]:
    """Return (passing, failing, total) counts."""
    passing = sum(1 for t in tests if lookup.get(t, {}).get("status") == "pass")
    total = len(tests)
    return passing, total - passing, total


# ---------------------------------------------------------------------------
# Section generators
# ---------------------------------------------------------------------------

def generate_header(data: dict, filtered: bool, ignored_count: int) -> str:
    md = []
    if filtered:
        md.append("# Failing Ruffle Tests by Feature Category (Filtered)")
    else:
        md.append("# Failing Ruffle Tests by Feature Category")
    md.append("")
    md.append("<!-- Auto-generated by scripts/generate_failing_by_feature.py -->")
    md.append("<!-- Do not edit manually — edit feature_categories.json instead -->")
    md.append("")

    meta = data.get("metadata", {})
    sha = meta.get("git_sha", get_git_sha())
    if sha:
        sha = sha[:10]

    total = data["total"]
    passing = data["pass"]
    failing = data["fail"]
    rate = data["pass_rate"]
    breakdown = data.get("breakdown", {})

    md.append(f"- **Total tests**: {total}")
    md.append(f"- **Passing**: {passing} ({rate}%)")

    # Build breakdown string
    bd_parts = []
    for cat in sorted(breakdown.keys()):
        count = breakdown[cat]
        label = cat.replace("_", " ")
        bd_parts.append(f"{count} {label}")
    bd_str = ", ".join(bd_parts) if bd_parts else str(failing)
    md.append(f"- **Failing**: {failing} ({bd_str})")

    if sha:
        md.append(f"- **Based on**: CI run at commit `{sha}`")
    md.append("")

    if filtered:
        md.append(f"This is a filtered version with {ignored_count} ignored tests removed. "
                   f"Ignored tests include interactive input (mouse/keyboard/focus), "
                   f"external resource loading, sound streaming, FileReference, ExternalInterface, "
                   f"BitmapData pixel ops, and cross-movie loading.")
        md.append("")

    md.append("Tests are sorted by category (ordered by priority). "
              "Within each category, tests are listed alphabetically.")
    md.append("")
    return "\n".join(md)


def generate_category_section(
    cat: dict,
    priority: int,
    lookup: dict[str, dict],
    ignored: set[str],
    filtered: bool,
    test_to_docs: dict[str, list[tuple[str, str]]],
) -> str | None:
    """Generate one ## Feature: section. Returns None if category has no failing tests."""
    tests = cat["tests"]
    if filtered:
        tests = [t for t in tests if t not in ignored]
    if not tests:
        return None

    # Only include failing tests
    failing_tests = [t for t in tests if lookup.get(t, {}).get("status") != "pass"]
    if not failing_tests:
        return None

    passing, failing, total = count_by_status(tests, lookup)

    md = []
    md.append(f"## {priority}. {cat['name']} ({failing} failing / {total} total)")
    md.append("")
    md.append(f"Failing tests: {format_test_list(failing_tests, lookup)}")
    md.append("")

    if cat.get("description"):
        md.append(f"Description: {cat['description']}")
        md.append("")

    sub_cats = cat.get("sub_categories", [])
    if sub_cats:
        has_subcats = False
        subcat_lines = []
        for sc in sub_cats:
            sc_tests = sc.get("tests", [])
            if filtered:
                sc_tests = [t for t in sc_tests if t not in ignored]

            if sc.get("remainder"):
                # Remainder = all tests not in other sub-categories
                explicit_tests = set()
                for other_sc in sub_cats:
                    if not other_sc.get("remainder"):
                        for t in other_sc.get("tests", []):
                            explicit_tests.add(t)
                sc_tests = [t for t in tests if t not in explicit_tests]

            # Only include failing tests in sub-category counts
            sc_failing = [t for t in sc_tests if lookup.get(t, {}).get("status") != "pass"]
            if not sc_failing:
                continue

            has_subcats = True
            sc_count = len(sc_failing)
            note = f" -- {sc['note']}" if sc.get("note") else ""
            subcat_lines.append(f"- **{sc['name']}**: {sc_count} failing{note}")

        if has_subcats:
            md.append("Sub-categories:")
            md.extend(subcat_lines)
            md.append("")

    # Collect related investigation docs for failing tests in this category
    seen_docs: dict[str, str] = {}  # rel_path -> display_name (dedup)
    for t in failing_tests:
        for doc_name, doc_path in test_to_docs.get(t, []):
            if doc_path not in seen_docs:
                seen_docs[doc_path] = doc_name
    if seen_docs:
        links = [f"[{name}]({path})" for path, name in sorted(seen_docs.items(), key=lambda x: x[1].lower())]
        md.append(f"Investigation docs: {', '.join(links)}")
        md.append("")

    md.append("---")
    md.append("")
    return "\n".join(md)


def generate_near_passing(
    lookup: dict[str, dict],
    notes: dict[str, str],
    ignored: set[str],
    filtered: bool,
) -> str:
    """Generate 'Likely Fixable' section for tests >THRESHOLD match rate."""
    md = []
    md.append("## Likely Fixable with Bug Fixes to Existing Features")
    md.append("")
    md.append(f"These tests are >{NEAR_PASSING_THRESHOLD:.0f}% passing and likely need "
              f"bug fixes rather than new features:")
    md.append("")

    candidates = []
    for name, t in lookup.items():
        if filtered and name in ignored:
            continue
        if t["status"] != "output_mismatch":
            continue
        rate = match_rate(t)
        if rate is not None and rate >= NEAR_PASSING_THRESHOLD:
            note = notes.get(name, "")
            candidates.append((name, t, rate, note))

    candidates.sort(key=lambda x: -x[2])

    if not candidates:
        md.append("No tests above threshold.")
        md.append("")
        return "\n".join(md)

    md.append("| Test | Match Rate | Likely Issue |")
    md.append("|------|-----------|-------------|")

    for name, t, rate, note in candidates:
        rate_str = match_rate_str(t)
        md.append(f"| {name} | {rate_str} | {note} |")

    md.append("")
    return "\n".join(md)


def generate_crashes_timeouts(
    lookup: dict[str, dict],
    notes: dict[str, str],
    ignored: set[str],
    filtered: bool,
) -> str:
    """Generate 'Crashes and Timeouts' section."""
    md = []

    crash_tests = []
    for name, t in sorted(lookup.items()):
        if filtered and name in ignored:
            continue
        status = t["status"]
        if status in ("segfault", "runtime_segfault"):
            note = notes.get(name, "")
            crash_tests.append((name, "segfault", note))
        elif status == "timeout":
            note = notes.get(name, "")
            crash_tests.append((name, "timeout", note))

    md.append(f"## Crashes and Timeouts ({len(crash_tests)} tests)")
    md.append("")

    if not crash_tests:
        md.append("None.")
        md.append("")
        return "\n".join(md)

    md.append("| Test | Status | Likely Cause |")
    md.append("|------|--------|-------------|")

    for name, status, note in crash_tests:
        md.append(f"| {name} | {status} | {note} |")

    md.append("")
    return "\n".join(md)


def generate_uncategorized(
    categories: list[dict],
    lookup: dict[str, dict],
    ignored: set[str],
    filtered: bool,
) -> str:
    """Safety net: show tests not in any category."""
    categorized = set()
    for cat in categories:
        for t in cat["tests"]:
            categorized.add(t)

    uncategorized = []
    for name in sorted(lookup.keys()):
        if name in categorized:
            continue
        if filtered and name in ignored:
            continue
        uncategorized.append(name)

    if not uncategorized:
        return ""

    # Only show failing tests
    failing = [t for t in uncategorized if lookup[t]["status"] != "pass"]

    if not failing:
        return ""

    md = []
    md.append(f"## Uncategorized Tests ({len(failing)} failing)")
    md.append("")
    md.append("Failing tests not assigned to any feature category above.")
    md.append("")

    md.append(f"{format_test_list(failing, lookup)}")
    md.append("")

    md.append("---")
    md.append("")
    return "\n".join(md)


def generate_summary_table(
    categories: list[dict],
    lookup: dict[str, dict],
    ignored: set[str],
    filtered: bool,
) -> str:
    """Generate summary table with computed counts."""
    md = []
    md.append("## Summary by Feature Priority")
    md.append("")
    md.append("| Priority | Feature | Failing | Total | Notes |")
    md.append("|----------|---------|---------|-------|-------|")

    total_failing_all = 0
    total_tests_all = 0

    for i, cat in enumerate(categories, 1):
        tests = cat["tests"]
        if filtered:
            tests = [t for t in tests if t not in ignored]
        if not tests:
            continue

        passing, failing, total = count_by_status(tests, lookup)
        total_failing_all += failing
        total_tests_all += total

        # Compute average match rate for failing tests
        rates = []
        for t_name in tests:
            t = lookup.get(t_name)
            if t and t["status"] == "output_mismatch":
                r = match_rate(t)
                if r is not None:
                    rates.append(r)

        notes = ""
        if rates:
            avg = sum(rates) / len(rates)
            notes = f"avg {avg:.0f}% match"

        md.append(f"| {i} | {cat['name']} | {failing} | {total} | {notes} |")

    # Uncategorized
    categorized = set()
    for cat in categories:
        for t in cat["tests"]:
            categorized.add(t)

    uncat_tests = [n for n in lookup if n not in categorized and (not filtered or n not in ignored)]
    if uncat_tests:
        u_passing, u_failing, u_total = count_by_status(uncat_tests, lookup)
        total_failing_all += u_failing
        total_tests_all += u_total
        md.append(f"| -- | *(Uncategorized)* | {u_failing} | {u_total} | |")

    md.append(f"| | **Total** | **{total_failing_all}** | **{total_tests_all}** | |")
    md.append("")
    return "\n".join(md)


# ---------------------------------------------------------------------------
# Orchestration
# ---------------------------------------------------------------------------

def generate_document(data: dict, categories_data: dict, ignored: set[str], filtered: bool) -> str:
    categories = categories_data["categories"]
    near_notes = categories_data.get("near_passing_notes", {})
    crash_notes = categories_data.get("crash_notes", {})
    lookup = build_test_lookup(data)
    test_to_docs = build_investigation_index()

    ignored_count = len(ignored) if filtered else 0

    sections = []

    # Header
    sections.append(generate_header(data, filtered, ignored_count))

    # Separator
    sections.append("---\n")

    # Category sections
    for i, cat in enumerate(categories, 1):
        section = generate_category_section(cat, i, lookup, ignored, filtered, test_to_docs)
        if section:
            sections.append(section)

    # Uncategorized
    uncat = generate_uncategorized(categories, lookup, ignored, filtered)
    if uncat:
        sections.append(uncat)

    # Near-passing
    sections.append(generate_near_passing(lookup, near_notes, ignored, filtered))

    # Crashes and timeouts
    sections.append(generate_crashes_timeouts(lookup, crash_notes, ignored, filtered))

    # Summary
    sections.append("---\n")
    sections.append(generate_summary_table(categories, lookup, ignored, filtered))

    return "\n".join(s for s in sections if s)


def main():
    if not CATEGORIES_PATH.exists():
        print(f"Error: {CATEGORIES_PATH} not found", file=sys.stderr)
        sys.exit(1)

    if not RESULTS_PATH.exists():
        print(f"Error: {RESULTS_PATH} not found", file=sys.stderr)
        sys.exit(1)

    categories_data = load_categories()
    ignored = load_ignored_tests()

    # --- Unfiltered ---
    print("Generating unfiltered document...")
    results = load_results(RESULTS_PATH)
    doc = generate_document(results, categories_data, set(), filtered=False)
    out_path = INVESTIGATION_DIR / "FAILING_TESTS_BY_FEATURE.md"
    with open(out_path, "w") as f:
        f.write(doc)
    print(f"  Written to {out_path}")

    # --- Filtered ---
    print("Generating filtered document...")
    if RESULTS_FILTERED_PATH.exists():
        results_filtered = load_results(RESULTS_FILTERED_PATH)
    else:
        # Filter results.json by ignored_tests.txt
        results_filtered = dict(results)
        results_filtered["tests"] = [
            t for t in results["tests"] if t["test"] not in ignored
        ]
        results_filtered["total"] = len(results_filtered["tests"])
        results_filtered["pass"] = sum(
            1 for t in results_filtered["tests"] if t["status"] == "pass"
        )
        results_filtered["fail"] = results_filtered["total"] - results_filtered["pass"]
        if results_filtered["total"] > 0:
            results_filtered["pass_rate"] = round(
                results_filtered["pass"] / results_filtered["total"] * 100, 1
            )
        else:
            results_filtered["pass_rate"] = 0.0
        breakdown = {}
        for t in results_filtered["tests"]:
            if t["status"] != "pass":
                status = t["status"]
                breakdown[status] = breakdown.get(status, 0) + 1
        results_filtered["breakdown"] = breakdown

    doc_filtered = generate_document(
        results_filtered, categories_data, ignored, filtered=True
    )
    out_path_filtered = INVESTIGATION_DIR / "FAILING_TESTS_BY_FEATURE_FILTERED.md"
    with open(out_path_filtered, "w") as f:
        f.write(doc_filtered)
    print(f"  Written to {out_path_filtered}")

    print("\nDone.")


if __name__ == "__main__":
    main()
