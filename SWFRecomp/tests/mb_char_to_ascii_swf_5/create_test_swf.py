#!/usr/bin/env python3
import struct

# Create a SWF5 file to test MB_CHAR_TO_ASCII opcode (0x36)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF5 for multibyte support

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test cases for MB_CHAR_TO_ASCII (0x36)
# Each test: PUSH string, MB_CHAR_TO_ASCII, TRACE

actions = b''

# Test 1: Basic ASCII - "A" → 65
string1 = "A\x00".encode('utf-8')
actions += struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH string
actions += string1
actions += bytes([0x36])  # MB_CHAR_TO_ASCII (0x36)
actions += bytes([0x26])  # TRACE

# Test 2: 2-byte UTF-8 - "é" → 233 (U+00E9)
string2 = "é\x00".encode('utf-8')  # é = 0xC3 0xA9 in UTF-8
actions += struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH string
actions += string2
actions += bytes([0x36])  # MB_CHAR_TO_ASCII (0x36)
actions += bytes([0x26])  # TRACE

# Test 3: 3-byte UTF-8 - "€" → 8364 (U+20AC)
string3 = "€\x00".encode('utf-8')  # € = 0xE2 0x82 0xAC in UTF-8
actions += struct.pack('<BHB', 0x96, len(string3) + 1, 0)  # PUSH string
actions += string3
actions += bytes([0x36])  # MB_CHAR_TO_ASCII (0x36)
actions += bytes([0x26])  # TRACE

# Test 4: CJK character (3-byte UTF-8) - "中" → 20013 (U+4E2D)
string4 = "中\x00".encode('utf-8')  # 中 = 0xE4 0xB8 0xAD in UTF-8
actions += struct.pack('<BHB', 0x96, len(string4) + 1, 0)  # PUSH string
actions += string4
actions += bytes([0x36])  # MB_CHAR_TO_ASCII (0x36)
actions += bytes([0x26])  # TRACE

# Test 5: Empty string → 0
string5 = "\x00".encode('utf-8')
actions += struct.pack('<BHB', 0x96, len(string5) + 1, 0)  # PUSH string
actions += string5
actions += bytes([0x36])  # MB_CHAR_TO_ASCII (0x36)
actions += bytes([0x26])  # TRACE

# END action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

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
print("65")
print("233")
print("8364")
print("20013")
print("0")
