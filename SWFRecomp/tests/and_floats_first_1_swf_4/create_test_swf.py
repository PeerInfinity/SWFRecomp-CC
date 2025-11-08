#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with AND operation: 0 && 1
# Expected output: 0

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace(0 && 1)
# Stack-based: push 1, push 0, AND, trace

# Push 1 (first value on stack - will be second operand)
action_push_1 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_1 += struct.pack('<f', 1.0)

# Push 0 (second value on stack - will be first operand)
action_push_0 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_0 += struct.pack('<f', 0.0)

# AND operation (0x10)
action_and = bytes([0x10])

# TRACE action (0x26)
action_trace = bytes([0x26])

# END action
action_end = bytes([0x00])

# Combine actions
actions = action_push_1 + action_push_0 + action_and + action_trace + action_end

# DoAction tag
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
