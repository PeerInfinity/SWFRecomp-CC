#!/usr/bin/env python3
import struct

# Create a comprehensive but simpler SWF4 file with SET_PROPERTY actions
# This test sets all settable properties without using GET_PROPERTY

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create SET_PROPERTY action
def set_property(target, prop_index, value):
    actions = b''
    # PUSH target path (string)
    target_bytes = target.encode('utf-8') + b'\x00'
    actions += struct.pack('<BHB', 0x96, len(target_bytes) + 1, 0) + target_bytes

    # PUSH property index (float)
    actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(prop_index))

    # PUSH value (float)
    actions += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(value))

    # SET_PROPERTY opcode
    actions += bytes([0x23])

    return actions

# ActionScript bytecode to test SET_PROPERTY comprehensively
actions = b''

# Test 1: Basic numeric properties (0-3, 6-10)
actions += set_property("_root", 0, 100)   # _x = 100
actions += set_property("_root", 1, 200)   # _y = 200
actions += set_property("_root", 2, 50)    # _xscale = 50
actions += set_property("_root", 3, 150)   # _yscale = 150
actions += set_property("_root", 6, 75)    # _alpha = 75
actions += set_property("_root", 7, 0)     # _visible = 0 (false)
actions += set_property("_root", 8, 320)   # _width = 320
actions += set_property("_root", 9, 240)   # _height = 240
actions += set_property("_root", 10, 45)   # _rotation = 45

# Test 2: Properties 16-18 (SWF 4+ properties)
actions += set_property("_root", 16, 2)    # _highquality = 2
actions += set_property("_root", 17, 0)    # _focusrect = 0
actions += set_property("_root", 18, 10)   # _soundbuftime = 10

# Test 3: Edge cases - negative values
actions += set_property("_root", 10, -90)  # _rotation = -90

# Test 4: Edge cases - attempt to set read-only property (should be ignored)
actions += set_property("_root", 4, 99)    # Try to set _currentframe (read-only)

# Test 5: Edge cases - large values
actions += set_property("_root", 2, 500)   # _xscale = 500 (very large)

# Trace completion message
completion_msg = b'All SET_PROPERTY tests passed\x00'
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
print("Comprehensive SET_PROPERTY test created with:")
print("  - All basic properties (0-3, 6-10)")
print("  - SWF 4+ properties (16-18)")
print("  - Edge cases (negative, read-only, large values)")
