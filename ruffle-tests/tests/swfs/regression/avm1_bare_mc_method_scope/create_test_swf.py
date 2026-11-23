#!/usr/bin/env python3
"""avm1_bare_mc_method_scope: a bare MovieClip-method call (ActionCallFunction)
resolves its receiver through the scope chain: the innermost `with` clip, else
the current target (a child clip's own frame script, a tellTarget block, or the
defining timeline of a function), never a hard-coded _root.

s26 w1-avm1-dispatch-scope item 1. Ruffle: ActionCallFunction ->
activation.get_variable(name) -> CallableValue::Callable(scope_object, fn), so
`this` is the with-clip / target clip that answered the name
(core/src/avm1/activation.rs action_call_function; scope.rs resolve).

Frames:
  sprite `c` (placed at depth 1, x=100) frame 1: bare createTextField,
     createEmptyMovieClip, attachMovie, getNextHighestDepth,
     getInstanceAtDepth, getDepth, localToGlobal, swapDepths-free.
  root f2: with(w) { same calls }   (w = _root.createEmptyMovieClip("w", 20), w._x = 10)
  root f3: tellTarget("c") { createTextField("t4", 30, ...) }
           function defined on c's timeline, called from root: c.f()
  root f4: stop

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat

# ---- sprite c frame 1 (target = c) ----
c_f1 = (
    callf('createTextField', 't1', 5, 0, 0, 50, 20)
    + T('c ctf: c.t1=', typeof_('this.t1'), ' root.t1=', typeof_('_root.t1'))
    + callf('createEmptyMovieClip', 'e1', 6)
    + T('c cemc: c.e1=', typeof_('this.e1'), ' root.e1=', typeof_('_root.e1'))
    + callf('attachMovie', 'lib', 'a1', 8)
    + T('c am: c.a1=', typeof_('this.a1'), ' root.a1=', typeof_('_root.a1'))
    + T('c gnhd=', callf('getNextHighestDepth', keep=True))
    + T('c giad6=', callf('getInstanceAtDepth', 6, keep=True))
    + T('c gd=', callf('getDepth', keep=True))
    + push('p', 'x', 1, 'y', 2, 2) + INITOBJ + DEFLOCAL
    + push('p') + GETVAR + push(1, 'localToGlobal') + CALLF + POP
    + T('c l2g p.x=', get('p.x'))
    # function f() { createTextField("t5", 31, 0, 0, 5, 5); } on c's timeline
    + push('f') + deffunc2('', [], callf('createTextField', 't5', 31, 0, 0, 5, 5)) + SETVAR
)

# ---- root ----
r_f1 = b''
r_f2 = (
    callm('_root', 'createEmptyMovieClip', 'w', 20)
    + push('w') + GETVAR + push('_x', 10) + SETMEM
    + get('w') + with_block(
        callf('createTextField', 't2', 1, 0, 0, 10, 10)
        + callf('createEmptyMovieClip', 'e2', 2)
        + callf('attachMovie', 'lib', 'a2', 3)
        + T('w gnhd=', callf('getNextHighestDepth', keep=True))
        + T('w giad2=', callf('getInstanceAtDepth', 2, keep=True))
        + T('w gd=', callf('getDepth', keep=True))
        + push('q', 'x', 1, 'y', 2, 2) + INITOBJ + DEFLOCAL
        + push('q') + GETVAR + push(1, 'localToGlobal') + CALLF + POP
        + callf('swapDepths', 40)
    )
    + T('w swap gd=', callm('w', 'getDepth', keep=True))
    + T('w ctf: w.t2=', typeof_('w.t2'), ' root.t2=', typeof_('_root.t2'))
    + T('w cemc: w.e2=', typeof_('w.e2'), ' root.e2=', typeof_('_root.e2'))
    + T('w am: w.a2=', typeof_('w.a2'), ' root.a2=', typeof_('_root.a2'))
    + T('w l2g q.x=', get('q.x'))
    + T('root gnhd=', callf('getNextHighestDepth', keep=True))
)
r_f3 = (
    settarget('c')
    + callf('createTextField', 't4', 30, 0, 0, 10, 10)
    + settarget('')
    + T('tt ctf: c.t4=', typeof_('c.t4'), ' root.t4=', typeof_('_root.t4'))
    + callm('c', 'f')
    + T('fn ctf: c.t5=', typeof_('c.t5'), ' root.t5=', typeof_('_root.t5'))
)
r_f4 = T('done') + STOP

lib = sprite(3, [b''])
c = sprite(2, [doaction(c_f1)])
defs = lib + export(3, 'lib') + c
root = [place(1, 2, 'c', x=100) + doaction(r_f1), doaction(r_f2), doaction(r_f3), doaction(r_f4)]
open(sys.argv[1], 'wb').write(swf(8, defs, root))
