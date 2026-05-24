#!/usr/bin/env python3
"""Run SWFRecomp graphics-native against an (already injected) SWF and capture
per-frame PNGs + trace output.

Drives the same compile_native / run_binary helpers verify_output.py uses, but
with a stable on-disk build directory so artifacts survive past the run.

Usage:
  python3 tools/divergence/run_swfrecomp.py <input.swf> <output_dir> [--frames N]

Outputs in <output_dir>:
  test.swf                  copy of input
  RecompiledScripts/...     SWFRecomp output
  build/                    object files + binary
  build/F0001.png ... F<N>.png
  trace.txt                 raw stdout (trace lines + any prints)
  stderr.txt                raw stderr
"""
import argparse
import os
import shutil
import sys
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(PROJECT_ROOT / "ruffle-tests"))

# Import helpers from verify_output.py. We share its compile + run logic so
# this stays in sync with the regular test runner.
import verify_output as vo  # noqa: E402


def make_test_toml(num_frames: int) -> str:
    """Generate a test.toml with num_frames + one image_comparison per tick.

    The image_comparisons block is what tells SWFRecomp's capture.c to drop a
    PNG named "F0001.png" etc. on each tick. We re-create the comparison block
    here even though we don't have expected images — verify_output's helper
    parse_image_comparisons just emits CAPTURE_TRIGGERS, and we drive the run
    ourselves so the missing-expected-png path never trips.
    """
    lines = [f"num_frames = {num_frames}", ""]
    for i in range(1, num_frames + 1):
        lines.append(f"[image_comparisons.F{i:04d}]")
        lines.append(f"trigger = {i}")
        lines.append("")
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    ap.add_argument("output_dir", type=Path)
    ap.add_argument("--frames", type=int, default=100,
                    help="Number of frames to capture (default 100)")
    ap.add_argument("--recompile", action="store_true",
                    help="Force SWFRecomp re-run even if cache exists")
    ap.add_argument("--no-ccache", action="store_true",
                    help="Disable ccache for the C compile")
    args = ap.parse_args()

    if not args.input_swf.exists():
        print(f"Input SWF not found: {args.input_swf}", file=sys.stderr)
        sys.exit(1)

    test_dir = args.output_dir
    test_dir.mkdir(parents=True, exist_ok=True)
    build_dir = test_dir / "build"
    build_dir.mkdir(exist_ok=True)

    # 1. Stage test.swf + test.toml
    test_swf = test_dir / "test.swf"
    shutil.copy2(args.input_swf, test_swf)
    (test_dir / "test.toml").write_text(make_test_toml(args.frames))
    print(f"Staged {test_swf} ({args.frames} frames)", file=sys.stderr)

    # 2. Run the recompiler (cached unless --recompile)
    t0 = time.perf_counter()
    ok, stderr_text = vo.recompile_swf(test_dir, force=args.recompile)
    if not ok:
        print(f"SWFRecomp failed:\n{stderr_text}", file=sys.stderr)
        sys.exit(2)
    print(f"  recompile: {time.perf_counter() - t0:.2f}s", file=sys.stderr)

    # 3. Compile native binary, graphics mode (offscreen Dawn)
    t0 = time.perf_counter()
    ok, err = vo.compile_native(
        test_dir, args.frames, build_dir,
        mode="graphics", has_image_comparisons=True,
        asan=False, use_ccache=not args.no_ccache,
    )
    if not ok:
        print(f"compile_native failed:\n{err}", file=sys.stderr)
        sys.exit(3)
    print(f"  compile:   {time.perf_counter() - t0:.2f}s", file=sys.stderr)

    # 4. Run binary with capture triggers + collect outputs
    triggers = ",".join(f"F{i:04d}:iteration:{i}" for i in range(1, args.frames + 1))
    extra_env = {
        "CAPTURE_TRIGGERS": triggers,
        "CAPTURE_OUTPUT_DIR": str(build_dir),
        # WSL2: force lavapipe software Vulkan (matches verify_output.py).
        "VK_ICD_FILENAMES": "/usr/share/vulkan/icd.d/lvp_icd.json",
        "VK_DRIVER_FILES": "/usr/share/vulkan/icd.d/lvp_icd.json",
    }
    t0 = time.perf_counter()
    stdout, rc, stderr_run = vo.run_binary(build_dir, event_file=None, extra_env=extra_env)
    print(f"  run:       {time.perf_counter() - t0:.2f}s (rc={rc})", file=sys.stderr)

    if stdout is None:
        print("Test binary timed out.", file=sys.stderr)
        sys.exit(4)

    # 5. Save artifacts
    (test_dir / "trace.txt").write_text(stdout)
    (test_dir / "stderr.txt").write_text(stderr_run or "")
    png_count = sum(1 for p in build_dir.glob("F*.png"))
    print(f"  outputs:   trace.txt ({len(stdout.splitlines())} lines), {png_count} PNGs in build/",
          file=sys.stderr)

    if rc != 0:
        print(f"WARNING: test_run exited with code {rc}", file=sys.stderr)
        if stderr_run:
            for line in stderr_run.splitlines()[:5]:
                print(f"  stderr: {line}", file=sys.stderr)


if __name__ == "__main__":
    main()
