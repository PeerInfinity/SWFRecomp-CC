#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with bitwise OR operations
# Test cases:
# 1. 12 | 10 = 14 (1100 | 1010 = 1110)
# 2. 42 | 0 = 42 (identity)
# 3. 10 | 15 = 15 (1010 | 1111 = 1111)
# 4. 1 | 2 | 4 = 7 (001 | 010 | 100 = 111)
# 5. 0xFF00 | 0x00FF = 65535 (0xFFFF)

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

# Helper function to create bit_or action
def bit_or():
    return bytes([0x61])  # BIT_OR opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# Test 1: 12 | 10 = 14
actions += push_float(10.0)  # Push second operand first (stack order)
actions += push_float(12.0)  # Push first operand
actions += bit_or()
actions += trace()

# Test 2: 42 | 0 = 42
actions += push_float(0.0)
actions += push_float(42.0)
actions += bit_or()
actions += trace()

# Test 3: 10 | 15 = 15
actions += push_float(15.0)
actions += push_float(10.0)
actions += bit_or()
actions += trace()

# Test 4: 1 | 2 | 4 = 7 (chained operations)
# First: 1 | 2 = 3
actions += push_float(2.0)
actions += push_float(1.0)
actions += bit_or()
# Then: 3 | 4 = 7
actions += push_float(4.0)
actions += bit_or()
actions += trace()

# Test 5: 0xFF00 | 0x00FF = 65535
actions += push_float(0x00FF)  # 255
actions += push_float(0xFF00)  # 65280
actions += bit_or()
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
print("  12 | 10 = 14")
print("  42 | 0 = 42")
print("  10 | 15 = 15")
print("  1 | 2 | 4 = 7")
print("  0xFF00 | 0x00FF = 65535")
