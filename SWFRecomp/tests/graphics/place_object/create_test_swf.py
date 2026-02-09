#!/usr/bin/env python3
"""Generate test.swf for PlaceObject (tag 4) graphics test.

Places a red square using the legacy PlaceObject tag (tag 4) instead of
PlaceObject2 (tag 26). Also tests optional CXFORM (RGB-only, 3 channels)
by tinting a second green square darker via multiply factors.
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, LineTo,
    _build_matrix_bits, _BitWriter, _bits_needed_signed,
)


def _build_place_object_body(char_id, depth, trans_x=0, trans_y=0,
                              scale_x=None, scale_y=None,
                              cxform=None):
    """Build raw PlaceObject (tag 4) body.

    PlaceObject format: CharacterId(UI16), Depth(UI16), Matrix(MATRIX),
    optional CXFORM (RGB only, no alpha — present if bytes remain).
    """
    body = struct.pack('<H', char_id)
    body += struct.pack('<H', depth)

    mat = {"transX": trans_x, "transY": trans_y}
    if scale_x is not None:
        mat["scaleX"] = scale_x
    if scale_y is not None:
        mat["scaleY"] = scale_y
    body += _build_matrix_bits(mat)

    if cxform is not None:
        # CXFORM (not CXFORMWITHALPHA): RGB only, 3 channels
        has_add = any(v != 0 for v in cxform.get("add", (0, 0, 0)))
        has_mult = any(v != 256 for v in cxform.get("mult", (256, 256, 256)))

        bw = _BitWriter()
        bw.write_bits(1 if has_add else 0, 1)
        bw.write_bits(1 if has_mult else 0, 1)

        vals = []
        if has_mult:
            vals.extend(cxform.get("mult", (256, 256, 256)))
        if has_add:
            vals.extend(cxform.get("add", (0, 0, 0)))

        nbits = max((_bits_needed_signed(v) for v in vals), default=1) if vals else 1
        bw.write_bits(nbits, 4)

        if has_mult:
            for v in cxform.get("mult", (256, 256, 256)):
                bw.write_sb(v, nbits)
        if has_add:
            for v in cxform.get("add", (0, 0, 0)):
                bw.write_sb(v, nbits)

        body += bw.to_bytes()

    return body


swf = SWFMLBuilder(width=550, height=400, fps=12, version=3)
swf.set_background(255, 255, 255)

# Define a red square (shape 1)
shape1 = swf.define_shape(object_id=1, bounds=(1000, 5000, 1000, 5000))
shape1.add_fill(SolidFill(255, 0, 0))
shape1.add_edges([
    ShapeSetup(x=1000, y=1000, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Define a green square (shape 2)
shape2 = swf.define_shape(object_id=2, bounds=(1000, 5000, 1000, 5000))
shape2.add_fill(SolidFill(0, 255, 0))
shape2.add_edges([
    ShapeSetup(x=1000, y=1000, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Place shape 1 using PlaceObject (tag 4) — no CXFORM
body1 = _build_place_object_body(char_id=1, depth=1, trans_x=0, trans_y=0)
swf.add_raw_tag(4, body1)

# Place shape 2 using PlaceObject (tag 4) with CXFORM tint (50% brightness)
body2 = _build_place_object_body(
    char_id=2, depth=2, trans_x=5000, trans_y=0,
    cxform={"mult": (128, 128, 128)}  # 50% multiply on R,G,B
)
swf.add_raw_tag(4, body2)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
