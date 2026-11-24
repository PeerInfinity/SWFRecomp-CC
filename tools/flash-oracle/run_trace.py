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

HERE = os.path.dirname(os.path.abspath(__file__))


def load_toml(d):
    p = os.path.join(d, "test.toml")
    if not os.path.exists(p):
        return {}
    with open(p, "rb") as f:
        return tomllib.load(f)


XGRAB = os.path.join(HERE, "xgrab", "xgrab")


def type_trigger(marker, text, delay_ms=150):
    import subprocess

    def fn(denv):
        r = subprocess.run([XGRAB, "--type", text, str(delay_ms)], env=denv,
                           capture_output=True, text=True)
        print(f"# typed {text!r} after {marker!r}: {r.stderr.strip()}", file=sys.stderr)
    return (marker, fn)


def run_direct(test_dir, swf, frames, rate, log_warnings, max_duration=None, max_idle=None,
               windows=False, triggers=()):
    length = frames / max(rate, 1.0)
    md = max_duration or (length + 2.0)
    mi = max_idle or md
    if windows:
        mi = max_idle or 2.5  # idle counts only after the first write
        env = flashenv.WinPlayerEnv(log_warnings=log_warnings, trust_paths=[test_dir])
        log = env.run(swf, max_duration=md, max_idle=mi)
    else:
        env = flashenv.PlayerEnv(log_warnings=log_warnings, trust_paths=[test_dir])
        log = env.run(os.path.abspath(swf), max_duration=md, max_idle=mi, cwd=test_dir,
                      triggers=triggers)
    reason = env.stop_reason
    env.cleanup()
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
    ap.add_argument("--swf", default="test.swf")
    ap.add_argument("--max-duration", type=float)
    ap.add_argument("--max-idle", type=float)
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
                                     a.max_duration, a.max_idle, windows=True)
            shutil.rmtree(work, ignore_errors=True)
        else:
            trig = [type_trigger(a.type_after, a.type, a.type_delay_ms)] if a.type else []
            log, reason = run_direct(d, swf, frames, info["rate"], lw, a.max_duration, a.max_idle,
                                     triggers=trig)
    if a.output:
        with open(a.output, "w", newline="\n") as f:
            f.write(log)
    print(f"# flash trace: mode={'wrapped' if a.wrapped else 'direct'}"
          f"{' windows' if a.windows else ''} frames={frames} rate={info['rate']} stop={reason}",
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
