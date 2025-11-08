#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with CallMethod action using empty method name
# Tests: function obj() { return 42; }; trace(obj());
# This uses CallMethod with empty string to invoke function directly

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps
frame_count = struct.pack('<H', 1)  # 1 frame

# Define a simple function that returns 42
# DefineFunction2: name="", numParams=0, registerCount=0, flags=0
# Body: Push 42, Return

# Push 42.0
action_push_42 = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 42.0)

# Return (0x3E)
action_return = bytes([0x3E])

# Function body
function_body = action_push_42 + action_return

# DefineFunction2 header (0x8E)
# Format: name (null-terminated), numParams(u16), registerCount(u8), flags(u16), params[], codeSize(u16), body
function_name = b'testFunc\x00'  # Named function (we'll call it with empty method name)
num_params = struct.pack('<H', 0)  # 0 parameters
register_count = struct.pack('B', 0)  # 0 registers
flags = struct.pack('<H', 0)  # No flags
code_size = struct.pack('<H', len(function_body))

define_func2_data = (function_name + num_params + register_count + flags +
                     code_size + function_body)

# Use short header format for actions < 63 bytes
define_func2 = struct.pack('<BH', 0x8E, len(define_func2_data)) + define_func2_data

# Store function in variable "obj"
# Push string "obj"
var_name = b'obj\x00'
action_push_var_name = struct.pack('<BHB', 0x96, len(var_name) + 1, 0)
action_push_var_name += var_name

# SetVariable (0x1D)
action_set_variable = bytes([0x1D])

# Now call the function using CallMethod with empty method name
# Stack order: numArgs, function object, methodName (empty string)

# Push argument count (0.0)
action_push_zero = struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', 0.0)

# Get variable "obj" (the function)
obj_name = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(obj_name) + 1, 0)
action_push_obj_name += obj_name
action_get_variable = bytes([0x1C])

# Push empty method name
empty_string = b'\x00'
action_push_empty = struct.pack('<BHB', 0x96, len(empty_string) + 1, 0)
action_push_empty += empty_string

# CallMethod (0x52)
action_call_method = bytes([0x52])

# Trace the result
action_trace = bytes([0x26])

action_end = bytes([0x00])

# Combine all actions
actions = (define_func2 + action_push_var_name + action_set_variable +
           action_push_zero + action_push_obj_name + action_get_variable +
           action_push_empty + action_call_method + action_trace + action_end)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

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
print('Test: function obj() { return 42; }; trace(obj()); // Using CallMethod with empty name')
print("Expected output: 42")
