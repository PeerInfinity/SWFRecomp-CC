#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with CharToAscii (0x32) tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test 1: Single character "A" - should output 65
string1 = b'A\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0) + string1
action_char_to_ascii1 = bytes([0x32])  # CharToAscii opcode
action_trace1 = bytes([0x26])  # Trace

# Test 2: Multiple characters "Hello" - should output 72 (ASCII of 'H')
string2 = b'Hello\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0) + string2
action_char_to_ascii2 = bytes([0x32])
action_trace2 = bytes([0x26])

# Test 3: Special character "!" - should output 33
string3 = b'!\x00'
action_push3 = struct.pack('<BHB', 0x96, len(string3) + 1, 0) + string3
action_char_to_ascii3 = bytes([0x32])
action_trace3 = bytes([0x26])

# Test 4: Empty string - should output NaN
string4 = b'\x00'
action_push4 = struct.pack('<BHB', 0x96, len(string4) + 1, 0) + string4
action_char_to_ascii4 = bytes([0x32])
action_trace4 = bytes([0x26])

# Test 5: Unicode character "é" (0xE9 in Latin-1) - should output 233
string5 = b'\xe9\x00'
action_push5 = struct.pack('<BHB', 0x96, len(string5) + 1, 0) + string5
action_char_to_ascii5 = bytes([0x32])
action_trace5 = bytes([0x26])

# Combine all actions
all_actions = (
    action_push1 + action_char_to_ascii1 + action_trace1 +
    action_push2 + action_char_to_ascii2 + action_trace2 +
    action_push3 + action_char_to_ascii3 + action_trace3 +
    action_push4 + action_char_to_ascii4 + action_trace4 +
    action_push5 + action_char_to_ascii5 + action_trace5
)

action_end = bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions + action_end)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions + action_end

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
print("\nExpected output:")
print("65    (from 'A')")
print("72    (from 'Hello' - first char 'H')")
print("33    (from '!')")
print("nan   (from empty string)")
print("233   (from 'é')")
