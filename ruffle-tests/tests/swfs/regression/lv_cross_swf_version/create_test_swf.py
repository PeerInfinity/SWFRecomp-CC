#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for lv_cross_swf_version.

Exercises per-function SWF-version semantics on the async-load dispatch
family (dispatch plan Stage 4 normalization pass (b)): fireLoadVarsCallback
(LoadVars.onData row) and soundFireCallback (the shared Sound/XML event
dispatcher — XML.onLoad row) lacked switchToFunctionVersion. Same proven bug
class as Stage 0's timer fix; modeled on regression/mc_event_cross_swf_version,
sharing its _level0 handoff because per-version _global groups are exactly
what the switch swaps.

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");
    // frame 4 (child has initialized by then):
    _root.lv = new LoadVars();
    _root.lv.onData = _level0.cbl;        // v6-DEFINED
    _root.lv.load("vars.txt");
    _root.doc = new XML();
    _root.doc.onLoad = _level0.cbx;       // v6-DEFINED
    _root.doc.load("doc.xml");
    trace("loading");                     // both drains fire AFTER this

Child (v6):
    _level0.cbl = function (src) { trace("lv:[" + u + "]"); };
    _level0.cbx = function (ok)  { trace("xml:[" + u + "]"); };
    trace("child:[" + u + "]");           // v6: undefined -> ""

Both drains run from the frame loop with the ROOT movie's (v7) ambient
version. Flash/Ruffle run a function at the SWF version of its DEFINING
movie, so both rows must trace "[]"; without version switches they trace
"[undefined]". The data files vars.txt/doc.xml are auto-embedded by
verify_output.py (HAS_DATA_FILES), so the loads succeed offline.
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
NEW_OBJECT    = bytes([0x40])
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

def new_obj(class_name):
    return push_float(0.0) + push_string(class_name) + NEW_OBJECT

def get_root_member(name):
    return get_var('_root') + push_string(name) + GET_MEMBER

def set_root_member(name, value_bytes):
    return get_var('_root') + push_string(name) + value_bytes + SET_MEMBER

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
child += get_var('_level0') + push_string('cbl')
child += define_function('', ['src'], trace_bracketed('lv:['))
child += SET_MEMBER
child += get_var('_level0') + push_string('cbx')
child += define_function('', ['ok'], trace_bracketed('xml:['))
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
# _root.lv = new LoadVars();  lv.onData = _level0.cbl;  lv.load("vars.txt");
frame4 += set_root_member('lv', new_obj('LoadVars'))
frame4 += (get_root_member('lv') + push_string('onData')
           + get_var('_level0') + push_string('cbl') + GET_MEMBER + SET_MEMBER)
frame4 += call_method(get_root_member('lv'), 'load', [push_string('vars.txt')], 1)
frame4 += POP
# _root.doc = new XML();  doc.onLoad = _level0.cbx;  doc.load("doc.xml");
frame4 += set_root_member('doc', new_obj('XML'))
frame4 += (get_root_member('doc') + push_string('onLoad')
           + get_var('_level0') + push_string('cbx') + GET_MEMBER + SET_MEMBER)
frame4 += call_method(get_root_member('doc'), 'load', [push_string('doc.xml')], 1)
frame4 += POP
frame4 += push_string('loading')
frame4 += TRACE
frame4 += END

build_swf('test.swf', 7, [frame1, None, None, frame4, None])
