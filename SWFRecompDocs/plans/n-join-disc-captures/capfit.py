#!/usr/bin/env python3
# brute-force the cap shape on capR start cells for one lw: polygon arcs
import json, sys, math, itertools
from PIL import Image
D, PNG, LW = sys.argv[1], sys.argv[2], int(sys.argv[3]); NAME = sys.argv[4] if len(sys.argv) > 4 else "capR"
spec = json.load(open(D + "/layout.json")); im = Image.open(PNG).convert("L"); PX = im.load()
def obs(x, y): return min(16, round((255 - PX[x, y]) / 16))
u = round(4 * LW / 20); W = 1 if u <= 4 else (2 if u == 8 else 3); h = W / 2
cells = []
for it in spec["items"]:
    if it["lw"] != LW or it["name"] != NAME: continue
    ox, oy = it["m"][4] // 20, it["m"][5] // 20
    cx = math.floor(4 * it["m"][4] / 20 + .5) / 4; cy = math.floor(4 * it["m"][5] / 20 + .5) / 4
    E = math.floor(4 * cy + .5); L = math.floor((E - 2 * W + 2) / 4)
    cells.append((ox, oy, cx, cy, L, {(x, y): obs(x, y) for x in range(ox - 3, ox) for y in range(oy - 3, oy + 4)}))
def poly_hw(n, phase, r, dy):
    # half-width at dy of a regular polygon (vertices at phase + k*2pi/n), radius r, centred
    pts = [(r * math.cos(phase + 2 * math.pi * k / n), r * math.sin(phase + 2 * math.pi * k / n)) for k in range(n)]
    xs = []
    for (x0, y0), (x1, y1) in zip(pts, pts[1:] + pts[:1]):
        if (y0 <= dy < y1) or (y1 <= dy < y0):
            xs.append(x0 + (dy - y0) * (x1 - x0) / (y1 - y0))
    return max(xs) if xs else -1
best = []
for n in (0, 8, 12, 16, 24, 32):
    for ph in ((0, math.pi / n) if n else (0,)):
        for rs in (h - 0.25, h - 0.1875, h - .125, h - .0625, h, h + .0625):
            for cymode in ("snap", "unsnap", "mid"):
                for sx, sy in ((.5, 0), (.5, .5), (0, 0), (.5, .25)):
                    err = 0
                    for ox, oy, cx, cy, L, ob in cells:
                        ys = L + W / 2
                        c_y = ys if cymode == "snap" else (cy if cymode == "unsnap" else (ys + cy) / 2)
                        for (x, y), v in ob.items():
                            k = 0
                            for j in range(4):
                                yy = y + (j + sy) / 4
                                if not (L <= yy < L + W): continue
                                dy = yy - c_y
                                hw = math.sqrt(max(0, rs * rs - dy * dy)) if (n == 0 and abs(dy) < rs) else (poly_hw(n, ph, rs, dy) if n else -1)
                                for i in range(4):
                                    xx = x + (i + sx) / 4
                                    if xx >= cx or (cx - xx) < hw: k += 1
                            err += abs(k - v)
                    best.append((err, n, round(ph, 3), rs, cymode, sx, sy))
best.sort()
for b in best[:12]: print(b)
import os
if os.environ.get("ALL"):
    for b in best: print(b)
