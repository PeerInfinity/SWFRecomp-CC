#!/usr/bin/env python3
"""Build test.swf for resolve_type1_args.

Pins actionCallMethod's OBJECT `__resolve` arm — the call of the function that
`__resolve` *returned* — for a plain DefineFunction (type-1) callee:

    o.__resolve = r;  r() returns g;   o.missing("one", "two")

Two independent behaviours are pinned.

(1) ARG MARSHALLING (instance seven of the TYPE1_ARG_ORDER clamp/pad class).
    Before the Stage 3c migration onto invokeFunctionValue, this arm's type-1
    branch pushed exactly `num_args` values and let the callee's prologue pop
    `param_count` of them. Neither clamped nor padded, so:

      * a SHORT call made the prologue pop a value belonging to the caller's
        in-progress expression, binding a caller operand to a parameter;
      * a LONG call stranded the surplus on the caller's eval stack.

    Detected by pushing a sentinel string BENEATH the call operands and tracing
    it once the call's result is popped.

(2) SCOPE ORDER. This arm pushes the callee's fresh local scope FIRST and its
    captured closure scopes ON TOP of it — the inverse of every other dispatcher
    and of invokeFunctionValue. Because `getCurrentLocalScope()` skips is_with
    frames, parameter *binds* still land on the local frame either way; what
    differs is *lookup*: actionGetVariable walks the chain top-down over all
    frames, so under the inversion a captured scope shadows the callee's own
    parameters and locals.

    `h` is defined inside `with (w)`, so it captures `w` (is_with). `w.a` exists
    and `h`'s sole parameter is also named `a`. Under the inversion `h` reads
    `w.a`; if the ordering were ever normalized it would read its own parameter.
    That line is the guard on INV_LOCAL_SCOPE_UNDER_CAPTURED: normalizing the
    ordering (a Stage-4 decision) must update this expectation deliberately.

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
SET_VARIABLE = bytes([0x1D])
GET_MEMBER   = bytes([0x4E])
SET_MEMBER   = bytes([0x4F])
INIT_OBJECT  = bytes([0x43])
CALL_METHOD  = bytes([0x52])
POP          = bytes([0x17])
TRACE        = bytes([0x26])
ADD2         = bytes([0x47])
RETURN       = bytes([0x3E])
END          = bytes([0x00])

def define_function(name, params, body):
    payload = name.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(params))
    for p in params:
        payload += p.encode('utf-8') + b'\x00'
    payload += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(payload)) + payload + body

def with_block(body):
    """ActionWith: payload is just the UI16 body size; the body follows after."""
    return struct.pack('<BHH', 0x94, 2, len(body)) + body

def trace_concat(prefix, var_name):
    return (push_string(prefix) + push_string(var_name) + GET_VARIABLE
            + ADD2 + TRACE)

def call_missing_method(args, method='missing'):
    """push argN-1..arg0, num_args, o, "<method>", CallMethod, Pop.

    actionCallMethod pops args[0] first, so operands go on deepest-last.
    `method` is absent from `o`, so dispatch falls through to __resolve.
    """
    out = b''
    for a in reversed(args):
        out += push_string(a)
    out += push_float(float(len(args)))
    out += push_string('o')
    out += GET_VARIABLE          # receiver object
    out += push_string(method)   # method name (not present on o)
    out += CALL_METHOD
    out += POP                   # discard the call's return value
    return out

# ---- functions -----------------------------------------------------------

actions = b''

# g(a, b): trace("a=" + a); trace("b=" + b)
actions += define_function('g', ['a', 'b'],
                           trace_concat('a=', 'a') + trace_concat('b=', 'b'))

# r(n): return target   — the __resolve hook. Returns whichever function the
# global `target` currently holds, so one hook serves both sections.
actions += define_function('r', ['n'],
                           push_string('target') + GET_VARIABLE + RETURN)

# o = {}; o.__resolve = r
actions += push_string('o') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += (push_string('o') + GET_VARIABLE
            + push_string('__resolve')
            + push_string('r') + GET_VARIABLE
            + SET_MEMBER)

# ---- section 1: arg marshalling ------------------------------------------

# target = g
actions += push_string('target') + push_string('g') + GET_VARIABLE + SET_VARIABLE

# Exact arity. The sentinel beneath it must survive untouched.
actions += push_string('SENTINEL1')
actions += call_missing_method(['one', 'two'])
actions += TRACE

# Short call: the missing param pads with undefined. With the bug the prologue
# popped one value too many and bound a="SENTINEL2", b="only".
actions += push_string('SENTINEL2')
actions += call_missing_method(['only'])
actions += TRACE

# Long call: the surplus arg is dropped. With the bug the callee bound
# a="two", b="three" and left "one" stranded, so this TRACE printed "one".
actions += push_string('SENTINEL3')
actions += call_missing_method(['one', 'two', 'three'])
actions += TRACE

# ---- section 2: captured-scope ordering ----------------------------------

# w = {}; w.a = "W_A"
actions += push_string('w') + push_float(0.0) + INIT_OBJECT + SET_VARIABLE
actions += (push_string('w') + GET_VARIABLE
            + push_string('a') + push_string('W_A')
            + SET_MEMBER)

# with (w) { function h(a) { trace("h a=" + a) } }
#
# Defined inside the with-scope, so h captures [w] (is_with). h is stored
# globally: actionDefineFunction -> setVariableByName -> getCurrentLocalScope()
# skips is_with frames and finds none, so it falls through to the global table.
actions += push_string('w') + GET_VARIABLE
actions += with_block(define_function('h', ['a'], trace_concat('h a=', 'a')))

# target = h
actions += push_string('target') + push_string('h') + GET_VARIABLE + SET_VARIABLE

actions += push_string('SENTINEL4')
actions += call_missing_method(['one'], method='alsoMissing')
actions += TRACE

# The parameter bind landed on the local frame, not on the captured `w`.
actions += (push_string('w.a=')
            + push_string('w') + GET_VARIABLE
            + push_string('a') + GET_MEMBER
            + ADD2 + TRACE)

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
