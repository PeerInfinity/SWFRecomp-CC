#!/usr/bin/env python3
"""Generate test.swf for thiccie graphics test.

Lines-only shape with three different line widths (thin, medium, thick).
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

shape = swf.define_shape(object_id=1, bounds=(2400, 6740, 3940, 6819))
shape.add_line_style(LineStyle(20, 0, 0, 0))    # 1: thin
shape.add_line_style(LineStyle(80, 0, 0, 0))    # 2: medium
shape.add_line_style(LineStyle(160, 0, 0, 0))   # 3: thick

shape.add_edges([
    ShapeSetup(x=2480, y=6739, lineStyle=3),
    LineTo(1160, -2719),
    LineTo(3020, 2339),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
