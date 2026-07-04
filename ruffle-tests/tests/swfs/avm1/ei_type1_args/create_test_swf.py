#!/usr/bin/env python3
"""Build test.swf for ei_type1_args.

A SWF8 movie whose DoAction defines a plain DefineFunction (type-1, NOT
DefineFunction2) callback with two named parameters, registers it via
flash.external.ExternalInterface.addCallback("extfunc", null, f), and traces
"registered". The per-test test_harness.c then invokes the callback through
actionEI_callInternalInterface with distinguishable args to verify type-1
argument marshalling (forward order + pad to param_count).

DefineFunction is emitted by hand here because MTASC emits DefineFunction2
for SWF6+; the whole point of this test is exercising the type-1 arm.
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
GET_MEMBER   = bytes([0x4E])
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

# ---- function body: trace("a="+a); trace("b="+b); return "ok"; ---------

body = b''
for pname in ('a', 'b'):
    body += push_string(pname + '=')
    body += push_string(pname)
    body += GET_VARIABLE
    body += ADD2
    body += TRACE
body += push_string('ok')
body += RETURN

# ---- main actions -------------------------------------------------------

actions = b''
actions += define_function('f', ['a', 'b'], body)

# flash.external.ExternalInterface.addCallback("extfunc", null, f);
# CallMethod stack (bottom->top): argN..arg1, num_args, object, method_name
actions += push_string('f')
actions += GET_VARIABLE            # arg3 = f (deepest)
actions += push_null()             # arg2 = null
actions += push_string('extfunc')  # arg1 = "extfunc" (top of args)
actions += push_float(3.0)         # num_args
actions += push_string('flash')
actions += GET_VARIABLE
actions += push_string('external')
actions += GET_MEMBER
actions += push_string('ExternalInterface')
actions += GET_MEMBER
actions += push_string('addCallback')
actions += CALL_METHOD
actions += POP

actions += push_string('registered')
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
