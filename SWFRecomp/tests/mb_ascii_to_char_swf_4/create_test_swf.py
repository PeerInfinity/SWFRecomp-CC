#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with MB_ASCII_TO_CHAR (mbchr) operations
# Tests various UTF-8 encoding cases

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4  # SWF 4 (multibyte support starts in SWF 4)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test cases for mbchr (MB_ASCII_TO_CHAR opcode 0x37)
test_cases = [
    (65, "A"),          # Test 1: Basic ASCII
    (97, "a"),          # Test 2: Basic ASCII lowercase
    (233, "é"),         # Test 3: 2-byte UTF-8 (U+00E9)
    (241, "ñ"),         # Test 4: 2-byte UTF-8 (U+00F1)
    (20013, "中"),      # Test 5: 3-byte UTF-8 CJK (U+4E2D)
    (26085, "日"),      # Test 6: 3-byte UTF-8 CJK (U+65E5)
    (8364, "€"),        # Test 7: 3-byte UTF-8 symbol (U+20AC)
    (0, ""),            # Test 8: Null character (may be empty)
    (9999999, ""),      # Test 9: Out of range (should produce empty string)
]

# Build ActionScript bytecode
actions = b''

for codepoint, expected in test_cases:
    # Push the codepoint value
    action_push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
    action_push += struct.pack('<f', float(codepoint))
    actions += action_push

    # MB_ASCII_TO_CHAR operation (0x37)
    action_mb_ascii_to_char = bytes([0x37])
    actions += action_mb_ascii_to_char

    # Trace action (0x26)
    action_trace = bytes([0x26])
    actions += action_trace

# End action (0x00)
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
print(f"Test cases:")
for codepoint, expected in test_cases:
    print(f"  mbchr({codepoint}) = '{expected}' (U+{codepoint:04X})")
