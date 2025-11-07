#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with removeMovieClip action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test case 1: Remove a sprite (basic test)
# Stack-based: Push sprite name "mySprite", then call removeMovieClip (0x25)
sprite_name = b'mySprite\x00'
action_push_sprite = struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH action, length, type=0 (string)
action_push_sprite += sprite_name
action_remove_sprite = bytes([0x25])  # REMOVE_SPRITE action (0x25)

# Trace confirmation message
trace_msg = b'Sprite removed\x00'
action_push_msg = struct.pack('<BHB', 0x96, len(trace_msg) + 1, 0)
action_push_msg += trace_msg
action_trace = bytes([0x26])  # TRACE action (0x26)

# Test case 2: Remove non-existent sprite
trace_before = b'Before remove\x00'
action_push_before = struct.pack('<BHB', 0x96, len(trace_before) + 1, 0)
action_push_before += trace_before
action_trace_before = bytes([0x26])

nonexist_sprite = b'nonExistent\x00'
action_push_nonexist = struct.pack('<BHB', 0x96, len(nonexist_sprite) + 1, 0)
action_push_nonexist += nonexist_sprite
action_remove_nonexist = bytes([0x25])

trace_after = b'After remove\x00'
action_push_after = struct.pack('<BHB', 0x96, len(trace_after) + 1, 0)
action_push_after += trace_after
action_trace_after = bytes([0x26])

action_end = bytes([0x00])  # END action

# Combine all actions
all_actions = (action_push_sprite + action_remove_sprite +
               action_push_msg + action_trace +
               action_push_before + action_trace_before +
               action_push_nonexist + action_remove_nonexist +
               action_push_after + action_trace_after +
               action_end)

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
