#!/usr/bin/env python3
"""Generate test.swf for PlaceObject2 clip actions graphics test.

Tests clip actions (CLIPACTIONS) on PlaceObject2. A sprite is placed with:
  - onLoad: trace("clip_load")

The sprite contains a red square. The visual test verifies the shape renders
correctly; clip action execution can be verified in the browser console
(single "clip_load" message on load).

swfmill does not support CLIPACTIONS in PlaceObject2 XML, so the PlaceObject2
tag is built as raw binary.
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _build_matrix_bits, _build_rect_bits,
    _BitWriter, _bits_needed_signed,
)


def _build_action_trace(message):
    """Build ActionScript bytecode: ActionPush(string) + ActionTrace + ActionEnd."""
    data = bytearray()
    # ActionPush (0x96)
    push_str = message.encode('ascii') + b'\x00'
    data.append(0x96)
    data += struct.pack('<H', 1 + len(push_str))  # length
    data.append(0x00)  # type 0 = string
    data += push_str
    # ActionTrace (0x26)
    data.append(0x26)
    # ActionEnd (0x00)
    data.append(0x00)
    return bytes(data)


def _build_place_object2_with_clip_actions(char_id, depth, trans_x, trans_y,
                                            clip_actions, swf_version=6):
    """Build raw PlaceObject2 (tag 26) with CLIPACTIONS.

    clip_actions: list of (event_flags, action_bytes) tuples
    swf_version: determines UI16 vs UI32 for event flags
    """
    flags = 0x02 | 0x04 | 0x80  # HasCharacter | HasMatrix | HasClipActions

    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)

    # Matrix (translate only)
    body += _build_matrix_bits({"transX": trans_x, "transY": trans_y})

    # --- CLIPACTIONS ---
    # Reserved (UI16)
    body += struct.pack('<H', 0)

    # AllEventFlags: OR of all event flags
    all_flags = 0
    for event_flags, _ in clip_actions:
        all_flags |= event_flags

    if swf_version >= 6:
        body += struct.pack('<I', all_flags)  # UI32
    else:
        body += struct.pack('<H', all_flags & 0xFFFF)  # UI16

    # CLIPACTIONRECORD entries
    for event_flags, action_bytes in clip_actions:
        if swf_version >= 6:
            body += struct.pack('<I', event_flags)  # EventFlags (UI32)
        else:
            body += struct.pack('<H', event_flags & 0xFFFF)  # EventFlags (UI16)

        body += struct.pack('<I', len(action_bytes))  # ActionRecordSize
        body += action_bytes

    # ClipActionEndFlag
    if swf_version >= 6:
        body += struct.pack('<I', 0)  # UI32
    else:
        body += struct.pack('<H', 0)  # UI16

    return bytes(body)


# Event flag constants (matching SWF spec)
CLIP_EVENT_LOAD = 0x00001


swf = SWFMLBuilder(width=550, height=400, fps=12, version=6)
swf.set_background(255, 255, 255)

# Define a red square (shape 1)
shape = swf.define_shape(object_id=1, bounds=(0, 4000, 0, 4000))
shape.add_fill(SolidFill(255, 0, 0))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Define sprite (object 2) containing the red square
sprite = swf.define_sprite(object_id=2, frame_count=1)
sprite.place_object(object_id=1, depth=1)
sprite.show_frame()

# Place sprite with clip actions (raw binary PlaceObject2)
clip_actions = [
    (CLIP_EVENT_LOAD, _build_action_trace("clip_load")),
]

place_body = _build_place_object2_with_clip_actions(
    char_id=2, depth=1,
    trans_x=1000, trans_y=1000,
    clip_actions=clip_actions,
    swf_version=6,
)
swf.add_raw_tag(26, place_body)  # PlaceObject2

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
