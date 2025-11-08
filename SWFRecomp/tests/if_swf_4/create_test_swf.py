#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with ActionIf opcode
# Test case: True condition - jumps over "skipped" to print "after"
#
# Bytecode sequence:
# 1. PUSH 1.0 (truthy value)
# 2. IF +offset (jump if true)
# 3. PUSH "skipped" (this should be skipped)
# 4. TRACE (this should be skipped)
# 5. PUSH "after" (jump target)
# 6. TRACE (this will execute)
#
# Expected output: "after"

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

# 1. Push 1.0 (truthy condition)
actions += push_float(1.0)

# Calculate the offset for the IF instruction
# We need to skip over: PUSH "skipped" + TRACE
push_skipped = push_string("skipped")
trace_skipped = trace()
bytes_to_skip = len(push_skipped) + len(trace_skipped)

# 2. IF with offset to jump over the skipped section
actions += action_if(bytes_to_skip)

# 3. PUSH "skipped" (will be skipped when condition is true)
actions += push_skipped

# 4. TRACE (will be skipped when condition is true)
actions += trace_skipped

# 5. PUSH "after" (jump target - where we land after the IF)
actions += push_string("after")

# 6. TRACE (this will execute)
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
print(f"Offset for IF: {bytes_to_skip} bytes")
print("Test: IF with true condition (1.0)")
print("Expected output: after")
