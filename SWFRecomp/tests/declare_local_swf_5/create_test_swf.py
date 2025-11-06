#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with DECLARE_LOCAL opcode test
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF5 for local variable support

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing DECLARE_LOCAL
# Note: DECLARE_LOCAL (0x41) pops a variable name from stack

# Test: Basic DECLARE_LOCAL test
# trace("Testing DECLARE_LOCAL opcode")
string1 = b'Testing DECLARE_LOCAL opcode\x00'
action_push1 = struct.pack('<BHB', 0x96, len(string1) + 1, 0)  # PUSH string
action_push1 += string1
action_trace1 = bytes([0x26])  # TRACE

# Push variable name "x" onto stack
var_name = b'x\x00'
action_push_var = struct.pack('<BHB', 0x96, len(var_name) + 1, 0)  # PUSH string
action_push_var += var_name

# Call DECLARE_LOCAL (0x41)
action_declare_local = bytes([0x41])

# trace("DECLARE_LOCAL completed (warning expected)")
string2 = b'DECLARE_LOCAL completed (warning expected)\x00'
action_push2 = struct.pack('<BHB', 0x96, len(string2) + 1, 0)  # PUSH string
action_push2 += string2
action_trace2 = bytes([0x26])  # TRACE

action_end = bytes([0x00])  # END action

# Combine all actions
actions = (action_push1 + action_trace1 +
           action_push_var + action_declare_local +
           action_push2 + action_trace2 +
           action_end)

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
print("Note: Test will show warning 'DECLARE_LOCAL outside function' - this is expected")
print("Full local variable functionality requires DEFINE_FUNCTION opcode (not yet implemented)")
