#!/usr/bin/env python3
import struct

# Test that defines a function and calls it

# SWF Header
signature = b'FWS'
version = 5

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Function body: return 42.0
func_body = b''
func_body += struct.pack('<BHB', 0x96, 5, 1)  # PUSH 42.0
func_body += struct.pack('<f', 42.0)
func_body += struct.pack('<B', 0x3E)  # RETURN
func_body += struct.pack('<B', 0x00)  # END

func_body_size = len(func_body)

# DEFINE_FUNCTION: function getValue() { return 42; }
func_name = b'getValue\x00'
num_params = struct.pack('<H', 0)
code_size = struct.pack('<H', func_body_size)

define_func_data = func_name + num_params + code_size + func_body
define_func_length = len(define_func_data)
action_define_func = struct.pack('<BH', 0x9B, define_func_length) + define_func_data

# Call the function: getValue()
# Push function name
action_push_name = struct.pack('<BHB', 0x96, 9, 0)  # PUSH string
action_push_name += b'getValue\x00'

# Call
action_call = struct.pack('<B', 0x9E)

# Trace the result
action_trace = struct.pack('<B', 0x26)

# End
action_end = struct.pack('<B', 0x00)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_data = action_define_func + action_push_name + action_call + action_trace + action_end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print(f"Test: function getValue() {{ return 42; }}; trace(getValue()) = 42")
