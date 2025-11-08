#!/usr/bin/env python3
import struct

# Create a comprehensive SWF3 file testing GoToLabel with various labels
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for comprehensive label testing

def create_trace(msg):
    """Create PUSH + TRACE actions for a message"""
    string_data = (msg + '\x00').encode('utf-8')
    action_push = struct.pack('<BHB', 0x96, len(string_data) + 1, 0)  # PUSH action, length, type=0 (string)
    action_push += string_data
    action_trace = bytes([0x26])  # TRACE action (0x26)
    return action_push + action_trace

def create_goto_label(label):
    """Create GoToLabel action with given label"""
    label_data = (label + '\x00').encode('utf-8')  # Null-terminated label string
    action_goto_label_length = len(label_data)
    action_goto_label = struct.pack('<BH', 0x8C, action_goto_label_length)  # GoToLabel action (0x8C), length
    action_goto_label += label_data
    return action_goto_label

# Build comprehensive test
actions = b''

# Test 1: Basic label
actions += create_trace("Test 1: Basic label")
actions += create_goto_label("scene1")

# Test 2: Label with underscores and numbers
actions += create_trace("Test 2: Label with underscores")
actions += create_goto_label("frame_2_start")

# Test 3: Label with mixed case
actions += create_trace("Test 3: Mixed case label")
actions += create_goto_label("MyScene")

# Test 4: Empty label (edge case)
actions += create_trace("Test 4: Empty label")
actions += create_goto_label("")

# Test 5: Single character label
actions += create_trace("Test 5: Single char label")
actions += create_goto_label("A")

# Test 6: Long label
actions += create_trace("Test 6: Long label")
actions += create_goto_label("this_is_a_very_long_frame_label_name")

# Test 7: Label with special characters
actions += create_trace("Test 7: Special chars label")
actions += create_goto_label("label-with-dash")

# Final trace
actions += create_trace("All tests complete")

# END action
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
