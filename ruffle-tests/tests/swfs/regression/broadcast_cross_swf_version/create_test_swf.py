#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for broadcast_cross_swf_version.

Exercises per-function SWF-version semantics on the AsBroadcaster dispatch
path (dispatch plan Stage 4 normalization pass (b):
builtin_broadcaster_broadcastMessage lacked switchToFunctionVersion — same
proven bug class as Stage 0's timer fix; modeled on
regression/mc_event_cross_swf_version, sharing its _level0 handoff, because
per-version _global groups are exactly what the switch swaps).

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    o = {};  AsBroadcaster.initialize(o);
    l = {};  l.onX = _level0.cb;          // the v6-DEFINED function
    o.addListener(l);
    o.broadcastMessage("onX");            // fires the listener FROM v7 bytecode
    trace("done");

Child (v6):
    _level0.cb = function () {
        trace("cb:[" + u + "]");          // v6 semantics: undefined -> ""
    };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function with the SWF version of its DEFINING movie, so
the listener must trace "cb:[]" even though the broadcast is triggered from
the host's (v7) frame script. Without a version switch in
builtin_broadcaster_broadcastMessage it traces "cb:[undefined]".

broadcastMessage fires MID-SCRIPT (a real marshalling-visible dispatcher, the
same one instance twenty-one's broadcast_type1_args pins).
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
    """args_actions_reversed: actions pushing args argN..arg1 (arg1 last/top)."""
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

child = b''
child += get_var('_level0') + push_string('cb')
child += define_function('', [], trace_bracketed('cb:['))
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
# o = {};
frame4 += set_var('o', push_float(0.0) + INIT_OBJECT)
# AsBroadcaster.initialize(o);
frame4 += call_method(get_var('AsBroadcaster'), 'initialize', [get_var('o')], 1)
frame4 += POP
# l = {};  l.onX = _level0.cb;
frame4 += set_var('l', push_float(0.0) + INIT_OBJECT)
frame4 += get_var('l') + push_string('onX')
frame4 += get_var('_level0') + push_string('cb') + GET_MEMBER
frame4 += SET_MEMBER
# o.addListener(l);
frame4 += call_method(get_var('o'), 'addListener', [get_var('l')], 1)
frame4 += POP
# o.broadcastMessage("onX");
frame4 += call_method(get_var('o'), 'broadcastMessage', [push_string('onX')], 1)
frame4 += POP
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 7, [frame1, None, None, frame4, None])
