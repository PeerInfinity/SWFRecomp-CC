#!/usr/bin/env python3
"""
Comprehensive test for the ImplementsOp (0x2C) opcode.

This test covers:
1. Single interface implementation
2. Multiple interfaces implementation
3. Zero interfaces (edge case)
4. Verifies that ImplementsOp executes without crashing

Uses DefineFunction2 (opcode 0x8E) to create proper constructor functions
that have prototype objects, as required by the runtime's actionImplementsOp.
"""
import struct


def create_push_int(value):
    """Create PUSH action for an integer value."""
    return struct.pack('<BHB', 0x96, 5, 7) + struct.pack('<I', value)


def create_push_float(value):
    """Create PUSH action for a float value."""
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', value)


def create_push_string(string):
    """Create PUSH action for a string value."""
    string_bytes = string.encode('utf-8') + b'\x00'
    return struct.pack('<BHB', 0x96, len(string_bytes) + 1, 0) + string_bytes


def create_trace(message):
    """Create a trace statement."""
    return create_push_string(message) + bytes([0x26])  # Trace opcode


def create_define_function2():
    """Create an anonymous DefineFunction2 that pushes a function value onto the stack.

    DefineFunction2 format:
    - Opcode: 0x8E
    - Length: UI16 (of everything after the length field)
    - FunctionName: null-terminated string (empty = anonymous, pushed to stack)
    - NumParams: UI16 (0)
    - RegisterCount: UI8 (1)
    - Flags: UI16 (0x0000)
    - CodeSize: UI16 (size of body)
    - Body: the function body actions

    An anonymous function (empty name) gets pushed onto the stack.
    Body is just ActionEnd (0x00) for an empty constructor.
    """
    func_name = b'\x00'    # empty name = anonymous, result pushed to stack
    num_params = struct.pack('<H', 0)
    register_count = struct.pack('B', 1)
    flags = struct.pack('<H', 0x0000)
    body = bytes([0x00])   # ActionEnd - empty function body
    code_size = struct.pack('<H', len(body))

    payload = func_name + num_params + register_count + flags + code_size + body
    return struct.pack('<BH', 0x8E, len(payload)) + payload


# Create SWF7 file (ActionScript 2.0 support)
signature = b'FWS'  # Uncompressed SWF
version = 7

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode to test ImplementsOp
actions = b''

# TEST 1: Single interface
# ========================
# Create interface constructor function (has prototype automatically)
actions += create_define_function2()
# Stack: [interface1_func]

# Push interface count (1)
actions += create_push_float(1.0)
# Stack: [interface1_func, 1]

# Create constructor function
actions += create_define_function2()
# Stack: [interface1_func, 1, constructor_func]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 1: Single interface - OK")

# TEST 2: Multiple interfaces (3 interfaces)
# ===========================================
# Create interface constructor functions
actions += create_define_function2()  # interface1
actions += create_define_function2()  # interface2
actions += create_define_function2()  # interface3
# Stack: [iface1_func, iface2_func, iface3_func]

# Push interface count (3)
actions += create_push_float(3.0)
# Stack: [iface1_func, iface2_func, iface3_func, 3]

# Create constructor function
actions += create_define_function2()
# Stack: [iface1_func, iface2_func, iface3_func, 3, constructor_func]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 2: Multiple interfaces - OK")

# TEST 3: Zero interfaces (edge case)
# ====================================
# Push interface count (0)
actions += create_push_float(0.0)
# Stack: [0]

# Create constructor function
actions += create_define_function2()
# Stack: [0, constructor_func]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 3: Zero interfaces - OK")

# TEST 4: Two interfaces (different count)
# =========================================
# Create interface constructor functions
actions += create_define_function2()  # interface1
actions += create_define_function2()  # interface2
# Stack: [iface1_func, iface2_func]

# Push interface count (2)
actions += create_push_float(2.0)
# Stack: [iface1_func, iface2_func, 2]

# Create constructor function
actions += create_define_function2()
# Stack: [iface1_func, iface2_func, 2, constructor_func]

# Call ImplementsOp
actions += bytes([0x2C])  # ImplementsOp
# Stack: []

# Trace success
actions += create_trace("Test 4: Two interfaces - OK")

# Final success message
actions += create_trace("All ImplementsOp tests passed")

# End actions
actions += bytes([0x00])  # END

# DoAction tag (tag type 12)
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

# ShowFrame tag (tag type 1)
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
print("Comprehensive ImplementsOp test:")
print("  - Test 1: Single interface")
print("  - Test 2: Multiple interfaces (3)")
print("  - Test 3: Zero interfaces")
print("  - Test 4: Two interfaces")
print("")
print("Expected outputs:")
print("  Test 1: Single interface - OK")
print("  Test 2: Multiple interfaces - OK")
print("  Test 3: Zero interfaces - OK")
print("  Test 4: Two interfaces - OK")
print("  All ImplementsOp tests passed")
