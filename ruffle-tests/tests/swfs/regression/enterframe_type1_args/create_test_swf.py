#!/usr/bin/env python3
"""Build test.swf for enterframe_type1_args.

BEHAVIOR LOCK, not a bug repro (verified to pass both before and after the
Stage-4 migration — say so honestly, per the worthless-as-repro guardrail).
Pins the enterFrame dispatch family's type-1 arms
(actionDispatchEnterFrameHandlers' children arm + root arm). onEnterFrame
handlers are invoked with ZERO args and the old type-1 arms pushed nothing;
the core now pads a param'd handler's params with undefined. That is NOT
observable at frame-loop level, where this family exclusively runs: the
between-frames eval stack is empty and the guarded empty-stack pop already
synthesized undefined (typeof included — A/B verified identical), so unlike
the timer/watch instances there is no popped-operand or stranded-slot signature
to repro. What this test locks instead: a param'd type-1 handler sees
undefined params (value AND typeof), one deterministic fire per handler,
children-before-root dispatch order, and that both handlers can disable
themselves via explicit paths.

Three handlers, one per arm:
  - children arm:  m.onEnterFrame = f2(a, b)     (SetMember on a dynamic MC)
  - root arm:      _root.onEnterFrame = fr(a)    (SetMember on _root's dynamic_props)
  - var-map arm:   covered separately — a timeline `onEnterFrame = fv(a)`
    SetVariable registration only fires when _root.dynamic_props has NO
    onEnterFrame, so it cannot coexist with the root arm in one movie; the
    root arm is the richer ritual and is the one pinned here.

Each handler disables itself on first fire via an EXPLICIT path
(_root.m.onEnterFrame = 0 / _root.onEnterFrame = 0) so the output is one
deterministic group per handler regardless of frame count. NOT via
`this.onEnterFrame = 0`: the type-1 children arm gives the handler no `this`
channel (no this-stack, no bind — preserved), so GetVariable("this") falls
back through the base-clip context to _root and the write would kill the
ROOT handler's registration instead (found the hard way — the first draft of
this test did exactly that).
DefineFunction is emitted by hand because MTASC emits DefineFunction2 for
SWF6+ and the type-1 arms cannot be reached any other way.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); POP = bytes([0x17]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); TYPE_OF = bytes([0x44]); END = bytes([0x00])

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

def tc(prefix, var):
    return push_string(prefix) + gv(var) + ADD2 + TRACE

def tt(prefix, var):
    # trace(prefix + typeof var) — the discriminating rows: at frame-loop
    # level the eval stack is empty and the old under-pop read the clamped
    # stack boundary, which traces as "" just like a padded undefined under
    # SWF6 concat. typeof tells them apart: boundary garbage reads as
    # "string" (zeroed type tag = STRING), a real pad as "undefined".
    return push_string(prefix) + gv(var) + TYPE_OF + ADD2 + TRACE

def disable_path(*members):
    # _root.<members...>.onEnterFrame = 0;  (explicit path — see docstring)
    out = gv('_root')
    for m in members:
        out += push_string(m) + GET_MEMBER
    return out + push_string('onEnterFrame') + push_float(0.0) + SET_MEMBER

actions = b''

# _root.createEmptyMovieClip("m", 1);
actions += call_method(gv('_root'), 'createEmptyMovieClip',
                       [push_string('m'), push_float(1.0)])

# function f2(a, b) { trace("m:a="+a); trace("m:b="+b); _root.m.onEnterFrame = 0; }
actions += define_function('f2', ['a', 'b'],
                           tc('m:a=', 'a') + tc('m:b=', 'b')
                           + tt('m:ta=', 'a') + tt('m:tb=', 'b') + disable_path('m'))
# m.onEnterFrame = f2;
actions += gv('m') + push_string('onEnterFrame') + gv('f2') + SET_MEMBER

# function fr(a) { trace("r:a=" + a); _root.onEnterFrame = 0; }
actions += define_function('fr', ['a'],
                           tc('r:a=', 'a') + tt('r:ta=', 'a') + disable_path())
# _root.onEnterFrame = fr;
actions += gv('_root') + push_string('onEnterFrame') + gv('fr') + SET_MEMBER

actions += push_string('setup') + TRACE
actions += END

# last frame marker
last = push_string('done') + TRACE + END

tags = b''
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags += struct.pack('<H', 1 << 6)      # ShowFrame 1
tags += struct.pack('<H', 1 << 6)      # ShowFrame 2
tags += struct.pack('<H', 1 << 6)      # ShowFrame 3
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(last)) + last
tags += struct.pack('<H', 1 << 6)      # ShowFrame 4
tags += bytes([0, 0])

body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 4) + tags)
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
