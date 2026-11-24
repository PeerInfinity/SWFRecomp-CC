#!/usr/bin/env python3
"""avm1_edittext_path_variable_same_frame: (LEAD fixture, fails after the s27
prototype) the same bindings as avm1_edittext_path_variable_scope, but `mc`
and the fields are placed on the SAME frame of `s`. On master + prototype the
bind-time GetVariable "mc" (context s) does not find s's just-created child
and materializes a second `mc` under _root, so the bindings land on a ghost.

Original description: DefineEditText `variable` paths on a
field inside a sprite (no button) resolve from the field's PARENT, and the
right-most ':' or '.' splits target from variable name.

s27 w1-avm1-leftovers item 2. Ruffle edit_text.rs try_bind_text_field_variable
runs resolve_variable_path(parent, path) in a child frame for the parent
(climbed past buttons); resolve_variable_path splits at path.rfind(":."), and
an unresolved field is retried by bind_variables (set_initial_value = false)
when a later frame runs, again from the parent.
Sprite `s` (root depth 1) holds empty sprite `mc` (depth 1) and fields:
  t1 "mc:foo"         = "F"  -> s.mc.foo = "F"
  t2 "_root.s.mc:bar" = "B"  -> s.mc.bar = "B"
  t3 "mc.baz"         = "Z"  -> s.mc.baz = "Z"   (relative to s, not _root)
  t4 "_parent.pv"     = "P"  -> _root.pv = "P"
  t5 "late.q"         = "L"  -> unbound until frame 2 creates s.late; the
                                retry does not copy; s.late.q = "X" (frame 3)
                                then sets t5.text.
With no existing variable, the field's non-empty text seeds the variable.

Golden: Flash Player 32 DIRECT-mode trace (s27 coordinator). Flash binds the
same-frame fields to the real `s.mc` (and `_root.s.mc:bar`); before s27 w2 the
bind-time GetVariable "mc" materialized a ghost clip (tfVarWalkClipPath fix).
`s.t5.text=L`: like the _scope twin, Flash never late-binds t5.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat


def edit_text(cid, var, text):
    # HasText | ReadOnly; no font (device default), no layout.
    return tag(37, struct.pack('<H', cid) + rect(0, 2000, 0, 400) + bytes([0x80 | 0x08, 0x00])
               + s(var) + s(text))


fields = [('t1', 'mc:foo', 'F'), ('t2', '_root.s.mc:bar', 'B'), ('t3', 'mc.baz', 'Z'),
          ('t4', '_parent.pv', 'P'), ('t5', 'late.q', 'L')]
defs = sprite(2, [b''])
for i, (_, var, txt) in enumerate(fields):
    defs += edit_text(10 + i, var, txt)
s_f1 = place(1, 2, 'mc') + b''.join(place(2 + i, 10 + i, nm, 0, 20 * i) for i, (nm, _, _) in enumerate(fields))
defs += sprite(3, [s_f1])

f1 = place(1, 3, 's')
f2 = doaction(
    T('s.mc.foo=', get('s.mc.foo')) + T('s.mc:foo=', push('s.mc:foo') + GETVAR)
    + T('s[mc:foo]=', get('s') + push('mc:foo') + GETMEM)
    + T('s.mc.bar=', get('s.mc.bar'))
    + T('s.mc.baz=', get('s.mc.baz')) + T('_root.mc=', get('_root.mc') + TYPEOF)
    + T('_root.pv=', get('_root.pv')) + T('s.pv=', get('s.pv'))
    + T('same mc=', get('s.mc') + get('s.t1') + push('_parent') + GETMEM + push('mc') + GETMEM + op(0x49))
    + callm('s', 'createEmptyMovieClip', 'late', 10)
)
f3 = doaction(T('s.late.q=', get('s.late.q') + TYPEOF)
              + get('s.late') + push('q', 'X') + SETMEM)
f4 = doaction(T('s.t5.text=', get('s.t5.text')) + STOP)
open(sys.argv[1], 'wb').write(swf(8, defs, [f1, f2, f3, f4]))
