#!/usr/bin/env python3
"""avm1_mc_resolve: `__resolve` set on a MovieClip is called for a missing
member read (GetMember), with `this` = the clip; a present member, a child
clip and a built-in property do not call it.

s26 w1-avm1-dispatch-scope (found while auditing item 2). Ruffle
core/src/avm1/object.rs Object::get -> get_opt(.., call_resolve_fn = true)
-> find_resolve_method / resolve.call("__resolve", this, [name]); a
MovieClip is an ordinary Object for this path (StageObject).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
R1, R2 = Reg(1), Reg(2)
res = deffunc2('', ['n'], T('resolve(', push(R2), ') this=', push(R1) + push('_name') + GETMEM)
               + push('R_') + push(R2) + ADD2 + RETURN, nregs=4, flags=PRELOAD_THIS, first_param_reg=2)
f1 = (
    callm('_root', 'createEmptyMovieClip', 'mc', 1)
    + callm('mc', 'createEmptyMovieClip', 'kid', 1)
    + get('mc') + push('v', 7) + SETMEM
    + get('mc') + push('__resolve') + res + SETMEM
    + T('missing: ', get('mc.zzz'))
    + T('present: ', get('mc.v'))
    + T('child: ', get('mc.kid._name'))
    + T('builtin: ', get('mc._name'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
