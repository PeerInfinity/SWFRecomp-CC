#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with bit right shift operations
# Test cases for BIT_RSHIFT (0x64) opcode

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test Case 1: 8 >> 2 = 2
# Stack order: Push VALUE first, then SHIFT_COUNT (becomes top)
print("Test 1: 8 >> 2 = 2")
test1_push_8 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 8.0)
test1_push_2 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 2.0)
test1_rshift = bytes([0x64])
test1_trace = bytes([0x26])

# Test Case 2: 20 >> 2 = 5
print("Test 2: 20 >> 2 = 5")
test2_push_20 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 20.0)
test2_push_2 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 2.0)
test2_rshift = bytes([0x64])
test2_trace = bytes([0x26])

# Test Case 3: -8 >> 2 = -2 (sign extension)
print("Test 3: -8 >> 2 = -2")
test3_push_neg8 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', -8.0)
test3_push_2 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 2.0)
test3_rshift = bytes([0x64])
test3_trace = bytes([0x26])

# Test Case 4: 42 >> 0 = 42
print("Test 4: 42 >> 0 = 42")
test4_push_42 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 42.0)
test4_push_0 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 0.0)
test4_rshift = bytes([0x64])
test4_trace = bytes([0x26])

# Test Case 5: 16 >> 33 = 8 (33 & 0x1F = 1, so 16 >> 1 = 8)
print("Test 5: 16 >> 33 = 8 (shift count wraps to 1)")
test5_push_16 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 16.0)
test5_push_33 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 33.0)
test5_rshift = bytes([0x64])
test5_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# Build complete action sequence
do_action_data = (
    test1_push_8 + test1_push_2 + test1_rshift + test1_trace +
    test2_push_20 + test2_push_2 + test2_rshift + test2_trace +
    test3_push_neg8 + test3_push_2 + test3_rshift + test3_trace +
    test4_push_42 + test4_push_0 + test4_rshift + test4_trace +
    test5_push_16 + test5_push_33 + test5_rshift + test5_trace +
    action_end
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

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

print(f"\nCreated test.swf ({len(swf_data)} bytes)")
print("Expected output:")
print("2")
print("5")
print("-2")
print("42")
print("8")
