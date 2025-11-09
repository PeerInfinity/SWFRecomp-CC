#!/usr/bin/env python3
import struct

# Test try-finally (no exception)
signature = b'FWS'
version = 7

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

def push_string(s):
    s_bytes = s.encode('utf-8') + b'\x00'
    length = len(s_bytes) + 1
    return struct.pack('<BHB', 0x96, length, 0) + s_bytes

def trace_action():
    return bytes([0x26])

# Try block: trace("In try"); trace("No error");
try_block = b''
try_block += push_string("In try")
try_block += trace_action()
try_block += push_string("No error")
try_block += trace_action()

# Catch block: empty (no catch)
catch_block = b''

# Finally block: trace("In finally");
finally_block = b''
finally_block += push_string("In finally")
finally_block += trace_action()

try_size = len(try_block)
catch_size = len(catch_block)
finally_size = len(finally_block)

# Flags: has_catch=0, has_finally=1, catch_in_register=0
flags = 0x02  # Only finally block

action_try_payload = (
    struct.pack('<B', flags) +
    struct.pack('<H', try_size) +
    struct.pack('<H', catch_size) +
    struct.pack('<H', finally_size) +
    try_block +
    catch_block +
    finally_block
)

action_try = struct.pack('<BH', 0x8F, len(action_try_payload)) + action_try_payload

# After try-finally
after_actions = b''
after_actions += push_string("After try-finally")
after_actions += trace_action()

all_actions = action_try + after_actions + bytes([0x00])

do_action_header = struct.pack('<H', (12 << 6) | 0x3F)
do_action_header += struct.pack('<I', len(all_actions))
do_action_tag = do_action_header + all_actions

bg_color_tag = struct.pack('<HBB B', (9 << 6) | 3, 0xFF, 0xFF, 0xFF)
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

tags = bg_color_tag + do_action_tag + show_frame_tag + end_tag
body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)

swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test_finally.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test_finally.swf ({len(swf_data)} bytes)")
print("Expected output:")
print("In try")
print("No error")
print("In finally")
print("After try-finally")
