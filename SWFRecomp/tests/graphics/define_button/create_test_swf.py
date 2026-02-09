#!/usr/bin/env python3
"""Generate test.swf for define_button graphics test.

A DefineButton (tag 7) with a green rectangle as the "up" state and a gray
rectangle as the hit-test area.  Only the up-state shape should be rendered.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# Shape 1: green rectangle (100x80 twips = 5x4 pixels at 20 twips/px)
# Actually let's make it bigger: 2000x1600 twips = 100x80 pixels
shape_up = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 1600))
shape_up.add_fill(SolidFill(0, 180, 0))
shape_up.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 1600),
    LineTo(-2000, 0),
    LineTo(0, -1600),
])

# Shape 2: gray rectangle for hit-test area (same size)
shape_hit = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 1600))
shape_hit.add_fill(SolidFill(128, 128, 128))
shape_hit.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 1600),
    LineTo(-2000, 0),
    LineTo(0, -1600),
])

# Button (object_id=3): green rect for up state, gray rect for hit-test
button = swf.define_button(object_id=3)
button.add_record(char_id=1, depth=1, up=True)
button.add_record(char_id=2, depth=2, hit_test=True)

# Place button at (100, 80) pixels = (2000, 1600) twips
swf.place_object(object_id=3, depth=1, trans_x=2000, trans_y=1600)
swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
