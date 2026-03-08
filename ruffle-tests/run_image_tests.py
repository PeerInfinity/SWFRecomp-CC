#!/usr/bin/env python3
"""
Run all Ruffle AVM1 image comparison tests locally (headless WebGPU rendering).

Discovers tests with [image_comparisons] in test.toml, runs each one via
verify_output.py --headless, and writes results to image_results.json.

Usage:
    python3 ruffle-tests/run_image_tests.py                  # run all
    python3 ruffle-tests/run_image_tests.py --test=color     # run one
    python3 ruffle-tests/run_image_tests.py --report-only    # regenerate .md from existing JSON
"""

import argparse
import json
import os
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

try:
    import tomllib
except ImportError:
    import tomli as tomllib

SCRIPT_DIR = Path(__file__).parent.resolve()
VERIFY_SCRIPT = SCRIPT_DIR / "verify_output.py"
RESULTS_JSON = SCRIPT_DIR / "image_results.json"
RESULTS_MD = SCRIPT_DIR.parent / "ruffle-image-results.md"


def discover_image_tests():
    """Find all test dirs with [image_comparisons] in test.toml."""
    tests = []
    for test_dir in sorted(SCRIPT_DIR.iterdir()):
        if not test_dir.is_dir() or test_dir.name.startswith(("_", ".")):
            continue
        toml_path = test_dir / "test.toml"
        if not toml_path.exists():
            continue
        with open(toml_path, "rb") as f:
            data = tomllib.load(f)
        if data.get("image_comparisons"):
            tests.append(test_dir.name)
    return tests


def run_single_test(test_name):
    """Run a single image comparison test via verify_output.py.

    Returns (entry_dict, stdout_text).
    """
    cmd = [
        sys.executable, str(VERIFY_SCRIPT),
        f"--test={test_name}",
        "--headless",
        "--verbose",
        "--diff",
    ]

    start = time.monotonic()
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=300)
    duration = round(time.monotonic() - start, 2)

    stdout = result.stdout
    stderr = result.stderr

    # Parse result from verify_output.py stdout
    entry = {
        "test": test_name,
        "duration": duration,
    }

    # Determine trace status from stdout.
    # The final status line from verify_output.py is on its own line (e.g. "PASS" or "MISMATCH").
    # We look for standalone status words, ignoring [image:...] lines.
    trace_status = "unknown"
    for line in stdout.splitlines():
        stripped = line.strip()
        # Skip lines with image comparison results
        if "[image:" in stripped:
            continue
        if stripped == "PASS":
            trace_status = "pass"
        elif stripped == "MISMATCH":
            trace_status = "output_mismatch"
        elif "RECOMP_FAIL" in stripped:
            trace_status = "recomp_fail"
        elif "COMPILE_FAIL" in stripped:
            trace_status = "compile_fail"
        elif "TIMEOUT" in stripped:
            trace_status = "timeout"
        elif "SEGFAULT" in stripped or "SIGSEGV" in stripped:
            trace_status = "segfault"
    entry["trace_status"] = trace_status

    # Parse image comparison results from verbose output lines like:
    #     [image:output] PASS - Image check passed: 0 outliers ...
    #     [image:output] FAIL - Image comparison failed: 90000 outliers ...
    # These may appear mid-line after the test name prefix.
    image_results = {}
    for line in stdout.splitlines():
        if "[image:" not in line:
            continue
        # Find each [image:NAME] occurrence in the line
        idx = 0
        while True:
            pos = line.find("[image:", idx)
            if pos == -1:
                break
            try:
                bracket_end = line.index("]", pos)
                cmp_name = line[pos + 7:bracket_end]  # len("[image:") == 7
                rest = line[bracket_end + 2:]  # skip "] "
                parts = rest.split(" - ", 1)
                status = parts[0].strip().lower()
                message = parts[1].strip() if len(parts) > 1 else ""
                image_results[cmp_name] = {
                    "status": status,
                    "message": message,
                }
            except (ValueError, IndexError):
                pass
            idx = pos + 1

    entry["image_comparisons"] = image_results

    # Determine overall image status
    if not image_results:
        entry["image_status"] = "no_render"
    elif all(r["status"] == "pass" for r in image_results.values()):
        entry["image_status"] = "pass"
    elif all(r["status"] == "skip" for r in image_results.values()):
        entry["image_status"] = "skip"
    else:
        entry["image_status"] = "fail"

    return entry, stdout


def get_git_sha():
    """Get current git SHA."""
    try:
        result = subprocess.run(
            ["git", "rev-parse", "HEAD"],
            capture_output=True, text=True, timeout=5,
            cwd=str(SCRIPT_DIR.parent))
        return result.stdout.strip() if result.returncode == 0 else ""
    except Exception:
        return ""


def build_report(test_results, run_start):
    """Build JSON report from test results."""
    total = len(test_results)
    image_pass = sum(1 for t in test_results if t["image_status"] == "pass")
    image_fail = sum(1 for t in test_results if t["image_status"] == "fail")
    image_no_render = sum(1 for t in test_results if t["image_status"] == "no_render")
    image_skip = sum(1 for t in test_results if t["image_status"] == "skip")
    trace_pass = sum(1 for t in test_results if t["trace_status"] == "pass")

    return {
        "metadata": {
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "git_sha": get_git_sha(),
            "duration_seconds": round(time.monotonic() - run_start, 2),
        },
        "total": total,
        "image_pass": image_pass,
        "image_fail": image_fail,
        "image_no_render": image_no_render,
        "image_skip": image_skip,
        "trace_pass": trace_pass,
        "tests": test_results,
    }


def _parse_outliers(message):
    """Extract outlier count from image comparison message."""
    import re
    m = re.search(r'(\d+) outliers', message)
    return int(m.group(1)) if m else None


def _format_image_summary(image_comparisons):
    """Format image comparison results compactly.

    Single-image tests: "3914 outliers, max diff 255"
    Multi-image tests:  "6/12 pass (failing: 01a=408, 01b=408, 04a=408, ...)"
    """
    if not image_comparisons:
        return ""

    items = list(image_comparisons.items())
    if len(items) == 1:
        name, r = items[0]
        if r["status"] == "pass":
            return "PASS"
        msg = r.get("message", "")
        outliers = _parse_outliers(msg)
        import re
        max_diff_m = re.search(r'max difference (\d+)', msg)
        max_diff = int(max_diff_m.group(1)) if max_diff_m else None
        parts = []
        if outliers is not None:
            parts.append(f"{outliers:,} outliers")
        if max_diff is not None:
            parts.append(f"max diff {max_diff}")
        return ", ".join(parts) if parts else msg

    # Multi-image test
    total = len(items)
    passing = sum(1 for _, r in items if r["status"] == "pass")
    if passing == total:
        return f"{passing}/{total} pass"

    failing_details = []
    for name, r in items:
        if r["status"] != "pass":
            outliers = _parse_outliers(r.get("message", ""))
            short_name = name.replace("output.", "")
            if outliers is not None:
                failing_details.append(f"{short_name}={outliers:,}")
            else:
                failing_details.append(short_name)

    # Compact failing details — if all have same outlier count, collapse
    outlier_counts = set()
    for name, r in items:
        if r["status"] != "pass":
            o = _parse_outliers(r.get("message", ""))
            if o is not None:
                outlier_counts.add(o)

    if len(outlier_counts) == 1:
        count = outlier_counts.pop()
        failing_names = [name.replace("output.", "") for name, r in items if r["status"] != "pass"]
        return f"{passing}/{total} pass ({total-passing} fail: {count:,} outliers each)"
    else:
        detail_str = ", ".join(failing_details[:6])
        if len(failing_details) > 6:
            detail_str += f", +{len(failing_details)-6} more"
        return f"{passing}/{total} pass (fail: {detail_str})"


def generate_markdown(results_path, output_path):
    """Generate markdown report from image results JSON."""
    with open(results_path) as f:
        data = json.load(f)

    md = []
    meta = data.get("metadata", {})

    md.append("# Ruffle AVM1 Image Comparison Test Results")
    md.append("")

    # Metadata
    ts = meta.get("timestamp", "")
    if ts:
        try:
            dt = datetime.fromisoformat(ts)
            md.append(f"**Date**: {dt.strftime('%Y-%m-%d %H:%M UTC')}")
        except ValueError:
            md.append(f"**Date**: {ts}")
    if meta.get("git_sha"):
        md.append(f"**Git SHA**: `{meta['git_sha'][:10]}`")
    if meta.get("duration_seconds"):
        dur = meta["duration_seconds"]
        minutes = int(dur // 60)
        seconds = dur % 60
        md.append(f"**Run Duration**: {minutes}m {seconds:.0f}s")
    md.append("")

    # Summary
    total = data["total"]
    image_pass = data["image_pass"]
    image_fail = data["image_fail"]
    image_no_render = data["image_no_render"]
    trace_pass = data["trace_pass"]

    md.append("## Summary")
    md.append("")
    md.append("| Metric | Value |")
    md.append("|--------|-------|")
    md.append(f"| Total image tests | {total} |")
    md.append(f"| Image passing | **{image_pass}** ({100*image_pass/total:.0f}%) |" if total else "| Image passing | 0 |")
    md.append(f"| Image failing | {image_fail} |")
    md.append(f"| No render (build/runtime fail) | {image_no_render} |")
    md.append(f"| Trace output passing | {trace_pass} ({100*trace_pass/total:.0f}%) |" if total else "| Trace passing | 0 |")
    md.append("")

    tests = data["tests"]

    # Passing image tests
    passing = [t for t in tests if t["image_status"] == "pass"]
    passing.sort(key=lambda t: t["test"])
    md.append("## Passing Image Tests")
    md.append("")
    if passing:
        md.append(f"**{len(passing)} tests** with matching rendered output")
        md.append("")
        md.append("| # | Test | Trace | Duration |")
        md.append("|---|------|-------|----------|")
        for i, t in enumerate(passing, 1):
            trace = "PASS" if t["trace_status"] == "pass" else t["trace_status"].upper()
            dur = f"{t['duration']:.1f}s"
            md.append(f"| {i} | `{t['test']}` | {trace} | {dur} |")
        md.append("")
    else:
        md.append("No image tests passing yet.")
        md.append("")

    # Failing image tests — sorted by outlier count (ascending = closest to passing)
    failing = [t for t in tests if t["image_status"] == "fail"]
    def _sort_key(t):
        """Sort by total outliers across all comparisons (lowest first)."""
        total_outliers = 0
        for r in t.get("image_comparisons", {}).values():
            o = _parse_outliers(r.get("message", ""))
            if o is not None:
                total_outliers += o
        return total_outliers
    failing.sort(key=_sort_key)

    md.append("## Failing Image Tests")
    md.append("")
    if failing:
        md.append(f"**{len(failing)} tests** with image comparison failures (sorted by outlier count, closest to passing first)")
        md.append("")
        md.append("| # | Test | Trace | Image Result | Duration |")
        md.append("|---|------|-------|-------------|----------|")
        for i, t in enumerate(failing, 1):
            trace = "PASS" if t["trace_status"] == "pass" else t["trace_status"].upper()
            img_summary = _format_image_summary(t.get("image_comparisons", {}))
            dur = f"{t['duration']:.1f}s"
            md.append(f"| {i} | `{t['test']}` | {trace} | {img_summary} | {dur} |")
        md.append("")
    else:
        md.append("No image test failures.")
        md.append("")

    # Tests that couldn't render (build/runtime failures)
    no_render = [t for t in tests if t["image_status"] == "no_render"]
    no_render.sort(key=lambda t: t["test"])
    if no_render:
        md.append("## Tests That Could Not Render")
        md.append("")
        md.append(f"**{len(no_render)} tests** failed before image comparison (build or runtime error)")
        md.append("")
        md.append("| # | Test | Status | Duration |")
        md.append("|---|------|--------|----------|")
        for i, t in enumerate(no_render, 1):
            dur = f"{t['duration']:.1f}s"
            md.append(f"| {i} | `{t['test']}` | {t['trace_status']} | {dur} |")
        md.append("")

    markdown = "\n".join(md)
    with open(output_path, "w") as f:
        f.write(markdown)

    print(f"Markdown report written to {output_path}")


def main():
    parser = argparse.ArgumentParser(
        description="Run Ruffle AVM1 image comparison tests (headless WebGPU)")
    parser.add_argument(
        "--test", metavar="NAME", action="append",
        help="Run specific test(s) (repeatable). Default: all image tests.")
    parser.add_argument(
        "--json", metavar="PATH", default=str(RESULTS_JSON),
        help=f"Output JSON path (default: {RESULTS_JSON.name})")
    parser.add_argument(
        "--md", metavar="PATH", default=str(RESULTS_MD),
        help=f"Output markdown path (default: {RESULTS_MD.name})")
    parser.add_argument(
        "--report-only", action="store_true",
        help="Skip running tests; regenerate .md from existing JSON")
    parser.add_argument(
        "--no-report", action="store_true",
        help="Skip markdown generation")
    args = parser.parse_args()

    json_path = Path(args.json)
    md_path = Path(args.md)

    if args.report_only:
        if not json_path.exists():
            print(f"Error: {json_path} not found", file=sys.stderr)
            sys.exit(1)
        generate_markdown(json_path, md_path)
        return

    # Discover tests
    if args.test:
        all_image_tests = discover_image_tests()
        tests = []
        for t in args.test:
            if t not in all_image_tests:
                print(f"Warning: '{t}' does not have image_comparisons in test.toml")
            tests.append(t)
    else:
        tests = discover_image_tests()

    if not tests:
        print("No image comparison tests found.")
        sys.exit(0)

    print(f"Running {len(tests)} image comparison test(s)...")
    print()

    run_start = time.monotonic()
    test_results = []

    for i, name in enumerate(tests):
        print(f"[{i+1}/{len(tests)}] {name}...", end=" ", flush=True)
        try:
            entry, stdout = run_single_test(name)
        except subprocess.TimeoutExpired:
            entry = {
                "test": name,
                "duration": 300.0,
                "trace_status": "timeout",
                "image_status": "no_render",
                "image_comparisons": {},
            }
            stdout = ""
        test_results.append(entry)

        # Print concise result
        img = entry["image_status"].upper()
        trace = entry["trace_status"].upper()
        parts = [f"image:{img}", f"trace:{trace}"]
        # Include image detail if available
        for cname, cresult in entry.get("image_comparisons", {}).items():
            if cresult["status"] != "pass":
                msg = cresult.get("message", "")
                if msg:
                    parts.append(msg[:80])
        print(f"{' | '.join(parts)} ({entry['duration']:.1f}s)")

    # Build and write JSON report
    report = build_report(test_results, run_start)
    with open(json_path, "w") as f:
        json.dump(report, f, indent=2)
    print(f"\nResults written to {json_path}")

    # Print summary
    print(f"\n{'='*60}")
    print(f"Total:        {report['total']}")
    print(f"Image pass:   {report['image_pass']}")
    print(f"Image fail:   {report['image_fail']}")
    print(f"No render:    {report['image_no_render']}")
    print(f"Trace pass:   {report['trace_pass']}")
    print(f"{'='*60}")

    # Generate markdown
    if not args.no_report:
        generate_markdown(json_path, md_path)


if __name__ == "__main__":
    main()
