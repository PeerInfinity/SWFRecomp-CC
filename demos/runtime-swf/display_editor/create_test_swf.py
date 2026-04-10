#!/usr/bin/env python3
"""Generate test.swf for display_editor demo.

Creates a SWF with three colored rectangles at different positions:
- Red rectangle at (50, 50)
- Blue rectangle at (200, 100)
- Green rectangle at (100, 250)

Each shape is at a separate depth for individual manipulation.
SWF version 7, two frames (stop on frame 1 so shapes persist).
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__),
    "..", "..", "..", "SWFRecomp", "tests", "graphics"))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=400, height=400, fps=12, version=7)
swf.set_background(240, 240, 240)

# Shape 1: Red rectangle 100x80 (bounds in twips: 0-2000, 0-1600)
s1 = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 1600))
s1.add_fill(SolidFill(220, 50, 50))
s1.add_line_style(LineStyle(20, 0, 0, 0))
s1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2000, 0),
    LineTo(0, 1600),
    LineTo(-2000, 0),
    LineTo(0, -1600),
])

# Shape 2: Blue rectangle 120x60
s2 = swf.define_shape(object_id=2, bounds=(0, 2400, 0, 1200))
s2.add_fill(SolidFill(50, 80, 220))
s2.add_line_style(LineStyle(20, 0, 0, 0))
s2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(2400, 0),
    LineTo(0, 1200),
    LineTo(-2400, 0),
    LineTo(0, -1200),
])

# Shape 3: Green rectangle 80x100
s3 = swf.define_shape(object_id=3, bounds=(0, 1600, 0, 2000))
s3.add_fill(SolidFill(50, 180, 80))
s3.add_line_style(LineStyle(20, 0, 0, 0))
s3.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(1600, 0),
    LineTo(0, 2000),
    LineTo(-1600, 0),
    LineTo(0, -2000),
])

# Place shapes at different positions (trans_x/trans_y in twips, 20 twips = 1 pixel)
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=1000)   # (50, 50)
swf.place_object(object_id=2, depth=2, trans_x=4000, trans_y=2000)   # (200, 100)
swf.place_object(object_id=3, depth=3, trans_x=2000, trans_y=5000)   # (100, 250)

# Add a trace and stop
swf.add_trace("display_editor: 3 shapes placed")
swf.show_frame()

# Frame 2: just stop (ActionStop = 0x07)
# The swfmill_helpers don't have a direct stop() API, so add raw bytecode trace
swf.add_trace("display_editor: stopped")
swf.show_frame()

swf.save("test.swf")
print("Created test.swf")
