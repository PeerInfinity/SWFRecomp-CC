#!/usr/bin/env python3
"""Build test.swf for string_prim_method_type1_args.

Pins actionCallMethod's STRING-primitive arm — a user-overridden
String.prototype method invoked on a primitive receiver — for a plain
DefineFunction (type-1) callee:

    String.prototype.m = m;   "abc".m("one", "two")

Two behaviours are pinned.

(1) ARG MARSHALLING (instance eight of the TYPE1_ARG_ORDER clamp/pad class).
    Before the Stage 3c migration onto invokeFunctionValue, this arm's type-1
    branch pushed exactly `num_args` values and let the callee's prologue pop
    `param_count` of them. Neither clamped nor padded, so a SHORT call popped a
    value belonging to the caller's in-progress expression and a LONG call
    stranded the surplus on the caller's eval stack. Detected with a sentinel
    string pushed BENEATH the call operands and traced once the result is popped.

(2) THE TYPE-1 ACTIVATION RITUAL. This arm reads `_sp_fn->flags` without first
    branching on function_type, so it applies the *type-2* activation to type-1
    bodies too: a plain DefineFunction (whose `flags` is always 0) gets "this",
    "arguments" AND "super" bound by name on its local scope. The core's
    INV_ACT_* rule table deliberately gives a type-1 callee no "this"/"super"
    scope binding, so migrating with act_flags = THIS|ARGUMENTS|SUPER alone would
    silently drop two of them.

    `typeof super` is the discriminator: it reads "object" only because the arm
    bound `super` on a type-1 frame. `this` and `arguments.length` are traced for
    completeness. Behaviour-preserving migration keeps all three; normalizing
    this arm to the core's type-1 rules (a Stage-4 decision) must change these
    expectations deliberately.

DefineFunction is emitted by hand because MTASC emits DefineFunction2 for SWF6+,
and the type-1 arm cannot be reached any other way.
"""
import struct

# ---- action helpers ----------------------------------------------------

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
GET_MEMBER   = bytes([0x4E])
SET_MEMBER   = bytes([0x4F])
CALL_METHOD  = bytes([0x52])
POP          = bytes([0x17])
TRACE        = bytes([0x26])
ADD2         = bytes([0x47])
TYPE_OF      = bytes([0x44])
END          = bytes([0x00])

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

def trace_concat(prefix, var_name):
    return push_string(prefix) + push_string(var_name) + GET_VARIABLE + ADD2 + TRACE

def call_string_method(args):
    """push argN-1..arg0, num_args, "abc", "m", CallMethod, Pop.

    actionCallMethod pops args[0] first, so operands go on deepest-last. The
    receiver is a String *primitive*, which is what selects this arm.
    """
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += push_string('abc')    # primitive receiver
    out += push_string('m')      # method name
    out += CALL_METHOD
    out += POP                   # discard the call's return value
    return out

# ---- method body ---------------------------------------------------------

body = b''
body += trace_concat('a=', 'a')
body += trace_concat('b=', 'b')
# `this` is the transient String wrapper box; Add2 coerces it via valueOf.
body += trace_concat('t=', 'this')
# "object" only because this arm binds `super` on a *type-1* local frame.
body += (push_string('ts=') + push_string('super') + GET_VARIABLE + TYPE_OF
         + ADD2 + TRACE)
body += (push_string('n=') + push_string('arguments') + GET_VARIABLE
         + push_string('length') + GET_MEMBER + ADD2 + TRACE)

# ---- main actions --------------------------------------------------------

actions = b''
actions += define_function('m', ['a', 'b'], body)

# String.prototype.m = m
actions += (push_string('String') + GET_VARIABLE
            + push_string('prototype') + GET_MEMBER
            + push_string('m')
            + push_string('m') + GET_VARIABLE
            + SET_MEMBER)

# Exact arity. The sentinel beneath it must survive untouched.
actions += push_string('SENTINEL1')
actions += call_string_method(['one', 'two'])
actions += TRACE

# Short call: the missing param pads with undefined. With the bug the prologue
# popped one value too many and bound a="SENTINEL2", b="only".
actions += push_string('SENTINEL2')
actions += call_string_method(['only'])
actions += TRACE

# Long call: the surplus arg is dropped. With the bug the callee bound
# a="two", b="three" and left "one" stranded, so this TRACE printed "one".
actions += push_string('SENTINEL3')
actions += call_string_method(['one', 'two', 'three'])
actions += TRACE

actions += push_string('done') + TRACE
actions += END

# ---- SWF wrapper ---------------------------------------------------------

do_action_tag = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
show_frame_tag = struct.pack('<H', 1 << 6)
end_tag = bytes([0x00, 0x00])

rect_data = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
frame_rate = struct.pack('<H', 24 << 8)
frame_count = struct.pack('<H', 1)

tags = do_action_tag + show_frame_tag + end_tag
tag_body = rect_data + frame_rate + frame_count + tags
file_length = 8 + len(tag_body)

with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, file_length) + tag_body)

print(f'Created test.swf ({file_length} bytes)')
