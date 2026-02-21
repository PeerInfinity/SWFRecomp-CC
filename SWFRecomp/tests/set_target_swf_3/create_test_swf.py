#!/usr/bin/env python3
import struct

# Create a SWF3 file that tests SetTarget (0x8B) with trace output
# In NO_GRAPHICS mode, SetTarget to any sprite name silently fails (no sprites exist).
# This test verifies:
# 1. trace("test1") works on main timeline
# 2. SetTarget("nonexistent") silently does nothing
# 3. trace("test2") still works (main timeline context preserved)
# 4. SetTarget("") resets to main timeline
# 5. trace("Done") confirms we're back on main timeline

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3  # SetTarget is available in SWF 3+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame


# Helper function to create a PUSH action for a string value
def push_string(s):
    s_bytes = s.encode('ascii') + b'\x00'  # Null-terminated string
    length = len(s_bytes) + 1  # +1 for the type byte
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes


# Helper function to create a SetTarget action (0x8B)
# Format: 0x8B + UI16 length + null-terminated target string
def set_target(target):
    target_bytes = target.encode('ascii') + b'\x00'
    return struct.pack('<BH', 0x8B, len(target_bytes)) + target_bytes


actions = b''

# Step 1: trace("test1") - on main timeline
actions += push_string("test1")
actions += bytes([0x26])  # TRACE

# Step 2: SetTarget("nonexistent") - silently fails in NO_GRAPHICS mode
actions += set_target("nonexistent")

# Step 3: trace("test2") - still works from main timeline
actions += push_string("test2")
actions += bytes([0x26])  # TRACE

# Step 4: SetTarget("") - reset to main timeline
actions += set_target("")

# Step 5: trace("Done") - confirm main timeline context
actions += push_string("Done")
actions += bytes([0x26])  # TRACE

# End action
actions += bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_header += struct.pack('<I', len(actions))
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
print("  1. trace('test1') -> test1")
print("  2. SetTarget('nonexistent') -> silently ignored")
print("  3. trace('test2') -> test2")
print("  4. SetTarget('') -> reset to main")
print("  5. trace('Done') -> Done")
