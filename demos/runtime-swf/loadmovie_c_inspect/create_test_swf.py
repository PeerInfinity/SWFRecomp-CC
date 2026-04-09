#!/usr/bin/env python3
"""
Create test.swf — minimal parent that loads target.swf into "holder".
The actual inspection is done by test_harness.c after tick 2.
"""
import struct

def push_string(s):
    data = s.encode('latin-1') + b'\x00'
    return struct.pack('<BHB', 0x96, len(data) + 1, 0) + data

def push_constant(idx):
    return struct.pack('<BHB', 0x96, 2, 8) + bytes([idx])

def push_float(val):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', val)

def constant_pool(strings):
    data = struct.pack('<H', len(strings))
    for s in strings:
        data += s.encode('latin-1') + b'\x00'
    return struct.pack('<BH', 0x88, len(data)) + data

def get_url2(send_vars, load_target, load_vars):
    flags = (send_vars & 0x03) | ((load_target & 1) << 6) | ((load_vars & 1) << 7)
    return struct.pack('<BHB', 0x9A, 1, flags)

def make_do_action(actions):
    data = actions + b'\x00'
    if len(data) >= 63:
        return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(data)) + data
    return struct.pack('<H', (12 << 6) | len(data)) + data

SHOW_FRAME = struct.pack('<H', 1 << 6)
END_TAG = b'\x00\x00'
TRACE = b'\x26'
GET_VARIABLE = b'\x1C'
CALL_METHOD = b'\x52'
POP = b'\x17'

CP = ["holder", "target.swf", "createEmptyMovieClip", "this"]

# Frame 1: create holder and load child
f1 = b''
f1 += constant_pool(CP)
# this.createEmptyMovieClip("holder", 1)
f1 += push_float(1.0)
f1 += push_constant(0)   # "holder"
f1 += push_float(2.0)
f1 += push_constant(3)   # "this"
f1 += GET_VARIABLE
f1 += push_constant(2)   # "createEmptyMovieClip"
f1 += CALL_METHOD
f1 += POP
# loadMovie("target.swf", "holder")
f1 += push_constant(1)   # "target.swf"
f1 += push_constant(0)   # "holder"
f1 += get_url2(0, 1, 0)

# Frame 2: empty (wait for child)
f2 = b''

# Frame 3: empty (test_harness does the work after tick 2)
f3 = b''
f3 += push_string("FSCommand:quit")
f3 += push_string("")
f3 += get_url2(0, 0, 0)

# Assemble
signature = b'FWS'
version = 7
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 3)

tags = make_do_action(f1) + SHOW_FRAME
tags += make_do_action(f2) + SHOW_FRAME
tags += make_do_action(f3) + SHOW_FRAME
tags += END_TAG

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)
print(f"Created test.swf ({len(swf_data)} bytes)")
