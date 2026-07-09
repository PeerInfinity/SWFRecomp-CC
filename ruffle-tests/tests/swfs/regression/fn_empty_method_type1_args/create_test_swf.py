#!/usr/bin/env python3
"""Build test.swf for fn_empty_method_type1_args.

Pins actionCallMethod's EMPTY-METHOD-NAME arm ("invoke the object as a
function") for a plain DefineFunction (type-1) callee:

    push argN..arg0; push num_args; push f; push undefined; CallMethod

Before the Stage 3c migration onto invokeFunctionValue, that arm's type-1 branch
pushed exactly `num_args` values onto the eval stack and let the callee's
prologue pop `param_count` of them. Neither clamped nor padded, so:

  * a SHORT call (fewer args than params) made the prologue pop values belonging
    to the caller's in-progress expression — binding a caller operand to a
    parameter;
  * a LONG call (more args than params) stranded the surplus on the caller's
    eval stack, corrupting whatever opcode ran next.

Both cases are detected here by pushing a sentinel string BEFORE the call
operands and tracing it after the call's result is popped. With the bug, the
short call binds the sentinel to a parameter and the long call traces a stray
argument in the sentinel's place.

Distinct from fn_call_type1_args, which covers the `.call`/`.apply`-via-GetMember
arm (`g_getmember_call_target`). This one has no GetMember at all: the receiver
is a bare FUNCTION value with an undefined method name.

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

def push_undefined():
    item = b'\x03'
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
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

def call_as_function(args):
    """push argN-1..arg0, num_args, f, undefined, CallMethod.

    actionCallMethod pops args[0] first, so the operands go on deepest-last.
    """
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += push_string('f')
    out += GET_VARIABLE
    out += push_undefined()   # empty method name -> invoke object as function
    out += CALL_METHOD
    out += POP                # discard the call's return value
    return out

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

# Exact arity. The sentinel below it must survive untouched.
actions += push_string('SENTINEL1')
actions += call_as_function(['one', 'two'])
actions += TRACE

# Short call: the missing param pads with undefined. With the bug the prologue
# popped one value too many and bound a="SENTINEL2", b="only".
actions += push_string('SENTINEL2')
actions += call_as_function(['only'])
actions += TRACE

# Long call: the surplus arg is dropped. With the bug the callee bound
# a="two", b="three" and left "one" stranded, so this TRACE printed "one".
actions += push_string('SENTINEL3')
actions += call_as_function(['one', 'two', 'three'])
actions += TRACE

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
