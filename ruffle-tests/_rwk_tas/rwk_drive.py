#!/usr/bin/env python3
"""RWK TAS driver: compile a compact plan into the line-based event format,
run the built test_run, dump frames at checkpoints.

Plan entries: (tick, "down"/"up", key) or (tick, "mouse", x, y).
Keys: LEFT=37 UP=38 RIGHT=39 DOWN=40 X=88 Z=90 C=67 R=82.
One WAIT per tick; events for tick N go before the (N+1)th WAIT.
"""
import os, subprocess, sys, shutil

S = "/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/3723b0cd-94f4-4a46-bec2-939e57820ae3/scratchpad"
BUILD = f"{S}/rwk_build"
FRAMES = f"{S}/rwk_run"

KEY = {"LEFT": 37, "UP": 38, "RIGHT": 39, "DOWN": 40, "X": 88, "Z": 90,
       "C": 67, "R": 82}
CHAR = {"X": 120, "Z": 122, "C": 99, "R": 114}


def hold(plan, key, t0, t1):
    plan.append((t0, "down", key))
    plan.append((t1, "up", key))


def press(plan, key, t):
    hold(plan, key, t, t + 2)


def click(plan, x, y, t):
    plan.append((t, "move", x, y))
    plan.append((t + 2, "mdown", x, y))
    plan.append((t + 4, "mup", x, y))


def compile_plan(plan, total_ticks, path):
    by_tick = {}
    for e in plan:
        by_tick.setdefault(e[0], []).append(e)
    lines = []
    for t in range(total_ticks):
        for e in by_tick.get(t, []):
            kind = e[1]
            if kind == "down":
                lines.append(f"KEY_DOWN {KEY[e[2]]} {CHAR.get(e[2], 0)} 0")
            elif kind == "up":
                lines.append(f"KEY_UP {KEY[e[2]]} {CHAR.get(e[2], 0)} 0")
            elif kind == "move":
                lines.append(f"MOUSE_MOVE {e[2]:.6f} {e[3]:.6f}")
            elif kind == "mdown":
                lines.append(f"MOUSE_DOWN_LEFT {e[2]:.6f} {e[3]:.6f} 0")
            elif kind == "mup":
                lines.append(f"MOUSE_UP_LEFT {e[2]:.6f} {e[3]:.6f}")
        lines.append("WAIT")
    with open(path, "w") as f:
        f.write("\n".join(lines) + "\n")


def run(total_ticks, dump=True):
    shutil.rmtree(FRAMES, ignore_errors=True)
    os.makedirs(FRAMES, exist_ok=True)
    env = dict(os.environ)
    env["TZ"] = "NPT-5:45"
    env["AVM2_MAX_TICKS"] = str(total_ticks)
    if dump:
        env["AVM2_CPU_DUMP"] = f"{FRAMES}/f"
    r = subprocess.run([f"{BUILD}/test_run", f"{S}/rwk_events.txt"],
                       cwd=BUILD, env=env, capture_output=True, text=True,
                       timeout=900)
    errs = [l for l in (r.stdout + r.stderr).splitlines()
            if "rror" in l or "xception" in l]
    print("exit", r.returncode, "errlines", len(errs))
    for l in errs[:5]:
        print("  ", l)


RUFFLE_KEY = {"LEFT": "ArrowLeft", "RIGHT": "ArrowRight", "UP": "ArrowUp",
              "DOWN": "ArrowDown", "X": "KeyX", "Z": "KeyZ", "C": "KeyC",
              "R": "KeyR"}


def compile_ruffle_json(plan, total_ticks, path):
    """Emit the same plan in the Ruffle-test AutomatedEvent format for the
    RUFFLE_INPUT_FILE-patched exporter (one Wait per frame)."""
    import json
    by_tick = {}
    for e in plan:
        by_tick.setdefault(e[0], []).append(e)
    out = []
    for t in range(total_ticks):
        for e in by_tick.get(t, []):
            kind = e[1]
            if kind == "down":
                out.append({"type": "KeyDown", "key": RUFFLE_KEY[e[2]]})
            elif kind == "up":
                out.append({"type": "KeyUp", "key": RUFFLE_KEY[e[2]]})
            elif kind == "move":
                out.append({"type": "MouseMove", "pos": [e[2], e[3]]})
            elif kind == "mdown":
                out.append({"type": "MouseDown", "pos": [e[2], e[3]], "btn": "Left"})
            elif kind == "mup":
                out.append({"type": "MouseUp", "pos": [e[2], e[3]], "btn": "Left"})
        out.append({"type": "Wait"})
    with open(path, "w") as f:
        json.dump(out, f)


if __name__ == "__main__":
    plan = []
    exec(open(sys.argv[1]).read())  # defines plan + TOTAL
    compile_plan(plan, TOTAL, f"{S}/rwk_events.txt")
    run(TOTAL)
