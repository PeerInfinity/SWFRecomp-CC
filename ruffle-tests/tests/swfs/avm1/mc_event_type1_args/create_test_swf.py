#!/usr/bin/env python3
"""Build test.swf for mc_event_type1_args.

A SWF8 movie that assigns type-1 (plain DefineFunction, NOT DefineFunction2)
AS2 event handlers WITH declared parameters and fires them via
Selection.setFocus focus changes:

    createTextField("t1", 1, 0, 0, 100, 20);
    createTextField("t2", 2, 0, 30, 100, 20);
    t1.onSetFocus = function (old) { trace("t1 old=" + old); };
    t2.onSetFocus = function (old, x) { trace("t2 old=" + old + " x=" + x); };
    Selection.setFocus(t1);   // t1 old=null
    Selection.setFocus(t2);   // t2 old=_level0.t1 x=undefined
    trace("done");

Flash semantics: onSetFocus receives oldFocus as its argument; params beyond
the event's arguments read undefined. This exercises mc_call_as2_handler_ng's
type-1 arm, which must marshal handler_args forward-order and pad to
param_count (the generated type-1 prologue pops EXACTLY param_count values —
without marshalling it swallows unrelated eval-stack slots).

DefineFunction is emitted by hand because MTASC emits DefineFunction2 for
SWF6+; the whole point of this test is exercising the type-1 arm.
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
END          = bytes([0x00])

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

# ---- handler bodies ------------------------------------------------------

# trace("t1 old=" + old);
body_t1 = (push_string('t1 old=') + get_var('old') + ADD2 + TRACE)

# trace("t2 old=" + old + " x=" + x);
body_t2 = (push_string('t2 old=') + get_var('old') + ADD2 +
           push_string(' x=') + ADD2 + get_var('x') + ADD2 + TRACE)

# ---- main actions ---------------------------------------------------------

actions = b''

# createTextField("t1", 1, 0, 0, 100, 20) / ("t2", 2, 0, 30, 100, 20) on _root
for name, depth, y in (('t1', 1, 0), ('t2', 2, 30)):
    actions += call_method(
        get_var('_root'), 'createTextField',
        [push_float(20.0),          # arg6 height (deepest)
         push_float(100.0),         # arg5 width
         push_float(float(y)),      # arg4 y
         push_float(0.0),           # arg3 x
         push_float(float(depth)),  # arg2 depth
         push_string(name)],        # arg1 name (top)
        6)
    actions += POP

# t1.onSetFocus = function (old) {...};
actions += get_var('t1')
actions += push_string('onSetFocus')
actions += define_function('', ['old'], body_t1)   # anonymous -> pushed on stack
actions += SET_MEMBER

# t2.onSetFocus = function (old, x) {...};
actions += get_var('t2')
actions += push_string('onSetFocus')
actions += define_function('', ['old', 'x'], body_t2)
actions += SET_MEMBER

# Selection.setFocus(t1); Selection.setFocus(t2);
for name in ('t1', 't2'):
    actions += call_method(get_var('Selection'), 'setFocus', [get_var(name)], 1)
    actions += POP

actions += push_string('done')
actions += TRACE
actions += END

# ---- SWF wrapper -----------------------------------------------------------

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
