#!/usr/bin/env python3
"""Generate test.swf for define_font3 graphics test.

Tests DefineFont3 (tag 75) and DefineText (tag 11) rendering.
DefineFont3 is identical to DefineFont2 in structure but uses a 20480-unit
EM square (20x higher resolution than DefineFont2's 1024 units).  Defines
a font with 3 geometric glyphs (arrow, hexagon, cross) using DefineFont3
and renders a sequence of them as static text.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
    TextRecord,
)

# SWF version 8+ required for DefineFont3
swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# ---- Define Font3 (object ID 1) with 3 geometric glyphs ----
# DefineFont3 uses a 20480-unit EM square (20x DefineFont2's 1024)
EM = 20480
font = swf.define_font3(object_id=1, font_name="TestFont3")

# Glyph 0: Right-pointing triangle
font.add_glyph([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(EM, EM // 2),
    LineTo(-EM, EM // 2),
    LineTo(0, -EM),
])

# Glyph 1: Hexagon
import math
hex_r = EM // 2
hex_cx, hex_cy = EM // 2, EM // 2
hex_pts = []
for i in range(6):
    angle = math.pi / 3 * i - math.pi / 2
    hex_pts.append((
        int(hex_cx + hex_r * math.cos(angle)),
        int(hex_cy + hex_r * math.sin(angle)),
    ))

edges_hex = [ShapeSetup(x=hex_pts[0][0], y=hex_pts[0][1], fillStyle1=1)]
for i in range(1, 6):
    dx = hex_pts[i][0] - hex_pts[i-1][0]
    dy = hex_pts[i][1] - hex_pts[i-1][1]
    edges_hex.append(LineTo(dx, dy))
# Close back to start
dx = hex_pts[0][0] - hex_pts[5][0]
dy = hex_pts[0][1] - hex_pts[5][1]
edges_hex.append(LineTo(dx, dy))
font.add_glyph(edges_hex)

# Glyph 2: Plus/cross shape
arm = EM // 6  # arm half-width
ext = EM // 2  # arm length from center
cx, cy = EM // 2, EM // 2
font.add_glyph([
    ShapeSetup(x=cx - arm, y=cy - ext, fillStyle1=1),
    LineTo(arm * 2, 0),         # top edge right
    LineTo(0, ext - arm),       # down to right arm
    LineTo(ext - arm, 0),       # right arm out
    LineTo(0, arm * 2),         # right arm down
    LineTo(-(ext - arm), 0),    # right arm back
    LineTo(0, ext - arm),       # down to bottom
    LineTo(-arm * 2, 0),        # bottom edge left
    LineTo(0, -(ext - arm)),    # up to left arm
    LineTo(-(ext - arm), 0),    # left arm out
    LineTo(0, -arm * 2),        # left arm up
    LineTo(ext - arm, 0),       # left arm back
    LineTo(0, -(ext - arm)),    # close to top
])

# ---- Define Text (object ID 2) ----
text = swf.define_text(
    object_id=2,
    bounds=(0, 7000, 0, 1600),
    transform={"transX": 0, "transY": 0},
)

text.add_record(TextRecord(
    font_id=1,
    color=(200, 50, 50),
    x_offset=0,
    y_offset=1200,
    text_height=1200,
    glyphs=[
        (0, 1400),  # arrow
        (1, 1400),  # hexagon
        (2, 1400),  # cross
        (0, 1400),  # arrow
        (2, 1400),  # cross
    ],
))

swf.place_object(object_id=2, depth=1, trans_x=1000, trans_y=4000)
swf.show_frame()
swf.save("test.swf")
