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

# Test Case 1: "apple" > "zebra" => 0 (false)
# Stack order: push "apple" (arg2), push "zebra" (arg1)
# STRING_GREATER pops arg1 ("zebra"), then arg2 ("apple"), computes arg2 > arg1
test1 = push_string("apple")     # Push arg2 (popped second)
test1 += push_string("zebra")    # Push arg1 (popped first)
test1 += bytes([0x68])           # STRING_GREATER (0x68): computes "apple" > "zebra" = 0
test1 += bytes([0x26])           # TRACE

# Test Case 2: "zebra" > "apple" => 1 (true)
test2 = push_string("zebra")     # Push arg2 (popped second)
test2 += push_string("apple")    # Push arg1 (popped first)
test2 += bytes([0x68])           # STRING_GREATER: computes "zebra" > "apple" = 1
test2 += bytes([0x26])           # TRACE

# Test Case 3: "hello" > "hello" => 0 (equal strings, not greater)
test3 = push_string("hello")     # Push arg2 (popped second)
test3 += push_string("hello")    # Push arg1 (popped first)
test3 += bytes([0x68])           # STRING_GREATER: computes "hello" > "hello" = 0
test3 += bytes([0x26])           # TRACE

# Test Case 4: "a" > "Z" => 1 (true, lowercase 'a'=97 > uppercase 'Z'=90)
test4 = push_string("a")         # Push arg2 (popped second)
test4 += push_string("Z")        # Push arg1 (popped first)
test4 += bytes([0x68])           # STRING_GREATER: computes "a" > "Z" = 1
test4 += bytes([0x26])           # TRACE

# Test Case 5: "hello" > "hello world" => 0 (false, shorter when prefix matches)
test5 = push_string("hello")            # Push arg2 (popped second)
test5 += push_string("hello world")     # Push arg1 (popped first)
test5 += bytes([0x68])                  # STRING_GREATER: computes "hello" > "hello world" = 0
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
print("0  (apple > zebra = false)")
print("1  (zebra > apple = true)")
print("0  (hello > hello = false)")
print("1  (a > Z = true, 97 > 90)")
print("0  (hello > hello world = false)")
