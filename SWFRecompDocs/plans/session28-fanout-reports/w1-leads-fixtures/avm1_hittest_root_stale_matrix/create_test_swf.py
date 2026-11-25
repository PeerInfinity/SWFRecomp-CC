#!/usr/bin/env python3
"""avm1_hittest_root_stale_matrix: which coordinate model does Flash's
MovieClip.hitTest(x, y, shapeFlag) use right after _root's own transform
changes in the SAME frame (before any render)?

s28 w1-leads item 1. avm1/movieclip_hittest_shapeflag's block "donut, root
transformed" sets _root._x = 400, _root._xscale = 50 and hit-tests at once;
pinned FP32 prints false on 3 of the 4 ring points where Ruffle's golden says
true. Three candidate models, each with a distinct truth table at phase B:
  ruffle (point is root-local, mapped through _root's NEW matrix; clip's
          world matrix fresh):          150:true  250:false 50:false
  stale  (point mapped through _root's NEW matrix, clip's world matrix still
          the pre-change one):          150:false 250:false 50:true
  stage  (point is stage-global):       150:false 250:true  50:false
Clip c = 100x100 red square drawn at (0,0), placed at (100,100) in _root.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat


def setp(path, prop, val):
    return get(path) + push(prop, val) + SETMEM


def ht(x, y, shape):
    return callm('c', 'hitTest', x, y, shape, keep=True)


def phase(p):
    code = b''
    for x in (150, 250, 50):
        code += T(p + ' hit(' + str(x) + ',150) shape=', ht(x, 150, True), ' bounds=', ht(x, 150, False))
    # localToGlobal of c's origin (does it see the same matrix?)
    code += push('o', 0, 'Object') + NEWOBJ + DEFLOCAL
    code += setp('o', 'x', 0) + setp('o', 'y', 0)
    code += push('o') + GETVAR + push(1) + get('c') + push('localToGlobal') + CALLM + POP
    code += T(p + ' c.localToGlobal(0,0)=', get('o.x'), ',', get('o.y'))
    return code


f1 = (
    callm('this', 'createEmptyMovieClip', 'c', 1)
    + callm('c', 'beginFill', 0xFF0000, 100)
    + callm('c', 'moveTo', 0, 0)
    + callm('c', 'lineTo', 100, 0)
    + callm('c', 'lineTo', 100, 100)
    + callm('c', 'lineTo', 0, 100)
    + callm('c', 'lineTo', 0, 0)
    + callm('c', 'endFill')
    + setp('c', '_x', 100) + setp('c', '_y', 100)
    + phase('A identity:')
    + setp('_root', '_x', 100)
    + phase('B same-frame _root._x=100:')
)
f2 = (
    phase('C next-frame _root._x=100:')
    + setp('_root', '_x', 0)
    + phase('D same-frame _root._x=0:')
)
f3 = (
    phase('E next-frame identity:')
    + setp('c', '_x', 200)
    + phase('F same-frame c._x=200:')
    + setp('_root', '_xscale', 50)
    + phase('G same-frame _root._xscale=50:')
    + setp('_root', '_xscale', 100)
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f) for f in (f1, f2, f3)], w=640, h=520))
