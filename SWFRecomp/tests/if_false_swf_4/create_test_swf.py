#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with ActionIf opcode
# Test case: False condition - does NOT jump, executes code normally
#
# Bytecode sequence:
# 1. PUSH 0.0 (falsy value)
# 2. IF +offset (jump if true - but won't jump because condition is false)
# 3. PUSH "not skipped" (this WILL execute because IF is false)
# 4. TRACE (this WILL execute)
# 5. PUSH "after"
# 6. TRACE
#
# Expected output:
# not skipped
# after

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper function to create PUSH action for a float
def push_float(value):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', float(value))

# Helper function to create PUSH action for a string
def push_string(value):
    str_bytes = value.encode('utf-8') + b'\x00'
    length = 1 + len(str_bytes)  # 1 byte for type + string + null terminator
    return struct.pack('<BH', 0x96, length) + bytes([0]) + str_bytes

# Helper function to create IF action with signed 16-bit offset
def action_if(offset):
    return struct.pack('<BH', 0x9D, 2) + struct.pack('<h', offset)  # <h for signed short

# Helper function to create trace action
def trace():
    return bytes([0x26])  # TRACE opcode

# Build the action sequence
actions = b''

# 1. Push 0.0 (falsy condition)
actions += push_float(0.0)

# Calculate the offset for the IF instruction (not that it matters - won't jump!)
# The offset would skip over: PUSH "not skipped" + TRACE
# But since condition is false, this section WILL execute
push_not_skipped = push_string("not skipped")
trace_not_skipped = trace()
bytes_to_skip = len(push_not_skipped) + len(trace_not_skipped)

# 2. IF with offset (won't jump because condition is 0.0 = false)
actions += action_if(bytes_to_skip)

# 3. PUSH "not skipped" (will execute because IF is false)
actions += push_not_skipped

# 4. TRACE (will execute)
actions += trace_not_skipped

# 5. PUSH "after"
actions += push_string("after")

# 6. TRACE
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
print(f"Offset for IF: {bytes_to_skip} bytes (won't be used - condition is false)")
print("Test: IF with false condition (0.0)")
print("Expected output:")
print("not skipped")
print("after")
