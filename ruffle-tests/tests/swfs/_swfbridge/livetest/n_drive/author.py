#!/usr/bin/env python3
"""author.py - batch-try N input scripts on the local Ruffle exporter (oracle).
  python3 author.py [--every N] [--frames F] "attempt0" "attempt1" ...
Each attempt "ticks:KEYS|..." runs on episode 0 level 0; the probe force-kills
at script end (AUTOKILL) so N's own retry flow starts the next attempt.
Prints a sampled trajectory + events per attempt. Authoring aid only."""
import os, re, subprocess, sys, tempfile
HERE = os.path.dirname(os.path.abspath(__file__))
EXP = os.path.expanduser("~/CC/ruffle/target/release/exporter")
args = sys.argv[1:]; every = 10; frames = None; kill = "true"
while args and args[0].startswith("--"):
    a = args.pop(0)
    if a == "--every": every = int(args.pop(0))
    elif a == "--frames": frames = int(args.pop(0))
    elif a == "--nokill": kill = "false"
script = "/".join(args)
ticks = sum(sum(int(p.split(":")[0]) for p in a.split("|")) for a in args)
frames = frames or 230 + ticks + 130 * len(args)
w = tempfile.mkdtemp()
swf = os.path.join(w, "a.swf")
subprocess.run([os.path.join(HERE, "build.sh"), script, swf], check=True, env=dict(os.environ, AUTOKILL=kill),
               stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
subprocess.run(["flock", "/tmp/swfrecomp-cpu.lock", EXP, "-s", "-f", str(frames), "--trace-log", os.path.join(w, "t.txt"), swf,
                os.path.join(w, "png")], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
out = open(os.path.join(w, "t.txt")).read().splitlines()
open(os.path.join(HERE, "last_trace.txt"), "w").write("\n".join(out) + "\n")
for l in out:
    if l.startswith("ND "):
        if "phase" in l and ("run" not in l and "dead" not in l and "retry" not in l and "post" not in l): continue
        print(l)
    elif l.startswith("NF"):
        m = re.search(r"t=(\d+) x=(\S+) y=(\S+) vx=(\S+) vy=(\S+) st=(\d+) k=(\S+)", l)
        t = int(m.group(1))
        if t % every == 0:
            print(f"  t={t:4d} x={float(m.group(2)):7.2f} y={float(m.group(3)):7.2f} vx={float(m.group(4)):6.2f} vy={float(m.group(5)):6.2f} st={m.group(6)} k={m.group(7)}")
print("frames", frames, "trace ->", os.path.join(HERE, "last_trace.txt"))
