#!/usr/bin/env python3
"""widths.py DIR PNG...: per item, device stroke width on each edge (top,right,bottom,left of the
local rect) = ink integrated over an 8 px strip across the edge midpoint / 8; plus model predictions."""
import json, sys, math
from PIL import Image
D = sys.argv[1]; spec = json.load(open(D + "/layout.json"))
ims = [Image.open(p).convert("L") for p in sys.argv[2:]]; pxs = [im.load() for im in ims]
W, H = ims[0].size
L, RR = 8, 14
for it in spec["items"]:
    a, b, c, d, tx, ty = it["m"]
    f = lambda x, y: ((a * x + c * y + tx) / 20, (b * x + d * y + ty) / 20)
    w, h = it["rw"] * 20, it["rh"] * 20
    P = [f(0, 0), f(w, 0), f(w, h), f(0, h)]
    out = []
    for px in pxs:
        ws = []
        for i in range(4):
            P0, P1 = P[i], P[(i + 1) % 4]
            mx, my = (P0[0] + P1[0]) / 2, (P0[1] + P1[1]) / 2
            ln = math.dist(P0, P1); ux, uy = (P1[0] - P0[0]) / ln, (P1[1] - P0[1]) / ln
            tot = 0
            for X in range(int(mx - 25), int(mx + 26)):
                for Y in range(int(my - 25), int(my + 26)):
                    if not (0 <= X < W and 0 <= Y < H): continue
                    dx, dy = X + .5 - mx, Y + .5 - my
                    if abs(dx * ux + dy * uy) <= L / 2 and abs(-dx * uy + dy * ux) <= RR:
                        tot += 1 - px[X, Y] / 255
            ws.append(tot / L)
        out.append(ws)
    vx, vy = a + c, b + d
    pred = {"norm": math.hypot(vx, vy) / math.sqrt(2), "nov": abs(vx), "noh": abs(vy)}[it["row"]] * it["lw"] / 20
    print("%-4s %-7s M=[%5.2f %5.2f;%5.2f %5.2f] w1=%5.2f  " % (it["row"], it["label"], a, c, b, d, pred)
          + " | ".join(" ".join("%5.2f" % x for x in ws) for ws in out))
