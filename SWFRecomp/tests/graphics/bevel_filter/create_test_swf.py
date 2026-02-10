#!/usr/bin/env python3
"""Generate test.swf for BevelFilter graphics test.

Two green rectangles side by side:
  - Left: unfiltered reference
  - Right: BevelFilter with black shadow and white highlight
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(200, 200, 200)

# Green rectangle 120x120 px = 2400x2400 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2400, 0, 2400), shape_version=3)
shape.add_fill(SolidFill(60, 160, 60, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2400, 0),
    LineTo(0, 2400),
    LineTo(-2400, 0),
    LineTo(0, -2400),
])

# Left: unfiltered reference at (40, 100)px = (800, 2000) twips
swf.place_object(object_id=1, depth=1, trans_x=800, trans_y=2000)

# Right: beveled at (300, 100)px = (6000, 2000) twips via PlaceObject3
po3_body = build_place_object3(
    object_id=1, depth=2, trans_x=6000, trans_y=2000,
    filter_data={
        'type': 'bevel',
        'shadow_color': (0, 0, 0, 255),
        'highlight_color': (255, 255, 255, 255),
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
