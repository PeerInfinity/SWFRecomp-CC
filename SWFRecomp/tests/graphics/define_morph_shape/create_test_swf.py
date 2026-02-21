#!/usr/bin/env python3
"""Generate test.swf for define_morph_shape graphics test.

A DefineMorphShape (tag 46) that morphs from a red square (ratio=0) to a
blue diamond (ratio=65535).  Placed at ratio=32768 (50%), so an intermediate
purple shape should be rendered.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, MorphShapeDefinition,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

# Morph shape: red square -> blue diamond
# Start bounds and end bounds both cover the same area
morph = swf.define_morph_shape(
    object_id=1,
    start_bounds=(1000, 5000, 1000, 5000),
    end_bounds=(1000, 5000, 1000, 5000),
)

# One solid fill: red at start, blue at end
morph.add_solid_fill(
    start_color=(255, 0, 0, 255),
    end_color=(0, 0, 255, 255),
)

# Start shape: square from (1000,1000) to (5000,5000)
morph.add_start_edges([
    ShapeSetup(x=1000, y=1000, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# End shape: diamond inscribed in the same bounds
# Center at (3000, 3000), vertices at midpoints of square sides
morph.add_end_edges([
    ShapeSetup(x=3000, y=1000),
    LineTo(2000, 2000),
    LineTo(-2000, 2000),
    LineTo(-2000, -2000),
    LineTo(2000, -2000),
])

swf.place_object(object_id=1, depth=1, ratio=32768)
swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
