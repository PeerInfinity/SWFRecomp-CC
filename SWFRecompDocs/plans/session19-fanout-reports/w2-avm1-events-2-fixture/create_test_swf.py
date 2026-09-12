#!/usr/bin/env python3
"""Build test.swf for ctor_before_first_call_locals.

BUG REPRO (fail-before = every local in the constructor reads `undefined`).
`setVariableOnLocalScope` (action.c) allocates the property name through
`setProperty(g_scope_app_context, ...)`, and `g_scope_app_context` is a
file-static that was assigned ONLY at the entry of `actionCallFunction`,
`actionCallMethod` and `actionNewMethod`. `actionNewObject` never set it, so
when the FIRST user code in a movie is a `new`-invoked constructor the static
is still NULL: `heap_alloc(NULL, ...)` returns NULL, and `object.c`'s
setProperty then silently DROPS the property (`num_used--`). The named
parameter never lands in the local frame and neither does any `var` the
constructor declares — both read back as `undefined`, with no diagnostic
beyond a stderr warning.

    Foo = function (p) {            // DefineFunction2, param in register 0
        v = "L";                    //   -> setVariableByName -> local scope
        trace("p=" + p);            //   dropped  -> "p=undefined"
        trace("v=" + v);            //   dropped  -> "v=undefined"
    };
    o = new Foo("A");               // <- FIRST call of any kind in the movie
    trace("done");

The order matters and is the whole point: a single preceding ordinary call
(`noop()`) latches `g_scope_app_context` and hides the bug, so the fixture
puts the `new` first and only then calls a plain function, whose locals are
traced as the control row (they were always correct).

Fixed by seeding `g_scope_app_context` in `actionNewObject` (and once in
`ensureGlobalInit`, so no future entry point can reintroduce the hole).

`DefineFunction2` (0x8E) is hand-assembled with register_count=0, flags=0 and
the parameter in register 0 (bind-by-name into the local scope) — that is the
shape whose prologue goes through `setVariableByName`. The SWF is v8.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
NEW_OBJECT   = bytes([0x40]); POP = bytes([0x17])
CALL_FUNCTION = bytes([0x3D])
TRACE = bytes([0x26]); ADD2 = bytes([0x47]); END = bytes([0x00])

def define_function2(name, params, register_count, flags, body):
    """DefineFunction2 (0x8E). params = [(register, name), ...]; register 0
    means bind by name into the local scope (no preload)."""
    p = name.encode() + b'\x00'
    p += struct.pack('<H', len(params))
    p += struct.pack('<B', register_count)
    p += struct.pack('<H', flags)
    for reg, pname in params:
        p += struct.pack('<B', reg) + pname.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x8E, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

def set_var(name, value_bytes):
    return push_string(name) + value_bytes + SET_VARIABLE

# Foo(p): v = "L"; trace("p=" + p); trace("v=" + v);
ctor_body = (
    set_var('v', push_string('L'))
    + push_string('p=') + gv('p') + ADD2 + TRACE
    + push_string('v=') + gv('v') + ADD2 + TRACE
)

# Bar(q): w = "M"; trace("q=" + q); trace("w=" + w);   (control row)
plain_body = (
    set_var('w', push_string('M'))
    + push_string('q=') + gv('q') + ADD2 + TRACE
    + push_string('w=') + gv('w') + ADD2 + TRACE
)

actions = b''
actions += set_var('Foo', define_function2('', [(0, 'p')], 0, 0, ctor_body))
actions += set_var('Bar', define_function2('', [(0, 'q')], 0, 0, plain_body))
# The FIRST call of any kind in the movie is a `new`.
actions += set_var('o', push_string('A') + push_float(1.0)
                        + push_string('Foo') + NEW_OBJECT)
# Control: an ordinary call afterwards (always worked).
actions += push_string('B') + push_float(1.0) + push_string('Bar') + CALL_FUNCTION + POP
actions += push_string('done') + TRACE
actions += END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags = do_action + struct.pack('<H', 1 << 6) + bytes([0, 0])
def make_rect(xmin, xmax, ymin, ymax):
    """SWF RECT, twips. Field-width-first, MSB-first, zero-padded. The four
    fields are SIGNED (Ruffle's read_rect uses read_sbits), so the width needs
    a spare sign bit — without it Ruffle reads a 550px stage as width 0 and
    the exporter refuses to render."""
    nbits = max(1, max(v.bit_length() for v in (xmin, xmax, ymin, ymax)) + 1)
    bits = f'{nbits:05b}' + ''.join(f'{v:0{nbits}b}' for v in (xmin, xmax, ymin, ymax))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return bytes(int(bits[i:i + 8], 2) for i in range(0, len(bits), 8))

rect = make_rect(0, 11000, 0, 8000)   # 550 x 400 px
body = rect + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
with open('test.swf', 'wb') as fh:
    fh.write(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
print(f'Created test.swf (v8, {8 + len(body)} bytes)')
