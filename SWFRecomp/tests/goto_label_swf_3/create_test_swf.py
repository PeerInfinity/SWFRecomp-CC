#!/usr/bin/env python3
import struct

# Create a minimal SWF3 file with a GoToLabel action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for:
# trace("Testing GoToLabel");
# gotoAndStop("testlabel");
# trace("After GoToLabel");

# First trace: "Testing GoToLabel"
string1 = b'Testing GoToLabel\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH action, length, type=0 (string)
action_push1 += string1
action_trace1 = bytes([0x26])  # TRACE action (0x26)

# GoToLabel with label "testlabel"
label = b'testlabel\x00'  # Null-terminated label string
action_goto_label_length = len(label)
action_goto_label = struct.pack('<BH', 0x8C, action_goto_label_length)  # GoToLabel action (0x8C), length
action_goto_label += label

# Second trace: "After GoToLabel"
string2 = b'After GoToLabel\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH action, length, type=0 (string)
action_push2 += string2
action_trace2 = bytes([0x26])  # TRACE action (0x26)

action_end = bytes([0x00])  # END action

# Combine all actions
all_actions = action_push1 + action_trace1 + action_goto_label + action_push2 + action_trace2 + action_end

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
