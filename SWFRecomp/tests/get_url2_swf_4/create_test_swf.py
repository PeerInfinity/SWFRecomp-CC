#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file to test the GetURL2 opcode (0x9A)
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing GetURL2 opcode
actions = b''

# Test Case 1: Load URL in new window (no method)
# Expected output: "URL load requested"
string_url1 = b'https://www.example.com\x00'
string_target1 = b'_blank\x00'
string_trace1 = b'URL load requested\x00'

# Push URL
actions += struct.pack('<BHB', 0x96, len(string_url1) + 1, 0)  # PUSH string
actions += string_url1

# Push target
actions += struct.pack('<BHB', 0x96, len(string_target1) + 1, 0)  # PUSH string
actions += string_target1

# GetURL2 with flags = 0x00 (no method, window target, load content)
actions += struct.pack('<BHB', 0x9A, 1, 0x00)

# Trace confirmation
actions += struct.pack('<BHB', 0x96, len(string_trace1) + 1, 0)  # PUSH string
actions += string_trace1
actions += bytes([0x26])  # TRACE

# Test Case 2: GET request with variables
# Expected output: "Loading variables"
string_url2 = b'script.php\x00'
string_target2 = b'_self\x00'
string_trace2 = b'Loading variables\x00'

# Push URL
actions += struct.pack('<BHB', 0x96, len(string_url2) + 1, 0)  # PUSH string
actions += string_url2

# Push target
actions += struct.pack('<BHB', 0x96, len(string_target2) + 1, 0)  # PUSH string
actions += string_target2

# GetURL2 with flags = 0x41 (GET method, window target, load variables)
# Flags: 01 (GET) in bits 7-6, 0 in bit 1 (window), 1 in bit 0 (load vars)
actions += struct.pack('<BHB', 0x9A, 1, 0x41)

# Trace confirmation
actions += struct.pack('<BHB', 0x96, len(string_trace2) + 1, 0)  # PUSH string
actions += string_trace2
actions += bytes([0x26])  # TRACE

# Test Case 3: POST request
# Expected output: "Posting data"
string_url3 = b'submit.php\x00'
string_target3 = b'_root\x00'
string_trace3 = b'Posting data\x00'

# Push URL
actions += struct.pack('<BHB', 0x96, len(string_url3) + 1, 0)  # PUSH string
actions += string_url3

# Push target
actions += struct.pack('<BHB', 0x96, len(string_target3) + 1, 0)  # PUSH string
actions += string_target3

# GetURL2 with flags = 0x81 (POST method, window target, load variables)
# Flags: 10 (POST) in bits 7-6, 0 in bit 1 (window), 1 in bit 0 (load vars)
actions += struct.pack('<BHB', 0x9A, 1, 0x81)

# Trace confirmation
actions += struct.pack('<BHB', 0x96, len(string_trace3) + 1, 0)  # PUSH string
actions += string_trace3
actions += bytes([0x26])  # TRACE

# Test Case 4: Load SWF into sprite
# Expected output: "Loading movie"
string_url4 = b'movie.swf\x00'
string_target4 = b'/clip\x00'
string_trace4 = b'Loading movie\x00'

# Push URL
actions += struct.pack('<BHB', 0x96, len(string_url4) + 1, 0)  # PUSH string
actions += string_url4

# Push target
actions += struct.pack('<BHB', 0x96, len(string_target4) + 1, 0)  # PUSH string
actions += string_target4

# GetURL2 with flags = 0x02 (no method, sprite target, load content)
# Flags: 00 (no method) in bits 7-6, 1 in bit 1 (sprite), 0 in bit 0 (load content)
actions += struct.pack('<BHB', 0x9A, 1, 0x02)

# Trace confirmation
actions += struct.pack('<BHB', 0x96, len(string_trace4) + 1, 0)  # PUSH string
actions += string_trace4
actions += bytes([0x26])  # TRACE

# Test Case 5: Dynamic URL from expression
# Expected output: "Opening page"
string_base = b'https://example.com/\x00'
string_page = b'page.html\x00'
string_target5 = b'_blank\x00'
string_trace5 = b'Opening page\x00'

# Push base URL
actions += struct.pack('<BHB', 0x96, len(string_base) + 1, 0)  # PUSH string
actions += string_base

# Push page
actions += struct.pack('<BHB', 0x96, len(string_page) + 1, 0)  # PUSH string
actions += string_page

# String concatenation (ADD for strings in SWF4 uses 0x21 STRING_ADD)
actions += bytes([0x21])  # STRING_ADD

# Push target
actions += struct.pack('<BHB', 0x96, len(string_target5) + 1, 0)  # PUSH string
actions += string_target5

# GetURL2 with flags = 0x00 (no method, window target, load content)
actions += struct.pack('<BHB', 0x9A, 1, 0x00)

# Trace confirmation
actions += struct.pack('<BHB', 0x96, len(string_trace5) + 1, 0)  # PUSH string
actions += string_trace5
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
