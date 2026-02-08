#!/usr/bin/env python3
"""Generate test.swf for static_text graphics test.

Tests DefineFont (tag 10) and DefineText (tag 11) rendering.
Defines a font with 3 geometric glyphs (triangle, square, diamond)
and renders a sequence of them as static text.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
    FontDefinition, TextDefinition, TextRecord,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# ---- Define Font (object ID 1) with 3 geometric glyphs ----
# Glyph coordinates are in the font's EM square coordinate system.
# SWF fonts typically use a 1024-unit EM square.
# fillStyle1=1 (right fill) with CW winding in SWF's Y-down coords.
# CW in Y-down means the filled interior is to the RIGHT of each edge.

font = swf.define_font(object_id=1)

# Glyph 0: Triangle (pointing up)
#   CW in Y-down: (0,1024) -> (512,0) -> (1024,1024) -> (0,1024)
#   Interior (the triangle) is to the right of each edge.
font.add_glyph([
    ShapeSetup(x=0, y=1024, fillStyle1=1),
    LineTo(512, -1024),   # left edge: up-right to apex
    LineTo(512, 1024),    # right edge: down-right to bottom-right
    LineTo(-1024, 0),     # bottom edge: left back to start
])

# Glyph 1: Square
#   CW in Y-down: (0,0) -> (1024,0) -> (1024,1024) -> (0,1024) -> (0,0)
font.add_glyph([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(1024, 0),    # top edge: right
    LineTo(0, 1024),    # right edge: down
    LineTo(-1024, 0),   # bottom edge: left
    LineTo(0, -1024),   # left edge: up
])

# Glyph 2: Diamond
#   CW in Y-down: (0,512) -> (512,0) -> (1024,512) -> (512,1024) -> (0,512)
font.add_glyph([
    ShapeSetup(x=0, y=512, fillStyle1=1),
    LineTo(512, -512),   # left to top: up-right
    LineTo(512, 512),    # top to right: down-right
    LineTo(-512, 512),   # right to bottom: down-left
    LineTo(-512, -512),  # bottom to left: up-left
])

# ---- Define Text (object ID 2) ----
# Render glyphs [0, 1, 2, 0, 1] (triangle, square, diamond, triangle, square)
# at 1200 twips height (60 pixels), black color, positioned at (50, 200) pixels.

# Text bounds (conservative): covers the full rendering area
# 5 glyphs at ~60px each = ~300px wide, ~60px tall
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
        (0, 1400),  # triangle, advance 1400 twips
        (1, 1400),  # square
        (2, 1400),  # diamond
        (0, 1400),  # triangle
        (1, 1400),  # square
    ],
))

# Place text at (1000, 4000) twips = (50, 200) pixels
swf.place_object(object_id=2, depth=1, trans_x=1000, trans_y=4000)
swf.show_frame()
swf.save("test.swf")
