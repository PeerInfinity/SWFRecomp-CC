#!/usr/bin/env python3
"""Build test.swf for fn_call_type1_args.

A SWF8 movie whose DoAction defines a plain DefineFunction (type-1, NOT
DefineFunction2) with two named parameters, then reaches Function.prototype.call
through GetMember rather than CallMethod("call"):

    push args; push num_args; push f; GetMember("call"); push undefined; CallMethod

That is the `g_getmember_call_target` shortcut arm of actionCallMethod. Its
type-1 branch pushed the call arguments in REVERSE order, so `f.call(null,
"one", "two")` bound a="two" / b="one" — the same TYPE1_ARG_ORDER bug class the
bcacc3f70 sweep fixed in six other dispatchers and Stage 0 of the dispatch
consolidation fixed in actionEI_callInternalInterface.

The apply form exercises the same arm through g_fn_apply_func, whose call_args
come from an array rather than the trailing operands.

DefineFunction is emitted by hand here because MTASC emits DefineFunction2 for
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

def push_null():
    item = b'\x02'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_undefined():
    item = b'\x03'
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
GET_MEMBER   = bytes([0x4E])
CALL_METHOD  = bytes([0x52])
INIT_ARRAY   = bytes([0x42])
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

# ---- function body: trace("a=" + a); trace("b=" + b); -------------------

body = b''
for pname in ('a', 'b'):
    body += push_string(pname + '=')
    body += push_string(pname)
    body += GET_VARIABLE
    body += ADD2
    body += TRACE

# ---- main actions -------------------------------------------------------

actions = b''
actions += define_function('f', ['a', 'b'], body)

# f.call(null, "one", "two") reached via GetMember("call").
# CallMethod stack (bottom->top): argN..arg1, num_args, object, method_name
actions += push_string('two')      # args[2]
actions += push_string('one')      # args[1]
actions += push_null()             # args[0] = thisArg
actions += push_float(3.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('call')
actions += GET_MEMBER              # -> Function.prototype.call, target = f
actions += push_undefined()        # empty method name
actions += CALL_METHOD
actions += POP

# f.apply(null, ["one", "two"]) reached via GetMember("apply").
actions += push_string('two')      # array element 1
actions += push_string('one')      # array element 0
actions += push_float(2.0)         # array length
actions += INIT_ARRAY              # args[1] = ["one", "two"]
actions += push_null()             # args[0] = thisArg
actions += push_float(2.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('apply')
actions += GET_MEMBER              # -> Function.prototype.apply, target = f
actions += push_undefined()        # empty method name
actions += CALL_METHOD
actions += POP

# A one-argument call must pad the missing param with undefined, not leave the
# callee's prologue popping the caller's eval stack.
actions += push_string('only')     # args[1]
actions += push_null()             # args[0] = thisArg
actions += push_float(2.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('call')
actions += GET_MEMBER
actions += push_undefined()
actions += CALL_METHOD
actions += POP

actions += push_string('done')
actions += TRACE
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
