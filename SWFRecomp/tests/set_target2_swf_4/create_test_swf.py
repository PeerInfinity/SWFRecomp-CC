#!/usr/bin/env python3
import struct

# Create a SWF4 file with SET_TARGET2 (0x20) opcode tests
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

# Test Case 1: Set target to "mySprite"
test1 = push_string("mySprite")      # Push target name
test1 += bytes([0x20])               # SET_TARGET2 (0x20)
test1 += push_string("In mySprite")  # Message to trace
test1 += bytes([0x26])               # TRACE

# Test Case 2: Return to main timeline (empty string)
test2 = push_string("")              # Push empty string (return to main)
test2 += bytes([0x20])               # SET_TARGET2 (0x20)
test2 += push_string("Back to main") # Message to trace
test2 += bytes([0x26])               # TRACE

# Test Case 3: Set target to nested path
test3 = push_string("nested/path")   # Push nested path
test3 += bytes([0x20])               # SET_TARGET2 (0x20)
test3 += push_string("In nested path") # Message to trace
test3 += bytes([0x26])               # TRACE

# Test Case 4: Return to main again
test4 = push_string("")              # Push empty string
test4 += bytes([0x20])               # SET_TARGET2 (0x20)
test4 += push_string("Final main")   # Message to trace
test4 += bytes([0x26])               # TRACE

# Combine all tests
action_script = test1 + test2 + test3 + test4
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
print("// SetTarget2: mySprite")
print("In mySprite")
print("// SetTarget2: (main)")
print("Back to main")
print("// SetTarget2: nested/path")
print("In nested path")
print("// SetTarget2: (main)")
print("Final main")
