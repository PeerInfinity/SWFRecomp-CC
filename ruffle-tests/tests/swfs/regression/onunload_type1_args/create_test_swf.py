#!/usr/bin/env python3
"""Build test.swf for onunload_type1_args.

BUG REPRO (fail-before verified against the pre-migration dispatch sites).
The eight inline onUnload firing sites all delegated to
invokeSpecialFunction, whose type-1 arm invokes the handler with NOTHING
pushed on the eval stack. Six of those sites fire MID-SCRIPT
(mc.unloadMovie(), mc.loadMovie(""), GetURL2 empty-URL, actionGetURL's
_level and named-clip branches, MCL.unloadClip) — so a param'd
type-1 onUnload handler's generated prologue popped the CALLER's
in-progress expression operands, the same class as onConstruct (instance
19, regression/onconstruct_type1_args). Here `trace("X: " +
m.unloadMovie())` has "X: " parked on the stack when onUnload fires.

The observed fail-before signature differs from onConstruct's, because
invokeSpecialFunction's type-1 path pushes NO local frame: the prologue's
popVar+setVariableByName binds miss any local scope and land ambiently, so
the param VALUE rows read undefined under both the old and new code — the
theft is invisible in the params. What discriminates is the OUTER
expression: the old path consumed "X: " (both prologue pops ate live
caller slots), so the trailing trace collapsed to `0` (ADD2 of two
synthesized undefineds); the invokeFunctionValue core pads exactly
param_count undefineds and "X: " survives (`X: ` — SWF6 coerces the
undefined return to ""). The 20th confirmed in-the-wild instance of the
TYPE1_ARG_ORDER clamp/pad class. The no-local-frame bind leak itself is
preserved-by-omission (normalization candidate, documented at
invokeUnloadHandler).

The queue-drained unload sites (removeMovieClip / timeline removal) drain
at ShowFrame on an empty stack, where the pad is inert — this test pins the
synchronous unloadMovie site, the richest shape.

DefineFunction is emitted by hand because MTASC emits DefineFunction2 for
SWF6+ and the type-1 arm cannot be reached any other way.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C])
SET_MEMBER = bytes([0x4F])
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

def tc(prefix, var):
    return push_string(prefix) + gv(var) + ADD2 + TRACE

def tt(prefix, var):
    # typeof discriminates a stolen caller operand ("string") from a padded
    # undefined ("undefined").
    return push_string(prefix) + gv(var) + TYPE_OF + ADD2 + TRACE

actions = b''

# _root.createEmptyMovieClip("m", 1);  (result discarded)
for a in reversed([push_string('m'), push_float(1.0)]):
    actions += a
actions += push_float(2.0) + gv('_root') + push_string('createEmptyMovieClip')
actions += CALL_METHOD + POP

# function ou(a, b) { value+typeof rows for both params }
actions += define_function('ou', ['a', 'b'],
                           tc('u:a=', 'a') + tt('u:ta=', 'a')
                           + tc('u:b=', 'b') + tt('u:tb=', 'b'))

# m.onUnload = ou;
actions += gv('m') + push_string('onUnload') + gv('ou') + SET_MEMBER

# trace("X: " + m.unloadMovie());
# "X: " sits on the eval stack while onUnload fires synchronously — the
# repro shape (mid-script site, unlike the queue-drained removal paths).
actions += push_string('X: ')
actions += push_float(0.0)                 # num_args
actions += gv('m')                         # receiver
actions += push_string('unloadMovie')
actions += CALL_METHOD
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
