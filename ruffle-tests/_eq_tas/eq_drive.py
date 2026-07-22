#!/usr/bin/env python3
"""Elephant Quest native drive (EQ-1/EQ-2 tooling, git-tracked as of EQ-2).

Recompile + build (no-graphics, -O0, one-file-at-a-time under ulimit) + run the
EQ native binary with an events file. Mirrors ruffle-tests/_rwk_tas/rwk_drive.py
but for EQ; shares verify_output.py's compile_native / run_binary helpers.

Set EQ_SCRATCH to a writable scratch dir (default: a subdir of the system temp).
It stages test.swf there, recompiles into <EQ_SCRATCH>/eq, builds into
<EQ_SCRATCH>/eq/build, and runs <EQ_SCRATCH>/eq/build/test_run.

  export EQ_SCRATCH=/tmp/eqscratch
  python3 eq_drive.py recompile          # SWFRecomp -> RecompiledABC/ (ulimit 4GB inside)
  ulimit -v 8388608; python3 eq_drive.py build   # -O0 no-graphics (peak ~3.3GB; run monitored)
  AVM2_DUMP_TREE=1 python3 eq_drive.py run events.txt 18   # run N ticks, dump tree to stderr

Events-file line format (avm2_display.c input parser): WAIT (one per tick),
MOUSE_MOVE x y, MOUSE_DOWN_LEFT x y idx, MOUSE_UP_LEFT x y, KEY_DOWN/KEY_UP code
char loc. Build the same plan as a Ruffle-test input.json for the
RUFFLE_INPUT_FILE oracle (see ruffle-tests/_rwk_tas/rwk_drive.compile_ruffle_json).

Env knobs the binary reads: AVM2_MAX_TICKS (frames without rebuild),
AVM2_CPU_DUMP=<prefix> (per-tick .ppm), AVM2_DUMP_TREE=1 (per-tick read-only
display-tree dump to stderr: each node's stage-space AABB in px, and for a
SimpleButton the hit/up state world bbox + center — the self bbox is EMPTY).

EQ frame1 preloader Play button: SimpleButton 'playB', nested root -> preloader
-> playB, hit-state world AABB ~[39,206]..[281,274]px, CLICK center (160,240).
"""
import os, sys, time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "ruffle-tests"))
import verify_output as vo  # noqa: E402

EQ_SWF = Path(os.environ.get(
    "EQ_SWF", str(Path.home() / "CC/newgrounds/566862_ElephantQuest_Public2_secu.swf")))
SCRATCH = Path(os.environ.get("EQ_SCRATCH", "/tmp/eqscratch"))
TEST = SCRATCH / "eq"
BUILD = TEST / "build"


def stage():
    TEST.mkdir(parents=True, exist_ok=True)
    import shutil
    if not (TEST / "test.swf").exists():
        shutil.copy2(EQ_SWF, TEST / "test.swf")
    if not (TEST / "test.toml").exists():
        (TEST / "test.toml").write_text("num_frames = 30\n")


def do_recompile():
    stage()
    os.environ["SWFRECOMP_RECOMPILE_TIMEOUT"] = "180"
    t0 = time.perf_counter()
    ok, err = vo.recompile_swf(TEST, force=False)
    print(f"recompile ok={ok} {time.perf_counter()-t0:.1f}s", file=sys.stderr)
    if not ok:
        print(err[-3000:], file=sys.stderr); sys.exit(2)


def do_build():
    BUILD.mkdir(parents=True, exist_ok=True)
    os.environ["SWFRECOMP_OPT_LEVEL"] = "-O0"
    t0 = time.perf_counter()
    ok, err = vo.compile_native(TEST, 30, BUILD, mode="no-graphics",
                                has_image_comparisons=False, asan=False,
                                use_ccache=True)
    print(f"build ok={ok} {time.perf_counter()-t0:.1f}s", file=sys.stderr)
    if not ok:
        print(err[-4000:], file=sys.stderr); sys.exit(3)


def do_run(events, ticks):
    env = dict(os.environ)
    env["AVM2_MAX_TICKS"] = str(ticks)
    ev = str(events) if events and events != "-" else None
    t0 = time.perf_counter()
    stdout, rc, stderr = vo.run_binary(BUILD, event_file=ev, extra_env=env)
    print(f"run rc={rc} {time.perf_counter()-t0:.1f}s", file=sys.stderr)
    (SCRATCH / "eq_trace.txt").write_text(stdout or "")
    (SCRATCH / "eq_stderr.txt").write_text(stderr or "")
    errs = [l for l in ((stdout or "") + "\n" + (stderr or "")).splitlines()
            if "rror" in l or "xcept" in l or "#10" in l]
    print(f"--- {len((stdout or '').splitlines())} trace lines, {len(errs)} err lines")
    for l in errs[:15]:
        print("  ERR", l)
    print(f"trace -> {SCRATCH/'eq_trace.txt'}, stderr(+tree) -> {SCRATCH/'eq_stderr.txt'}")


if __name__ == "__main__":
    cmd = sys.argv[1] if len(sys.argv) > 1 else "recompile"
    if cmd == "recompile":
        do_recompile()
    elif cmd == "build":
        do_build()
    elif cmd == "run":
        do_run(sys.argv[2] if len(sys.argv) > 2 else "-",
               int(sys.argv[3]) if len(sys.argv) > 3 else 18)
    else:
        print(f"unknown cmd {cmd!r}", file=sys.stderr); sys.exit(1)
