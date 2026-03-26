#!/usr/bin/env python3
"""Generate ruffle-tests/results-index.md linking to all per-category result files.

Scans for _results/results.json under ruffle-tests/tests/swfs/ and produces
a summary table with links to each category's detailed results.
"""

import glob
import json
import sys
from pathlib import Path

BASE_DIR = Path(__file__).parent.parent
RUFFLE_DIR = BASE_DIR / "ruffle-tests"
SWF_DIR = RUFFLE_DIR / "tests" / "swfs"
OUTPUT = RUFFLE_DIR / "results-index.md"


def main():
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

        # Derive category name from path relative to tests/swfs/
        try:
            cat_name = str(category_dir.relative_to(SWF_DIR))
        except ValueError:
            cat_name = category_dir.name

        with open(path) as f:
            data = json.load(f)

        total = data.get("total", 0)
        passed = data.get("pass", 0)
        rate = data.get("pass_rate", 0)
        breakdown = data.get("breakdown", {})

        # Build links relative to ruffle-tests/
        results_rel = str(results_dir.relative_to(RUFFLE_DIR))
        results_link = f"[results]({results_rel}/results.md)"

        filtered_link = "-"
        filtered_json = results_dir / "results_filtered.json"
        if filtered_json.exists():
            with open(filtered_json) as f:
                fdata = json.load(f)
            f_pass = fdata.get("pass", 0)
            f_total = fdata.get("total", 0)
            f_rate = fdata.get("pass_rate", 0)
            filtered_link = f"[filtered]({results_rel}/results_filtered.md) ({f_pass}/{f_total}, {f_rate}%)"

        meta = data.get("metadata", {})
        rows.append((cat_name, passed, total, rate, results_link, filtered_link, breakdown, meta))

    # Generate markdown
    lines = [
        "# Ruffle Test Results Index\n",
        f"| Category | Pass | Total | Rate | Report | Filtered |",
        "|----------|-----:|------:|-----:|--------|----------|",
    ]

    for cat_name, passed, total, rate, results_link, filtered_link, breakdown, meta in rows:
        note = ""
        if meta.get("incomplete"):
            ms = meta.get("missing_shards", 0)
            es = meta.get("expected_shards", 0)
            note = f" **⚠️ {es - ms}/{es} shards**"
        lines.append(
            f"| {cat_name} | {passed} | {total} | {rate}% | {results_link} | {filtered_link} |{note}")

    lines.append("")

    # Incomplete run warnings
    incomplete_cats = [(cat, meta) for cat, _, _, _, _, _, _, meta in rows if meta.get("incomplete")]
    if incomplete_cats:
        lines.append("### ⚠️ Incomplete runs\n")
        for cat, meta in incomplete_cats:
            ms = meta.get("missing_shards", 0)
            es = meta.get("expected_shards", 0)
            lines.append(f"- **{cat}**: {es - ms}/{es} shards produced results ({ms} missing). "
                          "Some tests may be absent due to shard failure, not code changes.")
        lines.append("")

    # Per-category breakdown
    for cat_name, passed, total, rate, _, _, breakdown, _ in rows:
        if breakdown:
            lines.append(f"### {cat_name} failures\n")
            lines.append("| Category | Count |")
            lines.append("|----------|------:|")
            for k, v in sorted(breakdown.items(), key=lambda x: -x[1]):
                lines.append(f"| {k} | {v} |")
            lines.append("")

    md = "\n".join(lines)

    with open(OUTPUT, "w") as f:
        f.write(md)

    print(f"Written to {OUTPUT}")
    for cat_name, passed, total, rate, _, _, _, _ in rows:
        print(f"  {cat_name}: {passed}/{total} ({rate}%)")


if __name__ == "__main__":
    main()
