#!/usr/bin/env python3
"""cmp.py DIR FLASH.png OURS.png [OURS2.png]: per (lw, shape) summed |coverage diff| (in 1/16) over
each cell's 7x7 window, and px count with |diff|>2/255 levels."""
import json, sys
from PIL import Image
D = sys.argv[1]; spec = json.load(open(D + "/layout.json"))
ims = [Image.open(p).convert("L").load() for p in sys.argv[2:]]
def c(px, x, y): return (255 - px[x, y]) / 16
res = {}
for it in spec["items"]:
    ox, oy = it["m"][4] // 20, it["m"][5] // 20
    k = (it["lw"], it["name"][:3] if it["name"].startswith("cap") else ("rect" if it["name"] == "rect" else "join"))
    r = res.setdefault(k, [[0, 0] for _ in ims[1:]])
    for y in range(oy - 3, oy + 4):
        for x in range(ox - 3, ox + 4):
            f = c(ims[0], x, y)
            for i, im in enumerate(ims[1:]):
                d = abs(c(im, x, y) - f); r[i][0] += d; r[i][1] += d * 16 > 2
tot = [[0, 0] for _ in ims[1:]]
for k in sorted(res):
    print(k, "  ".join("err %7.1f px %4d" % tuple(v) for v in res[k]))
    for i, v in enumerate(res[k]): tot[i][0] += v[0]; tot[i][1] += v[1]
print("TOTAL", "  ".join("err %7.1f px %4d" % tuple(v) for v in tot))
