#!/usr/bin/env python3
"""Build test.swf for onunload_type1_local_frame.

NORMALIZATION (pass (b) remainder, master-list item 5). The shared
invokeUnloadHandler adapter pushed a fresh local activation frame for a
type-2 onUnload handler (INV_LOCAL_SCOPE) but NONE for a type-1 handler — so a
type-1 handler's declared parameters, bound by its generated prologue via
setVariableByName, missed any local scope and leaked into the ambient scope
(the base clip's timeline / root var_map). A param whose name collides with a
timeline variable therefore CLOBBERED it.

Flash/Ruffle run every AS-level handler as a function call with its own
activation object; parameters are locals and never touch the enclosing
timeline. So the leak was a real, user-visible bug; INV_LOCAL_SCOPE for the
type-1 branch fixes it (matching the type-2 branch and the enterFrame
children arm, which have always had the frame).

Repro (fires the SYNCHRONOUS mid-script unloadMovie site, like
onunload_type1_args):

    x = "GLOBAL";                       // root var_map
    _root.createEmptyMovieClip("m", 1);
    function ou(x) { }                  // type-1 onUnload handler, param `x`
    m.onUnload = ou;
    m.unloadMovie();                    // fires onUnload synchronously;
                                        // prologue binds param x = undefined
    trace("x=[" + x + "]");            // leaked -> "x=[]" (SWF6 undefined->"")
                                        // local  -> "x=[GLOBAL]"
    trace("after");

Before the fix the param bind overwrites the root `x` (traces `x=[]`); after,
the fresh local frame absorbs it and the root `x` survives (`x=[GLOBAL]`).

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
SET_VARIABLE = bytes([0x1D])
SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); POP = bytes([0x17]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

actions = b''

# x = "GLOBAL";  (root var_map)
actions += push_string('x') + push_string('GLOBAL') + SET_VARIABLE

# _root.createEmptyMovieClip("m", 1);  (result discarded)
for a in reversed([push_string('m'), push_float(1.0)]):
    actions += a
actions += push_float(2.0) + gv('_root') + push_string('createEmptyMovieClip')
actions += CALL_METHOD + POP

# function ou(x) { }   — empty body; the only effect under test is the
# prologue's param bind (x = undefined).
actions += define_function('ou', ['x'], b'')

# m.onUnload = ou;
actions += gv('m') + push_string('onUnload') + gv('ou') + SET_MEMBER

# m.unloadMovie();  (statement — result popped; NOT parked in an expression,
# so this isolates the local-frame leak from the clamp/pad stack-theft class).
actions += push_float(0.0) + gv('m') + push_string('unloadMovie') + CALL_METHOD + POP

# trace("x=[" + x + "]");   — leaked -> x=[] ; local frame -> x=[GLOBAL]
actions += push_string('x=[') + gv('x') + ADD2 + push_string(']') + ADD2 + TRACE
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
