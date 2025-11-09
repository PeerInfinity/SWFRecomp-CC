#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file with NEW_OBJECT operations
# Tests: Array constructor with length, Array with elements, Object constructor, edge cases

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

def push_string(s):
    """Helper to create PUSH string action"""
    return struct.pack('<BHB', 0x96, 1 + len(s) + 1, 0) + s.encode('ascii') + b'\x00'

def push_float(f):
    """Helper to create PUSH float action"""
    return struct.pack('<BHBf', 0x96, 5, 1, f)

# Opcodes
OP_PUSH = 0x96
OP_POP = 0x17
OP_TRACE = 0x26
OP_NEW_OBJECT = 0x40
OP_GET_MEMBER = 0x4E
OP_SET_MEMBER = 0x4F
OP_END = 0x00

# Test 1: new Array(5) - creates array with length 5, then check length property
test1 = b''
# Create: var arr1 = new Array(5);
test1 += push_float(5.0)              # Push argument: 5.0 (array length)
test1 += push_float(1.0)              # Push numArgs: 1
test1 += push_string("Array")         # Push constructor name
test1 += bytes([OP_NEW_OBJECT])       # Create array -> stack: [array]
# Duplicate array for later use
test1 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [array, array]
# Get length: trace(arr1.length);
test1 += push_string("length")        # Push property name -> stack: [array, array, "length"]
test1 += bytes([OP_GET_MEMBER])       # Get arr1.length -> stack: [array, length_value]
test1 += bytes([OP_TRACE])            # Trace the length -> stack: [array]
test1 += bytes([OP_POP])              # Pop the array -> stack: []

# Test 2: new Array(10, 20, 30) - creates array with elements [10, 20, 30]
test2 = b''
# Create array with 3 elements
test2 += push_float(10.0)             # Push arg1 (first element)
test2 += push_float(20.0)             # Push arg2 (second element)
test2 += push_float(30.0)             # Push arg3 (third element)
test2 += push_float(3.0)              # Push numArgs: 3
test2 += push_string("Array")         # Push constructor name
test2 += bytes([OP_NEW_OBJECT])       # Create array with elements -> stack: [array]
# Duplicate array reference
test2 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [array, array]
# Check length
test2 += push_string("length")        # Push property name -> stack: [array, array, "length"]
test2 += bytes([OP_GET_MEMBER])       # Get arr2.length -> stack: [array, 3]
test2 += bytes([OP_TRACE])            # Trace the length (should be 3) -> stack: [array]
test2 += bytes([OP_POP])              # Pop the array -> stack: []

# Test 3: new Array(10, 20, 30) - verify first element
test3 = b''
# Create array with 3 elements
test3 += push_float(10.0)             # Push arg1
test3 += push_float(20.0)             # Push arg2
test3 += push_float(30.0)             # Push arg3
test3 += push_float(3.0)              # Push numArgs: 3
test3 += push_string("Array")         # Push constructor name
test3 += bytes([OP_NEW_OBJECT])       # Create array -> stack: [array]
# Duplicate array reference
test3 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [array, array]
# Get element [0]
test3 += push_string("0")             # Push index "0" -> stack: [array, array, "0"]
test3 += bytes([OP_GET_MEMBER])       # Get arr[0] -> stack: [array, 10]
test3 += bytes([OP_TRACE])            # Trace first element (should be 10) -> stack: [array]
test3 += bytes([OP_POP])              # Pop the array -> stack: []

# Test 4: new Object() - creates empty object, then set and get property
test4 = b''
# Create: var obj = new Object();
test4 += push_float(0.0)              # Push numArgs: 0
test4 += push_string("Object")        # Push constructor name
test4 += bytes([OP_NEW_OBJECT])       # Create object -> stack: [object]
# Duplicate for SET_MEMBER (which will consume it)
test4 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [object, object]
# Set property: obj.x = 42;
test4 += push_string("x")             # Push property name -> stack: [object, object, "x"]
test4 += push_float(42.0)             # Push value: 42 -> stack: [object, object, "x", 42]
test4 += bytes([OP_SET_MEMBER])       # Set obj.x = 42 -> stack: [object]
# Get property: trace(obj.x);
test4 += push_string("x")             # Push property name -> stack: [object, "x"]
test4 += bytes([OP_GET_MEMBER])       # Get obj.x -> stack: [42]
test4 += bytes([OP_TRACE])            # Trace the value (should be 42) -> stack: []

# Test 5: new Array() - creates empty array (no arguments)
test5 = b''
test5 += push_float(0.0)              # Push numArgs: 0
test5 += push_string("Array")         # Push constructor name
test5 += bytes([OP_NEW_OBJECT])       # Create empty array -> stack: [array]
# Duplicate array reference
test5 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [array, array]
# Check length
test5 += push_string("length")        # Push property name -> stack: [array, array, "length"]
test5 += bytes([OP_GET_MEMBER])       # Get arr.length -> stack: [array, 0]
test5 += bytes([OP_TRACE])            # Trace the length (should be 0) -> stack: [array]
test5 += bytes([OP_POP])              # Pop the array -> stack: []

# Test 6: new Array(0) - creates array with length 0
test6 = b''
test6 += push_float(0.0)              # Push argument: 0 (array length)
test6 += push_float(1.0)              # Push numArgs: 1
test6 += push_string("Array")         # Push constructor name
test6 += bytes([OP_NEW_OBJECT])       # Create array with length 0 -> stack: [array]
# Duplicate array reference
test6 += bytes([0x4C])                # PUSH_DUPLICATE -> stack: [array, array]
# Check length
test6 += push_string("length")        # Push property name -> stack: [array, array, "length"]
test6 += bytes([OP_GET_MEMBER])       # Get arr.length -> stack: [array, 0]
test6 += bytes([OP_TRACE])            # Trace the length (should be 0) -> stack: [array]
test6 += bytes([OP_POP])              # Pop the array -> stack: []

# Build complete action sequence
action_sequence = (
    test1 + test2 + test3 + test4 + test5 + test6 +
    bytes([OP_END])
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(action_sequence)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_sequence

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
print("  1. new Array(5) - verify length is 5")
print("  2. new Array(10, 20, 30) - verify length is 3")
print("  3. new Array(10, 20, 30) - verify first element is 10")
print("  4. new Object() - set and get property x=42")
print("  5. new Array() - verify empty array has length 0")
print("  6. new Array(0) - verify array with length 0")
print("Expected output:")
print("  5")
print("  3")
print("  10")
print("  42")
print("  0")
print("  0")
