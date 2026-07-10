#!/usr/bin/env python3
"""Build test.swf for watch_timeline_named_params.

Real-bug repro for the timeline watch arm (actionSetVariable, dossier Site A,
D13): the arm passed the freshly-allocated property-name arg OWNING and then
freed it unconditionally after the call. Every suite watcher is a
register-preloaded DefineFunction2, whose prologue copies args into the
registers array — the arg's string is never bound into the local scope, so
the single explicit free was correct. But a NAMED-param DefineFunction2
(register slot 0 for every param — what Flash emits when a function body
references `arguments` siblings or the compiler skips preloading) binds each
arg via setVariableByName -> setProperty, which POINTER-SHARES the string
into the local frame with owns_memory intact; releaseObject on that frame
frees it, and the arm's unconditional free() then double-frees (heap
corruption / glibc abort).

DefineFunction2 (0x8E) is hand-assembled with register_count=0, flags=0, and
all params in register 0 (named binding). The watcher also stashes `prop`
into a timeline var so the fixed discipline (non-owning + never freed, the
OBJECT arm's documented leak-over-dangle) is pinned against the dangle
alternative: `stash` must still print "tv" AFTER the call.

Site A only fires type-2 watchers on timeline variables watched via
`_root.watch(name, fn)` (the MC name-dispatch registration with mc == the
current context), set through a plain SetVariable.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

def push_float(f):
    return struct.pack('<BH', 0x96, 5) + b'\x01' + struct.pack('<f', f)

GET_VARIABLE = bytes([0x1C]); SET_VARIABLE = bytes([0x1D])
GET_MEMBER = bytes([0x4E]); SET_MEMBER = bytes([0x4F])
CALL_METHOD = bytes([0x52]); POP = bytes([0x17]); TRACE = bytes([0x26])
ADD2 = bytes([0x47]); RETURN = bytes([0x3E]); END = bytes([0x00])

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

def call_method(recv_bytes, method, arg_pushes):
    out = b''
    for a in reversed(arg_pushes):
        out += a
    out += push_float(float(len(arg_pushes)))
    out += recv_bytes
    out += push_string(method)
    return out + CALL_METHOD + POP

actions = b''

# function w(prop, oldV, newV, ud) {   // named params, 0 registers
#   trace("w: " + prop + "|" + oldV + "|" + newV + "|" + ud);
#   stash = prop;                       // pointer-shared copy outlives the call
#   return newV;
# }
w_body = (push_string('w: ')
          + gv('prop') + ADD2 + push_string('|') + ADD2
          + gv('oldV') + ADD2 + push_string('|') + ADD2
          + gv('newV') + ADD2 + push_string('|') + ADD2
          + gv('ud') + ADD2 + TRACE
          + push_string('stash') + gv('prop') + SET_VARIABLE
          + gv('newV') + RETURN)
actions += define_function2('w', [(0, 'prop'), (0, 'oldV'), (0, 'newV'), (0, 'ud')],
                            0, 0, w_body)

# _root.watch("tv", w, "UD");   // timeline watch: obj==NULL, mc==root
actions += call_method(gv('_root'), 'watch',
                       [push_string('tv'), gv('w'), push_string('UD')])

# tv = "x1";  -> SetVariable -> Site A fires the watcher
actions += push_string('tv') + push_string('x1') + SET_VARIABLE

actions += (push_string('stored tv=') + gv('tv') + ADD2 + TRACE)
actions += (push_string('stash=') + gv('stash') + ADD2 + TRACE)
actions += push_string('end') + TRACE
actions += END

do_action = struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 1)
        + do_action + struct.pack('<H', 1 << 6) + bytes([0, 0]))
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
