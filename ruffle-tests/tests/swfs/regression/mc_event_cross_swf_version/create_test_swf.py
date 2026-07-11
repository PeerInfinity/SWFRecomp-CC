#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for mc_event_cross_swf_version.

Exercises per-function SWF-version semantics on the AS2 MC event dispatch path
(dispatch plan Stage 4 normalization pass (b): mc_call_as2_handler_ng lacked
switchToFunctionVersion — same proven bug class as Stage 0's timer fix,
regression/timer_cross_swf_version, which this test is modeled on).

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    _root.createTextField("t1", 2, 0, 0, 100, 20);
    t1.onSetFocus = _level0.cb;           // the v6-DEFINED function
    Selection.setFocus(t1);               // fires onSetFocus FROM v7 bytecode
    trace("done");

Child (v6):
    _level0.cb = function (old) {
        trace("cb:[" + u + "]");          // v6 semantics: undefined -> ""
    };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function with the SWF version of its DEFINING movie, so the
handler must trace "cb:[]" even though the focus change is triggered from the
host's (v7) frame script — g_swf_version is 7 at dispatch time. Firing from
the HOST is essential: setFocus from child bytecode would already have v6
installed and mask the bug. Without a version switch in
mc_call_as2_handler_ng it traces "cb:[undefined]".

onSetFocus is the right event: synchronous, dispatched via
mc_call_as2_handler_ng (selection_do_focus_change), no input.json needed.

Design notes (deviations from the dossier's sketch, both forced by probing):
  * The dossier had the CHILD create the TextField inside itself and the host
    focus "_level0.holder.t1". That fails today for unrelated reasons: the
    child's `this` MC and the host's `_level0.holder` wrapper are DIFFERENT
    MovieClip instances (dynamic_props set by the child are invisible via the
    host's GetMember path), so the handler/`focusEnabled` can't be seen from
    the host. Pre-existing loaded-movie identity bug, tracked separately.
  * The handoff uses `_level0.cb`, NOT `_global.cb`: _global is per-version
    grouped (exactly what switchToFunctionVersion swaps), so a v6 child's
    _global.cb is invisible to the v7 host.
  * The host creates its TextField on frame 4 (after the load), not frame 1:
    a root-level TF created BEFORE loadMovie becomes unresolvable by name
    afterwards — another pre-existing bug, also tracked separately.
The function is still DEFINED by v6 bytecode (func->swf_version = 6), and the
dispatch still runs from v7 bytecode, so the cross-version observable is
identical to the dossier's design.
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

# _level0.cb = function (old) { trace("cb:[" + u + "]"); };
child = b''
child += get_var('_level0') + push_string('cb')
child += define_function('', ['old'], trace_bracketed('cb:['))
child += SET_MEMBER
child += trace_bracketed('child:[')
child += END

build_swf('child.swf', 6, [child])

# ---- test.swf (SWF7 host) -------------------------------------------------

frame1 = b''
frame1 += trace_bracketed('host:[')
# _root.createEmptyMovieClip("holder", 1);
frame1 += call_method(
    get_var('_root'), 'createEmptyMovieClip',
    [push_float(1.0),          # arg2 depth (deepest)
     push_string('holder')],   # arg1 name (top)
    2)
frame1 += POP
# loadMovie("child.swf", "_level0.holder");  (GetURL2, LoadTargetFlag)
frame1 += push_string('child.swf')       # URL
frame1 += push_string('_level0.holder')  # target
frame1 += get_url2(0x40)
frame1 += END

# frame 4: child has initialized; wire the v6 handler and fire it FROM v7 bytecode
frame4 = b''
frame4 += call_method(
    get_var('_root'), 'createTextField',
    [push_float(20.0),    # arg6 height (deepest)
     push_float(100.0),   # arg5 width
     push_float(0.0),     # arg4 y
     push_float(0.0),     # arg3 x
     push_float(2.0),     # arg2 depth
     push_string('t1')],  # arg1 name (top)
    6)
frame4 += POP
# t1.onSetFocus = _level0.cb;
frame4 += get_var('t1') + push_string('onSetFocus')
frame4 += get_var('_level0') + push_string('cb') + GET_MEMBER
frame4 += SET_MEMBER
# Selection.setFocus(t1);
frame4 += call_method(get_var('Selection'), 'setFocus', [get_var('t1')], 1)
frame4 += POP
frame4 += push_string('done')
frame4 += TRACE
frame4 += END

# 5 frames: frame 1 runs the loader; frames 2-3 idle so the child inits;
# frame 4 wires + fires the handler; frame 5 idle.
build_swf('test.swf', 7, [frame1, None, None, frame4, None])
