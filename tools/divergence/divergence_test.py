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
import difflib
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


_FRAME_RE = re.compile(r"^F(\d+)\b")


def _frame_of(line: str):
    """Parse the leading frame number from a tracer line ("F12 ..." -> 12).
    Returns None for non-frame lines (e.g. "TRACER: start ...")."""
    m = _FRAME_RE.match(line)
    return int(m.group(1)) if m else None


def analyze_trace_divergence(a_lines: list[str], b_lines: list[str],
                             rel_tol: float = 0.0, abs_tol: float = 0.0,
                             accept_rules=None) -> dict:
    """Align the two filtered traces with difflib (exact-line keys) and classify
    every difference. Unlike a positional index compare, this correctly handles
    INSERTED / DELETED lines (e.g. a preloader clip Ruffle keeps but SWFRecomp
    removed) — they show up as ruffle-only / swfrecomp-only lines instead of
    shifting every subsequent line into a false divergence.

    Identical lines (frame headers, matched clips) anchor the alignment; float
    precision and structural diffs land in `replace` blocks where the existing
    numeric tolerance + accepted-diff rules are applied per pair.

    Returns a dict:
      first        None, or {kind, a, b, a_frame, b_frame} for the first real
                   divergence (kind: 'replace'|'ruffle_only'|'swfrecomp_only').
      absorbed     count of lines that differed only within numeric tolerance.
      accepted     [(tag), ...] lines matched by a documented per-game rule.
      ruffle_only  count of lines present in Ruffle but not SWFRecomp.
      swf_only     count of lines present in SWFRecomp but not Ruffle.
      matched      count of exactly-equal aligned lines.
      diverge_frames  sorted list of frame numbers carrying a real divergence.
      max_frame    highest frame number seen on either side (None if none).
      transient    None, or {reconverge_frame, diverge_frames} when all real
                   divergences are confined to early frames and the traces
                   re-converge (match) for at least one later frame.
    """
    res = {"first": None, "absorbed": 0, "accepted": [], "ruffle_only": 0,
           "swf_only": 0, "matched": 0, "diverge_frames": set(),
           "max_frame": None, "transient": None, "clip_transient": []}

    def note_frame(line):
        f = _frame_of(line)
        if f is not None:
            res["max_frame"] = f if res["max_frame"] is None else max(res["max_frame"], f)
        return f

    def _clip_path(line):
        """The clip path of a tracer line: the whitespace tokens with no '='
        after the leading frame token ("F1 _root.instance68 _x=0" ->
        "_root.instance68"). Empty for pathless lines (e.g. "F1 _currentframe=1")."""
        toks = [t for t in line.split() if "=" not in t]
        return " ".join(toks[1:]) if len(toks) > 1 else ""

    # Per-clip-path frame bookkeeping for the self-healing-clip recognizer below.
    clip_obs = {}   # path -> set of frames where the clip appears (any outcome)
    clip_div = {}   # path -> set of frames where the clip has a real replace divergence

    def _obs(line):
        p, f = _clip_path(line), _frame_of(line)
        if p and f is not None:
            clip_obs.setdefault(p, set()).add(f)

    # Real divergences are collected in trace order and resolved AFTER the walk,
    # so the per-clip self-healing classification (which needs the whole run) can
    # absorb a clip's first-frame blip before the first divergence is chosen.
    events = []   # ordered: {kind, a, b, path, frame}

    sm = difflib.SequenceMatcher(None, a_lines, b_lines, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        for ln in a_lines[i1:i2] + b_lines[j1:j2]:
            note_frame(ln)
        if tag == "equal":
            res["matched"] += (i2 - i1)
            for ln in a_lines[i1:i2]:
                _obs(ln)
        elif tag == "replace":
            ra, rb = a_lines[i1:i2], b_lines[j1:j2]
            m = min(len(ra), len(rb))
            for k in range(m):
                pa, pb = ra[k], rb[k]
                _obs(pa)   # the clip appears this frame regardless of outcome
                if (rel_tol > 0 or abs_tol > 0) and lines_equivalent(pa, pb, rel_tol, abs_tol):
                    res["absorbed"] += 1
                    continue
                if accept_rules:
                    t = accepted_diffs.match_any(accept_rules, pa, pb)
                    if t is not None:
                        res["accepted"].append(t)
                        continue
                p, f = _clip_path(pa), _frame_of(pa)
                if p and f is not None:
                    clip_div.setdefault(p, set()).add(f)
                events.append({"kind": "replace", "a": pa, "b": pb, "path": p, "frame": f})
            # Unpaired remainder of a longer side = ruffle-only / swfrecomp-only.
            for pa in ra[m:]:
                res["ruffle_only"] += 1
                events.append({"kind": "ruffle_only", "a": pa, "b": "<absent>",
                               "path": _clip_path(pa), "frame": _frame_of(pa)})
            for pb in rb[m:]:
                res["swf_only"] += 1
                events.append({"kind": "swfrecomp_only", "a": "<absent>", "b": pb,
                               "path": _clip_path(pb), "frame": _frame_of(pb)})
        elif tag == "delete":   # lines only in a (Ruffle)
            for pa in a_lines[i1:i2]:
                res["ruffle_only"] += 1
                events.append({"kind": "ruffle_only", "a": pa, "b": "<absent>",
                               "path": _clip_path(pa), "frame": _frame_of(pa)})
        elif tag == "insert":   # lines only in b (SWFRecomp)
            for pb in b_lines[j1:j2]:
                res["swf_only"] += 1
                events.append({"kind": "swfrecomp_only", "a": "<absent>", "b": pb,
                               "path": _clip_path(pb), "frame": _frame_of(pb)})

    # Self-healing-clip (per-clip transient) recognizer: a NAMED clip whose only
    # real divergences land on its FIRST observed frame, after which it re-converges
    # and matches on every later frame it appears in. This is the signature of an
    # observer / enterFrame-ordering artifact — e.g. Riddle School's custom mouse
    # cursor `instance68`, whose `onClipEvent(enterFrame){this._x=_root._xmouse;...}`
    # fires on the opposite side of the injected tracer's own onEnterFrame at the
    # same tick (headless `_xmouse=0`), so the FIRST sample reads the placement and
    # every later sample matches. SWFRecomp's two-phase enterFrame dispatch
    # (clip-action EF then AS onEnterFrame) can't match Ruffle's single
    # instantiation-ordered exec list (#10b), so the newest clip (the tracer) and an
    # older clip-action clip swap order for exactly one observation. This absorbs
    # that one-frame blip the same way #10b/Pacman is absorbed — but automatically
    # and per-clip, rather than via a hand-written accepted/<game>.txt manifest.
    # Guards: requires a non-empty clip path (a pathless root `_currentframe` blip is
    # NEVER silently absorbed — that stays a whole-trace divergence) and at least one
    # later matched frame (genuine re-convergence, not a one-frame run); and the
    # divergence must be confined to the clip's first appearance (a multi-frame or
    # recurring divergence — e.g. a real nested-sprite frame lag — is still flagged).
    transient_clips = set()
    for p, dfr in clip_div.items():
        obs = clip_obs.get(p, set())
        if not obs:
            continue
        first_obs = min(obs)
        if dfr == {first_obs} and max(obs) > first_obs:
            transient_clips.add(p)

    for ev in events:
        if ev["kind"] == "replace" and ev["path"] in transient_clips:
            res["clip_transient"].append(
                {"path": ev["path"], "frame": ev["frame"], "a": ev["a"], "b": ev["b"]})
            continue
        if res["first"] is None:
            res["first"] = {"kind": ev["kind"], "a": ev["a"], "b": ev["b"],
                            "a_frame": ev["frame"] if ev["a"] != "<absent>" else None,
                            "b_frame": ev["frame"] if ev["b"] != "<absent>" else None}
        for ln in (ev["a"], ev["b"]):
            if ln != "<absent>":
                f = _frame_of(ln)
                if f is not None:
                    res["diverge_frames"].add(f)

    # Whole-trace re-convergence: real divergences (after per-clip absorption above)
    # confined to early frames, with at least one fully-matched later frame (the
    # hallmark of a transient preloader/pacing blip that self-heals, vs a bug that
    # cascades for the rest of the run).
    df = res["diverge_frames"]
    if df and res["max_frame"] is not None and max(df) < res["max_frame"]:
        res["transient"] = {"reconverge_frame": max(df) + 1,
                            "diverge_frames": sorted(df)}
    res["diverge_frames"] = sorted(df)
    return res


def detect_byte_preloader(swfrecomp_dir: Path) -> bool:
    """True if the recompiled scripts reference getBytesLoaded/getBytesTotal —
    i.e. the SWF has a byte-loading preloader. Such SWFs report fully-loaded
    immediately under SWFRecomp (local file) while Ruffle's headless exporter
    streams bytes progressively, so early-frame divergences are often
    exporter-pacing artifacts rather than runtime bugs."""
    scripts = swfrecomp_dir / "RecompiledScripts"
    if not scripts.is_dir():
        return False
    for f in scripts.glob("*.c"):
        try:
            txt = f.read_text(errors="ignore")
        except OSError:
            continue
        if "getBytesLoaded" in txt or "getBytesTotal" in txt:
            return True
    return False


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
    an = analyze_trace_divergence(a, b, rel_tol, abs_tol, accept_rules)
    absorbed = an["absorbed"]
    accepted = an["accepted"]
    first = an["first"]
    byte_preloader = detect_byte_preloader(swfrecomp_dir)

    report = []
    report.append(f"=== Divergence report: {stem} ===")
    report.append(f"Frames compared: {args.frames}")
    report.append(f"Trace lines: ruffle={len(a)}, swfrecomp={len(b)}")
    if absorbed:
        report.append(f"Trace: {absorbed} line(s) differed only within numeric "
                      f"tolerance (rel={rel_tol:g}, abs={abs_tol:g}) — float-precision "
                      f"noise, not flagged. Use --trace-exact to see them.")
    if accepted:
        tags = ", ".join(sorted(set(accepted)))
        mname = accepted_diffs.manifest_path(stem).name
        report.append(f"Trace: {len(accepted)} line(s) matched documented "
                      f"accepted-diff rule(s) in accepted/{mname} ({tags}) — "
                      f"known observer/tooling artifact, not flagged. Use "
                      f"--no-accept to see them.")
    clip_transient = an["clip_transient"]
    if clip_transient:
        ct_clips = sorted(set(e["path"] for e in clip_transient))
        ct_frames = ",".join(f"F{x}" for x in sorted(set(e["frame"] for e in clip_transient)))
        report.append(f"Trace: {len(clip_transient)} self-healing per-clip "
                      f"divergence(s) on {', '.join(ct_clips)} confined to "
                      f"{ct_frames}, re-converging and matching through "
                      f"F{an['max_frame']} — observer / enterFrame-ordering artifact "
                      f"(custom-cursor-style onClipEvent(enterFrame) sampled opposite "
                      f"the tracer; #10b class), not flagged.")
    if first is None:
        if clip_transient:
            n = len(clip_transient) + len(accepted)
            report.append(f"Trace: converged (modulo {n} self-healing / documented "
                          f"observer-artifact line(s))")
        elif accepted:
            report.append(f"Trace: converged (modulo {len(accepted)} documented "
                          f"accepted-diff line(s))")
        elif absorbed:
            report.append("Trace: equivalent within tolerance")
        else:
            report.append("Trace: identical")
    else:
        kind = first["kind"]
        report.append(f"Trace: first divergence ({kind})"
                      + (f" at frame F{first['a_frame'] or first['b_frame']}"
                         if (first['a_frame'] or first['b_frame']) is not None else ""))
        report.append(f"  ruffle:    {first['a']}")
        report.append(f"  swfrecomp: {first['b']}")
        if an["ruffle_only"] or an["swf_only"]:
            report.append(f"  line counts: {an['ruffle_only']} ruffle-only, "
                          f"{an['swf_only']} swfrecomp-only, "
                          f"{an['matched']} matched")
        # B: transient (re-convergence) classification.
        if an["transient"]:
            t = an["transient"]
            fr = ",".join(f"F{x}" for x in t["diverge_frames"])
            report.append(f"  TRANSIENT: divergences confined to {fr}; traces "
                          f"re-converge at F{t['reconverge_frame']} and match "
                          f"through F{an['max_frame']}.")
        # C: byte-loading-preloader context. Gate on the actual pacing
        # signatures — a transient (self-healing) divergence or a clip
        # add/remove line-count mismatch — not merely "early frame", so a real
        # early value-replace bug (e.g. an auto-instance-counter off-by-N) in a
        # SWF that happens to have a preloader is not mislabeled.
        if byte_preloader and (an["transient"] or an["ruffle_only"] or an["swf_only"]):
            report.append("  PRELOADER: SWF uses getBytesLoaded/getBytesTotal — "
                          "SWFRecomp reports fully-loaded immediately (local file) "
                          "while Ruffle's exporter streams progressively, so an "
                          "early-frame divergence here is likely an exporter-pacing "
                          "artifact (accepted preloader-pacing class), not a runtime "
                          "bug. Verify before treating as a bug.")

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
