#!/usr/bin/env python3
"""run_native.py — recompile an (already probe-injected) SWF to the SWFRecomp
graphics-native (OFFSCREEN_RENDER) build and run it HEADLESS, optionally driving
input events (clicks / keypresses) from an input.json.

This is tier 2 of the DJ flashSubstrate feasibility probe (tier 1 = Ruffle,
tier 3 = WASM-in-browser). Native is fully headless and needs no DISPLAY/WebGPU,
so it is the fast agent-solo loop for the read / write / placement experiments.
The injected AS reports via trace() -> stdout, captured to trace.txt.

Usage:
  python3 run_native.py <input.swf> <output_dir> [--frames N] [--input input.json]

Reuses verify_output.py's compile/run helpers (same as tools/divergence/
run_swfrecomp.py, which this is a thin superset of — it adds --input)."""
import argparse
import shutil
import sys
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[6]
sys.path.insert(0, str(PROJECT_ROOT / "ruffle-tests"))
import verify_output as vo  # noqa: E402


def make_test_toml(num_frames: int, capture_ticks=None) -> str:
    lines = [f"num_frames = {num_frames}", ""]
    ticks = capture_ticks or range(1, min(num_frames, 16) + 1)
    for i in ticks:
        lines.append(f"[image_comparisons.F{i:04d}]")
        lines.append(f"trigger = {i}")
        lines.append("")
    return "\n".join(lines)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    ap.add_argument("output_dir", type=Path)
    ap.add_argument("--frames", type=int, default=60)
    ap.add_argument("--input", type=Path, default=None,
                    help="input.json (Ruffle event schema) to drive clicks/keys")
    ap.add_argument("--recompile", action="store_true")
    ap.add_argument("--asan", action="store_true",
                    help="compile with AddressSanitizer (UAF/OOB pinning)")
    ap.add_argument("--capture-ticks", default=None,
                    help="comma-separated tick numbers for PNG capture "
                         "(default: 1..16); deterministic visual probes")
    args = ap.parse_args()

    if not args.input_swf.exists():
        sys.exit(f"Input SWF not found: {args.input_swf}")

    test_dir = args.output_dir
    test_dir.mkdir(parents=True, exist_ok=True)
    build_dir = test_dir / "build"
    build_dir.mkdir(exist_ok=True)

    shutil.copy2(args.input_swf, test_dir / "test.swf")
    cap = ([int(t) for t in args.capture_ticks.split(",")]
           if args.capture_ticks else None)
    (test_dir / "test.toml").write_text(make_test_toml(args.frames, cap))

    event_file = None
    if args.input is not None:
        event_file = build_dir / "input_events.txt"
        n_wait = vo.preprocess_input_json(args.input, event_file, scale_factor=1.0)
        print(f"  input: {args.input.name} -> {n_wait} WAIT ticks", file=sys.stderr)

    t0 = time.perf_counter()
    ok, err = vo.recompile_swf(test_dir, force=args.recompile)
    if not ok:
        sys.exit(f"SWFRecomp failed:\n{err}")
    print(f"  recompile: {time.perf_counter()-t0:.2f}s", file=sys.stderr)

    t0 = time.perf_counter()
    ok, err = vo.compile_native(test_dir, args.frames, build_dir, mode="graphics",
                                has_image_comparisons=True, asan=args.asan,
                                use_ccache=not args.asan)
    if not ok:
        sys.exit(f"compile_native failed:\n{err}")
    print(f"  compile:   {time.perf_counter()-t0:.2f}s", file=sys.stderr)

    triggers = ",".join(f"F{i:04d}:iteration:{i}"
                        for i in (cap or range(1, min(args.frames, 16) + 1)))
    extra_env = {
        "CAPTURE_TRIGGERS": triggers,
        "CAPTURE_OUTPUT_DIR": str(build_dir),
        "VK_ICD_FILENAMES": "/usr/share/vulkan/icd.d/lvp_icd.json",
        "VK_DRIVER_FILES": "/usr/share/vulkan/icd.d/lvp_icd.json",
    }
    t0 = time.perf_counter()
    stdout, rc, stderr_run = vo.run_binary(build_dir, event_file=event_file, extra_env=extra_env)
    print(f"  run:       {time.perf_counter()-t0:.2f}s (rc={rc})", file=sys.stderr)
    if stdout is None:
        sys.exit("Test binary timed out.")

    (test_dir / "trace.txt").write_text(stdout)
    (test_dir / "stderr.txt").write_text(stderr_run or "")
    png_count = sum(1 for _ in build_dir.glob("F*.png"))
    print(f"  outputs:   trace.txt ({len(stdout.splitlines())} lines), {png_count} PNGs",
          file=sys.stderr)


if __name__ == "__main__":
    main()
