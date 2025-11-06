#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with InitArray operations
# Test: Create empty array [] and array with elements [1, 2, 3]
# Note: Full testing requires GET_MEMBER opcode to access elements and length

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Test 1: Create empty array []
# Push 0 (count)
action_push_0 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_0 += struct.pack('<f', 0.0)  # Float value 0.0

# InitArray (0x42)
action_init_array_0 = bytes([0x42])

# Pop the array (since we can't access it yet without GET_MEMBER)
action_pop_1 = bytes([0x17])

# Test 2: Create array with 3 elements [1.0, 2.0, 3.0]
# Push elements in reverse order (rightmost first)
# Push 3.0 (elem_3)
action_push_3 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_3 += struct.pack('<f', 3.0)  # Float value 3.0

# Push 2.0 (elem_2)
action_push_2 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_2 += struct.pack('<f', 2.0)  # Float value 2.0

# Push 1.0 (elem_1)
action_push_1 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_1 += struct.pack('<f', 1.0)  # Float value 1.0

# Push 3 (count)
action_push_count_3 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_count_3 += struct.pack('<f', 3.0)  # Float value 3.0

# InitArray (0x42)
action_init_array_3 = bytes([0x42])

# Pop the array
action_pop_2 = bytes([0x17])

# Push success message
success_msg = b"Array creation test passed\x00"
action_push_success = struct.pack('<BHB', 0x96, len(success_msg) + 1, 0)  # PUSH action, type=0 (string)
action_push_success += success_msg

# Trace
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# Build complete action sequence
action_sequence = (
    action_push_0 + action_init_array_0 + action_pop_1 +
    action_push_3 + action_push_2 + action_push_1 + action_push_count_3 +
    action_init_array_3 + action_pop_2 +
    action_push_success + action_trace + action_end
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(action_sequence)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_sequence

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
print("Test: InitArray opcode")
print("  - Creates empty array []")
print("  - Creates array with 3 elements [1.0, 2.0, 3.0]")
print("Expected output: Array creation test passed")
