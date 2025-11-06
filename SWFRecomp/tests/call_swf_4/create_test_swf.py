#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with a CALL action
# This test demonstrates the CALL opcode (0x9E) which calls frame actions

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test: Call frame 2, then trace "continued"
# This tests:
# 1. PUSH frame number (2)
# 2. CALL opcode (0x9E)
# 3. TRACE to show execution continues

# Push frame number 2 (as a string)
string_2 = b'2\x00'
action_push_2 = struct.pack('<BHB', 0x96, len(string_2) + 1, 0x00)  # PUSH action, length includes type byte + string
action_push_2 += string_2

# CALL action (0x9E) - has length field because bit 7 is set
action_call = bytes([0x9E])  # CALL action
action_call += struct.pack('<H', 0)  # length = 0 (no additional data)

# Push "continued" string
string_continued = b'continued\x00'
action_push_str = struct.pack('<BHB', 0x96, len(string_continued) + 1, 0x00)  # PUSH action
action_push_str += string_continued

# TRACE action
action_trace = bytes([0x26])  # TRACE action (0x26)

# END action
action_end = bytes([0x00])  # END action

# Build action sequence
actions = action_push_2 + action_call + action_push_str + action_trace + action_end

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
print("Test: PUSH 2, CALL, TRACE 'continued'")
print("Expected output: '// Call frame 2' then 'continued'")
