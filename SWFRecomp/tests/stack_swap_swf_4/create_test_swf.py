#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with a stack swap operation
# Test: 2, 10, swap, divide → 10 / 2 = 5
# Without swap: 2 / 10 = 0.2

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: push 2, push 10, swap, divide, trace
# Push 2.0 (first value)
action_push_2 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_2 += struct.pack('<f', 2.0)  # Float value 2.0

# Push 10.0 (second value)
action_push_10 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_10 += struct.pack('<f', 10.0)  # Float value 10.0

# Stack Swap operation (0x4C)
action_stack_swap = bytes([0x4C])

# Divide operation (0x0D)
action_divide = bytes([0x0D])

# Trace action (0x26)
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_push_2 + action_push_10 + action_stack_swap + action_divide + action_trace + action_end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

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
print(f"Test: push 2, push 10, swap, divide, trace")
print(f"Expected output: 5 (10 / 2)")
print(f"Without swap would be: 0.2 (2 / 10)")
