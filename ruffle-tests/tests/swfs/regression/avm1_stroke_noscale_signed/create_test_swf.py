#!/usr/bin/env python3
"""s28 n-join-disc goal 2: single noVScale / noHScale stroke widths under 34 matrices
(scales, rotations, R*diag, diag*R, shears, flips). Rows normal / noVScale / noHScale, 8 px declared
stroke, 24 px rect outlines, DefineShape4. Flash: width factor max(0, a+c) (noV), max(0, b+d) (noH)."""
import json, struct, sys, pathlib, math

def tag(code, body, force_long=False):
    if len(body) < 0x3F and not force_long:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body

class BW:
    def __init__(s): s.bits = []
    def u(s, v, n):
        for i in range(n - 1, -1, -1): s.bits.append((v >> i) & 1)
    def sb(s, v, n): s.u(v & ((1 << n) - 1), n)
    def bytes(s):
        b = s.bits + [0] * ((-len(s.bits)) % 8)
        return bytes(int("".join(map(str, b[i:i + 8])), 2) for i in range(0, len(b), 8))

def rect(x0, x1, y0, y1, nb=20):
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()

def matrix(a, b, c, d, tx, ty):
    w = BW()
    if (a, d) != (1, 1):
        w.u(1, 1); w.u(24, 5); w.sb(round(a * 65536), 24); w.sb(round(d * 65536), 24)
    else: w.u(0, 1)
    if (b, c) != (0, 0):
        w.u(1, 1); w.u(24, 5); w.sb(round(b * 65536), 24); w.sb(round(c * 65536), 24)
    else: w.u(0, 1)
    w.u(20, 5); w.sb(int(tx), 20); w.sb(int(ty), 20)
    return w.bytes()

def outline(sid, it):
    W, H, lw = it["rw"] * 20, it["rh"] * 20, it["lw"]
    v = it.get("v", 1)
    pad = lw + 40
    b = struct.pack("<H", sid) + rect(-pad, W + pad, -pad, H + pad)
    if v == 4:
        b += rect(0, W, 0, H)
        b += bytes([(1 if (it.get("noh") or it.get("nov")) else 0) << 1 | 1])
    b += bytes([0])                                   # 0 fills
    b += bytes([1])
    if v == 4:
        f1 = (0 << 6) | (0 << 4) | (0 << 3) | (it.get("noh", 0) << 2) | (it.get("nov", 0) << 1) | it.get("hint", 0)
        f2 = 0
        b += struct.pack("<H", lw) + bytes([f1, f2]) + bytes([0, 0, 0, 255])
    else:
        b += struct.pack("<H", lw) + bytes([0, 0, 0])
    w = BW(); w.u(0, 4); w.u(1, 4)
    nb = 20
    w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1)
    w.u(nb, 5); w.sb(0, nb); w.sb(0, nb)
    w.u(1, 1)
    def edge(dx, dy):
        w.u(1, 1); w.u(1, 1); w.u(17 - 2, 4); nb = 17
        if dx != 0 and dy != 0:
            w.u(1, 1); w.sb(dx, nb); w.sb(dy, nb)
        elif dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, nb)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, nb)
    def curve(cx, cy, ax, ay):
        w.u(1, 0 + 1) if False else None
        w.u(1, 1); w.u(0, 1); w.u(17 - 2, 4); nb = 17
        for q in (cx, cy, ax, ay): w.sb(q, nb)
    if it.get("curve"):
        # ellipse-ish: 4 quadratic arcs through the rect's edge midpoints
        hw, hh = W // 2, H // 2
        # restart at (0,hh)
        w2 = None
        curve(0, -hh, hw, 0)
        curve(hw, 0, hw, hh)
        curve(0, hh, -hw, 0)
        curve(-hw, 0, -hw, -hh)
    else:
        edge(W, 0); edge(0, H); edge(-W, 0); edge(0, -H)
    w.u(0, 6)
    if it.get("curve"):
        # moveto must start at (0, H/2) for the arc path
        w.bits = []
        w.u(0, 4); w.u(1, 4)
        w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1)
        w.u(nb, 5); w.sb(0, nb); w.sb(H // 2, nb)
        w.u(1, 1)
        hw, hh = W // 2, H // 2
        curve(0, -hh, hw, 0); curve(hw, 0, hw, hh); curve(0, hh, -hw, 0); curve(-hw, 0, -hw, -hh)
        w.u(0, 6)
    b += w.bytes()
    return tag(83 if v == 4 else 2, b, force_long=True)

def place2(depth, cid, mat):
    return tag(26, bytes([0x06]) + struct.pack("<H", depth) + struct.pack("<H", cid) + mat)

def build(spec, out):
    out = pathlib.Path(out); out.mkdir(parents=True, exist_ok=True)
    defs = b""; frame = b""
    for i, it in enumerate(spec["items"]):
        defs += outline(100 + i, it)
        frame += place2(i + 1, 100 + i, matrix(*it["m"]))
    body = tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs + frame + tag(1, b"") + tag(0, b"")
    hdr = rect(0, spec["w"] * 20, 0, spec["h"] * 20, 16) + struct.pack("<HH", 30 << 8, 1)
    (out / "test.swf").write_bytes(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)

def R(t):
    c, s = math.cos(math.radians(t)), math.sin(math.radians(t)); return [[c, -s], [s, c]]
def mul(A, B): return [[sum(A[i][k] * B[k][j] for k in range(2)) for j in range(2)] for i in range(2)]
def D(x, y): return [[x, 0], [0, y]]
MATS2 = [("dm21", D(-2, 1)), ("d2m1", D(2, -1)), ("d1m2", D(1, -2)), ("R180", R(180)), ("R135", R(135)),
         ("Rm45d21", mul(R(-45), D(2, 1))), ("Rm45d12", mul(R(-45), D(1, 2))), ("R60d21", mul(R(60), D(2, 1))),
         ("R120d21", mul(R(120), D(2, 1))), ("dm2m1", D(-2, -1)), ("R20d31", mul(R(20), D(3, 1))),
         ("R70d13", mul(R(70), D(1, 3))), ("Rm20d13", mul(R(-20), D(1, 3))), ("shx-.5", [[1, -.5], [0, 1]]),
         ("R10", R(10)), ("R80", R(80)), ("R100", R(100))]
MATS = [("I", D(1, 1)), ("d21", D(2, 1)), ("d12", D(1, 2)), ("dh1", D(.5, 1)), ("d1h", D(1, .5)),
        ("R30", R(30)), ("R45", R(45)), ("R45d12", mul(R(45), D(1, 2))), ("R45d21", mul(R(45), D(2, 1))),
        ("R30d12", mul(R(30), D(1, 2))), ("R30d21", mul(R(30), D(2, 1))), ("d12R45", mul(D(1, 2), R(45))),
        ("d21R45", mul(D(2, 1), R(45))), ("shx.5", [[1, .5], [0, 1]]), ("shy.5", [[1, 0], [.5, 1]]),
        ("R90d12", mul(R(90), D(1, 2))), ("dm12", D(-1, 2))]
MATS = MATS + MATS2
items = []; cell = 90; cols = 12; k = 0
for row, fl in (("norm", {}), ("nov", {"nov": 1}), ("noh", {"noh": 1})):
    for name, M in MATS:
        cx, cy = (k % cols) * cell + cell // 2, (k // cols) * cell + cell // 2
        # place the rect centre (12, 12 px local) at the cell centre
        lx, ly = 12 * 20, 12 * 20
        tx = cx * 20 - (M[0][0] * lx + M[0][1] * ly); ty = cy * 20 - (M[1][0] * lx + M[1][1] * ly)
        it = {"lw": 160, "rw": 24, "rh": 24, "v": 4, "row": row, "label": name,
              "m": [M[0][0], M[1][0], M[0][1], M[1][1], round(tx), round(ty)]}
        it.update(fl); items.append(it); k += 1
rows = (k + cols - 1) // cols
if __name__ == "__main__":
    build({"w": cols * cell, "h": rows * cell, "items": items}, pathlib.Path(__file__).resolve().parent)
