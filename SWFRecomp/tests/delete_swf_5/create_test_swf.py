#!/usr/bin/env python3
"""
Test script for DELETE opcode (0x3A)

This creates a simple SWF that tests property deletion from objects.

Test Case 1: Delete existing property
  var obj = {a: 1, b: 2, c: 3};
  var result = delete obj.b;
  trace(result); // 1

Test Case 2: Delete non-existent property
  var obj2 = {a: 1};
  var result2 = delete obj2.xyz;
  trace(result2); // 1 (returns true even for non-existent)

Test Case 3: Delete from non-existent object
  var result3 = delete noobj.prop;
  trace(result3); // 1 (returns true even if object doesn't exist)
"""

import struct

# Create a minimal SWF5 file with DELETE tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # Use SWF version 5 for DELETE opcode

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# ===== Test Case 1: Delete existing property =====
# Create object {a: 1, b: 2, c: 3}

# Push property "a": value (1.0)
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

# Push property "a": name
string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0)  # PUSH string
action_push_a += string_a
actions += action_push_a

# Push property "b": value (2.0)
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

# Push property "b": name
string_b = b'b\x00'
action_push_b = struct.pack('<BHB', 0x96, len(string_b) + 1, 0)  # PUSH string
action_push_b += string_b
actions += action_push_b

# Push property "c": value (3.0)
action_push_3 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

# Push property "c": name
string_c = b'c\x00'
action_push_c = struct.pack('<BHB', 0x96, len(string_c) + 1, 0)  # PUSH string
action_push_c += string_c
actions += action_push_c

# Push count (3 properties)
action_push_3_count = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_3_count += struct.pack('<f', 3.0)
actions += action_push_3_count

# InitObject - creates object with properties
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# SetVariable - store in variable "obj"
string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string
action_push_obj_name += string_obj
actions += action_push_obj_name
action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# Now delete obj.b using DELETE opcode
# Stack order: push object name, then property name

# Push object name "obj"
action_push_obj_name2 = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string
action_push_obj_name2 += string_obj
actions += action_push_obj_name2

# Push property name "b"
action_push_b2 = struct.pack('<BHB', 0x96, len(string_b) + 1, 0)  # PUSH string
action_push_b2 += string_b
actions += action_push_b2

# DELETE opcode (0x3A)
action_delete = bytes([0x3A])  # DELETE (0x3A)
actions += action_delete

# Trace the result (should be 1.0)
action_trace = bytes([0x26])  # TRACE (0x26)
actions += action_trace

# ===== Test Case 2: Delete non-existent property =====
# Create object {a: 1}

# Push property "a": value (1.0)
actions += action_push_1

# Push property "a": name
actions += action_push_a

# Push count (1 property)
action_push_1_count = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_1_count += struct.pack('<f', 1.0)
actions += action_push_1_count

# InitObject
actions += action_init_object

# SetVariable - store in variable "obj2"
string_obj2 = b'obj2\x00'
action_push_obj2_name = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0)  # PUSH string
action_push_obj2_name += string_obj2
actions += action_push_obj2_name
actions += action_set_variable

# Delete obj2.xyz (non-existent property)
# Push object name "obj2"
action_push_obj2_name2 = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0)  # PUSH string
action_push_obj2_name2 += string_obj2
actions += action_push_obj2_name2

# Push property name "xyz"
string_xyz = b'xyz\x00'
action_push_xyz = struct.pack('<BHB', 0x96, len(string_xyz) + 1, 0)  # PUSH string
action_push_xyz += string_xyz
actions += action_push_xyz

# DELETE opcode
actions += action_delete

# Trace the result (should be 1.0)
actions += action_trace

# ===== Test Case 3: Delete from non-existent object =====
# Try to delete noobj.prop (where noobj doesn't exist)

# Push object name "noobj"
string_noobj = b'noobj\x00'
action_push_noobj = struct.pack('<BHB', 0x96, len(string_noobj) + 1, 0)  # PUSH string
action_push_noobj += string_noobj
actions += action_push_noobj

# Push property name "prop"
string_prop = b'prop\x00'
action_push_prop = struct.pack('<BHB', 0x96, len(string_prop) + 1, 0)  # PUSH string
action_push_prop += string_prop
actions += action_push_prop

# DELETE opcode
actions += action_delete

# Trace the result (should be 1.0)
actions += action_trace

# Trace completion message
string_complete = b'DELETE tests complete\x00'
action_push_complete = struct.pack('<BHB', 0x96, len(string_complete) + 1, 0)
action_push_complete += string_complete
actions += action_push_complete
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
print("  1. Delete existing property: var obj = {a:1, b:2, c:3}; delete obj.b")
print("  2. Delete non-existent property: var obj2 = {a:1}; delete obj2.xyz")
print("  3. Delete from non-existent object: delete noobj.prop")
print("Expected output:")
print("  1")
print("  1")
print("  1")
print("  DELETE tests complete")
