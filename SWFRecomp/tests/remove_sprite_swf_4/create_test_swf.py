#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file testing removeMovieClip action
# Tests: basic removal, non-existent sprite, empty string, special characters
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
trace_msg = b'Test 1: Basic remove\x00'
action_push_msg = struct.pack('<BHB', 0x96, len(trace_msg) + 1, 0)
action_push_msg += trace_msg
action_trace = bytes([0x26])  # TRACE action (0x26)

# Test case 2: Remove non-existent sprite
trace_test2 = b'Test 2: Non-existent\x00'
action_push_test2 = struct.pack('<BHB', 0x96, len(trace_test2) + 1, 0)
action_push_test2 += trace_test2
action_trace_test2 = bytes([0x26])

nonexist_sprite = b'nonExistent\x00'
action_push_nonexist = struct.pack('<BHB', 0x96, len(nonexist_sprite) + 1, 0)
action_push_nonexist += nonexist_sprite
action_remove_nonexist = bytes([0x25])

# Test case 3: Remove empty string
trace_test3 = b'Test 3: Empty string\x00'
action_push_test3 = struct.pack('<BHB', 0x96, len(trace_test3) + 1, 0)
action_push_test3 += trace_test3
action_trace_test3 = bytes([0x26])

empty_sprite = b'\x00'
action_push_empty = struct.pack('<BHB', 0x96, len(empty_sprite) + 1, 0)
action_push_empty += empty_sprite
action_remove_empty = bytes([0x25])

# Test case 4: Remove sprite with special characters in name
trace_test4 = b'Test 4: Special chars\x00'
action_push_test4 = struct.pack('<BHB', 0x96, len(trace_test4) + 1, 0)
action_push_test4 += trace_test4
action_trace_test4 = bytes([0x26])

special_sprite = b'my_sprite.123\x00'
action_push_special = struct.pack('<BHB', 0x96, len(special_sprite) + 1, 0)
action_push_special += special_sprite
action_remove_special = bytes([0x25])

# Test case 5: Remove sprite with path
trace_test5 = b'Test 5: Path notation\x00'
action_push_test5 = struct.pack('<BHB', 0x96, len(trace_test5) + 1, 0)
action_push_test5 += trace_test5
action_trace_test5 = bytes([0x26])

path_sprite = b'_root.myClip\x00'
action_push_path = struct.pack('<BHB', 0x96, len(path_sprite) + 1, 0)
action_push_path += path_sprite
action_remove_path = bytes([0x25])

# Final confirmation
trace_final = b'All tests completed\x00'
action_push_final = struct.pack('<BHB', 0x96, len(trace_final) + 1, 0)
action_push_final += trace_final
action_trace_final = bytes([0x26])

action_end = bytes([0x00])  # END action

# Combine all actions
all_actions = (action_push_sprite + action_remove_sprite +
               action_push_msg + action_trace +
               action_push_test2 + action_trace_test2 +
               action_push_nonexist + action_remove_nonexist +
               action_push_test3 + action_trace_test3 +
               action_push_empty + action_remove_empty +
               action_push_test4 + action_trace_test4 +
               action_push_special + action_remove_special +
               action_push_test5 + action_trace_test5 +
               action_push_path + action_remove_path +
               action_push_final + action_trace_final +
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
