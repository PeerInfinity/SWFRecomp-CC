#!/usr/bin/env python3
"""Build test.swf for coerce_recursion_guard.

BUG REPRO (fail-before = runtime_segfault). The coercion dispatch paths
(objectCallValueOf / objectCallToString / objectToPrimitive / convertFloat)
had NO recursion guard of any kind: a valueOf that re-triggers numeric
coercion of its own receiver recursed on the C stack until it segfaulted.

    o = {};
    o.valueOf = function () { return o - 1; };  // Subtract -> convertFloat
                                                // -> valueOf -> Subtract -> ...
    trace("before");
    r = o - 1;                                  // <- segfaulted here
    trace("r=" + r);
    trace("done");

Normalization pass (b) item 4 adds INV_SPECIAL_GUARD to all eight coercion
invoke sites: the core increments g_special_depth and at MAX_SPECIAL_DEPTH
(66) HALTS all script execution, returning undefined — Ruffle's model
exactly (ExecutionReason::Special, activation.rs special_count == 65 ->
SpecialRecursionLimit -> handle_error -> avm1.halt()). Flash likewise
aborts the action list on its recursion limits.

Expected output is therefore just "before": the recursion trips the limit,
execution halts, and neither "r=" nor "done" prints. (The legacy
g_special_depth users — sound/LV/unload dispatch — return non-fatally, a
preserved divergence; only the coercion guard takes Ruffle's halting
semantics.)

DefineFunction is emitted by hand; the SWF is v8.
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
SET_MEMBER   = bytes([0x4F])
INIT_OBJECT  = bytes([0x43])
TRACE        = bytes([0x26])
ADD2         = bytes([0x47])
SUBTRACT     = bytes([0x0B])
RETURN       = bytes([0x3E])
END          = bytes([0x00])

def get_var(n):
    return push_string(n) + GET_VARIABLE

def set_var(n, v):
    return push_string(n) + v + SET_VARIABLE

def define_function(name, params, body):
    p = name.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(params))
    for x in params:
        p += x.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

# o.valueOf body: return o - 1;
fb = get_var('o') + push_float(1.0) + SUBTRACT + RETURN

actions = b''
actions += set_var('o', push_float(0.0) + INIT_OBJECT)
actions += get_var('o') + push_string('valueOf') + define_function('', [], fb) + SET_MEMBER
actions += push_string('before') + TRACE
actions += set_var('r', get_var('o') + push_float(1.0) + SUBTRACT)
actions += push_string('r=') + get_var('r') + ADD2 + TRACE
actions += push_string('done') + TRACE
actions += END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags = do_action + struct.pack('<H', 1 << 6) + bytes([0, 0])
rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
body = rect + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
print(f'Created test.swf (v8, {8 + len(body)} bytes)')
