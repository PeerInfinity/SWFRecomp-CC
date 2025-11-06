#!/usr/bin/env python3
"""
Test script for ENUMERATE opcode (0x46)

This creates a simple SWF that tests object property enumeration.

Test Case: Basic enumeration
  var obj = {a: 1, b: 2, c: 3};
  enumerate obj and trace property names
  Expected output: property names (a, b, c in some order)
"""

import struct

# Create a minimal SWF4 file with ENUMERATE test
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Create object with three properties {a: 1, b: 2, c: 3}
# Stack order for InitObject: [value1, name1, value2, name2, value3, name3, count]

# Push property "a": value
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

# Push property "a": name
string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0)  # PUSH string
action_push_a += string_a
actions += action_push_a

# Push property "b": value
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

# Push property "b": name
string_b = b'b\x00'
action_push_b = struct.pack('<BHB', 0x96, len(string_b) + 1, 0)  # PUSH string
action_push_b += string_b
actions += action_push_b

# Push property "c": value
action_push_3 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

# Push property "c": name
string_c = b'c\x00'
action_push_c = struct.pack('<BHB', 0x96, len(string_c) + 1, 0)  # PUSH string
action_push_c += string_c
actions += action_push_c

# Push count (3 properties)
action_push_count = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_count += struct.pack('<f', 3.0)
actions += action_push_count

# InitObject - creates object with properties
action_init_object = bytes([0x43])  # INIT_OBJECT (0x43)
actions += action_init_object

# Store object in variable "obj"
# Duplicate first so we keep one copy for enumeration
action_duplicate = bytes([0x3D])  # DUPLICATE (0x3D)
actions += action_duplicate

string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)  # PUSH string
action_push_obj_name += string_obj
actions += action_push_obj_name

action_set_variable = bytes([0x1D])  # SET_VARIABLE (0x1D)
actions += action_set_variable

# Now enumerate the object
# Push variable name "obj" onto stack
actions += action_push_obj_name  # Push "obj" again

# Call ENUMERATE - this will pop "obj" name, look up the variable,
# and push null terminator + property names in reverse order
action_enumerate = bytes([0x46])  # ENUMERATE (0x46)
actions += action_enumerate

# Now stack has: [null, "c", "b", "a"] (assuming reverse order)
# We'll trace each property name by popping and tracing until we hit null

# For simplicity in this test, we'll just trace the first 3 property names
# In a real for..in loop, we'd use IF/JUMP to check for null terminator

# Trace first property (should be "a" or last added property)
action_trace = bytes([0x26])  # TRACE (0x26)
actions += action_trace

# Trace second property
actions += action_trace

# Trace third property
actions += action_trace

# Pop the null terminator
action_pop = bytes([0x17])  # POP (0x17)
actions += action_pop

# Add a completion message
string_complete = b'Enumeration test complete\x00'
action_push_complete = struct.pack('<BHB', 0x96, len(string_complete) + 1, 0)
action_push_complete += string_complete
actions += action_push_complete
actions += action_trace

# End action
action_end = bytes([0x00])
actions += action_end

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + actions

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
print("  Object enumeration: var obj = {a: 1, b: 2, c: 3}; enumerate and trace properties")
print("Expected output:")
print("  a")
print("  b")
print("  c")
print("  Enumeration test complete")
print("  (property names may appear in any consistent order)")
