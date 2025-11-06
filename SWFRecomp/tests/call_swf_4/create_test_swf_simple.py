#!/usr/bin/env python3
import struct

# Create minimal SWF4 file with just CALL action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Actions: PUSH 2, CALL
string_2 = b'2\x00'
# PUSH with type 0 (string) and data "2\x00"
action_push = bytes([0x96])  # PUSH opcode
action_push += struct.pack('<H', len(string_2) + 1)  # length = type byte + string
action_push += bytes([0x00])  # type = string
action_push += string_2  # data

# CALL action (has length field because bit 7 is set)
action_call = bytes([0x9E])
action_call += struct.pack('<H', 0)  # length = 0 (no additional data)

# END action
action_end = bytes([0x00])

actions = action_push + action_call + action_end

# DoAction tag (tag type 12, long form)
do_action_tag = struct.pack('<H', (12 << 6) | 0x3F)  # Tag header
do_action_tag += struct.pack('<I', len(actions))  # Length
do_action_tag += actions

# ShowFrame tag (tag type 1, short form)
show_frame_tag = struct.pack('<H', 1 << 6)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_simple.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_simple.swf ({len(swf_data)} bytes)")
