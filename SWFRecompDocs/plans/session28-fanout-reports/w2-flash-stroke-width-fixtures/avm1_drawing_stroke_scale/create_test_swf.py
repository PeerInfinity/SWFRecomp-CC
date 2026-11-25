#!/usr/bin/env python3
"""avm1_drawing_stroke_scale: Flash's device-space ISOTROPIC stroke width on
AVM1 Drawing-API strokes, under non-similar clip matrices, for every
lineStyle scale mode (s28 w2-flash-stroke-width).

Timeline (DefineShape4) strokes were measured against Flash 32 on
acid-stroke-0: Flash strokes in DEVICE space with one scalar width from
v = M*(1,1): normal -> |v|/sqrt2, "horizontal" (NoVScale) -> |v.x|,
"vertical" (NoHScale) -> |v.y|, "none" -> 1, then max(.., 1 device px), and
round joins/caps are device circles. This fixture asks whether the Drawing
API follows the same model (no Flash capture of a non-uniformly scaled
Drawing-API stroke exists in the corpus).

Grid: 4 rows = lineStyle(4, 0, 100, false, MODE) for MODE in
  normal / none / vertical / horizontal
6 columns = the clip matrix:
  c0 identity            c1 _xscale 200          c2 _yscale 200
  c3 _rotation 45, _yscale 200   (acid-stroke-0's R(45)diag(1,2) cell: the
                                 NoVScale anomaly, Flash drew a hairline)
  c4 parent _xscale 200, child _rotation 45   M=[[1.41 -1.41],[.71 .71]]
  c5 parent _xscale 200, child _rotation -45  M=[[1.41 1.41],[-.71 .71]]
Columns 0-5 draw a closed 24 px square (round joins, Flash's default);
row 4 (extra) draws an OPEN 'V' polyline (round caps + one sharp round
join) under each column's matrix, lineStyle(6) normal.

Regenerate:  python3 create_test_swf.py
Golden:      FLASH request (s28 w2-flash-stroke-width report): run_image.py,
             frame 1, quality high (draw() wrapper).
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
LIB = HERE.parents[4] / 'ruffle-tests' / 'tests' / 'swfs' / 'regression' / '_lib'
sys.path.insert(0, str(LIB))
from avm1asm import (do_action, swf_file, push, call_method, get_var,  # noqa: E402
                     get_path, set_member, STOP)

MODES = ['normal', 'none', 'vertical', 'horizontal']
# (parent_xscale, child_xscale, child_yscale, child_rotation)
COLS = [(100, 100, 100, 0), (100, 200, 100, 0), (100, 100, 200, 0),
        (100, 100, 200, 45), (200, 100, 100, 45), (200, 100, 100, -45)]
CW, RH, X0, Y0 = 78, 70, 30, 30


def clip(code_parent, name, depth):
    return call_method(code_parent, 'createEmptyMovieClip', name, depth)


def draw_square(ref, s=24):
    c = b''
    c += call_method(ref, 'moveTo', -s // 2, -s // 2)
    for x, y in [(s // 2, -s // 2), (s // 2, s // 2), (-s // 2, s // 2), (-s // 2, -s // 2)]:
        c += call_method(ref, 'lineTo', x, y)
    return c


def draw_v(ref):
    c = call_method(ref, 'moveTo', -12, -10)
    c += call_method(ref, 'lineTo', 0, 10)
    c += call_method(ref, 'lineTo', 12, -10)
    return c


body = b''
depth = 1
for row in range(5):
    for col, (pxs, cxs, cys, rot) in enumerate(COLS):
        pn = 'p%d_%d' % (row, col)
        body += clip(get_var('_root'), pn, depth); depth += 1
        body += set_member(get_var(pn), '_x', X0 + col * CW)
        body += set_member(get_var(pn), '_y', Y0 + row * RH)
        body += set_member(get_var(pn), '_xscale', pxs)
        body += clip(get_var(pn), 'k', 1)
        k = get_path(pn, 'k')
        body += set_member(k, '_xscale', cxs)
        body += set_member(k, '_yscale', cys)
        body += set_member(k, '_rotation', rot)
        if row < 4:
            body += call_method(k, 'lineStyle', 4, 0, 100, False, MODES[row])
            body += draw_square(k)
        else:
            body += call_method(k, 'lineStyle', 6, 0, 100)
            body += draw_v(k)
body += STOP
swf_file(HERE / 'test.swf', [do_action(body)], version=8, w=480, h=360)
