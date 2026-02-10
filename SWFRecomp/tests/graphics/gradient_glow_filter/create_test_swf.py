#!/usr/bin/env python3
"""Generate test.swf for GradientGlowFilter graphics test.

Two cyan rectangles side by side:
  - Left: unfiltered reference
  - Right: GradientGlowFilter with red-to-yellow gradient
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(30, 30, 30)

# Cyan rectangle 100x100 px = 2000x2000 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000), shape_version=3)
shape.add_fill(SolidFill(0, 200, 200, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Left: unfiltered reference
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=2000)

# Right: gradient glow via PlaceObject3
po3_body = build_place_object3(
    object_id=1, depth=2, trans_x=6000, trans_y=2000,
    filter_data={
        'type': 'gradient_glow',
        'colors': [(255, 0, 0, 0), (255, 128, 0, 128), (255, 255, 0, 255)],
        'ratios': [0, 128, 255],
        'blur_x': 20.0,
        'blur_y': 20.0,
        'angle': 0.0,
        'distance': 0.0,
        'strength': 2.0,
        'quality': 1,
    }
)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
