#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with CallMethod action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5 for CallMethod support

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test: trace("hello".toUpperCase());
# Stack order for CallMethod (bottom to top): arg_count, object, method_name

# Push argument count (0.0 as float)
zero_float = 0.0
action_push_zero = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', zero_float)

# Push the object string "hello"
string1 = b'hello\x00'
action_push_string = struct.pack('<BHB', 0x96, len(string1) + 1, 0)
action_push_string += string1

# Push method name "toUpperCase"
method_name = b'toUpperCase\x00'
action_push_method = struct.pack('<BHB', 0x96, len(method_name) + 1, 0)
action_push_method += method_name

# CallMethod action (0x52)
action_call_method = bytes([0x52])

# Trace the result
action_trace = bytes([0x26])

action_end = bytes([0x00])

# Combine all actions
actions = (action_push_zero + action_push_string + action_push_method +
           action_call_method + action_trace + action_end)

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
print('Test: trace("hello".toUpperCase());')
print("Expected output: HELLO")
