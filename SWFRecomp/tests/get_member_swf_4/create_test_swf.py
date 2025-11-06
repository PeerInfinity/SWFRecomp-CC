#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file that tests the GET_MEMBER opcode (0x4E)
# Test Case: Access the "length" property of a string

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for:
# var x = "Hello";
# trace(x.length);  // Should output: 5

# Test 1: String length property
# Push string "Hello"
string1 = b'Hello\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH action, length, type=0 (string)
action_push1 += string1

# Push property name "length"
prop_name = b'length\x00'
action_push2 = struct.pack('<BHB', 0x96, len(prop_name) + 1, 0)  # PUSH action
action_push2 += prop_name

# GET_MEMBER (0x4E) - pops property name, pops object, pushes property value
action_get_member = bytes([0x4E])

# Trace the result (should be 5)
action_trace = bytes([0x26])

# Test 2: Access undefined property
# Push string "World"
string2 = b'World\x00'
action_push3 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)
action_push3 += string2

# Push property name "xyz" (doesn't exist)
prop_name2 = b'xyz\x00'
action_push4 = struct.pack('<BHB', 0x96, len(prop_name2) + 1, 0)
action_push4 += prop_name2

# GET_MEMBER again
action_get_member2 = bytes([0x4E])

# Trace the result (should be "undefined")
action_trace2 = bytes([0x26])

# END action
action_end = bytes([0x00])

# Combine all actions
actions = (action_push1 + action_push2 + action_get_member + action_trace +
           action_push3 + action_push4 + action_get_member2 + action_trace2 +
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
print("Expected output:")
print("5")
print("undefined")
