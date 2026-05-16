#!/usr/bin/env python3
"""Generate test.swf for lossless_bitmap_rgb15 graphics test.

Tests DefineBitsLossless (tag 20) with format 4 = Rgb15 (15-bit RGB555,
big-endian u16 per pixel: 1 pad + 5R + 5G + 5B). Uses an odd-width
bitmap (7x7) to exercise the row padding to 4-byte boundaries that
caught us during implementation.

Regression for the format-4 decoder added in commit 813c50b8
(per SWFRecompDocs/plans/define-bits-lossless-format-3-4.md). Format 4
is invalid in DefineBitsLossless2 per spec.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

# Odd width forces row padding (7 pixels * 2 bytes = 14, padded to 16).
W, H = 7, 7
# Diagonal gradient: per-pixel colors that round-trip cleanly through
# the 5→8 bit (c >> 3 then (c5*255+15)/31) channel scaling. Use values
# that are already multiples of 8 in their decoded form so the
# round-trip is exact and we can assert it visually if needed.
pixels = []
for y in range(H):
    for x in range(W):
        # Exact-roundtrip values: c >> 3 << 3 doesn't perfectly invert,
        # so just use varied colors and let the decoder do its thing.
        r = ((x * 36) & 0xFF)
        g = ((y * 36) & 0xFF)
        b = (((x + y) * 18) & 0xFF)
        pixels.append((r, g, b))

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

swf.define_bits_lossless_format4(
    object_id=1, width=W, height=H, pixels=pixels,
)

DISPLAY_W, DISPLAY_H = 210, 210
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
