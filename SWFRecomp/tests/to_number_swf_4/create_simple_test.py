#!/usr/bin/env python3
import struct

# Simplified test - just test number input
# Test: Number(42.5) should output 42.5

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

actions = b''

# Test: Number(42.5) - already a number
float_value = struct.pack('<f', 42.5)
action_push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, type=1 (float)
action_push += float_value
actions += action_push
actions += bytes([0x4A])  # ToNumber action
actions += bytes([0x26])  # Trace action

# END action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test: Number(42.5) -> Expected: 42.5")
