#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with toggle quality action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test Case 1: Basic quality toggle
# trace("Before toggleHighQuality");
string1 = b'Before toggleHighQuality\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH action, length, type=0 (string)
action_push1 += string1
action_trace1 = bytes([0x26])  # TRACE action (0x26)

# toggleHighQuality(); - This is opcode 0x08
action_toggle_quality = bytes([0x08])  # TOGGLE_QUALITY action (0x08)

# trace("After toggleHighQuality");
string2 = b'After toggleHighQuality\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH action, length, type=0 (string)
action_push2 += string2
action_trace2 = bytes([0x26])  # TRACE action (0x26)

# End action
action_end = bytes([0x00])  # END action

# Combine all actions
all_actions = action_push1 + action_trace1 + action_toggle_quality + action_push2 + action_trace2 + action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

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
