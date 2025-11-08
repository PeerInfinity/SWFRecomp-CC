#!/usr/bin/env python3
"""
Create a test SWF for the Jump opcode (0x99).

Test: Forward jump to skip code
- Push 1, trace (executes)
- Jump forward (skip next push/trace)
- Push 2, trace (skipped)
- Push 3, trace (executes)

Expected output:
1
3
"""
import struct

# SWF header
signature = b'FWS'
version = 4
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

# Opcodes
action_push = 0x96
action_trace = 0x26
action_jump = 0x99
action_end = 0x00

# Test sequence:
# 1. Push 1 and trace (8 + 1 = 9 bytes)
push_1 = struct.pack('<BHB', action_push, 5, 1) + struct.pack('<f', 1.0)
trace_1 = bytes([action_trace])

# 2. Push 2 and trace (8 + 1 = 9 bytes) - this will be skipped
push_2 = struct.pack('<BHB', action_push, 5, 1) + struct.pack('<f', 2.0)
trace_2 = bytes([action_trace])

# 3. Jump instruction - skip push_2 + trace_2 (9 bytes)
# Jump format: opcode(1) + length(2) + offset(2) = 5 bytes
# Offset is from the byte AFTER this instruction, so offset = +9
jump_skip = struct.pack('<BH', action_jump, 2) + struct.pack('<h', 9)

# 4. Push 3 and trace (8 + 1 = 9 bytes)
push_3 = struct.pack('<BHB', action_push, 5, 1) + struct.pack('<f', 3.0)
trace_3 = bytes([action_trace])

# Assemble action sequence
action_sequence = (
    push_1 + trace_1 +      # Execute: output "1"
    jump_skip +             # Jump forward 9 bytes
    push_2 + trace_2 +      # Skipped: won't output "2"
    push_3 + trace_3 +      # Execute: output "3"
    bytes([action_end])
)

# Create DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_length = len(action_sequence)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + action_sequence

# Other tags
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

# Assemble SWF
tags = do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

# Write file
with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
print("Expected output:")
print("  1")
print("  3")
print("(The value 2 is skipped by the jump)")
