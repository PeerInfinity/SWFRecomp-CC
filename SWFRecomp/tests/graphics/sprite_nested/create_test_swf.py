#!/usr/bin/env python3
"""Generate test.swf for sprite_nested graphics test.

Tests that all character types render correctly inside sprites:
- Shape children (red square at depth 1)
- Text children (geometric glyphs at depth 2)
- Nested sprite children (inner sprite containing green square at depth 3)

Outer sprite (ID 6) is placed on the main timeline.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
    FontDefinition, TextDefinition, TextRecord,
)

swf = SWFMLBuilder(width=550, height=400, fps=1, version=5)
swf.set_background(255, 255, 255)

# ---- Shape ID 1: Red square (100x100 px) ----
shape1 = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape1.add_fill(SolidFill(255, 0, 0))
shape1.add_line_style(LineStyle(20, 0, 0, 0))
shape1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# ---- Shape ID 2: Green square (100x100 px) ----
shape2 = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 2000))
shape2.add_fill(SolidFill(0, 180, 0))
shape2.add_line_style(LineStyle(20, 0, 0, 0))
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# ---- Font ID 3: Simple geometric glyphs ----
font = swf.define_font(object_id=3)

# Glyph 0: Triangle
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

# ---- Text ID 4: Two glyphs (triangle + square) ----
text = swf.define_text(
    object_id=4,
    bounds=(0, 3000, 0, 1600),
    transform={"transX": 0, "transY": 0},
)
text.add_record(TextRecord(
    font_id=3,
    color=(0, 0, 255),
    x_offset=0,
    y_offset=1200,
    text_height=1200,
    glyphs=[
        (0, 1400),  # triangle
        (1, 1400),  # square
    ],
))

# ---- Inner sprite ID 5: contains green square ----
inner_sprite = swf.define_sprite(object_id=5, frame_count=1)
inner_sprite.place_object(object_id=2, depth=1)
inner_sprite.show_frame()

# ---- Outer sprite ID 6: shape + text + nested sprite ----
outer_sprite = swf.define_sprite(object_id=6, frame_count=1)
# Depth 1: red square at (0, 0)
outer_sprite.place_object(object_id=1, depth=1)
# Depth 2: blue text at (2400, 0) — to the right of the red square
outer_sprite.place_object(object_id=4, depth=2, trans_x=2400)
# Depth 3: inner sprite (green square) at (0, 2400) — below the red square
outer_sprite.place_object(object_id=5, depth=3, trans_x=0, trans_y=2400)
outer_sprite.show_frame()

# Place outer sprite on main timeline at (50, 50) px
swf.place_object(object_id=6, depth=1, trans_x=1000, trans_y=1000)
swf.show_frame()
swf.save("test.swf")
