#!/usr/bin/env python3
"""
Comprehensive test script for WITH opcode (0x94)

This creates a more thorough SWF that tests various WITH statement scenarios:
1. Basic with statement (original test)
2. Nested with statements
3. Property shadowing (with property vs global variable)

Expected output:
  10
  20
  2
  1
  42
  100
"""

import struct

# Create a minimal SWF5 file with WITH tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # WITH statement requires SWF 5+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# ====================================================================
# Test Case 1: Basic with statement (same as original)
# var obj = {x: 10, y: 20};
# with (obj) { trace(x); trace(y); }
# ====================================================================

# Create object {x: 10, y: 20}
action_push_10 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 10.0)
actions += action_push_10

string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x
actions += action_push_x

action_push_20 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 20.0)
actions += action_push_20

string_y = b'y\x00'
action_push_y = struct.pack('<BHB', 0x96, len(string_y) + 1, 0) + string_y
actions += action_push_y

action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 2.0)
actions += action_push_2

action_init_object = bytes([0x43])  # INIT_OBJECT
actions += action_init_object

# Store in variable "obj"
string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0) + string_obj
actions += action_push_obj_name
action_stack_swap = bytes([0x4D])  # StackSwap
actions += action_stack_swap
action_set_variable = bytes([0x1D])  # SET_VARIABLE
actions += action_set_variable

# WITH block for test case 1
with_block_1 = b''
with_block_1 += struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x
with_block_1 += bytes([0x1C])  # GET_VARIABLE
with_block_1 += bytes([0x26])  # TRACE

with_block_1 += struct.pack('<BHB', 0x96, len(string_y) + 1, 0) + string_y
with_block_1 += bytes([0x1C])  # GET_VARIABLE
with_block_1 += bytes([0x26])  # TRACE

with_block_size_1 = len(with_block_1)
with_length_1 = 2 + with_block_size_1

action_with_1 = bytes([0x94])  # WITH opcode
action_with_1 += struct.pack('<H', with_length_1)
action_with_1 += struct.pack('<H', with_block_size_1)
action_with_1 += with_block_1

# Push obj for WITH to consume
actions += struct.pack('<BHB', 0x96, len(string_obj) + 1, 0) + string_obj
actions += bytes([0x1C])  # GET_VARIABLE
actions += action_with_1

# ====================================================================
# Test Case 2: Nested with statements
# var obj1 = {a: 1};
# var obj2 = {b: 2};
# with (obj1) { with (obj2) { trace(b); trace(a); } }
# Expected: 2, 1
# ====================================================================

# Create obj1 = {a: 1}
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 1.0)
actions += action_push_1

string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0) + string_a
actions += action_push_a

action_push_1_count = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 1.0)
actions += action_push_1_count

action_init_object_1 = bytes([0x43])  # INIT_OBJECT
actions += action_init_object_1

# Store in variable "obj1"
string_obj1 = b'obj1\x00'
action_push_obj1_name = struct.pack('<BHB', 0x96, len(string_obj1) + 1, 0) + string_obj1
actions += action_push_obj1_name
action_stack_swap = bytes([0x4D])
actions += action_stack_swap
action_set_variable = bytes([0x1D])
actions += action_set_variable

# Create obj2 = {b: 2}
action_push_2_val = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 2.0)
actions += action_push_2_val

string_b = b'b\x00'
action_push_b = struct.pack('<BHB', 0x96, len(string_b) + 1, 0) + string_b
actions += action_push_b

action_push_1_count2 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 1.0)
actions += action_push_1_count2

action_init_object_2 = bytes([0x43])
actions += action_init_object_2

# Store in variable "obj2"
string_obj2 = b'obj2\x00'
action_push_obj2_name = struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0) + string_obj2
actions += action_push_obj2_name
action_stack_swap = bytes([0x4D])
actions += action_stack_swap
action_set_variable = bytes([0x1D])
actions += action_set_variable

# Inner WITH block (obj2) - trace(b); trace(a);
inner_with_block = b''
inner_with_block += struct.pack('<BHB', 0x96, len(string_b) + 1, 0) + string_b
inner_with_block += bytes([0x1C])  # GET_VARIABLE
inner_with_block += bytes([0x26])  # TRACE

inner_with_block += struct.pack('<BHB', 0x96, len(string_a) + 1, 0) + string_a
inner_with_block += bytes([0x1C])  # GET_VARIABLE
inner_with_block += bytes([0x26])  # TRACE

inner_with_size = len(inner_with_block)
inner_with_action = bytes([0x94])
inner_with_action += struct.pack('<H', 2 + inner_with_size)
inner_with_action += struct.pack('<H', inner_with_size)
inner_with_action += inner_with_block

# Outer WITH block (obj1) - contains obj2.push + inner WITH
outer_with_block = b''
# Push obj2
outer_with_block += struct.pack('<BHB', 0x96, len(string_obj2) + 1, 0) + string_obj2
outer_with_block += bytes([0x1C])  # GET_VARIABLE
# Inner WITH
outer_with_block += inner_with_action

outer_with_size = len(outer_with_block)
outer_with_action = bytes([0x94])
outer_with_action += struct.pack('<H', 2 + outer_with_size)
outer_with_action += struct.pack('<H', outer_with_size)
outer_with_action += outer_with_block

# Push obj1 for outer WITH
actions += struct.pack('<BHB', 0x96, len(string_obj1) + 1, 0) + string_obj1
actions += bytes([0x1C])  # GET_VARIABLE
actions += outer_with_action

# ====================================================================
# Test Case 3: Property shadowing
# var x = 100;
# var obj = {x: 42};
# with (obj) { trace(x); }  # Should print 42 (obj.x shadows global x)
# trace(x);  # Should print 100 (global x)
# Expected: 42, 100
# ====================================================================

# Set global x = 100
action_push_100 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 100.0)
actions += action_push_100
actions += struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x
action_stack_swap = bytes([0x4D])
actions += action_stack_swap
action_set_variable = bytes([0x1D])
actions += action_set_variable

# Create obj3 = {x: 42}
action_push_42 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 42.0)
actions += action_push_42

actions += struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x

action_push_1_count3 = struct.pack('<BHB', 0x96, 1 + 4, 1) + struct.pack('<f', 1.0)
actions += action_push_1_count3

action_init_object_3 = bytes([0x43])
actions += action_init_object_3

# Store in variable "obj3"
string_obj3 = b'obj3\x00'
action_push_obj3_name = struct.pack('<BHB', 0x96, len(string_obj3) + 1, 0) + string_obj3
actions += action_push_obj3_name
action_stack_swap = bytes([0x4D])
actions += action_stack_swap
action_set_variable = bytes([0x1D])
actions += action_set_variable

# WITH block - trace(x) should get obj3.x = 42
with_block_3 = b''
with_block_3 += struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x
with_block_3 += bytes([0x1C])  # GET_VARIABLE
with_block_3 += bytes([0x26])  # TRACE

with_block_size_3 = len(with_block_3)
action_with_3 = bytes([0x94])
action_with_3 += struct.pack('<H', 2 + with_block_size_3)
action_with_3 += struct.pack('<H', with_block_size_3)
action_with_3 += with_block_3

# Push obj3 for WITH
actions += struct.pack('<BHB', 0x96, len(string_obj3) + 1, 0) + string_obj3
actions += bytes([0x1C])  # GET_VARIABLE
actions += action_with_3

# Now trace global x (should be 100)
actions += struct.pack('<BHB', 0x96, len(string_x) + 1, 0) + string_x
actions += bytes([0x1C])  # GET_VARIABLE
actions += bytes([0x26])  # TRACE

# End action
action_end = bytes([0x00])
actions += action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_comprehensive.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_comprehensive.swf ({len(swf_data)} bytes)")
print("Test cases:")
print("  1. Basic with: obj = {x: 10, y: 20}; with (obj) { trace(x); trace(y); }")
print("  2. Nested with: obj1 = {a: 1}; obj2 = {b: 2}; with (obj1) { with (obj2) { trace(b); trace(a); } }")
print("  3. Shadowing: x = 100; obj3 = {x: 42}; with (obj3) { trace(x); }; trace(x);")
print("Expected output:")
print("  10")
print("  20")
print("  2")
print("  1")
print("  42")
print("  100")
