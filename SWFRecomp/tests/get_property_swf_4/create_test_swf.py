#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with GET_PROPERTY tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing GET_PROPERTY
actions = b''

# Test 1: Get _xscale (property index 2)
# Push target path "" (empty string refers to current MovieClip / _root)
target = b'\x00'  # Empty string
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)  # PUSH action, length, type=0 (string)
action_push_target += target

# Push property index 2 (_xscale)
prop_index = struct.pack('<f', 2.0)  # Float value 2.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5 (1 byte type + 4 bytes float), type=1 (float)
action_push_index += prop_index

# GET_PROPERTY opcode (0x22)
action_get_property = bytes([0x22])

# TRACE opcode (0x26)
action_trace = bytes([0x26])

# Add Test 1
actions += action_push_target + action_push_index + action_get_property + action_trace

# Test 2: Get _yscale (property index 3)
target = b'\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)
action_push_target += target

prop_index = struct.pack('<f', 3.0)  # Float value 3.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)
action_push_index += prop_index

actions += action_push_target + action_push_index + action_get_property + action_trace

# Test 3: Get _visible (property index 7)
target = b'\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)
action_push_target += target

prop_index = struct.pack('<f', 7.0)  # Float value 7.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)
action_push_index += prop_index

actions += action_push_target + action_push_index + action_get_property + action_trace

# Test 4: Get _alpha (property index 6)
target = b'\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)
action_push_target += target

prop_index = struct.pack('<f', 6.0)  # Float value 6.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)
action_push_index += prop_index

actions += action_push_target + action_push_index + action_get_property + action_trace

# Test 5: Get _x (property index 0)
target = b'\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)
action_push_target += target

prop_index = struct.pack('<f', 0.0)  # Float value 0.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)
action_push_index += prop_index

actions += action_push_target + action_push_index + action_get_property + action_trace

# Test 6: Get _y (property index 1)
target = b'\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target) + 1, 0)
action_push_target += target

prop_index = struct.pack('<f', 1.0)  # Float value 1.0
action_push_index = struct.pack('<BHB', 0x96, 5, 1)
action_push_index += prop_index

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

print(f"Created test.swf ({len(swf_data)} bytes)")
