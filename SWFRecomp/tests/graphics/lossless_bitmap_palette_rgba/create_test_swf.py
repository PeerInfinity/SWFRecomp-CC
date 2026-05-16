#!/usr/bin/env python3
"""Generate test.swf for lossless_bitmap_palette_rgba graphics test.

Tests DefineBitsLossless2 (tag 36) with format 3 = ColorMap8 palette
where each entry is RGBA (4 bytes) instead of RGB (3 bytes). Same 8x8
four-quadrant bitmap, but the four palette entries carry per-color
alpha (top half opaque, bottom half partially transparent).

Regression for the format-3 Lossless2 decoder added in commit 813c50b8
(per SWFRecompDocs/plans/define-bits-lossless-format-3-4.md). Exercises
the 4-byte palette stride that differs from the Lossless1 variant.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

W, H = 8, 8
# RGBA palette: red opaque, green opaque, blue half-alpha, yellow quarter-alpha.
palette = [
    (255, 0,   0,   255),  # 0: red, opaque
    (0,   255, 0,   255),  # 1: green, opaque
    (0,   0,   255, 128),  # 2: blue, 50% alpha
    (255, 255, 0,   64 ),  # 3: yellow, 25% alpha
]
indices = []
for y in range(H):
    for x in range(W):
        if y < H // 2:
            indices.append(0 if x < W // 2 else 1)
        else:
            indices.append(2 if x < W // 2 else 3)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

swf.define_bits_lossless2_format3(
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
