#!/usr/bin/env python3
"""Generate test.swf for clip_mask graphics test.

Tests PlaceObject2 with ClipDepth: a circular clipping mask restricts
rendering of a large red square, producing a visible circle-shaped region.

Layout:
  - Shape 1 (depth 1, clipDepth=2): A circle used as a clipping mask
  - Shape 2 (depth 2): A large red square that gets clipped by the circle
  - Shape 3 (depth 3): A blue square rendered normally (outside clip range)
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, LineStyle,
    ShapeSetup, LineTo, CurveTo,
)

import math

os.chdir(os.path.dirname(os.path.abspath(__file__)))

swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# --- Shape 1: Circle (clipping mask) ---
# Approximate a circle with 8 quadratic Bezier curves
# Center at (3000, 3000), radius 2000 twips (100 pixels)
cx, cy = 3000, 3000
r = 2000

# Compute points on circle at 45-degree intervals
# Angle 0 = top of circle, going clockwise
angles = [i * math.pi / 4 for i in range(9)]  # 0 to 2*pi
pts = []
for a in angles:
    px = cx + int(r * math.sin(a))
    py = cy - int(r * math.cos(a))
    pts.append((px, py))

shape1 = swf.define_shape(object_id=1, bounds=(cx - r - 40, cx + r + 40, cy - r - 40, cy + r + 40))
shape1.add_fill(SolidFill(0, 0, 0))  # fill index 1 (black, used as mask shape)

edges = [ShapeSetup(x=pts[0][0], y=pts[0][1], fillStyle1=1)]

for i in range(8):
    # Control point for quadratic bezier between pts[i] and pts[i+1]
    mid_angle = (angles[i] + angles[i + 1]) / 2
    # Control point is at radius / cos(pi/8) along the bisector
    cp_r = r / math.cos(math.pi / 8)
    cp_x = cx + int(cp_r * math.sin(mid_angle))
    cp_y = cy - int(cp_r * math.cos(mid_angle))

    # CurveTo uses delta coordinates from current position
    dx1 = cp_x - pts[i][0]
    dy1 = cp_y - pts[i][1]
    dx2 = pts[i + 1][0] - cp_x
    dy2 = pts[i + 1][1] - cp_y

    edges.append(CurveTo(dx1, dy1, dx2, dy2))

shape1.add_edges(edges)

# --- Shape 2: Large red square (will be clipped by the circle) ---
sq_size = 5000  # 250 pixels
shape2 = swf.define_shape(object_id=2, bounds=(0, sq_size + 40, 0, sq_size + 40))
shape2.add_fill(SolidFill(255, 0, 0))       # fill index 1
shape2.add_line_style(LineStyle(20, 0, 0, 0))  # line index 1

shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(sq_size, 0),
    LineTo(0, sq_size),
    LineTo(-sq_size, 0),
    LineTo(0, -sq_size),
])

# --- Shape 3: Blue square (outside clip range, renders normally) ---
blue_size = 2000  # 100 pixels
shape3 = swf.define_shape(object_id=3, bounds=(0, blue_size + 40, 0, blue_size + 40))
shape3.add_fill(SolidFill(0, 0, 255))       # fill index 1
shape3.add_line_style(LineStyle(20, 0, 0, 0))  # line index 1

shape3.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1, lineStyle=1),
    LineTo(blue_size, 0),
    LineTo(0, blue_size),
    LineTo(-blue_size, 0),
    LineTo(0, -blue_size),
])

# --- Place objects ---
# Shape 1 at depth 1 with clipDepth=2: acts as clipping mask for depth 2
swf.place_object(object_id=1, depth=1, trans_x=0, trans_y=0, clip_depth=2)

# Shape 2 at depth 2: clipped by the circle mask
swf.place_object(object_id=2, depth=2, trans_x=1000, trans_y=1000)

# Shape 3 at depth 3: outside clip range, renders normally
swf.place_object(object_id=3, depth=3, trans_x=7000, trans_y=1000)

swf.show_frame()
swf.save("test.swf")
