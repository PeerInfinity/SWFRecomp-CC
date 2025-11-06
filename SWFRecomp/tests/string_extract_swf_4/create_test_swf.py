#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with STRING_EXTRACT opcode tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH string action
def push_string(s):
    string_bytes = s.encode('ascii') + b'\x00'  # Null-terminated
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes

# Helper function to create PUSH float action
def push_float(f):
    # PUSH action with type 1 (float)
    float_bytes = struct.pack('<f', f)
    return struct.pack('<BHB', 0x96, 5, 1) + float_bytes

# Test 1: Basic substring - substring("Hello World", 0, 5) → "Hello"
test1 = b''
test1 += push_string("Hello World")  # Push string
test1 += push_float(0.0)             # Push index
test1 += push_float(5.0)             # Push length
test1 += bytes([0x15])               # STRING_EXTRACT opcode
test1 += bytes([0x26])               # TRACE

# Test 2: Middle of string - substring("Hello World", 6, 5) → "World"
test2 = b''
test2 += push_string("Hello World")  # Push string
test2 += push_float(6.0)             # Push index
test2 += push_float(5.0)             # Push length
test2 += bytes([0x15])               # STRING_EXTRACT opcode
test2 += bytes([0x26])               # TRACE

# Test 3: Length extends beyond string - substring("Hello", 2, 100) → "llo"
test3 = b''
test3 += push_string("Hello")        # Push string
test3 += push_float(2.0)             # Push index
test3 += push_float(100.0)           # Push length (beyond string)
test3 += bytes([0x15])               # STRING_EXTRACT opcode
test3 += bytes([0x26])               # TRACE

# Test 4: Index beyond string length - substring("Hello", 10, 5) → ""
test4 = b''
test4 += push_string("Hello")        # Push string
test4 += push_float(10.0)            # Push index (beyond string)
test4 += push_float(5.0)             # Push length
test4 += bytes([0x15])               # STRING_EXTRACT opcode
test4 += bytes([0x26])               # TRACE

# Test 5: Zero length - substring("Hello", 2, 0) → ""
test5 = b''
test5 += push_string("Hello")        # Push string
test5 += push_float(2.0)             # Push index
test5 += push_float(0.0)             # Push length (zero)
test5 += bytes([0x15])               # STRING_EXTRACT opcode
test5 += bytes([0x26])               # TRACE

# Combine all tests
actions = test1 + test2 + test3 + test4 + test5
action_end = bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions + action_end)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions + action_end

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
print("Hello")
print("World")
print("llo")
print("")  # Empty string for test 4
print("")  # Empty string for test 5
