#!/usr/bin/env python3
"""Probe: _invoke_sort_comparator (Array.sort user comparator), type-1 callee.

callArrayMethod's sort branch invokes a user comparator per comparison. Before
Stage 4 the type-1 arm pushed exactly 2 args forward with NO clamp to
param_count and NO pad — the fifteenth instance of the TYPE1_ARG_ORDER class.
A 1-param comparator bound `b` into its only param and leaked a stack slot per
comparison; a 3-param comparator popped a stale caller-stack slot into its
first param. Latent in the suite: gnash array-v5/v6 comparators declare
exactly 2 params (and are output_mismatch for accepted sort-UB reasons), so no
green test covered the arm at all — this repro doubles as the missing lock.

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode
(plain DefineFunction comparators). Expected output is pinned to the exact
comparison sequence the existing in-place quicksort produces (constant return
1) — derived from the fixed implementation, not from Flash intuition. Fixed by
migrating _invoke_sort_comparator onto invokeFunctionValue in dispatch Stage 4.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); INIT_ARRAY = bytes([0x42]); POP = bytes([0x17])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); RETURN = bytes([0x3E]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def getvar(name):
    return push_string(name) + GET_VARIABLE

def concat_var(var):
    # ... + var  (stack: prefix -> prefix+var)
    return getvar(var) + ADD2

actions = b''

# cmp1(x): trace("cmp1:"+x); return 1
actions += define_function('cmp1', ['x'],
    push_string('cmp1:') + concat_var('x') + TRACE + push_float(1.0) + RETURN)

# cmp3(p1,p2,p3): trace("cmp3:"+p1+","+p2+","+p3); return 1
actions += define_function('cmp3', ['p1', 'p2', 'p3'],
    push_string('cmp3:') + concat_var('p1')
    + push_string(',') + ADD2 + concat_var('p2')
    + push_string(',') + ADD2 + concat_var('p3')
    + TRACE + push_float(1.0) + RETURN)

# arr = [20, 10]  (InitArray pops count, then elem0 first)
actions += push_string('arr') + push_float(10.0) + push_float(20.0) + push_float(2.0) + INIT_ARRAY + SET_VARIABLE
# arr.sort(cmp1)
actions += (getvar('cmp1') + push_float(1.0) + getvar('arr') + push_string('sort')
            + CALL_METHOD + POP)
# trace("r1=" + arr.join(","))
actions += (push_string('r1=')
            + push_string(',') + push_float(1.0) + getvar('arr') + push_string('join') + CALL_METHOD
            + ADD2 + TRACE)

# arr2 = [7, 5]
actions += push_string('arr2') + push_float(5.0) + push_float(7.0) + push_float(2.0) + INIT_ARRAY + SET_VARIABLE
# arr2.sort(cmp3)
actions += (getvar('cmp3') + push_float(1.0) + getvar('arr2') + push_string('sort')
            + CALL_METHOD + POP)
# trace("r2=" + arr2.join(","))
actions += (push_string('r2=')
            + push_string(',') + push_float(1.0) + getvar('arr2') + push_string('join') + CALL_METHOD
            + ADD2 + TRACE)

actions += push_string('done') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
