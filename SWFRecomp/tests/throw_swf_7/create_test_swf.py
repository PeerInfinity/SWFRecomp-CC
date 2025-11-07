#!/usr/bin/env python3
import struct

# Create a minimal SWF7 file with a THROW action
# SWF Header
signature = b'FWS'  # Uncompressed SWF
version = 7  # SWF 7 supports exception handling

# Frame size (RECT): 0-8000 twips (0-400 pixels)
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])

frame_rate = struct.pack('<H', 24 << 8)  # 24 fps (8.8 fixed point)
frame_count = struct.pack('<H', 1)  # 1 frame

# ActionScript bytecode for:
# trace("Before throw");
# throw "Error message";
# trace("After throw");  // Should not execute

# 1. Trace "Before throw"
before_string = b'Before throw\x00'
action_push_before = struct.pack('<BHB', 0x96, len(before_string) + 1, 0)
action_push_before += before_string
action_trace_before = bytes([0x26])  # TRACE action (0x26)

# 2. Push exception message and throw
error_string = b'Error message\x00'
action_push_error = struct.pack('<BHB', 0x96, len(error_string) + 1, 0)
action_push_error += error_string
action_throw = bytes([0x2A])  # THROW action (0x2A)

# 3. Trace "After throw" (should not execute)
after_string = b'After throw\x00'
action_push_after = struct.pack('<BHB', 0x96, len(after_string) + 1, 0)
action_push_after += after_string
action_trace_after = bytes([0x26])  # TRACE action (0x26)

# End of actions
action_end = bytes([0x00])

# Combine all actions
all_actions = (
    action_push_before + action_trace_before +
    action_push_error + action_throw +
    action_push_after + action_trace_after +
    action_end
)

# DoAction tag
do_action_header = struct.pack('<H', (12 << 6) | 0x3F)  # Tag type 12, long form
do_action_length = len(all_actions)
do_action_header += struct.pack('<I', do_action_length)
do_action_tag = do_action_header + all_actions

# ShowFrame tag
show_frame_tag = struct.pack('<H', 1 << 6)  # Tag type 1, short form

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
print("Test: throw 'Error message'")
print("Expected output:")
print("Before throw")
print("[Uncaught exception: Error message]")
