#!/usr/bin/env python3
"""Build test.swf (SWF7 host) + child.swf (SWF6 child) for timer_cross_swf_version.

Exercises per-function SWF-version semantics on the timer dispatch path
(dispatch plan Stage 0, suspect 3: fireTimerCallback lacks
switchToFunctionVersion).

Host (v7):
    trace("host:[" + u + "]");            // v7: undefined -> "undefined"
    _root.createEmptyMovieClip("holder", 1);
    loadMovie("child.swf", "_level0.holder");

Child (v6):
    function cb() {
        clearInterval(_global.iid);
        trace("cb:[" + u + "]");          // v6 semantics: undefined -> ""
    }
    _global.iid = setInterval(cb, 1);
    trace("child:[" + u + "]");           // v6: undefined -> ""

Flash/Ruffle run a function with the SWF version of its DEFINING movie, so
cb must trace "cb:[]" even though the timer fires from the host's (v7) frame
loop. Without a version switch on the timer path it traces "cb:[undefined]".
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
CALL_FUNCTION = bytes([0x3D])
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

# cb body: clearInterval(_global.iid); trace("cb:[" + u + "]");
cb_body = b''
cb_body += get_var('_global') + push_string('iid') + GET_MEMBER  # arg1 (top)
cb_body += push_float(1.0)
cb_body += push_string('clearInterval')
cb_body += CALL_FUNCTION
cb_body += POP
cb_body += trace_bracketed('cb:[')

child = b''
child += define_function('cb', [], cb_body)
# _global.iid = setInterval(cb, 1);
child += get_var('_global')          # object
child += push_string('iid')          # member name
child += push_float(1.0)             # arg2 delay (deepest arg)
child += get_var('cb')               # arg1 function (top of args)
child += push_float(2.0)             # num_args
child += push_string('setInterval')
child += CALL_FUNCTION               # leaves interval id (the SetMember value)
child += SET_MEMBER
child += trace_bracketed('child:[')
child += END

build_swf('child.swf', 6, [child])

# ---- test.swf (SWF7 host) -------------------------------------------------

host = b''
host += trace_bracketed('host:[')
# _root.createEmptyMovieClip("holder", 1);
host += push_float(1.0)              # arg2 depth (deepest)
host += push_string('holder')        # arg1 name (top)
host += push_float(2.0)              # num_args
host += get_var('_root')
host += push_string('createEmptyMovieClip')
host += CALL_METHOD
host += POP
# loadMovie("child.swf", "_level0.holder");  (GetURL2, LoadTargetFlag)
host += push_string('child.swf')     # URL
host += push_string('_level0.holder')  # target
host += get_url2(0x40)
host += END

# 5 frames: frame 1 runs the loader; frames 2-5 idle so the child inits and
# its 1ms interval fires (self-clearing -> exactly one cb line).
build_swf('test.swf', 7, [host, None, None, None, None])
