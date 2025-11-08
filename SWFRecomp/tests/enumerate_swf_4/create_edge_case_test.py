#!/usr/bin/env python3
"""
Comprehensive edge case test for ENUMERATE opcode (0x46)

Tests:
1. Empty object
2. Single property object
3. Object with multiple properties
4. Non-existent variable
"""

import struct

# Create a minimal SWF4 file with ENUMERATE edge case tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Build ActionScript bytecode
actions = b''

# Test 1: Empty object
# Create empty object and assign to variable
string_empty = b'emptyObj\x00'
action_push_empty_name = struct.pack('<BHB', 0x96, len(string_empty) + 1, 0)
action_push_empty_name += string_empty
actions += action_push_empty_name

# Push count (0 properties)
action_push_0 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_0 += struct.pack('<f', 0.0)
actions += action_push_0

# InitObject
actions += bytes([0x43])  # INIT_OBJECT

# SetVariable
actions += bytes([0x1D])  # SET_VARIABLE

# Enumerate empty object
actions += action_push_empty_name
actions += bytes([0x46])  # ENUMERATE

# Pop the null terminator and count
action_pop = bytes([0x17])  # POP
actions += action_pop

# Trace "Empty object test complete"
string_empty_complete = b'Empty object: OK\x00'
action_push_empty_complete = struct.pack('<BHB', 0x96, len(string_empty_complete) + 1, 0)
action_push_empty_complete += string_empty_complete
actions += action_push_empty_complete
actions += bytes([0x26])  # TRACE


# Test 2: Single property object
string_single = b'singleObj\x00'
action_push_single_name = struct.pack('<BHB', 0x96, len(string_single) + 1, 0)
action_push_single_name += string_single
actions += action_push_single_name

# Push property "only": value 42
action_push_42 = struct.pack('<BHB', 0x96, 1 + 4, 1)  # PUSH float
action_push_42 += struct.pack('<f', 42.0)
actions += action_push_42

string_only = b'only\x00'
action_push_only = struct.pack('<BHB', 0x96, len(string_only) + 1, 0)
action_push_only += string_only
actions += action_push_only

# Push count (1 property)
action_push_1 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_1 += struct.pack('<f', 1.0)
actions += action_push_1

# InitObject and SetVariable
actions += bytes([0x43])  # INIT_OBJECT
actions += bytes([0x1D])  # SET_VARIABLE

# Enumerate
actions += action_push_single_name
actions += bytes([0x46])  # ENUMERATE

# Trace the property name
actions += bytes([0x26])  # TRACE

# Pop null terminator
actions += action_pop

# Trace completion
string_single_complete = b'Single property: OK\x00'
action_push_single_complete = struct.pack('<BHB', 0x96, len(string_single_complete) + 1, 0)
action_push_single_complete += string_single_complete
actions += action_push_single_complete
actions += bytes([0x26])  # TRACE


# Test 3: Non-existent variable
string_noexist = b'doesNotExist\x00'
action_push_noexist = struct.pack('<BHB', 0x96, len(string_noexist) + 1, 0)
action_push_noexist += string_noexist
actions += action_push_noexist
actions += bytes([0x46])  # ENUMERATE

# Should push only null terminator
# Pop it
actions += action_pop

# Trace completion
string_noexist_complete = b'Non-existent variable: OK\x00'
action_push_noexist_complete = struct.pack('<BHB', 0x96, len(string_noexist_complete) + 1, 0)
action_push_noexist_complete += string_noexist_complete
actions += action_push_noexist_complete
actions += bytes([0x26])  # TRACE


# Test 4: Multiple properties (from original test)
string_obj = b'obj\x00'
action_push_obj_name = struct.pack('<BHB', 0x96, len(string_obj) + 1, 0)
action_push_obj_name += string_obj
actions += action_push_obj_name

# Push property "a": value 1
action_push_1f = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_1f += struct.pack('<f', 1.0)
actions += action_push_1f

string_a = b'a\x00'
action_push_a = struct.pack('<BHB', 0x96, len(string_a) + 1, 0)
action_push_a += string_a
actions += action_push_a

# Push property "b": value 2
action_push_2 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_2 += struct.pack('<f', 2.0)
actions += action_push_2

string_b = b'b\x00'
action_push_b = struct.pack('<BHB', 0x96, len(string_b) + 1, 0)
action_push_b += string_b
actions += action_push_b

# Push property "c": value 3
action_push_3 = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_3 += struct.pack('<f', 3.0)
actions += action_push_3

string_c = b'c\x00'
action_push_c = struct.pack('<BHB', 0x96, len(string_c) + 1, 0)
action_push_c += string_c
actions += action_push_c

# Push count (3 properties)
action_push_3f = struct.pack('<BHB', 0x96, 1 + 4, 1)
action_push_3f += struct.pack('<f', 3.0)
actions += action_push_3f

# InitObject and SetVariable
actions += bytes([0x43])  # INIT_OBJECT
actions += bytes([0x1D])  # SET_VARIABLE

# Enumerate
actions += action_push_obj_name
actions += bytes([0x46])  # ENUMERATE

# Trace first 3 properties
actions += bytes([0x26])  # TRACE
actions += bytes([0x26])  # TRACE
actions += bytes([0x26])  # TRACE

# Pop null terminator
actions += action_pop

# Final completion message
string_final = b'All edge case tests complete\x00'
action_push_final = struct.pack('<BHB', 0x96, len(string_final) + 1, 0)
action_push_final += string_final
actions += action_push_final
actions += bytes([0x26])  # TRACE

# End action
actions += bytes([0x00])

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

with open('test_edge_cases.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_edge_cases.swf ({len(swf_data)} bytes)")
print("\nEdge cases tested:")
print("  1. Empty object (0 properties)")
print("  2. Single property object")
print("  3. Non-existent variable")
print("  4. Multiple properties (3)")
print("\nExpected output:")
print("  Empty object: OK")
print("  only")
print("  Single property: OK")
print("  Non-existent variable: OK")
print("  c")
print("  b")
print("  a")
print("  All edge case tests complete")
