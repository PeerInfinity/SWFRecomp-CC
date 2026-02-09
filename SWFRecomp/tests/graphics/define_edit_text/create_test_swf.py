#!/usr/bin/env python3
"""Generate test.swf for define_edit_text graphics test.

Tests DefineEditText (tag 37) rendering via DefineFont2 code table lookup.
Defines a font with 3 geometric glyphs (triangle, square, diamond) mapped to
'A', 'B', 'C', then uses DefineEditText with InitialText="ABCAB" to render them.
The result should look identical to the define_font2 test.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=6)
swf.set_background(255, 255, 255)

# ---- Define Font2 (object ID 1) with 3 geometric glyphs ----
# Code table maps: glyph 0 → 'A' (65), glyph 1 → 'B' (66), glyph 2 → 'C' (67)
font = swf.define_font2(object_id=1, font_name="TestFont")

# Glyph 0: Triangle (pointing up) → 'A'
font.add_glyph([
    ShapeSetup(x=0, y=1024, fillStyle1=1),
    LineTo(512, -1024),
    LineTo(512, 1024),
    LineTo(-1024, 0),
])

# Glyph 1: Square → 'B'
font.add_glyph([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(1024, 0),
    LineTo(0, 1024),
    LineTo(-1024, 0),
    LineTo(0, -1024),
])

# Glyph 2: Diamond → 'C'
font.add_glyph([
    ShapeSetup(x=0, y=512, fillStyle1=1),
    LineTo(512, -512),
    LineTo(512, 512),
    LineTo(-512, 512),
    LineTo(-512, -512),
])

# ---- Define EditText (object ID 2) with InitialText="ABCAB" ----
swf.define_edit_text(
    object_id=2,
    bounds=(0, 7000, 0, 1600),
    font_id=1,
    font_height=1200,
    color=(255, 0, 0, 255),
    initial_text="ABCAB",
    read_only=True,
)

swf.place_object(object_id=2, depth=1, trans_x=1000, trans_y=4000)
swf.show_frame()
swf.save("test.swf")
