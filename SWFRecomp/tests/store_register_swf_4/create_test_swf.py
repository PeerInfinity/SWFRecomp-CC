#!/usr/bin/env python3
import struct

# Create a minimal SWF4 file with store_register operation
# Test: Store value 42 in register 0, then push and trace it

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: store 42 in register 0, push register 0, trace
# Push 42.0
action_push_42 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_42 += struct.pack('<f', 42.0)  # Float value 42.0

# StoreRegister 0 (0x87)
# This opcode has the high bit set, so it has a length field
action_store_reg = struct.pack('<BHB', 0x87, 1, 0)  # StoreRegister, length=1, register=0

# Push register 0 back to stack
# PUSH action with type 4 (register)
action_push_reg = struct.pack('<BHB', 0x96, 2, 4)  # PUSH action, length=2, type=4 (register)
action_push_reg += struct.pack('<B', 0)  # Register number 0

# Trace action (0x26)
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_push_42 + action_store_reg + action_push_reg + action_trace + action_end
do_action_length = len(do_action_data)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + do_action_data

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
print(f"Test: Store 42 in register 0, push register 0, trace = 42")
