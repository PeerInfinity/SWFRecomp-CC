#!/usr/bin/env python3
import struct

signature = b'FWS'
version = 4
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 3)

# Frame 0: trace "Frame 1"
frame0_actions = b''
string1 = b'Frame 1\x00'
frame0_actions += struct.pack('<BHB', 0x96, len(string1) + 1, 0)
frame0_actions += string1
frame0_actions += bytes([0x26, 0x00])

# Frame 1: trace "Frame 2", STOP
frame1_actions = b''
string2 = b'Frame 2\x00'
frame1_actions += struct.pack('<BHB', 0x96, len(string2) + 1, 0)
frame1_actions += string2
frame1_actions += bytes([0x26, 0x07, 0x00])

# Frame 2: trace "Frame 3", prevFrame()
frame2_actions = b''
string3 = b'Frame 3\x00'
frame2_actions += struct.pack('<BHB', 0x96, len(string3) + 1, 0)
frame2_actions += string3
frame2_actions += bytes([0x26, 0x05, 0x00])

def make_do_action_tag(actions):
    if len(actions) < 63:
        return struct.pack('<H', (12 << 6) | len(actions)) + actions
    return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(actions)) + actions

tags = make_do_action_tag(frame0_actions)
tags += struct.pack('<H', 1 << 6)
tags += make_do_action_tag(frame1_actions)
tags += struct.pack('<H', 1 << 6)
tags += make_do_action_tag(frame2_actions)
tags += struct.pack('<H', 1 << 6)
tags += bytes([0x00, 0x00])

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)
print(f"Created test.swf ({len(swf_data)} bytes)")
