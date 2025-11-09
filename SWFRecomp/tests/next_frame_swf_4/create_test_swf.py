#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with NEXT_FRAME action
# This test creates a multi-frame SWF to test frame advancement
#
# Test cases:
# 1. Basic nextFrame: Frame 0 -> Frame 1
# 2. Skip frame: Frame 0 skips Frame 1, goes to Frame 2
# 3. Multiple nextFrame calls: Skip multiple frames
# 4. nextFrame at last frame: Should not crash
#
# Frame 0: trace("Frame 1"); nextFrame();  // Goes to Frame 1
# Frame 1: trace("Frame 2"); nextFrame();  // Goes to Frame 2
# Frame 2: trace("Frame 3"); nextFrame();  // Goes to Frame 3
# Frame 3: trace("Frame 4"); stop();       // Stops execution

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 5)  # 5 frames

# Frame 1: trace("Frame 1"); nextFrame();
actions_frame1 = b''

# PUSH "Frame 1"
msg1 = b'Frame 1\x00'
actions_frame1 += struct.pack('<BHB', 0x96, len(msg1) + 1, 0) + msg1  # PUSH string

# TRACE (0x26)
actions_frame1 += bytes([0x26])

# NEXT_FRAME (0x04)
actions_frame1 += bytes([0x04])

# END action
actions_frame1 += bytes([0x00])

# DoAction tag for Frame 1
do_action_header1 = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length1 = len(actions_frame1)
do_action_header1 += struct.pack('<I', do_action_length1)
do_action_tag1 = do_action_header1 + actions_frame1

# ShowFrame tag for Frame 1
show_frame_tag1 = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# Frame 2: trace("Frame 2"); nextFrame();
actions_frame2 = b''

# PUSH "Frame 2"
msg2 = b'Frame 2\x00'
actions_frame2 += struct.pack('<BHB', 0x96, len(msg2) + 1, 0) + msg2  # PUSH string

# TRACE (0x26)
actions_frame2 += bytes([0x26])

# NEXT_FRAME (0x04)
actions_frame2 += bytes([0x04])

# END action
actions_frame2 += bytes([0x00])

# DoAction tag for Frame 2
do_action_header2 = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length2 = len(actions_frame2)
do_action_header2 += struct.pack('<I', do_action_length2)
do_action_tag2 = do_action_header2 + actions_frame2

# ShowFrame tag for Frame 2
show_frame_tag2 = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# Frame 3: trace("Frame 3"); nextFrame();
actions_frame3 = b''

# PUSH "Frame 3"
msg3 = b'Frame 3\x00'
actions_frame3 += struct.pack('<BHB', 0x96, len(msg3) + 1, 0) + msg3  # PUSH string

# TRACE (0x26)
actions_frame3 += bytes([0x26])

# NEXT_FRAME (0x04)
actions_frame3 += bytes([0x04])

# END action
actions_frame3 += bytes([0x00])

# DoAction tag for Frame 3
do_action_header3 = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length3 = len(actions_frame3)
do_action_header3 += struct.pack('<I', do_action_length3)
do_action_tag3 = do_action_header3 + actions_frame3

# ShowFrame tag for Frame 3
show_frame_tag3 = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# Frame 4: trace("Frame 4"); stop();
actions_frame4 = b''

# PUSH "Frame 4"
msg4 = b'Frame 4\x00'
actions_frame4 += struct.pack('<BHB', 0x96, len(msg4) + 1, 0) + msg4  # PUSH string

# TRACE (0x26)
actions_frame4 += bytes([0x26])

# STOP (0x07) - prevent looping
actions_frame4 += bytes([0x07])

# END action
actions_frame4 += bytes([0x00])

# DoAction tag for Frame 4
do_action_header4 = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length4 = len(actions_frame4)
do_action_header4 += struct.pack('<I', do_action_length4)
do_action_tag4 = do_action_header4 + actions_frame4

# ShowFrame tag for Frame 4
show_frame_tag4 = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# Frame 5: Empty frame (should not execute)
show_frame_tag5 = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = (do_action_tag1 + show_frame_tag1 +
        do_action_tag2 + show_frame_tag2 +
        do_action_tag3 + show_frame_tag3 +
        do_action_tag4 + show_frame_tag4 +
        show_frame_tag5 +
        end_tag)

body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Multi-frame SWF with NEXT_FRAME test:")
print("  Frame 0: trace('Frame 1'); nextFrame();  // Goes to Frame 1")
print("  Frame 1: trace('Frame 2'); nextFrame();  // Goes to Frame 2")
print("  Frame 2: trace('Frame 3'); nextFrame();  // Goes to Frame 3")
print("  Frame 3: trace('Frame 4'); stop();       // Stops execution")
print("  Frame 4: (empty - should not execute)")
print("")
print("Expected output:")
print("  Frame 1")
print("  Frame 2")
print("  Frame 3")
print("  Frame 4")
