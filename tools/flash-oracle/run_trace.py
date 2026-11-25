#!/usr/bin/env python3
"""Flash Player trace oracle for Ruffle-layout test dirs (incl. our regression/).

    run_trace.py <test_dir> [-o out.txt] [--diff] [--wrapped] [--frames N]

Default (direct) mode = what `cargo testutils execute` does: run test.swf as
the projector's root movie with a temp HOME + mm.cfg, LC_ALL=C, and stop on
max-duration / max-idle. Unlike testutils, the timeouts default to the test's
own length (num_frames / frame rate + 2 s), because Flash never stops at
num_frames: traces from frames after num_frames may appear at the end.

--wrapped runs the SWF as a LOADED child of capture/CaptureWrapper.swf, which
counts ticks exactly (README "Tick alignment") and cuts the log at the end of
tick N — the same cut Ruffle's runner makes. The child is then not the
root movie (_level0 / stage / loaderInfo differ), so prefer direct mode and
use --wrapped to locate the num_frames boundary inside the direct log.

Output is flashlog.txt verbatim (LF newlines), the format of Ruffle's output.txt.
"""
import argparse
import difflib
import os
import shutil
import sys
import tempfile
import tomllib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import flashenv  # noqa: E402
import run_image  # noqa: E402

HERE = os.path.dirname(os.path.abspath(__file__))


def load_toml(d):
    p = os.path.join(d, "test.toml")
    if not os.path.exists(p):
        return {}
    with open(p, "rb") as f:
        return tomllib.load(f)


XGRAB = os.path.join(HERE, "xgrab", "xgrab")

# Flash ErrorReportingEnable lines (only logged with mm.cfg ErrorReportingEnable=1).
WARNING_PREFIXES = ("Warning: ",)


def golden_has_warnings(d):
    """Some goldens were captured with ErrorReportingEnable although their
    test.toml has no log_warnings (s28: set_property_values/swf4,
    global_proto_decls*). Any line starting "Warning: " in output.txt -- the
    form Flash logs them in -- switches --log-warnings on."""
    p = os.path.join(d, "output.txt")
    if not os.path.exists(p):
        return False
    with open(p, encoding="utf-8", errors="replace") as f:
        return any(line.startswith(WARNING_PREFIXES) for line in f)


def type_trigger(marker, text, delay_ms=150):
    import subprocess

    def fn(denv):
        r = subprocess.run([XGRAB, "--type", text, str(delay_ms)], env=denv,
                           capture_output=True, text=True)
        print(f"# typed {text!r} after {marker!r}: {r.stderr.strip()}", file=sys.stderr)
    return (marker, fn)


def run_direct(test_dir, swf, frames, rate, log_warnings, max_duration=None, max_idle=None,
               windows=False, triggers=(), pin=True, quality=None, fonts=(), overrun=None):
    """pin: start from capture/PinStub.swf, which loads the test into _level0
    only once the drawing area is 1:1 (README "Direct-mode window pin").
    overrun: seconds the run may continue past the cap while flashlog is
    still growing (default flashenv.run_cap; 0 = hard cut at the cap)."""
    cap, default_overrun = flashenv.run_cap(frames, rate)
    # The pin's own cost: the gate (~1.5 s Linux, 3 s Windows) plus ~3 STUB
    # frames (it polls __pin_go.txt on enterFrame at the test's rate, and the
    # _level0 load lands a frame later): 0.25 fps -> first trace at 13.7 s.
    period = 1.0 / (rate if rate > 0 else 1.0)
    md = max_duration or cap + (((4.0 if windows else 2.5) + 3 * period) if pin else 0)
    ov = default_overrun if overrun is None else overrun
    mi = max_idle or md
    stage_tmp = gate = None
    if pin and not windows:
        # Flash resolves relative URLs against the FIRST root's directory, so
        # the stub must sit inside (a staged copy of) the test dir.
        stage_tmp = tempfile.mkdtemp(prefix="flashpin-")
        test_dir = os.path.join(stage_tmp, os.path.basename(os.path.abspath(test_dir)))
        shutil.copytree(os.path.dirname(os.path.abspath(swf)), test_dir)
        swf = os.path.join(test_dir, os.path.basename(swf))
    try:
        if windows:
            mi = max_idle or 2.5  # idle counts only after the first write
            root = flashenv.pinned_root(swf, test_dir, quality=quality) if pin else swf
            gate = flashenv.PinGate(test_dir) if pin else None
            env = flashenv.WinPlayerEnv(log_warnings=log_warnings, trust_paths=[test_dir])
            log = env.run(root, max_duration=md, max_idle=mi, pin_gate=gate, overrun=ov)
        else:
            root = flashenv.pinned_root(swf, test_dir, quality=quality) if pin else os.path.abspath(swf)
            gate = flashenv.PinGate(test_dir) if pin else None
            env = flashenv.PlayerEnv(log_warnings=log_warnings, trust_paths=[test_dir], fonts=fonts)
            log = env.run(root, max_duration=md, max_idle=mi, cwd=test_dir, triggers=triggers,
                          pin_gate=gate, overrun=ov)
    finally:
        if stage_tmp:
            shutil.rmtree(stage_tmp, ignore_errors=True)
    reason = env.stop_reason
    env.cleanup()
    if gate is not None:
        reason += f" pin={gate.released}"
    return log, reason


def run_wrapped(test_dir, swf, frames, rate, log_warnings, max_duration=None):
    info = flashenv.swf_info(swf)
    work = tempfile.mkdtemp(prefix="flashtrace-")
    try:
        wrapper = os.path.join(work, "wrapper.swf")
        flashenv.patch_swf_header(os.path.join(HERE, "capture", "CaptureWrapper.swf"), wrapper,
                                  info["rect"], info["rate"])
        cfg = {"swf": "file://" + os.path.abspath(swf), "width": int(info["width"]),
               "height": int(info["height"]), "bg": info["bg"], "ticks": frames,
               "image": "0", "marks": "1", "verbose": "0"}
        with open(os.path.join(work, "capture_config.txt"), "w") as f:
            f.write("".join(f"{k}={v}\n" for k, v in cfg.items()))
        env = flashenv.PlayerEnv(log_warnings=log_warnings, trust_paths=[work, test_dir])
        md = max_duration or (frames / max(rate, 1.0) * 3 + 5.0)
        log = env.run(wrapper, max_duration=md, max_idle=md, cwd=work,
                      done_marker="#FLASHCAP DONE")
        reason = env.stop_reason
        env.cleanup()
    finally:
        shutil.rmtree(work, ignore_errors=True)
    out = []
    for line in log.splitlines(keepends=True):
        if line.startswith(f"#FLASHCAP TICK {frames}\n"):
            break
        if not line.startswith("#FLASHCAP"):
            out.append(line)
    return "".join(out), reason


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("test_dir")
    ap.add_argument("-o", "--output", help="write the Flash trace here (never the fixture's output.txt unless you mean it)")
    ap.add_argument("--diff", action="store_true", help="diff against <test_dir>/output.txt")
    ap.add_argument("--wrapped", action="store_true")
    ap.add_argument("--windows", action="store_true", help="direct mode on the Windows projector")
    ap.add_argument("--frames", type=int)
    ap.add_argument("--no-pin", action="store_true", help="direct mode WITHOUT the window pin "
                    "(test.swf is the projector's first root; show-all scaled for its first frames)")
    ap.add_argument("--force-pin", action="store_true", help="keep the window pin even when the "
                    "SWF defines a frame-1 root onLoad (which the pinned run never fires)")
    ap.add_argument("--swf", default="test.swf")
    ap.add_argument("--max-duration", type=float)
    ap.add_argument("--max-idle", type=float)
    ap.add_argument("--overrun", type=float, help="seconds a direct run may continue past its cap "
                    "while flashlog is still growing (default max(5 s, test length); 0 = hard cut)")
    ap.add_argument("--type", help="type this text (XTest) into the projector window once "
                    "--type-after appears in the log (Linux direct mode)")
    ap.add_argument("--type-after", default="", help="log marker that triggers --type (default: first trace)")
    ap.add_argument("--type-delay-ms", type=int, default=150)
    ap.add_argument("--log-warnings", action="store_true",
                    help="ErrorReportingEnable=1 (Ruffle sets it only for log_warnings tests)")
    a = ap.parse_args()
    d = os.path.abspath(a.test_dir)
    toml = load_toml(d)
    frames = a.frames or toml.get("num_frames") or toml.get("num_ticks") or 1
    swf = os.path.join(d, a.swf)
    info = flashenv.swf_info(swf)
    lw = a.log_warnings or bool(toml.get("log_warnings", False))
    if not lw and not a.log_warnings and golden_has_warnings(d):
        print("# NOTE: output.txt contains Flash ErrorReportingEnable lines (Warning: ...): "
              "running with --log-warnings", file=sys.stderr)
        lw = True
    if not a.wrapped and not a.no_pin and not a.force_pin and flashenv.root_onload_defined(swf):
        # The pin loads the test as a REPLACED _level0: Flash then fires no
        # frame-1 root onLoad (s28). Unpinned keeps it (show-all scaled for the
        # first frames instead -- the lesser evil for a trace).
        print("# NOTE: the SWF defines a frame-1 root onLoad, which the pinned run never fires: "
              "running UNPINNED (--force-pin overrides)", file=sys.stderr)
        a.no_pin = True
    if a.wrapped:
        log, reason = run_wrapped(d, swf, frames, info["rate"], lw, a.max_duration)
    else:
        if a.windows:
            # Windows can't read the WSL fs: stage a copy under C:\flashplayer\work.
            os.makedirs(flashenv.WIN_ROOT + "/work", exist_ok=True)
            work = tempfile.mkdtemp(prefix="flashtrace-", dir=flashenv.WIN_ROOT + "/work")
            stage = os.path.join(work, "test")
            shutil.copytree(d, stage)
            log, reason = run_direct(stage, os.path.join(stage, a.swf), frames, info["rate"], lw,
                                     a.max_duration, a.max_idle, windows=True, pin=not a.no_pin,
                                     quality=run_image.toml_quality(toml), overrun=a.overrun)
            shutil.rmtree(work, ignore_errors=True)
        else:
            trig = [type_trigger(a.type_after, a.type, a.type_delay_ms)] if a.type else []
            log, reason = run_direct(d, swf, frames, info["rate"], lw, a.max_duration, a.max_idle,
                                     triggers=trig, pin=not a.no_pin,
                                     quality=run_image.toml_quality(toml),
                                     fonts=flashenv.toml_fonts(d, toml), overrun=a.overrun)
    if a.output:
        with open(a.output, "w", newline="\n") as f:
            f.write(log)
    print(f"# flash trace: mode={'wrapped' if a.wrapped else 'direct'}"
          f"{' windows' if a.windows else ''}{' unpinned' if a.no_pin and not a.wrapped else ''} frames={frames} rate={info['rate']} stop={reason}",
          file=sys.stderr)
    if reason.endswith("pin=None"):
        print("#" * 72 + "\n# WARNING: the window pin NEVER RELEASED: the test SWF never ran (this\n"
              "# log is the stub's). Seen with 8 parallel Linux runs (xvfb-run -a); keep to\n"
              "# <= 4 in parallel and re-run.\n" + "#" * 72, file=sys.stderr)
    if "TRUNCATED" in reason:
        print("#" * 72 + "\n# WARNING: flashlog was STILL BEING WRITTEN at the run cap: this capture\n"
              "# may be TRUNCATED (or the test traces every frame forever). Re-run with a\n"
              "# larger --max-duration / --overrun before grading against it.\n" + "#" * 72,
              file=sys.stderr)
    if a.diff:
        exp_p = os.path.join(d, "output.txt")
        exp = open(exp_p).read() if os.path.exists(exp_p) else ""
        if exp == log:
            print("BYTE-IDENTICAL to output.txt")
        else:
            sys.stdout.writelines(difflib.unified_diff(exp.splitlines(True), log.splitlines(True),
                                                       "output.txt", "flash"))
            sys.exit(1)
    elif not a.output:
        sys.stdout.write(log)


if __name__ == "__main__":
    main()
