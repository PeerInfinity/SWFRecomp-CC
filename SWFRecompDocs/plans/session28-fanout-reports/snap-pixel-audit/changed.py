#!/usr/bin/env python3
"""changed.py A B : per row, over pixels where variant A != variant B, which is closer to Flash."""
import sys, os, json
import numpy as np
from PIL import Image
S = os.path.dirname(os.path.abspath(__file__))
R = "/home/robert/CC/SWFRecomp-CC"
F = R + "/SWFRecompDocs/plans/session28-fanout-reports/snap-pixel-audit/flash/png"
A, B = sys.argv[1], sys.argv[2]
rows = json.load(open(S + "/grade.json"))
res = {}
def L(p):
    return np.asarray(Image.open(p).convert("RGB")).astype(int) if os.path.exists(p) else None
for r in rows:
    t, c = r["test"], r["cmp"]; k = t.replace("/", "__")
    a = L(f"{S}/ab/{A}/{t}/{c}.actual.png"); b = L(f"{S}/ab/{B}/{t}/{c}.actual.png")
    fs = L(f"{F}/{k}__{c}.screen.png"); fd = L(f"{F}/{k}__{c}.png")
    f = fs if fs is not None else fd
    src = "screen" if fs is not None else "draw"
    if a is None or b is None or f is None or a.shape != f.shape:
        print(f"{t} {c}: n/a"); continue
    m = (a != b).any(-1)
    n = int(m.sum())
    if n == 0: print(f"{t} {c}: identical"); continue
    da = np.abs(a - f)[m].max(-1); db = np.abs(b - f)[m].max(-1)
    ea, eb = int((da <= 2).sum()), int((db <= 2).sum())
    closer_a = int((da < db).sum()); closer_b = int((db < da).sum())
    res[f"{t}|{c}"] = dict(changed=n, A_exact=ea, B_exact=eb, A_closer=closer_a, B_closer=closer_b, L1_A=int(da.sum()), L1_B=int(db.sum()), src=src)
    print(f"{t} {c} [{src}]: changed {n}px; within2 of Flash {A}={ea} {B}={eb}; closer {A}={closer_a} {B}={closer_b}; maxL1 {A}={int(da.sum())} {B}={int(db.sum())}")
json.dump(res, open(f"{S}/changed_{A}_{B}.json", "w"), indent=1)
