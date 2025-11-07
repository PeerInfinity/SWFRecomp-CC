#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file testing CLONE_SPRITE opcode (0x24)
# Test case: duplicateMovieClip("originalSprite", "clonedSprite", 1);
#             trace("Sprite cloned");

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode
# duplicateMovieClip("originalSprite", "clonedSprite", 1)
# Stack order for CLONE_SPRITE: target, source, depth (pops in reverse)

# Push target name "clonedSprite"
target_string = b'clonedSprite\x00'
action_push_target = struct.pack('<BHB', 0x96, len(target_string) + 1, 0)  # PUSH, length, type=0 (string)
action_push_target += target_string

# Push source name "originalSprite"
source_string = b'originalSprite\x00'
action_push_source = struct.pack('<BHB', 0x96, len(source_string) + 1, 0)  # PUSH, length, type=0 (string)
action_push_source += source_string

# Push depth 1 (as float)
depth_value = struct.pack('<f', 1.0)
action_push_depth = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_depth += depth_value

# CLONE_SPRITE action (0x24)
action_clone_sprite = bytes([0x24])

# trace("Sprite cloned")
trace_string = b'Sprite cloned\x00'
action_push_trace = struct.pack('<BHB', 0x96, len(trace_string) + 1, 0)  # PUSH, length, type=0 (string)
action_push_trace += trace_string
action_trace = bytes([0x26])  # TRACE action (0x26)

# END action
action_end = bytes([0x00])

# Combine all actions
actions = (action_push_target + action_push_source + action_push_depth +
           action_clone_sprite + action_push_trace + action_trace + action_end)

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
print("Test: duplicateMovieClip('originalSprite', 'clonedSprite', 1); trace('Sprite cloned');")
