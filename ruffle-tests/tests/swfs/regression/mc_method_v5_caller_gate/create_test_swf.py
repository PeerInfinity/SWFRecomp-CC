#!/usr/bin/env python3
"""Build test.swf (SWF5 host) + child.swf (SWF7 child) for mc_method_v5_caller_gate.

Exercises the callee-vs-caller version-gate unification (dispatch plan
Stage 4 normalization pass (b), item 3). The MOVIECLIP method arms (plus
fireTimerCallback's function form and the enterFrame children arm) gated
their base-clip/version behavior on the CALLEE's SWF version — an accident
of statement order (they read g_swf_version after their own
switchToFunctionVersion). Every other arm gates on the caller's version,
and Ruffle's model (core/src/avm1/function.rs, Avm1Function::call) is
explicit: `is_closure = activation.swf_version() >= 6` — the CALLER decides.
A v5 caller is pre-closure: the callee runs in its RECEIVER's timeline at
the receiver's CURRENT version, regardless of where it was defined.

Host (v5):
    trace("host:[" + u + "]");            // v5: undefined -> ""
    loadMovieNum("child.swf", 1);        // v5 host: no createEmptyMovieClip;
                                          // a dot-path target root-replaces
    // frame 4 (child has initialized by then):
    _root.f = _level0.cb;                 // the v7-DEFINED function
    _root.f();                            // MC-method arm, receiver = root (v5)
    trace("done");

Child (v7):
    _level0.cb = function () { trace("cb:[" + u + "]"); };
    trace("child:[" + u + "]");           // v7: undefined -> "undefined"

Ruffle/Flash: the v5 caller is pre-closure, so cb runs at the RECEIVER's
(root, v5) version — "cb:[]" — in the receiver's timeline. Under the old
callee gate the arm installed cb's defining version (7) and entered its
base clip, tracing "cb:[undefined]".

(The mirror direction — v6+ caller, v5 callee — is not separately testable:
a v5-defined function still carries a base_clip, but the unified caller
gate and the old callee gate agree there for the version switch, since
switchToFunctionVersion no-ops only on swf_version==0, not <6.)
"""
import struct

# ---- action helpers ----------------------------------------------------

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE  = bytes([0x1C])
GET_MEMBER    = bytes([0x4E])
SET_MEMBER    = bytes([0x4F])
CALL_METHOD   = bytes([0x52])
POP           = bytes([0x17])
TRACE         = bytes([0x26])
ADD2          = bytes([0x47])
END           = bytes([0x00])

def get_url2(flags):
    return struct.pack('<BHB', 0x9A, 1, flags)

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

def get_var(name):
    return push_string(name) + GET_VARIABLE

def call_method(obj_actions, method, args_actions_reversed, num_args):
    out = b''
    for a in args_actions_reversed:
        out += a
    out += push_float(float(num_args))
    out += obj_actions
    out += push_string(method)
    out += CALL_METHOD
    return out

def trace_bracketed(prefix):
    return (push_string(prefix) + get_var('u') + ADD2 +
            push_string(']') + ADD2 + TRACE)

def build_swf(path, version, actions_per_frame):
    tags = b''
    for actions in actions_per_frame:
        if actions:
            tags += struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
        tags += struct.pack('<H', 1 << 6)  # ShowFrame
    tags += bytes([0x00, 0x00])            # End
    rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    frame_rate = struct.pack('<H', 24 << 8)
    frame_count = struct.pack('<H', len(actions_per_frame))
    body = rect_data + frame_rate + frame_count + tags
    file_length = 8 + len(body)
    with open(path, 'wb') as fh:
        fh.write(b'FWS' + struct.pack('<BI', version, file_length) + body)
    print(f'Created {path} (v{version}, {file_length} bytes)')

# ---- child.swf (SWF7) ----------------------------------------------------

child = b''
child += get_var('_level0') + push_string('cb')
child += define_function('', [], trace_bracketed('cb:['))
child += SET_MEMBER
child += trace_bracketed('child:[')
child += END

build_swf('child.swf', 7, [child])

# ---- test.swf (SWF5 host) -------------------------------------------------

frame1 = b''
frame1 += trace_bracketed('host:[')
# loadMovieNum("child.swf", 1): a v5 host has no createEmptyMovieClip, and a
# dot-path target falls back to a root replacement — load into _level1 instead.
frame1 += push_string('child.swf')
frame1 += push_string('_level1')
frame1 += get_url2(0x40)
frame1 += END

frame4 = b''
# _root.f = _level0.cb;
frame4 += get_var('_root') + push_string('f')
frame4 += get_var('_level0') + push_string('cb') + GET_MEMBER
frame4 += SET_MEMBER
# _root.f();  -> MOVIECLIP method arm, receiver = root (v5)
frame4 += call_method(get_var('_root'), 'f', [], 0)
frame4 += POP
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 5, [frame1, None, None, frame4, None])
