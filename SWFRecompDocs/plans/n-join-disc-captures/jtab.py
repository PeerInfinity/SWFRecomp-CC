#!/usr/bin/env python3
# per join: grid of (obs-model) summed over window, and corner-pixel obs, per (qx,qy)
import os, subprocess, sys, json, math
lw = sys.argv[1]
for j in ["jUR","jRD","jDL","jLU","jUL","jLD","jDR","jRU"]:
    out = subprocess.run(["python3","model.py","jc","jc/flash_high.png"], env=dict(os.environ, SHOW=lw+","+j), capture_output=True, text=True).stdout.split("\n")
    # parse blocks
    grids = {}
    i = 0
    while i < len(out):
        if out[i].startswith("q "):
            p = out[i].split(); qx, qy = int(p[1]), int(p[2])
            rows = out[i+1:i+8]
            grids[(qx,qy)] = [(r[3:10], r[13:20]) for r in rows]
            i += 8
        else: i += 1
    print("==", j, " obs|model 3x3 around origin pixel, rows qy, cols qx")
    for qy in range(4):
        for r in range(2, 5):
            print("  " + "    ".join(grids[(qx,qy)][r][0][2:5] + "|" + grids[(qx,qy)][r][1][2:5] for qx in range(4)))
        print()
