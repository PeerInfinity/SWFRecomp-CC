#!/usr/bin/env python3
"""Generate test.swf for new_styles graphics test.

DefineShape2 with StateNewStyles: two squares with different fill/line
styles defined in separate style lists within the same shape.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

shape = swf.define_shape(object_id=1, bounds=(2126, 8874, 1195, 6824),
                         shape_version=2)
shape.add_fill(SolidFill(255, 0, 0))             # 1: red
shape.add_line_style(LineStyle(20, 0, 0, 0))     # 1: thin black

# First square with initial styles
shape.add_edges([
    ShapeSetup(x=8864, y=6814, fillStyle1=1, lineStyle=1),
    LineTo(-2849, 0),
    LineTo(0, -2849),
    LineTo(2849, 0),
    LineTo(0, 2849),
])

# Style change with new style list (DefineShape2 StateNewStyles)
shape.add_edge(ShapeSetup(
    x=0, y=0,
    fillStyle0=0, fillStyle1=0, lineStyle=0,
    new_styles=(
        [SolidFill(255, 105, 0)],   # new fill 1: orange
        [LineStyle(20, 0, 0, 0)],   # new line 1: thin black
    )
))

# Second square with new styles
shape.add_edges([
    ShapeSetup(x=5785, y=4854, fillStyle1=1, lineStyle=1),
    LineTo(-3649, 0),
    LineTo(0, -3649),
    LineTo(3649, 0),
    LineTo(0, 3649),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
