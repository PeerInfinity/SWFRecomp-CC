#!/usr/bin/env python3
"""Generate test.swf for define_text2 graphics test.

Tests DefineText2 (tag 33) which extends DefineText with RGBA color support.
Defines a font with geometric glyphs and renders them with semi-transparent
colors overlapping a colored background shape to demonstrate alpha blending.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
    FontDefinition, TextDefinition, TextRecord,
)

# SWF version 7+ is needed for DefineText2 (RGBA text colors)
swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

# ---- Define a background rectangle (object ID 1) ----
# Green rectangle behind the text area to show alpha blending
bg_shape = swf.define_shape(object_id=1, bounds=(0, 8000, 0, 3000))
bg_shape.add_fill(SolidFill(50, 180, 50))
bg_shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(8000, 0),
    LineTo(0, 3000),
    LineTo(-8000, 0),
    LineTo(0, -3000),
])

# ---- Define Font (object ID 2) with 3 geometric glyphs ----
font = swf.define_font(object_id=2)

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

# ---- Define Text2 (object ID 3) with semi-transparent red ----
# RGBA color (255, 0, 0, 128) = semi-transparent red
text1 = swf.define_text2(
    object_id=3,
    bounds=(0, 7000, 0, 1600),
    transform={"transX": 0, "transY": 0},
)

text1.add_record(TextRecord(
    font_id=2,
    color=(255, 0, 0, 128),  # Semi-transparent red (RGBA)
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

# ---- Define Text2 (object ID 4) with semi-transparent blue ----
text2 = swf.define_text2(
    object_id=4,
    bounds=(0, 7000, 0, 1600),
    transform={"transX": 0, "transY": 0},
)

text2.add_record(TextRecord(
    font_id=2,
    color=(0, 0, 255, 180),  # Semi-transparent blue (RGBA)
    x_offset=0,
    y_offset=1200,
    text_height=1200,
    glyphs=[
        (2, 1400),  # diamond
        (0, 1400),  # triangle
        (1, 1400),  # square
        (2, 1400),  # diamond
        (0, 1400),  # triangle
    ],
))

# Place background at (500, 2000) twips = (25, 100) pixels
swf.place_object(object_id=1, depth=1, trans_x=500, trans_y=2000)
# Place semi-transparent red text overlapping the green background
swf.place_object(object_id=3, depth=2, trans_x=600, trans_y=2200)
# Place semi-transparent blue text offset slightly, also overlapping
swf.place_object(object_id=4, depth=3, trans_x=600, trans_y=3400)
swf.show_frame()
swf.save("test.swf")
