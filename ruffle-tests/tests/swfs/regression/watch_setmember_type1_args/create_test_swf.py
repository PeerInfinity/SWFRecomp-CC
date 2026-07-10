#!/usr/bin/env python3
"""Build test.swf for watch_setmember_type1_args.

Pins actionSetMember's OBJECT-receiver watch arm (dossier Site B), type-1
callee. Before the Stage-4 migration onto invokeFunctionValue the type-1
branch pushed EXACTLY 4 values (name, oldVal, newVal, userData) forward with
no clamp and no pad, so:

  * the CANONICAL 3-param watcher `function(prop, oldV, newV)` bound
    prop=oldVal, oldV=newVal, newV=userData — every arg off by one — and
    left the name string stranded on the caller's eval stack (corrupting
    the next expression that pops it);
  * a 5-param watcher's 5th param popped a stale caller slot instead of
    padding with undefined.

Post-fix the core pushes exactly param_count values: clamped for the 3-param
watcher, padded for the 5-param one. The `stored:` lines additionally pin
return-value-becomes-new-value through a DEFINED return on this arm. The
undefined-return case (D1, Ruffle stores undefined / we keep the intended
value) is deliberately NOT asserted — that is normalization-gated.

DefineFunction is emitted by hand because MTASC emits DefineFunction2 for
SWF6+ and the type-1 arm cannot be reached any other way (zero suite
coverage before this test).
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
INIT_OBJECT = bytes([0x43]); CALL_METHOD = bytes([0x52])
POP = bytes([0x17]); TRACE = bytes([0x26]); ADD2 = bytes([0x47])
RETURN = bytes([0x3E]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

def call_method(recv_bytes, method, arg_pushes):
    # Stack (bottom->top): args[N-1..0], num_args, receiver, method name.
    out = b''
    for a in reversed(arg_pushes):
        out += a
    out += push_float(float(len(arg_pushes)))
    out += recv_bytes
    out += push_string(method)
    return out + CALL_METHOD + POP

def trace_params(tag, params):
    # trace(tag + p1 + "|" + p2 + ...)
    out = push_string(tag)
    for i, p in enumerate(params):
        if i:
            out += push_string('|') + ADD2
        out += gv(p) + ADD2
    return out + TRACE

actions = b''

# ---- section 1: canonical 3-param watcher (clamp + stranded-name) ---------

# function w(prop, oldV, newV) { trace(...); return newV + "!"; }
actions += define_function('w', ['prop', 'oldV', 'newV'],
                           trace_params('w: ', ['prop', 'oldV', 'newV'])
                           + gv('newV') + push_string('!') + ADD2 + RETURN)

# o = {}; o.watch("p", w); o.p = "x";
actions += push_string('o') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += call_method(gv('o'), 'watch',
                       [push_string('p'), gv('w')])
# SENTINEL beneath the assignment expression: with the stranded-name bug the
# name string "p" is left on the eval stack and this TRACE prints it.
actions += push_string('SENTINEL1')
actions += gv('o') + push_string('p') + push_string('x') + SET_MEMBER
actions += TRACE
actions += (push_string('stored: ') + gv('o') + push_string('p') + GET_MEMBER
            + ADD2 + TRACE)

# ---- section 2: 5-param watcher (pad) --------------------------------------

# function w5(prop, oldV, newV, ud, e) { trace(...); return newV; }
actions += define_function('w5', ['prop', 'oldV', 'newV', 'ud', 'e'],
                           trace_params('w5: ', ['prop', 'oldV', 'newV', 'ud', 'e'])
                           + gv('newV') + RETURN)

# o2 = {}; o2.watch("q", w5, "UD"); o2.q = "y";
actions += push_string('o2') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += call_method(gv('o2'), 'watch',
                       [push_string('q'), gv('w5'), push_string('UD')])
actions += push_string('SENTINEL2')
actions += gv('o2') + push_string('q') + push_string('y') + SET_MEMBER
actions += TRACE
actions += (push_string('stored2: ') + gv('o2') + push_string('q') + GET_MEMBER
            + ADD2 + TRACE)

actions += push_string('end') + TRACE
actions += END

# ---- SWF wrapper ---------------------------------------------------------

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
