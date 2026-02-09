#!/usr/bin/env python3
"""Generate test.swf for PlaceObject3 + blend mode test.

Two overlapping colored rectangles:
  - Shape 1 (red) at depth 1 with normal PlaceObject2
  - Shape 2 (blue) at depth 2 with PlaceObject3 blend_mode=8 (Add)
The overlap area should appear bright magenta/white due to additive blending.
"""
import sys, os, struct, base64
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _build_place_object2_body, _build_matrix_bits,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(0, 0, 0)  # Black background to see additive blend

# Shape 1: red rectangle 200x200 px = 4000x4000 twips
shape1 = swf.define_shape(object_id=1, bounds=(0, 4000, 0, 4000), shape_version=3)
shape1.add_fill(SolidFill(255, 0, 0, 255))
shape1.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Shape 2: blue rectangle 200x200 px
shape2 = swf.define_shape(object_id=2, bounds=(0, 4000, 0, 4000), shape_version=3)
shape2.add_fill(SolidFill(0, 0, 255, 255))
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Place shape 1 at (50, 50)px = (1000, 1000) twips with normal PlaceObject2
swf.place_object(object_id=1, depth=1, trans_x=1000, trans_y=1000)

# Build PlaceObject3 raw binary for shape 2 with blend_mode=8 (Add)
# Place at (150, 100)px = (3000, 2000) twips, overlapping shape 1
def build_place_object3(object_id, depth, trans_x, trans_y, blend_mode):
    """Build raw PlaceObject3 (tag 70) body."""
    # Flags byte 1: HasCharacter(0x02) + HasMatrix(0x04)
    flags1 = 0x02 | 0x04
    # Flags byte 2: HasBlendMode(0x04)
    flags2 = 0x04

    body = struct.pack('<B', flags1)     # flags byte 1
    body += struct.pack('<B', flags2)    # flags byte 2 (PO3)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', object_id)
    body += _build_matrix_bits({"transX": trans_x, "transY": trans_y})
    # FilterList: none (flags2 bit 1 not set)
    # BlendMode: UI8
    body += struct.pack('<B', blend_mode)
    return body

po3_body = build_place_object3(object_id=2, depth=2, trans_x=3000, trans_y=2000, blend_mode=8)
swf.add_raw_tag(70, po3_body)  # PlaceObject3 = tag 70

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
