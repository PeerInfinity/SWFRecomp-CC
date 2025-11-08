#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with NEW_METHOD operations
# Test: Create object with constructor properties and use NEW_METHOD

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF version 5 (supports NEW_METHOD)

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing NEW_METHOD

# Test 1: Create an object with a constructor property
# obj = { ArrayCtor: "Array" }
# Then use: new obj.ArrayCtor(5)

# Step 1: Create object using INIT_OBJECT with 1 property
# Push property value: "Array"
action_push_array_str = struct.pack('<BHB', 0x96, 1 + len("Array") + 1, 0)  # PUSH, length, type=0 (string)
action_push_array_str += b"Array\x00"

# Push property name: "ArrayCtor"
action_push_prop_name = struct.pack('<BHB', 0x96, 1 + len("ArrayCtor") + 1, 0)  # PUSH, length, type=0 (string)
action_push_prop_name += b"ArrayCtor\x00"

# Push number of properties: 1
action_push_num_props = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_num_props += struct.pack('<f', 1.0)

# INIT_OBJECT (0x43) - creates object with the property
action_init_object = bytes([0x43])

# Step 2: Store object in a variable for reuse
# Duplicate the object on stack
action_duplicate = bytes([0x4C])  # DUPLICATE is 0x4C

# Push variable name "testObj"
action_push_var_name = struct.pack('<BHB', 0x96, 1 + len("testObj") + 1, 0)  # PUSH, length, type=0 (string)
action_push_var_name += b"testObj\x00"

# Swap stack so variable name is below object value
action_stack_swap = bytes([0x4D])  # STACK_SWAP is 0x4D

# SET_VARIABLE (0x1D)
action_set_variable = bytes([0x1D])

# Step 3: Use NEW_METHOD to call obj.ArrayCtor(5)
# Push argument: 5.0
action_push_arg = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_arg += struct.pack('<f', 5.0)

# Push argument count: 1
action_push_arg_count = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_arg_count += struct.pack('<f', 1.0)

# Get the object back from variable
action_push_var_name_2 = struct.pack('<BHB', 0x96, 1 + len("testObj") + 1, 0)  # PUSH, length, type=0 (string)
action_push_var_name_2 += b"testObj\x00"

# GET_VARIABLE (0x1C)
action_get_variable = bytes([0x1C])

# Push method name: "ArrayCtor"
action_push_method_name = struct.pack('<BHB', 0x96, 1 + len("ArrayCtor") + 1, 0)  # PUSH, length, type=0 (string)
action_push_method_name += b"ArrayCtor\x00"

# NEW_METHOD (0x53)
action_new_method = bytes([0x53])

# Step 4: Get the length property of the created array
# Duplicate the array
action_duplicate_2 = bytes([0x4C])  # DUPLICATE is 0x4C

# Push property name "length"
action_push_length_str = struct.pack('<BHB', 0x96, 1 + len("length") + 1, 0)  # PUSH, length, type=0 (string)
action_push_length_str += b"length\x00"

# GET_MEMBER (0x4E) - gets array.length
action_get_member = bytes([0x4E])

# TRACE (0x26) - trace the length
action_trace = bytes([0x26])

# Pop the array object
action_pop = bytes([0x17])

# Test 2: Simple test with a message
# Push string "NEW_METHOD test completed"
test_message = "NEW_METHOD test completed"
action_push_message = struct.pack('<BHB', 0x96, 1 + len(test_message) + 1, 0)  # PUSH, length, type=0 (string)
action_push_message += test_message.encode('ascii') + b'\x00'

# Trace action (0x26)
action_trace_2 = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# Build complete action sequence
action_sequence = (
    # Create object with constructor property
    action_push_array_str +       # Push value "Array"
    action_push_prop_name +        # Push property name "ArrayCtor"
    action_push_num_props +        # Push 1.0 (number of properties)
    action_init_object +           # Create object { ArrayCtor: "Array" }
    action_duplicate +             # Duplicate object
    action_push_var_name +         # Push "testObj"
    action_stack_swap +            # Swap to get name below value
    action_set_variable +          # testObj = object

    # Use NEW_METHOD to create array
    action_push_arg +              # Push 5.0 (argument)
    action_push_arg_count +        # Push 1.0 (arg count)
    action_push_var_name_2 +       # Push "testObj"
    action_get_variable +          # Get testObj
    action_push_method_name +      # Push "ArrayCtor"
    action_new_method +            # new obj.ArrayCtor(5)

    # Get and trace the array length
    action_duplicate_2 +           # Duplicate array
    action_push_length_str +       # Push "length"
    action_get_member +            # Get array.length
    action_trace +                 # Trace length (should be 5)
    action_pop +                   # Pop array

    # Trace completion message
    action_push_message +          # Push success message
    action_trace_2 +               # trace(message)
    action_end
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

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test case:")
print("  1. Create object with property ArrayCtor='Array'")
print("  2. Use NEW_METHOD to call obj.ArrayCtor(5)")
print("  3. Trace the length property of created array")
print("Expected output:")
print("  5")
print("  NEW_METHOD test completed")
