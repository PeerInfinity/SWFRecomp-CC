#!/usr/bin/env python3
"""s28 n-join-disc: snapped-stroke caps and corners (DefineShape1, round caps/joins).
W = 0.5/1/2/3/4 px x 4 caps + 8 corners x 16 quarter-pixel (qx, qy) offsets. Regenerates test.swf.
Flash golden: SWFRecomp-CC-history:SWFRecompDocs/plans/n-join-disc-captures/jc/flash_high.png."""
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

def place2(depth, cid, mat):
    return tag(26, bytes([0x06]) + struct.pack("<H", depth) + struct.pack("<H", cid) + mat)

def shape(sid, it):
    lw = it["lw"]; sx, sy = it["start"]
    xs = [sx]; ys = [sy]; x, y = sx, sy
    for dx, dy in it["edges"]:
        x += dx; y += dy; xs.append(x); ys.append(y)
    pad = lw + 40
    b = struct.pack("<H", sid) + rect(min(xs) - pad, max(xs) + pad, min(ys) - pad, max(ys) + pad)
    b += bytes([0]) + bytes([1]) + struct.pack("<H", lw) + bytes([0, 0, 0])
    w = BW(); w.u(0, 4); w.u(1, 4)
    nb = 20
    w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1)   # stylechange: lineStyle + moveTo
    w.u(nb, 5); w.sb(sx, nb); w.sb(sy, nb)
    w.u(1, 1)
    for dx, dy in it["edges"]:
        w.u(1, 1); w.u(1, 1); w.u(17 - 2, 4)
        if dx != 0 and dy != 0: w.u(1, 1); w.sb(dx, 17); w.sb(dy, 17)
        elif dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, 17)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, 17)
    w.u(0, 6)
    b += w.bytes()
    return tag(2, b, force_long=True)

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
def build(spec, out):
    out = pathlib.Path(out); out.mkdir(parents=True, exist_ok=True)
    defs = b""; frame = b""
    for i, it in enumerate(spec["items"]):
        defs += shape(100 + i, it)
        frame += place2(i + 1, 100 + i, matrix(*it["m"]))
    body = tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs + frame + tag(1, b"") + tag(0, b"")
    hdr = rect(0, spec["w"] * 20, 0, spec["h"] * 20, 16) + struct.pack("<HH", 30 << 8, 1)
    (out / "test.swf").write_bytes(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)

if __name__ == "__main__":
    build(spec([10, 20, 40, 60, 80]), pathlib.Path(__file__).resolve().parent)
