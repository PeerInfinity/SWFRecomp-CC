#!/usr/bin/env python3
"""avm1_resolve_dotted_getvariable: GetVariable / SetVariable of a dotted
path string ("o.b.c") calls __resolve for a MISSING INTERMEDIATE segment,
but not for the final one.

s27 w1-avm1-leftovers item 3. Ruffle activation.rs get_variable: the path
before the right-most '.'/':' goes through resolve_target_path, which reads
each segment with object.get(name) (get_opt(.., call_resolve_fn = true)), so
a miss calls __resolve; the final name is checked with has_property (no
__resolve) and an absent one falls through the scope chain to undefined.
set_variable resolves the target the same way. Clips too (child_by_name
first, then object.get -> MovieClip __resolve).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat


def gv(path):
    return push(path) + GETVAR


# __resolve(n): trace, then return {c: "C_" + n, d: {e: "E_" + n}} for n != "prim", else "P"
res_body = (
    T('  resolve ', push('n') + GETVAR)
    + push('n') + GETVAR + push('prim') + op(0x49)       # Equals2
    + op(0x12)                                           # Not
    + op(0x9d, (len(push('P') + RETURN)).to_bytes(2, 'little', signed=True))  # If !(n==prim) skip
    + push('P') + RETURN
    + push('c', 'C_') + push('n') + GETVAR + ADD2
    + push('d', 'e', 'E_') + push('n') + GETVAR + ADD2 + push(1) + INITOBJ
    + push(2) + INITOBJ + RETURN
)
resolver = deffunc1('', ['n'], res_body)

f1 = (
    push('o', 0) + INITOBJ + SETVAR
    + get('o') + push('__resolve') + resolver + SETMEM
    + get('o') + push('real', 'R') + SETMEM
    + T('o.b.c = ', gv('o.b.c'))
    + T('o.b.d.e = ', gv('o.b.d.e'))
    + T('o:b.c = ', gv('o:b.c'))
    + T('o.zz = ', gv('o.zz'))
    + T('o.real = ', gv('o.real'))
    + T('o.prim.c = ', gv('o.prim.c'))
    + push('o.w.c', 'set') + SETVAR
    + T('after set o.w.c: o.w = ', get('o.w') + TYPEOF)
    # a clip with __resolve
    + callm('this', 'createEmptyMovieClip', 'm', 1)
    + get('m') + push('__resolve') + resolver + SETMEM
    + T('m.q.c = ', gv('m.q.c'))
    + T('m.zz = ', gv('m.zz'))
    + T('_root.m.q.c = ', gv('_root.m.q.c'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(6, b'', [doaction(f1)]))
