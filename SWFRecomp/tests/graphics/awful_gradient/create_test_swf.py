#!/usr/bin/env python3
"""Generate test.swf for awful_gradient graphics test.

Multiple overlapping shapes with 11 linear gradient fills.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, LinearGradientFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)

RED_TO_BLACK = [(0, 255, 0, 0), (255, 0, 0, 0)]

shape = swf.define_shape(object_id=1, bounds=(1708, 9293, 1012, 4767))

# 11 linear gradient fills with various matrices
gradient_matrices = [
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 5500, "transY": 4009},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 7900, "transY": 4009},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 6670, "transY": 2219},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 4290, "transY": 2200},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 6668, "transY": 2889},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 4332, "transY": 2890},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 5500, "transY": 2889},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.10711669921875000, "skewY": -0.10711669921875000, "transX": 5500, "transY": 2889},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07324218750000000, "skewY": -0.07324218750000000, "transX": 4945, "transY": 2334},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.08087158203125000, "skewY": -0.23086547851562500, "transX": 5501, "transY": 3432},
    {"scaleX": 0.0, "scaleY": 0.0, "skewX": 0.07846069335937500, "skewY": -0.15188598632812500, "transX": 4207, "transY": 2307},
]
for mat in gradient_matrices:
    shape.add_fill(LinearGradientFill(mat, RED_TO_BLACK))

shape.add_line_style(LineStyle(20, 0, 0, 0))

shape.add_edges([
    ShapeSetup(x=6695, y=2107, fillStyle1=10, lineStyle=1),
    LineTo(2588, 682),
    LineTo(-6358, 1968),
    LineTo(-1207, -1164),
    ShapeSetup(fillStyle1=11),
    LineTo(254, -1565),
    LineTo(3953, -1006),
    LineTo(770, 1085),
    ShapeSetup(fillStyle0=10),
    LineTo(-4977, 1486),
])

swf.place_object(object_id=1, depth=1, trans_y=1800)
swf.show_frame()
swf.save("test.swf")
