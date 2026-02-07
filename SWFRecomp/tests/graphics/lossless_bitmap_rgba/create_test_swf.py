#!/usr/bin/env python3
"""Generate test.swf for lossless_bitmap_rgba graphics test.

Tests DefineBitsLossless2 (tag 36) with a 32-bit ARGB lossless bitmap used as
a ClippedBitmap fill inside a rectangular shape.  The bitmap is an 8x8 pixel
image with four colored quadrants at varying alpha levels:
  Top-left:  red (fully opaque)      Top-right:  green (75% opaque)
  Bot-left:  blue (50% opaque)       Bot-right:  yellow (25% opaque)
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

# Build an 8x8 pixel RGBA bitmap with four colored quadrants at different alphas:
#   Top-left:  red   (a=255)    Top-right:  green (a=191)
#   Bot-left:  blue  (a=128)    Bot-right:  yellow (a=64)
W, H = 8, 8
pixels = []
for y in range(H):
    for x in range(W):
        if y < H // 2:
            if x < W // 2:
                pixels.append((255, 0, 0, 255))      # red, fully opaque
            else:
                pixels.append((0, 255, 0, 191))      # green, 75% opaque
        else:
            if x < W // 2:
                pixels.append((0, 0, 255, 128))      # blue, 50% opaque
            else:
                pixels.append((255, 255, 0, 64))     # yellow, 25% opaque

swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

# DefineBitsLossless2 tag (object_id=1) with the 8x8 RGBA bitmap
swf.define_bits_lossless2(object_id=1, width=W, height=H, pixels=pixels)

# Rectangle shape filled with the lossless RGBA bitmap
# Display at 200x200 pixels (quarter of 550x400 canvas), centered
DISPLAY_W, DISPLAY_H = 200, 200
left = (550 - DISPLAY_W) // 2 * 20   # center horizontally (twips)
top = (400 - DISPLAY_H) // 2 * 20    # center vertically (twips)
right = left + DISPLAY_W * 20
bottom = top + DISPLAY_H * 20
sx = float(DISPLAY_W) / W * 20.0  # twips per bitmap texel
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
