#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with division operations
# Tests ActionDivide (0x0D) with various cases including division by zero

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

def create_push_float(value):
    """Create a PUSH action for a float value"""
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)

def create_divide_trace():
    """Create divide (0x0D) and trace (0x26) actions"""
    return bytes([0x0D, 0x26])

# Stack order: Push dividend first, then divisor
# Result = dividend / divisor

# Test Case 1: Basic Division (15 / 3 = 5)
test1 = create_push_float(15.0) + create_push_float(3.0) + create_divide_trace()

# Test Case 2: Floating Point Result (10 / 4 = 2.5)
test2 = create_push_float(10.0) + create_push_float(4.0) + create_divide_trace()

# Test Case 3: Division by Zero (5 / 0 = #ERROR# in SWF4)
test3 = create_push_float(5.0) + create_push_float(0.0) + create_divide_trace()

# Test Case 4: Negative Division by Zero (-5 / 0 = #ERROR# in SWF4)
test4 = create_push_float(-5.0) + create_push_float(0.0) + create_divide_trace()

# Test Case 5: Zero Divided by Zero (0 / 0 = #ERROR# in SWF4)
test5 = create_push_float(0.0) + create_push_float(0.0) + create_divide_trace()

# Test Case 6: Fractional Division (1 / 3 = 0.333333...)
test6 = create_push_float(1.0) + create_push_float(3.0) + create_divide_trace()

# End action (0x00)
action_end = bytes([0x00])

# Combine all test cases
all_tests = test1 + test2 + test3 + test4 + test5 + test6 + action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_tests)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_tests

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
print("Test cases (SWF 4):")
print("  1. trace(15 / 3) = 5")
print("  2. trace(10 / 4) = 2.5")
print("  3. trace(5 / 0) = #ERROR#")
print("  4. trace(-5 / 0) = #ERROR#")
print("  5. trace(0 / 0) = #ERROR#")
print("  6. trace(1 / 3) = 0.333333...")
