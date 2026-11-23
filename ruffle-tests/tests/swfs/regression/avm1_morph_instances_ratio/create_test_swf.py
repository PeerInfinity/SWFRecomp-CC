#!/usr/bin/env python3
"""avm1_morph_instances_ratio: several instances of ONE morph character at
different ratios in the same frame must each draw at their own ratio.

Pins (2026-11-23, s26 n-gold-streaks): the runtime lerped a morph's vertices
(and colours) into the character's single shared GPU region at compose time
(tag.c, renderer_update_vertices at ch->morph_start_offset). Those writes are
queue writes that all land before the frame's draws, so every instance drew
the LAST-composed instance's ratio. In N, coins collected 1-3 frames apart all
play the same morph (char 568/569); every streak drew at the newest pickup's
ratio and looked 2-3 frames late. Fix: renderer_draw_morph lerps each
instance at draw time into the per-frame dynamic vertex region, with its own
dynamic colour slots.

One DefineMorphShape: a RED 40x40 square (start) -> a BLUE 20x80 bar (end).
Only ratios 0 and 65535 are used, so geometry and colour are exact (no lerp
rounding) and the image holds at tolerance 0.

  depth 1  root, ratio 0      at x=20    -> red square
  depth 2  root, ratio 65535  at x=100   -> blue bar
  depth 3  sprite "s" holding the morph at ratio 0, at x=180 -> red square
  depth 4  sprite "t" holding the morph at ratio 65535, at x=260 -> blue bar

Before the fix every instance drew as the last-composed one (all four the same
shape and colour). Trace: Ruffle exporter; image: exporter, -f 2.

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png -s -f 2  (writes a dir; keep its last frame 1.png)
"""
import struct, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / "avm1_parent_child_morph"))
from create_test_swf import (Bits, sbits_needed, rect, tag, shape_records,  # noqa: E402
                             box_edges)

T = 20


def define_morph(morph_id, start_px, end_px, rgb0, rgb1):
    sx0, sy0, sx1, sy1 = [v * T for v in start_px]
    ex0, ey0, ex1, ey1 = [v * T for v in end_px]
    fs = bytearray([1, 0x00]) + bytes(rgb0) + b"\xff" + bytes(rgb1) + b"\xff"
    ls = b"\x00"
    se = shape_records((sx0, sy0), box_edges(sx0, sy0, sx1, sy1), 1, 1)
    ee = shape_records((ex0, ey0), box_edges(ex0, ey0, ex1, ey1), 0, 0)
    body = (struct.pack("<H", morph_id) + rect(sx0, sx1, sy0, sy1) + rect(ex0, ex1, ey0, ey1)
            + struct.pack("<I", len(fs) + len(ls) + len(se)) + fs + ls + se + ee)
    return tag(46, body)


def matrix_translate(tx, ty):
    b = Bits()
    b.u(0, 1); b.u(0, 1)
    nb = sbits_needed(tx, ty)
    b.u(nb, 5); b.s(tx, nb); b.s(ty, nb)
    return b.bytes()


def place(depth, cid, x=0, y=0, ratio=None, name=None):
    flags = 0x02 | 0x04 | (0x10 if ratio is not None else 0) | (0x20 if name else 0)
    body = bytes([flags]) + struct.pack("<HH", depth, cid) + matrix_translate(x * T, y * T)
    if ratio is not None:
        body += struct.pack("<H", ratio)
    if name:
        body += name.encode() + b"\0"
    return tag(26, body)


def sprite(sid, inner):
    return tag(39, struct.pack("<HH", sid, 1) + inner + tag(1, b"") + tag(0, b""))


def doaction_trace(msg):
    s = msg.encode() + b"\0"
    return tag(12, b"\x96" + struct.pack("<H", len(s) + 1) + b"\x00" + s + b"\x26\x00")


MORPH, SPR_A, SPR_B = 1, 2, 3
body = (tag(69, struct.pack("<I", 0)) + tag(9, b"\xff\xff\xff")
        + define_morph(MORPH, (0, 20, 40, 60), (10, 0, 30, 80), (255, 0, 0), (0, 0, 255))
        + sprite(SPR_A, place(1, MORPH, ratio=0))
        + sprite(SPR_B, place(1, MORPH, ratio=65535))
        + place(1, MORPH, 20, 10, ratio=0)
        + place(2, MORPH, 100, 10, ratio=65535)
        + place(3, SPR_A, 180, 10, name="s")
        + place(4, SPR_B, 260, 10, name="t")
        + doaction_trace("placed") + tag(1, b"")
        + doaction_trace("frame 2") + tag(1, b"") + tag(0, b""))
hdr = rect(0, 320 * T, 0, 100 * T) + struct.pack("<HH", 30 << 8, 2)
out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / "test.swf")
open(out, "wb").write(b"FWS" + bytes([6]) + struct.pack("<I", 8 + len(hdr) + len(body)) + hdr + body)
