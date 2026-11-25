#!/usr/bin/env python3
"""avm1_onunload_setvar_scope: a function defined in _root's frame script and
installed as a timeline clip's onUnload does an UNQUALIFIED `n = n + 1`.
SetVariable must resolve `n` through the function's captured scope chain
(_root, where `n` already exists), so _root.n counts the unloads. Also the
same handler called as an ordinary method and as onEnterFrame, for contrast.
s28 w1-leads side lead (seen while building avm1_remove_unload_finalize_overflow:
_root.unloads stayed 0).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
defs = sprite(1, [doaction(STOP)])
inc = deffunc1('', [], push('n') + get('n') + push(1) + ADD2 + SETVAR
               + T('  in handler: n=', get('n'), ' this=', get('this'), ' this.n=', get('this.n')))
f1 = (place(1, 1, 'a') + place(2, 1, 'b')
      + doaction(push('n', 0) + SETVAR
                 + get('a') + push('onUnload') + inc + SETMEM
                 + get('b') + push('bump') + inc + SETMEM
                 + callm('b', 'bump')
                 + T('frame 1 after method call: _root.n=', get('_root.n'), ' b.n=', get('b.n'))))
f2 = tag(28, struct.pack('<H', 1)) + doaction(T('frame 2 after remove: _root.n=', get('_root.n')))
f3 = doaction(T('frame 3: _root.n=', get('_root.n')) + STOP)
open(sys.argv[1], 'wb').write(swf(8, defs, [f1, f2, f3]))
