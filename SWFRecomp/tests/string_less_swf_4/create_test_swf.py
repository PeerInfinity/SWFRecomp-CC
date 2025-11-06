#!/usr/bin/env python3
import struct

# Create a SWF4 file with STRING_LESS (0x29) opcode tests
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

# Test Case 1: "apple" < "banana" => 1 (true)
# Stack order: push "apple" (left), push "banana" (right), then STRING_LESS computes left < right
test1 = push_string("apple")     # Push left operand (will become b after two pops)
test1 += push_string("banana")   # Push right operand (will become a after first pop)
test1 += bytes([0x29])           # STRING_LESS (0x29): computes b < a = apple < banana
test1 += bytes([0x26])           # TRACE

# Test Case 2: "zebra" < "apple" => 0 (false)
test2 = push_string("zebra")     # Push left operand
test2 += push_string("apple")    # Push right operand
test2 += bytes([0x29])           # STRING_LESS: computes zebra < apple
test2 += bytes([0x26])           # TRACE

# Test Case 3: "Apple" < "apple" => 1 (true, uppercase 'A'=65 < lowercase 'a'=97)
test3 = push_string("Apple")     # Push left operand
test3 += push_string("apple")    # Push right operand
test3 += bytes([0x29])           # STRING_LESS: computes Apple < apple
test3 += bytes([0x26])           # TRACE

# Test Case 4: "hello" < "hello" => 0 (equal strings, not less)
test4 = push_string("hello")     # Push left operand
test4 += push_string("hello")    # Push right operand
test4 += bytes([0x29])           # STRING_LESS: computes hello < hello
test4 += bytes([0x26])           # TRACE

# Test Case 5: "cat" < "catch" => 1 (true, shorter prefix is less)
test5 = push_string("cat")       # Push left operand
test5 += push_string("catch")    # Push right operand
test5 += bytes([0x29])           # STRING_LESS: computes cat < catch
test5 += bytes([0x26])           # TRACE

# Test Case 6: "" < "a" => 1 (true, empty string is less)
test6 = push_string("")          # Push left operand (empty string)
test6 += push_string("a")        # Push right operand
test6 += bytes([0x29])           # STRING_LESS: computes "" < a
test6 += bytes([0x26])           # TRACE

# Combine all tests
action_script = test1 + test2 + test3 + test4 + test5 + test6
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
print("1  (apple < banana)")
print("0  (zebra < apple)")
print("1  (Apple < apple)")
print("0  (hello < hello)")
print("1  (cat < catch)")
print("1  (empty < a)")
