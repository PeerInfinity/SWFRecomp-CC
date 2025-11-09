#!/usr/bin/env python3
"""
Comprehensive test for ActionCall (0x9E)

Creates a multi-frame SWF to test:
1. Calling frames by number
2. Calling frames with string numbers
3. Calling with frame labels (logs as not implemented)
4. Calling with target paths (logs as not implemented)
5. Edge cases: negative frames, out of range
"""
import struct

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 3)  # 3 frames

def make_push_string(s):
    """Create a PUSH action for a string"""
    string_data = s.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_data) + 1, 0x00) + string_data

def make_push_float(f):
    """Create a PUSH action for a float"""
    return struct.pack('<BHBf', 0x96, 5, 0x00, f)

def make_call():
    """Create a CALL action (0x9E)"""
    return bytes([0x9E]) + struct.pack('<H', 0)

def make_trace():
    """Create a TRACE action (0x26)"""
    return bytes([0x26])

def make_do_action(actions):
    """Wrap actions in a DoAction tag"""
    do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
    do_action_length = len(actions)
    do_action_header += struct.pack('<I', do_action_length)
    return do_action_header + actions

def make_show_frame():
    """Create a ShowFrame tag"""
    return struct.pack('<H', 1 << 6)  # Tag type 1, short form

# Frame 0: Setup frame - calls frame 1 by number
frame_0_actions = (
    make_push_string("Frame 0 starting") +
    make_trace() +
    make_push_float(1.0) +  # Call frame 1
    make_call() +
    make_push_string("Frame 0 done") +
    make_trace() +
    bytes([0x00])  # END
)

# Frame 1: Called frame - traces and returns
frame_1_actions = (
    make_push_string("Frame 1 executed") +
    make_trace() +
    bytes([0x00])  # END
)

# Frame 2: Test various call scenarios
frame_2_actions = (
    # Test 1: Call frame 1 with string number
    make_push_string("Test 1: Call frame 1 with string") +
    make_trace() +
    make_push_string("1") +
    make_call() +

    # Test 2: Call with frame label (not implemented)
    make_push_string("Test 2: Call with label") +
    make_trace() +
    make_push_string("myLabel") +
    make_call() +

    # Test 3: Call with target path (not implemented)
    make_push_string("Test 3: Call with target path") +
    make_trace() +
    make_push_string("/movieclip:1") +
    make_call() +

    # Test 4: Negative frame (ignored)
    make_push_string("Test 4: Negative frame") +
    make_trace() +
    make_push_float(-1.0) +
    make_call() +

    # Test 5: Out of range frame (ignored)
    make_push_string("Test 5: Out of range") +
    make_trace() +
    make_push_float(99.0) +
    make_call() +

    make_push_string("All tests complete") +
    make_trace() +
    bytes([0x00])  # END
)

# Build tags
tags = (
    make_do_action(frame_0_actions) +
    make_show_frame() +
    make_do_action(frame_1_actions) +
    make_show_frame() +
    make_do_action(frame_2_actions) +
    make_show_frame() +
    bytes([0x00, 0x00])  # End tag
)

# Build complete SWF
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)  # Header is 8 bytes
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_comprehensive.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_comprehensive.swf ({len(swf_data)} bytes)")
print("3 frames:")
print("  Frame 0: Calls frame 1 by number")
print("  Frame 1: Simple trace")
print("  Frame 2: Tests all call scenarios")
