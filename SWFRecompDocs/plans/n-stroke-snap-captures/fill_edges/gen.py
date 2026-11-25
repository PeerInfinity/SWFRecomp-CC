#!/usr/bin/env python3
"""Filled (no stroke) 16x10 px rects at x/y + 0..19 twips; rows: quality via test.toml only."""
import sys, struct, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent.parent))
from probe import tag, BW, rect, matrix, place2
def filled(sid, W, H):
    b = struct.pack("<H", sid) + rect(0, W, 0, H) + bytes([1, 0, 0, 0, 0]) + bytes([0])
    w = BW(); w.u(1, 4); w.u(0, 4)
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)
    w.u(20, 5); w.sb(0, 20); w.sb(0, 20); w.u(1, 1)
    for dx, dy in ((W, 0), (0, H), (-W, 0), (0, -H)):
        w.u(1, 1); w.u(1, 1); w.u(15, 4)
        if dy == 0: w.u(0, 1); w.u(0, 1); w.sb(dx, 17)
        else: w.u(0, 1); w.u(1, 1); w.sb(dy, 17)
    w.u(0, 6)
    return tag(2, b + w.bytes(), force_long=True)
defs = filled(100, 320, 200); fr = b""
for o in range(20):
    fr += place2(o + 1, 100, matrix(1, 0, 0, 1, (10 + o * 26) * 20 + o, 10 * 20 + o))
body = tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff") + defs + fr + tag(1, b"") + tag(0, b"")
hdr = rect(0, 540 * 20, 0, 40 * 20, 16) + struct.pack("<HH", 30 << 8, 1)
open("test.swf", "wb").write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
