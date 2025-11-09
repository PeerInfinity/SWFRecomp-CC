#!/usr/bin/env python3
"""
Test script for WITH opcode (0x94)

This creates a simple SWF that tests the WITH statement.

Test Case: Basic with statement
  var obj = {x: 10, y: 20};
  with (obj) {
      trace(x); // Should output: 10
      trace(y); // Should output: 20
  }
  Expected output:
    10
    20
"""

import struct

# Create a minimal SWF5 file with WITH test
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
# Test Case: Basic with statement
# var obj = {x: 10, y: 20};
# with (obj) { trace(x); trace(y); }
# ====================================================================

# Step 1: Create object with two properties {x: 10, y: 20}
# For InitObject, stack order is: [value1, name1, value2, name2, count]
# So for {x: 10, y: 20}, we push: [10, "x", 20, "y", 2]

# Push property "x": value (10)
action_push_10 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_10 += struct.pack('<f', 10.0)
actions += action_push_10

# Push property "x": name
string_x = b'x\x00'
action_push_x = struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH string
action_push_x += string_x
actions += action_push_x

# Push property "y": value (20)
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
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# Step 2: Store object in variable "obj"
# SetVariable expects stack: [name, value] with value on top
# After InitObject, stack is: [object]
# We need: ["obj", object]
# Solution: Push name, then use StackSwap (0x4D) to swap top two items

string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string "obj"
action_push_obj_name += string_obj
actions += action_push_obj_name
# Stack is now: [object, "obj"]

# Use StackSwap to get ["obj", object]
action_stack_swap = bytes([0x4D])  # StackSwap (0x4D)
actions += action_stack_swap
# Stack is now: ["obj", object]

# SetVariable consumes the stack correctly
action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# Step 3: Build the WITH block
# The WITH block needs to:
# 1. Push "x" variable name and get variable (should resolve to obj.x = 10)
# 2. Trace the result
# 3. Push "y" variable name and get variable (should resolve to obj.y = 20)
# 4. Trace the result

with_block = b''

# trace(x) - inside WITH block, "x" should resolve to obj.x
with_block += struct.pack('<BHB', 0x96, len(string_x) + 1, 0)  # PUSH "x"
with_block += string_x
with_block += bytes([0x1C])  # GET_VARIABLE (0x1C)
with_block += bytes([0x26])  # TRACE (0x26)

# trace(y) - inside WITH block, "y" should resolve to obj.y
with_block += struct.pack('<BHB', 0x96, len(string_y) + 1, 0)  # PUSH "y"
with_block += string_y
with_block += bytes([0x1C])  # GET_VARIABLE (0x1C)
with_block += bytes([0x26])  # TRACE (0x26)

# Step 4: Build WITH action
# WITH format: 0x94 (opcode), UI16 length, UI16 block_size, actions[block_size]
with_block_size = len(with_block)
with_length = 2 + with_block_size  # 2 bytes for block_size + block content

action_with = bytes([0x94])  # WITH opcode (0x94)
action_with += struct.pack('<H', with_length)  # Length field (UI16)
action_with += struct.pack('<H', with_block_size)  # Block size (UI16)
action_with += with_block  # The actual actions

# The object should be pushed again for WITH to consume
string_obj_get = b'obj\x00'
action_push_obj_get = struct.pack('<BHB', 0x96, len(string_obj_get) + 1, 0)  # PUSH string
action_push_obj_get += string_obj_get
actions += action_push_obj_get
actions += bytes([0x1C])  # GET_VARIABLE to push the object

# Now add the WITH action
actions += action_with

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
print("Test case:")
print("  var obj = {x: 10, y: 20};")
print("  with (obj) {")
print("    trace(x);")
print("    trace(y);")
print("  }")
print("Expected output:")
print("  10")
print("  20")
