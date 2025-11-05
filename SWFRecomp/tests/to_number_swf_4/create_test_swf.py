#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with ToNumber action
# Test: Number("123.45") should output 123.45 (string to number conversion)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace(toNumber("123.45"))
# Push "123.45" as a string
test_str = "123.45".encode('ascii') + b'\x00'
action_push = struct.pack('<BHB', 0x96, len(test_str) + 1, 0)  # PUSH action, type=0 (string)
action_push += test_str

# ToNumber action (0x4A)
action_to_number = bytes([0x4A])

# Trace action (0x26)
action_trace = bytes([0x26])

# END action
action_end = bytes([0x00])

# DoAction tag
actions = action_push + action_to_number + action_trace + action_end
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

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
print("Test case: Number(\"123.45\")")
print("Expected output: 123.45")
