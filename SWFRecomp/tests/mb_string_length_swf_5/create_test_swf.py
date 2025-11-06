#!/usr/bin/env python3
import struct

# Create a SWF5 file to test MB_STRING_LENGTH opcode (0x35)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF 5 for multibyte support

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test cases for MB_STRING_LENGTH
test_cases = [
    ("Hello", "Basic ASCII string"),
    ("café", "String with 2-byte UTF-8 (é)"),
    ("€100", "String with 3-byte UTF-8 (€)"),
    ("中文", "CJK characters"),
    ("", "Empty string"),
    ("Hello世界", "Mixed ASCII and multibyte"),
]

# Build ActionScript bytecode
actions = b''

for test_string, description in test_cases:
    # Encode string to UTF-8
    string_bytes = test_string.encode('utf-8') + b'\x00'  # Null-terminated

    # PUSH string
    action_push = struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0)  # PUSH action, length, type=0 (string)
    action_push += string_bytes

    # MB_STRING_LENGTH opcode (0x35)
    action_mb_string_length = bytes([0x35])

    # TRACE the result
    action_trace = bytes([0x26])  # TRACE action (0x26)

    actions += action_push + action_mb_string_length + action_trace

# END action
action_end = bytes([0x00])
actions += action_end

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
print("\nExpected output:")
print("5      (Hello)")
print("4      (café)")
print("4      (€100)")
print("2      (中文)")
print("0      (empty string)")
print("7      (Hello世界)")
