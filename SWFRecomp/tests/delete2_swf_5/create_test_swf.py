#!/usr/bin/env python3
import struct

# Create a SWF5 file that tests DELETE2 opcode (0x3B)
#
# DELETE2 is fully implemented per the SWF specification:
# - Searches scope chain for named property
# - Deletes if found in scope chain objects
# - Cannot delete var declarations (returns false)
# - Returns true for non-existent properties (Flash behavior)
#
# Test Case:
# Delete non-existent property -> should return 1 (true)

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

# Test Case: Delete non-existent property
# According to Flash spec, deleting a non-existent property returns true
actions += push_string("nonExistent")
actions += bytes([0x3B])  # Delete2
actions += bytes([0x26])  # Trace -> Output: 1

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
print("Test case: delete nonExistent -> 1 (true)")
