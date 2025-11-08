#!/usr/bin/env python3
"""
Create a minimal SWF4 file to test the POP opcode (0x17).

Test logic:
1. Push string "wrong" (should be popped)
2. Pop (remove "wrong" from stack)
3. Push string "correct" (should remain)
4. Trace (should output "correct")

Expected output: "correct"
"""
import struct

# Create a minimal SWF4 file
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 4

# Frame size (RECT): 0-8000 twips (0-400 pixels)
# Simple RECT with all zeros for minimal size
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode:
# 1. PUSH "wrong"
string_wrong = b'wrong\x00'  # Null-terminated string
action_push_wrong = struct.pack('<BHB', 0x96, len(string_wrong) + 1, 0)  # PUSH action, length, type=0 (string)
action_push_wrong += string_wrong

# 2. POP (0x17) - remove "wrong" from stack
action_pop = bytes([0x17])  # POP action

# 3. PUSH "correct"
string_correct = b'correct\x00'  # Null-terminated string
action_push_correct = struct.pack('<BHB', 0x96, len(string_correct) + 1, 0)  # PUSH action, length, type=0 (string)
action_push_correct += string_correct

# 4. TRACE - should output "correct"
action_trace = bytes([0x26])  # TRACE action (0x26)

# 5. END
action_end = bytes([0x00])  # END action

# Combine all actions
actions = action_push_wrong + action_pop + action_push_correct + action_trace + action_end

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
print("Test: PUSH 'wrong' -> POP -> PUSH 'correct' -> TRACE")
print("Expected output: correct")
