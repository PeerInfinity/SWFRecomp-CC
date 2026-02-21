#!/usr/bin/env python3
"""Generate test.swf for DoInitAction (tag 59) trace test.

Defines a sprite with a DoInitAction that traces "init_action_ran".
The sprite is placed, and frame 1 traces "frame_1".
Expected output:
  init_action_ran
  frame_1
"""
import sys, os, struct, base64
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "graphics"))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill, ShapeSetup, LineTo,
    _BitWriter, _bits_needed_signed,
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# Define a simple sprite (object_id=1) with 1 frame
sprite = swf.define_sprite(object_id=1, frame_count=1)
sprite.show_frame()

# Add DoInitAction (tag 59) for sprite ID 1
# Format: SpriteId(UI16) + ActionRecords
# ActionPush string "init_action_ran" + ActionTrace + ActionEnd
action_data = b""
# ActionPush (0x96)
push_str = b"init_action_ran\x00"
action_data += struct.pack('<B', 0x96)  # ActionPush
action_data += struct.pack('<H', 1 + len(push_str))  # length
action_data += struct.pack('<B', 0x00)  # type 0 = string
action_data += push_str
# ActionTrace (0x26)
action_data += struct.pack('<B', 0x26)
# ActionEnd (0x00)
action_data += struct.pack('<B', 0x00)

body = struct.pack('<H', 1) + action_data  # SpriteId=1
swf.add_raw_tag(59, body)

# Place the sprite
swf.place_object(object_id=1, depth=1)

# Frame 1: trace "frame_1"
swf.add_trace("frame_1")
swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
