#!/usr/bin/env python3
"""avm1_stroke_style_id_order: within one style layer, strokes draw in
LINE-STYLE-ID order, not shape-record order.

Pins (2026-11-23, s26 n-trap-stroke): SWFRecomp's recompiler emitted stroke
runs in record order. Ruffle's ShapeConverter (render/src/shape_utils.rs
flush_layer: "Paths are drawn in order of style id, not based on the order of
the draw commands") collects a layer's edges per style id and draws them in
id order, as Flash does. N's exit-door panel (char 202) strokes its inner rect
with style 2 FIRST and the outer rect with style 1 AFTER; both share the
right edge, so the edge column came out style-1 dark on ours and style-2
light on Ruffle (36-64 px per level-0 shot once the door opens).

Original equivalent shape (N's chars are not redistributed), one DefineShape:
  grey fill (0,0)-(80,60)
  record 1: style 2 (RED,  6 px) inner rect (20,10)-(80,50)   <- drawn LAST
  record 2: style 1 (BLUE, 6 px) outer rect (0,0)-(80,60)     <- drawn FIRST
The shared right edge x=80 must be RED from y=10..50 and BLUE elsewhere.
A second instance at x=110 uses a 1-twip hairline version of both strokes
(the N case: two 1 px strokes on one column).

Trace: exporter. Image: exporter, -f 2.
Regenerate:  python3 create_test_swf.py
Golden:      WGPU_BACKEND=vulkan ~/CC/ruffle/target/release/exporter -s -f 2 test.swf out  (keep out/1.png)
"""
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import Bits, tag, place_object2, do_action, swf_file, trace_str  # noqa: E402

T = 20


def nbits(*vals):
    return max(max(abs(v).bit_length() for v in vals) + 1, 2)


def define_shape(cid, w1, w2):
    fills = bytes([1, 0x00, 0xb0, 0xb0, 0xb9])
    lines = bytes([2]) + struct.pack('<H', w1) + bytes([0, 0, 255]) \
        + struct.pack('<H', w2) + bytes([255, 0, 0])
    b = Bits().u(1, 4).u(2, 4)

    def style(x, y, fill1=None, line=None):
        b.u(0, 1).u(0, 1).u(1 if line is not None else 0, 1).u(1 if fill1 is not None else 0, 1)
        b.u(0, 1).u(1, 1)
        n = nbits(x, y)
        b.u(n, 5).s(x, n).s(y, n)
        if fill1 is not None:
            b.u(fill1, 1)
        if line is not None:
            b.u(line, 2)

    def line(dx, dy):
        n = nbits(dx, dy)
        b.u(1, 1).u(1, 1).u(n - 2, 4)
        if dx and dy:
            b.u(1, 1).s(dx, n).s(dy, n)
        elif dx:
            b.u(0, 1).u(0, 1).s(dx, n)
        else:
            b.u(0, 1).u(1, 1).s(dy, n)

    # record 1: inner rect, fill 1 + line style 2, starting on the shared edge
    style(80 * T, 10 * T, fill1=1, line=2)
    for dx, dy in ((0, 40 * T), (-60 * T, 0), (0, -40 * T), (60 * T, 0)):
        line(dx, dy)
    # record 2: outer rect, no fill, line style 1
    style(80 * T, 0, fill1=0, line=1)
    for dx, dy in ((0, 60 * T), (-80 * T, 0), (0, -60 * T), (80 * T, 0)):
        line(dx, dy)
    b.u(0, 1).u(0, 5)
    pad = 4 * T
    n = nbits(-pad, 80 * T + pad, 60 * T + pad)
    bounds = Bits().u(n, 5).s(-pad, n).s(80 * T + pad, n).s(-pad, n).s(60 * T + pad, n).bytes()
    return tag(2, struct.pack('<H', cid) + bounds + fills + lines + b.bytes())


defs = define_shape(1, 6 * T, 6 * T) + define_shape(2, 1, 1)
f1 = (place_object2(1, 1, tx=10 * T, ty=20 * T) + place_object2(2, 2, tx=110 * T, ty=20 * T)
      + do_action(trace_str('placed')))
swf_file(HERE / 'test.swf', [f1, b''], version=8, w=200, h=100, prefix=defs)
