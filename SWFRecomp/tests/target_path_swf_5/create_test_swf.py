#!/usr/bin/env python3
import struct

# Create a comprehensive SWF5 file to test the TARGET_PATH opcode (0x45)
# Tests multiple value types to ensure proper undefined handling

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5 (TARGET_PATH available in SWF 5+)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build actions for comprehensive tests
actions = []

# Test 1: targetPath(number) - should return undefined
# PUSH float 42.0
push_data = struct.pack('<Bf', 1, 42.0)
actions.append(struct.pack('<BH', 0x96, len(push_data)) + push_data)
# TARGET_PATH
actions.append(bytes([0x45]))
# TRACE
actions.append(bytes([0x26]))

# Test 2: targetPath(string) - should return undefined
# PUSH string "test"
str_val = b'test\x00'
push_data = struct.pack('<B', 0) + str_val
actions.append(struct.pack('<BH', 0x96, len(push_data)) + push_data)
# TARGET_PATH
actions.append(bytes([0x45]))
# TRACE
actions.append(bytes([0x26]))

# Test 3: targetPath(0) - should return undefined
# PUSH float 0.0
push_data = struct.pack('<Bf', 1, 0.0)
actions.append(struct.pack('<BH', 0x96, len(push_data)) + push_data)
# TARGET_PATH
actions.append(bytes([0x45]))
# TRACE
actions.append(bytes([0x26]))

# Test 4: targetPath(undefined) - should return undefined
# PUSH undefined (type 3)
push_data = struct.pack('<B', 3)
actions.append(struct.pack('<BH', 0x96, len(push_data)) + push_data)
# TARGET_PATH
actions.append(bytes([0x45]))
# TRACE
actions.append(bytes([0x26]))

# Test 5: targetPath(Object) - should return "_root" (placeholder until MovieClip support)
# PUSH empty string (will use InitObject if available, for now just push undefined to represent an object placeholder)
# Since we can't easily create objects without InitObject, we'll skip this test for now
# and add it later when we can properly test with objects

# Completion message
message = b'All tests complete\x00'
push_data = struct.pack('<B', 0) + message
actions.append(struct.pack('<BH', 0x96, len(push_data)) + push_data)
actions.append(bytes([0x26]))  # TRACE

# END action
actions.append(bytes([0x00]))

# Combine all actions
all_actions = b''.join(actions)

# DoAction tag (tag type 12)
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_header += struct.pack('<I', len(all_actions))
do_action_tag = do_action_header + all_actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Tests:")
print("  1. targetPath(42.0) - expects 'undefined'")
print("  2. targetPath('test') - expects 'undefined'")
print("  3. targetPath(0) - expects 'undefined'")
print("  4. targetPath(undefined) - expects 'undefined'")
