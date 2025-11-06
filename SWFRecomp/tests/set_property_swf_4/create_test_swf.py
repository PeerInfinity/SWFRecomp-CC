#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with SET_PROPERTY actions
# This test sets various MovieClip properties using the SET_PROPERTY opcode (0x23)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode to test SET_PROPERTY
# We'll set several properties on _root and trace completion

actions = b''

# Test 1: Set _root._x = 100
# PUSH "_root" (target path)
target = b'_root\x00'
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 0 (property index for _x)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 0)  # PUSH float (type=1)

# PUSH 100 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 100)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Test 2: Set _root._y = 200
# PUSH "_root"
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 1 (property index for _y)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 1)  # PUSH float (type=1)

# PUSH 200 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 200)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Test 3: Set _root._xscale = 50
# PUSH "_root"
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 2 (property index for _xscale)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 2)  # PUSH float (type=1)

# PUSH 50 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 50)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Test 4: Set _root._yscale = 150
# PUSH "_root"
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 3 (property index for _yscale)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 3)  # PUSH float (type=1)

# PUSH 150 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 150)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Test 5: Set _root._alpha = 75
# PUSH "_root"
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 6 (property index for _alpha)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 6)  # PUSH float (type=1)

# PUSH 75 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 75)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Test 6: Set _root._rotation = 45
# PUSH "_root"
actions += struct.pack('<BHB', 0x96, len(target) + 1, 0) + target  # PUSH string

# PUSH 10 (property index for _rotation)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 10)  # PUSH float (type=1)

# PUSH 45 (value)
actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 45)  # PUSH float (type=1)

# SET_PROPERTY (0x23)
actions += bytes([0x23])

# Trace completion message
completion_msg = b'SET_PROPERTY tests completed\x00'
actions += struct.pack('<BHB', 0x96, len(completion_msg) + 1, 0) + completion_msg
actions += bytes([0x26])  # TRACE

# END action
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
print("Test sets the following MovieClip properties:")
print("  _root._x = 100")
print("  _root._y = 200")
print("  _root._xscale = 50")
print("  _root._yscale = 150")
print("  _root._alpha = 75")
print("  _root._rotation = 45")
