#!/usr/bin/env python3
import struct

# Create a comprehensive SWF4 file to test STOP_SOUNDS opcode (0x09)
# Tests:
# 1. Basic functionality - opcode executes without error
# 2. Stack integrity - opcode doesn't affect the stack
# 3. Multiple calls - opcode can be called multiple times
# 4. Integration - opcode works with other operations

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test 1: Basic functionality
# trace("Test 1: Basic stopAllSounds");
string1 = b'Test 1: Basic stopAllSounds\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)
action_push1 += string1
action_trace1 = bytes([0x26])

# stopAllSounds();
action_stop_sounds1 = bytes([0x09])

# trace("Success");
string2 = b'Success\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)
action_push2 += string2
action_trace2 = bytes([0x26])

# Test 2: Stack integrity
# trace("Test 2: Stack integrity");
string3 = b'Test 2: Stack integrity\x00'
action_push3 = struct.pack('<BHB', 0x96, len(string3) + 1, 0)
action_push3 += string3
action_trace3 = bytes([0x26])

# Push 42
action_push_42 = struct.pack('<BHBf', 0x96, 5, 1, 42.0)  # PUSH action, type=1 (float for SWF4)

# stopAllSounds();
action_stop_sounds2 = bytes([0x09])

# trace(42) - should still be on stack
action_trace4 = bytes([0x26])

# Test 3: Multiple calls
# trace("Test 3: Multiple calls");
string5 = b'Test 3: Multiple calls\x00'
action_push5 = struct.pack('<BHB', 0x96, len(string5) + 1, 0)
action_push5 += string5
action_trace5 = bytes([0x26])

# stopAllSounds();
action_stop_sounds3 = bytes([0x09])

# stopAllSounds();
action_stop_sounds4 = bytes([0x09])

# trace("Success");
string6 = b'Success\x00'
action_push6 = struct.pack('<BHB', 0x96, len(string6) + 1, 0)
action_push6 += string6
action_trace6 = bytes([0x26])

# Test 4: Integration with arithmetic
# trace("Test 4: Integration test");
string7 = b'Test 4: Integration test\x00'
action_push7 = struct.pack('<BHB', 0x96, len(string7) + 1, 0)
action_push7 += string7
action_trace7 = bytes([0x26])

# Push 10
action_push_10 = struct.pack('<BHBf', 0x96, 5, 1, 10.0)  # type=1 for SWF4

# Push 5
action_push_5 = struct.pack('<BHBf', 0x96, 5, 1, 5.0)  # type=1 for SWF4

# stopAllSounds();
action_stop_sounds5 = bytes([0x09])

# Add (10 + 5 = 15)
action_add = bytes([0x0A])

# trace(15)
action_trace8 = bytes([0x26])

action_end = bytes([0x00])  # END action

# Combine all actions
actions = (action_push1 + action_trace1 + action_stop_sounds1 + action_push2 + action_trace2 +
           action_push3 + action_trace3 + action_push_42 + action_stop_sounds2 + action_trace4 +
           action_push5 + action_trace5 + action_stop_sounds3 + action_stop_sounds4 + action_push6 + action_trace6 +
           action_push7 + action_trace7 + action_push_10 + action_push_5 + action_stop_sounds5 + action_add + action_trace8 +
           action_end)

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
