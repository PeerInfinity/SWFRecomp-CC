#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file to test the TARGET_PATH opcode (0x45)
# Test Case: targetPath(42) - should return empty string for non-MovieClip value

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5 (TARGET_PATH available in SWF 5+)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing TARGET_PATH
# Test: Push float 42.0, call targetPath (should return empty string), then trace it

# PUSH float 42.0
push_data_1 = struct.pack('<Bf', 1, 42.0)  # type=1 (float), value=42.0
action_push_1 = struct.pack('<BH', 0x96, len(push_data_1)) + push_data_1

# TARGET_PATH opcode
action_target_path = bytes([0x45])

# TRACE (will trace the empty string result)
action_trace_1 = bytes([0x26])

# PUSH message string
message = b'targetPath(42) test complete\x00'
push_data_2 = struct.pack('<B', 0) + message  # type=0 (string) + string data
action_push_2 = struct.pack('<BH', 0x96, len(push_data_2)) + push_data_2

# TRACE message
action_trace_2 = bytes([0x26])

# END action
action_end = bytes([0x00])

# Combine all actions
all_actions = (action_push_1 + action_target_path + action_trace_1 +
               action_push_2 + action_trace_2 + action_end)

# DoAction tag (tag type 12)
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_header += struct.pack('<I', len(all_actions))
do_action_tag = do_action_header + all_actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test: targetPath(42.0) - expects empty string")
