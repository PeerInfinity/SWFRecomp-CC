#!/usr/bin/env python3
"""
Simple test to verify InitObject + GetMember works
"""
import struct

signature = b'FWS'
version = 5
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

actions = b''

# Create object {x: 42}
action_push_42 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_42 += struct.pack('<f', 42.0)
actions += action_push_42

string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH string
action_push_x += string_x
actions += action_push_x

action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

# InitObject
action_init_object = bytes([0x43])
actions += action_init_object

# Duplicate for GetMember
action_duplicate = bytes([0x3D])
actions += action_duplicate

# Push "x" and GetMember
actions += action_push_x
action_get_member = bytes([0x4E])
actions += action_get_member

# Trace result (should be 42)
action_trace = bytes([0x26])
actions += action_trace

# End
action_end = bytes([0x00])
actions += action_end

# Build SWF
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('/tmp/simple_test.swf', 'wb') as f:
    f.write(swf_data)

print("Created simple test - should output 42")
