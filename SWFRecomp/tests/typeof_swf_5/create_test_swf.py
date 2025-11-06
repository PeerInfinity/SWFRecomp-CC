#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with Typeof actions
# Test typeof operator to verify TYPEOF opcode (0x3C)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test Case 1: trace(typeof(42))
# Expected output: "number"
float_42 = struct.pack('<f', 42.0)
action_push_42 = struct.pack('<BHB', 0x96, 5, 1) + float_42  # PUSH 42.0
action_typeof_1 = bytes([0x3C])  # Typeof (0x3C)
action_trace_1 = bytes([0x26])  # Trace

# Test Case 2: trace(typeof("hello"))
# Expected output: "string"
string_hello = b'hello\x00'
action_push_hello = struct.pack('<BHB', 0x96, 7, 0) + string_hello  # PUSH "hello"
action_typeof_2 = bytes([0x3C])  # Typeof (0x3C)
action_trace_2 = bytes([0x26])  # Trace

# Test Case 3: trace(typeof(3.14))
# Expected output: "number"
float_314 = struct.pack('<f', 3.14)
action_push_314 = struct.pack('<BHB', 0x96, 5, 1) + float_314  # PUSH 3.14
action_typeof_3 = bytes([0x3C])  # Typeof (0x3C)
action_trace_3 = bytes([0x26])  # Trace

# Test Case 4: trace(typeof(""))
# Expected output: "string"
string_empty = b'\x00'
action_push_empty = struct.pack('<BHB', 0x96, 1, 0) + string_empty  # PUSH ""
action_typeof_4 = bytes([0x3C])  # Typeof (0x3C)
action_trace_4 = bytes([0x26])  # Trace

# END action
action_end = bytes([0x00])

# Combine all actions
actions = (action_push_42 + action_typeof_1 + action_trace_1 +
           action_push_hello + action_typeof_2 + action_trace_2 +
           action_push_314 + action_typeof_3 + action_trace_3 +
           action_push_empty + action_typeof_4 + action_trace_4 +
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
print("1. typeof(42)      -> Expected: number")
print("2. typeof(\"hello\") -> Expected: string")
print("3. typeof(3.14)    -> Expected: number")
print("4. typeof(\"\")      -> Expected: string")
