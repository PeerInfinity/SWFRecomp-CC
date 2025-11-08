#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file to test GET_VARIABLE opcode (0x1C)
# Test cases:
# 1. Get existing numeric variable: var x = 42; trace(x); -> 42
# 2. Get existing string variable: var name = "hello"; trace(name); -> hello
# 3. Get after assignment: var x = 10; var y = x; trace(y); -> 10

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for a float
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(value))

# Helper function to create PUSH action for a string
def push_string(value):
    str_bytes = value.encode('utf-8') + b'\x00'
    length = 1 + len(str_bytes)  # 1 byte for type + string + null terminator
    return struct.pack('<BH', 0x96, length) + bytes([0]) + str_bytes

# Helper function to create SET_VARIABLE action
def set_variable():
    return bytes([0x1D])  # SET_VARIABLE opcode

# Helper function to create GET_VARIABLE action
def get_variable():
    return bytes([0x1C])  # GET_VARIABLE opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# Test 1: Get existing numeric variable
# var x = 42;
# trace(x);
actions += push_string("x")         # Push variable name FIRST
actions += push_float(42.0)         # Push value SECOND (top of stack)
actions += set_variable()           # Set variable
actions += push_string("x")         # Push variable name
actions += get_variable()           # Get variable value
actions += trace()                  # Trace the result

# Test 2: Get existing string variable
# var name = "hello";
# trace(name);
actions += push_string("name")      # Push variable name FIRST
actions += push_string("hello")     # Push value SECOND (top of stack)
actions += set_variable()           # Set variable
actions += push_string("name")      # Push variable name
actions += get_variable()           # Get variable value
actions += trace()                  # Trace the result

# Test 3: Get after assignment
# var x = 10;
# var y = x;
# trace(y);
actions += push_string("x")         # Push variable name FIRST
actions += push_float(10.0)         # Push value SECOND (top of stack)
actions += set_variable()           # Set variable x = 10
actions += push_string("x")         # Push variable name
actions += get_variable()           # Get x value
actions += push_string("y")         # Push variable name for y FIRST
actions += set_variable()           # Set variable y = x (x value is on stack)
actions += push_string("y")         # Push variable name
actions += get_variable()           # Get variable value
actions += trace()                  # Trace the result

# End of actions
actions += bytes([0x00])  # END action

# DoAction tag
tag_code_and_length = (12 << 6) | 0x3F  # DoAction tag (code 12), long format
action_length = len(actions)
tag_header = struct.pack('<H', tag_code_and_length) + struct.pack('<I', action_length)
do_action_tag = tag_header + actions

# SetBackgroundColor tag (white background)
bg_color = bytes([0x43, 0x02, 0xFF, 0xFF, 0xFF])  # RGB white

# ShowFrame tag
show_frame = bytes([0x40, 0x00])  # ShowFrame tag (code 1)

# End tag
end_tag = bytes([0x00, 0x00])

# Combine all tags
tags = bg_color + do_action_tag + show_frame + end_tag

# File size (will be updated)
file_size = 8 + len(rect_data) + len(frame_rate) + len(frame_count) + len(tags)

# Write SWF file
header = signature + bytes([version]) + struct.pack('<I', file_size) + rect_data + frame_rate + frame_count

with open('test.swf', 'wb') as f:
    f.write(header + tags)

print(f"Created test.swf ({file_size} bytes)")
print("Test cases:")
print("  1. var x = 42; trace(x) -> expected: 42")
print("  2. var name = 'hello'; trace(name) -> expected: hello")
print("  3. var x = 10; var y = x; trace(y) -> expected: 10")
