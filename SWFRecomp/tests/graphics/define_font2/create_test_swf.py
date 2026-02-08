#!/usr/bin/env python3
"""Generate test.swf for define_font2 graphics test.

Tests DefineFont2 (tag 48) and DefineText (tag 11) rendering.
Defines a font with 3 geometric glyphs (triangle, square, diamond)
using DefineFont2 and renders a sequence of them as static text.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
    TextRecord,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=6)
swf.set_background(255, 255, 255)

# ---- Define Font2 (object ID 1) with 3 geometric glyphs ----
font = swf.define_font2(object_id=1, font_name="TestFont")

# Glyph 0: Triangle (pointing up)
font.add_glyph([
    ShapeSetup(x=0, y=1024, fillStyle1=1),
    LineTo(512, -1024),
    LineTo(512, 1024),
    LineTo(-1024, 0),
])

# Glyph 1: Square
font.add_glyph([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(1024, 0),
    LineTo(0, 1024),
    LineTo(-1024, 0),
    LineTo(0, -1024),
])

# Glyph 2: Diamond
font.add_glyph([
    ShapeSetup(x=0, y=512, fillStyle1=1),
    LineTo(512, -512),
    LineTo(512, 512),
    LineTo(-512, 512),
    LineTo(-512, -512),
])

# ---- Define Text (object ID 2) ----
text = swf.define_text(
    object_id=2,
    bounds=(0, 7000, 0, 1600),
    transform={"transX": 0, "transY": 0},
)

text.add_record(TextRecord(
    font_id=1,
    color=(0, 0, 0),
    x_offset=0,
    y_offset=1200,
    text_height=1200,
    glyphs=[
        (0, 1400),  # triangle
        (1, 1400),  # square
        (2, 1400),  # diamond
        (0, 1400),  # triangle
        (1, 1400),  # square
    ],
))

swf.place_object(object_id=2, depth=1, trans_x=1000, trans_y=4000)
swf.show_frame()
swf.save("test.swf")
