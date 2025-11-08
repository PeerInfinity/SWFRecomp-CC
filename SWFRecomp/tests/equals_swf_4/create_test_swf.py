#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with EQUALS operations
# Test cases:
# 1. Equal numbers: 5 == 5 = 1 (true)
# 2. Unequal numbers: 5 == 3 = 0 (false)
# 3. Zero comparison: 0 == 0 = 1 (true)
# 4. Different numbers: 10 == 20 = 0 (false)
# 5. Negative comparison: -5 == -5 = 1 (true)

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

# Test Case 1: trace(5 == 5) = 1
test1 = push_float(5.0) + push_float(5.0) + bytes([0x0E]) + bytes([0x26])

# Test Case 2: trace(5 == 3) = 0
test2 = push_float(5.0) + push_float(3.0) + bytes([0x0E]) + bytes([0x26])

# Test Case 3: trace(0 == 0) = 1
test3 = push_float(0.0) + push_float(0.0) + bytes([0x0E]) + bytes([0x26])

# Test Case 4: trace(10 == 20) = 0
test4 = push_float(10.0) + push_float(20.0) + bytes([0x0E]) + bytes([0x26])

# Test Case 5: trace(-5 == -5) = 1
test5 = push_float(-5.0) + push_float(-5.0) + bytes([0x0E]) + bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = test1 + test2 + test3 + test4 + test5 + action_end
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

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test cases:")
print("  1. trace(5 == 5) = 1")
print("  2. trace(5 == 3) = 0")
print("  3. trace(0 == 0) = 1")
print("  4. trace(10 == 20) = 0")
print("  5. trace(-5 == -5) = 1")
