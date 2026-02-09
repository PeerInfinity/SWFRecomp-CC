#!/usr/bin/env python3
"""Generate test.swf for ColorMatrixFilter test.

A red rectangle placed with PlaceObject3 + ColorMatrixFilter that converts
it to grayscale. The grayscale formula uses standard luminance weights:
  R_out = 0.299*R + 0.587*G + 0.114*B
  G_out = 0.299*R + 0.587*G + 0.114*B
  B_out = 0.299*R + 0.587*G + 0.114*B
  A_out = A
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _build_matrix_bits,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(200, 200, 200)  # Light gray background

# Shape 1: bright red rectangle 200x200 px = 4000x4000 twips
shape = swf.define_shape(object_id=1, bounds=(0, 4000, 0, 4000), shape_version=3)
shape.add_fill(SolidFill(255, 0, 0, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Shape 2: same red rectangle (placed normally for comparison)
shape2 = swf.define_shape(object_id=2, bounds=(0, 4000, 0, 4000), shape_version=3)
shape2.add_fill(SolidFill(255, 0, 0, 255))
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Place shape 2 normally (red, no filter) at left side
swf.place_object(object_id=2, depth=1, trans_x=500, trans_y=1000)

# Build PlaceObject3 with ColorMatrixFilter (grayscale)
def build_po3_with_color_matrix(object_id, depth, trans_x, trans_y, matrix_20):
    """Build PlaceObject3 with a ColorMatrixFilter.

    matrix_20: list of 20 floats (row-major 4x5 color matrix)
    """
    # Flags byte 1: HasCharacter(0x02) + HasMatrix(0x04)
    flags1 = 0x02 | 0x04
    # Flags byte 2: HasFilterList(0x02)
    flags2 = 0x02

    body = struct.pack('<B', flags1)
    body += struct.pack('<B', flags2)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', object_id)
    body += _build_matrix_bits({"transX": trans_x, "transY": trans_y})

    # FilterList: NumberOfFilters=1, FilterId=6 (ColorMatrixFilter), 20 floats
    body += struct.pack('<B', 1)   # 1 filter
    body += struct.pack('<B', 6)   # ColorMatrixFilter
    for f in matrix_20:
        body += struct.pack('<f', f)

    return body

# Grayscale color matrix (standard luminance weights)
# Row 0 (R_out): 0.299*R + 0.587*G + 0.114*B + 0*A + 0 bias
# Row 1 (G_out): 0.299*R + 0.587*G + 0.114*B + 0*A + 0 bias
# Row 2 (B_out): 0.299*R + 0.587*G + 0.114*B + 0*A + 0 bias
# Row 3 (A_out): 0*R + 0*G + 0*B + 1*A + 0 bias
grayscale_matrix = [
    0.299, 0.587, 0.114, 0, 0,  # R row
    0.299, 0.587, 0.114, 0, 0,  # G row
    0.299, 0.587, 0.114, 0, 0,  # B row
    0,     0,     0,     1, 0,  # A row
]

po3_body = build_po3_with_color_matrix(
    object_id=1, depth=2, trans_x=5500, trans_y=1000, matrix_20=grayscale_matrix)
swf.add_raw_tag(70, po3_body)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
