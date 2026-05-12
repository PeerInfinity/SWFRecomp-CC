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
import glob
import json
import os
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path

try:
    import tomllib
except ImportError:
    import tomli as tomllib

SCRIPT_DIR = Path(__file__).parent.resolve()
TESTS_DIR = SCRIPT_DIR / "tests" / "swfs"
VERIFY_SCRIPT = SCRIPT_DIR / "verify_output.py"
RESULTS_JSON = SCRIPT_DIR / "image_results.json"
RESULTS_MD = SCRIPT_DIR.parent / "ruffle-image-results.md"
RESULTS_HTML = SCRIPT_DIR.parent / "ruffle-image-results.html"


_DISCOVERY_SKIP_DIRS = {
    "__framework__", "_investigation", "_image-test-output", "_results",
    "RecompiledScripts", "RecompiledTags",
}


def discover_image_tests():
    """Find all test dirs (at any nesting depth) with [image_comparisons]
    in their test.toml. Returns sorted relative paths (posix-style)."""
    tests = []

    def _walk(current):
        toml_path = current / "test.toml"
        if (current / "test.swf").exists() and toml_path.exists():
            try:
                with open(toml_path, "rb") as f:
                    data = tomllib.load(f)
            except Exception:
                return
            if data.get("image_comparisons"):
                rel = current.relative_to(TESTS_DIR).as_posix()
                if rel and rel != ".":
                    tests.append(rel)
            return
        try:
            children = sorted(current.iterdir())
        except (NotADirectoryError, PermissionError):
            return
        for child in children:
            if not child.is_dir():
                continue
            if child.name in _DISCOVERY_SKIP_DIRS or child.name.startswith("."):
                continue
            _walk(child)

    _walk(TESTS_DIR)
    return sorted(tests)


def run_single_test(test_name):
    """Run a single image comparison test via verify_output.py.

    Returns (entry_dict, stdout_text).
    """
    # --json=<sink> keeps verify_output.py from clobbering its default
    # per-mode results file (tests/swfs/_results/results_graphics.json)
    # on every single-test invocation. We don't read this JSON — the
    # canonical output is image_results.json written below.
    json_sink = tempfile.NamedTemporaryFile(
        prefix="verify_sink_", suffix=".json", delete=False).name
    cmd = [
        sys.executable, str(VERIFY_SCRIPT),
        f"--tests-dir={TESTS_DIR}",
        f"--test={test_name}",
        "--mode=graphics",
        f"--json={json_sink}",
        "--verbose",
        "--diff",
    ]

    start = time.monotonic()
    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=300)
    finally:
        try:
            os.unlink(json_sink)
        except OSError:
            pass
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

    # Parse outlier counts from messages for strict vs tolerance classification
    import re
    for cmp_name, r in image_results.items():
        msg = r.get("message", "")
        m = re.search(r'(\d+) outliers', msg)
        r["outliers"] = int(m.group(1)) if m else None
        m2 = re.search(r'max difference (\d+)', msg)
        r["max_diff"] = int(m2.group(1)) if m2 else None

    entry["image_comparisons"] = image_results

    # Determine overall image status (tolerance-based, as reported by verify_output.py)
    if not image_results:
        entry["image_status"] = "no_render"
    elif all(r["status"] == "pass" for r in image_results.values()):
        entry["image_status"] = "pass"
    elif all(r["status"] == "skip" for r in image_results.values()):
        entry["image_status"] = "skip"
    else:
        entry["image_status"] = "fail"

    # Determine strict image status (0 outliers, 0 max_diff)
    if not image_results:
        entry["image_status_strict"] = "no_render"
    elif all(r.get("outliers") == 0 and r.get("max_diff", 0) == 0
             for r in image_results.values() if r["status"] != "skip"):
        entry["image_status_strict"] = "pass"
    elif all(r["status"] == "skip" for r in image_results.values()):
        entry["image_status_strict"] = "skip"
    else:
        entry["image_status_strict"] = "fail"

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
    strict_pass = sum(1 for t in test_results if t.get("image_status_strict") == "pass")
    strict_fail = sum(1 for t in test_results if t.get("image_status_strict") == "fail")
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
        "strict_pass": strict_pass,
        "strict_fail": strict_fail,
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
    strict_pass = data.get("strict_pass", 0)
    trace_pass = data["trace_pass"]

    tolerance_only_count = image_pass - strict_pass

    md.append("## Summary")
    md.append("")
    md.append("| Metric | Value |")
    md.append("|--------|-------|")
    md.append(f"| Total image tests | {total} |")
    md.append(f"| Strict image pass (exact pixel match) | **{strict_pass}** ({100*strict_pass/total:.0f}%) |" if total else "| Strict image pass | 0 |")
    md.append(f"| Tolerance-only pass (non-zero diff within test.toml limits) | **{tolerance_only_count}** |" if total else "| Tolerance-only pass | 0 |")
    md.append(f"| **Total image pass** | **{image_pass}** ({100*image_pass/total:.0f}%) |" if total else "| Total image pass | 0 |")
    md.append(f"| Image failing | {image_fail} |")
    md.append(f"| No render (build/runtime fail) | {image_no_render} |")
    md.append(f"| Trace output passing | {trace_pass} ({100*trace_pass/total:.0f}%) |" if total else "| Trace passing | 0 |")
    md.append("")

    tests = data["tests"]

    # Strict passing image tests (0 outliers, exact match)
    strict_passing = [t for t in tests if t.get("image_status_strict") == "pass"]
    strict_passing.sort(key=lambda t: t["test"])
    md.append("## Strict Passing Image Tests (exact pixel match)")
    md.append("")
    if strict_passing:
        md.append(f"**{len(strict_passing)} tests** with 0 outliers across all image comparisons")
        md.append("")
        md.append("| # | Test | Trace | Duration |")
        md.append("|---|------|-------|----------|")
        for i, t in enumerate(strict_passing, 1):
            trace = "PASS" if t["trace_status"] == "pass" else t["trace_status"].upper()
            dur = f"{t['duration']:.1f}s"
            md.append(f"| {i} | `{t['test']}` | {trace} | {dur} |")
        md.append("")
    else:
        md.append("No tests with exact pixel match.")
        md.append("")

    # Tolerance-only passing (pass with tolerance but not strict)
    tolerance_only = [t for t in tests
                      if t["image_status"] == "pass"
                      and t.get("image_status_strict") != "pass"]
    tolerance_only.sort(key=lambda t: t["test"])
    if tolerance_only:
        md.append("## Tolerance-Only Passing (non-zero outliers within test.toml limits)")
        md.append("")
        md.append(f"**{len(tolerance_only)} tests** pass within configured tolerance but have image differences")
        md.append("")
        md.append("| # | Test | Trace | Outliers | Max Diff | Duration |")
        md.append("|---|------|-------|---------|----------|----------|")
        for i, t in enumerate(tolerance_only, 1):
            trace = "PASS" if t["trace_status"] == "pass" else t["trace_status"].upper()
            dur = f"{t['duration']:.1f}s"
            # Summarize outliers across comparisons
            total_outliers = 0
            worst_diff = 0
            for r in t.get("image_comparisons", {}).values():
                o = r.get("outliers")
                if o is not None:
                    total_outliers += o
                d = r.get("max_diff", 0)
                if d and d > worst_diff:
                    worst_diff = d
            md.append(f"| {i} | `{t['test']}` | {trace} | {total_outliers:,} | {worst_diff} | {dur} |")
        md.append("")

    # Failing image tests — sorted by outlier count (ascending = closest to passing)
    failing = [t for t in tests if t["image_status"] == "fail"]
    def _sort_key(t):
        """Sort by total outliers across all comparisons (lowest first)."""
        total_outliers = 0
        for r in t.get("image_comparisons", {}).values():
            o = r.get("outliers")
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


HTML_TEMPLATE = r"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<title>Ruffle Image Test Results</title>
<style>
  :root {
    --bg: #1a1a1a; --fg: #e8e8e8; --muted: #888; --card: #242424;
    --border: #333; --accent: #4a9eff;
    --strict: #4caf50; --tolerance: #d4a017; --fail: #e53935; --norender: #666;
  }
  body.light {
    --bg: #fafafa; --fg: #222; --muted: #666; --card: #fff;
    --border: #ddd; --accent: #1565c0;
  }
  * { box-sizing: border-box; }
  body { margin: 0; font: 14px/1.4 -apple-system, BlinkMacSystemFont, "Segoe UI", sans-serif;
         background: var(--bg); color: var(--fg); }
  header.page { padding: 16px 24px; border-bottom: 1px solid var(--border);
                position: sticky; top: 0; background: var(--bg); z-index: 10; }
  header.page h1 { margin: 0 0 4px 0; font-size: 18px; }
  .meta { color: var(--muted); font-size: 12px; margin-bottom: 12px; }
  .meta code { color: var(--fg); }
  .controls { display: flex; flex-wrap: wrap; gap: 12px; align-items: center; }
  .filter-group { display: inline-flex; gap: 4px; align-items: center; }
  .filter-group .label { color: var(--muted); font-size: 11px; text-transform: uppercase; margin-right: 4px; }
  .chip { padding: 4px 10px; border: 1px solid var(--border); border-radius: 12px;
          background: var(--card); cursor: pointer; font-size: 12px; user-select: none; }
  .chip.active { background: var(--accent); color: white; border-color: var(--accent); }
  .chip .count { color: var(--muted); margin-left: 4px; font-size: 11px; }
  .chip.active .count { color: rgba(255,255,255,0.8); }
  input[type=search], select { padding: 4px 8px; background: var(--card); color: var(--fg);
                                border: 1px solid var(--border); border-radius: 4px; font-size: 12px; }
  input[type=search] { min-width: 200px; }
  main { padding: 16px 24px; }
  .card { background: var(--card); border: 1px solid var(--border); border-radius: 6px;
          margin-bottom: 12px; overflow: hidden; }
  .card.hidden { display: none; }
  .card-header { display: flex; align-items: center; gap: 12px; padding: 10px 14px;
                 border-bottom: 1px solid var(--border); cursor: pointer; }
  .card-name { font-family: ui-monospace, "SF Mono", Consolas, monospace; font-weight: 600; flex: 1; }
  .badge { padding: 2px 8px; border-radius: 10px; font-size: 11px; font-weight: 600;
           text-transform: uppercase; letter-spacing: 0.04em; }
  .badge-strict     { background: var(--strict); color: white; }
  .badge-tolerance  { background: var(--tolerance); color: #1a1a1a; }
  .badge-fail       { background: var(--fail); color: white; }
  .badge-no-render  { background: var(--norender); color: white; }
  .max-diff { color: var(--muted); font-size: 12px; font-family: ui-monospace, monospace; }
  .card-body { padding: 8px 14px 14px; }
  .card.collapsed .card-body { display: none; }
  .comparison { margin: 8px 0; }
  .cmp-name { font-family: ui-monospace, monospace; font-size: 12px; color: var(--muted); margin: 6px 0 4px; }
  .triptych { display: flex; gap: 8px; flex-wrap: wrap; }
  .triptych figure { margin: 0; text-align: center; background: #000;
                      border: 1px solid var(--border); padding: 4px; }
  .triptych figure img { display: block; max-width: 280px; max-height: 280px;
                          image-rendering: pixelated; background:
                            repeating-conic-gradient(#222 0% 25%, #2a2a2a 0% 50%) 50% / 16px 16px; }
  body.light .triptych figure img { background:
    repeating-conic-gradient(#e8e8e8 0% 25%, #d8d8d8 0% 50%) 50% / 16px 16px; }
  .triptych figcaption { color: var(--muted); font-size: 10px; padding-top: 4px;
                          text-transform: uppercase; letter-spacing: 0.04em; }
  .triptych figure.missing img { width: 100px; height: 100px; }
  .triptych figure.missing::after { content: "no image"; color: var(--muted); font-size: 10px; }
  .cmp-detail { color: var(--muted); font-size: 12px; margin-top: 6px;
                font-family: ui-monospace, monospace; }
  .empty { color: var(--muted); padding: 40px; text-align: center; font-style: italic; }
  .toggle-theme { background: transparent; color: var(--fg); border: 1px solid var(--border);
                   padding: 4px 10px; border-radius: 4px; cursor: pointer; font-size: 12px; }
</style>
</head>
<body>
<header class="page">
  <h1>Ruffle Image Test Results</h1>
  <div class="meta">
    <span id="meta-sha">SHA: <code>…</code></span> ·
    <span id="meta-ts">…</span> ·
    <span id="meta-counts">…</span>
  </div>
  <div class="controls">
    <div class="filter-group">
      <span class="label">Status</span>
      <span class="chip active" data-status-filter="all">All</span>
      <span class="chip" data-status-filter="fail">Fail</span>
      <span class="chip" data-status-filter="tolerance">Tolerance</span>
      <span class="chip" data-status-filter="strict">Strict</span>
      <span class="chip" data-status-filter="no-render">No render</span>
    </div>
    <div class="filter-group" id="suite-filters">
      <span class="label">Suite</span>
      <span class="chip active" data-suite-filter="all">All</span>
    </div>
    <input type="search" id="search" placeholder="filter by name…">
    <select id="sort">
      <option value="status">Sort: status (worst first)</option>
      <option value="name">Sort: name</option>
      <option value="max-diff-desc">Sort: max diff (desc)</option>
    </select>
    <button class="toggle-theme" id="toggle-theme">☀</button>
  </div>
</header>
<main id="cards"></main>
<script>
const RESULTS = __RESULTS_JSON__;
const IMG_ROOT = "__IMG_ROOT__";

function classify(t) {
  if (t.image_status === "no_render") return "no-render";
  if (t.image_status === "fail")      return "fail";
  if (t.image_status_strict === "pass") return "strict";
  if (t.image_status === "pass")      return "tolerance";
  return "fail";
}
function maxDiff(t) {
  let m = 0;
  for (const c of Object.values(t.image_comparisons || {}))
    if (typeof c.max_diff === "number" && c.max_diff > m) m = c.max_diff;
  return m;
}
function statusRank(s) {
  return {fail:0, "no-render":1, tolerance:2, strict:3}[s] ?? 4;
}

const tests = (RESULTS.tests || []).map(t => ({
  ...t,
  suite: t.test.split("/")[0],
  klass: classify(t),
  max_diff: maxDiff(t),
}));

const statusCounts = {all: tests.length, fail:0, tolerance:0, strict:0, "no-render":0};
for (const t of tests) statusCounts[t.klass]++;

const suiteCounts = {all: tests.length};
for (const t of tests) suiteCounts[t.suite] = (suiteCounts[t.suite] || 0) + 1;

document.querySelectorAll("[data-status-filter]").forEach(c => {
  const k = c.dataset.statusFilter;
  c.innerHTML += ` <span class="count">${statusCounts[k] ?? 0}</span>`;
});
const suiteContainer = document.getElementById("suite-filters");
for (const suite of Object.keys(suiteCounts).filter(s => s !== "all").sort()) {
  const chip = document.createElement("span");
  chip.className = "chip";
  chip.dataset.suiteFilter = suite;
  chip.innerHTML = `${suite} <span class="count">${suiteCounts[suite]}</span>`;
  suiteContainer.appendChild(chip);
}
document.querySelector('[data-suite-filter="all"]').innerHTML += ` <span class="count">${suiteCounts.all}</span>`;

document.getElementById("meta-sha").innerHTML = `SHA: <code>${(RESULTS.metadata?.git_sha || "?").slice(0,8)}</code>`;
document.getElementById("meta-ts").textContent = RESULTS.metadata?.timestamp || "?";
document.getElementById("meta-counts").innerHTML =
  `${RESULTS.total} total · ` +
  `<span style="color:var(--strict)">strict ${RESULTS.strict_pass}</span> · ` +
  `<span style="color:var(--tolerance)">tolerance ${RESULTS.image_pass - RESULTS.strict_pass}</span> · ` +
  `<span style="color:var(--fail)">fail ${RESULTS.image_fail}</span> · ` +
  `<span style="color:var(--norender)">no-render ${RESULTS.image_no_render}</span>`;

const state = { status: "all", suite: "all", search: "", sort: "status" };

function renderCard(t) {
  const card = document.createElement("article");
  card.className = "card";
  card.dataset.status = t.klass;
  card.dataset.suite = t.suite;
  card.dataset.name = t.test;

  const labelByStatus = {
    strict: "STRICT", tolerance: "TOLERANCE", fail: "FAIL", "no-render": "NO RENDER",
  };

  const header = document.createElement("div");
  header.className = "card-header";
  header.innerHTML = `
    <span class="card-name">${t.test}</span>
    <span class="badge badge-${t.klass}">${labelByStatus[t.klass]}</span>
    <span class="max-diff">max_diff: ${t.max_diff}</span>
  `;
  header.addEventListener("click", () => card.classList.toggle("collapsed"));
  card.appendChild(header);

  const body = document.createElement("div");
  body.className = "card-body";
  for (const [cmpName, cmp] of Object.entries(t.image_comparisons || {})) {
    const cmpDiv = document.createElement("div");
    cmpDiv.className = "comparison";
    const showDiff = (cmp.status !== "pass") || (cmp.max_diff && cmp.max_diff > 0);
    const dir = `${IMG_ROOT}/${t.test}`;
    cmpDiv.innerHTML = `
      <div class="cmp-name">${cmpName} — ${cmp.status} (max_diff ${cmp.max_diff ?? "?"})</div>
      <div class="triptych">
        <figure><a href="${dir}/${cmpName}.expected.png" target="_blank"><img loading="lazy" src="${dir}/${cmpName}.expected.png" alt="expected"></a><figcaption>expected</figcaption></figure>
        <figure><a href="${dir}/${cmpName}.actual.png" target="_blank"><img loading="lazy" src="${dir}/${cmpName}.actual.png" alt="actual" onerror="this.parentElement.parentElement.classList.add('missing'); this.remove();"></a><figcaption>actual</figcaption></figure>
        ${showDiff ? `<figure><a href="${dir}/${cmpName}.difference.png" target="_blank"><img loading="lazy" src="${dir}/${cmpName}.difference.png" alt="diff" onerror="this.parentElement.parentElement.classList.add('missing'); this.remove();"></a><figcaption>diff</figcaption></figure>` : ""}
      </div>
      ${cmp.message ? `<div class="cmp-detail">${cmp.message}</div>` : ""}
    `;
    body.appendChild(cmpDiv);
  }
  card.appendChild(body);
  return card;
}

function refresh() {
  const container = document.getElementById("cards");
  const search = state.search.toLowerCase();
  let filtered = tests.filter(t =>
    (state.status === "all" || t.klass === state.status) &&
    (state.suite === "all" || t.suite === state.suite) &&
    (search === "" || t.test.toLowerCase().includes(search))
  );
  if (state.sort === "name") filtered.sort((a,b) => a.test.localeCompare(b.test));
  else if (state.sort === "max-diff-desc") filtered.sort((a,b) => b.max_diff - a.max_diff || a.test.localeCompare(b.test));
  else filtered.sort((a,b) => statusRank(a.klass) - statusRank(b.klass) || a.test.localeCompare(b.test));

  container.innerHTML = "";
  if (filtered.length === 0) {
    container.innerHTML = '<div class="empty">no tests match the current filters</div>';
    return;
  }
  for (const t of filtered) container.appendChild(renderCard(t));
}

document.querySelectorAll("[data-status-filter]").forEach(c => c.addEventListener("click", () => {
  document.querySelectorAll("[data-status-filter]").forEach(x => x.classList.remove("active"));
  c.classList.add("active");
  state.status = c.dataset.statusFilter;
  refresh();
}));
function wireSuites() {
  document.querySelectorAll("[data-suite-filter]").forEach(c => c.addEventListener("click", () => {
    document.querySelectorAll("[data-suite-filter]").forEach(x => x.classList.remove("active"));
    c.classList.add("active");
    state.suite = c.dataset.suiteFilter;
    refresh();
  }));
}
wireSuites();
document.getElementById("search").addEventListener("input", e => { state.search = e.target.value; refresh(); });
document.getElementById("sort").addEventListener("change", e => { state.sort = e.target.value; refresh(); });
document.getElementById("toggle-theme").addEventListener("click", () => {
  document.body.classList.toggle("light");
  document.getElementById("toggle-theme").textContent = document.body.classList.contains("light") ? "☾" : "☀";
});

refresh();
</script>
</body>
</html>
"""


def generate_html(results_path, output_path):
    """Render a self-contained HTML viewer for the image-test results."""
    with open(results_path) as f:
        data = json.load(f)

    # Relative path from the HTML file's dir to _image-test-output/.
    # Default html_path is the project root, so this resolves to
    # ruffle-tests/tests/swfs/_image-test-output. If the user redirects
    # --html to a different location we recompute accordingly.
    image_root_abs = TESTS_DIR / "_image-test-output"
    try:
        rel = os.path.relpath(image_root_abs, output_path.parent)
    except ValueError:
        # Different drives on Windows — fall back to absolute path.
        rel = str(image_root_abs)
    rel = rel.replace(os.sep, "/")

    html = (HTML_TEMPLATE
            .replace("__RESULTS_JSON__", json.dumps(data))
            .replace("__IMG_ROOT__", rel))
    with open(output_path, "w") as f:
        f.write(html)
    print(f"HTML report written to {output_path}")


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
        "--html", metavar="PATH", default=str(RESULTS_HTML),
        help=f"Output HTML path (default: {RESULTS_HTML.name})")
    parser.add_argument(
        "--report-only", action="store_true",
        help="Skip running tests; regenerate .md from existing JSON")
    parser.add_argument(
        "--collect-only", action="store_true",
        help="Skip running tests; just gather *.png from each discovered "
             "test dir into _image-test-output/. Useful for rebuilding the "
             "gathered tree from leftover --verbose run artifacts.")
    parser.add_argument(
        "--rebuild-json", action="store_true",
        help="Skip running tests; rebuild image_results.json (and the "
             "MD/HTML reports) by re-running compare_images() over the "
             "*.expected.png / *.actual.png pairs already on disk. "
             "trace_status and duration are marked unknown / 0 since those "
             "only come from a fresh run.")
    parser.add_argument(
        "--no-report", action="store_true",
        help="Skip markdown generation")
    parser.add_argument(
        "--no-html", action="store_true",
        help="Skip HTML report generation")
    args = parser.parse_args()

    json_path = Path(args.json)
    md_path = Path(args.md)
    html_path = Path(args.html)

    if args.report_only:
        if not json_path.exists():
            print(f"Error: {json_path} not found", file=sys.stderr)
            sys.exit(1)
        if not args.no_report:
            generate_markdown(json_path, md_path)
        if not args.no_html:
            generate_html(json_path, html_path)
        return

    if args.collect_only:
        tests = discover_image_tests()
        print(f"Collecting image output for {len(tests)} test(s)...")
        collect_image_output(tests, full_sweep=True)
        return

    if args.rebuild_json:
        tests = discover_image_tests()
        print(f"Rebuilding {json_path} from on-disk PNGs over {len(tests)} test(s)...")
        rebuild_json_from_disk(tests, json_path)
        if not args.no_report:
            generate_markdown(json_path, md_path)
        if not args.no_html:
            generate_html(json_path, html_path)
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
        strict = entry.get("image_status_strict", "?").upper()
        tolerant = entry["image_status"].upper()
        trace = entry["trace_status"].upper()
        if strict == tolerant:
            img_label = f"image:{strict}"
        else:
            img_label = f"image:strict={strict},tolerance={tolerant}"
        parts = [img_label, f"trace:{trace}"]
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
    print(f"Total:              {report['total']}")
    print(f"Strict image pass:  {report['strict_pass']}  (0 outliers, exact pixel match)")
    print(f"Tolerance pass:     {report['image_pass'] - report['strict_pass']}  (non-zero diff within test.toml limits)")
    print(f"Total image pass:   {report['image_pass']}")
    print(f"Image fail:         {report['image_fail']}")
    print(f"No render:          {report['image_no_render']}")
    print(f"Trace pass:         {report['trace_pass']}")
    print(f"{'='*60}")

    # Generate markdown
    if not args.no_report:
        generate_markdown(json_path, md_path)
    if not args.no_html:
        generate_html(json_path, html_path)

    # Collect image output PNGs into _image-test-output/. A single-test
    # invocation (--test=foo) should refresh just that test's gathered
    # dir; a full-suite invocation does a complete sweep (clean rebuild).
    # Without this distinction, `--test=foo` after a full sweep would
    # rmtree the whole gathered tree and leave only foo's dir.
    collect_image_output(tests, full_sweep=not args.test)

    # verify_output.py's main() unconditionally creates RESULTS_DIR
    # (= TESTS_DIR / "_results"). With TESTS_DIR pointing at
    # tests/swfs (not a per-suite dir), that's a stray top-level
    # _results/ that doesn't belong to any suite. The per-test --json
    # redirect above keeps it empty, so just remove the empty dir.
    side_effect_results = TESTS_DIR / "_results"
    if side_effect_results.exists():
        try:
            side_effect_results.rmdir()
        except OSError:
            # Non-empty — leave it for the user to inspect.
            pass


def rebuild_json_from_disk(tests, json_path):
    """Recompute image_results.json from the persisted PNGs without running
    any tests. Reads each test.toml for its image_comparisons configuration
    and re-runs verify_output.compare_images() over the *.actual.png /
    *.expected.png pairs in each test dir.

    trace_status is set to "unknown" and duration to 0 because both
    signals only come from an actual run.
    """
    # Lazy import — verify_output pulls in PIL etc.
    sys.path.insert(0, str(SCRIPT_DIR))
    from verify_output import parse_image_comparisons, compare_images
    import re

    test_results = []
    run_start = time.monotonic()

    for name in tests:
        test_dir = TESTS_DIR / name
        cfg = parse_image_comparisons(test_dir)

        image_results = {}
        for cmp_name, cmp_cfg in cfg.items():
            actual = test_dir / f"{cmp_name}.actual.png"
            expected = test_dir / f"{cmp_name}.expected.png"
            # Fallback for expected: some tests keep upstream/<name>/<cmp>.expected.png
            # only — but verify_output's main run path copies them next to the test.
            # If neither exists, compare_images returns a meaningful error message.
            if not actual.exists():
                # Skip this cmp; if all cmps end up missing, the overall
                # status will fall through to "no_render" below.
                image_results[cmp_name] = {
                    "status": "fail",
                    "message": f"No actual image on disk ({actual.name}); rerun the test",
                    "outliers": None,
                    "max_diff": None,
                }
                continue
            passed, message, max_diff = compare_images(
                actual, expected, cmp_cfg["checks"])
            m = re.search(r'(\d+) outliers', message)
            outliers = int(m.group(1)) if m else None
            image_results[cmp_name] = {
                "status": "pass" if passed else "fail",
                "message": message,
                "outliers": outliers,
                "max_diff": max_diff,
            }

        entry = {
            "test": name,
            "duration": 0,
            "trace_status": "unknown",
            "image_comparisons": image_results,
        }

        # Status aggregation — mirrors run_single_test exactly so the
        # report consumers (build_report, generate_markdown, generate_html)
        # don't need to know we took a shortcut here.
        valid_pngs = {k: v for k, v in image_results.items()
                      if v["message"] and not v["message"].startswith("No actual image on disk")}
        if not image_results:
            entry["image_status"] = "no_render"
            entry["image_status_strict"] = "no_render"
        elif not valid_pngs:
            # All cmps had missing actual.png — treat as no_render so the
            # report flags it for rerun rather than counting as a fail.
            entry["image_status"] = "no_render"
            entry["image_status_strict"] = "no_render"
        else:
            if all(r["status"] == "pass" for r in image_results.values()):
                entry["image_status"] = "pass"
            elif all(r["status"] == "skip" for r in image_results.values()):
                entry["image_status"] = "skip"
            else:
                entry["image_status"] = "fail"
            if all(r.get("outliers") == 0 and r.get("max_diff", 0) == 0
                   for r in image_results.values() if r["status"] != "skip"):
                entry["image_status_strict"] = "pass"
            elif all(r["status"] == "skip" for r in image_results.values()):
                entry["image_status_strict"] = "skip"
            else:
                entry["image_status_strict"] = "fail"

        test_results.append(entry)

    report = build_report(test_results, run_start)
    with open(json_path, "w") as f:
        json.dump(report, f, indent=2)
    print(f"JSON report rebuilt from disk: {json_path} "
          f"({report['total']} tests; "
          f"strict={report['strict_pass']} "
          f"pass={report['image_pass']} "
          f"fail={report['image_fail']} "
          f"no_render={report['image_no_render']})")


def collect_image_output(tests, *, full_sweep=True):
    """Copy all PNG files from each test directory into _image-test-output/{test}/.

    full_sweep=True wipes _image-test-output/ first and rebuilds from `tests`.
    full_sweep=False preserves any per-test dirs not in `tests` (used for
    --test=X / single-test runs so a smoke check doesn't blow away gathered
    output from a prior full run).
    """
    output_root = TESTS_DIR / "_image-test-output"
    if full_sweep:
        if output_root.exists():
            shutil.rmtree(output_root)
        output_root.mkdir()
    else:
        output_root.mkdir(exist_ok=True)

    copied = 0
    for name in tests:
        test_dir = TESTS_DIR / name
        pngs = sorted(test_dir.glob("*.png"))
        if not pngs:
            continue
        dest = output_root / name
        if not full_sweep and dest.exists():
            # Refresh just this test's gathered files; stale PNGs from a
            # prior run with different capture names would otherwise linger.
            shutil.rmtree(dest)
        dest.mkdir(parents=True, exist_ok=True)
        for png in pngs:
            shutil.copy2(png, dest / png.name)
            copied += 1

    print(f"Image output collected in {output_root} ({copied} files)")


if __name__ == "__main__":
    main()
