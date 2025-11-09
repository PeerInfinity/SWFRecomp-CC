#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file to test the START_DRAG opcode (0x27)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing START_DRAG opcode
actions = b''

# Test Case 1: Basic drag (no constraints)
# startDrag("mySprite", false);
# trace("Drag started");
# Stack order (push): constrain(false), lock_center(false), target("mySprite")
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (constrain=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (lock_center=false)
actions += struct.pack('<f', 0.0)
sprite_name = b'mySprite\x00'
actions += struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH string
actions += sprite_name
actions += bytes([0x27])  # START_DRAG (0x27)

# Trace "Drag started"
trace_msg1 = b'Drag started\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg1) + 1, 0)
actions += trace_msg1
actions += bytes([0x26])  # TRACE

# Test Case 2: Drag with lock center
# trace("Before drag");
# startDrag("mySprite", true);
# trace("After drag");
trace_msg2 = b'Before drag\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg2) + 1, 0)
actions += trace_msg2
actions += bytes([0x26])  # TRACE

# Stack order (push): constrain(false), lock_center(true), target("mySprite")
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (constrain=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 1.0 (lock_center=true)
actions += struct.pack('<f', 1.0)
actions += struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH string
actions += sprite_name
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg3 = b'After drag\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg3) + 1, 0)
actions += trace_msg3
actions += bytes([0x26])  # TRACE

# Test Case 3: Drag with constraints
# startDrag("mySprite", false, 0, 0, 100, 100);
# trace("Constrained drag started");
# Stack order (push): x1, y1, x2, y2, constrain(true), lock_center(false), target("mySprite")
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (x1)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (y1)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 100.0 (x2)
actions += struct.pack('<f', 100.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 100.0 (y2)
actions += struct.pack('<f', 100.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 1.0 (constrain=true)
actions += struct.pack('<f', 1.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (lock_center=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH string
actions += sprite_name
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg4 = b'Constrained drag started\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg4) + 1, 0)
actions += trace_msg4
actions += bytes([0x26])  # TRACE

# Test Case 4: Type conversions - numeric target (should convert to string)
# startDrag(123, false);
# trace("Numeric target");
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (constrain=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (lock_center=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 123.0 (target as number)
actions += struct.pack('<f', 123.0)
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg5 = b'Numeric target\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg5) + 1, 0)
actions += trace_msg5
actions += bytes([0x26])  # TRACE

# Test Case 5: Type conversions - string boolean flags
# startDrag("mySprite", "1", "0");
# trace("String flags");
# Note: "1" should convert to 1 (true), "0" should convert to 0 (false)
actions += struct.pack('<BHB', 0x96, 2, 0)  # PUSH string "0"
actions += b'0\x00'
actions += struct.pack('<BHB', 0x96, 2, 0)  # PUSH string "1"
actions += b'1\x00'
actions += struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH string
actions += sprite_name
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg6 = b'String flags\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg6) + 1, 0)
actions += trace_msg6
actions += bytes([0x26])  # TRACE

# Test Case 6: Type conversions - string coordinates
# startDrag("mySprite", false, "10", "20", "30", "40");
# trace("String coordinates");
actions += struct.pack('<BHB', 0x96, 3, 0)  # PUSH string "10"
actions += b'10\x00'
actions += struct.pack('<BHB', 0x96, 3, 0)  # PUSH string "20"
actions += b'20\x00'
actions += struct.pack('<BHB', 0x96, 3, 0)  # PUSH string "30"
actions += b'30\x00'
actions += struct.pack('<BHB', 0x96, 3, 0)  # PUSH string "40"
actions += b'40\x00'
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 1.0 (constrain=true)
actions += struct.pack('<f', 1.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (lock_center=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, len(sprite_name) + 1, 0)  # PUSH string
actions += sprite_name
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg7 = b'String coordinates\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg7) + 1, 0)
actions += trace_msg7
actions += bytes([0x26])  # TRACE

# Test Case 7: Empty string target
# startDrag("", false);
# trace("Empty target");
empty_target = b'\x00'
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (constrain=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float 0.0 (lock_center=false)
actions += struct.pack('<f', 0.0)
actions += struct.pack('<BHB', 0x96, len(empty_target) + 1, 0)  # PUSH empty string
actions += empty_target
actions += bytes([0x27])  # START_DRAG (0x27)

trace_msg8 = b'Empty target\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg8) + 1, 0)
actions += trace_msg8
actions += bytes([0x26])  # TRACE

actions += bytes([0x00])  # END action

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

print("Created test.swf")
