#\!/usr/bin/env python3
"""
Test script for DELETE opcode (0x3A)

This creates a SWF that tests property deletion from objects.

Test Case 1: Delete existing property
  var obj = {a: 1, b: 2, c: 3};
  var result = delete obj.b;
  trace(result);  // Expected: 1 (true)
  trace(obj.b);   // Expected: undefined

Test Case 2: Delete non-existent property
  var obj2 = {x: 10};
  var result2 = delete obj2.xyz;
  trace(result2); // Expected: 1 (true, AS2 spec)
"""

import struct

# Create a minimal SWF5 file with DELETE tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # DELETE requires SWF5+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Test Case 1: Delete existing property
# Create object {a: 1, b: 2, c: 3}
# For InitObject, stack order is: [... valueN, nameN, ..., value1, name1, count]
# We push: [1, "a", 2, "b", 3, "c", 3]

# Push property "a": value
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

# Push property "a": name
string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0)  # PUSH string
action_push_a += string_a
actions += action_push_a

# Push property "b": value
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

# Push property "b": name
string_b = b'b\x00'
action_push_b = struct.pack('<BHB', 0x96, len(string_b) + 1, 0)  # PUSH string
action_push_b += string_b
actions += action_push_b

# Push property "c": value
action_push_3 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

# Push property "c": name
string_c = b'c\x00'
action_push_c = struct.pack('<BHB', 0x96, len(string_c) + 1, 0)  # PUSH string
action_push_c += string_c
actions += action_push_c

# Push count (3 properties)
action_push_count = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_count += struct.pack('<f', 3.0)
actions += action_push_count

# InitObject - creates object with properties
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# Store object in variable "obj"
# Duplicate object so we can use it later
action_duplicate = bytes([0x4C])  # DUPLICATE (0x4C)
actions += action_duplicate

string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string
action_push_obj_name += string_obj
actions += action_push_obj_name

action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# Now delete property "b" from "obj"
# DELETE opcode (0x3A) expects:
# - Top of stack: property name (string)
# - Second: object name (string - variable name)

# Push object name "obj"
actions += action_push_obj_name  # Reuse the same push

# Push property name "b"
actions += action_push_b  # Reuse the same push

# DELETE (0x3A) - deletes property, pushes success boolean
action_delete = bytes([0x3A])  # DELETE (0x3A)
actions += action_delete

# Trace the result (should be 1 for success)
action_trace = bytes([0x26])  # TRACE (0x26)
actions += action_trace

# Now try to access obj.b (should be undefined)
# GET_VARIABLE to get the object
actions += action_push_obj_name  # Push "obj"
action_get_variable = bytes([0x1C])  # GET_VARIABLE (0x1C)
actions += action_get_variable

# Push property name "b"
actions += action_push_b

# GET_MEMBER (0x4E) - get property value
action_get_member = bytes([0x4E])  # GET_MEMBER (0x4E)
actions += action_get_member

# Trace the result (should be "undefined")
actions += action_trace

# Test Case 2: Delete non-existent property
# Create object {x: 10}

# Push property "x": value
action_push_10 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_10 += struct.pack('<f', 10.0)
actions += action_push_10

# Push property "x": name
string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH string
action_push_x += string_x
actions += action_push_x

# Push count (1 property)
action_push_1_count = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_1_count += struct.pack('<f', 1.0)
actions += action_push_1_count

# InitObject
actions += action_init_object

# Store in variable "obj2"
string_obj2 = b'obj2\x00'
action_push_obj2_name = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0)
action_push_obj2_name += string_obj2
actions += action_push_obj2_name
actions += action_set_variable

# Delete non-existent property "xyz"
actions += action_push_obj2_name  # Push "obj2"

string_xyz = b'xyz\x00'
action_push_xyz = struct.pack('<BHB', 0x96, len(string_xyz) + 1, 0)
action_push_xyz += string_xyz
actions += action_push_xyz

# DELETE
actions += action_delete

# Trace result (should be 1, AS2 spec returns true for non-existent)
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
print("  1. Delete existing property 'b' from obj: delete obj.b")
print("  2. Access deleted property: obj.b (should be undefined)")
print("  3. Delete non-existent property: delete obj2.xyz")
print("Expected output:")
print("  1")
print("  undefined")
print("  1")
