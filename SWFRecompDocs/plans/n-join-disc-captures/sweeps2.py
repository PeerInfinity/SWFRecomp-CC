#!/usr/bin/env python3
"""sweeps2.py NAME -> spec JSON. Each cell: one shape whose probed point (cap end
or corner) sits at the item origin, offset by (qx, qy) quarter pixels."""
import json, sys
L = 160  # 8 px arms
DIRS = {"R": (1, 0), "D": (0, 1), "L": (-1, 0), "U": (0, -1)}
def shapes():
    out = []
    # caps: a single segment starting at the origin (start cap) in each direction
    for d in "RDLU":
        dx, dy = DIRS[d]; out.append(("cap" + d, [0, 0], [[dx * L, dy * L]]))
    # corners: incoming d1 then outgoing d2, corner at origin
    for d1 in "RDLU":
        for d2 in "RDLU":
            a, b = DIRS[d1], DIRS[d2]
            if a[0] * b[0] + a[1] * b[1] != 0: continue
            out.append(("j" + d1 + d2, [-a[0] * L, -a[1] * L], [[a[0] * L, a[1] * L], [b[0] * L, b[1] * L]]))
    return out
def spec(lws, cell=22, cols=48):
    items = []; k = 0
    for lw in lws:
        for name, st, ed in shapes():
            for qy in range(4):
                for qx in range(4):
                    cx, cy = (k % cols) * cell + cell // 2, (k // cols) * cell + cell // 2
                    items.append({"lw": lw, "name": name, "qx": qx, "qy": qy, "start": st, "edges": ed,
                                  "m": [1, 0, 0, 1, cx * 20 + qx * 5, cy * 20 + qy * 5]})
                    k += 1
    rows = (k + cols - 1) // cols
    return {"w": cols * cell, "h": rows * cell, "items": items}
S = {"jc": [10, 20, 40, 60, 80]}
if __name__ == "__main__":
    print(json.dumps(spec(S[sys.argv[1]])))
