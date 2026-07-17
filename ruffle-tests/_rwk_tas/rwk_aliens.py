#!/usr/bin/env python3
"""Print per-tick screen positions of red alien blobs (clustered) + player."""
import sys, os
import numpy as np
from PIL import Image

S = os.path.dirname(os.path.abspath(__file__))
RUN = sys.argv[1] if len(sys.argv) > 1 else f"{S}/rwk_run"
T0, T1 = int(sys.argv[2]), int(sys.argv[3])
STEP = int(sys.argv[4]) if len(sys.argv) > 4 else 4

def clusters(xs, ys, gap=24):
    pts = sorted(zip(xs, ys))
    out = []
    cur = [pts[0]] if pts else []
    for p in pts[1:]:
        if p[0] - cur[-1][0] > gap:
            out.append(cur); cur = [p]
        else:
            cur.append(p)
    if cur: out.append(cur)
    return [(sum(x for x,_ in c)/len(c), sum(y for _,y in c)/len(c)) for c in out]

for t in range(T0, T1, STEP):
    p = f"{RUN}/f{t:03d}.ppm"
    if not os.path.exists(p): break
    im = np.asarray(Image.open(p).convert("RGB"), dtype=np.int16)
    r, g, b = im[:,:,0], im[:,:,1], im[:,:,2]
    am = (r > 200) & (g < 90) & (b < 90)
    ys, xs = np.nonzero(am[:460])   # skip nothing; aliens anywhere
    al = clusters(xs, ys) if len(xs) > 20 else []
    pm = (np.abs(r-154) < 12) & (np.abs(g-143) < 12) & (np.abs(b-120) < 12) \
       | (np.abs(r-134) < 10) & (np.abs(g-124) < 10) & (np.abs(b-102) < 10)
    pys, pxs = np.nonzero(pm)
    pl = (pxs.mean(), pys.mean()) if len(pys) > 25 else None
    astr = " ".join(f"A({ax:.0f},{ay:.0f})" for ax, ay in al)
    pstr = f"P({pl[0]:.0f},{pl[1]:.0f})" if pl else "P(-)"
    print(f"t={t:4d} {pstr:16s} {astr}")
