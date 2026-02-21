#!/usr/bin/env python3
"""Generate test.swf for GlowFilter graphics test.

A white rectangle on dark background with a red glow effect.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(30, 30, 30)  # Dark background

# White rectangle 100x80 px = 2000x1600 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 1600), shape_version=3)
shape.add_fill(SolidFill(255, 255, 255, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 1600),
    LineTo(-2000, 0),
    LineTo(0, -1600),
])

# Place with GlowFilter at (175, 120)px = (3500, 2400) twips
po3_body = build_place_object3(
    object_id=1, depth=1, trans_x=3500, trans_y=2400,
    filter_data={
        'type': 'glow',
        'color': (255, 40, 40, 255),   # Red glow
        'blur_x': 20.0,
        'blur_y': 20.0,
        'strength': 2.0,
        'quality': 1,
    }
)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
