#!/usr/bin/env python3
"""Build test.swf for broadcast_type1_args.

BUG REPRO (fail-before verified against the pre-migration dispatcher).
builtin_broadcaster_broadcastMessage's type-1 listener arm pushed the
broadcast extras in forward order and PADDED shortfalls to param_count —
but did NOT CLAMP: with more extras than params, ALL extras were pushed,
the callee's prologue popped only param_count (binding the LAST args to
the params, off by extras-params) and the surplus was stranded on the
caller's value stack. Multi-arg broadcasts are real in-tree (Selection
passes 2 extras, Stage onFullScreen 1, MCL onLoadProgress/onLoadError 2),
so this is the claimable marshalling bug of the family (dossier §5/§7).

Three broadcasts, per the dossier's design:
  bc1 ("one","two")      — order lock (passed before the fix)
  bc2 ("solo")           — pad lock (passed before the fix; typeof row)
  bc3 ("x1","x2","x3")   — the CLAMP repro: expected a=x1 b=x2; the old
    arm bound a=x2 b=x3 and stranded "x1", which the surrounding
    trace("X: " + o.broadcastMessage(...)) then surfaced as "x1true"
    (the stranded slot displaced "X: " under the return value).

The listener handler is a hand-emitted DefineFunction (MTASC emits
DefineFunction2 for SWF6+; the type-1 arm — including gnash
AsBroadcaster-v6's super shadow — cannot be reached any other way).
Invoking broadcastMessage via CallMethod from bytecode also puts the outer
invocation frame + live super context on the chain, the arm's most
demanding configuration (the super shadow itself is pinned by
from_gnash/actionscript.all/AsBroadcaster-v6).
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
INIT_OBJECT = bytes([0x43])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

def tc(prefix, var):
    return push_string(prefix) + gv(var) + ADD2 + TRACE

def tt(prefix, var):
    return push_string(prefix) + gv(var) + TYPE_OF + ADD2 + TRACE

def call_method(recv_bytes, method, arg_pushes, keep_result=False):
    out = b''
    for a in reversed(arg_pushes):
        out += a
    out += push_float(float(len(arg_pushes)))
    out += recv_bytes
    out += push_string(method)
    out += CALL_METHOD
    if not keep_result:
        out += POP
    return out

actions = b''

# function h(a, b) { trace("a="+a); trace("b="+b); trace("tb="+typeof b); }
actions += define_function('h', ['a', 'b'],
                           tc('a=', 'a') + tc('b=', 'b') + tt('tb=', 'b'))

# o = {};   (ActionSetVariable pops value then name: push name, value, 0x1D)
actions += push_string('o') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += push_string('l') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE

# AsBroadcaster.initialize(o);
actions += call_method(gv('AsBroadcaster'), 'initialize', [gv('o')])

# l.onTest = h;
actions += gv('l') + push_string('onTest') + gv('h') + SET_MEMBER

# o.addListener(l);
actions += call_method(gv('o'), 'addListener', [gv('l')])

# bc1: order lock
actions += push_string('bc1') + TRACE
actions += call_method(gv('o'), 'broadcastMessage',
                       [push_string('onTest'), push_string('one'), push_string('two')])

# bc2: pad lock
actions += push_string('bc2') + TRACE
actions += call_method(gv('o'), 'broadcastMessage',
                       [push_string('onTest'), push_string('solo')])

# bc3: clamp repro — trace("X: " + o.broadcastMessage("onTest","x1","x2","x3"))
actions += push_string('bc3') + TRACE
actions += push_string('X: ')
actions += call_method(gv('o'), 'broadcastMessage',
                       [push_string('onTest'), push_string('x1'),
                        push_string('x2'), push_string('x3')],
                       keep_result=True)
actions += ADD2 + TRACE

actions += push_string('after') + TRACE
actions += END

tags = b''
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags += struct.pack('<H', 1 << 6)      # ShowFrame
tags += bytes([0, 0])

body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags)
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
