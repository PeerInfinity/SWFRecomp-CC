#!/usr/bin/env python3
"""Generate test.swf for DefineMorphShape2 (tag 84) graphics test.

DefineMorphShape2 extends DefineMorphShape (tag 46) with:
  - StartEdgeBounds + EndEdgeBounds RECTs
  - Flags byte (NonScalingStrokes / ScalingStrokes)
  - MorphLineStyle2 (caps, joins, fill, miter)

This test places a morph shape at ratio=32768 (50%) to verify interpolation
works correctly with the tag 84 format.

Expected: A shape partway between a green square (start) and a yellow diamond (end),
rendered as a teal/green-yellow intermediate color and intermediate shape.
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ShapeSetup, LineTo,
    _build_rect_bits, _build_shape_binary, _build_matrix_bits,
    _build_place_object2_body,
    _BitWriter, _bits_needed_signed,
)


def _build_define_morph_shape2_body(morph_def):
    """Build the raw tag body for DefineMorphShape2 (tag 84).

    morph_def: a dict with keys:
      object_id, start_bounds, end_bounds, fill_styles, start_edges, end_edges
    """
    body = bytearray()

    # CharacterID (UI16)
    body += struct.pack('<H', morph_def['object_id'])

    # StartBounds (RECT)
    body += _build_rect_bits(*morph_def['start_bounds'])

    # EndBounds (RECT)
    body += _build_rect_bits(*morph_def['end_bounds'])

    # --- DefineMorphShape2 extra fields ---
    # StartEdgeBounds (RECT) — same as StartBounds for simplicity
    body += _build_rect_bits(*morph_def['start_bounds'])

    # EndEdgeBounds (RECT) — same as EndBounds for simplicity
    body += _build_rect_bits(*morph_def['end_bounds'])

    # Flags byte: Reserved(6) + UsesNonScalingStrokes(1) + UsesScalingStrokes(1)
    body.append(0x01)  # UsesScalingStrokes = 1

    # Build fill/line/edges to compute Offset
    fill_styles = morph_def['fill_styles']
    fill_count = len(fill_styles)

    # MORPHFILLSTYLEARRAY
    fill_bytes = bytearray()
    fill_bytes.append(fill_count)
    for fill_type, start_color, end_color in fill_styles:
        if fill_type == "solid":
            fill_bytes.append(0x00)  # FillStyleType = solid
            fill_bytes.extend(start_color)  # StartColor (RGBA)
            fill_bytes.extend(end_color)    # EndColor (RGBA)

    # MORPHLINESTYLE2ARRAY (empty for this test)
    line_bytes = bytearray()
    line_bytes.append(0)  # 0 line styles

    # StartEdges SHAPE
    fill_bits = max(fill_count.bit_length(), 1) if fill_count > 0 else 0
    start_edges_bytes = _build_shape_binary(morph_def['start_edges'], fill_bits, 0)

    # EndEdges SHAPE
    end_edges_bytes = _build_shape_binary(morph_def['end_edges'], 0, 0)

    # Offset = fill_bytes + line_bytes + start_edges_bytes
    offset = len(fill_bytes) + len(line_bytes) + len(start_edges_bytes)
    body += struct.pack('<I', offset)

    body += fill_bytes
    body += line_bytes
    body += start_edges_bytes
    body += end_edges_bytes

    return bytes(body)


swf = SWFMLBuilder(width=550, height=400, fps=12, version=8)
swf.set_background(255, 255, 255)

# Start shape: green square at (1000,1000) to (5000,5000)
# End shape: yellow diamond centered at (3000,3000) with radius 3000
morph = {
    'object_id': 1,
    'start_bounds': (1000, 5000, 1000, 5000),
    'end_bounds': (0, 6000, 0, 6000),
    'fill_styles': [
        ("solid", (0, 200, 0, 255), (200, 200, 0, 255)),  # green -> yellow
    ],
    'start_edges': [
        ShapeSetup(x=1000, y=1000, fillStyle1=1),
        LineTo(4000, 0),
        LineTo(0, 4000),
        LineTo(-4000, 0),
        LineTo(0, -4000),
    ],
    'end_edges': [
        ShapeSetup(x=3000, y=0),
        LineTo(3000, 3000),
        LineTo(-3000, 3000),
        LineTo(-3000, -3000),
        LineTo(3000, -3000),
    ],
}

body = _build_define_morph_shape2_body(morph)
swf.add_raw_tag(84, body)  # DefineMorphShape2

# Place with ratio=32768 (50% morph)
place_body = _build_place_object2_body({
    'object_id': 1,
    'depth': 1,
    'trans_x': 1000,
    'trans_y': 1000,
    'ratio': 32768,
})
swf.add_raw_tag(26, place_body)  # PlaceObject2

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
