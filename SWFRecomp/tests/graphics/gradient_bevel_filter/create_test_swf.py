#!/usr/bin/env python3
"""Generate test.swf for GradientBevelFilter graphics test.

Two orange rectangles side by side:
  - Left: unfiltered reference
  - Right: GradientBevelFilter with dark-to-light gradient bevel
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(180, 180, 180)

# Orange rectangle 120x120 px = 2400x2400 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2400, 0, 2400), shape_version=3)
shape.add_fill(SolidFill(220, 140, 40, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2400, 0),
    LineTo(0, 2400),
    LineTo(-2400, 0),
    LineTo(0, -2400),
])

# Left: unfiltered reference
swf.place_object(object_id=1, depth=1, trans_x=800, trans_y=2000)

# Right: gradient bevel via PlaceObject3
po3_body = build_place_object3(
    object_id=1, depth=2, trans_x=6000, trans_y=2000,
    filter_data={
        'type': 'gradient_bevel',
        'colors': [(40, 20, 0, 255), (255, 240, 200, 255)],
        'ratios': [0, 255],
        'blur_x': 10.0,
        'blur_y': 10.0,
        'angle': 45.0,
        'distance': 4.0,
        'strength': 1.0,
        'quality': 1,
    }
)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
