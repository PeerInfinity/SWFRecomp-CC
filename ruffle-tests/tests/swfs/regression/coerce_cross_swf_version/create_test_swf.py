#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for coerce_cross_swf_version.

Exercises per-function SWF-version semantics on the coercion dispatch paths
that lacked switchToFunctionVersion (dispatch plan Stage 4 normalization
pass (b)): objectToPrimitive (both legs), convertFloat (both branches), the
objectCallValueOf/objectCallToString GETTER sub-branches, and
call_function_with_this (fixed without a repro row — asfunction is
unreachable in the suite). The oCVO/oCTS MAIN branches already switched
(kept-in-arm ritual) and are unchanged. Same proven bug class as Stage 0's
timer fix; modeled on regression/mc_event_cross_swf_version, sharing its
_level0 handoff because per-version _global groups are exactly what the
switch swaps.

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    o = {};  o.valueOf = _level0.vo;      // the v6-DEFINED function
    trace("less");  (o < 1);              // Less2      -> objectToPrimitive
    trace("sub");   (o - 1);              // Subtract   -> convertFloat
    trace("done");

Child (v6):
    _level0.vo = function () {
        trace("vo:[" + u + "]");          // v6 semantics: undefined -> ""
        return 5;
    };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function at the SWF version of its DEFINING movie, so both
rows must trace "vo:[]" even though the coercions are triggered from the
host's (v7) frame script. Without version switches on these paths they trace
"vo:[undefined]". Both trigger sites fire MID-SCRIPT (this family is where
the marshalling repro coerce_type1_args lives too).
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
INIT_OBJECT   = bytes([0x43])
POP           = bytes([0x17])
TRACE         = bytes([0x26])
ADD2          = bytes([0x47])
LESS2         = bytes([0x48])
SUBTRACT      = bytes([0x0B])
RETURN        = bytes([0x3E])
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

# vo body: trace("vo:[" + u + "]"); return 5;
vo_body = trace_bracketed('vo:[') + push_float(5.0) + RETURN

child = b''
child += get_var('_level0') + push_string('vo')
child += define_function('', [], vo_body)
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
# o = {};  o.valueOf = _level0.vo;
frame4 += set_var('o', push_float(0.0) + INIT_OBJECT)
frame4 += get_var('o') + push_string('valueOf')
frame4 += get_var('_level0') + push_string('vo') + GET_MEMBER
frame4 += SET_MEMBER
# trace("less");  (o < 1);   Less2 -> objectToPrimitive
frame4 += push_string('less') + TRACE
frame4 += get_var('o') + push_float(1.0) + LESS2 + POP
# trace("sub");   (o - 1);   Subtract -> convertFloat
frame4 += push_string('sub') + TRACE
frame4 += get_var('o') + push_float(1.0) + SUBTRACT + POP
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 7, [frame1, None, None, frame4, None])
