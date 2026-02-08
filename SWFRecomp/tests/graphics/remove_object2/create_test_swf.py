#!/usr/bin/env python3
"""Generate test.swf for remove_object2 graphics test.

Tests RemoveObject2 (tag 28): places 3 colored squares on the display list,
renders frame 1 with all 3 visible, then removes the middle square (depth 2)
and renders frame 2. The final output should show only the red and blue squares.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, LineTo,
)

# Create the SWF (version 5 for multi-frame support)
swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# Define a red square (object ID 1) - 100x100 pixels = 2000x2000 twips
shape1 = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape1.add_fill(SolidFill(255, 0, 0))  # fill 1: red
shape1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a green square (object ID 2) - 100x100 pixels = 2000x2000 twips
shape2 = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 2000))
shape2.add_fill(SolidFill(0, 255, 0))  # fill 1: green
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a blue square (object ID 3) - 100x100 pixels = 2000x2000 twips
shape3 = swf.define_shape(object_id=3, bounds=(0, 2000, 0, 2000))
shape3.add_fill(SolidFill(0, 0, 255))  # fill 1: blue
shape3.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Place all 3 squares at different positions and depths
# Red at (50, 150) pixels = (1000, 3000) twips, depth 1
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=3000)
# Green at (225, 150) pixels = (4500, 3000) twips, depth 2
swf.place_object(object_id=2, depth=2, trans_x=4500, trans_y=3000)
# Blue at (400, 150) pixels = (8000, 3000) twips, depth 3
swf.place_object(object_id=3, depth=3, trans_x=8000, trans_y=3000)

# Frame 1: all 3 squares visible
swf.show_frame()

# Remove the green square (depth 2)
swf.remove_object(depth=2)

# Frame 2: only red and blue visible
swf.show_frame()

swf.save("test.swf")
