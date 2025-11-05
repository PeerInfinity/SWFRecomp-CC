#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with bitwise left shift operations
# Tests multiple cases of the << operator (0x63)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action
def push_float(value):
    """Create a PUSH action for a float value"""
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)

# ActionScript bytecode for multiple left shift tests
actions = b''

# Test 1: trace(1 << 3) = 8
# Stack order: push value (1), push shift_count (3), lshift
actions += push_float(1.0)    # Push value first
actions += push_float(3.0)    # Push shift count second
actions += bytes([0x63])      # BIT_LSHIFT operation
actions += bytes([0x26])      # TRACE

# Test 2: trace(5 << 2) = 20
actions += push_float(5.0)    # Push value
actions += push_float(2.0)    # Push shift count
actions += bytes([0x63])      # BIT_LSHIFT
actions += bytes([0x26])      # TRACE

# Test 3: trace(1 << 33) = 2 (33 & 0x1F = 1)
actions += push_float(1.0)    # Push value
actions += push_float(33.0)   # Push shift count (will be masked to 1)
actions += bytes([0x63])      # BIT_LSHIFT
actions += bytes([0x26])      # TRACE

# Test 4: trace(42 << 0) = 42
actions += push_float(42.0)   # Push value
actions += push_float(0.0)    # Push shift count
actions += bytes([0x63])      # BIT_LSHIFT
actions += bytes([0x26])      # TRACE

# Test 5: trace(1 << 31) = -2147483648 (shift into sign bit)
actions += push_float(1.0)    # Push value
actions += push_float(31.0)   # Push shift count
actions += bytes([0x63])      # BIT_LSHIFT
actions += bytes([0x26])      # TRACE

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
print("Expected output:")
print("8")
print("20")
print("2")
print("42")
print("-2147483648")
