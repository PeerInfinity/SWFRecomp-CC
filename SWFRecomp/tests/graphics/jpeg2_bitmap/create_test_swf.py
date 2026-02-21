#!/usr/bin/env python3
"""Generate test.swf for jpeg2_bitmap graphics test.

Tests DefineBitsJPEG2 (tag 21) with a self-contained JPEG bitmap used as
a ClippedBitmap fill inside a rectangular shape.  The bitmap is an 8x8 pixel
image split into four colored quadrants (red, green, blue, yellow).
"""
import io
import sys
import os

sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from PIL import Image
from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

# Build an 8x8 pixel bitmap with four colored quadrants:
#   Top-left:  red       Top-right:  green
#   Bot-left:  blue      Bot-right:  yellow
W, H = 8, 8
img = Image.new("RGB", (W, H))
for y in range(H):
    for x in range(W):
        if y < H // 2:
            img.putpixel((x, y), (255, 0, 0) if x < W // 2 else (0, 255, 0))
        else:
            img.putpixel((x, y), (0, 0, 255) if x < W // 2 else (255, 255, 0))

# Save as JPEG bytes (maximum quality to minimize compression artifacts)
jpeg_buf = io.BytesIO()
img.save(jpeg_buf, format="JPEG", quality=100, subsampling=0)
jpeg_bytes = jpeg_buf.getvalue()

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# DefineBitsJPEG2 tag (object_id=1) with self-contained JPEG
swf.define_bits_jpeg2(object_id=1, jpeg_data_bytes=jpeg_bytes)

# Rectangle shape filled with the JPEG bitmap
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
