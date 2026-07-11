#!/usr/bin/env python3
"""Build test.swf for watch_timeline_reentrant.

BUG REPRO (fail-before = runtime_segfault). The timeline watch arm (Site A,
actionSetVariable) and the MOVIECLIP watch arm (Site C, actionSetMember) had
NO re-entrancy guard: a watcher that sets the SAME watched variable again
re-entered the arm and recursed on the C stack until it segfaulted. Site B
(the OBJECT arm) has always bounded this with Flash's version-specific
re-fire depth (1 for SWF6, 65 for SWF7+ — accessorReentryLimit()) plus the
MAX_SPECIAL_DEPTH total-nesting cap; normalization pass (b) item 4 gives
Sites A and C the identical ritual (watch_firing_push/depth/pop keyed on
(NULL, mc, name)).

    c = 0;
    _root.watch("va", function (p, ov, nv, ud) {   // DefineFunction2 —
        c = c + 1;                                 // Site A fires type-2 only
        va = 9;                                    // re-set the watched var
    });
    trace("before");
    va = 1;                                        // <- segfaulted here
    trace("c=" + c);                               // 65 = SWF7+ re-fire depth
    trace("done");

Past the limit the value commits without re-firing (Site B semantics; Ruffle
recurses unboundedly here — its watch recursion tests are known_failure — so
Flash's bounded depth is the oracle, same decision as Site B's).
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    item = b'\x01' + struct.pack('<f', f)
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F]); CALL_METHOD = bytes([0x52])
INIT_OBJECT = bytes([0x43]); POP = bytes([0x17]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); END = bytes([0x00])

def get_var(n):
    return push_string(n) + GET_VARIABLE

def set_var(n, v):
    return push_string(n) + v + SET_VARIABLE

def call_method(obj, m, args_rev, n):
    out = b''
    for a in args_rev:
        out += a
    out += push_float(float(n)) + obj + push_string(m) + CALL_METHOD
    return out

def define_function2(name, params, register_count, flags, body):
    p = name.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(params))
    p += struct.pack('<B', register_count)
    p += struct.pack('<H', flags)
    for reg, pn in params:
        p += struct.pack('<B', reg) + pn.encode('utf-8') + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x8E, len(p)) + p + body

# watcher body: c = c + 1;  va = 9;
wb = set_var('c', get_var('c') + push_float(1.0) + ADD2)
wb += set_var('va', push_float(9.0))

actions = b''
actions += set_var('c', push_float(0.0))
actions += call_method(get_var('_root'), 'watch',
                       [define_function2('', [(0, 'p'), (0, 'ov'), (0, 'nv'), (0, 'ud')], 0, 0, wb),
                        push_string('va')], 2)
actions += POP
actions += push_string('before') + TRACE
actions += set_var('va', push_float(1.0))
actions += push_string('c=') + get_var('c') + ADD2 + TRACE
actions += push_string('done') + TRACE
actions += END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags = do_action + struct.pack('<H', 1 << 6) + bytes([0, 0])
rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
body = rect + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
print(f'Created test.swf (v8, {8 + len(body)} bytes)')
