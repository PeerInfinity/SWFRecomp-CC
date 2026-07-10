#!/usr/bin/env python3
"""Probe: fireLoadVarsCallback (LoadVars async-load dispatch), type-1 callee.

LoadVars.load queues a pending load; the frame loop drains it (right after
processTimers) by resolving `onData` on the receiver at fire time and calling
it with the raw file content. Before Stage 4 the type-1 arm of that dispatcher
pushed the delivered args in REVERSE with no clamp and no pad — the thirteenth
instance of the TYPE1_ARG_ORDER class. It was latent on the live path: every
caller passes exactly 1 arg (reverse == forward at 1) and the gnash LoadVars
handlers declare exactly 1 param. This repro reaches the arm with a plain
`DefineFunction` (type-1) onData handler declaring TWO params: before the fix
the prologue pops the content into `b` and `a` gets a stale caller-stack slot;
after, `a` gets the content and `b` pads to undefined.

MTASC emits DefineFunction2 for SWF6+, so this is hand-assembled SWF6 bytecode.
The data file `vars.txt` is auto-embedded by verify_output.py (HAS_DATA_FILES),
so the load succeeds offline and deterministically. Fixed by migrating
fireLoadVarsCallback onto invokeFunctionValue in dispatch Stage 4.
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

def new_obj(class_name):
    return push_float(0.0) + push_string(class_name) + NEW_OBJECT

def get_root_member(name):
    return push_string('_root') + GET_VARIABLE + push_string(name) + GET_MEMBER

def set_root_member(name, value_bytes):
    return push_string('_root') + GET_VARIABLE + push_string(name) + value_bytes + SET_MEMBER

def call_method(recv_bytes, method, args):
    # Stack (bottom->top): args[N-1..0], num_args, receiver, method.
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += recv_bytes
    out += push_string(method)
    out += CALL_METHOD + POP  # discard the return
    return out

actions = b''
# The type-1 onData handler, two declared params.
actions += define_function('handler', ['a', 'b'], tc('a=', 'a') + tc('b=', 'b'))

# _root.lv = new LoadVars(); _root.lv.onData = handler; lv.load("vars.txt")
actions += set_root_member('lv', new_obj('LoadVars'))
actions += (get_root_member('lv') + push_string('onData')
            + push_string('handler') + GET_VARIABLE + SET_MEMBER)
actions += call_method(get_root_member('lv'), 'load', ['vars.txt'])

# The drain fires post-timers in the frame loop, AFTER this marker.
actions += push_string('loading') + TRACE + END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
SHOW_FRAME = struct.pack('<H', 1 << 6)
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 2)
        + do_action + SHOW_FRAME + SHOW_FRAME + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
