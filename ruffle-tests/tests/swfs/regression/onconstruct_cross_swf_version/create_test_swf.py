#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for onconstruct_cross_swf_version.

Exercises per-function SWF-version semantics on the onConstruct/onLoad MC
lifecycle dispatcher family (dispatch plan Stage 4 normalization pass (b):
actionDispatchMCOnConstruct and actionDispatchMCOnLoad — explicit ritual
clones, migrated together as instance nineteen — lacked
switchToFunctionVersion; same proven bug class as Stage 0's timer fix;
modeled on regression/mc_event_cross_swf_version, sharing its _level0
handoff because per-version _global groups are exactly what the switch swaps).

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    _root.createEmptyMovieClip("m0", 3);
    p = m0.__proto__;                     // the REAL MovieClip prototype
    p.onConstruct = _level0.cbc;          // v6-DEFINED handler
    _root.createEmptyMovieClip("m2", 4);  // onConstruct fires MID-SCRIPT here
    trace("done");

Child (v6):
    _level0.cbc = function () { trace("oc:[" + u + "]"); };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function at the SWF version of its DEFINING movie, so the
handler must trace "oc:[]" (v6 undefined-coercion) even though the clip
creation that triggers it runs in the host's (v7) frame script. Without a
version switch in the dispatcher it traces "oc:[undefined]".

The repro row covers the FAMILY: actionDispatchMCOnLoad receives the
identical change (base-clip switch moved into the arm, caller-version gated,
+ INV_VERSION_SWITCH), but a cross-version onLoad trigger is not buildable
today — onLoad only queues from attachMovie, and a hand-assembled
DefineSprite/ExportAssets attachMovie does not instantiate in the
child-movie environment (pre-existing gap, like the two identity bugs
below). onLoad's unchanged same-version behavior stays locked by
regression/onload_type1_args.

Design notes (workarounds for pre-existing bugs, both also hit by
mc_event_cross_swf_version's probing, documented there):
  * The handler must be assigned on `m0.__proto__` (a throwaway clip's real
    prototype), NOT on `MovieClip.prototype`: in the loaded-child
    environment the host's `MovieClip` global names a DIFFERENT prototype
    object than the one createEmptyMovieClip wires into new clips
    (probe: m2.__proto__ == MovieClip.prototype -> false). Pre-existing
    loaded-movie identity bug, tracked separately.
  * The handoff uses `_level0.cbc`, not `_global`: per-version _global
    groups are exactly what switchToFunctionVersion swaps.
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

def set_var(name, value_actions):
    return push_string(name) + value_actions + SET_VARIABLE

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

# ---- child.swf (SWF6) ----------------------------------------------------

child = b''
child += get_var('_level0') + push_string('cbc')
child += define_function('', [], trace_bracketed('oc:['))
child += SET_MEMBER
child += trace_bracketed('child:[')
child += END

build_swf('child.swf', 6, [child])

# ---- test.swf (SWF7 host) -------------------------------------------------

frame1 = b''
frame1 += trace_bracketed('host:[')
frame1 += call_method(
    get_var('_root'), 'createEmptyMovieClip',
    [push_float(1.0), push_string('holder')], 2)
frame1 += POP
frame1 += push_string('child.swf')
frame1 += push_string('_level0.holder')
frame1 += get_url2(0x40)
frame1 += END

frame4 = b''
# m0 = throwaway clip; p = m0.__proto__ (the real MovieClip prototype)
frame4 += call_method(
    get_var('_root'), 'createEmptyMovieClip',
    [push_float(3.0), push_string('m0')], 2)
frame4 += POP
frame4 += set_var('p', get_var('m0') + push_string('__proto__') + GET_MEMBER)
# p.onConstruct = _level0.cbc;
frame4 += get_var('p') + push_string('onConstruct')
frame4 += get_var('_level0') + push_string('cbc') + GET_MEMBER
frame4 += SET_MEMBER
# _root.createEmptyMovieClip("m2", 4);  -> onConstruct fires MID-SCRIPT
frame4 += call_method(
    get_var('_root'), 'createEmptyMovieClip',
    [push_float(4.0), push_string('m2')], 2)
frame4 += POP
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 7, [frame1, None, None, frame4, None])
