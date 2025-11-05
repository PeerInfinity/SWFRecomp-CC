#!/usr/bin/env python3
import struct

# Minimal test: just one comparison
# trace(5 === 5) should output 1

# SWF Header
signature = b'FWS'
version = 4
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Push 5.0
push_5a = struct.pack('<BHB', 0x96, 5, 1)
push_5a += struct.pack('<f', 5.0)

# Push 5.0
push_5b = struct.pack('<BHB', 0x96, 5, 1)
push_5b += struct.pack('<f', 5.0)

# StrictEquals (0x66)
strict_equals = bytes([0x66])

# Trace (0x26)
trace = bytes([0x26])

# End (0x00)
end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_data = push_5a + push_5b + strict_equals + trace + end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)

# End tag
end_tag = bytes([0x00, 0x00])

# Build SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_minimal.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_minimal.swf ({len(swf_data)} bytes)")
print("Test: trace(5 === 5) = 1")
