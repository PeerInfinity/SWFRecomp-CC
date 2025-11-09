#!/usr/bin/env python3
import struct

# Create a SWF4 file that properly tests ActionPrevFrame (0x05)
# The test creates a 3-frame SWF where:
# - Frame 0: trace "Frame 1", gotoFrame(2) - jumps to Frame 2
# - Frame 1: trace "Frame 2", STOP - only executes when prevFrame() is called
# - Frame 2: trace "Frame 3", prevFrame() - goes back to Frame 1
# Expected output: Frame 1, Frame 3, Frame 2

signature = b'FWS'
version = 4
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 3)

# Frame 0: trace "Frame 1", gotoFrame(2)
frame0_actions = b''
string1 = b'Frame 1\x00'
# PUSH "Frame 1"
frame0_actions += struct.pack('<BHB', 0x96, len(string1) + 1, 0)
frame0_actions += string1
# TRACE
frame0_actions += bytes([0x26])
# GOTO_FRAME 2 (0x81) - skip to Frame 2
frame0_actions += bytes([0x81])  # ActionGotoFrame
frame0_actions += struct.pack('<H', 2)  # Length = 2 bytes
frame0_actions += struct.pack('<H', 2)  # Frame index = 2
# END
frame0_actions += bytes([0x00])

# Frame 1: trace "Frame 2", STOP
frame1_actions = b''
string2 = b'Frame 2\x00'
# PUSH "Frame 2"
frame1_actions += struct.pack('<BHB', 0x96, len(string2) + 1, 0)
frame1_actions += string2
# TRACE
frame1_actions += bytes([0x26])
# STOP
frame1_actions += bytes([0x07])
# END
frame1_actions += bytes([0x00])

# Frame 2: trace "Frame 3", prevFrame()
frame2_actions = b''
string3 = b'Frame 3\x00'
# PUSH "Frame 3"
frame2_actions += struct.pack('<BHB', 0x96, len(string3) + 1, 0)
frame2_actions += string3
# TRACE
frame2_actions += bytes([0x26])
# PREV_FRAME (0x05) - go back to Frame 1
frame2_actions += bytes([0x05])
# END
frame2_actions += bytes([0x00])

def make_do_action_tag(actions):
    if len(actions) < 63:
        return struct.pack('<H', (12 << 6) | len(actions)) + actions
    return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(actions)) + actions

tags = make_do_action_tag(frame0_actions)
tags += struct.pack('<H', 1 << 6)  # ShowFrame
tags += make_do_action_tag(frame1_actions)
tags += struct.pack('<H', 1 << 6)  # ShowFrame
tags += make_do_action_tag(frame2_actions)
tags += struct.pack('<H', 1 << 6)  # ShowFrame
tags += bytes([0x00, 0x00])  # End tag

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test structure:")
print("  Frame 0: trace('Frame 1'); gotoFrame(2);")
print("  Frame 1: trace('Frame 2'); stop();")
print("  Frame 2: trace('Frame 3'); prevFrame();")
print("")
print("Expected output:")
print("  Frame 1")
print("  Frame 3")
print("  Frame 2")
