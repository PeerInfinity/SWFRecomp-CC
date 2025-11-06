#!/usr/bin/env python3
import struct

# Create a minimal SWF7 file with a DefineFunction2 action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 supports DefineFunction2

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Create a simple DefineFunction2 that adds two numbers
# Function name: "add"
func_name = b'add\x00'

# NumParams: 2
num_params = struct.pack('<H', 2)

# RegisterCount: 3 (register 0 reserved, 1 and 2 for parameters)
register_count = struct.pack('B', 3)

# Flags: 0x0000 (no preloading or suppression for simplicity)
flags = struct.pack('<H', 0x0000)

# Parameters:
# Parameter 0: register 1, name "a"
param0_reg = struct.pack('B', 1)
param0_name = b'a\x00'

# Parameter 1: register 2, name "b"
param1_reg = struct.pack('B', 2)
param1_name = b'b\x00'

# Function body (very simple - just return undefined for now)
# We'll just have an END opcode
function_body = bytes([0x00])  # END

# CodeSize
code_size = struct.pack('<H', len(function_body))

# Build complete DefineFunction2 action
# Action code 0x8E with long form (has length field)
action_define_function2_data = (
    func_name +
    num_params +
    register_count +
    flags +
    param0_reg + param0_name +
    param1_reg + param1_name +
    code_size +
    function_body
)

# Calculate total length for the action
action_length = len(action_define_function2_data)
action_define_function2 = struct.pack('<BH', 0x8E, action_length) + action_define_function2_data

# Add a trace to show the function was defined
trace_string = b'Function defined\x00'
action_push = struct.pack('<BHB', 0x96, len(trace_string) + 1, 0)  # PUSH action
action_push += trace_string
action_trace = bytes([0x26])  # TRACE action

# End of actions
action_end = bytes([0x00])

# Combine all actions
all_actions = action_define_function2 + action_push + action_trace + action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

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
print(f"Function: add(a, b)")
print(f"Expected output: Function defined")
