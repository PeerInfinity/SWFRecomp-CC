#!/usr/bin/env python3
"""Generate test.swf for three_boxes graphics test.

Three colored box shapes (red, blue, green) with black outlines.
Includes a DoAction trace.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)
swf.add_trace("three_boxes")

shape = swf.define_shape(object_id=1, bounds=(2630, 8370, 910, 7109))
shape.add_fill(SolidFill(255, 0, 0))    # 1: red
shape.add_fill(SolidFill(0, 0, 255))    # 2: blue
shape.add_fill(SolidFill(0, 255, 0))    # 3: green
shape.add_line_style(LineStyle(20, 0, 0, 0))

shape.add_edges([
    ShapeSetup(x=6540, y=2900, fillStyle1=2, lineStyle=1),
    LineTo(1820, 0),
    LineTo(0, 4199),
    LineTo(-3700, 0),
    LineTo(40, -1959),
    ShapeSetup(fillStyle1=1),
    LineTo(-2060, 0),
    LineTo(0, -4220),
    LineTo(3900, 0),
    LineTo(0, 1980),
    ShapeSetup(fillStyle0=2, fillStyle1=3),
    LineTo(-20, 2240),
    LineTo(-1820, 0),
    ShapeSetup(fillStyle0=1),
    LineTo(0, -2200),
    LineTo(1840, -40),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
