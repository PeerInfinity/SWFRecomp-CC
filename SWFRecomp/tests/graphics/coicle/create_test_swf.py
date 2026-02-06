#!/usr/bin/env python3
"""Generate test.swf for coicle graphics test.

Circle approximated with 8 quadratic bezier curves, solid red fill.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, CurveTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

shape = swf.define_shape(object_id=1, bounds=(2875, 8125, 1384, 6634))
shape.add_fill(SolidFill(255, 0, 0))

shape.add_edges([
    ShapeSetup(x=5500, y=1384, fillStyle1=1),
    CurveTo(1087, 0, 769, 769),
    CurveTo(769, 769, 0, 1087),
    CurveTo(0, 1087, -769, 769),
    CurveTo(-769, 769, -1087, 0),
    CurveTo(-1087, 0, -769, -769),
    CurveTo(-769, -769, 0, -1087),
    CurveTo(0, -1087, 769, -769),
    CurveTo(769, -769, 1087, 0),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
