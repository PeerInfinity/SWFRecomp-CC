#!/usr/bin/env python3
"""End-to-end divergence test: inject tracer into a SWF, run it through both
Ruffle and SWFRecomp, and report the first point where their outputs diverge
(either in trace text or in rendered pixels).

Usage:
  python3 tools/divergence/divergence_test.py <input.swf> [--frames N]
                                              [--out DIR] [--tolerance N]
                                              [--max-outliers N]

Default output: tools/divergence/runs/<swf_stem>/
  injected.swf                injected tracer SWF (input to both runtimes)
  ruffle/<NN>.png             per-frame PNG from Ruffle exporter
  ruffle/trace.txt            Ruffle trace log
  swfrecomp/build/F<NNNN>.png per-frame PNG from SWFRecomp graphics-native
  swfrecomp/trace.txt         SWFRecomp trace log (raw stdout)
  compare/f<NN>.ruffle.png    side-by-side comparison set (all frames):
  compare/f<NN>.swfrecomp.png   the Ruffle + SWFRecomp frame, co-located, plus
  compare/f<NN>.swfrecomp.difference.png  a per-frame difference image (written
                              for every frame that differs at all)
  divergence.txt              first divergence report
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
PROJECT_ROOT = HERE.parent.parent
sys.path.insert(0, str(PROJECT_ROOT / "ruffle-tests"))
import verify_output as vo  # for compare_images

RUFFLE_EXPORTER = Path.home() / "CC" / "ruffle" / "target" / "release" / "exporter"

# Filter out lines that are guaranteed to differ between platforms or come
# from non-tracer instrumentation. Both sides get the same filter so the diff
# reflects only meaningful runtime divergences.
NOISE_PATTERNS = [
    re.compile(r"^SWF Runtime Loaded"),
    re.compile(r"^\[HEAP\]"),
    re.compile(r" \$version="),    # Capabilities.version differs LNX vs WIN
]


def filter_trace(text: str) -> list[str]:
    out = []
    for line in text.splitlines():
        if not line.strip():
            continue
        if any(p.search(line) for p in NOISE_PATTERNS):
            continue
        out.append(line)
    return out


def first_trace_divergence(a_lines: list[str], b_lines: list[str]) -> tuple[int, str, str]:
    """Return (index, a_line, b_line) of first differing line, or (-1, '', '')."""
    n = max(len(a_lines), len(b_lines))
    for i in range(n):
        a = a_lines[i] if i < len(a_lines) else "<EOF>"
        b = b_lines[i] if i < len(b_lines) else "<EOF>"
        if a != b:
            return i, a, b
    return -1, "", ""


def ruffle_png_for_frame(ruffle_dir: Path, frame: int, total: int) -> Path:
    # Ruffle exporter zero-pads to len(str(total)). Frame numbers are 0-based:
    # ruffle 0.png corresponds to swfrecomp F0001.png (state after first tick).
    digits = len(str(total))
    return ruffle_dir / f"{frame - 1:0{digits}d}.png"


def swfrecomp_png_for_frame(build_dir: Path, frame: int) -> Path:
    return build_dir / f"F{frame:04d}.png"


def build_comparison(ruffle_dir: Path, swfrecomp_build: Path, total: int,
                     tolerance: int, max_outliers: int,
                     compare_dir: Path) -> tuple[int, str]:
    """Walk every frame in order. For each frame where both PNGs exist, co-locate
    the Ruffle and SWFRecomp renders side-by-side in compare_dir as
    f<NN>.ruffle.png / f<NN>.swfrecomp.png, and (via compare_images) write a
    per-frame difference image f<NN>.swfrecomp.difference.png whenever the pair
    differs at all. Returns (frame, message) of the FIRST frame whose PNG pair
    fails the tolerance check, or (-1, '') if all match. Frames where either PNG
    is missing are skipped (with a note) since absence may just mean the run
    ended early on one side."""
    if compare_dir.exists():
        shutil.rmtree(compare_dir)
    compare_dir.mkdir(parents=True)
    digits = max(2, len(str(total)))
    first_frame, first_msg = -1, ""
    notes = []
    for frame in range(1, total + 1):
        a = ruffle_png_for_frame(ruffle_dir, frame, total)
        b = swfrecomp_png_for_frame(swfrecomp_build, frame)
        if not a.exists() or not b.exists():
            notes.append(f"  frame {frame}: missing ({'ruffle' if not a.exists() else ''} "
                         f"{'swfrecomp' if not b.exists() else ''})".strip())
            continue
        # Co-locate the pair so all three (ruffle / swfrecomp / diff) sit together
        # under compare/ and sort by frame for easy side-by-side browsing.
        r_copy = compare_dir / f"f{frame:0{digits}d}.ruffle.png"
        s_copy = compare_dir / f"f{frame:0{digits}d}.swfrecomp.png"
        shutil.copy2(a, r_copy)
        shutil.copy2(b, s_copy)
        # compare_images writes "<actual_stem>.difference.png" next to s_copy
        # whenever there is any pixel difference (independent of pass/fail).
        passed, msg, max_diff = vo.compare_images(
            s_copy, r_copy, [{"tolerance": tolerance, "max_outliers": max_outliers}])
        if not passed and first_frame < 0:
            first_frame, first_msg = frame, f"max_diff={max_diff} ({msg})"
    if notes:
        print("Image comparison notes:", file=sys.stderr)
        for n in notes[:5]:
            print(n, file=sys.stderr)
    return first_frame, first_msg


def run(cmd, **kw):
    print(f"$ {' '.join(str(c) for c in cmd)}", file=sys.stderr)
    return subprocess.run(cmd, check=True, **kw)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    ap.add_argument("--frames", type=int, default=30,
                    help="Number of frames to compare (default 30)")
    ap.add_argument("--out", type=Path,
                    help="Output directory (default: tools/divergence/runs/<stem>/)")
    ap.add_argument("--tolerance", type=int, default=0,
                    help="Per-channel pixel tolerance, 0-255 (default 0=exact)")
    ap.add_argument("--max-outliers", type=int, default=0,
                    help="Max channels allowed to exceed tolerance (default 0)")
    ap.add_argument("--skip-ruffle", action="store_true",
                    help="Skip Ruffle run (reuse existing outputs)")
    ap.add_argument("--skip-swfrecomp", action="store_true",
                    help="Skip SWFRecomp run (reuse existing outputs)")
    ap.add_argument("--recompile", action="store_true",
                    help="Force SWFRecomp re-recompile")
    args = ap.parse_args()

    if not RUFFLE_EXPORTER.exists():
        print(f"Ruffle exporter not built at {RUFFLE_EXPORTER}", file=sys.stderr)
        print("  cd ~/CC/ruffle && cargo +nightly build --release -p exporter", file=sys.stderr)
        sys.exit(1)

    stem = args.input_swf.stem
    out_dir = args.out or (HERE / "runs" / stem)
    out_dir.mkdir(parents=True, exist_ok=True)
    injected = out_dir / "injected.swf"
    ruffle_dir = out_dir / "ruffle"
    swfrecomp_dir = out_dir / "swfrecomp"

    # 1. Inject tracer
    run(["python3", str(HERE / "inject_tracer.py"), str(args.input_swf), str(injected)])

    # 2. Ruffle: per-frame PNGs + trace
    if not args.skip_ruffle:
        if ruffle_dir.exists():
            shutil.rmtree(ruffle_dir)
        ruffle_dir.mkdir()
        run([str(RUFFLE_EXPORTER), "-f", str(args.frames), "-s",
             "--trace-log", str(ruffle_dir / "trace.txt"),
             str(injected), str(ruffle_dir)])

    # 3. SWFRecomp: per-frame PNGs + trace
    if not args.skip_swfrecomp:
        cmd = ["python3", str(HERE / "run_swfrecomp.py"),
               str(injected), str(swfrecomp_dir),
               "--frames", str(args.frames)]
        if args.recompile:
            cmd.append("--recompile")
        run(cmd)

    # 4. Diff traces
    ruffle_trace = (ruffle_dir / "trace.txt").read_text()
    swfrecomp_trace = (swfrecomp_dir / "trace.txt").read_text()
    a = filter_trace(ruffle_trace)
    b = filter_trace(swfrecomp_trace)
    idx, a_line, b_line = first_trace_divergence(a, b)

    report = []
    report.append(f"=== Divergence report: {stem} ===")
    report.append(f"Frames compared: {args.frames}")
    report.append(f"Trace lines: ruffle={len(a)}, swfrecomp={len(b)}")
    if idx < 0:
        report.append("Trace: identical")
    else:
        report.append(f"Trace: first divergence at filtered line {idx}")
        report.append(f"  ruffle:    {a_line}")
        report.append(f"  swfrecomp: {b_line}")
        ctx_start = max(0, idx - 3)
        report.append(f"  context (filtered lines {ctx_start}-{idx-1}):")
        for j in range(ctx_start, idx):
            report.append(f"    {j:>4}: {a[j]}")

    # 5. Diff images (also builds the side-by-side compare/ set for all frames)
    img_frame, img_msg = build_comparison(
        ruffle_dir, swfrecomp_dir / "build", args.frames,
        args.tolerance, args.max_outliers, out_dir / "compare")
    if img_frame < 0:
        report.append(f"Image: identical (tolerance={args.tolerance}/{args.max_outliers})")
    else:
        report.append(f"Image: first divergence at frame {img_frame}: {img_msg}")

    text = "\n".join(report) + "\n"
    (out_dir / "divergence.txt").write_text(text)
    print()
    print(text, end="")


if __name__ == "__main__":
    main()
