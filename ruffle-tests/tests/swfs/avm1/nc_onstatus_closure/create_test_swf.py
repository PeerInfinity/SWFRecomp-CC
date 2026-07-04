#!/usr/bin/env python3
"""Build test.swf for nc_onstatus_closure.

Verifies that a closure used as a NetConnection.onStatus handler keeps its
captured scope when invoked through the NC dispatch path (dispatch plan
Stage 0, suspect 4):

    function make() {
        var secret = "s3cret";
        return function () { trace("closure:" + secret); };
    }
    nc = new NetConnection();
    nc.onStatus = make();
    nc.connect(null);          // fires onStatus NetConnection.Connect.Success
    trace("done");

`secret` lives in make's activation scope (DefineLocal in a plain
DefineFunction), which the anonymous inner function captures at definition
time; the dispatcher must restore that captured scope or `secret` reads
undefined. Hand-assembled SWF8 bytecode.
"""
import struct

# ---- action helpers ----------------------------------------------------

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

def push_null():
    item = b'\x02'
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE  = bytes([0x1C])
SET_VARIABLE  = bytes([0x1D])
SET_MEMBER    = bytes([0x4F])
CALL_METHOD   = bytes([0x52])
CALL_FUNCTION = bytes([0x3D])
NEW_OBJECT    = bytes([0x40])
DEFINE_LOCAL  = bytes([0x3C])
POP           = bytes([0x17])
TRACE         = bytes([0x26])
ADD2          = bytes([0x47])
RETURN        = bytes([0x3E])
END           = bytes([0x00])

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

def get_var(name):
    return push_string(name) + GET_VARIABLE

# ---- inner closure body: trace("closure:" + secret) ----------------------

inner_body = (push_string('closure:') + get_var('secret') + ADD2 + TRACE)

# ---- make body: var secret = "s3cret"; return function(){...}; -----------

make_body = b''
make_body += push_string('secret') + push_string('s3cret') + DEFINE_LOCAL
make_body += define_function('', [], inner_body)   # anonymous -> on stack
make_body += RETURN

# ---- main actions ----------------------------------------------------------

actions = b''
actions += define_function('make', [], make_body)

# nc = new NetConnection();
actions += push_string('nc')            # SetVariable name
actions += push_float(0.0)              # num ctor args
actions += push_string('NetConnection')
actions += NEW_OBJECT
actions += SET_VARIABLE

# nc.onStatus = make();
actions += get_var('nc')                # object
actions += push_string('onStatus')      # member name
actions += push_float(0.0)              # num args to make()
actions += push_string('make')
actions += CALL_FUNCTION                # value on stack
actions += SET_MEMBER

# nc.connect(null);
actions += push_null()                  # arg1
actions += push_float(1.0)
actions += get_var('nc')
actions += push_string('connect')
actions += CALL_METHOD
actions += POP

actions += push_string('done')
actions += TRACE
actions += END

# ---- SWF wrapper -------------------------------------------------------------

do_action_tag = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 2)

tags = do_action_tag + show_frame_tag + show_frame_tag + end_tag
tag_body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(tag_body)

with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, file_length) + tag_body)

print(f'Created test.swf ({file_length} bytes)')
