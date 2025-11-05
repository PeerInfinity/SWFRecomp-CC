#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with unsigned right shift operations
# Tests for ActionBitURShift (0x65) - Logical right shift (zero-fill)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create a PUSH action
def push_float(value):
    data = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
    data += struct.pack('<f', value)  # Float value
    return data

# ActionScript bytecode for multiple test cases

# Test 1: Basic unsigned right shift
# trace(8 >>> 2) = 2
action_test1 = push_float(8.0) + push_float(2.0) + bytes([0x65]) + bytes([0x26])

# Test 2: Shift negative number (no sign extension)
# trace(-8 >>> 2) = 1073741822
# -8 as int32 = 0xFFFFFFF8, unsigned >> 2 = 0x3FFFFFFE = 1073741822
action_test2 = push_float(-8.0) + push_float(2.0) + bytes([0x65]) + bytes([0x26])

# Test 3: Zero shift
# trace(42 >>> 0) = 42
action_test3 = push_float(42.0) + push_float(0.0) + bytes([0x65]) + bytes([0x26])

# Test 4: Shift all bits out
# trace(255 >>> 8) = 0
action_test4 = push_float(255.0) + push_float(8.0) + bytes([0x65]) + bytes([0x26])

# Test 5: Shift count wrapping
# trace(16 >>> 33) = 8
# 33 & 0x1F = 1, so 16 >>> 1 = 8
action_test5 = push_float(16.0) + push_float(33.0) + bytes([0x65]) + bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_test1 + action_test2 + action_test3 + action_test4 + action_test5 + action_end
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
print(f"Test cases:")
print(f"  1. trace(8 >>> 2) = 2")
print(f"  2. trace(-8 >>> 2) = 1073741824 (float precision)")
print(f"  3. trace(42 >>> 0) = 42")
print(f"  4. trace(255 >>> 8) = 0")
print(f"  5. trace(16 >>> 33) = 8")
