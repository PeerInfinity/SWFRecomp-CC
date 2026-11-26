#!/usr/bin/env python3
"""Fit Flash's snapped-stroke cap/join coverage. model.py DIR PNG [variant]"""
import json, sys, math, os
from PIL import Image
D, PNG = sys.argv[1], sys.argv[2]
VAR = sys.argv[3] if len(sys.argv) > 3 else "A"
spec = json.load(open(D + "/layout.json"))
CLOSE = os.environ.get("CLOSE")   # rect outlines: join the closing vertex
for it in spec["items"]:
    if "rw" in it:
        W_, H_ = it["rw"] * 20, it["rh"] * 20
        it.update(start=[0, 0], edges=[[W_, 0], [0, H_], [-W_, 0], [0, -H_]], name="rect", qx=0, qy=0)
    if CLOSE and len(it["edges"]) > 2 and sum(e[0] for e in it["edges"]) == 0 and sum(e[1] for e in it["edges"]) == 0:
        it["edges"].append(list(it["edges"][0]))
im = Image.open(PNG).convert("L"); PX = im.load()
import os
SX, SY = float(os.environ.get("SX", .5)), float(os.environ.get("SY", 0))
SHOW = os.environ.get("SHOW")
def W_of(lw):
    if not 0 < lw < 70: return 0
    u = round(4 * lw / 20)
    return 1 if u <= 4 else (2 if u == 8 else (3 if u == 12 else 0))
def qz(v): return math.floor(4 * v + 0.5) / 4
def snapc(e, W):
    E = math.floor(4 * e + 0.5); L = math.floor((E - 2 * W + 2) / 4); return L + 0.5 * W
JW1 = os.environ.get("JW1", "disc")   # W=1 join: none|disc
def prims(it):
    """device-space primitives: ('rect',x0,y0,x1,y1) half-open, ('disc',cx,cy,r,clip|None)."""
    W = W_of(it["lw"]); tx, ty = it["m"][4] / 20, it["m"][5] / 20
    pts = [(it["start"][0], it["start"][1])]
    for dx, dy in it["edges"]: pts.append((pts[-1][0] + dx, pts[-1][1] + dy))
    pts = [(qz(tx + x / 20), qz(ty + y / 20)) for x, y in pts]
    h = W / 2; rr = h - float(os.environ.get("RD", 0))
    segs = []
    for (x0, y0), (x1, y1) in zip(pts, pts[1:]):
        if y0 == y1:
            Y = snapc(y0, W); segs.append(dict(rect=(min(x0, x1), Y - h, max(x0, x1), Y + h), a=(x0, Y), b=(x1, Y)))
        else:
            X = snapc(x0, W); segs.append(dict(rect=(X - h, min(y0, y1), X + h, max(y0, y1)), a=(X, y0), b=(X, y1)))
    out = [("rect",) + s["rect"] for s in segs]
    n = len(segs)
    for i, s in enumerate(segs):
        for end in ("a", "b"):
            joined = (end == "a" and i > 0) or (end == "b" and i < n - 1)
            if not joined:
                if W > 1: out.append(("disc", s[end][0], s[end][1], rr, None))
                continue
            o = segs[i - 1] if end == "a" else segs[i + 1]
            # corner square = intersection of the two lateral strips
            r1, r2 = s["rect"], o["rect"]
            if s["rect"][0] == r1[0] and (r1[3] - r1[1]) == W:   # s horizontal
                pass
            hz = lambda r: abs((r[3] - r[1]) - W) < 1e-9 and abs((r[2] - r[0]) - W) > 1e-9
            sq = (r2[0], r1[1], r2[2], r1[3]) if hz(r1) else (r1[0], r2[1], r1[2], r2[3])
            if W > 1 or JW1 == "disc":
                out.append(("disc", s[end][0], s[end][1], rr, sq if os.environ.get("NOCLIP") is None else None))
    return out
CAPN = int(os.environ.get("CAPN", 0))
def inpoly(n, r, dx, dy):
    # regular n-gon, vertices at k*2pi/n, circumradius r
    if dx * dx + dy * dy >= r * r: return False
    a = math.atan2(dy, dx) % (2 * math.pi); s = 2 * math.pi / n
    k = math.floor(a / s); a0 = k * s
    # inside iff projection on the edge normal < apothem
    mid = a0 + s / 2
    return dx * math.cos(mid) + dy * math.sin(mid) < r * math.cos(s / 2)
def inside(p, x, y):
    if p[0] == "rect": return p[1] <= x < p[3] and p[2] <= y < p[4]
    if p[4] is not None and not (p[4][0] <= x < p[4][2] and p[4][1] <= y < p[4][3]): return False
    if CAPN: return inpoly(CAPN, p[3], x - p[1], y - p[2])
    return (x - p[1]) ** 2 + (y - p[2]) ** 2 < p[3] ** 2
NS = int(os.environ.get("NS", 4))
def cover(ps, px, py):
    if NS == 1:
        return 16 if any(inside(p, px + SX, py + SY) for p in ps) else 0
    n = 0
    for j in range(4):
        for i in range(4):
            x = px + (i + SX) / 4; y = py + (j + SY) / 4
            if any(inside(p, x, y) for p in ps): n += 1
    return n
def obs(x, y): return min(16, round((255 - PX[x, y]) / 16))
tot = 0; bad = 0; per = {}
ONLY = os.environ.get("ONLY")
for it in spec["items"]:
    if W_of(it["lw"]) == 0: continue
    if ONLY and not (it["name"].startswith(ONLY.split(",")[1]) and str(it["lw"]) == ONLY.split(",")[0]): continue
    ps = prims(it)
    ox, oy = it["m"][4] // 20, it["m"][5] // 20
    err = 0
    for y in range(oy - 3, oy + 4):
        for x in range(ox - 3, ox + 4):
            e = abs(cover(ps, x, y) - obs(x, y)); err += e
    if SHOW and SHOW == "%d,%s" % (it["lw"], it["name"]):
        print("q", it["qx"], it["qy"], "err", err)
        for y in range(oy - 3, oy + 4):
            f = lambda v: "#" if v >= 16 else ("." if v == 0 else "%x" % v)
            print("   " + "".join(f(obs(x, y)) for x in range(ox - 3, ox + 4)) + "   " + "".join(f(cover(ps, x, y)) for x in range(ox - 3, ox + 4)))
    key = (it["lw"], it["name"]); per.setdefault(key, [0, 0]); per[key][0] += err; per[key][1] += 1
    tot += err
print("total abs err", tot)
for k in sorted(per): print(k, per[k][0])
