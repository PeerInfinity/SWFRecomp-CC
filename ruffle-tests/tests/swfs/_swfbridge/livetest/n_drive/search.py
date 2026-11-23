#!/usr/bin/env python3
"""search.py LEVEL PREFIX CAND... (s26 n-levels route search): run PREFIX|CAND attempts via author.py (one exporter
session) and print per-attempt: events, final pos/state, and the last standing pos."""
import os, re, subprocess, sys
HERE = os.path.dirname(os.path.abspath(__file__))
lvl, prefix, cands = sys.argv[1], sys.argv[2], sys.argv[3:]
atts = [(prefix + "|" + c) if prefix else c for c in cands]
env = dict(os.environ, START_LEVEL=lvl, FREEZE="")
subprocess.run(["python3", os.path.join(HERE, "author.py")] + atts, env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
lines = open(os.path.join(HERE, "last_trace.txt")).read().splitlines()
cur = -1; info = {}
for l in lines:
    m = re.match(r"ND attempt (\d+)", l)
    if m: cur = int(m.group(1)); info[cur] = {"ev": [], "last": None, "stand": None}; continue
    if cur < 0: continue
    if l.startswith("ND EV") and "kill" not in l: info[cur]["ev"].append(l[6:])
    if l.startswith("ND EV kill"):
        if "type=4 fx=0 fy=0" not in l: info[cur]["ev"].append(l[6:])
    m = re.match(r"NF a=\d+ t=(\d+) x=(\S+) y=(\S+) vx=(\S+) vy=(\S+) st=(\d+)", l)
    if m:
        t, x, y, vx, vy, st = int(m.group(1)), float(m.group(2)), float(m.group(3)), float(m.group(4)), float(m.group(5)), m.group(6)
        info[cur]["last"] = (t, round(x,1), round(y,1), round(vx,2), round(vy,2), st)
        if st in ("0","1","2") and t > 5: info[cur]["stand"] = (t, round(x,1), round(y,1))
for i, c in enumerate(cands):
    d = info.get(i)
    if not d: print(i, c, "NO RUN"); continue
    print(f"{i} {c:40s} last={d['last']} stand={d['stand']} ev={d['ev']}")
