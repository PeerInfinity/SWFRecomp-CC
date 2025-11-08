#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with ADD operations
# Test cases covering basic arithmetic, type conversion, and edge cases:
# 1. Basic integer: 5 + 3 = 8
# 2. Floating point: 2.5 + 1.5 = 4
# 3. String conversion: "10" + 5 = 15
# 4. Zero addition: 0 + 42 = 42
# 5. Negative numbers: -5 + 10 = 5
# 6. Mixed float/int: 7.5 + 2 = 9.5
# 7. Large numbers: 1000000 + 500000 = 1500000
# 8. Small decimals: 0.001 + 0.002 = 0.003
# 9. Negative result: -10 + 3 = -7
# 10. Double negative: -5 + -5 = -10
# 11. Non-numeric string: "hello" + 5 = 5 (atof("hello") = 0)

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

# Helper function to create add action
def add():
    return bytes([0x0A])  # ADD opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# Test 1: Basic integer 5 + 3 = 8
actions += push_float(3.0)  # Push second operand first (stack order matters)
actions += push_float(5.0)  # Push first operand
actions += add()
actions += trace()

# Test 2: Floating point 2.5 + 1.5 = 4
actions += push_float(1.5)
actions += push_float(2.5)
actions += add()
actions += trace()

# Test 3: String conversion "10" + 5 = 15
actions += push_float(5.0)
actions += push_string("10")
actions += add()
actions += trace()

# Test 4: Zero addition 0 + 42 = 42
actions += push_float(42.0)
actions += push_float(0.0)
actions += add()
actions += trace()

# Test 5: Negative numbers -5 + 10 = 5
actions += push_float(10.0)
actions += push_float(-5.0)
actions += add()
actions += trace()

# Test 6: Mixed float/int 7.5 + 2 = 9.5
actions += push_float(2.0)
actions += push_float(7.5)
actions += add()
actions += trace()

# Test 7: Large numbers 1000000 + 500000 = 1500000
actions += push_float(500000.0)
actions += push_float(1000000.0)
actions += add()
actions += trace()

# Test 8: Small decimals 0.001 + 0.002 = 0.003
actions += push_float(0.002)
actions += push_float(0.001)
actions += add()
actions += trace()

# Test 9: Negative result -10 + 3 = -7
actions += push_float(3.0)
actions += push_float(-10.0)
actions += add()
actions += trace()

# Test 10: Double negative -5 + -5 = -10
actions += push_float(-5.0)
actions += push_float(-5.0)
actions += add()
actions += trace()

# Test 11: NaN case "hello" + 5 = NaN
actions += push_float(5.0)
actions += push_string("hello")
actions += add()
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
print("  1. 5 + 3 = 8 (basic integer)")
print("  2. 2.5 + 1.5 = 4 (floating point)")
print("  3. \"10\" + 5 = 15 (string conversion)")
print("  4. 0 + 42 = 42 (zero addition)")
print("  5. -5 + 10 = 5 (negative numbers)")
print("  6. 7.5 + 2 = 9.5 (mixed float/int)")
print("  7. 1000000 + 500000 = 1500000 (large numbers)")
print("  8. 0.001 + 0.002 = 0.003 (small decimals)")
print("  9. -10 + 3 = -7 (negative result)")
print(" 10. -5 + -5 = -10 (double negative)")
print(" 11. \"hello\" + 5 = 5 (non-numeric string becomes 0)")