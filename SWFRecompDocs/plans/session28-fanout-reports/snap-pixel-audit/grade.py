#!/usr/bin/env python3
"""grade.py VARIANTS... : for each test/cmp in the 51 rows, outliers vs golden and vs Flash (draw and screen)."""
import sys, os, re, json, tomllib
import numpy as np
from PIL import Image
S = os.path.dirname(os.path.abspath(__file__))
R = "/home/robert/CC/SWFRecomp-CC"
F = R + "/SWFRecompDocs/plans/session28-fanout-reports/snap-pixel-audit/flash/png"
rows = []
for l in open(R + "/SWFRecompDocs/plans/session28-fanout-reports/interim2-pixel-diff.txt"):
    m = re.match(r"\s+(\S+) \[(\S+)\]: pass -> fail", l)
    if m: rows.append(m.groups())
def load(p):
    if not os.path.exists(p): return None
    return np.asarray(Image.open(p).convert("RGBA")).astype(int)
def tol(t, c):
    d = tomllib.load(open(f"{R}/ruffle-tests/tests/swfs/{t}/test.toml", "rb"))
    ic = d.get("image_comparisons", {}).get(c, {})
    ch = ic.get("checks") or [ic]
    return ch[0].get("tolerance", 0)
def cmp(a, b, t):
    if a is None or b is None: return None
    if a.shape != b.shape: return "shape"
    d = np.abs(a - b)
    return int((d[..., :3] > t).sum()), int((d[..., :3].max(-1) > 2).sum())
variants = sys.argv[1:]
out = []
for t, c in rows:
    T = tol(t, c)
    g = load(f"{R}/ruffle-tests/tests/swfs/{t}/{c}.expected.png")
    k = t.replace("/", "__")
    fd = load(f"{F}/{k}__{c}.png"); fs = load(f"{F}/{k}__{c}.screen.png")
    rec = {"test": t, "cmp": c, "tol": T, "golden_vs_flash_draw": cmp(g, fd, T), "golden_vs_flash_screen": cmp(g, fs, T)}
    for v in variants:
        a = load(f"{S}/ab/{v}/{t}/{c}.actual.png")
        rec[v] = {"golden": cmp(a, g, T), "flash_draw": cmp(a, fd, T), "flash_screen": cmp(a, fs, T)}
    out.append(rec)
json.dump(out, open(S + "/grade.json", "w"), indent=1)
def f(x): return "-" if x is None else (x if isinstance(x, str) else f"{x[0]}/{x[1]}")
print("test cmp tol | G~Fd G~Fs | " + " | ".join(f"{v}: G Fd Fs" for v in variants))
for r in out:
    print(f"{r['test']} {r['cmp']} {r['tol']} | {f(r['golden_vs_flash_draw'])} {f(r['golden_vs_flash_screen'])} | " +
          " | ".join(f"{f(r[v]['golden'])} {f(r[v]['flash_draw'])} {f(r[v]['flash_screen'])}" for v in variants))
