#!/usr/bin/env python3
"""
Simple test for local variables in DefineFunction2
Just declare a local variable and trace its type
"""
import struct

# SWF Header
signature = b'FWS'
version = 7  # SWF 7 for DefineFunction2

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Function: function test() { var x; trace(typeof(x)); }
func_name = b'test\x00'
num_params = struct.pack('<H', 0)
register_count = struct.pack('B', 1)
flags = struct.pack('<H', 0x0000)

# Function body
function_body = b''

# var x
var_name_x = b'x\x00'
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH "x"
function_body += var_name_x
function_body += bytes([0x41])  # DECLARE_LOCAL

# typeof(x)
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH "x"
function_body += var_name_x
function_body += bytes([0x1C])  # GET_VARIABLE
function_body += bytes([0x44])  # TYPE_OF
function_body += bytes([0x26])  # TRACE

# END
function_body += bytes([0x00])

code_size = struct.pack('<H', len(function_body))

action_define_function2_data = (
    func_name +
    num_params +
    register_count +
    flags +
    code_size +
    function_body
)

action_length = len(action_define_function2_data)
action_define_function2 = struct.pack('<BH', 0x8E, action_length) + action_define_function2_data

# Call the function
arg_count_zero = struct.pack('<f', 0.0)
action_push_zero = struct.pack('<BHB', 0x96, len(arg_count_zero) + 1, 1)
action_push_zero += arg_count_zero

action_push_func_name = struct.pack('<BHB', 0x96, len(func_name), 0)
action_push_func_name += func_name

action_call_function = bytes([0x3D])
action_pop = bytes([0x17])
action_end = bytes([0x00])

all_actions = (
    action_define_function2 +
    action_push_zero +
    action_push_func_name +
    action_call_function +
    action_pop +
    action_end
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

# ShowFrame & End
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

# Build SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_simple.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_simple.swf ({len(swf_data)} bytes)")
print("Expected: undefined")
