#!/usr/bin/env python3
import struct

# Minimal test - just create an array and trace "DONE"

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

def push_string(s):
    """Helper to create PUSH string action"""
    return struct.pack('<BHB', 0x96, 1 + len(s) + 1, 0) + s.encode('ascii') + b'\x00'

def push_float(f):
    """Helper to create PUSH float action"""
    return struct.pack('<BHBf', 0x96, 5, 1, f)

# Opcodes
OP_POP = 0x17
OP_TRACE = 0x26
OP_NEW_OBJECT = 0x40
OP_END = 0x00

# Test: create array, pop it, trace "DONE"
test = b''
test += push_float(5.0)              # Push argument: 5.0 (array length)
test += push_float(1.0)              # Push numArgs: 1
test += push_string("Array")         # Push constructor name
test += bytes([OP_NEW_OBJECT])       # Create array
test += bytes([OP_POP])              # Pop the array
test += push_string("DONE")          # Push message
test += bytes([OP_TRACE])            # Trace
test += bytes([OP_END])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(test)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + test

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_minimal.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_minimal.swf ({len(swf_data)} bytes)")
print("Expected output: DONE")
