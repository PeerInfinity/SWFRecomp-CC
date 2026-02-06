#!/usr/bin/env python3
"""Generate test.swf for rgba_shape graphics test.

Three overlapping semi-transparent rectangles using DefineShape3 (RGBA colors).
Tests alpha channel support in fill styles and line styles.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo, ShapeDefinition,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

# Shape 1: Semi-transparent red rectangle
shape1 = swf.define_shape(object_id=1,
    bounds=(0, 5000, 0, 4000), shape_version=3)
fill1 = shape1.add_fill(SolidFill(255, 0, 0, 128))
line1 = shape1.add_line_style(LineStyle(40, 0, 0, 0, 200))
shape1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=fill1, lineStyle=line1),
    LineTo(5000, 0),
    LineTo(0, 4000),
    LineTo(-5000, 0),
    LineTo(0, -4000),
])

# Shape 2: Semi-transparent green rectangle
shape2 = swf.define_shape(object_id=2,
    bounds=(0, 5000, 0, 4000), shape_version=3)
fill2 = shape2.add_fill(SolidFill(0, 200, 0, 128))
line2 = shape2.add_line_style(LineStyle(40, 0, 0, 0, 200))
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=fill2, lineStyle=line2),
    LineTo(5000, 0),
    LineTo(0, 4000),
    LineTo(-5000, 0),
    LineTo(0, -4000),
])

# Shape 3: Semi-transparent blue rectangle
shape3 = swf.define_shape(object_id=3,
    bounds=(0, 5000, 0, 4000), shape_version=3)
fill3 = shape3.add_fill(SolidFill(0, 0, 255, 128))
line3 = shape3.add_line_style(LineStyle(40, 0, 0, 0, 200))
shape3.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=fill3, lineStyle=line3),
    LineTo(5000, 0),
    LineTo(0, 4000),
    LineTo(-5000, 0),
    LineTo(0, -4000),
])

# Place shapes overlapping: offset each by 100px right and 60px down
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=1000)
swf.place_object(object_id=2, depth=2, trans_x=3000, trans_y=1000)
swf.place_object(object_id=3, depth=3, trans_x=2000, trans_y=2200)
swf.show_frame()
swf.save("test.swf")
