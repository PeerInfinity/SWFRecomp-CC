#!/usr/bin/env python3
"""Generate test.swf for three_boxes_holes graphics test.

Three colored boxes with multiple cutout holes. Two DefineShape tags.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

# Shape 1: Three boxes with holes
shape1 = swf.define_shape(object_id=1, bounds=(2630, 8370, 910, 7109))
shape1.add_fill(SolidFill(255, 0, 0))      # 1: red
shape1.add_fill(SolidFill(0, 0, 255))      # 2: blue
shape1.add_fill(SolidFill(0, 255, 0))      # 3: green
shape1.add_fill(SolidFill(255, 110, 0))    # 4: orange
shape1.add_fill(SolidFill(255, 255, 0))    # 5: yellow
shape1.add_line_style(LineStyle(20, 0, 0, 0))

shape1.add_edges([
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
    ShapeSetup(x=5400, y=3800, fillStyle0=5, fillStyle1=4),
    LineTo(0, 250),
    LineTo(250, 0),
    ShapeSetup(fillStyle1=5),
    LineTo(0, -250),
    ShapeSetup(fillStyle1=4),
    LineTo(-250, 0),
    ShapeSetup(x=5650, y=3800, fillStyle0=4, fillStyle1=5),
    LineTo(250, 0),
    LineTo(0, 250),
    LineTo(-250, 0),
    ShapeSetup(x=6030, y=3540, fillStyle0=3, fillStyle1=4),
    LineTo(0, 790),
    LineTo(-790, 0),
    LineTo(0, -790),
    LineTo(790, 0),
])

# Shape 2: Small separate shape
shape2 = swf.define_shape(object_id=2, bounds=(0, 600, 0, 600))
shape2.add_fill(SolidFill(255, 0, 0))    # 1: red
shape2.add_fill(SolidFill(0, 255, 0))    # 2: green

shape2.add_edges([
    ShapeSetup(x=100, y=100, fillStyle0=1),
    LineTo(0, 250),
    LineTo(250, 0),
    ShapeSetup(fillStyle1=2),
    LineTo(0, -250),
    ShapeSetup(fillStyle1=0),
    LineTo(-250, 0),
    ShapeSetup(x=350, y=100, fillStyle0=0, fillStyle1=2),
    LineTo(250, 0),
    LineTo(0, 250),
    LineTo(-250, 0),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
