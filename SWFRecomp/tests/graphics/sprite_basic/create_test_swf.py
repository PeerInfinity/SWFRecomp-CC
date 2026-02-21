#!/usr/bin/env python3
"""Generate test.swf for sprite_basic graphics test.

Tests DefineSprite (tag 39): a simple movie clip containing a red square.
The shape is defined in the main timeline, wrapped in a DefineSprite,
and the sprite is placed on the display list.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

# Create the SWF (version 5 supports DefineSprite properly)
swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# Define a red square shape (object ID 1)
# Bounds: 100x100 pixels = 2000x2000 twips, starting at origin
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape.add_fill(SolidFill(255, 0, 0))       # fill 1: red
shape.add_line_style(LineStyle(20, 0, 0, 0))  # line 1: 1px black outline

shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),     # right
    LineTo(0, 2000),     # down
    LineTo(-2000, 0),    # left
    LineTo(0, -2000),    # up (close)
])

# Define a sprite (object ID 2) that contains the red square
sprite = swf.define_sprite(object_id=2, frame_count=1)
sprite.place_object(object_id=1, depth=1)
sprite.show_frame()

# Place the sprite on the main timeline at position (100, 100) pixels
swf.place_object(object_id=2, depth=1, trans_x=2000, trans_y=2000)
swf.show_frame()
swf.save("test.swf")
