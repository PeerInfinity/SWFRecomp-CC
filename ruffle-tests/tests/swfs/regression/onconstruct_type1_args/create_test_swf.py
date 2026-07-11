#!/usr/bin/env python3
"""Build test.swf for onconstruct_type1_args.

BUG REPRO (fail-before verified against the pre-migration dispatcher).
actionDispatchMCOnConstruct's type-1 arm invoked the handler with NOTHING
pushed on the eval stack. Unlike its onLoad sibling (queue-drain only, empty
stack), onConstruct fires MID-SCRIPT from inside createEmptyMovieClip — so a
param'd type-1 handler's generated prologue popped the CALLER's in-progress
expression operands. Here `trace("X: " + createEmptyMovieClip(...))` has
"X: " parked on the stack when onConstruct fires: the old arm let the
handler's last-declared param swallow it (b="X: ", typeof "string") and the
outer concat then read the empty-stack boundary. The invokeFunctionValue
core pads exactly param_count undefineds instead — the 19th confirmed
in-the-wild instance of the TYPE1_ARG_ORDER clamp/pad class.

MovieClip.prototype.onConstruct = oc(a, b) is looked up through the
prototype-chain fallback (fresh createEmptyMovieClip clips may have no
dynamic_props yet). DefineFunction is emitted by hand because MTASC emits
DefineFunction2 for SWF6+ and the type-1 arm cannot be reached any other way.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); TYPE_OF = bytes([0x44]); END = bytes([0x00])

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
    # trace(prefix + typeof var) — the discriminator: a stolen caller operand
    # reads as "string", a real pad as "undefined".
    return push_string(prefix) + gv(var) + TYPE_OF + ADD2 + TRACE

actions = b''

# function oc(a, b) { trace rows for value + typeof of both params }
actions += define_function('oc', ['a', 'b'],
                           tc('c:a=', 'a') + tt('c:ta=', 'a')
                           + tc('c:b=', 'b') + tt('c:tb=', 'b'))

# MovieClip.prototype.onConstruct = oc;
actions += gv('MovieClip') + push_string('prototype') + GET_MEMBER
actions += push_string('onConstruct') + gv('oc') + SET_MEMBER

# trace("X: " + _root.createEmptyMovieClip("m", 1));
# "X: " sits on the eval stack while onConstruct fires — the repro shape.
actions += push_string('X: ')
for a in reversed([push_string('m'), push_float(1.0)]):
    actions += a
actions += push_float(2.0)                 # num_args
actions += gv('_root')                     # receiver
actions += push_string('createEmptyMovieClip')
actions += CALL_METHOD                     # leaves the new MC on the stack
actions += ADD2 + TRACE                    # trace("X: " + mc)

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
