#!/usr/bin/env python3
"""Generate test.swf for lossless_bitmap_palette graphics test.

Tests DefineBitsLossless (tag 20) with format 3 = ColorMap8 (8-bit indexed
palette, RGB entries). Same four-quadrant 8x8 bitmap as lossless_bitmap,
but encoded with a 4-entry palette + 1-byte-per-pixel indices.

Regression for the format-3 decoder added in commit 813c50b8 (per
SWFRecompDocs/plans/define-bits-lossless-format-3-4.md). Before that fix
the recompiler threw EXC_ARG on any bitmap_format != 5.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

W, H = 8, 8
# 4-entry RGB palette: red, green, blue, yellow.
palette = [
    (255, 0,   0  ),  # 0: red
    (0,   255, 0  ),  # 1: green
    (0,   0,   255),  # 2: blue
    (255, 255, 0  ),  # 3: yellow
]
indices = []
for y in range(H):
    for x in range(W):
        if y < H // 2:
            indices.append(0 if x < W // 2 else 1)
        else:
            indices.append(2 if x < W // 2 else 3)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

swf.define_bits_lossless_format3(
    object_id=1, width=W, height=H,
    palette=palette, indices=indices,
)

DISPLAY_W, DISPLAY_H = 200, 200
left = (550 - DISPLAY_W) // 2 * 20
top = (400 - DISPLAY_H) // 2 * 20
right = left + DISPLAY_W * 20
bottom = top + DISPLAY_H * 20
sx = float(DISPLAY_W) / W * 20.0
sy = float(DISPLAY_H) / H * 20.0

shape = swf.define_shape(object_id=2, bounds=(left, right, top, bottom))
shape.add_fill(ClippedBitmapFill(
    object_id=1,
    matrix={"scaleX": sx, "scaleY": sy, "transX": left, "transY": top},
))

shape.add_edges([
    ShapeSetup(x=right, y=bottom, fillStyle1=1),
    LineTo(-(right - left), 0),
    LineTo(0, -(bottom - top)),
    LineTo(right - left, 0),
    LineTo(0, bottom - top),
])

swf.place_object(object_id=2, depth=1)
swf.show_frame()
swf.save("test.swf")
