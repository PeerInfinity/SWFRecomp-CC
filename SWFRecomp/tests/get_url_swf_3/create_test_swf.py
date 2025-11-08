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

# Test Case 6: Empty URL (edge case)
url6 = b'\x00'
target6 = b'_blank\x00'
length6 = len(url6) + len(target6)
actions += struct.pack('<BH', 0x83, length6)
actions += url6 + target6
# Trace confirmation
trace_msg6 = b'Empty URL test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg6) + 1, 0)
actions += trace_msg6
actions += bytes([0x26])  # TRACE

# Test Case 7: Empty target (edge case)
url7 = b'https://www.example.com\x00'
target7 = b'\x00'
length7 = len(url7) + len(target7)
actions += struct.pack('<BH', 0x83, length7)
actions += url7 + target7
# Trace confirmation
trace_msg7 = b'Empty target test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg7) + 1, 0)
actions += trace_msg7
actions += bytes([0x26])  # TRACE

# Test Case 8: File protocol
url8 = b'file:///path/to/file.html\x00'
target8 = b'_self\x00'
length8 = len(url8) + len(target8)
actions += struct.pack('<BH', 0x83, length8)
actions += url8 + target8
# Trace confirmation
trace_msg8 = b'File protocol test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg8) + 1, 0)
actions += trace_msg8
actions += bytes([0x26])  # TRACE

# Test Case 9: Level with number
url9 = b'app.swf\x00'
target9 = b'_level5\x00'
length9 = len(url9) + len(target9)
actions += struct.pack('<BH', 0x83, length9)
actions += url9 + target9
# Trace confirmation
trace_msg9 = b'Level 5 test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg9) + 1, 0)
actions += trace_msg9
actions += bytes([0x26])  # TRACE

# Test Case 10: Special characters in URL
url10 = b'https://example.com/page?foo=bar&baz=qux#anchor\x00'
target10 = b'_top\x00'
length10 = len(url10) + len(target10)
actions += struct.pack('<BH', 0x83, length10)
actions += url10 + target10
# Trace confirmation
trace_msg10 = b'Special chars test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg10) + 1, 0)
actions += trace_msg10
actions += bytes([0x26])  # TRACE

# Test Case 11: Relative URL
url11 = b'../parent/page.html\x00'
target11 = b'contentFrame\x00'
length11 = len(url11) + len(target11)
actions += struct.pack('<BH', 0x83, length11)
actions += url11 + target11
# Trace confirmation
trace_msg11 = b'Relative URL test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg11) + 1, 0)
actions += trace_msg11
actions += bytes([0x26])  # TRACE

# Test Case 12: Parent frame target
url12 = b'https://www.example.com/page\x00'
target12 = b'_parent\x00'
length12 = len(url12) + len(target12)
actions += struct.pack('<BH', 0x83, length12)
actions += url12 + target12
# Trace confirmation
trace_msg12 = b'Parent frame test\x00'
actions += struct.pack('<BHB', 0x96, len(trace_msg12) + 1, 0)
actions += trace_msg12
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
