#!/usr/bin/env python3
import struct

# Create a minimal SWF3 file to test the ActionGotoFrame opcode (0x81)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame (simplified test)

# ActionScript bytecode for testing ActionGotoFrame
actions = b''

# Test: Trace "Start", then GotoFrame(2), then Trace "After goto"
# Expected: "Start", then "After goto" (goto doesn't print anything)

# Push string "Start"
string_start = b'Start\x00'
actions += struct.pack('<BHB', 0x96, len(string_start) + 1, 0)  # PUSH string
actions += string_start

# TRACE - prints "Start"
actions += bytes([0x26])  # TRACE (0x26)

# ActionGotoFrame with frame index 2
# Format: ActionCode (0x81), Length (UI16 = 2), Frame (UI16 = 2)
actions += bytes([0x81])  # ActionGotoFrame
actions += struct.pack('<H', 2)  # Length = 2 bytes
actions += struct.pack('<H', 2)  # Frame index = 2

# Push string "After goto"
string_after = b'After goto\x00'
actions += struct.pack('<BHB', 0x96, len(string_after) + 1, 0)  # PUSH string
actions += string_after

# TRACE - prints "After goto"
actions += bytes([0x26])  # TRACE (0x26)

# END action
actions += bytes([0x00])

# DoAction tag (tag type 12)
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# SetBackgroundColor tag (tag type 9)
# RGB: white (255, 255, 255)
set_bg_color_tag = struct.pack('<H', (9 << 6) | 3)  # Tag type 9, short form (length 3)
set_bg_color_tag += bytes([0xFF, 0xFF, 0xFF])  # White background

# ShowFrame tag (tag type 1)
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag (tag type 0)
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = set_bg_color_tag + do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print("Created test.swf with ActionGotoFrame test (simplified - logging only)")
