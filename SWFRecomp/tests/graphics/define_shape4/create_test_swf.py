#!/usr/bin/env python3
"""Generate test.swf for define_shape4 graphics test.

Three rectangles using DefineShape4 (tag 83) with LINESTYLE2 (advanced line styles).
Tests basic DefineShape4 parsing with different cap and join styles:
  - Red rectangle with thick black round-cap round-join lines
  - Green rectangle with thick blue square-cap miter-join lines
  - Blue rectangle with thick red bevel-join lines
"""
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle2,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# --- Shape 1: Red filled rectangle with thick black round-cap round-join lines ---
shape1 = swf.define_shape(object_id=1,
    bounds=(-100, 3100, -100, 3100), shape_version=4)
fill1 = shape1.add_fill(SolidFill(220, 50, 50, 255))
line1 = shape1.add_line_style(LineStyle2(
    width=100, r=0, g=0, b=0, a=255,
    start_cap=0, end_cap=0, join_style=0))  # round caps, round join
shape1.add_edges([
    ShapeSetup(x=200, y=200, fillStyle1=fill1, lineStyle=line1),
    LineTo(2600, 0),
    LineTo(0, 2600),
    LineTo(-2600, 0),
    LineTo(0, -2600),
])

# --- Shape 2: Green filled rectangle with thick blue square-cap miter-join lines ---
shape2 = swf.define_shape(object_id=2,
    bounds=(-100, 3100, -100, 3100), shape_version=4)
fill2 = shape2.add_fill(SolidFill(50, 180, 50, 255))
line2 = shape2.add_line_style(LineStyle2(
    width=100, r=0, g=0, b=200, a=255,
    start_cap=2, end_cap=2, join_style=2,  # square caps, miter join
    miter_limit=2.0))
shape2.add_edges([
    ShapeSetup(x=200, y=200, fillStyle1=fill2, lineStyle=line2),
    LineTo(2600, 0),
    LineTo(0, 2600),
    LineTo(-2600, 0),
    LineTo(0, -2600),
])

# --- Shape 3: Blue filled rectangle with thick red bevel-join lines ---
shape3 = swf.define_shape(object_id=3,
    bounds=(-100, 3100, -100, 3100), shape_version=4)
fill3 = shape3.add_fill(SolidFill(50, 80, 220, 255))
line3 = shape3.add_line_style(LineStyle2(
    width=100, r=200, g=0, b=0, a=255,
    start_cap=0, end_cap=0, join_style=1))  # round caps, bevel join
shape3.add_edges([
    ShapeSetup(x=200, y=200, fillStyle1=fill3, lineStyle=line3),
    LineTo(2600, 0),
    LineTo(0, 2600),
    LineTo(-2600, 0),
    LineTo(0, -2600),
])

# Place shapes side by side
swf.place_object(object_id=1, depth=1, trans_x=500, trans_y=1500)
swf.place_object(object_id=2, depth=2, trans_x=3800, trans_y=1500)
swf.place_object(object_id=3, depth=3, trans_x=7200, trans_y=1500)
swf.show_frame()
swf.save("test.swf")
