#\!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with bitwise left shift operations
# Test cases:
# 1. 1 << 3 = 8 (0001 << 3 = 1000)
# 2. 5 << 2 = 20 (5 * 2^2 = 5 * 4 = 20)
# 3. 1 << 33 = 2 (33 & 0x1F = 1, so 1 << 1 = 2, tests 5-bit masking)
# 4. 42 << 0 = 42 (no shift)
# 5. 1 << 31 = -2147483648 (shifts into sign bit)

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

# Helper function to create bit left shift action
def bit_lshift():
    return bytes([0x63])  # BIT_LSHIFT opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# IMPORTANT: Stack order for bit shift operations:
# The implementation pops shift_count first, then value
# So we push: value first (bottom), shift_count second (top)

# Test 1: 1 << 3 = 8
actions += push_float(1.0)   # Push value (bottom of stack)
actions += push_float(3.0)   # Push shift count (top of stack)
actions += bit_lshift()
actions += trace()

# Test 2: 5 << 2 = 20
actions += push_float(5.0)
actions += push_float(2.0)
actions += bit_lshift()
actions += trace()

# Test 3: 1 << 33 = 2 (33 & 0x1F = 1, so 1 << 1 = 2)
actions += push_float(1.0)
actions += push_float(33.0)
actions += bit_lshift()
actions += trace()

# Test 4: 42 << 0 = 42
actions += push_float(42.0)
actions += push_float(0.0)
actions += bit_lshift()
actions += trace()

# Test 5: 1 << 31 = -2147483648 (shifts into sign bit)
actions += push_float(1.0)
actions += push_float(31.0)
actions += bit_lshift()
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
print("  1. 1 << 3 = 8 (basic left shift)")
print("  2. 5 << 2 = 20 (multiply by power of 2)")
print("  3. 1 << 33 = 2 (shift count wrapping with 5-bit mask)")
print("  4. 42 << 0 = 42 (zero shift)")
print("  5. 1 << 31 = -2147483648 (shift into sign bit)")
