#\!/usr/bin/env python3
import struct

# Create a minimal SWF5 file that tests DELETE2 opcode (0x3B)
# Test Cases:
# 1. Delete non-existent property -> should return 1 (true)
# 2. Delete property after setting (if implementation supports)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create a PUSH action for a string value
def push_string(s):
    s_bytes = s.encode('ascii') + b'\x00'  # Null-terminated string
    length = len(s_bytes) + 1  # +1 for the type byte
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

# ActionScript bytecode
actions = b''

# Test Case 1: Delete non-existent property
# According to Flash spec, deleting a non-existent property returns true
# Push "nonExistent" (property name to delete)
actions += push_string("nonExistent")
# Delete2 (0x3B) - pops name, searches scope chain, pushes result
actions += bytes([0x3B])
# Trace (0x26) - pops and prints the result
actions += bytes([0x26])

# End action (0x00)
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
print("Test case:")
print("  1. delete nonExistent -> 1 (true - Flash returns true for non-existent)")
