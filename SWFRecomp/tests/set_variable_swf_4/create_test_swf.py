#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file that tests SET_VARIABLE opcode (0x1D)
# Test Cases:
# 1. Set number variable: x = 42, trace(x) -> 42
# 2. Set string variable: name = "Alice", trace(name) -> Alice
# 3. Update variable: y = 10, y = 20, trace(y) -> 20
# 4. Set from expression: z = 5 + 3, trace(z) -> 8

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create a PUSH action for a float value
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)

# Helper function to create a PUSH action for a string value
def push_string(s):
    s_bytes = s.encode('ascii') + b'\x00'  # Null-terminated string
    length = len(s_bytes) + 1  # +1 for the type byte
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

# ActionScript bytecode
actions = b''

# Test Case 1: x = 42; trace(x)
# Push "x" (variable name) - second to pop
actions += push_string("x")
# Push 42.0 (value) - first to pop
actions += push_float(42.0)
# Set variable (0x1D)
actions += bytes([0x1D])
# Push "x" (variable name to get)
actions += push_string("x")
# Get variable (0x1C)
actions += bytes([0x1C])
# Trace (0x26)
actions += bytes([0x26])

# Test Case 2: name = "Alice"; trace(name)
# Push "name" (variable name) - second to pop
actions += push_string("name")
# Push "Alice" (value) - first to pop
actions += push_string("Alice")
# Set variable (0x1D)
actions += bytes([0x1D])
# Push "name" (variable name to get)
actions += push_string("name")
# Get variable (0x1C)
actions += bytes([0x1C])
# Trace (0x26)
actions += bytes([0x26])

# Test Case 3: y = 10; y = 20; trace(y)
# Push "y" (variable name) - second to pop
actions += push_string("y")
# Push 10.0 (first value) - first to pop
actions += push_float(10.0)
# Set variable (0x1D)
actions += bytes([0x1D])
# Push "y" (variable name) - second to pop
actions += push_string("y")
# Push 20.0 (second value - update) - first to pop
actions += push_float(20.0)
# Set variable (0x1D)
actions += bytes([0x1D])
# Push "y" (variable name to get)
actions += push_string("y")
# Get variable (0x1C)
actions += bytes([0x1C])
# Trace (0x26)
actions += bytes([0x26])

# Test Case 4: z = 5 + 3; trace(z)
# Push "z" (variable name) - second to pop
actions += push_string("z")
# Push 5.0
actions += push_float(5.0)
# Push 3.0
actions += push_float(3.0)
# Add (0x0A)
actions += bytes([0x0A])
# Set variable (0x1D) - value (result of 5+3) is now at top
actions += bytes([0x1D])
# Push "z" (variable name to get)
actions += push_string("z")
# Get variable (0x1C)
actions += bytes([0x1C])
# Trace (0x26)
actions += bytes([0x26])

# End action (0x00)
actions += bytes([0x00])

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
print("  1. x = 42; trace(x) -> 42")
print("  2. name = \"Alice\"; trace(name) -> Alice")
print("  3. y = 10; y = 20; trace(y) -> 20")
print("  4. z = 5 + 3; trace(z) -> 8")
