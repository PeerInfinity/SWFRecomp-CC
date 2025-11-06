#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with ADD2 (0x47) operations
# Tests type-aware addition with multiple type combinations

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF5 (ADD2 requires SWF5+)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Test 1: Number + Number (5 + 3 = 8)
# Push 3.0
action_push_3 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

# Push 5.0
action_push_5 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_5 += struct.pack('<f', 5.0)
actions += action_push_5

# ADD2 operation (0x47)
actions += bytes([0x47])

# Trace result
actions += bytes([0x26])

# Test 2: String + Number ("Total: " + 42 = "Total: 42")
# Push "Total: " first (left operand)
string2 = b'Total: \x00'  # Null-terminated string
action_push_str2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH action, type=0 (string)
action_push_str2 += string2
actions += action_push_str2

# Push 42.0 second (right operand)
action_push_42 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_42 += struct.pack('<f', 42.0)
actions += action_push_42

# ADD2 operation (0x47)
actions += bytes([0x47])

# Trace result
actions += bytes([0x26])

# Test 3: Number + String (5 + " items" = "5 items")
# Push 5.0 first (left operand)
action_push_5_again = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_5_again += struct.pack('<f', 5.0)
actions += action_push_5_again

# Push " items" second (right operand)
string3 = b' items\x00'  # Null-terminated string
action_push_str3 = struct.pack('<BHB', 0x96, len(string3) + 1, 0)  # PUSH action, type=0 (string)
action_push_str3 += string3
actions += action_push_str3

# ADD2 operation (0x47)
actions += bytes([0x47])

# Trace result
actions += bytes([0x26])

# End action (0x00)
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
print("  1. trace(5 + 3) = 8")
print("  2. trace('Total: ' + 42) = Total: 42")
print("  3. trace(5 + ' items') = 5 items")
