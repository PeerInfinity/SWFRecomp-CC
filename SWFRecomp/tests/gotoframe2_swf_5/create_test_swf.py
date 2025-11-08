#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with GotoFrame2 action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for:
# 1. Push frame number 2
# 2. GotoFrame2 with play_flag=0 (stop)
# 3. Trace to show we executed

# Test 1: Numeric frame
action_push_frame = struct.pack('<BHB', 0x96, 5, 0x01)  # PUSH, length=5, type=1 (float/F32)
action_push_frame += struct.pack('<f', 2.0)  # Frame number 2

# GotoFrame2: opcode 0x9F with flags
# flags: bit 0 = play_flag (0=stop), bit 1 = scene_bias_flag (0=no bias)
action_gotoframe2_flags = bytes([0x00])  # play_flag=0, scene_bias_flag=0
action_gotoframe2 = struct.pack('<BHB', 0x9F, 1, 0x00)  # opcode, length=1, flags=0

# Trace message to confirm execution
string1 = b'After GotoFrame2\x00'
action_push_str = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH, type=0 (string)
action_push_str += string1
action_trace = bytes([0x26])  # TRACE

# Test 2: String label
string_label = b'scene2\x00'
action_push_label = struct.pack('<BHB', 0x96, len(string_label) + 1, 0)  # PUSH label
action_push_label += string_label

# GotoFrame2 with play_flag=1 (play)
action_gotoframe2_play = struct.pack('<BHB', 0x9F, 1, 0x01)  # play_flag=1

# Trace after label goto
string2 = b'After GotoFrame2 with label\x00'
action_push_str2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)
action_push_str2 += string2
action_trace2 = bytes([0x26])

action_end = bytes([0x00])  # END action

# Combine all actions
actions = (action_push_frame + action_gotoframe2 + action_push_str + action_trace +
           action_push_label + action_gotoframe2_play + action_push_str2 + action_trace2 +
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
