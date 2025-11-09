#!/usr/bin/env python3
import struct

# Create a comprehensive SWF3 file with SetTarget actions testing edge cases
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3  # SetTarget is available in SWF 3+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Comprehensive test sequence for SetTarget:
# 1. SetTarget "mySprite" (non-existent sprite)
# 2. SetTarget "" (return to main)
# 3. SetTarget "_root" (explicit root)
# 4. SetTarget "/" (root via slash)
# 5. SetTarget "invalidTarget" (another invalid target)
# 6. SetTarget "" (return to main again)

actions = b''

# Test 1: SetTarget to non-existent sprite
target_1 = b'mySprite\x00'
actions += struct.pack('<BH', 0x8B, len(target_1)) + target_1

# Test 2: SetTarget to empty string (return to main)
target_2 = b'\x00'
actions += struct.pack('<BH', 0x8B, len(target_2)) + target_2

# Test 3: SetTarget to "_root"
target_3 = b'_root\x00'
actions += struct.pack('<BH', 0x8B, len(target_3)) + target_3

# Test 4: SetTarget to "/" (root via slash)
target_4 = b'/\x00'
actions += struct.pack('<BH', 0x8B, len(target_4)) + target_4

# Test 5: SetTarget to invalid nested path
target_5 = b'invalid/nested/path\x00'
actions += struct.pack('<BH', 0x8B, len(target_5)) + target_5

# Test 6: SetTarget to empty string (return to main)
target_6 = b'\x00'
actions += struct.pack('<BH', 0x8B, len(target_6)) + target_6

# End action
actions += bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_header += struct.pack('<I', len(actions))
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
