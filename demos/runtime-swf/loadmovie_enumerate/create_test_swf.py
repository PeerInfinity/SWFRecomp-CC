#!/usr/bin/env python3
"""
Create test.swf — parent SWF that loads target.swf and enumerates what it can see.

Frame 1: this.createEmptyMovieClip("holder", 1); loadMovie("target.swf", "holder")
Frame 2: (wait for child to load)
Frame 3: Enumerate everything visible and trace results, then stop.
"""
import struct

# --- helpers ---

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

def push_null():
    return struct.pack('<BHB', 0x96, 1, 2)

def store_register(reg):
    return struct.pack('<BHB', 0x87, 1, reg)

def constant_pool(strings):
    data = struct.pack('<H', len(strings))
    for s in strings:
        data += s.encode('latin-1') + b'\x00'
    return struct.pack('<BH', 0x88, len(data)) + data

def make_do_action(actions):
    data = actions + b'\x00'  # END
    if len(data) >= 63:
        return struct.pack('<H', (12 << 6) | 0x3F) + struct.pack('<I', len(data)) + data
    return struct.pack('<H', (12 << 6) | len(data)) + data

def jump(offset):
    return struct.pack('<BHh', 0x99, 2, offset)

def if_action(offset):
    return struct.pack('<BHh', 0x9D, 2, offset)

def get_url2(send_vars, load_target, load_vars):
    """GetURL2 (0x9A). Flags byte: sendVars in bits 0-1, loadTarget bit 6, loadVars bit 7."""
    flags = (send_vars & 0x03) | ((load_target & 1) << 6) | ((load_vars & 1) << 7)
    return struct.pack('<BHB', 0x9A, 1, flags)

SHOW_FRAME = struct.pack('<H', 1 << 6)
END_TAG = b'\x00\x00'

TRACE = b'\x26'
SET_VARIABLE = b'\x1D'
GET_VARIABLE = b'\x1C'
SET_MEMBER = b'\x4F'
GET_MEMBER = b'\x4E'
CALL_FUNCTION = b'\x3D'
CALL_METHOD = b'\x52'
POP = b'\x17'
ADD2 = b'\x47'
ENUMERATE2 = b'\x55'
EQUALS2 = b'\x49'
TYPE_OF = b'\x44'
STOP = b'\x07'

# Constant pool
CP = [
    "holder",               # 0
    "target.swf",           # 1
    "createEmptyMovieClip", # 2
    "this",                 # 3
    "_global",              # 4
    "childGlobal",          # 5
    "MovieClip",            # 6
    "prototype",            # 7
    "childMethod",          # 8
    "_totalframes",         # 9
    "_currentframe",        # 10
    "=== holder properties (for..in) ===",  # 11
    "  ",                   # 12
    " = ",                  # 13
    "=== _global.childGlobal ===",          # 14
    "=== MovieClip.prototype.childMethod ===",  # 15
    "=== holder timeline info ===",         # 16
    "=== typeof checks ===",               # 17
    "typeof holder.",       # 18
    "myVar",                # 19
    "myFunc",               # 20
    "childNum",             # 21
    "childBool",            # 22
    "childObj",             # 23
    "=== calling holder.myFunc() ===",      # 24
    "=== calling holder.childMethod() ===", # 25
    "=== done ===",         # 26
    "_totalframes = ",      # 27
    "_currentframe = ",     # 28
    " = ",                  # 29  (duplicate, but fine)
]

# --- Frame 1: Create clip and load child ---
f1 = b''
f1 += constant_pool(CP)

# this.createEmptyMovieClip("holder", 1)
# CallMethod pops: methodName, object, argCount, then argCount args (first popped = arg[0])
# So push depth first (bottom), then name (top, popped first = arg[0])
f1 += push_float(1.0)    # depth (arg[1]) — pushed first, popped second
f1 += push_constant(0)   # "holder" (arg[0] = name) — pushed second, popped first
f1 += push_float(2.0)    # argCount = 2
f1 += push_constant(3)   # "this"
f1 += GET_VARIABLE        # → this MC
f1 += push_constant(2)   # "createEmptyMovieClip"
f1 += CALL_METHOD
f1 += POP                 # discard return value

# loadMovie("target.swf", "holder") via GetURL2
# Stack: URL, target (top→bottom for GetURL2: target on top, URL below)
f1 += push_constant(1)   # "target.swf" (URL)
f1 += push_constant(0)   # "holder" (target path)
f1 += get_url2(0, 1, 0)  # GetURL2: sendVars=NONE, loadTarget=1, loadVars=0

f1 += push_string("parent frame 1: loading target.swf")
f1 += TRACE

# --- Frame 2: Wait for child load ---
f2 = b''
f2 += push_string("parent frame 2: waiting for child")
f2 += TRACE

# --- Frame 3: Enumerate and inspect ---
f3 = b''

# === holder properties (for..in) ===
f3 += push_constant(11)  # header
f3 += TRACE

# for (var prop in holder) { trace("  " + prop + " = " + holder[prop]); }
f3 += push_constant(0)   # "holder"
f3 += GET_VARIABLE        # get holder MC
f3 += ENUMERATE2          # pushes null sentinel then property names

# Loop top: StoreRegister(0) to save name, check if null
# StoreRegister saves to register but does NOT pop.
# Equals2 pops TWO values — the null AND the name — consuming one name per iteration.
loop_top = b''
loop_top += store_register(0)  # reg0 = propName (keeps name on stack)
loop_top += push_null()        # push null on top
loop_top += EQUALS2            # pops null + name, pushes (name == null)?

# Loop body: format and trace
trace_body = b''
trace_body += push_constant(12)   # "  "
trace_body += push_register(0)    # propName
trace_body += ADD2                # "  " + propName
trace_body += push_constant(13)   # " = "
trace_body += ADD2                # "  propName = "
trace_body += push_constant(0)    # "holder"
trace_body += GET_VARIABLE
trace_body += push_register(0)    # propName
trace_body += GET_MEMBER          # holder[propName]
trace_body += ADD2                # "  propName = value"
trace_body += TRACE

# Calculate jump distances
jump_back_size = len(jump(0))
forward_skip = len(trace_body) + jump_back_size
backward_dist = -(len(loop_top) + len(if_action(0)) + len(trace_body) + jump_back_size)

f3 += loop_top + if_action(forward_skip) + trace_body + jump(backward_dist)

# === _global.childGlobal ===
f3 += push_constant(14)  # header
f3 += TRACE
f3 += push_constant(4)   # "_global"
f3 += GET_VARIABLE
f3 += push_constant(5)   # "childGlobal"
f3 += GET_MEMBER
f3 += TRACE

# === MovieClip.prototype.childMethod ===
f3 += push_constant(15)  # header
f3 += TRACE
f3 += push_constant(6)   # "MovieClip"
f3 += GET_VARIABLE
f3 += push_constant(7)   # "prototype"
f3 += GET_MEMBER
f3 += push_constant(8)   # "childMethod"
f3 += GET_MEMBER
f3 += TYPE_OF
f3 += TRACE

# === holder timeline info ===
f3 += push_constant(16)  # header
f3 += TRACE
# _totalframes
f3 += push_constant(27)  # "_totalframes = "
f3 += push_constant(0)   # "holder"
f3 += GET_VARIABLE
f3 += push_constant(9)   # "_totalframes"
f3 += GET_MEMBER
f3 += ADD2
f3 += TRACE
# _currentframe
f3 += push_constant(28)  # "_currentframe = "
f3 += push_constant(0)   # "holder"
f3 += GET_VARIABLE
f3 += push_constant(10)  # "_currentframe"
f3 += GET_MEMBER
f3 += ADD2
f3 += TRACE

# === typeof checks ===
f3 += push_constant(17)  # header
f3 += TRACE

for prop_idx in [19, 20, 21, 22, 23]:  # myVar, myFunc, childNum, childBool, childObj
    f3 += push_constant(18)   # "typeof holder."
    f3 += push_constant(prop_idx)  # property name
    f3 += ADD2                # "typeof holder.propName"
    f3 += push_constant(13)  # " = "
    f3 += ADD2                # "typeof holder.propName = "
    f3 += push_constant(0)   # "holder"
    f3 += GET_VARIABLE
    f3 += push_constant(prop_idx)
    f3 += GET_MEMBER
    f3 += TYPE_OF
    f3 += ADD2                # "typeof holder.propName = type"
    f3 += TRACE

# === calling holder.myFunc() ===
f3 += push_constant(24)  # header
f3 += TRACE
# holder.myFunc() via CallMethod
f3 += push_float(0.0)    # 0 args
f3 += push_constant(0)   # "holder"
f3 += GET_VARIABLE        # holder MC
f3 += push_constant(20)  # "myFunc"
f3 += CALL_METHOD
f3 += POP

# === calling holder.childMethod() ===
f3 += push_constant(25)  # header
f3 += TRACE
f3 += push_float(0.0)    # 0 args
f3 += push_constant(0)   # "holder"
f3 += GET_VARIABLE        # holder MC
f3 += push_constant(8)   # "childMethod"
f3 += CALL_METHOD
f3 += POP

# === done ===
f3 += push_constant(26)
f3 += TRACE

# FSCommand:quit to stop the test cleanly
f3 += push_string("")           # target (empty)
f3 += push_string("FSCommand:quit")  # URL
f3 += get_url2(0, 0, 0)        # GetURL2: send to browser/quit

# --- Assemble SWF ---
signature = b'FWS'
version = 7
rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 3)

tags = b''
tags += make_do_action(f1)
tags += SHOW_FRAME
tags += make_do_action(f2)
tags += SHOW_FRAME
tags += make_do_action(f3)
tags += SHOW_FRAME
tags += END_TAG

body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(body)
swf_data = signature + struct.pack('<BI', version, file_length) + body

with open('test.swf', 'wb') as f:
    f.write(swf_data)

print(f"Created test.swf ({len(swf_data)} bytes)")
