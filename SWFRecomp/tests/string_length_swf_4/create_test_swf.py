#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with STRING_LENGTH opcode tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH string action
def push_string(s):
    string_bytes = s.encode('ascii') + b'\x00'  # Null-terminated
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes

# Test 1: Basic string - length("hello") → 5
test1 = b''
test1 += push_string("hello")      # Push string
test1 += bytes([0x14])             # STRING_LENGTH opcode
test1 += bytes([0x26])             # TRACE

# Test 2: Empty string - length("") → 0
test2 = b''
test2 += push_string("")           # Push empty string
test2 += bytes([0x14])             # STRING_LENGTH opcode
test2 += bytes([0x26])             # TRACE

# Test 3: String with spaces - length("hello world") → 11
test3 = b''
test3 += push_string("hello world")  # Push string with spaces
test3 += bytes([0x14])             # STRING_LENGTH opcode
test3 += bytes([0x26])             # TRACE

# Combine all tests
actions = test1 + test2 + test3
action_end = bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions + action_end)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions + action_end

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
print("Expected output:")
print("5")
print("0")
print("11")
