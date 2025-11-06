#!/usr/bin/env python3
"""
Test script for DELETE2 opcode (0x5B)

This creates a simple SWF that tests property deletion using delete operator.

Test Case 1: Delete existing property
  var obj = {x: 10, y: 20, z: 30};
  var result = delete obj.y;
  trace(result);  // 1 (true)
  trace(obj.y);   // undefined
  trace(obj.x);   // 10

Test Case 2: Delete non-existent property
  var obj = {a: 1};
  var result = delete obj.missing;
  trace(result);  // 1 (true - Flash returns true for non-existent)

Test Case 3: Simple delete test
  Create object {foo: 100, bar: 200}
  Delete "bar"
  Verify bar is undefined and foo is still 100
"""

import struct

# Create a minimal SWF5 file with DELETE2 tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # DELETE2 is SWF5+ feature

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# ===== Test Case 1: Delete existing property =====
# Create object {x: 10, y: 20, z: 30}
# Stack order for InitObject: [value1, name1, value2, name2, value3, name3, count]
# We push in order: 10, "x", 20, "y", 30, "z", 3

# Push x: 10
action_push_10 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_10 += struct.pack('<f', 10.0)
actions += action_push_10

# Push "x"
string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH string
action_push_x += string_x
actions += action_push_x

# Push y: 20
action_push_20 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_20 += struct.pack('<f', 20.0)
actions += action_push_20

# Push "y"
string_y = b'y\x00'
action_push_y = struct.pack('<BHB', 0x96, len(string_y) + 1, 0)
action_push_y += string_y
actions += action_push_y

# Push z: 30
action_push_30 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_30 += struct.pack('<f', 30.0)
actions += action_push_30

# Push "z"
string_z = b'z\x00'
action_push_z = struct.pack('<BHB', 0x96, len(string_z) + 1, 0)
action_push_z += string_z
actions += action_push_z

# Push count: 3
action_push_3 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

# InitObject (0x43) - creates object with 3 properties
action_init_object = bytes([0x43])
actions += action_init_object

# Duplicate object reference for later use
action_duplicate = bytes([0x3D])
actions += action_duplicate

# Store in variable "obj" (need to dup again)
actions += action_duplicate
string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)
action_push_obj_name += string_obj
actions += action_push_obj_name
action_set_variable = bytes([0x1D])  # SET_VARIABLE
actions += action_set_variable

# Now delete obj.y
# Stack for DELETE2: [object, property_name]
# Object is already on stack from duplicate above
# Push property name "y"
actions += action_push_y

# DELETE2 (0x5B) - pops property name and object, pushes result (1.0 or 0.0)
action_delete2 = bytes([0x5B])
actions += action_delete2

# Trace result (should be 1)
action_trace = bytes([0x26])
actions += action_trace

# Now verify obj.y is undefined
# Get variable "obj"
actions += action_push_obj_name
action_get_variable = bytes([0x1C])  # GET_VARIABLE
actions += action_get_variable

# Push "y" and get member
actions += action_push_y
action_get_member = bytes([0x4E])  # GET_MEMBER
actions += action_get_member

# Trace obj.y (should be undefined)
actions += action_trace

# Verify obj.x is still 10
# Get variable "obj"
actions += action_push_obj_name
actions += action_get_variable

# Push "x" and get member
actions += action_push_x
actions += action_get_member

# Trace obj.x (should be 10)
actions += action_trace

# ===== Test Case 2: Delete non-existent property =====
# Create object {a: 1}
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0)
action_push_a += string_a
actions += action_push_a

# Push count: 1
actions += action_push_1

# InitObject
actions += action_init_object

# Push property name "missing"
string_missing = b'missing\x00'
action_push_missing = struct.pack('<BHB', 0x96, len(string_missing) + 1, 0)
action_push_missing += string_missing
actions += action_push_missing

# DELETE2 - should return 1 (true) even for non-existent
actions += action_delete2

# Trace result (should be 1)
actions += action_trace

# ===== Test Case 3: Simple test with two properties =====
# Create object {foo: 100, bar: 200}
action_push_100 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_100 += struct.pack('<f', 100.0)
actions += action_push_100

string_foo = b'foo\x00'
action_push_foo = struct.pack('<BHB', 0x96, len(string_foo) + 1, 0)
action_push_foo += string_foo
actions += action_push_foo

action_push_200 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_200 += struct.pack('<f', 200.0)
actions += action_push_200

string_bar = b'bar\x00'
action_push_bar = struct.pack('<BHB', 0x96, len(string_bar) + 1, 0)
action_push_bar += string_bar
actions += action_push_bar

# Push count: 2
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

# InitObject
actions += action_init_object

# Dup for later
actions += action_duplicate

# Store in "obj2"
actions += action_duplicate
string_obj2 = b'obj2\x00'
action_push_obj2 = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0)
action_push_obj2 += string_obj2
actions += action_push_obj2
actions += action_set_variable

# Delete bar
actions += action_push_bar
actions += action_delete2

# Trace delete result
actions += action_trace

# Verify bar is undefined
actions += action_push_obj2
actions += action_get_variable
actions += action_push_bar
actions += action_get_member
actions += action_trace

# Verify foo is still 100
actions += action_push_obj2
actions += action_get_variable
actions += action_push_foo
actions += action_get_member
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
print("  1. Delete existing property 'y' from {x:10, y:20, z:30}")
print("     Expected: 1 (delete succeeded), undefined (y is gone), 10 (x still exists)")
print("  2. Delete non-existent property 'missing'")
print("     Expected: 1 (returns true for non-existent)")
print("  3. Delete 'bar' from {foo:100, bar:200}")
print("     Expected: 1 (delete succeeded), undefined (bar is gone), 100 (foo still exists)")
print("")
print("Expected output:")
print("1")
print("undefined")
print("10")
print("1")
print("1")
print("undefined")
print("100")
