#!/usr/bin/env python3
import struct

# Create a simple test that just defines a function and traces a message

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Build a very simple function body that just returns 42
func_body = b''

# Push 42.0
func_body += struct.pack('<BHB', 0x96, 5, 1)  # PUSH float
func_body += struct.pack('<f', 42.0)

# Return
func_body += struct.pack('<B', 0x3E)  # RETURN

# End
func_body += struct.pack('<B', 0x00)  # END

func_body_size = len(func_body)

# DEFINE_FUNCTION action (0x9B)
func_name = b'testFunc\x00'
num_params = struct.pack('<H', 0)  # No parameters
code_size = struct.pack('<H', func_body_size)

define_func_data = func_name + num_params + code_size + func_body
define_func_length = len(define_func_data)
action_define_func = struct.pack('<BH', 0x9B, define_func_length) + define_func_data

# Trace a message
action_push_msg = struct.pack('<BHB', 0x96, 18, 0)  # PUSH string
action_push_msg += b'Function defined\x00'

action_trace = struct.pack('<B', 0x26)  # TRACE

# End
action_end = struct.pack('<B', 0x00)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_define_func + action_push_msg + action_trace + action_end
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
print(f"Test: Define function testFunc() and trace 'Function defined'")
