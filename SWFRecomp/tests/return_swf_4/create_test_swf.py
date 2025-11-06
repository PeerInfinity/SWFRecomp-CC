#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file demonstrating the RETURN opcode
#
# IMPORTANT: This is a compile-time test!
# The RETURN opcode (0x3E) generates a C return statement, which will
# exit the script immediately. This test demonstrates:
# - The opcode is correctly recognized by SWFRecomp
# - The actionReturn() function is called
# - A C return; statement is generated
# - The script exits early (proving RETURN works)
#
# Expected behavior:
# - "Script started" appears
# - Script exits via RETURN
# - "After RETURN" does NOT appear (proving early exit)
#
# Full function call/return testing requires DefineFunction (0x9B) opcode.

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Push and trace a start message
string_start = b'Script started\x00'
action_push_start = struct.pack('<BHB', 0x96, len(string_start) + 1, 0)  # PUSH
action_push_start += string_start
actions += action_push_start

action_trace_start = bytes([0x26])  # TRACE
actions += action_trace_start

# Push a return value (simulating function return)
value_42 = struct.pack('<f', 42.0)
action_push_42 = struct.pack('<BHB', 0x96, len(value_42) + 1, 1)  # PUSH
action_push_42 += value_42
actions += action_push_42

# RETURN opcode (0x3E)
# This will cause the generated C function to return immediately
action_return = bytes([0x3E])
actions += action_return

# Code after RETURN - this should never execute
string_after = b'After RETURN (should NOT appear)\x00'
action_push_after = struct.pack('<BHB', 0x96, len(string_after) + 1, 0)
action_push_after += string_after
actions += action_push_after

action_trace_after = bytes([0x26])
actions += action_trace_after

# End of actions
action_end = bytes([0x00])
actions += action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

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
print("\nExpected output:")
print("Script started")
print("\nNote: The message 'After RETURN' should NOT appear.")
print("This proves RETURN correctly exits the script early.")
print("\nFull function testing requires DefineFunction (0x9B) opcode.")
