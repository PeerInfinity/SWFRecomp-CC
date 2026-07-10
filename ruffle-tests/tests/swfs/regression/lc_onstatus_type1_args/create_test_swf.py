#!/usr/bin/env python3
"""Probe: lc_dispatch_onStatus (LocalConnection sender onStatus), type-1 callee.

LocalConnection.send to a channel nobody is connected to queues the message;
at end of frame delivery fails and the runtime fires onStatus on the SENDER
with {level: "error"}. Before Stage 4 the type-1 arm of lc_dispatch_onStatus
pushed that single event object with no clamp and no pad, so a plain
`DefineFunction` handler declaring two params popped its LAST param from the
event object and its first from the (empty) end-of-frame value stack — the
twelfth instance of the TYPE1_ARG_ORDER clamp/pad class (pad direction).

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode
(LocalConnection is Flash 6+). Fixed by migrating the onStatus dispatcher
family onto invokeFunctionValue in dispatch Stage 4.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); NEW_OBJECT = bytes([0x40]); POP = bytes([0x17])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def tc(prefix, var):
    return push_string(prefix) + push_string(var) + GET_VARIABLE + ADD2 + TRACE

def tc_member(prefix, var, member):
    return (push_string(prefix) + push_string(var) + GET_VARIABLE
            + push_string(member) + GET_MEMBER + ADD2 + TRACE)

def get_root_member(name):
    return push_string('_root') + GET_VARIABLE + push_string(name) + GET_MEMBER

def set_root_member(name, value_bytes):
    return push_string('_root') + GET_VARIABLE + push_string(name) + value_bytes + SET_MEMBER

def call_method(recv_bytes, method, args):
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += recv_bytes
    out += push_string(method)
    out += CALL_METHOD + POP
    return out

actions = b''
# The type-1 onStatus handler, two declared params: a should bind the event
# object ({level: "error"}), b should pad to undefined.
actions += define_function('handler', ['a', 'b'],
                           tc_member('a.level=', 'a', 'level') + tc('b=', 'b'))

# _root.sc = new LocalConnection(); sc.onStatus = handler;
# sc.send to a channel with no receiver -> delivery fails at end of frame.
actions += set_root_member('sc', push_float(0.0) + push_string('LocalConnection') + NEW_OBJECT)
actions += (get_root_member('sc') + push_string('onStatus')
            + push_string('handler') + GET_VARIABLE + SET_MEMBER)
actions += call_method(get_root_member('sc'), 'send', ['deadchan', 'nothing'])

# onStatus fires at end of frame, AFTER this marker.
actions += push_string('sent') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
