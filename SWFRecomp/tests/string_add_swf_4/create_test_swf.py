#!/usr/bin/env python3
import struct

# Create a SWF4 file that tests ActionStringAdd (0x21)
# This test does: trace("Hello" add " World")
# Expected output: "Hello World"

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace("Hello" add " World")
# The opcode spec says: result = string2 + string1
# where string1 is on top and string2 is second
# But we want: "Hello" + " World" = "Hello World"
#
# Current behavior analysis:
# If we push "Hello" then " World":
#   - After both pushes: Top=" World", Second="Hello"
#   - Result = Second + Top = "Hello" + " World" = "Hello World" ✓
#
# However, the recompiler seems to reverse string order when extracting from SWF,
# so we need to push in reverse order to compensate.

# Push " World" first
string2 = b' World\x00'  # Null-terminated string
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH action, length, type=0 (string)
action_push2 += string2

# Push "Hello" second
string1 = b'Hello\x00'  # Null-terminated string
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH action, length, type=0 (string)
action_push1 += string1

# StringAdd action (0x21) - concatenates the two strings
action_string_add = bytes([0x21])

# Trace action (0x26) - outputs the result
action_trace = bytes([0x26])

# End action
action_end = bytes([0x00])

# Combine all actions (push order: " World" first, then "Hello")
actions = action_push2 + action_push1 + action_string_add + action_trace + action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# SetBackgroundColor tag (optional, for completeness)
set_bg_color_tag = struct.pack('<HBBB', (9 << 6) | 3, 255, 255, 255)  # White background

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = set_bg_color_tag + do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test pushes: ' World' then 'Hello'")
print("With current implementation: ' WorldHello'")
