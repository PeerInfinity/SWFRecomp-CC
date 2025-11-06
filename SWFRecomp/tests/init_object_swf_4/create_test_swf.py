#!/usr/bin/env python3
"""
Test script for INIT_OBJECT opcode (0x43)

This creates a simple SWF that tests object creation with properties.

Test Case 1: Empty object
  var obj = {};
  trace(typeof(obj));
  Expected output: "object"

Test Case 2: Object with properties
  var obj2 = {x: 10, y: 20};
  trace(obj2);  // Will just show the object type for now
  Expected output: [object Object] or similar
"""

import struct

# Create a minimal SWF4 file with INIT_OBJECT tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Test Case 1: Create empty object and check typeof
# Push 0 (number of properties)
action_push_0 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH action, length, type=1 (float)
action_push_0 += struct.pack('<f', 0.0)  # 0 properties
actions += action_push_0

# InitObject - creates empty object and pushes to stack
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# Duplicate the object reference so we can use it twice
action_duplicate = bytes([0x3D])  # DUPLICATE (0x3D)
actions += action_duplicate

# SetVariable - store in variable "obj"
string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string
action_push_obj_name += string_obj
actions += action_push_obj_name
action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# typeof(obj) - the object is still on stack from duplicate
action_typeof = bytes([0x3C])  # TYPEOF (0x3C)
actions += action_typeof

# trace(typeof result)
action_trace = bytes([0x26])  # TRACE (0x26)
actions += action_trace

# Test Case 2: Create object with two properties {x: 10, y: 20}
# For InitObject, stack order is: [... valueN, nameN, ..., value1, name1, count]
# So for {x: 10, y: 20}, we push: [20, "y", 10, "x", 2]

# Push property "x": value
action_push_10 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_10 += struct.pack('<f', 10.0)
actions += action_push_10

# Push property "x": name
string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH string
action_push_x += string_x
actions += action_push_x

# Push property "y": value
action_push_20 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_20 += struct.pack('<f', 20.0)
actions += action_push_20

# Push property "y": name
string_y = b'y\x00'
action_push_y = struct.pack('<BHB', 0x96, len(string_y) + 1, 0)  # PUSH string
action_push_y += string_y
actions += action_push_y

# Push count (2 properties)
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

# InitObject - creates object with properties
actions += action_init_object

# Duplicate and store in variable "obj2"
actions += action_duplicate
string_obj2 = b'obj2\x00'
action_push_obj2_name = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0)
action_push_obj2_name += string_obj2
actions += action_push_obj2_name
actions += action_set_variable

# typeof(obj2)
actions += action_typeof
actions += action_trace

# Test Case 3: Trace a message to separate the tests
string_test_complete = b'InitObject tests complete\x00'
action_push_msg = struct.pack('<BHB', 0x96, len(string_test_complete) + 1, 0)
action_push_msg += string_test_complete
actions += action_push_msg
actions += action_trace

# End action
action_end = bytes([0x00])
actions += action_end

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
print("Test cases:")
print("  1. Empty object: var obj = {}; trace(typeof(obj));")
print("  2. Object with properties: var obj2 = {x: 10, y: 20}; trace(typeof(obj2));")
print("Expected output:")
print("  object")
print("  object")
print("  InitObject tests complete")
