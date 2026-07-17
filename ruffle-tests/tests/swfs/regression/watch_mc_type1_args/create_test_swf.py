#!/usr/bin/env python3
"""Build test.swf for watch_mc_type1_args.

Pins actionSetMember's MOVIECLIP-receiver watch arm (dossier Site C), type-1
callee. Before the Stage-4 migration onto invokeFunctionValue the type-1
branch pushed EXACTLY 3 values (name, oldVal, newVal — userData dropped, D6)
forward with no clamp and no pad, so a 4-param watcher
`function(prop, oldV, newV, ud)` popped one value too many: ud=newVal,
newV=oldVal, oldV=name, and prop popped a stale caller eval-stack slot
(detected here with a SENTINEL pushed beneath the assignment).

Post-fix the core pushes exactly param_count values. The `ud` param now
receives the watch() userData ("UD"): normalization pass (b) remainder (D6 /
master-list item 7) makes Site C deliver 4 args for BOTH function types, so a
type-1 MC watcher declaring a 4th param gets the userData — Ruffle always
delivers 4. (Before D6 landed, Site C type-1 dropped userData, num_args=3, and
this row read `ud=` / undefined; the clamp/pad migration kept it that way and
this line explicitly flipped when D6 landed.) The `stored:` line pins
return-value-becomes-new-value on the MC arm; a 2-param watcher pins the clamp
(the surplus newVal is dropped, nothing strands on the caller's stack).

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
CALL_METHOD = bytes([0x52])
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
    out = push_string(tag)
    for i, p in enumerate(params):
        if i:
            out += push_string('|') + ADD2
        out += gv(p) + ADD2
    return out + TRACE

actions = b''

# _root.createEmptyMovieClip("m", 1);
actions += call_method(gv('_root'), 'createEmptyMovieClip',
                       [push_string('m'), push_float(1.0)])

# ---- section 1: 4-param watcher (pad; userData deliberately dropped) -------

# function w4(prop, oldV, newV, ud) { trace(...); return newV; }
actions += define_function('w4', ['prop', 'oldV', 'newV', 'ud'],
                           trace_params('w4: ', ['prop', 'oldV', 'newV', 'ud'])
                           + gv('newV') + RETURN)

# m.watch("p", w4, "UD"); m.p = "x";
actions += call_method(gv('m'), 'watch',
                       [push_string('p'), gv('w4'), push_string('UD')])
# SENTINEL beneath the assignment: pre-fix, w4's first param popped it.
actions += push_string('SENTINEL1')
actions += gv('m') + push_string('p') + push_string('x') + SET_MEMBER
actions += TRACE
actions += (push_string('stored: ') + gv('m') + push_string('p') + GET_MEMBER
            + ADD2 + TRACE)

# ---- section 2: 2-param watcher (clamp) -------------------------------------

# function w2(prop, oldV) { trace(...); return "R2"; }
actions += define_function('w2', ['prop', 'oldV'],
                           trace_params('w2: ', ['prop', 'oldV'])
                           + push_string('R2') + RETURN)

# m.watch("q", w2); m.q = "y";
actions += call_method(gv('m'), 'watch',
                       [push_string('q'), gv('w2')])
actions += push_string('SENTINEL2')
actions += gv('m') + push_string('q') + push_string('y') + SET_MEMBER
actions += TRACE
actions += (push_string('stored2: ') + gv('m') + push_string('q') + GET_MEMBER
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
