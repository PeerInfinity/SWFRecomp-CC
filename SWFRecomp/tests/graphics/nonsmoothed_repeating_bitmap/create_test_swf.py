#!/usr/bin/env python3
"""Generate test.swf for nonsmoothed_repeating_bitmap graphics test.

Tests NonSmoothedRepeatingBitmap fill type (0x42) with a DefineBitsLossless bitmap.
The bitmap is a 4x4 pixel image with four colored quadrants (red, green, blue,
yellow) that tiles 4x4 across a 200x200 rectangle using nearest-neighbor sampling.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, NonSmoothedRepeatingBitmapFill,
    ShapeSetup, LineTo,
)

# Build a 4x4 pixel bitmap with four colored quadrants:
#   Top-left:  red       Top-right:  green
#   Bot-left:  blue      Bot-right:  yellow
W, H = 4, 4
pixels = []
for y in range(H):
    for x in range(W):
        if y < H // 2:
            pixels.append((255, 0, 0) if x < W // 2 else (0, 255, 0))
        else:
            pixels.append((0, 0, 255) if x < W // 2 else (255, 255, 0))

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(128, 128, 128)  # grey background to distinguish tile edges

# DefineBitsLossless tag (object_id=1) with the 4x4 bitmap
swf.define_bits_lossless(object_id=1, width=W, height=H, pixels=pixels)

# Rectangle shape filled with the non-smoothed repeating bitmap
# Display at 200x200 pixels, centered on 550x400 canvas
DISPLAY_W, DISPLAY_H = 200, 200
left = (550 - DISPLAY_W) // 2 * 20   # center horizontally (twips)
top = (400 - DISPLAY_H) // 2 * 20    # center vertically (twips)
right = left + DISPLAY_W * 20
bottom = top + DISPLAY_H * 20

# Scale so each tile = 50px (200px / 4 tiles).  Each texel = 50/4 = 12.5px.
# 12.5 pixels * 20 twips/pixel = 250 twips per texel
sx = 12.5 * 20.0  # 250.0 twips per texel
sy = 12.5 * 20.0

shape = swf.define_shape(object_id=2, bounds=(left, right, top, bottom))
shape.add_fill(NonSmoothedRepeatingBitmapFill(
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
