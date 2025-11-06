#!/usr/bin/env python3
import struct

# Create a test SWF4 file for SET_MEMBER opcode
# Test: Create object {x: 10}, set x = 20, trace x
# Expected output: 20

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Step 1: Create object {x: 10} using InitObject
# Push initial value (10)
value_10 = struct.pack('<f', 10.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
actions += value_10

# Push property name ("x")
prop_name_x = b'x\x00'
actions += struct.pack('<BHB', 0x96, len(prop_name_x) + 1, 0)  # PUSH action, type=0 (string)
actions += prop_name_x

# Push number of properties (1)
num_props = struct.pack('<f', 1.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
actions += num_props

# InitObject (0x43)
actions += bytes([0x43])

# Step 2: Duplicate object (so we can use it for both SET_MEMBER and GET_MEMBER)
actions += bytes([0x3D])  # DUPLICATE (0x3D)

# Step 3: Set property x = 20 using SetMember
# The stack now has: [obj, obj]
# We need: [obj, "x", 20] for SET_MEMBER

# Push property name ("x")
actions += struct.pack('<BHB', 0x96, len(prop_name_x) + 1, 0)  # PUSH action, type=0 (string)
actions += prop_name_x

# Push new value (20)
value_20 = struct.pack('<f', 20.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
actions += value_20

# SetMember (0x4F)
actions += bytes([0x4F])

# Step 4: Get property x using GetMember and trace it
# The stack now has: [obj]
# Push property name ("x")
actions += struct.pack('<BHB', 0x96, len(prop_name_x) + 1, 0)  # PUSH action, type=0 (string)
actions += prop_name_x

# GetMember (0x4E)
actions += bytes([0x4E])

# Trace (0x26)
actions += bytes([0x26])

# End action
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
print("Expected output: 20")
