#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file testing the ActionOr (0x11) opcode
# Tests all four combinations:
# 1. trace(1 || 1) = 1
# 2. trace(1 || 0) = 1
# 3. trace(0 || 1) = 1
# 4. trace(0 || 0) = 0

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# Helper to create PUSH action for float
def push_float(value):
    push = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
    push += struct.pack('<f', float(value))
    return push

# OR action (0x11)
action_or = bytes([0x11])

# Trace action (0x26)
action_trace = bytes([0x26])

# Build ActionScript bytecode for all test cases
actions = b''

# Test 1: trace(1 || 1) = 1
# Stack order: push 1 (b), push 1 (a), OR -> result is 1 || 1 = 1
actions += push_float(1.0)  # Push 1.0 (second operand)
actions += push_float(1.0)  # Push 1.0 (first operand)
actions += action_or        # OR operation
actions += action_trace     # Trace result

# Test 2: trace(1 || 0) = 1
# Stack order: push 1 (b), push 0 (a), OR -> result is 1 || 0 = 1
actions += push_float(1.0)  # Push 1.0 (second operand)
actions += push_float(0.0)  # Push 0.0 (first operand)
actions += action_or        # OR operation
actions += action_trace     # Trace result

# Test 3: trace(0 || 1) = 1
# Stack order: push 0 (b), push 1 (a), OR -> result is 0 || 1 = 1
actions += push_float(0.0)  # Push 0.0 (second operand)
actions += push_float(1.0)  # Push 1.0 (first operand)
actions += action_or        # OR operation
actions += action_trace     # Trace result

# Test 4: trace(0 || 0) = 0
# Stack order: push 0 (b), push 0 (a), OR -> result is 0 || 0 = 0
actions += push_float(0.0)  # Push 0.0 (second operand)
actions += push_float(0.0)  # Push 0.0 (first operand)
actions += action_or        # OR operation
actions += action_trace     # Trace result

# End action (0x00)
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
print("Test cases:")
print("  1. trace(1 || 1) = 1")
print("  2. trace(1 || 0) = 1")
print("  3. trace(0 || 1) = 1")
print("  4. trace(0 || 0) = 0")
