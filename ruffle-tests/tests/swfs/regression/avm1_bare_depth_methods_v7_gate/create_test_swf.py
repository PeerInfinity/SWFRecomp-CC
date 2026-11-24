#!/usr/bin/env python3
"""avm1_bare_depth_methods_v7_gate: getNextHighestDepth / getInstanceAtDepth are
VERSION_7 MovieClip methods (Ruffle movie_clip.rs; flash_flags 0x0400), so in a
SWF6 movie a BARE call (CallFunction, resolved through the scope chain to the
timeline clip) must be undefined, as the CallMethod form already is. SWF7 twin:
`create_test_swf.py out.swf 7`.

s27 w2-avm1-leftovers-land lead 3 (w1 census). Each row: `<label>: <typeof> <value>`.
GOLDEN = Flash Player 32 direct mode, byte-identical (both versions; s27
w2-local-oracles/w2-avm1-leftovers-land). Landed by s27 w2b-avm1-text-edit.
Usage: create_test_swf.py <out.swf> [version]
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
VER = int(sys.argv[2]) if len(sys.argv) > 2 else 6


def row(label, code):
    return push('_v') + code + SETVAR + T(label + ': ', get('_v') + TYPEOF, ' ', get('_v'))


f1 = (
    callm('this', 'createEmptyMovieClip', 'c1', 5)
    + row('typeof gv getNextHighestDepth', get('getNextHighestDepth'))
    + row('cf getNextHighestDepth', push(0, 'getNextHighestDepth') + CALLF)
    + row('cm _root.getNextHighestDepth', push(0) + get('_root') + push('getNextHighestDepth') + CALLM)
    + row('cf getInstanceAtDepth(5)', push(5, 1, 'getInstanceAtDepth') + CALLF)
    + row('cm _root.getInstanceAtDepth(5)', push(5, 1) + get('_root') + push('getInstanceAtDepth') + CALLM)
    + row('cf getDepth', push(0, 'getDepth') + CALLF)
    + STOP
)
open(sys.argv[1], 'wb').write(swf(VER, b'', [doaction(f1)]))
