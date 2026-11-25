#!/usr/bin/env python3
"""Stroke-snap probe generator (s28 n-stroke-snap).

Builds a SWF of stroked rect outlines (black on white, no fill), each placed
with an arbitrary MATRIX, as DefineShape (v1) or DefineShape4 (LINESTYLE2 with
pixelHinting / noHScale / noVScale flags).  Writes test.swf + layout.json (the
analyzer reads the layout to find each item's edges in device space).

usage: probe.py SPEC.json OUTDIR
SPEC = {"w":W,"h":H,"items":[{"lw":twips,"rw":px,"rh":px,"m":[a,b,c,d,tx,ty],
         "v":1|4,"hint":0|1,"noh":0|1,"nov":0|1,"curve":0|1}...]}
m: a=scaleX b=rotSkew0 c=rotSkew1 d=scaleY (Flash MATRIX order), tx/ty twips.
"""
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
    (out / "layout.json").write_text(json.dumps(spec))
    (out / "test.toml").write_text("num_frames = 1\n")

if __name__ == "__main__":
    build(json.load(open(sys.argv[1])), sys.argv[2])
