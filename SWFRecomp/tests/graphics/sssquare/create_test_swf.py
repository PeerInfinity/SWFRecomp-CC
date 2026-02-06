#!/usr/bin/env python3
"""Generate test.swf for sssquare graphics test.

Small stroked square with solid orange fill, separate edge segments.
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
swf.add_trace("sssquare")

shape = swf.define_shape(object_id=1, bounds=(0, 300, 0, 300))
shape.add_fill(SolidFill(255, 95, 0))

shape.add_edges([
    ShapeSetup(x=100, y=200, fillStyle1=1),
    LineTo(0, -100),
    ShapeSetup(x=200, y=200, fillStyle0=1, fillStyle1=0),
    LineTo(0, -100),
    ShapeSetup(x=200, y=200, fillStyle0=0, fillStyle1=1),
    LineTo(-100, 0),
    ShapeSetup(x=200, y=100, fillStyle0=1, fillStyle1=0),
    LineTo(-100, 0),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
