#!/usr/bin/env python3
"""Generate test.swf for define_button2 graphics test.

A DefineButton2 (tag 34) exercising per-record CXFORMWITHALPHA and transforms:
  - Up:   white rectangle tinted blue via cxform (mult_r=0, mult_g=80/256, mult_b=200/256)
  - Over: same white rectangle tinted green via cxform (mult_r=0, mult_b=0, add_g=200)
  - Down: same white rectangle tinted red via cxform + shifted 4px right/down
  - Hit:  same white rectangle (identity cxform, not rendered)

Also has BUTTONCONDACTION trace actions for release and hover transitions.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# Shape 1: white rectangle — 100x80 pixels = 2000x1600 twips
# All states reuse this shape with different color transforms
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 1600))
shape.add_fill(SolidFill(255, 255, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 1600),
    LineTo(-2000, 0),
    LineTo(0, -1600),
])

# Button2 (object_id=2): single shape, per-record CXFORMWITHALPHA + transform
button = swf.define_button2(object_id=2)

# Up: tint to blue — multiply (30/256, 80/256, 200/256, 256/256)
button.add_record(char_id=1, depth=1, up=True,
                  mult_r=30, mult_g=80, mult_b=200)

# Over: tint to green — multiply (0, 256, 0, 256) + additive (0, 40, 0, 0)
button.add_record(char_id=1, depth=1, over=True,
                  mult_r=0, mult_g=256, mult_b=0, add_g=40)

# Down: tint to red + shift 4px right and 4px down (80 twips each)
button.add_record(char_id=1, depth=1, down=True,
                  mult_r=256, mult_g=30, mult_b=30,
                  trans_x=80, trans_y=80)

# Hit: identity cxform (white rectangle, not rendered)
button.add_record(char_id=1, depth=2, hit_test=True)

button.add_trace_action("Button2 clicked!", condition=0x0008)   # OverDownToOverUp (release)
button.add_trace_action("Button2 hover!", condition=0x0001)     # IdleToOverUp (mouse enter)

# Place button at (100, 80) pixels = (2000, 1600) twips
swf.place_object(object_id=2, depth=1, trans_x=2000, trans_y=1600)
swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
