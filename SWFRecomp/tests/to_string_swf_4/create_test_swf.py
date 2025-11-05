#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with ToString actions
# Test multiple conversions to verify TO_STRING opcode (0x4B)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test Case 1: trace(toString(42))
# Expected output: "42"
float_42 = struct.pack('<f', 42.0)
action_push_42 = struct.pack('<BHB', 0x96, 5, 1) + float_42  # PUSH 42.0
action_to_string_1 = bytes([0x4B])  # ToString (0x4B)
action_trace_1 = bytes([0x26])  # Trace

# Test Case 2: trace(toString(3.14))
# Expected output: "3.14"
float_314 = struct.pack('<f', 3.14)
action_push_314 = struct.pack('<BHB', 0x96, 5, 1) + float_314  # PUSH 3.14
action_to_string_2 = bytes([0x4B])  # ToString (0x4B)
action_trace_2 = bytes([0x26])  # Trace

# Test Case 3: trace(toString(0))
# Expected output: "0"
float_0 = struct.pack('<f', 0.0)
action_push_0 = struct.pack('<BHB', 0x96, 5, 1) + float_0  # PUSH 0.0
action_to_string_3 = bytes([0x4B])  # ToString (0x4B)
action_trace_3 = bytes([0x26])  # Trace

# Test Case 4: trace(toString(-123.45))
# Expected output: "-123.45"
float_neg = struct.pack('<f', -123.45)
action_push_neg = struct.pack('<BHB', 0x96, 5, 1) + float_neg  # PUSH -123.45
action_to_string_4 = bytes([0x4B])  # ToString (0x4B)
action_trace_4 = bytes([0x26])  # Trace

# END action
action_end = bytes([0x00])

# Combine all actions
actions = (action_push_42 + action_to_string_1 + action_trace_1 +
           action_push_314 + action_to_string_2 + action_trace_2 +
           action_push_0 + action_to_string_3 + action_trace_3 +
           action_push_neg + action_to_string_4 + action_trace_4 +
           action_end)

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
print("\nTest cases:")
print("1. toString(42)      -> Expected: 42")
print("2. toString(3.14)    -> Expected: 3.14")
print("3. toString(0)       -> Expected: 0")
print("4. toString(-123.45) -> Expected: -123.45")
