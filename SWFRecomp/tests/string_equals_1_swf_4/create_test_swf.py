#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with a string equals operation
# Test: "hello" eq "hello" = 1 (true)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace("hello" eq "hello")
# Push "hello" (string2)
string1 = b"hello\x00"
action_push_hello1 = struct.pack('<BHB', 0x96, 1 + len(string1), 0)  # PUSH action, length=1+string_len, type=0 (string)
action_push_hello1 += string1

# Push "hello" (string1, top of stack)
string2 = b"hello\x00"
action_push_hello2 = struct.pack('<BHB', 0x96, 1 + len(string2), 0)  # PUSH action, length=1+string_len, type=0 (string)
action_push_hello2 += string2

# String equals operation (0x13)
action_string_equals = bytes([0x13])

# Trace action (0x26)
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_push_hello1 + action_push_hello2 + action_string_equals + action_trace + action_end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

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
print(f"Test: trace(\"hello\" eq \"hello\") = 1")
