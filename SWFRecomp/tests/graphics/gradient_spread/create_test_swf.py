#!/usr/bin/env python3
"""Generate test.swf for gradient spread modes graphics test.

Tests the three gradient spread modes (pad, reflect, repeat) using
DefineShape3 (tag 32) with linear gradients. Each shape has a gradient
that only covers the center portion, so the spread mode determines what
happens at the edges.

Expected: 3 rectangles side by side
  - Left:   Pad mode (gradient clamps at edges)
  - Center: Reflect mode (gradient mirrors back and forth)
  - Right:  Repeat mode (gradient repeats/tiles)
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
    _build_matrix_bits, _build_rect_bits, _build_shape_binary,
    _BitWriter, _bits_needed_signed,
)


def _build_define_shape3_gradient(object_id, bounds, spread_mode, gradient_matrix, stops, edges):
    """Build raw DefineShape3 (tag 32) body with a single linear gradient fill.

    bounds: (left, right, top, bottom) in twips
    spread_mode: 0=pad, 1=reflect, 2=repeat
    gradient_matrix: dict for _build_matrix_bits (scaleX/Y, transX/Y)
    stops: list of (ratio_0_255, r, g, b, a) tuples
    edges: list of ShapeSetup/LineTo/CurveTo records
    """
    body = bytearray()
    body += struct.pack('<H', object_id)  # CharacterID

    left, right, top, bottom = bounds
    body += _build_rect_bits(left, right, top, bottom)  # ShapeBounds

    # === FILLSTYLEARRAY (1 gradient fill) ===
    body.append(1)  # FillStyleCount
    body.append(0x10)  # FillStyleType = Linear Gradient
    body += _build_matrix_bits(gradient_matrix)  # GradientMatrix

    # GRADIENT: SpreadMode(UB2) | InterpolationMode(UB2) | NumGradients(UB4) = 1 byte
    header = (spread_mode << 6) | (0 << 4) | len(stops)
    body.append(header)

    # GradientRecords — RGBA for DefineShape3
    for ratio, r, g, b, a in stops:
        body.append(ratio)          # Ratio (UI8, 0-255)
        body.extend((r, g, b, a))   # Color (RGBA)

    # === LINESTYLEARRAY (empty) ===
    body.append(0)

    # === Shape records ===
    body += _build_shape_binary(edges, 1, 0)  # 1 fill bit, 0 line bits

    return bytes(body)


swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# Gradient stops: red -> blue, covering ratio 0-255
stops = [
    (0,   255, 0, 0, 255),   # Red at start
    (255, 0, 0, 255, 255),   # Blue at end
]

# Each rectangle: 120x200 twips (6000x10000 in twips @ 20 twips/pixel)
# Positioned at different X offsets
SHAPE_W = 6000   # 300px
SHAPE_H = 10000  # 500px... actually let's use smaller
SHAPE_W = 3000   # 150px
SHAPE_H = 5000   # 250px

# The gradient only covers the center 40% of the shape width.
# This makes the spread modes clearly visible at the edges.
# Gradient space: -16384 to +16384 = 32768 units
# We want gradient to map to the center 40% of shape width (1200 twips)
# scaleX = 1200 / 32768 ≈ 0.0366
# Center the gradient at the shape center
gradient_center_x = SHAPE_W // 2  # 1500
gradient_width = int(SHAPE_W * 0.4)  # 1200
grad_scale_x = gradient_width / 32768.0
grad_scale_y = SHAPE_H / 32768.0  # scale Y to fill shape height

grad_matrix = {
    "scaleX": grad_scale_x,
    "scaleY": grad_scale_y,
    "transX": gradient_center_x,
    "transY": SHAPE_H // 2,
}

# Simple rectangle edges
def make_rect_edges(w, h):
    return [
        ShapeSetup(x=0, y=0, fillStyle1=1),
        LineTo(w, 0),
        LineTo(0, h),
        LineTo(-w, 0),
        LineTo(0, -h),
    ]

edges = make_rect_edges(SHAPE_W, SHAPE_H)
bounds = (0, SHAPE_W, 0, SHAPE_H)

# Shape 1: Pad mode (spread_mode=0)
body1 = _build_define_shape3_gradient(1, bounds, 0, grad_matrix, stops, edges)
swf.add_raw_tag(32, body1)  # DefineShape3

# Shape 2: Reflect mode (spread_mode=1)
body2 = _build_define_shape3_gradient(2, bounds, 1, grad_matrix, stops, edges)
swf.add_raw_tag(32, body2)

# Shape 3: Repeat mode (spread_mode=2)
body3 = _build_define_shape3_gradient(3, bounds, 2, grad_matrix, stops, edges)
swf.add_raw_tag(32, body3)

# Place shapes side by side with some spacing
spacing = 500  # 25px gap
x_offset = 500  # left margin

swf.place_object(object_id=1, depth=1, trans_x=x_offset, trans_y=500)
swf.place_object(object_id=2, depth=2, trans_x=x_offset + SHAPE_W + spacing, trans_y=500)
swf.place_object(object_id=3, depth=3, trans_x=x_offset + 2 * (SHAPE_W + spacing), trans_y=500)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
