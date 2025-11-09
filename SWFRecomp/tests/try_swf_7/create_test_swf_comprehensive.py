#!/usr/bin/env python3
import struct

# Create a SWF7 file with comprehensive try-catch-finally exception handling tests
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # ActionTry requires SWF 7+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ============================================================================
# Helper Functions
# ============================================================================

def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'
    length = len(s_bytes) + 1  # +1 for type byte
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes  # 0x96 = PUSH, type 0 = string

def push_number(n):
    # Push a float number
    return struct.pack('<BHBf', 0x96, 5, 6, n)  # type 6 = float

def trace_action():
    return bytes([0x26])  # 0x26 = TRACE

def throw_action():
    return bytes([0x2A])  # 0x2A = THROW

def string_add_action():
    return bytes([0x21])  # 0x21 = STRING_ADD

def get_variable_action():
    return bytes([0x1C])  # 0x1C = GET_VARIABLE

def create_try_action(try_block, catch_block, finally_block, catch_name=None, catch_register=None):
    """Create an ActionTry bytecode structure"""
    # Flags byte: bit 0 = has_catch, bit 1 = has_finally, bit 2 = catch_in_register
    has_catch = len(catch_block) > 0 and catch_name is not None or catch_register is not None
    has_finally = len(finally_block) > 0
    catch_in_register = catch_register is not None

    flags = 0
    if has_catch:
        flags |= 0x01
    if has_finally:
        flags |= 0x02
    if catch_in_register:
        flags |= 0x04

    try_size = len(try_block)
    catch_size = len(catch_block)
    finally_size = len(finally_block)

    # Build catch name/register field
    catch_field = b''
    if has_catch:
        if catch_in_register:
            catch_field = struct.pack('<B', catch_register)
        else:
            catch_field = catch_name.encode('utf-8') + b'\x00'

    # Calculate total length for ActionTry
    action_try_payload = (
        struct.pack('<B', flags) +
        struct.pack('<H', try_size) +
        struct.pack('<H', catch_size) +
        struct.pack('<H', finally_size) +
        catch_field +
        try_block +
        catch_block +
        finally_block
    )

    action_try_length = len(action_try_payload)
    return struct.pack('<BH', 0x8F, action_try_length) + action_try_payload

# ============================================================================
# Test Case 1: Basic try-catch
# ============================================================================
print("Test 1: Basic try-catch")

try_block_1 = b''
try_block_1 += push_string("Test 1: Basic try-catch")
try_block_1 += trace_action()
try_block_1 += push_string("Error!")
try_block_1 += throw_action()
try_block_1 += push_string("This won't print")
try_block_1 += trace_action()

catch_block_1 = b''
catch_block_1 += push_string("  Caught: ")
catch_block_1 += push_string("e")
catch_block_1 += get_variable_action()
catch_block_1 += string_add_action()
catch_block_1 += trace_action()

test_1 = create_try_action(try_block_1, catch_block_1, b'', catch_name='e')

# ============================================================================
# Test Case 2: Try-finally (no exception)
# ============================================================================
print("Test 2: Try-finally (no exception)")

try_block_2 = b''
try_block_2 += push_string("Test 2: Try-finally")
try_block_2 += trace_action()
try_block_2 += push_string("  In try block")
try_block_2 += trace_action()

finally_block_2 = b''
finally_block_2 += push_string("  In finally block")
finally_block_2 += trace_action()

test_2 = create_try_action(try_block_2, b'', finally_block_2)

# ============================================================================
# Test Case 3: Try-catch-finally
# ============================================================================
print("Test 3: Try-catch-finally")

try_block_3 = b''
try_block_3 += push_string("Test 3: Try-catch-finally")
try_block_3 += trace_action()
try_block_3 += push_string("  In try")
try_block_3 += trace_action()
try_block_3 += push_string("Error in test 3")
try_block_3 += throw_action()

catch_block_3 = b''
catch_block_3 += push_string("  In catch: ")
catch_block_3 += push_string("e")
catch_block_3 += get_variable_action()
catch_block_3 += string_add_action()
catch_block_3 += trace_action()

finally_block_3 = b''
finally_block_3 += push_string("  In finally")
finally_block_3 += trace_action()

test_3 = create_try_action(try_block_3, catch_block_3, finally_block_3, catch_name='e')

# ============================================================================
# Test Case 4: No exception thrown
# ============================================================================
print("Test 4: No exception thrown")

try_block_4 = b''
try_block_4 += push_string("Test 4: No exception")
try_block_4 += trace_action()
try_block_4 += push_string("  Try block executed")
try_block_4 += trace_action()
try_block_4 += push_string("  No error")
try_block_4 += trace_action()

catch_block_4 = b''
catch_block_4 += push_string("  This catch won't execute")
catch_block_4 += trace_action()

test_4 = create_try_action(try_block_4, catch_block_4, b'', catch_name='e')

# ============================================================================
# Test Case 5: Different exception types
# ============================================================================
print("Test 5: Different exception types")

# Test 5a: Throw a number
try_block_5a = b''
try_block_5a += push_string("Test 5: Throw number")
try_block_5a += trace_action()
try_block_5a += push_number(42.0)
try_block_5a += throw_action()

catch_block_5a = b''
catch_block_5a += push_string("  Caught number: ")
catch_block_5a += push_string("e")
catch_block_5a += get_variable_action()
catch_block_5a += string_add_action()
catch_block_5a += trace_action()

test_5a = create_try_action(try_block_5a, catch_block_5a, b'', catch_name='e')

# ============================================================================
# Test Case 6: Finally with exception
# ============================================================================
print("Test 6: Finally always executes")

try_block_6 = b''
try_block_6 += push_string("Test 6: Finally with exception")
try_block_6 += trace_action()
try_block_6 += push_string("  Before throw")
try_block_6 += trace_action()
try_block_6 += push_string("Error")
try_block_6 += throw_action()

catch_block_6 = b''
catch_block_6 += push_string("  In catch")
catch_block_6 += trace_action()

finally_block_6 = b''
finally_block_6 += push_string("  Finally executed")
finally_block_6 += trace_action()

test_6 = create_try_action(try_block_6, catch_block_6, finally_block_6, catch_name='e')

# ============================================================================
# Assemble all tests
# ============================================================================

all_actions = b''
all_actions += test_1
all_actions += test_2
all_actions += test_3
all_actions += test_4
all_actions += test_5a
all_actions += test_6

# End marker
all_actions += push_string("All tests completed")
all_actions += trace_action()
all_actions += bytes([0x00])  # END action

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

# SetBackgroundColor tag (white)
bg_color_tag = struct.pack('<HBB B', (9 << 6) | 3, 0xFF, 0xFF, 0xFF)  # Tag type 9, RGB

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form (length 0)

# End tag
end_tag = bytes([0x00, 0x00])

# Build complete SWF
tags = bg_color_tag + do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags

file_length = 8 + len(body)  # Header is 8 bytes

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_comprehensive.swf', 'wb') as f:
    f.write(swf_data)

print(f"\nCreated test_comprehensive.swf ({len(swf_data)} bytes)")
print(f"Total action bytes: {len(all_actions)} bytes")
