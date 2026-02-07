#!/usr/bin/env python3
"""Generate test.swf for color_transform graphics test.

Tests CXFORMWITHALPHA color transforms in PlaceObject2. Places four
white squares with different multiplicative color transforms:
  - Square 1: Red tint (zero out green and blue channels)
  - Square 2: Green tint (zero out red and blue channels)
  - Square 3: Blue tint (zero out red and green channels)
  - Square 4: Half-brightness (halve all channels)

Note: swfmill 0.3.6 does not encode additive CXFORM terms, so this
test uses only multiplicative transforms.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle, ColorTransform,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(200, 200, 200)

# Define a white square (80x80 pixels = 1600x1600 twips) with a thin black outline
shape = swf.define_shape(object_id=1, bounds=(0, 1600, 0, 1600))
shape.add_fill(SolidFill(255, 255, 255))         # fill 1: white
shape.add_line_style(LineStyle(20, 0, 0, 0))     # line 1: 1px black outline

shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(1600, 0),
    LineTo(0, 1600),
    LineTo(-1600, 0),
    LineTo(0, -1600),
])

# Square 1: Red tint
# White (255,255,255) * (1.0, 0.0, 0.0) = (255, 0, 0) = red
swf.place_object(object_id=1, depth=1, trans_x=600, trans_y=3200,
                 color_transform=ColorTransform(
                     factor_red=256, factor_green=0, factor_blue=0))

# Square 2: Green tint
# White (255,255,255) * (0.0, 1.0, 0.0) = (0, 255, 0) = green
swf.place_object(object_id=1, depth=2, trans_x=3000, trans_y=3200,
                 color_transform=ColorTransform(
                     factor_red=0, factor_green=256, factor_blue=0))

# Square 3: Blue tint
# White (255,255,255) * (0.0, 0.0, 1.0) = (0, 0, 255) = blue
swf.place_object(object_id=1, depth=3, trans_x=5400, trans_y=3200,
                 color_transform=ColorTransform(
                     factor_red=0, factor_green=0, factor_blue=256))

# Square 4: Half-brightness (dimmed)
# White (255,255,255) * (0.5, 0.5, 0.5) = (127, 127, 127) = gray
swf.place_object(object_id=1, depth=4, trans_x=7800, trans_y=3200,
                 color_transform=ColorTransform(
                     factor_red=128, factor_green=128, factor_blue=128))

swf.show_frame()
swf.save("test.swf")
