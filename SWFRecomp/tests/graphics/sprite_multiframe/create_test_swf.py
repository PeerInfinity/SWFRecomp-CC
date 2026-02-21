#!/usr/bin/env python3
"""Generate test.swf for sprite_multiframe graphics test.

Tests multi-frame DefineSprite (tag 39): a sprite with 3 frames that cycles:
  Frame 0: Place red square at depth 1
  Frame 1: Place green square at depth 2 (red persists)
  Frame 2: Remove red square from depth 1 (green persists)

The main timeline has 12 frames (1 second at 12fps) with the sprite placed once.
Expected visual cycle: red -> red+green -> green -> red -> red+green -> green -> ...
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=1, version=5)
swf.set_background(255, 255, 255)

# Define a red square shape (object ID 1)
# 100x100 pixels = 2000x2000 twips
shape1 = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape1.add_fill(SolidFill(255, 0, 0))  # red
shape1.add_line_style(LineStyle(20, 0, 0, 0))  # 1px black outline
shape1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a green square shape (object ID 2)
# 100x100 pixels, offset to the right so both are visible
shape2 = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 2000))
shape2.add_fill(SolidFill(0, 180, 0))  # green
shape2.add_line_style(LineStyle(20, 0, 0, 0))  # 1px black outline
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Define a 3-frame sprite (object ID 3)
sprite = swf.define_sprite(object_id=3, frame_count=3)

# Sprite frame 0: place red square at depth 1
sprite.place_object(object_id=1, depth=1)
sprite.show_frame()

# Sprite frame 1: place green square at depth 2 (to the right of red)
sprite.place_object(object_id=2, depth=2, trans_x=2400)  # 120px right
sprite.show_frame()

# Sprite frame 2: remove red square from depth 1
sprite.remove_object(depth=1)
sprite.show_frame()

# Place the sprite on the main timeline at (50, 75) pixels
swf.place_object(object_id=3, depth=1, trans_x=1000, trans_y=1500)

# Main timeline: 12 frames (1 second loop at 12fps)
# Each ShowFrame advances the sprite by one sprite-frame
for _ in range(12):
    swf.show_frame()

swf.save("test.swf")
