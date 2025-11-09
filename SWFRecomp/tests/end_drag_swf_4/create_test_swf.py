#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file testing END_DRAG opcode (0x28)
# Tests:
#   1. END_DRAG when nothing is dragging (should be safe no-op)
#   2. START_DRAG followed by END_DRAG (should start and stop drag)
#   3. Multiple END_DRAG calls (should be safe)
#
# Expected output:
#   Test 1: END_DRAG with no drag
#   Test 2: Before START_DRAG
#   Test 3: After START_DRAG
#   Test 4: After END_DRAG
#   Test 5: After second END_DRAG

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create a PUSH string action
def push_string(s):
    string_bytes = s.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes

# Helper for TRACE action
def trace():
    return bytes([0x26])

# Test 1: END_DRAG when nothing is dragging
test1 = push_string("Test 1: END_DRAG with no drag") + trace()
test1 += bytes([0x28])  # END_DRAG

# Test 2: START_DRAG followed by END_DRAG
test2 = push_string("Test 2: Before START_DRAG") + trace()

# Push parameters for START_DRAG (target, lockcenter, constrain)
# Stack order: constrain, lockcenter, target
# We'll use: target="mySprite", lockcenter=0, constrain=0
test2 += push_string("mySprite")  # target name
# Push 0.0 for lockcenter (type 1 = float)
test2 += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 0.0)
# Push 0.0 for constrain (type 1 = float)
test2 += struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 0.0)
test2 += bytes([0x27])  # START_DRAG (0x27)

test3 = push_string("Test 3: After START_DRAG") + trace()

# Now END_DRAG
test4 = bytes([0x28])  # END_DRAG
test4 += push_string("Test 4: After END_DRAG") + trace()

# Test calling END_DRAG again (should be safe no-op)
test5 = bytes([0x28])  # END_DRAG again
test5 += push_string("Test 5: After second END_DRAG") + trace()

# End of actions
action_end = bytes([0x00])  # END action

# Combine all actions
all_actions = test1 + test2 + test3 + test4 + test5 + action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

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
