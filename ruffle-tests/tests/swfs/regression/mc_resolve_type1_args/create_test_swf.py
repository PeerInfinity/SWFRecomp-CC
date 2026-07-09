#!/usr/bin/env python3
"""Probe: actionCallMethod's MOVIECLIP-receiver __resolve hook, type-1 callee.

The OBJECT __resolve hook goes through invokeResolveFunction (the core), which
pushes exactly param_count values. The MOVIECLIP __resolve hook is hand-rolled
and pushes the synthesized name argument unconditionally, with no clamp and no
pad. So a type-1 __resolve declaring a param_count other than 1 mis-binds.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); POP = bytes([0x17])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params: p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def tc(prefix, var):
    return push_string(prefix) + push_string(var) + GET_VARIABLE + ADD2 + TRACE

def call_missing(method):
    return (push_float(0.0)                      # num_args = 0
            + push_string('_root') + GET_VARIABLE  # MOVIECLIP receiver
            + push_string(method) + CALL_METHOD + POP)

actions = b''
# __resolve declaring TWO params: gets the name plus one stolen caller operand.
actions += define_function('r2', ['a', 'b'], tc('r2 a=', 'a') + tc('r2 b=', 'b'))
# __resolve declaring ZERO params: the pushed name is stranded on the stack.
actions += define_function('r0', [], push_string('r0 ran') + TRACE)

def set_resolve(fn):
    return (push_string('_root') + GET_VARIABLE
            + push_string('__resolve')
            + push_string(fn) + GET_VARIABLE + SET_MEMBER)

actions += set_resolve('r2')
actions += push_string('SENTINEL1')
actions += call_missing('zzzMissingA')
actions += TRACE

actions += set_resolve('r0')
actions += push_string('SENTINEL2')
actions += call_missing('zzzMissingB')
actions += TRACE

actions += push_string('done') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78,0x00,0x0F,0xA0,0x00,0x00,0x0F,0xA0,0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0,0]))
open('test.swf','wb').write(b'FWS' + struct.pack('<BI', 8, 8+len(body)) + body)
print('ok')
