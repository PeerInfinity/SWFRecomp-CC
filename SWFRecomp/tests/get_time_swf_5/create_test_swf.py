#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file to test the GetTime opcode (0x34)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing GetTime opcode
actions = b''

# Test Case 1: Get time (should return milliseconds since runtime start)
string_test1 = b'Time (ms): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test1) + 1, 0)
actions += string_test1
actions += bytes([0x26])  # TRACE
actions += bytes([0x34])  # GET_TIME (0x34)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 2: Get time again to verify it's >= first time
actions += bytes([0x34])  # GET_TIME (0x34) - get a second time value
actions += bytes([0x26])  # TRACE

actions += bytes([0x00])  # END action

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
