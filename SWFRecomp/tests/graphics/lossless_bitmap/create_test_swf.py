#!/usr/bin/env python3
"""Generate test.swf for lossless_bitmap graphics test.

Tests DefineBitsLossless (tag 20) with a 24-bit RGB lossless bitmap used as
a ClippedBitmap fill inside a rectangular shape.  The bitmap is an 8x8 pixel
image split into four colored quadrants (red, green, blue, yellow).
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

# Build an 8x8 pixel bitmap with four colored quadrants:
#   Top-left:  red       Top-right:  green
#   Bot-left:  blue      Bot-right:  yellow
W, H = 8, 8
pixels = []
for y in range(H):
    for x in range(W):
        if y < H // 2:
            pixels.append((255, 0, 0) if x < W // 2 else (0, 255, 0))
        else:
            pixels.append((0, 0, 255) if x < W // 2 else (255, 255, 0))

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# DefineBitsLossless tag (object_id=1) with the 8x8 bitmap
swf.define_bits_lossless(object_id=1, width=W, height=H, pixels=pixels)

# Rectangle shape filled with the lossless bitmap
# The shape is 160x160 twips = 8x8 pixels, so each bitmap pixel maps 1:1 at scale 20
left, top = 2000, 2000
right, bottom = left + W * 20, top + H * 20

shape = swf.define_shape(object_id=2, bounds=(left, right, top, bottom))
shape.add_fill(ClippedBitmapFill(
    object_id=1,
    matrix={"scaleX": 20.0, "scaleY": 20.0, "transX": left, "transY": top},
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
