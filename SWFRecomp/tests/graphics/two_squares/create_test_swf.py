#!/usr/bin/env python3
"""Generate test.swf for two_squares graphics test.

Two filled square shapes: one red, one green, with a thin black outline.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

shape = swf.define_shape(object_id=1, bounds=(941, 10060, 1729, 6289))
shape.add_fill(SolidFill(255, 0, 0))    # fill 1: red
shape.add_fill(SolidFill(0, 255, 0))    # fill 2: green
shape.add_line_style(LineStyle(1, 0, 0, 0))  # line 1: thin black

shape.add_edges([
    ShapeSetup(x=10060, y=6289, fillStyle1=1, lineStyle=1),
    LineTo(-4560, 0),
    LineTo(0, -1),
    LineTo(-4559, 0),
    LineTo(0, -4559),
    LineTo(4559, 0),
    LineTo(4560, 0),
    LineTo(0, 4560),
    ShapeSetup(x=5500, y=1729, fillStyle0=1),
    LineTo(0, 4559),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
