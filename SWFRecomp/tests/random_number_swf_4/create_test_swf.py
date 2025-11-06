#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file to test the random number opcode (0x30)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing random number generation
actions = b''

# Test Case 1: random(0) - should return 0
string_test1 = b'Test 1 - random(0): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test1) + 1, 0)
actions += string_test1
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0
actions += struct.pack('<f', 0.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 2: random(1) - should return 0
string_test2 = b'Test 2 - random(1): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test2) + 1, 0)
actions += string_test2
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 1.0
actions += struct.pack('<f', 1.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 3: random(10) - should return 0-9
string_test3 = b'Test 3 - random(10): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test3) + 1, 0)
actions += string_test3
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 10.0
actions += struct.pack('<f', 10.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 4: random(100) - should return 0-99
string_test4 = b'Test 4 - random(100): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test4) + 1, 0)
actions += string_test4
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 100.0
actions += struct.pack('<f', 100.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 5: random(1000) - should return 0-999
string_test5 = b'Test 5 - random(1000): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test5) + 1, 0)
actions += string_test5
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 1000.0
actions += struct.pack('<f', 1000.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

# Test Case 6: random(-5) - should return 0 (negative max)
string_test6 = b'Test 6 - random(-5): \x00'
actions += struct.pack('<BHB', 0x96, len(string_test6) + 1, 0)
actions += string_test6
actions += bytes([0x26])  # TRACE
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float -5.0
actions += struct.pack('<f', -5.0)
actions += bytes([0x30])  # RANDOM_NUMBER (0x30)
actions += bytes([0x26])  # TRACE (trace the result)

actions += bytes([0x00])  # END action

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
