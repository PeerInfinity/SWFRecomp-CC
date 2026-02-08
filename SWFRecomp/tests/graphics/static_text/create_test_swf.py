#!/usr/bin/env python3
"""Generate test.swf for static_text graphics test.

Tests DefineFont (tag 10) and DefineText (tag 11): defines a font with
three geometric glyphs (triangle, square, diamond) and renders them as
static text using DefineText.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo, CurveTo,
)

# Create the SWF
swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# Glyph coordinate system: em-square is 1024x1024 units.
# text_height in DefineText scales glyphs from the em-square to display size.
# We define glyphs in this coordinate space.

# Glyph 0: Triangle (upward-pointing)
glyph_triangle = [
    ShapeSetup(x=0, y=1024, fillStyle1=1),
    LineTo(512, -1024),
    LineTo(512, 1024),
    LineTo(-1024, 0),
]

# Glyph 1: Square
glyph_square = [
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(1024, 0),
    LineTo(0, 1024),
    LineTo(-1024, 0),
    LineTo(0, -1024),
]

# Glyph 2: Diamond (rotated square)
glyph_diamond = [
    ShapeSetup(x=512, y=0, fillStyle1=1),
    LineTo(512, 512),
    LineTo(-512, 512),
    LineTo(-512, -512),
    LineTo(512, -512),
]

# Define font (object ID 1) with 3 glyphs
swf.define_font(object_id=1, glyphs=[
    glyph_triangle,
    glyph_square,
    glyph_diamond,
])

# Define text (object ID 2) rendering all 3 glyphs in a row
# text_height=1200 twips = 60 pixels (the em-square maps to this height)
# advance=1400 twips between glyphs (70 pixels)
swf.define_text(
    object_id=2,
    bounds=(0, 8000, 0, 2400),
    font_id=1,
    text_height=1200,
    color=(200, 50, 50),
    glyphs=[
        (0, 1400),  # triangle, advance 70px
        (1, 1400),  # square, advance 70px
        (2, 1400),  # diamond, advance 70px
    ],
    matrix_trans_x=1000,
    matrix_trans_y=2000,
)

# Place the text object on the display list
swf.place_object(object_id=2, depth=1)
swf.show_frame()
swf.save("test.swf")
