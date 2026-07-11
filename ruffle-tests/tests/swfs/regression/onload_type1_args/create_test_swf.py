#!/usr/bin/env python3
"""Build test.swf for onload_type1_args.

BEHAVIOR LOCK, not a bug repro (verified identical before/after the Stage-4
migration — say so honestly, per the worthless-as-repro guardrail). Pins
actionDispatchMCOnLoad's type-1 ritual, which is richer than its enterFrame
sibling: the arm pushes a this-stack entry (so a type-1 handler DOES have a
`this` channel — unlike the enterFrame children arm) and name-binds "this"
on its local frame (INV_BIND_THIS — dead for reads via the this-cell fast
path, preserved by the migration because the existing flag reproduces it at
zero cost). The core's clamp/pad is inert here: unlike onConstruct (which
fires mid-script and yielded regression/onconstruct_type1_args, the 19th
TYPE1_ARG_ORDER instance), onLoad only ever fires from the deferred queue
drain or the after-first-frame root hook, where the eval stack is empty and
the guarded pop already synthesized undefined (typeof included).

What this locks: a param'd type-1 root onLoad handler fires exactly once,
sees undefined params (value AND typeof rows — typeof discriminates a
stolen operand "string" from a padded/synthesized "undefined"), and `this`
resolves to _level0 through the this-stack push.

The handler reaches the dispatcher via the global var-map fallback
(getVariable("onLoad")) — the root-MC compatibility path. DefineFunction is
emitted by hand because MTASC emits DefineFunction2 for SWF6+ and the
type-1 arm cannot be reached any other way.
"""
import struct

def push_string(s):
    item = b'\x00' + s.encode('utf-8') + b'\x00'
    return struct.pack('<BH', 0x96, len(item)) + item

GET_VARIABLE = bytes([0x1C])
TRACE = bytes([0x26])
ADD2 = bytes([0x47]); TYPE_OF = bytes([0x44]); END = bytes([0x00])

def define_function(name, params, body):
    p = name.encode() + b'\x00' + struct.pack('<H', len(params))
    for x in params:
        p += x.encode() + b'\x00'
    p += struct.pack('<H', len(body))
    return struct.pack('<BH', 0x9B, len(p)) + p + body

def gv(name):
    return push_string(name) + GET_VARIABLE

def tc(prefix, var):
    return push_string(prefix) + gv(var) + ADD2 + TRACE

def tt(prefix, var):
    return push_string(prefix) + gv(var) + TYPE_OF + ADD2 + TRACE

actions = b''

# function onLoad(a, b) { value+typeof rows for both params, then this }
actions += define_function('onLoad', ['a', 'b'],
                           tc('l:a=', 'a') + tt('l:ta=', 'a')
                           + tc('l:b=', 'b') + tt('l:tb=', 'b')
                           + tc('l:this=', 'this'))

actions += push_string('setup') + TRACE
actions += END

last = push_string('done') + TRACE + END

tags = b''
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(actions)) + actions
tags += struct.pack('<H', 1 << 6)      # ShowFrame 1 (root onLoad fires after this)
tags += struct.pack('<HI', (12 << 6) | 0x3F, len(last)) + last
tags += struct.pack('<H', 1 << 6)      # ShowFrame 2
tags += bytes([0, 0])

body = (bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
        + struct.pack('<H', 24 << 8) + struct.pack('<H', 2) + tags)
open('test.swf', 'wb').write(b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body)
print('ok')
