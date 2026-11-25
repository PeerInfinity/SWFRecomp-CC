#!/usr/bin/env python3
"""Per item: left-edge profile -> (snapped?, ink interval).  Classify each width
row: SNAP if every offset gives only 0/100% pixels, else AA.  Also prints the
first ink pixel per offset.  usage: summarize.py DIR [PNG]"""
import json, sys, math
from PIL import Image
d = sys.argv[1]; png = sys.argv[2] if len(sys.argv) > 2 else d + "/flash.png"
spec = json.load(open(d + "/layout.json"))
im = Image.open(png).convert("L"); px = im.load()
rows = {}
for it in spec["items"]:
    a, b, c, dd, tx, ty = it["m"]
    ex = tx / 20; my = int(ty / 20 + dd * it["rh"] / 2)
    fx = math.floor(ex)
    prof = [round((1 - px[x, my] / 255) * 4) / 4 for x in range(fx - 4, fx + 5)]
    first = next((i for i, v in enumerate(prof) if v > 0), None)
    rows.setdefault((it["lw"], it.get("label2", "")), []).append((ex, prof, first))
for (lw, l2), lst in rows.items():
    solid = all(all(v in (0, 1) for v in p) for _, p, _ in lst)
    tot = set(round(sum(p), 2) for _, p, _ in lst)
    starts = " ".join("%+d" % (f - 4) if all(v in (0, 1) for v in p) else "~%+d" % (f - 4) for e, p, f in lst)
    print("lw=%3d %s %-5s ink=%s  start(rel floor e): %s" % (lw, l2, "SNAP" if solid else "AA", sorted(tot), starts))
