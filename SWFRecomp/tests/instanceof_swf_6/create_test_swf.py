#!/usr/bin/env python3
import struct

# Create a minimal SWF6 file with instanceof operation
# Test: 5 instanceof Number should return false (primitives are not instances)

# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 6  # instanceof is available in SWF 6+

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for: trace(5 instanceof Number)
# Note: Since we don't have full object support yet, we test the simplified case
# Push "Number" string (representing constructor)
action_push_constr = struct.pack('<BHB', 0x96, 8, 0)  # PUSH action, length=8, type=0 (string)
action_push_constr += b'Number\x00'  # String "Number" with null terminator

# Push 5.0 (primitive number - should not be an instance)
action_push_5 = struct.pack('<BHB', 0x96, 5, 1)  # PUSH action, length=5, type=1 (float)
action_push_5 += struct.pack('<f', 5.0)  # Float value 5.0

# InstanceOf operation (0x54)
# Stack before: [... obj, constr]
# Stack after: [... result]
action_instanceof = bytes([0x54])

# Trace action (0x26)
action_trace = bytes([0x26])

# End action (0x00)
action_end = bytes([0x00])

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_data = action_push_constr + action_push_5 + action_instanceof + action_trace + action_end
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
print(f"Test: trace(5 instanceof Number)")
print(f"Expected output: 0 (false - primitives are not instances)")
