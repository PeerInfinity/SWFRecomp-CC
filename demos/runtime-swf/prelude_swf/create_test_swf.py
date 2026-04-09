#!/usr/bin/env python3
"""
Create test.swf — main SWF that verifies prelude runtime APIs are available.

Frame 1:
- Check _global.runtimeVersion
- Check _global.runtimeReady
- Call this.greet() (from MovieClip.prototype, set by prelude)
- Create new Greeter("World") and call sayHi()
"""
import struct

def push_string(s):
    data = s.encode('latin-1') + b'\x00'
    return struct.pack('<BHB', 0x96, len(data) + 1, 0) + data

def push_constant(idx):
    if idx < 256:
        return struct.pack('<BHB', 0x96, 2, 8) + bytes([idx])
    return struct.pack('<BHB', 0x96, 3, 9) + struct.pack('<H', idx)

def push_float(val):
    return struct.pack('<BHB', 0x96, 5, 1) + struct.pack('<f', val)

def push_register(reg):
    return struct.pack('<BHB', 0x96, 2, 4) + bytes([reg])

def store_register(reg):
    return struct.pack('<BHB', 0x87, 1, reg)

def constant_pool(strings):
    data = struct.pack('<H', len(strings))
    for s in strings:
        data += s.encode('latin-1') + b'\x00'
    return struct.pack('<BH', 0x88, len(data)) + data

def make_do_action(actions):
    data = actions + b'\x00'
    if len(data) >= 63:
        return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(data)) + data
    return struct.pack('<H', (12 << 6) | len(data)) + data

SHOW_FRAME = struct.pack('<H', 1 << 6)
END_TAG = b'\x00\x00'
TRACE = b'\x26'
GET_VARIABLE = b'\x1C'
SET_VARIABLE = b'\x1D'
GET_MEMBER = b'\x4E'
SET_MEMBER = b'\x4F'
CALL_FUNCTION = b'\x3D'
CALL_METHOD = b'\x52'
NEW_OBJECT = b'\x40'
POP = b'\x17'
ADD2 = b'\x47'
TYPE_OF = b'\x44'

CP = [
    "_global",          # 0
    "runtimeVersion",   # 1
    "runtimeReady",     # 2
    "greet",            # 3
    "this",             # 4
    "Greeter",          # 5
    "World",            # 6
    "sayHi",            # 7
    "=== checking prelude globals ===",  # 8
    "runtimeVersion = ",  # 9
    "runtimeReady = ",    # 10
    "=== calling this.greet() ===",  # 11
    "=== creating new Greeter('World') ===",  # 12
    "=== calling greeter.sayHi() ===",  # 13
    "typeof Greeter = ",  # 14
    "=== done ===",  # 15
]

f1 = b''
f1 += constant_pool(CP)

# === checking prelude globals ===
f1 += push_constant(8)
f1 += TRACE

# trace("runtimeVersion = " + _global.runtimeVersion)
f1 += push_constant(9)
f1 += push_constant(0)   # "_global"
f1 += GET_VARIABLE
f1 += push_constant(1)   # "runtimeVersion"
f1 += GET_MEMBER
f1 += ADD2
f1 += TRACE

# trace("runtimeReady = " + _global.runtimeReady)
f1 += push_constant(10)
f1 += push_constant(0)
f1 += GET_VARIABLE
f1 += push_constant(2)   # "runtimeReady"
f1 += GET_MEMBER
f1 += ADD2
f1 += TRACE

# === calling this.greet() ===
f1 += push_constant(11)
f1 += TRACE
# this.greet() via CallMethod
f1 += push_float(0.0)    # 0 args
f1 += push_constant(4)   # "this"
f1 += GET_VARIABLE
f1 += push_constant(3)   # "greet"
f1 += CALL_METHOD
f1 += POP

# trace("typeof Greeter = " + typeof(Greeter))
f1 += push_constant(14)
f1 += push_constant(5)   # "Greeter"
f1 += GET_VARIABLE
f1 += TYPE_OF
f1 += ADD2
f1 += TRACE

# === creating new Greeter("World") ===
f1 += push_constant(12)
f1 += TRACE

# var greeter = new Greeter("World")
# NewObject: push args, push argcount, push constructor_name
f1 += push_constant(6)   # "World" (arg)
f1 += push_float(1.0)    # 1 arg
f1 += push_constant(5)   # "Greeter"
f1 += NEW_OBJECT          # new Greeter("World") → object on stack
f1 += store_register(0)  # save to reg0
f1 += POP                 # pop from stack (we have it in reg0)

# === calling greeter.sayHi() ===
f1 += push_constant(13)
f1 += TRACE
# greeter.sayHi()
f1 += push_float(0.0)    # 0 args
f1 += push_register(0)   # greeter object
f1 += push_constant(7)   # "sayHi"
f1 += CALL_METHOD
f1 += POP

# === done ===
f1 += push_constant(15)
f1 += TRACE

# FSCommand:quit
f1 += push_string("")
f1 += push_string("FSCommand:quit")
f1 += struct.pack('<BHB', 0x9A, 1, 0)  # GetURL2

# Assemble SWF — version 7 (must match prelude)
signature = b'FWS'
version = 7
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

tags = make_do_action(f1) + SHOW_FRAME + END_TAG

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)
print(f"Created test.swf ({len(swf_data)} bytes)")
