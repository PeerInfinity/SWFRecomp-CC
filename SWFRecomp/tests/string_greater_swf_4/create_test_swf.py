#!/usr/bin/env python3
import struct

# Create a SWF4 file with STRING_GREATER (0x68) opcode tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for a string
def push_string(s):
    string_data = s.encode('utf-8') + b'\x00'  # Null-terminated
    action = struct.pack('<BHB', 0x96, len(string_data) + 1, 0)  # PUSH, length, type=0 (string)
    action += string_data
    return action

# Test Case 1: "zebra" > "apple" => 1 (true)
# Stack order: push "apple" (b), push "zebra" (a), then STRING_GREATER computes b > a
test1 = push_string("apple")     # Push second operand (b)
test1 += push_string("zebra")    # Push first operand (a)
test1 += bytes([0x68])           # STRING_GREATER (0x68)
test1 += bytes([0x26])           # TRACE

# Test Case 2: "apple" > "zebra" => 0 (false)
test2 = push_string("zebra")     # Push second operand (b)
test2 += push_string("apple")    # Push first operand (a)
test2 += bytes([0x68])           # STRING_GREATER
test2 += bytes([0x26])           # TRACE

# Test Case 3: "hello" > "hello" => 0 (equal strings, not greater)
test3 = push_string("hello")     # Push second operand (b)
test3 += push_string("hello")    # Push first operand (a)
test3 += bytes([0x68])           # STRING_GREATER
test3 += bytes([0x26])           # TRACE

# Test Case 4: "Z" > "a" => 0 (false, uppercase 'Z'=90, lowercase 'a'=97)
test4 = push_string("a")         # Push second operand (b)
test4 += push_string("Z")        # Push first operand (a)
test4 += bytes([0x68])           # STRING_GREATER
test4 += bytes([0x26])           # TRACE

# Test Case 5: "hello world" > "hello" => 1 (true, longer string is greater)
test5 = push_string("hello")            # Push second operand (b)
test5 += push_string("hello world")     # Push first operand (a)
test5 += bytes([0x68])                  # STRING_GREATER
test5 += bytes([0x26])                  # TRACE

# Combine all tests
action_script = test1 + test2 + test3 + test4 + test5
action_end = bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(action_script + action_end)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_script + action_end

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
print("Expected output:")
print("1  (zebra > apple)")
print("0  (apple > zebra)")
print("0  (hello > hello)")
print("0  (Z > a)")
print("1  (hello world > hello)")
