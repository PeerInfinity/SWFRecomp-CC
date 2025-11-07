#!/usr/bin/env python3
import struct

# Create a minimal SWF3 file to test the GetURL opcode (0x83)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 3

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing GetURL opcode
actions = b''

# Test Case 1: Load external page with _blank
url1 = b'https://www.example.com\x00'
target1 = b'_blank\x00'
length1 = len(url1) + len(target1)
actions += struct.pack('<BH', 0x83, length1)
actions += url1 + target1
# Trace confirmation
trace_msg1 = b'URL load requested\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg1) + 1, 0)
actions += trace_msg1
actions += bytes([0x26])  # TRACE

# Test Case 2: Load into named frame
url2 = b'page.html\x00'
target2 = b'content\x00'
length2 = len(url2) + len(target2)
actions += struct.pack('<BH', 0x83, length2)
actions += url2 + target2
# Trace confirmation
trace_msg2 = b'Loading into frame\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg2) + 1, 0)
actions += trace_msg2
actions += bytes([0x26])  # TRACE

# Test Case 3: Load SWF into level
url3 = b'movie.swf\x00'
target3 = b'_level1\x00'
length3 = len(url3) + len(target3)
actions += struct.pack('<BH', 0x83, length3)
actions += url3 + target3
# Trace confirmation
trace_msg3 = b'Loading SWF into level 1\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg3) + 1, 0)
actions += trace_msg3
actions += bytes([0x26])  # TRACE

# Test Case 4: JavaScript call
url4 = b"javascript:alert('Hello')\x00"
target4 = b'\x00'  # Empty target for javascript: URLs
length4 = len(url4) + len(target4)
actions += struct.pack('<BH', 0x83, length4)
actions += url4 + target4
# Trace confirmation
trace_msg4 = b'JavaScript executed\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg4) + 1, 0)
actions += trace_msg4
actions += bytes([0x26])  # TRACE

# Test Case 5: Current window
url5 = b'https://www.example.com\x00'
target5 = b'_self\x00'
length5 = len(url5) + len(target5)
actions += struct.pack('<BH', 0x83, length5)
actions += url5 + target5
# Trace confirmation
trace_msg5 = b'Loading in current window\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg5) + 1, 0)
actions += trace_msg5
actions += bytes([0x26])  # TRACE

actions += bytes([0x00])  # END action

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
