#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with WaitForFrame2 opcode
# Test case: Check if frame 1 is loaded
# Since our implementation assumes all frames are loaded, it should not skip

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for a float
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(value))

# Helper function to create PUSH action for a string
def push_string(value):
    str_bytes = value.encode('utf-8') + b'\x00'
    length = 1 + len(str_bytes)  # 1 byte for type + string + null terminator
    return struct.pack('<BH', 0x96, length) + bytes([0]) + str_bytes

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Helper function to create WaitForFrame2 action
def wait_for_frame2(skip_count):
    # WaitForFrame2 opcode is 0x8D with length 1 (for skip_count parameter)
    return struct.pack('<BHB', 0x8D, 1, skip_count)

# Build action sequence for test case
actions = b''

# Test: Check if frame 1 is loaded
# Push frame number
actions += push_float(1.0)

# WaitForFrame2 with skip count of 1
# If frame NOT loaded, skip the next 1 action (the first trace)
# If frame IS loaded, continue normally
actions += wait_for_frame2(1)

# This trace should execute only if frame is loaded
actions += push_string("Frame 1 loaded")
actions += trace()

# This trace should always execute
actions += push_string("Continued")
actions += trace()

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
print("Test case:")
print("  WaitForFrame2 checks if frame 1 is loaded")
print("  Expected output (assuming all frames loaded):")
print("    Frame 1 loaded")
print("    Continued")
