#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with MULTIPLY operations
# Test cases covering basic arithmetic, edge cases:
# 1. Basic multiplication: 5 * 3 = 15
# 2. Floating point: 2.5 * 4 = 10
# 3. Multiply by zero: 42 * 0 = 0
# 4. Negative numbers: -3 * 7 = -21
# 5. Very large numbers: 1e200 * 1e200 = Infinity

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

# Helper function to create multiply action
def multiply():
    return bytes([0x0C])  # MULTIPLY opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# Test 1: Basic multiplication 5 * 3 = 15
actions += push_float(3.0)  # Push second operand first (stack order matters)
actions += push_float(5.0)  # Push first operand
actions += multiply()
actions += trace()

# Test 2: Floating point 2.5 * 4 = 10
actions += push_float(4.0)
actions += push_float(2.5)
actions += multiply()
actions += trace()

# Test 3: Multiply by zero 42 * 0 = 0
actions += push_float(0.0)
actions += push_float(42.0)
actions += multiply()
actions += trace()

# Test 4: Negative numbers -3 * 7 = -21
actions += push_float(7.0)
actions += push_float(-3.0)
actions += multiply()
actions += trace()

# Test 5: Very large numbers 1e38 * 1e38 = Infinity
# (Maximum float32 is about 3.4e38, so this will overflow to infinity)
actions += push_float(1e38)
actions += push_float(1e38)
actions += multiply()
actions += trace()

# End action
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
print("  1. 5 * 3 = 15 (basic multiplication)")
print("  2. 2.5 * 4 = 10 (floating point)")
print("  3. 42 * 0 = 0 (multiply by zero)")
print("  4. -3 * 7 = -21 (negative numbers)")
print("  5. 1e38 * 1e38 = Infinity (very large numbers overflow)")
