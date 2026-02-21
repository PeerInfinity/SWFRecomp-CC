#!/usr/bin/env python3
"""Generate test.swf for DropShadowFilter graphics test.

A green rectangle with a black drop shadow (45 degrees, 10px distance, blur 10).
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(220, 220, 220)

# Green rectangle 120x80 px = 2400x1600 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2400, 0, 1600), shape_version=3)
shape.add_fill(SolidFill(40, 180, 60, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2400, 0),
    LineTo(0, 1600),
    LineTo(-2400, 0),
    LineTo(0, -1600),
])

# Place with DropShadow filter at (150, 120)px = (3000, 2400) twips
po3_body = build_place_object3(
    object_id=1, depth=1, trans_x=3000, trans_y=2400,
    filter_data={
        'type': 'drop_shadow',
        'color': (0, 0, 0, 180),     # Semi-transparent black
        'blur_x': 10.0,
        'blur_y': 10.0,
        'angle': 45.0,               # 45 degrees
        'distance': 10.0,            # 10 pixels
        'strength': 1.0,
        'quality': 1,
    }
)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
