#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for watch_cross_swf_version.

Exercises per-function SWF-version semantics on all THREE watch dispatch arms
(dispatch plan Stage 4 normalization pass (b): none of them switched to the
watcher's defining movie's SWF version — same proven bug class as Stage 0's
timer fix; modeled on regression/mc_event_cross_swf_version, sharing its
_level0 handoff because per-version _global groups are exactly what the
switch swaps):

  Site A — timeline variable watch (actionSetVariable): _root.watch("va", cb)
           then a plain `va = 1` SetVariable. Fires type-2 watchers only.
  Site B — OBJECT-receiver watch (actionSetMember): o.watch("pb", cb); o.pb = 2.
  Site C — MOVIECLIP-receiver watch (actionSetMember): m.watch("qc", cb); m.qc = 3.

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    _root.watch("va", _level0.cb);   va = 1;      // Site A
    o = {};  o.watch("pb", _level0.cb);  o.pb = 2; // Site B
    _root.createEmptyMovieClip("m", 3);
    m.watch("qc", _level0.cb);  m.qc = 3;          // Site C
    trace("done");

Child (v6):
    _level0.cb = function (prop, oldV, newV, ud) {   // DefineFunction2
        trace(prop + ":[" + u + "]");     // v6 semantics: undefined -> ""
    };
    trace("child:[" + u + "]");           // v6: undefined -> ""

The watcher is a hand-assembled DefineFunction2 (register_count=0, named
params) because Site A only fires type-2 watchers (its type-1 gate is the
preserved D2 divergence). Flash/Ruffle run a function at the SWF version of
its DEFINING movie, so each row must trace "<prop>:[]" even though every
write is triggered from the host's (v7) frame script. Without version
switches on the watch arms they trace "<prop>:[undefined]".

All three watch sites fire MID-SCRIPT (the marshalling-visible family that
watch_setmember_type1_args / watch_mc_type1_args pin).
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

def define_function2(name, params, register_count, flags, body):
    """DefineFunction2 (0x8E). params = [(register, name), ...]; register 0
    means bind by name into the local scope (no preload)."""
    p = name.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(params))
    p += struct.pack('<B', register_count)
    p += struct.pack('<H', flags)
    for reg, pname in params:
        p += struct.pack('<B', reg) + pname.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x8E, len(p)) + p + body

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

# cb body: trace(prop + ":[" + u + "]");
cb_body = (get_var('prop') + push_string(':[') + ADD2 +
           get_var('u') + ADD2 + push_string(']') + ADD2 + TRACE)

child = b''
child += get_var('_level0') + push_string('cb')
child += define_function2('', [(0, 'prop'), (0, 'oldV'), (0, 'newV'), (0, 'ud')],
                          0, 0, cb_body)
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

cb_ref = get_var('_level0') + push_string('cb') + GET_MEMBER

frame4 = b''
# Site A: _root.watch("va", cb);  va = 1;
frame4 += call_method(get_var('_root'), 'watch',
                      [cb_ref, push_string('va')], 2)  # arg2=cb deepest, arg1="va" top
frame4 += POP
frame4 += set_var('va', push_float(1.0))
# Site B: o = {};  o.watch("pb", cb);  o.pb = 2;
frame4 += set_var('o', push_float(0.0) + INIT_OBJECT)
frame4 += call_method(get_var('o'), 'watch', [cb_ref, push_string('pb')], 2)
frame4 += POP
frame4 += get_var('o') + push_string('pb') + push_float(2.0) + SET_MEMBER
# Site C: _root.createEmptyMovieClip("m", 3);  m.watch("qc", cb);  m.qc = 3;
frame4 += call_method(get_var('_root'), 'createEmptyMovieClip',
                      [push_float(3.0), push_string('m')], 2)
frame4 += POP
frame4 += call_method(get_var('m'), 'watch', [cb_ref, push_string('qc')], 2)
frame4 += POP
frame4 += get_var('m') + push_string('qc') + push_float(3.0) + SET_MEMBER
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 7, [frame1, None, None, frame4, None])
