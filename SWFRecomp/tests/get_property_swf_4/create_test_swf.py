#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file with GET_PROPERTY tests for all 22 properties
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing GET_PROPERTY
actions = b''

# Property indices to test (all 22 properties)
property_tests = [
    (0, "_x"),
    (1, "_y"),
    (2, "_xscale"),
    (3, "_yscale"),
    (4, "_currentframe"),
    (5, "_totalframes"),
    (6, "_alpha"),
    (7, "_visible"),
    (8, "_width"),
    (9, "_height"),
    (10, "_rotation"),
    (11, "_target"),
    (12, "_framesloaded"),
    (13, "_name"),
    (14, "_droptarget"),
    (15, "_url"),
    (16, "_highquality"),
    (17, "_focusrect"),
    (18, "_soundbuftime"),
    (19, "_quality"),
    (20, "_xmouse"),
    (21, "_ymouse"),
]

# GET_PROPERTY opcode (0x22)
action_get_property = bytes([0x22])

# TRACE opcode (0x26)
action_trace = bytes([0x26])

# For each property, test GET_PROPERTY
for prop_index, prop_name in property_tests:
    # Push target path "" (empty string refers to current MovieClip / _root)
    target = b'\x00'  # Empty string
    action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)  # PUSH action, length, type=0 (string)
    action_push_target += target

    # Push property index
    prop_index_val = struct.pack('<f', float(prop_index))  # Float value
    action_push_index = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5 (1 byte type + 4 bytes float), type=1 (float)
    action_push_index += prop_index_val

    # Add to actions
    actions += action_push_target + action_push_index + action_get_property + action_trace

# END action
action_end = bytes([0x00])
actions += action_end

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

print(f"Created test.swf ({len(swf_data)} bytes) with tests for all 22 properties")
