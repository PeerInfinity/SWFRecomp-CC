#!/usr/bin/env python3
"""Build test.swf for fn_call_builtin_type1_args.

A SWF8 movie whose DoAction defines a plain DefineFunction (type-1, NOT
DefineFunction2) with two named parameters, then reaches Function.prototype.call
and Function.prototype.apply through the ordinary method-call bytecode:

    push args; push num_args; push f; push "call"; CallMethod

That lands in actionCallMethod's *builtin* `.call`/`.apply` handlers, a
different site from the `g_getmember_call_target` shortcut arm that
`fn_call_type1_args` pins (which uses GetMember("call") + CallMethod(undefined)).

Their type-1 branches padded the pushed operands up to `param_count` but never
CLAMPED them, so an over-long call pushed every argument and the callee's
prologue popped only the last `param_count` of them:

    f.call(null, "one", "two", "three")   ->  a="two", b="three"

and "one" was stranded on the *caller's* eval stack, where the next POP/TRACE
picked it up. Each over-long call is therefore followed here by POP + TRACE of a
sentinel pushed before the call: a leak traces the stranded argument instead of
the sentinel. Predicted by the Stage 3c design survey (plan §4, `action.c:65659`)
and confirmed by this test; fixed by routing both branches through
`invokeFunctionValue`'s single forward+clamp+pad marshalling loop.

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

GET_VARIABLE = bytes([0x1C])
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

# (1) f.call(null, "one", "two", "three") — one argument more than f declares.
# CallMethod stack (bottom->top): argN..arg1, num_args, object, method_name.
# "X" sits under the whole call; a missing clamp strands "one" above it.
actions += push_string('X')        # caller-stack sentinel
actions += push_string('three')    # args[3]
actions += push_string('two')      # args[2]
actions += push_string('one')      # args[1]
actions += push_null()             # args[0] = thisArg
actions += push_float(4.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('call')     # -> the builtin Function.prototype.call arm
actions += CALL_METHOD
actions += POP                     # discard f's return value
actions += TRACE                   # "X", unless an argument leaked

# (2) f.apply(null, ["one", "two", "three"]) — same overflow via the array form.
actions += push_string('Y')        # caller-stack sentinel
actions += push_string('three')    # array element 2
actions += push_string('two')      # array element 1
actions += push_string('one')      # array element 0
actions += push_float(3.0)         # array length
actions += INIT_ARRAY              # args[1] = ["one", "two", "three"]
actions += push_null()             # args[0] = thisArg
actions += push_float(2.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('apply')    # -> the builtin Function.prototype.apply arm
actions += CALL_METHOD
actions += POP
actions += TRACE                   # "Y", unless an argument leaked

# (3) A one-argument call must still pad the missing param with undefined
# (the pad half of the loop already worked; this guards against regressing it).
actions += push_string('Z')
actions += push_string('only')     # args[1]
actions += push_null()             # args[0] = thisArg
actions += push_float(2.0)         # num_args
actions += push_string('f')
actions += GET_VARIABLE
actions += push_string('call')
actions += CALL_METHOD
actions += POP
actions += TRACE                   # "Z"

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
