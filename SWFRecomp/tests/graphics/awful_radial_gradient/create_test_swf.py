#!/usr/bin/env python3
"""Generate test.swf for awful_radial_gradient graphics test.

Shapes with 2 linear gradients and 2 radial gradients.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, LinearGradientFill, RadialGradientFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

RED_TO_BLACK = [(0, 255, 0, 0), (255, 0, 0, 0)]

shape = swf.define_shape(object_id=1, bounds=(1708, 9293, 2132, 5887))

# Fill 1: linear gradient
shape.add_fill(LinearGradientFill(
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.08087158203125000, "skewY": -0.23086547851562500, "transX": 5501, "transY": 3432},
    RED_TO_BLACK
))
# Fill 2: linear gradient
shape.add_fill(LinearGradientFill(
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07846069335937500, "skewY": -0.15188598632812500, "transX": 4207, "transY": 2307},
    RED_TO_BLACK
))
# Fill 3: radial gradient
shape.add_fill(RadialGradientFill(
    {"scaleX": 0.25134277343750000, "scaleY": 0.25134277343750000, "transX": 5254, "transY": 4759},
    RED_TO_BLACK
))
# Fill 4: radial gradient
shape.add_fill(RadialGradientFill(
    {"scaleX": 0.17584228515625000, "scaleY": 0.17584228515625000, "transX": 3814, "transY": 3219},
    RED_TO_BLACK
))

shape.add_line_style(LineStyle(20, 0, 0, 0))

shape.add_edges([
    ShapeSetup(x=6695, y=3227, fillStyle1=3, lineStyle=1),
    LineTo(2588, 682),
    LineTo(-6358, 1968),
    LineTo(-1207, -1164),
    ShapeSetup(fillStyle1=4),
    LineTo(254, -1565),
    LineTo(3953, -1006),
    LineTo(770, 1085),
    ShapeSetup(fillStyle0=3),
    LineTo(-4977, 1486),
])

swf.place_object(object_id=1, depth=1)
swf.show_frame()
swf.save("test.swf")
