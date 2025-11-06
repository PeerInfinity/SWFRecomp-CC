#!/usr/bin/env python3
import struct

# Create a SWF5 file that tests CALL_FUNCTION opcode (0x3D)
# This test calls parseInt("42") and traces the result

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5 (required for CallFunction)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace(parseInt("42"))
# Stack operations for CallFunction: arguments pushed first, then count, then function name
# This way function name is on top and can be popped first
# Stack layout before CallFunction (top to bottom):
#   function name (top - last push, first pop)
#   arg count
#   arguments (bottom - first push, last pop)

actions = b''

# Push "42" (the argument to parseInt) - pushed FIRST so it's at bottom
arg_string = b'42\x00'
action_push_arg = struct.pack('<BHB', 0x96, len(arg_string) + 1, 0)  # PUSH, length, type=0 (string)
action_push_arg += arg_string
actions += action_push_arg

# Push 1 (argument count) - pushed SECOND
# Type 1 = float (IEEE 754 single precision)
arg_count_bytes = struct.pack('<f', 1.0)
action_push_count = struct.pack('<BHB', 0x96, len(arg_count_bytes) + 1, 1)  # PUSH, length, type=1 (float)
action_push_count += arg_count_bytes
actions += action_push_count

# Push "parseInt" (function name) - pushed LAST so it's on top
func_name = b'parseInt\x00'
action_push_func = struct.pack('<BHB', 0x96, len(func_name) + 1, 0)  # PUSH, length, type=0 (string)
action_push_func += func_name
actions += action_push_func

# CallFunction (0x3D)
action_call_function = bytes([0x3D])
actions += action_call_function

# Trace (0x26)
action_trace = bytes([0x26])
actions += action_trace

# End (0x00)
action_end = bytes([0x00])
actions += action_end

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
print(f"Test: trace(parseInt('42')) - Expected output: 42")
