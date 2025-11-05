#!/usr/bin/env python3
import struct

# Test with exactly 2 comparisons
# 1. trace(5 === 5) = 1
# 2. trace(5 === 3) = 0

signature = b'FWS'
version = 4
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

action_strict_equals = bytes([0x66])
action_trace = bytes([0x26])

# Test 1: 5 === 5
test1 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 5.0) + \
        struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 5.0) + \
        action_strict_equals + action_trace

# Test 2: 5 === 3
test2 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 5.0) + \
        struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 3.0) + \
        action_strict_equals + action_trace

action_end = bytes([0x00])

do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_data = test1 + test2 + action_end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_two.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_two.swf ({len(swf_data)} bytes)")
