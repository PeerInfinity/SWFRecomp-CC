#!/usr/bin/env python3
"""show.py DIR PNG LW NAME : coverage /16 (hex, #=16) of a 6x6 window around the probed point per (qx,qy)."""
import json, sys, math
from PIL import Image
d, png, lw, name = sys.argv[1], sys.argv[2], int(sys.argv[3]), sys.argv[4]
end = len(sys.argv) > 5
spec = json.load(open(d + "/layout.json")); im = Image.open(png).convert("L"); px = im.load()
def k(x, y):
    v = round((255 - px[x, y]) / 16); return "#" if v >= 16 else ("." if v == 0 else "%x" % v)
rows = {}
for it in spec["items"]:
    if it["lw"] != lw or it["name"] != name: continue
    ox, oy = it["m"][4] // 20, it["m"][5] // 20   # integer pixel of the origin (q adds < 1px)
    if end:
        ex = it["start"][0] + sum(e[0] for e in it["edges"]); ey = it["start"][1] + sum(e[1] for e in it["edges"])
        ox += ex // 20; oy += ey // 20
    g = ["".join(k(x, y) for x in range(ox - 3, ox + 4)) for y in range(oy - 3, oy + 4)]
    rows.setdefault(it["qy"], []).append(g)
for qy in sorted(rows):
    print("qy=%d  (qx 0..3)" % qy)
    for r in range(7): print("   " + "   ".join(g[r] for g in rows[qy]))
