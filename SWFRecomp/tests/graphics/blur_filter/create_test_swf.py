#!/usr/bin/env python3
"""Generate test.swf for BlurFilter graphics test.

Two blue rectangles side by side:
  - Left: unfiltered reference
  - Right: BlurFilter(blur_x=20, blur_y=20, quality=1)
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo, build_place_object3,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# Blue rectangle 100x100 px = 2000x2000 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000), shape_version=3)
shape.add_fill(SolidFill(40, 80, 200, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Left: unfiltered reference at (50, 100)px = (1000, 2000) twips
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=2000)

# Right: blurred at (300, 100)px = (6000, 2000) twips via PlaceObject3
po3_body = build_place_object3(
    object_id=1, depth=2, trans_x=6000, trans_y=2000,
    filter_data={'type': 'blur', 'blur_x': 20.0, 'blur_y': 20.0, 'quality': 1}
)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
