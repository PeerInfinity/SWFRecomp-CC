#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with AsciiToChar actions
# Test ASCII code to character conversion using ASCII_TO_CHAR opcode (0x32)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test Case 1: trace(chr(65))
# Expected output: "A"
float_65 = struct.pack('<f', 65.0)
action_push_65 = struct.pack('<BHB', 0x96, 5, 1) + float_65  # PUSH 65.0
action_ascii_to_char_1 = bytes([0x32])  # AsciiToChar (0x32)
action_trace_1 = bytes([0x26])  # Trace

# Test Case 2: trace(chr(97))
# Expected output: "a"
float_97 = struct.pack('<f', 97.0)
action_push_97 = struct.pack('<BHB', 0x96, 5, 1) + float_97  # PUSH 97.0
action_ascii_to_char_2 = bytes([0x32])  # AsciiToChar (0x32)
action_trace_2 = bytes([0x26])  # Trace

# Test Case 3: trace(chr(33))
# Expected output: "!"
float_33 = struct.pack('<f', 33.0)
action_push_33 = struct.pack('<BHB', 0x96, 5, 1) + float_33  # PUSH 33.0
action_ascii_to_char_3 = bytes([0x32])  # AsciiToChar (0x32)
action_trace_3 = bytes([0x26])  # Trace

# Test Case 4: trace(chr(32))
# Expected output: " " (space character)
float_32 = struct.pack('<f', 32.0)
action_push_32 = struct.pack('<BHB', 0x96, 5, 1) + float_32  # PUSH 32.0
action_ascii_to_char_4 = bytes([0x32])  # AsciiToChar (0x32)
action_trace_4 = bytes([0x26])  # Trace

# Test Case 5: trace(chr(233))
# Expected output: "é"
float_233 = struct.pack('<f', 233.0)
action_push_233 = struct.pack('<BHB', 0x96, 5, 1) + float_233  # PUSH 233.0
action_ascii_to_char_5 = bytes([0x32])  # AsciiToChar (0x32)
action_trace_5 = bytes([0x26])  # Trace

# END action
action_end = bytes([0x00])

# Combine all actions
actions = (action_push_65 + action_ascii_to_char_1 + action_trace_1 +
           action_push_97 + action_ascii_to_char_2 + action_trace_2 +
           action_push_33 + action_ascii_to_char_3 + action_trace_3 +
           action_push_32 + action_ascii_to_char_4 + action_trace_4 +
           action_push_233 + action_ascii_to_char_5 + action_trace_5 +
           action_end)

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
print("1. chr(65)  -> Expected: A")
print("2. chr(97)  -> Expected: a")
print("3. chr(33)  -> Expected: !")
print("4. chr(32)  -> Expected: ' ' (space)")
print("5. chr(233) -> Expected: é")
