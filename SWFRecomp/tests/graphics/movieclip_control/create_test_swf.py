#!/usr/bin/env python3
"""Generate test.swf for MovieClip timeline control test.

A sprite "mc" with 3 frames:
  - Frame 0: red square
  - Frame 1: green square
  - Frame 2: blue square

Main timeline ActionScript: setTarget("mc"); gotoAndStop(1);
This should freeze the sprite on frame 1 (green square).
Without MovieClip control, the sprite would cycle through all 3 frames.
"""
import sys, os, struct, base64
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _build_place_object2_body, _build_matrix_bits,
)

swf = SWFMLBuilder(width=550, height=400, fps=1, version=8)
swf.set_background(255, 255, 255)

# Shape 1: red square 200x200 px
shape = swf.define_shape(object_id=1, bounds=(0, 4000, 0, 4000), shape_version=3)
shape.add_fill(SolidFill(255, 0, 0, 255))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Shape 2: green square
shape2 = swf.define_shape(object_id=2, bounds=(0, 4000, 0, 4000), shape_version=3)
shape2.add_fill(SolidFill(0, 255, 0, 255))
shape2.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Shape 3: blue square
shape3 = swf.define_shape(object_id=3, bounds=(0, 4000, 0, 4000), shape_version=3)
shape3.add_fill(SolidFill(0, 0, 255, 255))
shape3.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(4000, 0),
    LineTo(0, 4000),
    LineTo(-4000, 0),
    LineTo(0, -4000),
])

# Sprite (object_id=4) with 3 frames
sprite = swf.define_sprite(object_id=4, frame_count=3)
sprite.place_object(object_id=1, depth=1, trans_x=0, trans_y=0)
sprite.show_frame()
sprite.remove_object(depth=1)
sprite.place_object(object_id=2, depth=1, trans_x=0, trans_y=0)
sprite.show_frame()
sprite.remove_object(depth=1)
sprite.place_object(object_id=3, depth=1, trans_x=0, trans_y=0)
sprite.show_frame()

# Place sprite with HasName — build raw PlaceObject2 with instance name "mc"
def build_po2_with_name(object_id, depth, trans_x, trans_y, name):
    """Build PlaceObject2 with HasName flag set."""
    flags = 0x02 | 0x04 | 0x20  # HasCharacter | HasMatrix | HasName
    body = struct.pack('<B', flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', object_id)
    body += _build_matrix_bits({"transX": trans_x, "transY": trans_y})
    body += name.encode('ascii') + b'\x00'  # null-terminated string
    return body

po2_body = build_po2_with_name(object_id=4, depth=1, trans_x=2000, trans_y=1000, name="mc")
swf.add_raw_tag(26, po2_body)  # PlaceObject2 = tag 26

# DoAction: setTarget("mc"); gotoAndStop(1);
# Build raw DoAction tag
def build_do_action_set_target_goto_stop(target_name, frame):
    """Build DoAction with SetTarget + GotoFrame + Stop."""
    body = b''
    # SetTarget (opcode 0x8B)
    name_bytes = target_name.encode('ascii') + b'\x00'
    body += struct.pack('<B', 0x8B)  # SetTarget
    body += struct.pack('<H', len(name_bytes))  # length
    body += name_bytes
    # GotoFrame (opcode 0x81)
    body += struct.pack('<B', 0x81)
    body += struct.pack('<H', 2)   # length = 2 bytes
    body += struct.pack('<H', frame)  # frame index (0-based)
    # Stop (opcode 0x07)
    body += struct.pack('<B', 0x07)
    # SetTarget "" to reset (opcode 0x8B)
    body += struct.pack('<B', 0x8B)
    body += struct.pack('<H', 1)
    body += b'\x00'
    # End (opcode 0x00)
    body += b'\x00'
    return body

do_action_body = build_do_action_set_target_goto_stop("mc", 1)
swf.add_raw_tag(12, do_action_body)  # DoAction = tag 12

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
