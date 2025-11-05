#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with multiple ToNumber action tests
# Tests various type conversions to number

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test cases for ToNumber opcode (0x4A):
# 1. Number input (42.5) - should remain 42.5
# 2. String "123.45" - should parse to 123.45
# 3. Empty string "" - should convert to 0
# 4. String "42" - should parse to 42

actions = b''

# Test 1: Number(42.5) - already a number
# Push 42.5 as a float
float_value = struct.pack('<f', 42.5)
action_push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push += float_value
actions += action_push
actions += bytes([0x4A])  # ToNumber action (0x4A)
actions += bytes([0x26])  # Trace action

# Test 2: Number("123.45") - string to number
# Push "123.45" as a string
test_str = "123.45".encode('ascii') + b'\x00'
action_push_str = struct.pack('<BHB', 0x96, len(test_str) + 1, 0)  # PUSH, type=0 (string)
action_push_str += test_str
actions += action_push_str
actions += bytes([0x4A])  # ToNumber action (0x4A)
actions += bytes([0x26])  # Trace action

# Test 3: Number("") - empty string to 0
# Push "" as a string
empty_str = b'\x00'
action_push_empty = struct.pack('<BHB', 0x96, len(empty_str) + 1, 0)  # PUSH, type=0 (string)
action_push_empty += empty_str
actions += action_push_empty
actions += bytes([0x4A])  # ToNumber action (0x4A)
actions += bytes([0x26])  # Trace action

# Test 4: Number("42") - string to integer
# Push "42" as a string
int_str = "42".encode('ascii') + b'\x00'
action_push_int_str = struct.pack('<BHB', 0x96, len(int_str) + 1, 0)  # PUSH, type=0 (string)
action_push_int_str += int_str
actions += action_push_int_str
actions += bytes([0x4A])  # ToNumber action (0x4A)
actions += bytes([0x26])  # Trace action

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
print("\nTest cases:")
print("1. Number(42.5)     -> Expected: 42.5")
print("2. Number(\"123.45\") -> Expected: 123.45")
print("3. Number(\"\")       -> Expected: 0")
print("4. Number(\"42\")     -> Expected: 42")
