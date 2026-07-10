#!/usr/bin/env python3
"""Probe: lc_dispatch_method (LocalConnection method dispatch), type-1 callee.

LocalConnection.send queues a message; at end of frame the runtime delivers it
by resolving the named method on the receiver and calling it. Before Stage 4 the
type-1 arm of that dispatcher pushed the delivered args in REVERSE with no clamp
and no pad — the tenth instance of the TYPE1_ARG_ORDER class. It was latent on a
live path: the existing avm1 `localconnection` test reaches the arm but only ever
with num_args = 0, param_count = 0. This repro reaches it with a plain
`DefineFunction` (type-1) receiver method declaring two params, invoked with 2,
1, and 3 args — pinning arg order, pad, and clamp respectively.

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode
(LocalConnection is Flash 6+; Flash MX-era SWF6 emits DefineFunction). Fixed by
migrating lc_dispatch_method onto invokeFunctionValue in dispatch Stage 4.
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

def new_lc():
    return push_float(0.0) + push_string('LocalConnection') + NEW_OBJECT

def get_root_member(name):
    return push_string('_root') + GET_VARIABLE + push_string(name) + GET_MEMBER

def set_root_member(name, value_bytes):
    return push_string('_root') + GET_VARIABLE + push_string(name) + value_bytes + SET_MEMBER

def call_method(recv_bytes, method, args):
    # Stack (bottom->top): args[N-1..0], num_args, receiver, method. CallMethod
    # pops method, receiver, num_args, then args[0..] (args[0] = top of region),
    # so push the arg list in reverse.
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += recv_bytes
    out += push_string(method)
    out += CALL_METHOD + POP  # discard the boolean return
    return out

actions = b''
# The shared type-1 receiver method, two declared params.
actions += define_function('myMethod', ['a', 'b'], tc('a=', 'a') + tc('b=', 'b'))

# _root.rc = new LocalConnection(); _root.rc.myMethod = myMethod; rc.connect("ch")
actions += set_root_member('rc', new_lc())
actions += (get_root_member('rc') + push_string('myMethod')
            + push_string('myMethod') + GET_VARIABLE + SET_MEMBER)
actions += call_method(get_root_member('rc'), 'connect', ['ch'])

# _root.sc = new LocalConnection(); send three shapes to rc.myMethod.
actions += set_root_member('sc', new_lc())
actions += call_method(get_root_member('sc'), 'send', ['ch', 'myMethod', 'one', 'two'])
actions += call_method(get_root_member('sc'), 'send', ['ch', 'myMethod', 'solo'])
actions += call_method(get_root_member('sc'), 'send', ['ch', 'myMethod', 'x1', 'x2', 'x3'])

# Delivered at end of frame, AFTER this marker.
actions += push_string('sent') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
