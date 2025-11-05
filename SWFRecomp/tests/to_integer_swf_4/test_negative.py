#!/usr/bin/env python3
import struct

# Test: toInteger(-12.7) should output -12

# SWF Header
signature = b'FWS'
version = 4

# Frame size (RECT)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Push -12.7 as a float
float_value = struct.pack('<f', -12.7)
action_push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push += float_value

# ToInteger (0x18)
action_to_integer = bytes([0x18])

# Trace (0x26)
action_trace = bytes([0x26])

# END
action_end = bytes([0x00])

# Build SWF
actions = action_push + action_to_integer + action_trace + action_end
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_header += struct.pack('<I', len(actions))
do_action_tag = do_action_header + actions

show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_negative.swf', 'wb') as f:
    f.write(swf_data)

print("Created test_negative.swf")
print("Test: toInteger(-12.7)")
print("Expected output: -12")
