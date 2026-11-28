#!/usr/bin/env python3
"""avm1_hairline_scaled_instances: one shape with 1-twip ("hairline") strokes,
drawn by several attachMovie'd instances at very different small scales in
the same frame. Every instance must draw its strokes exactly one device pixel
wide at ITS OWN scale.

Shape of N's level-1 trap switch (s26 n-trap-stroke; N's own chars are not
redistributed, this is an original equivalent): a 12x12 px square, grey fill
with a 1-twip outline, plus an inner half-rect with a 1-twip black outline,
placed at x8.333 inside the exported sprite "sw", and the sprite attached at
_xscale/_yscale 5% (net x0.417, ~5 px on screen), as N does.

  t0  5%     at (40.3, 40.6)   subpixel origin
  t1  12.5%  at (100, 40)
  t2  31.25% at (150.45, 90.2)
  t3  5%     at (40, 100)

Scales are >2x apart ON PURPOSE. Ruffle (core/src/tessellation_cache.rs,
2026-07) reuses a shape's tessellation for any draw within 2x of a cached
scale, so two instances within 2x of each other get a stroke width that
depends on which drew FIRST (N: the 7.5% locked-door trigger tessellates
char 188, the 5% trap switch reuses it -> 0.67 px strokes). Flash rasterises
each draw at its own matrix. With >2x spacing the exporter golden is the
Flash rule; see SWFRecomp-CC-history:SWFRecompDocs/plans/n-trap-stroke-report.md.

Regenerate:  python3 create_test_swf.py
Golden:      WGPU_BACKEND=vulkan ~/CC/ruffle/target/release/exporter -s -f 3 test.swf out  (keep out/2.png)
"""
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (Bits, tag, define_sprite, do_action, swf_file, push,  # noqa: E402
                     call_method, get_var, get_path, set_member, trace_expr,
                     STOP)

SHAPE, SPRITE = 1, 2


def nbits(*vals):
    return max(max(abs(v).bit_length() for v in vals) + 1, 2)


def define_hairline_shape(cid):
    # fills: 1 = grey, 2 = dark; lines: 1 = 1 twip slate, 2 = 1 twip black
    fills = bytes([2, 0x00, 0xac, 0xac, 0xb5, 0x00, 0x66, 0x66, 0x66])
    lines = bytes([2]) + struct.pack('<H', 1) + bytes([0x5f, 0x5f, 0x6b]) \
        + struct.pack('<H', 1) + bytes([0, 0, 0])
    b = Bits().u(2, 4).u(2, 4)

    def style(x, y, fill1, line):
        # StateLineStyle, StateFillStyle1, StateMoveTo
        b.u(0, 1).u(0, 1).u(1, 1).u(1, 1).u(0, 1).u(1, 1)
        n = nbits(x, y)
        b.u(n, 5).s(x, n).s(y, n)
        b.u(fill1, 2).u(line, 2)

    def line(dx, dy):
        n = nbits(dx, dy)
        b.u(1, 1).u(1, 1).u(n - 2, 4)
        if dx and dy:
            b.u(1, 1).s(dx, n).s(dy, n)
        elif dx:
            b.u(0, 1).u(0, 1).s(dx, n)
        else:
            b.u(0, 1).u(1, 1).s(dy, n)

    style(120, -120, 1, 1)
    for dx, dy in ((0, 240), (-240, 0), (0, -240), (240, 0)):
        line(dx, dy)
    style(-80, -80, 2, 2)
    for dx, dy in ((160, 0), (0, 80), (-160, 0), (0, -80)):
        line(dx, dy)
    b.u(0, 1).u(0, 5)
    n = nbits(121)
    bounds = Bits().u(n, 5).s(-121, n).s(121, n).s(-121, n).s(121, n).bytes()
    return tag(2, struct.pack('<H', cid) + bounds + fills + lines + b.bytes())


def place_scaled(depth, cid, scale):
    fx = int(round(scale * 65536))
    n = nbits(fx)
    m = Bits().u(1, 1).u(n, 5).s(fx, n).s(fx, n).u(0, 1).u(0, 5).bytes()
    return tag(26, struct.pack('<BHH', 0x02 | 0x04, depth, cid) + m)


INST = [(5.0, 40.3, 40.6), (12.5, 100.0, 40.0), (31.25, 150.45, 90.2), (5.0, 40.0, 100.0)]

f1 = call_method(get_var('_root'), 'createEmptyMovieClip', 'buf', 10)
for i, (sc, x, y) in enumerate(INST):
    name = 't%d' % i
    f1 += call_method(get_var('buf'), 'attachMovie', 'sw', name, 2 + i)
    for prop, v in (('_x', x), ('_y', y), ('_xscale', sc), ('_yscale', sc)):
        f1 += set_member(get_path('buf', name), prop, push(float(v)))
f1 += trace_expr('attached ', get_path('buf', 't0', '_xscale'), ' ', get_path('buf', 't2', '_xscale'))
f1 += STOP

defs = define_hairline_shape(SHAPE) + define_sprite(SPRITE, [place_scaled(2, SHAPE, 8.333328247070312)])
defs += tag(56, struct.pack('<HH', 1, SPRITE) + b'sw\x00')
swf_file(HERE / 'test.swf', [do_action(f1), b'', b''], version=8, w=200, h=150, prefix=defs)
