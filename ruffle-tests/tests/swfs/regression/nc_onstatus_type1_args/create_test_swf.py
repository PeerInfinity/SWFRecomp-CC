#!/usr/bin/env python3
"""Probe: nc_dispatch_onStatus (NetConnection onStatus delivery), type-1 callee.

nc.connect(null) fires NetConnection.Connect.Success synchronously, delivering
one info object to the onStatus handler. Before Stage 4 the type-1 arm of
nc_dispatch_onStatus pushed that single arg with no clamp and no pad, so a plain
`DefineFunction` handler declaring two params popped its LAST param from the
info object and its first from whatever sat below on the value stack — the
eleventh instance of the TYPE1_ARG_ORDER clamp/pad class (pad direction: the
core pushes args[0] forward and pads the second param with undefined).

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode
(NetConnection is Flash 6+). Fixed by migrating the onStatus dispatcher family
onto invokeFunctionValue in dispatch Stage 4.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

def push_null():
    return struct.pack('<BH', 0x96, 1) + b'\x02'

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

actions = b''
# The type-1 onStatus handler, two declared params: a should bind the info
# object, b should pad to undefined ("" under SWF6 string coercion).
actions += define_function('handler', ['a', 'b'],
                           tc_member('a.code=', 'a', 'code') + tc('b=', 'b'))

# _root.nc = new NetConnection(); nc.onStatus = handler; nc.connect(null)
actions += set_root_member('nc', push_float(0.0) + push_string('NetConnection') + NEW_OBJECT)
actions += (get_root_member('nc') + push_string('onStatus')
            + push_string('handler') + GET_VARIABLE + SET_MEMBER)
actions += (push_null() + push_float(1.0) + get_root_member('nc')
            + push_string('connect') + CALL_METHOD + POP)

# onStatus fires synchronously inside connect, BEFORE this marker.
actions += push_string('done') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
