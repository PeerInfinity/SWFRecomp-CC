#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for
root_enterframe_cross_swf_version.

Exercises per-function SWF-version semantics on the ROOT onEnterFrame dispatch
path (dispatch plan Stage 4 normalization pass (b), item 1: the root arm of
actionDispatchEnterFrameHandlers lacked switchToFunctionVersion — the CHILDREN
arm has always had it, so the runtime ran a child MC's onEnterFrame at its
defining version but the ROOT's at the ambient host version. Same proven bug
class as Stage 0's timer fix and pass-(b) item 1's seven event families;
modeled on regression/mc_event_cross_swf_version).

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    _root.onEnterFrame = _level0.cb;      // the v6-DEFINED function

Child (v6):
    _level0.cb = function () {
        trace("cb:[" + u + "]");          // v6 semantics: undefined -> ""
        _level0.onEnterFrame = u;         // self-remove (fire exactly once)
    };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function with the SWF version of its DEFINING movie. The
root onEnterFrame dispatcher runs from the host's frame loop, so g_swf_version
is 7 when the v6-defined handler fires. With the version switch it traces
"cb:[]"; without it, "cb:[undefined]".

The handler is assigned via `_root.onEnterFrame = f` — a SetMember on the root
MC, so it lands in root_movieclip.dynamic_props and is dispatched by the
`if (g_root_enterframe_eligible)` root arm of actionDispatchEnterFrameHandlers.
(The sibling bare-`onEnterFrame =` var-map arm is covered by
root_varmap_enterframe_cross_swf_version.)

Design notes (identical loaded-movie constraints as mc_event_cross_swf_version):
  * handoff via `_level0.cb`, NOT `_global.cb` (per-version _global groups are
    exactly what the switch swaps);
  * the handler self-removes (`this.onEnterFrame = undefined`) so it fires
    exactly once regardless of how many idle ticks follow — deterministic
    output. Self-removal uses explicit `_root.onEnterFrame = u` (NOT
    `this.onEnterFrame`): a type-1 handler's `this` falls back through its
    base_clip — which is the CHILD holder here, not the host root — so `this`
    would clear the wrong clip. `_root` resolves to _level0 (the host root)
    regardless of base_clip, matching where the host assigned the handler.
The function is DEFINED by v6 bytecode (func->swf_version = 6) and dispatched
from the v7 host frame loop, so the cross-version observable holds.
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
SET_VARIABLE  = bytes([0x1D])
GET_MEMBER    = bytes([0x4E])
SET_MEMBER    = bytes([0x4F])
CALL_METHOD   = bytes([0x52])
POP           = bytes([0x17])
TRACE         = bytes([0x26])
ADD2          = bytes([0x47])
END           = bytes([0x00])

def action_if(skip_len):
    # ActionIf (0x9D): pop value; if truthy, jump forward by `skip_len` bytes
    # (offset is relative to the instruction following this 5-byte ActionIf).
    return struct.pack('<BHh', 0x9D, 2, skip_len)

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
    # trace(prefix + u + "]") where u is undefined
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

# ---- child.swf (SWF6) ----------------------------------------------------

# fired = 0;   // child-timeline var, captured by the closure below
# _level0.cb = function () {
#     if (fired) return;   // one-shot guard via a CAPTURED var (see below)
#     fired = 1;
#     trace("cb:[" + u + "]");
# };
#
# Self-termination uses a closure-captured child-timeline variable, NOT a
# write to _level0/_root: the loaded child's view of the host root is a
# separate identity (dynamic_props written from the child are invisible to the
# host's dispatcher — a pre-existing loaded-movie identity split, confirmed by
# probing: setting/deleting _level0.onEnterFrame from the child did NOT stop
# the root dispatcher re-firing every tick). `fired` lives in the child's own
# captured scope, so the guard is entirely child-side and deterministic.
skip_body = (push_string('fired') + push_float(1.0) + SET_VARIABLE +  # fired = 1
             trace_bracketed('cb:['))
cb_body = (get_var('fired') +          # push fired (captured; initially 0)
           action_if(len(skip_body)) + # if truthy, jump past the body (return)
           skip_body)

child = b''
child += push_string('fired') + push_float(0.0) + SET_VARIABLE  # fired = 0
child += get_var('_level0') + push_string('cb')
child += define_function('', [], cb_body)
child += SET_MEMBER
child += trace_bracketed('child:[')
child += END

build_swf('child.swf', 6, [child])

# ---- test.swf (SWF7 host) -------------------------------------------------

frame1 = b''
frame1 += trace_bracketed('host:[')
frame1 += call_method(
    get_var('_root'), 'createEmptyMovieClip',
    [push_float(1.0),          # arg2 depth
     push_string('holder')],   # arg1 name (top)
    2)
frame1 += POP
frame1 += push_string('child.swf')       # URL
frame1 += push_string('_level0.holder')  # target
frame1 += get_url2(0x40)
frame1 += END

# frame 4: child has initialized; wire the v6 handler to _root.onEnterFrame
frame4 = b''
frame4 += get_var('_root') + push_string('onEnterFrame')
frame4 += get_var('_level0') + push_string('cb') + GET_MEMBER
frame4 += SET_MEMBER
frame4 += END

# frames: 1 loads; 2-3 idle so child inits; 4 wires the handler;
# 5-6 idle — the root onEnterFrame fires once (then self-removes).
build_swf('test.swf', 7, [frame1, None, None, frame4, None, None])
