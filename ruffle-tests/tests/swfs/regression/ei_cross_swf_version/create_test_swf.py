#!/usr/bin/env python3
"""Build test.swf (SWF8) for ei_cross_swf_version.

Exercises per-function SWF-version semantics on the ExternalInterface
internal-call dispatch path (dispatch plan Stage 4 normalization pass (b):
actionEI_callInternalInterface lacked switchToFunctionVersion — same proven
bug class as Stage 0's timer fix).

The movie is SWF8 and registers a v8-DEFINED callback:

    function f() { trace("cb:[" + u + "]"); }   // v8: undefined -> "undefined"
    flash.external.ExternalInterface.addCallback("extfunc", null, f);
    trace("registered");

The per-test test_harness.c then simulates a host-driven call arriving while
a DIFFERENT (older) movie's version is ambient: it sets g_swf_version = 6
(what a v6 sibling movie's bytecode would have installed), invokes
actionEI_callInternalInterface("extfunc"), and restores. Flash/Ruffle run a
function at the SWF version of its DEFINING movie, so the callback must
trace "cb:[undefined]" (v8 coercion); without a version switch on the EI
path it runs at the injected ambient v6 and traces "cb:[]".

Direction note: the other *_cross_swf_version repros use a v6 callee under a
v7 ambient. Here the polarity is INVERTED (v8 callee under a v6 ambient)
because ExternalInterface itself is version-hidden below SWF8 — a v6 movie
cannot call addCallback (probed: flash unhides via ASSetPropFlags, but
EI.addCallback/available stay version-gated undefined at v6). The observable
is the same property: the function runs at its DEFINING version, not the
ambient one.

Single-SWF (unlike the other *_cross_swf_version tests): the EI dispatcher
is harness-driven, so the ambient-version mismatch is injected in C rather
than via a loaded sibling movie.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

def push_null():
    item = b'\x02'
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
GET_MEMBER   = bytes([0x4E])
CALL_METHOD  = bytes([0x52])
POP          = bytes([0x17])
TRACE        = bytes([0x26])
ADD2         = bytes([0x47])
END          = bytes([0x00])

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

# ---- callback body: trace("cb:[" + u + "]"); ----------------------------

body = b''
body += push_string('cb:[')
body += push_string('u') + GET_VARIABLE
body += ADD2
body += push_string(']')
body += ADD2
body += TRACE

# ---- main actions -------------------------------------------------------

actions = b''
actions += define_function('f', [], body)

# flash.external.ExternalInterface.addCallback("extfunc", null, f);
actions += push_string('f')
actions += GET_VARIABLE            # arg3 = f (deepest)
actions += push_null()             # arg2 = null
actions += push_string('extfunc')  # arg1 = "extfunc" (top of args)
actions += push_float(3.0)         # num_args
actions += push_string('flash')
actions += GET_VARIABLE
actions += push_string('external')
actions += GET_MEMBER
actions += push_string('ExternalInterface')
actions += GET_MEMBER
actions += push_string('addCallback')
actions += CALL_METHOD
actions += POP

actions += push_string('registered')
actions += TRACE
actions += END

# ---- SWF wrapper ---------------------------------------------------------

do_action_tag = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

tags = do_action_tag + show_frame_tag + end_tag
tag_body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(tag_body)

with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, file_length) + tag_body)

print(f'Created test.swf (v8, {file_length} bytes)')
