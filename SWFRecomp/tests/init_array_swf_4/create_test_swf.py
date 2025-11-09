#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file with InitArray operations
# Tests: Empty array, simple array, mixed-type array, array.length, array element access

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for float
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)

# Helper function to create PUSH action for string
def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(s_bytes) + 1, 0) + s_bytes

# Helper function to create GET_MEMBER (0x4E) action
def get_member():
    return bytes([0x4E])

# Helper function to create TRACE (0x26) action
def trace():
    return bytes([0x26])

# Helper function to create DUPLICATE (0x4C) action
def duplicate():
    return bytes([0x4C])

# Test 1: Empty array [] - check length
actions = []
actions.append(push_float(0.0))  # Push count = 0
actions.append(bytes([0x42]))    # InitArray
actions.append(push_string("length"))  # Push property name
actions.append(get_member())     # Get array.length
actions.append(trace())          # Trace the length (should be 0)

# Test 2: Simple array [1, 2, 3] - check length and elements
# Per SWF spec: push elements in reverse order (rightmost first, leftmost last)
actions.append(push_float(3.0))  # Push 3 (rightmost element -> arr[2])
actions.append(push_float(2.0))  # Push 2 (middle element -> arr[1])
actions.append(push_float(1.0))  # Push 1 (leftmost element -> arr[0])
actions.append(push_float(3.0))  # count = 3
actions.append(bytes([0x42]))    # InitArray
actions.append(duplicate())      # Duplicate (array on stack twice)

# Check length
actions.append(push_string("length"))
actions.append(get_member())     # Get array.length
actions.append(trace())          # Trace the length (should be 3)

# Check element [0]
actions.append(duplicate())      # Duplicate array
actions.append(push_string("0"))
actions.append(get_member())     # Get array[0]
actions.append(trace())          # Trace (should be 1)

# Check element [1]
actions.append(duplicate())      # Duplicate array
actions.append(push_string("1"))
actions.append(get_member())     # Get array[1]
actions.append(trace())          # Trace (should be 2)

# Check element [2]
actions.append(duplicate())      # Duplicate array
actions.append(push_string("2"))
actions.append(get_member())     # Get array[2]
actions.append(trace())          # Trace (should be 3)

# Pop the array
actions.append(bytes([0x17]))    # Pop

# Test 3: Mixed-type array ["hello", 42, "world"]
# Push in reverse order: rightmost first
actions.append(push_string("world"))  # Push "world" (rightmost -> arr[2])
actions.append(push_float(42.0))      # Push 42 (middle -> arr[1])
actions.append(push_string("hello"))  # Push "hello" (leftmost -> arr[0])
actions.append(push_float(3.0))       # count = 3
actions.append(bytes([0x42]))         # InitArray
actions.append(duplicate())           # Duplicate

# Check element [0] - should be "hello"
actions.append(duplicate())      # Duplicate array
actions.append(push_string("0"))
actions.append(get_member())     # Get array[0]
actions.append(trace())          # Trace (should be "hello")

# Check element [1] - should be 42
actions.append(duplicate())      # Duplicate array
actions.append(push_string("1"))
actions.append(get_member())     # Get array[1]
actions.append(trace())          # Trace (should be 42)

# Check element [2] - should be "world"
actions.append(push_string("2"))
actions.append(get_member())     # Get array[2]
actions.append(trace())          # Trace (should be "world")

# Pop array
actions.append(bytes([0x17]))    # Pop

# Test 4: Out of bounds access
actions.append(push_float(5.0))  # elem_1
actions.append(push_float(1.0))  # count = 1
actions.append(bytes([0x42]))    # InitArray -> [5]
actions.append(duplicate())      # Duplicate

# Try to access element [10] (out of bounds)
actions.append(push_string("10"))
actions.append(get_member())     # Get array[10] -> should be undefined
actions.append(trace())          # Trace (should be "undefined")

# Pop array
actions.append(bytes([0x17]))    # Pop

# End action (0x00)
actions.append(bytes([0x00]))

# Build complete action sequence
action_sequence = b''.join(actions)

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
print("Comprehensive InitArray tests:")
print("  Test 1: Empty array [] - check length")
print("  Test 2: Simple array [1, 2, 3] - check length and elements")
print("  Test 3: Mixed-type array ['hello', 42, 'world'] - check elements")
print("  Test 4: Out of bounds access - check undefined")
print()
print("Expected output:")
print("0")
print("3")
print("1")
print("2")
print("3")
print("hello")
print("42")
print("world")
print("undefined")
