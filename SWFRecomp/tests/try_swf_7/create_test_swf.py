#!/usr/bin/env python3
import struct

# Create a SWF7 file with try-catch-finally exception handling
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # ActionTry requires SWF 7+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ============================================================================
# Test Case: Basic try-catch
# try {
#     trace("In try");
#     throw "Error!";
#     trace("This won't print");
# } catch (e) {
#     trace("Caught: " + e);
# }
# trace("After try-catch");
# ============================================================================

# Helper function to create PUSH action for string
def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'
    length = len(s_bytes) + 1  # +1 for type byte
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes  # 0x96 = PUSH, type 0 = string

# Helper function to create TRACE action
def trace_action():
    return bytes([0x26])  # 0x26 = TRACE

# Helper function to create THROW action
def throw_action():
    return bytes([0x2A])  # 0x2A = THROW

# Helper function to create STRING_ADD action
def string_add_action():
    return bytes([0x21])  # 0x21 = STRING_ADD

# Helper function to create GET_VARIABLE action
def get_variable_action():
    return bytes([0x1C])  # 0x1C = GET_VARIABLE

# Try block: trace("In try"); throw "Error!"; trace("This won't print");
try_block = b''
try_block += push_string("In try")
try_block += trace_action()
try_block += push_string("Error!")
try_block += throw_action()
try_block += push_string("This won't print")
try_block += trace_action()

# Catch block: trace("Caught: " + e);
catch_block = b''
catch_block += push_string("Caught: ")
catch_block += push_string("e")
catch_block += get_variable_action()
catch_block += string_add_action()
catch_block += trace_action()

# Finally block: empty for this test
finally_block = b''

try_size = len(try_block)
catch_size = len(catch_block)
finally_size = len(finally_block)

# ActionTry bytecode
# Flags byte: bit 0 = has_catch (1), bit 1 = has_finally (0), bit 2 = catch_in_register (0)
flags = 0x01  # has_catch=1, has_finally=0, catch_in_register=0

catch_name = b'e\x00'  # catch variable name

# Calculate total length for ActionTry
action_try_payload = (
    struct.pack('<B', flags) +
    struct.pack('<H', try_size) +
    struct.pack('<H', catch_size) +
    struct.pack('<H', finally_size) +
    catch_name +
    try_block +
    catch_block +
    finally_block
)

action_try_length = len(action_try_payload)
action_try = struct.pack('<BH', 0x8F, action_try_length) + action_try_payload

# After try-catch: trace("After try-catch");
after_try_catch = b''
after_try_catch += push_string("After try-catch")
after_try_catch += trace_action()

# Complete action block
action_end = bytes([0x00])  # END action
all_actions = action_try + after_try_catch + action_end

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

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print(f"Try block size: {try_size} bytes")
print(f"Catch block size: {catch_size} bytes")
print(f"Finally block size: {finally_size} bytes")
