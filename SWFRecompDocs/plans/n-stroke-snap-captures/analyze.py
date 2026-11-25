#!/usr/bin/env python3
"""Edge-profile analyzer for probe.py layouts (axis-aligned items only).
usage: analyze.py OUTDIR PNG [--edge left|top|right|bottom]
Prints, per item, coverage (0..1, black ink on white) of the 7 pixels around the
item's left edge (row through its middle) and top edge (column through middle)."""
import json, sys, math
from PIL import Image
d = sys.argv[1]; png = sys.argv[2]
spec = json.load(open(d + "/layout.json"))
im = Image.open(png).convert("L"); px = im.load()
def cov(x, y):
    if 0 <= x < im.width and 0 <= y < im.height: return 1 - px[x, y] / 255
    return float('nan')
def fmt(v): return " ." if v < 0.02 else ("##" if v > 0.98 else "%2d" % min(99, round(v * 100)))
for i, it in enumerate(spec["items"]):
    a, b, c, dd, tx, ty = it["m"]
    ex, ey = tx / 20, ty / 20
    my = int(ey + dd * it["rh"] / 2); mx = int(ex + a * it["rw"] / 2)
    fx, fy = math.floor(ex), math.floor(ey)
    L = [cov(x, my) for x in range(fx - 3, fx + 4)]
    T = [cov(mx, y) for y in range(fy - 3, fy + 4)]
    tag = it.get("label", "")
    print("%3d lw=%4d s=%s,%s edge x=%7.2f L[%s] y=%7.2f T[%s] %s" % (
        i, it["lw"], a, dd, ex, " ".join(fmt(v) for v in L), ey, " ".join(fmt(v) for v in T), tag))
