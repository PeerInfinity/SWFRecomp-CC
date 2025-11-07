#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file testing PLAY and STOP opcodes
# Test Case: Basic play/stop functionality with multiple frames
# Frame 1: trace("Frame 1"); stop(); trace("Stopped"); play(); trace("Playing");
# Frame 2: trace("Frame 2"); stop();
# Expected output: Frame 1, Stopped, Playing, Frame 2

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 2)  # 2 frames

# Helper function to push a string constant
def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'  # Null-terminated
    length = 1 + len(s_bytes)  # Type byte + string
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

# Frame 1 Actions
# trace("Frame 1")
trace_frame1 = push_string("Frame 1") + bytes([0x26])  # 0x26 = TRACE

# stop()
action_stop = bytes([0x07])  # 0x07 = STOP

# trace("Stopped")
trace_stopped = push_string("Stopped") + bytes([0x26])

# play()
action_play = bytes([0x06])  # 0x06 = PLAY

# trace("Playing")
trace_playing = push_string("Playing") + bytes([0x26])

# End of Frame 1 actions
action_end = bytes([0x00])

frame1_actions = trace_frame1 + action_stop + trace_stopped + action_play + trace_playing + action_end

# DoAction tag for Frame 1
do_action1_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action1_length = len(frame1_actions)
do_action1_header += struct.pack('<I', do_action1_length)
do_action1_tag = do_action1_header + frame1_actions

# ShowFrame tag 1
show_frame1_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

# Frame 2 Actions
# trace("Frame 2")
trace_frame2 = push_string("Frame 2") + bytes([0x26])

# stop()
# (action_stop already defined)

frame2_actions = trace_frame2 + action_stop + action_end

# DoAction tag for Frame 2
do_action2_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action2_length = len(frame2_actions)
do_action2_header += struct.pack('<I', do_action2_length)
do_action2_tag = do_action2_header + frame2_actions

# ShowFrame tag 2
show_frame2_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action1_tag + show_frame1_tag + do_action2_tag + show_frame2_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test case: PLAY and STOP opcodes")
print("Frame 1: trace('Frame 1'); stop(); trace('Stopped'); play(); trace('Playing');")
print("Frame 2: trace('Frame 2'); stop();")
print("Expected output:")
print("  Frame 1")
print("  Stopped")
print("  Playing")
print("  Frame 2")
