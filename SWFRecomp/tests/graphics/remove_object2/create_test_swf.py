#!/usr/bin/env python3
"""Generate test.swf for remove_object2 graphics test.

Tests RemoveObject2 (tag 28): places three colored squares side by side,
renders a frame showing all three, then removes the middle square and
renders a second frame showing only the left and right squares.

Frame 1: Red (depth 1) | Green (depth 2) | Blue (depth 3)
Frame 2: Red (depth 1) |                 | Blue (depth 3)
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, LineTo,
)

# Stage: 550x400 pixels
swf = SWFMLBuilder(width=550, height=400, fps=1, version=5)
swf.set_background(255, 255, 255)

# Define a red square (100x100 px = 2000x2000 twips), object ID 1
red = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
red.add_fill(SolidFill(255, 0, 0))
red.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a green square, object ID 2
green = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 2000))
green.add_fill(SolidFill(0, 255, 0))
green.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a blue square, object ID 3
blue = swf.define_shape(object_id=3, bounds=(0, 2000, 0, 2000))
blue.add_fill(SolidFill(0, 0, 255))
blue.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Place all three side by side:
# Red at (50, 150) px = (1000, 3000) twips, depth 1
# Green at (200, 150) px = (4000, 3000) twips, depth 2
# Blue at (350, 150) px = (7000, 3000) twips, depth 3
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=3000)
swf.place_object(object_id=2, depth=2, trans_x=4000, trans_y=3000)
swf.place_object(object_id=3, depth=3, trans_x=7000, trans_y=3000)

# Frame 1: all three squares visible
swf.show_frame()

# Remove the middle (green) square at depth 2
swf.remove_object(depth=2)

# Frame 2: only red and blue visible
swf.show_frame()

swf.save("test.swf")
