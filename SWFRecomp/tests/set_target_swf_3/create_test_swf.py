#!/usr/bin/env python3
import struct

# Create a minimal SWF3 file with SetTarget actions
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3  # SetTarget is available in SWF 3+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing SetTarget
# Test sequence:
# 1. SetTarget "mySprite"
# 2. SetTarget ""  (return to main)

# ActionSetTarget with target "mySprite"
target_name_1 = b'mySprite\x00'  # Null-terminated string
action_set_target_1 = struct.pack('<BH', 0x8B, len(target_name_1))  # SetTarget (0x8B), length
action_set_target_1 += target_name_1

# ActionSetTarget with empty target (return to main)
target_name_2 = b'\x00'  # Empty null-terminated string
action_set_target_2 = struct.pack('<BH', 0x8B, len(target_name_2))  # SetTarget (0x8B), length
action_set_target_2 += target_name_2

# End action
action_end = bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(action_set_target_1 + action_set_target_2 + action_end)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_set_target_1 + action_set_target_2 + action_end

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
