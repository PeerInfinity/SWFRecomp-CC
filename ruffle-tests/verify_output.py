#!/usr/bin/env python3
"""Verify SWFRecomp runtime output against Ruffle AVM1 expected output.

Pipeline for each test:
1. Run SWFRecomp to generate C code (if not already done)
2. Compile generated C with SWFModernRuntime in NO_GRAPHICS mode
3. Run the native binary, capture stdout
4. Filter out runtime boilerplate, keep only trace output
5. Compare against output.txt
"""

import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from collections import Counter

SCRIPT_DIR = Path(__file__).parent
PROJECT_ROOT = SCRIPT_DIR.parent
RECOMP_BIN = PROJECT_ROOT / "SWFRecomp" / "build" / "SWFRecomp"
RECOMP_CONFIG = SCRIPT_DIR / "_shared" / "config.toml"
SWFMODERN = PROJECT_ROOT / "SWFModernRuntime"
MAIN_C = PROJECT_ROOT / "SWFRecomp" / "wasm_wrappers" / "main.c"

SKIP = {"_shared", "__framework__"}

# Lines to filter from runtime output
BOILERPLATE_PATTERNS = [
    re.compile(r"^SWF Runtime Loaded"),
    re.compile(r"^=== SWF Execution"),
    re.compile(r"^\[HEAP\]"),
    re.compile(r"^\[Frame \d+\]"),
    re.compile(r"^\[Tag\] ShowFrame"),
    re.compile(r"^No function for frame"),
    re.compile(r"^WASM SWF Runtime"),
    re.compile(r"^This is a recompiled"),
    re.compile(r"^Call runSWF"),
    re.compile(r"^Starting SWF execution"),
]


OUTPUT_CONTEXT_LINES = 50
OUTPUT_CONTEXT_BEFORE = 5


def snippet_around_mismatch(actual, expected, max_lines=OUTPUT_CONTEXT_LINES,
                            before=OUTPUT_CONTEXT_BEFORE):
    """Return (actual_snippet, expected_snippet) centered on the first mismatch.

    Shows `before` lines of matching context, then up to max_lines - before
    lines from the mismatch onward. Adds truncation notes if trimmed.
    """
    actual_lines = actual.split("\n")
    expected_lines = expected.split("\n")

    # Find first mismatching line
    first_diff = 0
    for i in range(min(len(actual_lines), len(expected_lines))):
        if actual_lines[i] != expected_lines[i]:
            first_diff = i
            break
    else:
        # All common lines match — mismatch is due to different lengths
        first_diff = min(len(actual_lines), len(expected_lines))

    start = max(0, first_diff - before)
    end_actual = min(len(actual_lines), start + max_lines)
    end_expected = min(len(expected_lines), start + max_lines)

    def format_snippet(lines, start, end, total):
        parts = []
        if start > 0:
            parts.append(f"... ({start} lines before) ...")
        parts.extend(lines[start:end])
        remaining = total - end
        if remaining > 0:
            parts.append(f"... ({remaining} lines after) ...")
        return "\n".join(parts)

    return (format_snippet(actual_lines, start, end_actual, len(actual_lines)),
            format_snippet(expected_lines, start, end_expected, len(expected_lines)))


def get_git_sha():
    """Get the current git commit SHA, or None."""
    try:
        result = subprocess.run(
            ["git", "rev-parse", "HEAD"],
            cwd=str(PROJECT_ROOT),
            capture_output=True, text=True, timeout=5,
        )
        if result.returncode == 0:
            return result.stdout.strip()
    except Exception:
        pass
    return None


def get_num_frames(test_dir):
    """Parse num_frames from test.toml, default 1."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        m = re.search(r"num_frames\s*=\s*(\d+)", toml_path.read_text())
        if m:
            return int(m.group(1))
    return 1


def filter_output(raw_output):
    """Remove runtime boilerplate, return only trace lines."""
    lines = raw_output.split("\n")
    filtered = []
    for line in lines:
        if any(p.match(line) for p in BOILERPLATE_PATTERNS):
            continue
        filtered.append(line)

    # Strip leading/trailing blank lines
    while filtered and filtered[0].strip() == "":
        filtered.pop(0)
    while filtered and filtered[-1].strip() == "":
        filtered.pop()

    return "\n".join(filtered)


def recompile_swf(test_dir):
    """Run SWFRecomp on test.swf if not already done."""
    if (test_dir / "RecompiledScripts").exists():
        return True

    try:
        result = subprocess.run(
            [str(RECOMP_BIN), str(RECOMP_CONFIG)],
            cwd=str(test_dir),
            capture_output=True,
            text=True,
            timeout=30,
        )
        return result.returncode == 0
    except subprocess.TimeoutExpired:
        return False


def compile_native(test_dir, num_frames, build_dir):
    """Compile generated C code with runtime into native binary."""
    mem_dir = build_dir / "memory"
    mem_dir.mkdir(exist_ok=True)

    # Copy runtime sources
    for src in [
        "src/actionmodern/action.c",
        "src/actionmodern/variables.c",
        "src/actionmodern/object.c",
        "src/utils.c",
        "src/libswf/swf_core.c",
        "src/libswf/tag_stubs.c",
        "src/memory/heap.c",
    ]:
        shutil.copy2(SWFMODERN / src, build_dir)

    shutil.copy2(SWFMODERN / "lib/c-hashmap/map.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.h", build_dir)
    shutil.copy2(SWFMODERN / "include/memory/heap.h", mem_dir)
    shutil.copy2(MAIN_C, build_dir)

    # Copy generated files
    for folder in ["RecompiledScripts", "RecompiledTags"]:
        src_dir = test_dir / folder
        if src_dir.exists():
            for f in src_dir.iterdir():
                if f.suffix in (".c", ".h"):
                    shutil.copy2(f, build_dir)

    # Compile
    inc = SWFMODERN / "include"
    result = subprocess.run(
        [
            "gcc",
            *[str(f) for f in sorted(build_dir.glob("*.c"))],
            "-DNO_GRAPHICS",
            f"-DMAX_FRAMES={num_frames}",
            "-D_POSIX_C_SOURCE=199309L",
            f"-I{build_dir}",
            f"-I{inc}",
            f"-I{inc}/actionmodern",
            f"-I{inc}/libswf",
            f"-I{inc}/memory",
            f"-I{SWFMODERN}/lib/c-hashmap",
            "-w",
            "-std=c17",
            "-O2",
            "-o",
            str(build_dir / "test_run"),
            "-lm",
        ],
        capture_output=True,
        text=True,
        timeout=30,
    )
    return result.returncode == 0, result.stderr


def run_binary(build_dir):
    """Run the compiled binary and capture output."""
    try:
        result = subprocess.run(
            [str(build_dir / "test_run")],
            capture_output=True,
            text=True,
            timeout=10,
        )
        return result.stdout, result.returncode
    except subprocess.TimeoutExpired:
        return None, -1


def compare_output(actual, expected):
    """Compare filtered actual output with expected output.
    Returns (match, diff_summary, stats_dict)."""
    actual_lines = actual.split("\n")
    expected_lines = expected.rstrip("\n").split("\n")

    max_lines = max(len(actual_lines), len(expected_lines))
    matching = sum(
        1
        for i in range(max_lines)
        if (actual_lines[i] if i < len(actual_lines) else "<missing>")
        == (expected_lines[i] if i < len(expected_lines) else "<missing>")
    )
    line_stats = {
        "actual_lines": len(actual_lines),
        "expected_lines": len(expected_lines),
        "matching_lines": matching,
    }

    if actual_lines == expected_lines:
        return True, "", line_stats

    # Generate a brief diff summary
    diff = []
    mismatches = 0
    for i in range(min(max_lines, 20)):
        a = actual_lines[i] if i < len(actual_lines) else "<missing>"
        e = expected_lines[i] if i < len(expected_lines) else "<missing>"
        if a != e:
            mismatches += 1
            if mismatches <= 3:
                diff.append(f"  line {i+1}: got {a!r}, expected {e!r}")

    total_mismatches = max_lines - matching
    summary = f"{total_mismatches} line(s) differ (actual={len(actual_lines)}, expected={len(expected_lines)})"
    if diff:
        summary += "\n" + "\n".join(diff)
    return False, summary, line_stats


def main():
    if not RECOMP_BIN.exists():
        print(f"Error: SWFRecomp not found at {RECOMP_BIN}")
        sys.exit(1)

    verbose = "--verbose" in sys.argv or "-v" in sys.argv
    list_pass = "--list-pass" in sys.argv
    list_fail = "--list-fail" in sys.argv
    show_diff = "--diff" in sys.argv
    json_path = None
    limit = None
    for arg in sys.argv[1:]:
        if arg.startswith("--limit="):
            limit = int(arg.split("=")[1])
        if arg.startswith("--json="):
            json_path = arg.split("=", 1)[1]
        if arg.startswith("--test="):
            # Run a single test
            test_name = arg.split("=")[1]
            tests = [test_name]
            break
    else:
        tests = sorted(
            d.name
            for d in SCRIPT_DIR.iterdir()
            if d.is_dir()
            and d.name not in SKIP
            and (d / "test.swf").exists()
            and (d / "output.txt").exists()
        )

    total_available = len(tests)
    if limit:
        tests = tests[:limit]

    run_start = time.monotonic()
    stats = Counter()
    pass_list = []
    fail_list = []
    fail_details = {}
    test_results = []  # Per-test results for JSON output

    for i, name in enumerate(tests):
        test_dir = SCRIPT_DIR / name
        if verbose:
            print(f"[{i+1}/{len(tests)}] {name}...", end=" ", flush=True)

        test_start = time.monotonic()
        num_frames = get_num_frames(test_dir)
        entry = {"test": name, "num_frames": num_frames}

        # Step 1: Recompile SWF
        if not recompile_swf(test_dir):
            stats["recomp_fail"] += 1
            fail_list.append(name)
            fail_details[name] = "SWFRecomp failed"
            entry.update(status="recomp_fail", detail="SWFRecomp failed",
                         duration=round(time.monotonic() - test_start, 2))
            test_results.append(entry)
            if verbose:
                print("RECOMP_FAIL")
            continue

        # Step 2: Compile native
        with tempfile.TemporaryDirectory(prefix="swf_verify_") as tmpdir:
            build_dir = Path(tmpdir)
            ok, err = compile_native(test_dir, num_frames, build_dir)
            if not ok:
                stats["compile_fail"] += 1
                fail_list.append(name)
                # Categorize compile error
                if "error:" in err:
                    first_err = next(
                        (l for l in err.splitlines() if "error:" in l), err[:200]
                    )
                    detail = first_err.strip()[:200]
                else:
                    detail = err[:200]
                fail_details[name] = f"compile: {detail[:120]}"
                entry.update(status="compile_fail", detail=detail,
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if verbose:
                    print("COMPILE_FAIL")
                continue

            # Step 3: Run binary
            raw_output, rc = run_binary(build_dir)
            if raw_output is None:
                stats["timeout"] += 1
                fail_list.append(name)
                fail_details[name] = "runtime timeout"
                entry.update(status="timeout", detail="runtime timeout (>10s)",
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if verbose:
                    print("TIMEOUT")
                continue
            if rc != 0 and rc not in (-11, 139):
                stats["runtime_error"] += 1
                fail_list.append(name)
                fail_details[name] = f"runtime error (rc={rc})"
                entry.update(status="runtime_error", detail=f"exit code {rc}",
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if verbose:
                    print(f"RUNTIME_ERROR(rc={rc})")
                continue
            if rc in (-11, 139):
                stats["runtime_segfault"] += 1
                fail_list.append(name)
                fail_details[name] = "runtime segfault"
                entry.update(status="segfault", detail="SIGSEGV",
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if verbose:
                    print("SEGFAULT")
                continue

        # Step 4: Filter and compare
        actual = filter_output(raw_output)
        expected = (test_dir / "output.txt").read_text().rstrip("\n")

        match, diff_summary, line_stats = compare_output(actual, expected)
        entry["lines"] = line_stats
        entry["duration"] = round(time.monotonic() - test_start, 2)
        if match:
            stats["pass"] += 1
            pass_list.append(name)
            entry["status"] = "pass"
            test_results.append(entry)
            if verbose:
                print("PASS")
        else:
            stats["output_mismatch"] += 1
            fail_list.append(name)
            fail_details[name] = diff_summary
            entry["status"] = "output_mismatch"
            entry["detail"] = diff_summary.split("\n")[0]  # first line only
            actual_snip, expected_snip = snippet_around_mismatch(actual, expected)
            entry["actual_output"] = actual_snip
            entry["expected_output"] = expected_snip
            test_results.append(entry)
            if verbose:
                print("MISMATCH")

    # Print results
    total = len(tests)
    print(f"\n{'='*60}")
    print(f"Total tests:     {total}")
    print(f"Pass:            {stats['pass']} ({100*stats['pass']/total:.1f}%)" if total else "")
    print(f"Fail:            {total - stats['pass']}")
    print()
    print("Failure breakdown:")
    for key in ["output_mismatch", "compile_fail", "recomp_fail", "runtime_segfault", "runtime_error", "timeout"]:
        if stats[key]:
            print(f"  {stats[key]:4d}  {key}")

    if list_pass:
        print(f"\nPassing tests ({len(pass_list)}):")
        for name in pass_list:
            print(f"  {name}")

    if list_fail or show_diff:
        print(f"\nFailing tests ({len(fail_list)}):")
        for name in fail_list:
            detail = fail_details.get(name, "")
            print(f"  {name}: {detail}")

    # Write JSON results
    if json_path:
        total_duration = round(time.monotonic() - run_start, 2)
        report = {
            "metadata": {
                "timestamp": datetime.now(timezone.utc).isoformat(),
                "git_sha": get_git_sha(),
                "duration_seconds": total_duration,
                "total_available": total_available,
            },
            "total": total,
            "pass": stats["pass"],
            "fail": total - stats["pass"],
            "pass_rate": round(100 * stats["pass"] / total, 1) if total else 0,
            "breakdown": {
                k: stats[k]
                for k in ["output_mismatch", "compile_fail", "recomp_fail",
                           "runtime_segfault", "runtime_error", "timeout"]
                if stats[k]
            },
            "tests": test_results,
        }
        with open(json_path, "w") as f:
            json.dump(report, f, indent=2)
        print(f"\nResults written to {json_path}")


if __name__ == "__main__":
    main()
