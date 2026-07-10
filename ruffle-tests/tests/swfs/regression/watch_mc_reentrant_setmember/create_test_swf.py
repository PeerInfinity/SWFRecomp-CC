#!/usr/bin/env python3
"""Build test.swf for watch_mc_reentrant_setmember.

Real-bug repro for the MOVIECLIP-receiver watch arm (dossier Site C, risk
§8.1): `prop_name` at that site points at actionSetMember's STATIC `_sm_buf`
and — unlike the OBJECT arm, which copies it to a stack-local before firing
(action.c "IMPORTANT: prop_name points to a static buffer") — the MC arm
used it ACROSS the watcher call and read it again AFTER (the tabIndex check,
the dynamic_props setProperty that stores the assignment, the autoSize and
TF-binding notifications). Any SetMember performed inside the watcher
clobbers the buffer, so the original assignment is stored under the WRONG
name: with a watcher that does `this.side = "S"`, `m.p = "x"` ended up
storing the watcher's return value under `side` (clobbering it) and leaving
`m.p` undefined.

The watcher is a plain DefineFunction (type-1) purely because it is the
simplest to hand-assemble — the bug is in the SITE's post-call reads, not in
the callee dispatch, so the callee type is irrelevant.

Expected (fixed): p stored under p → "stored p=RET", side keeps the
watcher's write → "side=S". Pre-fix: "stored p=" (undefined) and side
clobbered to RET.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); POP = bytes([0x17]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); RETURN = bytes([0x3E]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

def call_method(recv_bytes, method, arg_pushes):
    out = b''
    for a in reversed(arg_pushes):
        out += a
    out += push_float(float(len(arg_pushes)))
    out += recv_bytes
    out += push_string(method)
    return out + CALL_METHOD + POP

actions = b''

# _root.createEmptyMovieClip("m", 1);
actions += call_method(gv('_root'), 'createEmptyMovieClip',
                       [push_string('m'), push_float(1.0)])

# function w() { this.side = "S"; return "RET"; }
# The this.side SetMember re-enters actionSetMember and rewrites _sm_buf.
w_body = (gv('this') + push_string('side') + push_string('S') + SET_MEMBER
          + push_string('RET') + RETURN)
actions += define_function('w', [], w_body)

# m.watch("p", w); m.p = "x";
actions += call_method(gv('m'), 'watch', [push_string('p'), gv('w')])
actions += gv('m') + push_string('p') + push_string('x') + SET_MEMBER

# trace what landed where
actions += (push_string('stored p=') + gv('m') + push_string('p') + GET_MEMBER
            + ADD2 + TRACE)
actions += (push_string('side=') + gv('m') + push_string('side') + GET_MEMBER
            + ADD2 + TRACE)
actions += push_string('end') + TRACE
actions += END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
