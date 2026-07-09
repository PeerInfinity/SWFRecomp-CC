#!/usr/bin/env python3
"""Build test.swf for array_element_type1_args.

A SWF8 movie whose DoAction defines a plain DefineFunction (type-1, NOT
DefineFunction2) with two named parameters, stores it as an array *element*, and
calls it through its numeric index:

    arr = [f]; arr[0]("one", "two", "three")

That lands in actionCallMethod's ARRAY receiver arm, numeric-index branch
("Try numeric index -> function call: arr[N](args)"). Its type-1 half pushed
`num_args` operands, neither clamping a long call nor padding a short one, so
the callee's prologue bound the LAST param_count of them:

    arr[0]("one", "two", "three")  ->  a="two", b="three", "one" leaked
    arr[0]("only")                 ->  a=<caller's stack top>, b="only"

Sibling of array_method_type1_args, which pins the `arr.m = f; arr.m(...)`
user-method branch of the same arm. Each over-long call is followed by POP +
TRACE of a sentinel pushed beneath it, so a leak traces the stranded argument
instead of the sentinel; the short call would swallow the sentinel outright.

DefineFunction is emitted by hand here because MTASC emits DefineFunction2 for
SWF6+; the whole point of this test is exercising the type-1 arm.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
SET_VARIABLE = bytes([0x1D])
INIT_ARRAY   = bytes([0x42])
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

body = b''
for pname in ('a', 'b'):
    body += push_string(pname + '=')
    body += push_string(pname)
    body += GET_VARIABLE
    body += ADD2
    body += TRACE

actions = b''
actions += define_function('f', ['a', 'b'], body)

# arr = [f];
actions += push_string('arr')
actions += push_string('f')
actions += GET_VARIABLE
actions += push_float(1.0)         # array length
actions += INIT_ARRAY
actions += SET_VARIABLE

# (1) arr[0]("one", "two", "three") — one argument more than f declares.
actions += push_string('X')        # caller-stack sentinel
actions += push_string('three')    # args[2]
actions += push_string('two')      # args[1]
actions += push_string('one')      # args[0]
actions += push_float(3.0)         # num_args
actions += push_string('arr')
actions += GET_VARIABLE
actions += push_string('0')        # method name = numeric index
actions += CALL_METHOD
actions += POP                     # discard f's return value
actions += TRACE                   # "X", unless an argument leaked

# (2) arr[0]("only") — one argument fewer; the missing param must pad to
# undefined rather than letting the prologue pop the caller's eval stack.
actions += push_string('Y')
actions += push_string('only')     # args[0]
actions += push_float(1.0)         # num_args
actions += push_string('arr')
actions += GET_VARIABLE
actions += push_string('0')
actions += CALL_METHOD
actions += POP
actions += TRACE                   # "Y"

actions += push_string('done')
actions += TRACE
actions += END

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
