#!/usr/bin/env python3
"""Build test.swf for convertfloat_type1_this.

NORMALIZATION (pass (b) remainder, master-list item 7 — convertFloat's missing
type-1 this push). objectToPrimitive pushes the receiver onto g_this_stack for
a type-1 valueOf/toString (the "14799 fix"), so `this` inside reads the object
being converted. convertFloat's OBJECT arm never did — it passed
INV_CAPTURED_SCOPE only — so a type-1 valueOf reached through convertFloat
(the numeric-coercion leg: Subtract, Less2's numeric path, increments,
coerceVarToNumber) saw the CALLER's `this` instead of its own receiver.

Flash/Ruffle bind `this` to the receiver for any valueOf invocation. Fix:
INV_THIS_STACK for the type-1 branch of convertFloat (per-branch gate, exactly
mirroring objectToPrimitive — a type-2 callee still sees no this-cell here).

Repro (hand-assembled SWF6; MTASC emits DefineFunction2):

    o = new Object();
    o.n = 42;
    o.valueOf = function () { return this.n; };   // type-1, reads `this`
    trace("r=" + (o - 1));   // Subtract -> convertFloat(o) -> valueOf

Fixed: this == o, this.n == 42, valueOf returns 42, 42 - 1 = 41  -> "r=41".
Broken: this is the caller's (root/undefined) this-cell, this.n == undefined,
convertFloat recurses on undefined -> NaN, NaN - 1 = NaN -> "r=NaN".

The `x=` row traces `this.n` from INSIDE valueOf too, so the fail-before
signature is visible directly (undefined -> "" under SWF6) as well as in the
subtraction result.
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
TRACE = bytes([0x26]); ADD2 = bytes([0x47])
SUBTRACT = bytes([0x0B]); RETURN = bytes([0x3E]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def getvar(name):
    return push_string(name) + GET_VARIABLE

# this.n :  push "this"; GetVariable; push "n"; GetMember
def this_n():
    return getvar('this') + push_string('n') + GET_MEMBER

actions = b''

# vo = function () { trace("x=" + this.n); return this.n; }
vo_body = (push_string('x=') + this_n() + ADD2 + TRACE +   # x=42 fixed ; x= broken
           this_n() + RETURN)
actions += define_function('vo', [], vo_body)

# o = new Object(); o.n = 42; o.valueOf = vo;
actions += push_string('o') + push_float(0.0) + push_string('Object') + NEW_OBJECT + SET_VARIABLE
actions += getvar('o') + push_string('n') + push_float(42.0) + SET_MEMBER
actions += getvar('o') + push_string('valueOf') + getvar('vo') + SET_MEMBER

# trace("r=" + (o - 1));   -> Subtract -> convertFloat object arm
actions += push_string('r=') + getvar('o') + push_float(1.0) + SUBTRACT + ADD2 + TRACE

actions += push_string('done') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
