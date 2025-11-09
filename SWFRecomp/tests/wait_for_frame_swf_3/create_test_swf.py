#!/usr/bin/env python3
import struct

# Create a minimal SWF3 file with WaitForFrame operations
# Test cases:
# 1. WaitForFrame for frame 0 (exists) - should execute trace
# 2. WaitForFrame for frame 100 (doesn't exist) - should skip trace
# 3. WaitForFrame with skip count 0 - should not skip even if frame doesn't exist
# 4. WaitForFrame with skip count 2 - should skip multiple actions
# 5. WaitForFrame for last frame (frame 1, if it exists in 2-frame SWF)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3  # SWF version 3 (WaitForFrame available in SWF 3+)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 2)  # 2 frames (to test boundary)

# Helper function to create PUSH action for a string
def push_string(s):
    s_bytes = s.encode('ascii') + b'\x00'
    length = 1 + len(s_bytes)  # Type byte + string
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Helper function to create WaitForFrame action
def wait_for_frame(frame_num, skip_count):
    # Opcode 0x8A, Length = 3, Frame (UI16), SkipCount (UI8)
    return struct.pack('<BHHB', 0x8A, 3, frame_num, skip_count)

# Build action sequence for all test cases
actions = b''

# Test 1: WaitForFrame for frame 0 (exists) - should print "Frame 0 loaded"
# Frame 0 exists, so WaitForFrame won't skip the PUSH+TRACE
actions += push_string("Frame 0 loaded")
actions += wait_for_frame(0, 1)  # Check frame 0, skip 1 action (TRACE) if not loaded
actions += trace()

# Test 2: WaitForFrame for frame 100 (doesn't exist) - should skip trace
# Frame 100 doesn't exist, so WaitForFrame will skip the TRACE
actions += push_string("Frame 100 loaded")
actions += wait_for_frame(100, 1)  # Check frame 100, skip 1 action (TRACE) if not loaded
actions += trace()  # This SHOULD be skipped

# Test 3: WaitForFrame with skip count 0
# Even if frame doesn't exist, skip count 0 means don't skip
actions += push_string("Skip count 0")
actions += wait_for_frame(200, 0)  # Check frame 200 (doesn't exist), but skip 0 actions
actions += trace()  # This SHOULD execute (skip count is 0)

# Test 4: WaitForFrame for last frame (frame 1, exists in 2-frame SWF)
# Frame 1 exists (SWF has 2 frames: 0 and 1), so this should NOT skip
actions += push_string("Frame 1 loaded")
actions += wait_for_frame(1, 1)  # Check frame 1, skip 1 if not loaded
actions += trace()  # This SHOULD execute (frame 1 exists)

# Test 5: WaitForFrame with skip count > 1
# Skip multiple actions if frame doesn't exist
actions += push_string("Skip test 1")
actions += push_string("Skip test 2")
actions += wait_for_frame(300, 2)  # Check frame 300 (doesn't exist), skip 2 actions
actions += trace()  # Skip this
actions += trace()  # Skip this too

# This should execute regardless
actions += push_string("Continued")
actions += trace()

# End action
actions += bytes([0x00])

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
print("Test cases:")
print("  1. WaitForFrame(0) - frame exists, should print 'Frame 0 loaded'")
print("  2. WaitForFrame(100) - frame doesn't exist, should skip trace")
print("  3. WaitForFrame(200, skip=0) - skip count 0, should print 'Skip count 0'")
print("  4. WaitForFrame(1) - last frame exists, should print 'Frame 1 loaded'")
print("  5. WaitForFrame(300, skip=2) - skip 2 actions, should not print skip tests")
print("  6. Should print 'Continued' at end")
print("\nExpected output:")
print("  Frame 0 loaded")
print("  Skip count 0")
print("  Frame 1 loaded")
print("  Continued")
