#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with strict equals (===) tests - NUMERIC ONLY
# Test cases:
# 1. trace(5 === 5) = 1 (true)
# 2. trace(5 === 3) = 0 (false)
# 3. trace(7 === 7) = 1 (true)
# 4. trace(3 === 7) = 0 (false)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test 1: trace(5 === 5)
test1_push_5a = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
test1_push_5a += struct.pack('<f', 5.0)

test1_push_5b = struct.pack('<BHB', 0x96, 5, 1)
test1_push_5b += struct.pack('<f', 5.0)

action_strict_equals = bytes([0x66])
action_trace = bytes([0x26])

test1 = test1_push_5a + test1_push_5b + action_strict_equals + action_trace

# Test 2: trace(5 === 3)
test2_push_5 = struct.pack('<BHB', 0x96, 5, 1)
test2_push_5 += struct.pack('<f', 5.0)

test2_push_3 = struct.pack('<BHB', 0x96, 5, 1)
test2_push_3 += struct.pack('<f', 3.0)

test2 = test2_push_5 + test2_push_3 + action_strict_equals + action_trace

# Test 3: trace(7 === 7)
test3_push_7a = struct.pack('<BHB', 0x96, 5, 1)
test3_push_7a += struct.pack('<f', 7.0)

test3_push_7b = struct.pack('<BHB', 0x96, 5, 1)
test3_push_7b += struct.pack('<f', 7.0)

test3 = test3_push_7a + test3_push_7b + action_strict_equals + action_trace

# Test 4: trace(3 === 7)
test4_push_3 = struct.pack('<BHB', 0x96, 5, 1)
test4_push_3 += struct.pack('<f', 3.0)

test4_push_7 = struct.pack('<BHB', 0x96, 5, 1)
test4_push_7 += struct.pack('<f', 7.0)

test4 = test4_push_3 + test4_push_7 + action_strict_equals + action_trace

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = test1 + test2 + test3 + test4 + action_end
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

with open('test_numeric.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_numeric.swf ({len(swf_data)} bytes)")
print("Test cases (numeric only):")
print("  trace(5 === 5) = 1 (true)")
print("  trace(5 === 3) = 0 (false)")
print("  trace(7 === 7) = 1 (true)")
print("  trace(3 === 7) = 0 (false)")
