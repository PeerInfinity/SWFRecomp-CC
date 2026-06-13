#!/usr/bin/env python3
"""End-to-end divergence test: inject tracer into a SWF, run it through both
Ruffle and SWFRecomp, and report the first point where their outputs diverge
(either in trace text or in rendered pixels).

Usage:
  python3 tools/divergence/divergence_test.py <input.swf> [--frames N]
                                              [--out DIR] [--tolerance N]
                                              [--max-outliers N]
                                              [--trace-rel-tol R] [--trace-abs-tol A]
                                              [--trace-exact]

The trace diff compares numbers with a relative+absolute tolerance by default
(rel 1e-5 / abs 1e-4), so float-precision noise — e.g. an _xscale that differs
only at the 8th significant digit because SWFRecomp stores scale in f32 while
Ruffle derives it in f64 — does NOT register as a divergence. The non-numeric
skeleton (clip paths, property keys, booleans, line structure) must still match
exactly, so real bugs (a missing property, a renamed clip, _y=-5 vs -4.3) are
still flagged. Pass --trace-exact for byte-exact comparison.

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
sys.path.insert(0, str(HERE))
import accepted_diffs  # per-game accepted-divergence manifests

RUFFLE_EXPORTER = Path.home() / "CC" / "ruffle" / "target" / "release" / "exporter"

# Filter out lines that are guaranteed to differ between platforms or come
# from non-tracer instrumentation. Both sides get the same filter so the diff
# reflects only meaningful runtime divergences.
NOISE_PATTERNS = [
    re.compile(r"^SWF Runtime Loaded"),
    re.compile(r"^\[HEAP\]"),
    re.compile(r" \$version="),    # Capabilities.version differs LNX vs WIN
    # _url / _root.<name>=_url properties echo the loaded movie's file:// path,
    # which is inherently environment-specific: Ruffle loads the injected SWF by
    # its absolute path, SWFRecomp stages it as test.swf. Same class as $version
    # (a path/host artifact, not a runtime divergence). Drops the line on both
    # sides so they cancel.
    re.compile(r'="file://[^"]*\.swf"'),
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


# A numeric token: optional sign, digits, optional fraction, optional exponent.
# Matches integers AND floats anywhere in a line — the value after "=", a frame
# number ("F4"), and the trailing digits of an instance name ("instance4"). That
# is intentional: a real structural divergence (instance4 vs instance5) keeps the
# same skeleton but its numbers differ far beyond tolerance, so it is still
# flagged; only genuine float-precision noise is absorbed.
_NUM_RE = re.compile(r"[-+]?\d+(?:\.\d+)?(?:[eE][-+]?\d+)?")


def _skeleton_and_nums(line: str):
    """Replace every numeric token with \\0 (the skeleton) and return the ordered
    list of the numeric values that were removed."""
    nums = []

    def repl(m):
        nums.append(float(m.group(0)))
        return "\0"

    return _NUM_RE.sub(repl, line), nums


def _nums_close(x: float, y: float, rel_tol: float, abs_tol: float) -> bool:
    if x == y:
        return True
    diff = abs(x - y)
    return diff <= abs_tol or diff <= rel_tol * max(abs(x), abs(y))


def lines_equivalent(a: str, b: str, rel_tol: float, abs_tol: float) -> bool:
    """True if a == b, or if they differ ONLY in numeric tokens that all agree
    within (rel_tol, abs_tol). The non-numeric skeleton (clip paths, property
    keys, true/false, line structure) must match exactly — so a missing property,
    a renamed clip, or an extra line is never absorbed; only float-precision
    differences (e.g. f32 scale storage vs Ruffle's f64) are."""
    if a == b:
        return True
    sa, na = _skeleton_and_nums(a)
    sb, nb = _skeleton_and_nums(b)
    if sa != sb or len(na) != len(nb):
        return False
    return all(_nums_close(x, y, rel_tol, abs_tol) for x, y in zip(na, nb))


def first_trace_divergence(a_lines: list[str], b_lines: list[str],
                           rel_tol: float = 0.0, abs_tol: float = 0.0,
                           accept_rules=None
                           ) -> tuple[int, str, str, int, list]:
    """Return (index, a_line, b_line, absorbed, accepted) of the first line that
    differs beyond numeric tolerance and is not covered by an accepted-diff rule.
    `absorbed` counts earlier lines that differed only within numeric tolerance
    (float-precision noise). `accepted` is the list of (index, tag) for earlier
    lines matched by a documented per-game accept rule. With rel_tol=abs_tol=0 and
    no accept_rules this is an exact line comparison. index=-1 = no divergence.
    Skeletons match per-line so absorbing a line preserves positional alignment."""
    n = max(len(a_lines), len(b_lines))
    absorbed = 0
    accepted = []
    for i in range(n):
        a = a_lines[i] if i < len(a_lines) else "<EOF>"
        b = b_lines[i] if i < len(b_lines) else "<EOF>"
        if a == b:
            continue
        if (rel_tol > 0 or abs_tol > 0) and a != "<EOF>" and b != "<EOF>" \
                and lines_equivalent(a, b, rel_tol, abs_tol):
            absorbed += 1
            continue
        if accept_rules and a != "<EOF>" and b != "<EOF>":
            tag = accepted_diffs.match_any(accept_rules, a, b)
            if tag is not None:
                accepted.append((i, tag))
                continue
        return i, a, b, absorbed, accepted
    return -1, "", "", absorbed, accepted


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
    ap.add_argument("--trace-rel-tol", type=float, default=1e-5,
                    help="Relative tolerance for numeric tokens in the trace diff "
                         "(default 1e-5). Absorbs f32-vs-f64 precision noise (e.g. "
                         "an _xscale that differs at the 8th significant digit) "
                         "while still flagging real value bugs.")
    ap.add_argument("--trace-abs-tol", type=float, default=1e-4,
                    help="Absolute tolerance for numeric tokens near zero "
                         "(default 1e-4), where relative tolerance breaks down.")
    ap.add_argument("--trace-exact", action="store_true",
                    help="Byte-exact trace comparison (sets both trace tolerances "
                         "to 0). Use to inspect float-precision noise directly.")
    ap.add_argument("--no-accept", action="store_true",
                    help="Ignore the per-game accepted-diff manifest "
                         "(tools/divergence/accepted/<stem>.txt), so documented "
                         "observer/tooling artifacts are flagged like any other "
                         "divergence. Use to inspect what a manifest is absorbing.")
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
    rel_tol = 0.0 if args.trace_exact else args.trace_rel_tol
    abs_tol = 0.0 if args.trace_exact else args.trace_abs_tol
    accept_rules = [] if args.no_accept else accepted_diffs.load_manifest(stem)
    idx, a_line, b_line, absorbed, accepted = first_trace_divergence(
        a, b, rel_tol, abs_tol, accept_rules)

    report = []
    report.append(f"=== Divergence report: {stem} ===")
    report.append(f"Frames compared: {args.frames}")
    report.append(f"Trace lines: ruffle={len(a)}, swfrecomp={len(b)}")
    if absorbed:
        report.append(f"Trace: {absorbed} line(s) differed only within numeric "
                      f"tolerance (rel={rel_tol:g}, abs={abs_tol:g}) — float-precision "
                      f"noise, not flagged. Use --trace-exact to see them.")
    if accepted:
        tags = ", ".join(sorted(set(t for _, t in accepted)))
        mname = accepted_diffs.manifest_path(stem).name
        report.append(f"Trace: {len(accepted)} line(s) matched documented "
                      f"accepted-diff rule(s) in accepted/{mname} ({tags}) — "
                      f"known observer/tooling artifact, not flagged. Use "
                      f"--no-accept to see them.")
    if idx < 0:
        if accepted:
            report.append(f"Trace: converged (modulo {len(accepted)} documented "
                          f"accepted-diff line(s))")
        elif absorbed:
            report.append("Trace: equivalent within tolerance")
        else:
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
