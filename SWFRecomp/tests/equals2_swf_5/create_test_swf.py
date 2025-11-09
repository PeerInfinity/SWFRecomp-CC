#!/usr/bin/env python3
import struct

# Create a minimal SWF5 file with ActionEquals2 operations
# Test cases for type-aware equality comparison (ECMA-262)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 5  # SWF 5+ required for ActionEquals2

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for a float
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(value))

# Helper function to create PUSH action for a string
def push_string(s):
    s_bytes = s.encode('ascii') + b'\x00'  # Null-terminated
    length = 1 + len(s_bytes)
    return struct.pack('<BH', 0x96, length) + bytes([0x00]) + s_bytes

# Helper function to create PUSH action for null
def push_null():
    return struct.pack('<BHB', 0x96, 1, 2)  # Type 2 = null

# Helper function to create PUSH action for undefined
def push_undefined():
    return struct.pack('<BHB', 0x96, 1, 3)  # Type 3 = undefined

# Helper function to create PUSH action for boolean
def push_boolean(value):
    return struct.pack('<BHBB', 0x96, 2, 5, 1 if value else 0)  # Type 5 = boolean

# Helper function to create equals2 action
def equals2():
    return bytes([0x49])  # EQUALS2 opcode

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build action sequence for all test cases
actions = b''

# Test 1: Number equality - 5 == 5 (should be true = 1.0)
actions += push_float(5.0)   # arg2 (pushed first)
actions += push_float(5.0)   # arg1 (pushed second)
actions += equals2()
actions += trace()

# Test 2: Number equality - 5 == 3 (should be false = 0.0)
actions += push_float(3.0)   # arg2
actions += push_float(5.0)   # arg1
actions += equals2()
actions += trace()

# Test 3: String equality - "hello" == "hello" (should be true = 1.0)
actions += push_string("hello")  # arg2
actions += push_string("hello")  # arg1
actions += equals2()
actions += trace()

# Test 4: String equality - "hello" == "world" (should be false = 0.0)
actions += push_string("world")  # arg2
actions += push_string("hello")  # arg1
actions += equals2()
actions += trace()

# Test 5: Type coercion - 5 == "5" (should be true = 1.0)
actions += push_string("5")  # arg2 (string)
actions += push_float(5.0)   # arg1 (number)
actions += equals2()
actions += trace()

# Test 6: Type coercion - 10 == "10" (should be true = 1.0)
actions += push_string("10") # arg2 (string)
actions += push_float(10.0)  # arg1 (number)
actions += equals2()
actions += trace()

# Test 7: Boolean equality - true == true (should be true = 1.0)
actions += push_boolean(True)  # arg2
actions += push_boolean(True)  # arg1
actions += equals2()
actions += trace()

# Test 8: Boolean equality - true == false (should be false = 0.0)
actions += push_boolean(False) # arg2
actions += push_boolean(True)  # arg1
actions += equals2()
actions += trace()

# Test 9: Boolean to number - true == 1 (should be true = 1.0)
actions += push_float(1.0)     # arg2
actions += push_boolean(True)  # arg1
actions += equals2()
actions += trace()

# Test 10: Boolean to number - false == 0 (should be true = 1.0)
actions += push_float(0.0)      # arg2
actions += push_boolean(False)  # arg1
actions += equals2()
actions += trace()

# Test 11: null == null (should be true = 1.0)
actions += push_null()  # arg2
actions += push_null()  # arg1
actions += equals2()
actions += trace()

# Test 12: undefined == undefined (should be true = 1.0)
actions += push_undefined()  # arg2
actions += push_undefined()  # arg1
actions += equals2()
actions += trace()

# Test 13: null == undefined (should be true = 1.0) - ECMA-262 special case
actions += push_undefined()  # arg2
actions += push_null()       # arg1
actions += equals2()
actions += trace()

# Test 14: null == 0 (should be false = 0.0)
actions += push_float(0.0)  # arg2
actions += push_null()      # arg1
actions += equals2()
actions += trace()

# Test 15: undefined == 0 (should be false = 0.0)
actions += push_float(0.0)      # arg2
actions += push_undefined()     # arg1
actions += equals2()
actions += trace()

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

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Test cases:")
print("  1. 5 == 5 -> 1.0 (true)")
print("  2. 5 == 3 -> 0.0 (false)")
print('  3. "hello" == "hello" -> 1.0 (true)')
print('  4. "hello" == "world" -> 0.0 (false)')
print('  5. 5 == "5" -> 1.0 (true, type coercion)')
print('  6. 10 == "10" -> 1.0 (true, type coercion)')
print('  7. true == true -> 1.0 (true)')
print('  8. true == false -> 0.0 (false)')
print('  9. true == 1 -> 1.0 (true, boolean to number)')
print(' 10. false == 0 -> 1.0 (true, boolean to number)')
print(' 11. null == null -> 1.0 (true)')
print(' 12. undefined == undefined -> 1.0 (true)')
print(' 13. null == undefined -> 1.0 (true, ECMA-262 special case)')
print(' 14. null == 0 -> 0.0 (false)')
print(' 15. undefined == 0 -> 0.0 (false)')
