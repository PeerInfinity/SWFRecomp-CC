#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file testing CLONE_SPRITE opcode (0x24)
# Tests multiple scenarios including edge cases

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

def make_push_string(s):
    """Helper to create a PUSH action for a string"""
    string_bytes = s.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes

def make_push_float(f):
    """Helper to create a PUSH action for a float"""
    float_bytes = struct.pack('<f', f)
    return struct.pack('<BHB', 0x96, 5, 1) + float_bytes

# Build test actions
actions = b''

# Test 1: Basic clone operation
# duplicateMovieClip("originalSprite", "clonedSprite", 1)
actions += make_push_string("clonedSprite")  # target
actions += make_push_string("originalSprite")  # source
actions += make_push_float(1.0)  # depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 1: Basic clone")
actions += bytes([0x26])  # TRACE

# Test 2: Clone with different depth
# duplicateMovieClip("sprite1", "sprite2", 10)
actions += make_push_string("sprite2")  # target
actions += make_push_string("sprite1")  # source
actions += make_push_float(10.0)  # depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 2: Different depth")
actions += bytes([0x26])  # TRACE

# Test 3: Clone with negative depth
# duplicateMovieClip("source", "target", -5)
actions += make_push_string("target")  # target
actions += make_push_string("source")  # source
actions += make_push_float(-5.0)  # negative depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 3: Negative depth")
actions += bytes([0x26])  # TRACE

# Test 4: Clone with zero depth
# duplicateMovieClip("src", "dst", 0)
actions += make_push_string("dst")  # target
actions += make_push_string("src")  # source
actions += make_push_float(0.0)  # zero depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 4: Zero depth")
actions += bytes([0x26])  # TRACE

# Test 5: Clone with empty strings
# duplicateMovieClip("", "", 1)
actions += make_push_string("")  # empty target
actions += make_push_string("")  # empty source
actions += make_push_float(1.0)  # depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 5: Empty strings")
actions += bytes([0x26])  # TRACE

# Test 6: Clone with long names
# duplicateMovieClip("verylongspritename123", "anotherlongname456", 100)
actions += make_push_string("anotherlongname456")  # target
actions += make_push_string("verylongspritename123")  # source
actions += make_push_float(100.0)  # depth
actions += bytes([0x24])  # CLONE_SPRITE
actions += make_push_string("Test 6: Long names")
actions += bytes([0x26])  # TRACE

# Test 7: Final confirmation
actions += make_push_string("All tests complete")
actions += bytes([0x26])  # TRACE

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
print("Tests:")
print("  1. Basic clone operation")
print("  2. Clone with different depth")
print("  3. Clone with negative depth")
print("  4. Clone with zero depth")
print("  5. Clone with empty strings")
print("  6. Clone with long names")
print("  7. All tests complete confirmation")
