#!/usr/bin/env python3
"""Generate test.swf for awful_shape_swf_4 graphics test.

Complex irregular polygon with solid red fill.
Includes a DoAction trace.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)
swf.add_trace("awful shape")

shape = swf.define_shape(object_id=1, bounds=(311, 10690, 2789, 5229))
shape.add_fill(SolidFill(255, 0, 0))

shape.add_edges([
    ShapeSetup(x=7970, y=2849, fillStyle1=1),
    LineTo(1720, 300),
    LineTo(600, 600),
    LineTo(400, 1480),
    LineTo(-10379, -600),
    LineTo(3499, -1840),
    LineTo(1120, 560),
    LineTo(300, 1160),
    LineTo(1400, 0),
    LineTo(320, -960),
    LineTo(1020, -700),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
