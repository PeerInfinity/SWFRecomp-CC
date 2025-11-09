#!/usr/bin/env python3
import struct

# Create a SWF4 file to test STOP opcode with multiple frames
# This test verifies:
# 1. Frame 1 executes and calls STOP
# 2. Frame 2 should NOT execute (because STOP was called in frame 1)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 2)  # 2 frames

# Frame 1 actions
string1 = b'Frame 1\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH action
action_push1 += string1
action_trace1 = bytes([0x26])  # TRACE action (0x26)
action_stop = bytes([0x07])  # STOP action (0x07)

# End of actions for frame 1
action_end1 = bytes([0x00])  # END action

# Combine frame 1 actions
frame1_actions = action_push1 + action_trace1 + action_stop + action_end1

# DoAction tag for frame 1
do_action1_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action1_length = len(frame1_actions)
do_action1_header += struct.pack('<I', do_action1_length)
do_action1_tag = do_action1_header + frame1_actions

# ShowFrame tag for frame 1
show_frame1_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# Frame 2 actions (should NOT execute)
string2 = b'Frame 2 - Should NOT appear\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH action
action_push2 += string2
action_trace2 = bytes([0x26])  # TRACE action (0x26)

# End of actions for frame 2
action_end2 = bytes([0x00])  # END action

# Combine frame 2 actions
frame2_actions = action_push2 + action_trace2 + action_end2

# DoAction tag for frame 2
do_action2_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action2_length = len(frame2_actions)
do_action2_header += struct.pack('<I', do_action2_length)
do_action2_tag = do_action2_header + frame2_actions

# ShowFrame tag for frame 2
show_frame2_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action1_tag + show_frame1_tag + do_action2_tag + show_frame2_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
