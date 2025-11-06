#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with NEW_OBJECT operations
# Test: new Array(3), new Object(), new Array(1, 2, 3)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for testing NEW_OBJECT

# Test 1: new Array(3) - creates array with length 3
# Push string "Array"
action_push_array_str = struct.pack('<BHB', 0x96, 1 + len("Array") + 1, 0)  # PUSH, length, type=0 (string)
action_push_array_str += b"Array\x00"

# Push 1 (number of arguments)
action_push_1 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_1 += struct.pack('<f', 1.0)

# Push 3.0 (the argument - array length)
action_push_3 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_3 += struct.pack('<f', 3.0)

# NEW_OBJECT (0x40)
action_new_object_1 = bytes([0x40])

# Pop the result (we can't trace objects directly without GET_MEMBER)
action_pop = bytes([0x17])

# Test 2: new Object() - creates empty object
# Push string "Object"
action_push_object_str = struct.pack('<BHB', 0x96, 1 + len("Object") + 1, 0)  # PUSH, length, type=0 (string)
action_push_object_str += b"Object\x00"

# Push 0 (number of arguments)
action_push_0 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_0 += struct.pack('<f', 0.0)

# NEW_OBJECT (0x40)
action_new_object_2 = bytes([0x40])

# Pop the result
action_pop_2 = bytes([0x17])

# Test 3: new Array(1, 2, 3) - creates array with elements [1, 2, 3]
# Push string "Array"
action_push_array_str_2 = struct.pack('<BHB', 0x96, 1 + len("Array") + 1, 0)  # PUSH, length, type=0 (string)
action_push_array_str_2 += b"Array\x00"

# Push 3 (number of arguments)
action_push_3_args = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_3_args += struct.pack('<f', 3.0)

# Push arguments: 1.0, 2.0, 3.0
action_push_arg_1 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_arg_1 += struct.pack('<f', 1.0)

action_push_arg_2 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_arg_2 += struct.pack('<f', 2.0)

action_push_arg_3 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH, length=5, type=1 (float)
action_push_arg_3 += struct.pack('<f', 3.0)

# NEW_OBJECT (0x40)
action_new_object_3 = bytes([0x40])

# Pop the result
action_pop_3 = bytes([0x17])

# Trace success message
# Push string "NEW_OBJECT tests completed"
test_message = "NEW_OBJECT tests completed"
action_push_message = struct.pack('<BHB', 0x96, 1 + len(test_message) + 1, 0)  # PUSH, length, type=0 (string)
action_push_message += test_message.encode('ascii') + b'\x00'

# Trace action (0x26)
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# Build complete action sequence
action_sequence = (
    action_push_3 +           # Push argument 3.0 (deepest on stack)
    action_push_1 +           # Push numArgs 1.0
    action_push_array_str +   # Push "Array"
    action_new_object_1 +     # new Array(3)
    action_pop +              # Pop result

    action_push_0 +           # Push numArgs 0.0
    action_push_object_str +  # Push "Object"
    action_new_object_2 +     # new Object()
    action_pop_2 +            # Pop result

    action_push_arg_1 +       # Push argument 1.0 (deepest on stack)
    action_push_arg_2 +       # Push argument 2.0
    action_push_arg_3 +       # Push argument 3.0 (topmost on stack)
    action_push_3_args +      # Push numArgs 3.0
    action_push_array_str_2 + # Push "Array"
    action_new_object_3 +     # new Array(1, 2, 3)
    action_pop_3 +            # Pop result

    action_push_message +     # Push success message
    action_trace +            # trace(message)
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
print("Test cases:")
print("  1. new Array(3) - creates array with length 3")
print("  2. new Object() - creates empty object")
print("  3. new Array(1, 2, 3) - creates array with elements")
print("Expected output: 'NEW_OBJECT tests completed'")
