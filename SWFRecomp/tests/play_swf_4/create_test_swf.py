#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file testing PLAY opcode (0x06)
# This test covers multiple edge cases:
# - Basic play from stopped state
# - Play when already playing (no-op)
# - Multiple consecutive play calls
# - Play/stop/play sequences
# - Frame progression

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 4)  # 4 frames for comprehensive testing

# Helper function to push a string constant
def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'  # Null-terminated
    length = 1 + len(s_bytes)  # Type byte + string
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

# Opcode constants
action_stop = bytes([0x07])  # 0x07 = STOP
action_play = bytes([0x06])  # 0x06 = PLAY
action_end = bytes([0x00])   # 0x00 = END

# Frame 1: Test basic play from stopped state
# trace("Frame 1"); stop(); trace("After stop"); play(); trace("After play");
frame1_actions = (
    push_string("Frame 1") + bytes([0x26]) +      # trace("Frame 1")
    action_stop +                                   # stop()
    push_string("After stop") + bytes([0x26]) +   # trace("After stop")
    action_play +                                   # play()
    push_string("After play") + bytes([0x26]) +   # trace("After play")
    action_end
)

# Frame 2: Test play when already playing (should be no-op)
# trace("Frame 2"); play(); play(); trace("Double play");
frame2_actions = (
    push_string("Frame 2") + bytes([0x26]) +      # trace("Frame 2")
    action_play +                                   # play() - redundant, already playing
    action_play +                                   # play() - redundant again
    push_string("Double play") + bytes([0x26]) +  # trace("Double play")
    action_end
)

# Frame 3: Test play/stop/play sequence
# trace("Frame 3"); stop(); play(); stop(); trace("Stop after play");
frame3_actions = (
    push_string("Frame 3") + bytes([0x26]) +      # trace("Frame 3")
    action_stop +                                   # stop()
    action_play +                                   # play()
    action_stop +                                   # stop() - should stop again
    push_string("Stop after play") + bytes([0x26]) + # trace("Stop after play")
    action_end
)

# Build tags for all frames
def build_do_action_tag(actions):
    header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
    header += struct.pack('<I', len(actions))
    return header + actions

def build_show_frame_tag():
    return struct.pack('<H', 1 << 6)  # Tag type 1, short form

tags = (
    build_do_action_tag(frame1_actions) + build_show_frame_tag() +
    build_do_action_tag(frame2_actions) + build_show_frame_tag() +
    build_do_action_tag(frame3_actions) + build_show_frame_tag() +
    bytes([0x00, 0x00])  # End tag
)

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)  # Header is 8 bytes
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("\nComprehensive PLAY opcode test cases:")
print("Frame 1: Basic play from stopped state")
print("  trace('Frame 1'); stop(); trace('After stop'); play(); trace('After play');")
print("Frame 2: Play when already playing (no-op)")
print("  trace('Frame 2'); play(); play(); trace('Double play');")
print("Frame 3: Play/stop/play sequence")
print("  trace('Frame 3'); stop(); play(); stop(); trace('Stop after play');")
print("\nExpected output:")
print("  Frame 1")
print("  After stop")
print("  After play")
print("  Frame 2")
print("  Double play")
print("  Frame 3")
print("  Stop after play")
