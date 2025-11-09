#!/usr/bin/env python3
import struct

def push_float(value):
    """Create PUSH action for a float value"""
    # PUSH action: 0x96 (long form)
    # Type 0 = String (not used here)
    # Type 1 = Float
    float_bytes = struct.pack('<f', value)
    data = struct.pack('B', 1) + float_bytes  # Type 1 = Float
    return struct.pack('<BH', 0x96, len(data)) + data

def push_string(s):
    """Create PUSH action for a string value"""
    # PUSH action: 0x96 (long form)
    # Type 0 = String
    string_bytes = s.encode('utf-8') + b'\x00'
    data = struct.pack('B', 0) + string_bytes  # Type 0 = String
    return struct.pack('<BH', 0x96, len(data)) + data

# Create a comprehensive SWF7 file with DefineFunction2 testing
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 supports DefineFunction2

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# =========================================================================
# Test 1: Function with register parameters that adds two numbers
# =========================================================================

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

# Function body: push registers 1 and 2, add them, return
# PUSH register 1 (parameter a)
action_push_reg1 = struct.pack('<BHB', 0x96, 2, 4)  # Type 4 = Register
action_push_reg1 += struct.pack('B', 1)  # Register 1

# PUSH register 2 (parameter b)
action_push_reg2 = struct.pack('<BHB', 0x96, 2, 4)  # Type 4 = Register
action_push_reg2 += struct.pack('B', 2)  # Register 2

# ADD action (0x0A)
action_add = bytes([0x0A])

# RETURN action (0x3E)
action_return = bytes([0x3E])

function_body = action_push_reg1 + action_push_reg2 + action_add + action_return

# CodeSize
code_size = struct.pack('<H', len(function_body))

# Build complete DefineFunction2 action
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
action_define_add = struct.pack('<BH', 0x8E, action_length) + action_define_function2_data

# =========================================================================
# Test 2: Function with no parameters that returns a constant
# =========================================================================

func2_name = b'getFortyTwo\x00'
num_params2 = struct.pack('<H', 0)  # No parameters
register_count2 = struct.pack('B', 1)  # Just register 0
flags2 = struct.pack('<H', 0x0000)

# Function body: push 42, return
function_body2 = push_float(42.0) + bytes([0x3E])  # RETURN
code_size2 = struct.pack('<H', len(function_body2))

action_define_function2_data2 = (
    func2_name +
    num_params2 +
    register_count2 +
    flags2 +
    code_size2 +
    function_body2
)

action_length2 = len(action_define_function2_data2)
action_define_getFortyTwo = struct.pack('<BH', 0x8E, action_length2) + action_define_function2_data2

# =========================================================================
# Test calls and output
# =========================================================================

# Test 1: Call add(10, 20)
test1 = (
    push_float(10.0) +  # Push first argument
    push_float(20.0) +  # Push second argument
    push_float(2.0) +   # Push number of arguments
    push_string("add") +  # Push function name
    bytes([0x3D]) +     # CALL_FUNCTION (0x3D)
    bytes([0x26])       # TRACE (0x26)
)

# Test 2: Call add(5, 7)
test2 = (
    push_float(5.0) +
    push_float(7.0) +
    push_float(2.0) +
    push_string("add") +
    bytes([0x3D]) +
    bytes([0x26])
)

# Test 3: Call getFortyTwo()
test3 = (
    push_float(0.0) +   # No arguments
    push_string("getFortyTwo") +
    bytes([0x3D]) +
    bytes([0x26])
)

# Test 4: Call add with more complex values
test4 = (
    push_float(100.5) +
    push_float(200.5) +
    push_float(2.0) +
    push_string("add") +
    bytes([0x3D]) +
    bytes([0x26])
)

# End of actions
action_end = bytes([0x00])

# Combine all actions
all_actions = (
    action_define_add +
    action_define_getFortyTwo +
    test1 +
    test2 +
    test3 +
    test4 +
    action_end
)

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
print(f"Test 1: add(10, 20) -> 30")
print(f"Test 2: add(5, 7) -> 12")
print(f"Test 3: getFortyTwo() -> 42")
print(f"Test 4: add(100.5, 200.5) -> 301")
