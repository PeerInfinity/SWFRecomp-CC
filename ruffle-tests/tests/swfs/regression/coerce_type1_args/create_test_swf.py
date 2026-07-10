#!/usr/bin/env python3
"""Probe: the coercion dispatch paths (objectCallValueOf / objectToPrimitive /
convertFloat / objectCallToString), type-1 callee with declared params.

Every coercion path invokes a user valueOf/toString with ZERO args. Before
Stage 4 the type-1 arms of all four sites pushed NOTHING at all, so a plain
`DefineFunction` valueOf/toString with declared params had its prologue pop
the caller's LIVE eval stack (in convertFloat's case the operand under
conversion). The core's canonical loop pads to param_count with undefined —
the sixteenth instance of the TYPE1_ARG_ORDER class (one instance for the
family; all four sites shared the identical zero-push shape). Latent in the
suite: the only type-1 valueOf/toString callees (gnash toString_valueOf-v5/v6)
declare 0 params.

obj1.valueOf hits objectCallValueOf (Add2), objectToPrimitive (Less2), and
convertFloat (Subtract); obj2.toString (valueOf inherited from
Object.prototype returns `this`, non-primitive) hits objectCallToString via
string-context Add2. MTASC emits DefineFunction2 for SWF6+, so this is
hand-assembled SWF6 bytecode. Expected output derived from the fixed
implementation (each path's exact re-dispatch count is pinned, e.g. Add2
calls valueOf once via oCVO and once more via convertFloat's numeric leg).
Fixed by migrating the coercion paths onto invokeFunctionValue in dispatch
Stage 4.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
NEW_OBJECT = bytes([0x40]); POP = bytes([0x17])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); LESS2 = bytes([0x48])
SUBTRACT = bytes([0x0B]); RETURN = bytes([0x3E]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def getvar(name):
    return push_string(name) + GET_VARIABLE

def concat_var(var):
    return getvar(var) + ADD2

actions = b''

# vo(a, b): trace("vo:"+a+","+b); return 5
actions += define_function('vo', ['a', 'b'],
    push_string('vo:') + concat_var('a') + push_string(',') + ADD2 + concat_var('b')
    + TRACE + push_float(5.0) + RETURN)

# ts(c, d): trace("ts:"+c+","+d); return "S"
actions += define_function('ts', ['c', 'd'],
    push_string('ts:') + concat_var('c') + push_string(',') + ADD2 + concat_var('d')
    + TRACE + push_string('S') + RETURN)

# obj1 = new Object(); obj1.valueOf = vo
actions += push_string('obj1') + push_float(0.0) + push_string('Object') + NEW_OBJECT + SET_VARIABLE
actions += getvar('obj1') + push_string('valueOf') + getvar('vo') + SET_MEMBER

# trace(obj1 + 1)   -> objectCallValueOf (Add2)
actions += getvar('obj1') + push_float(1.0) + ADD2 + TRACE
# trace(obj1 < 10)  -> objectToPrimitive (Less2)
actions += getvar('obj1') + push_float(10.0) + LESS2 + TRACE
# trace(obj1 - 1)   -> convertFloat object arm (Subtract)
actions += getvar('obj1') + push_float(1.0) + SUBTRACT + TRACE

# obj2 = new Object(); obj2.toString = ts
actions += push_string('obj2') + push_float(0.0) + push_string('Object') + NEW_OBJECT + SET_VARIABLE
actions += getvar('obj2') + push_string('toString') + getvar('ts') + SET_MEMBER

# trace("x" + obj2) -> objectCallToString (string-context Add2)
actions += push_string('x') + getvar('obj2') + ADD2 + TRACE

actions += push_string('done') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
