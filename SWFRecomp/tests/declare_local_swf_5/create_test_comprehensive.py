#!/usr/bin/env python3
"""
Comprehensive test for DECLARE_LOCAL (ActionDefineLocal2, 0x41)

This test creates a DefineFunction2 with local variables using ActionDefineLocal2.
Tests:
1. Basic local variable declaration
2. Local variable access
3. Local variable assignment
"""
import struct

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 for DefineFunction2

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Create a function that tests local variables
# function testLocal() {
#     var x;           // DECLARE_LOCAL
#     trace(typeof(x)); // Should output "undefined"
#     x = 42;          // SET_VARIABLE
#     trace(x);        // Should output "42"
# }
# testLocal();       // CALL_FUNCTION

func_name = b'testLocal\x00'
num_params = struct.pack('<H', 0)  # No parameters
register_count = struct.pack('B', 1)  # Just register 0
flags = struct.pack('<H', 0x0000)  # No special flags

# Function body
function_body = b''

# Push variable name "x" for DECLARE_LOCAL
var_name_x = b'x\x00'
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH string
function_body += var_name_x

# DECLARE_LOCAL (0x41)
function_body += bytes([0x41])

# typeof(x) - push "x" then GET_VARIABLE then TYPEOF then TRACE
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH "x"
function_body += var_name_x
function_body += bytes([0x1C])  # GET_VARIABLE
function_body += bytes([0x44])  # TYPE_OF
function_body += bytes([0x26])  # TRACE

# x = 42 - push 42, push "x", SET_VARIABLE
num_42 = struct.pack('<f', 42.0)
function_body += struct.pack('<BHB', 0x96, len(num_42) + 1, 1)  # PUSH float
function_body += num_42
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH "x"
function_body += var_name_x
function_body += bytes([0x1D])  # SET_VARIABLE

# trace(x) - push "x", GET_VARIABLE, TRACE
function_body += struct.pack('<BHB', 0x96, len(var_name_x) + 1, 0)  # PUSH "x"
function_body += var_name_x
function_body += bytes([0x1C])  # GET_VARIABLE
function_body += bytes([0x26])  # TRACE

# RETURN (implicit undefined return)
# function_body += bytes([0x3E])  # RETURN

# END
function_body += bytes([0x00])

code_size = struct.pack('<H', len(function_body))

# Build DefineFunction2
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

# Call the function: push 0 (arg count), push "testLocal", CALL_FUNCTION
arg_count_zero = struct.pack('<f', 0.0)
action_push_zero = struct.pack('<BHB', 0x96, len(arg_count_zero) + 1, 1)
action_push_zero += arg_count_zero

action_push_func_name = struct.pack('<BHB', 0x96, len(func_name), 0)
action_push_func_name += func_name

action_call_function = bytes([0x3D])  # CALL_FUNCTION

# Pop the return value
action_pop = bytes([0x17])  # POP

# End
action_end = bytes([0x00])

# Combine all actions
all_actions = (
    action_define_function2 +
    action_push_zero +
    action_push_func_name +
    action_call_function +
    action_pop +
    action_end
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_comprehensive.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_comprehensive.swf ({len(swf_data)} bytes)")
print("Expected output:")
print("undefined")
print("42")
