#!/usr/bin/env python3
"""Generate test.swf for define_shape4 graphics test.

Tests DefineShape4 (SWF tag 83) with LINESTYLE2, which supports
advanced line properties: start/end caps, join styles, and miter limits.

Creates three shapes with different line style properties:
  1. Triangle with round caps and round joins (red, thick lines)
  2. Square with square caps and miter joins (green)
  3. Pentagon with no caps and bevel joins (blue)
"""
import math
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle2,
    ShapeSetup, LineTo,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# --- Shape 1: Triangle with round caps, round joins ---
# Clockwise triangle (for fillStyle1 = interior fill)
# top-center -> bottom-right -> bottom-left -> close
side = 3000  # 150px in twips
h = int(side * math.sin(math.radians(60)))  # height ~2598

shape1 = swf.define_shape(object_id=1,
    bounds=(-100, side + 100, -100, h + 100), shape_version=4)
fill1 = shape1.add_fill(SolidFill(255, 200, 200, 255))
line1 = shape1.add_line_style(LineStyle2(
    width=100, r=200, g=0, b=0, a=255,
    start_cap=0, end_cap=0, join_style=0))  # round caps, round joins
shape1.add_edges([
    ShapeSetup(x=side // 2, y=0, fillStyle1=fill1, lineStyle=line1),
    LineTo(side // 2, h),       # down-right to bottom-right
    LineTo(-side, 0),           # left to bottom-left
    LineTo(side // 2, -h),      # up-right back to top
])

# --- Shape 2: Square with square caps, miter joins ---
# Clockwise: top-left -> top-right -> bottom-right -> bottom-left -> close
sq = 2600  # 130px

shape2 = swf.define_shape(object_id=2,
    bounds=(-100, sq + 100, -100, sq + 100), shape_version=4)
fill2 = shape2.add_fill(SolidFill(200, 255, 200, 255))
line2 = shape2.add_line_style(LineStyle2(
    width=80, r=0, g=150, b=0, a=255,
    start_cap=2, end_cap=2, join_style=2, miter_limit=2.0))  # square caps, miter
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=fill2, lineStyle=line2),
    LineTo(sq, 0),      # right
    LineTo(0, sq),       # down
    LineTo(-sq, 0),      # left
    LineTo(0, -sq),      # up
])

# --- Shape 3: Pentagon with no caps, bevel joins ---
# Regular pentagon traced clockwise
r_pent = 1600  # 80px radius in twips
cx, cy = 1700, 1700
# Generate points clockwise in SWF coords (Y increases downward)
pts = []
for i in range(5):
    angle = math.radians(-90 + i * 72)  # positive for clockwise in Y-down
    px = int(cx + r_pent * math.cos(angle))
    py = int(cy + r_pent * math.sin(angle))
    pts.append((px, py))

# Bounds
pxs = [p[0] for p in pts]
pys = [p[1] for p in pts]
shape3 = swf.define_shape(object_id=3,
    bounds=(min(pxs) - 100, max(pxs) + 100, min(pys) - 100, max(pys) + 100),
    shape_version=4)
fill3 = shape3.add_fill(SolidFill(200, 200, 255, 255))
line3 = shape3.add_line_style(LineStyle2(
    width=80, r=0, g=0, b=180, a=255,
    start_cap=1, end_cap=1, join_style=1))  # no caps, bevel joins
edges3 = [ShapeSetup(x=pts[0][0], y=pts[0][1], fillStyle1=fill3, lineStyle=line3)]
for i in range(1, 5):
    dx = pts[i][0] - pts[i-1][0]
    dy = pts[i][1] - pts[i-1][1]
    edges3.append(LineTo(dx, dy))
# Close back to start
dx = pts[0][0] - pts[4][0]
dy = pts[0][1] - pts[4][1]
edges3.append(LineTo(dx, dy))
shape3.add_edges(edges3)

# Place shapes side by side
swf.place_object(object_id=1, depth=1, trans_x=500, trans_y=1000)
swf.place_object(object_id=2, depth=2, trans_x=4000, trans_y=1000)
swf.place_object(object_id=3, depth=3, trans_x=7000, trans_y=1000)
swf.show_frame()
swf.save("test.swf")
