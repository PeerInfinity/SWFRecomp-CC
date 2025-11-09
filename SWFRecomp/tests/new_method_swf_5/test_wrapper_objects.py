#!/usr/bin/env python3
"""
Test script to create a comprehensive test for wrapper objects (String, Number, Boolean).
This creates a separate SWF that tests wrapper object creation and value storage.
"""
import struct

# Create a minimal SWF5 file with NEW_METHOD wrapper object tests
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH string action
def push_string(s):
    data = struct.pack('<BHB', 0x96, 1 + len(s) + 1, 0)  # PUSH, length, type=0 (string)
    data += s.encode('ascii') + b'\x00'
    return data

# Helper function to create PUSH float action
def push_float(f):
    data = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
    data += struct.pack('<f', f)
    return data

# Test 1: Create Number wrapper object
# Create object with NumberCtor="Number"
test1_actions = (
    push_string("Number") +           # Value
    push_string("NumberCtor") +       # Property name
    push_float(1.0) +                 # Num properties
    bytes([0x43]) +                   # INIT_OBJECT

    # Duplicate and store in variable
    bytes([0x4C]) +                   # DUPLICATE
    push_string("ctorObj") +          # Variable name
    bytes([0x4D]) +                   # STACK_SWAP
    bytes([0x1D]) +                   # SET_VARIABLE

    # Call new obj.NumberCtor(42)
    push_float(42.0) +                # Argument: 42
    push_float(1.0) +                 # Arg count
    push_string("ctorObj") +          # Variable name
    bytes([0x1C]) +                   # GET_VARIABLE
    push_string("NumberCtor") +       # Method name
    bytes([0x53]) +                   # NEW_METHOD

    # Get valueOf property
    bytes([0x4C]) +                   # DUPLICATE result
    push_string("valueOf") +          # Property name
    bytes([0x4E]) +                   # GET_MEMBER
    bytes([0x26]) +                   # TRACE (should output 42)
    bytes([0x17])                     # POP the number object
)

# Test 2: Create String wrapper object
test2_actions = (
    push_string("String") +           # Value
    push_string("StringCtor") +       # Property name
    push_float(1.0) +                 # Num properties
    bytes([0x43]) +                   # INIT_OBJECT

    bytes([0x4C]) +                   # DUPLICATE
    push_string("ctorObj2") +         # Variable name
    bytes([0x4D]) +                   # STACK_SWAP
    bytes([0x1D]) +                   # SET_VARIABLE

    # Call new obj.StringCtor("hello")
    push_string("hello") +            # Argument: "hello"
    push_float(1.0) +                 # Arg count
    push_string("ctorObj2") +         # Variable name
    bytes([0x1C]) +                   # GET_VARIABLE
    push_string("StringCtor") +       # Method name
    bytes([0x53]) +                   # NEW_METHOD

    # Get valueOf property
    bytes([0x4C]) +                   # DUPLICATE result
    push_string("valueOf") +          # Property name
    bytes([0x4E]) +                   # GET_MEMBER
    bytes([0x26]) +                   # TRACE (should output "hello")
    bytes([0x17])                     # POP the string object
)

# Test 3: Create Boolean wrapper object
test3_actions = (
    push_string("Boolean") +          # Value
    push_string("BoolCtor") +         # Property name
    push_float(1.0) +                 # Num properties
    bytes([0x43]) +                   # INIT_OBJECT

    bytes([0x4C]) +                   # DUPLICATE
    push_string("ctorObj3") +         # Variable name
    bytes([0x4D]) +                   # STACK_SWAP
    bytes([0x1D]) +                   # SET_VARIABLE

    # Call new obj.BoolCtor(1) - true
    push_float(1.0) +                 # Argument: 1 (truthy)
    push_float(1.0) +                 # Arg count
    push_string("ctorObj3") +         # Variable name
    bytes([0x1C]) +                   # GET_VARIABLE
    push_string("BoolCtor") +         # Method name
    bytes([0x53]) +                   # NEW_METHOD

    # Get valueOf property
    bytes([0x4C]) +                   # DUPLICATE result
    push_string("valueOf") +          # Property name
    bytes([0x4E]) +                   # GET_MEMBER
    bytes([0x26]) +                   # TRACE (should output 1)
    bytes([0x17])                     # POP the boolean object
)

# Completion message
completion_actions = (
    push_string("Wrapper objects test completed") +
    bytes([0x26])                     # TRACE
)

# Build complete action sequence
action_sequence = (
    test1_actions +
    test2_actions +
    test3_actions +
    completion_actions +
    bytes([0x00])                     # END
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(action_sequence)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_sequence

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_wrapper.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_wrapper.swf ({len(swf_data)} bytes)")
print("Test cases:")
print("  1. Create Number wrapper with value 42")
print("  2. Create String wrapper with value 'hello'")
print("  3. Create Boolean wrapper with value 1 (true)")
print("Expected output:")
print("  42")
print("  hello")
print("  1")
print("  Wrapper objects test completed")
