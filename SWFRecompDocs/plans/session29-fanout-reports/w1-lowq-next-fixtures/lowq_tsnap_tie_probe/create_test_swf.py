#!/usr/bin/env python3
"""s29 w1-lowq-next: Flash LOW probe for the translation snap (TSNAP), the .5-tie
sources and the LOW stroke width on diagonals. AVM1, SWF 8, 320x240, white.

The SWF sets `_quality = "LOW"` itself (frame-1 DoAction), so a direct pinned
capture is LOW whatever the stub does. Each cell is 40x40 px. cells.json lists
every cell with the pixel each competing model predicts.

Rows (y = 40 * row):
 0  x TSNAP: green rect, local x 5.25..25.25, y 5..25, placed at x + fx
 1  y TSNAP: blue rect, local y 5.25..25.25, x 5..25, placed at y + fy
 2  slanted TSNAP: red triangle (5,2)-(35,20)-(5,38) placed at x + fx
 3  nesting: sprite at (pf, pf) holding the row-0 rect placed at (cf, cf)
 4  static 45-degree stroke X, widths 1 2 3 4 5 6 8 10 px, integer placement
 5  c0/c1 3-px stroke + fill rect (drawing_order's shape) at +.5 / +0;
    c2 c3 c4 4-px stroke square under acid-stroke-0's three matrices;
    c5 AVM1 Drawing-API lineStyle(5) 45-degree line; c6 Drawing-API filled rect
    at 5.5..25.5 (vertex .5 tie); c7 the same rect as a static shape.
fx / fy / pf,cf per column: see FRACS / NEST below.
"""
import json, math, pathlib, struct, sys

HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parents[4]
REG = REPO / 'ruffle-tests' / 'tests' / 'swfs' / 'regression'
sys.path.insert(0, str(REG / '_lib'))
sys.path.insert(0, str(REG / 'lowq_sample_point_probe'))
from avm1asm import tag, show_frame, end_tag, do_action, push, SET_VARIABLE, GET_VARIABLE, SET_MEMBER, CALL_METHOD, POP, Bits  # noqa
from create_test_swf import (matrix, rect, tw, Path, solid, define_shape3, line3, rect_path)  # noqa

FRACS = [0.0, 0.25, 0.35, 0.45, 0.5, 0.55, 0.65, 0.75]
NEST = [(0.35, 0.35), (0.25, 0.25), (0.5, 0.0), (0.0, 0.5), (0.5, 0.5), (0.75, 0.75), (0.35, -0.35), (0.65, 0.0)]
WIDTHS = [1, 2, 3, 4, 5, 6, 8, 10]
MATS = {'para41': (2.0, 0.0, -1.4142, 1.4142), 'para51': (2.0, 0.0, 1.4142, 1.4142),
        'rot81': (0.7071, 0.7071, -1.4142, 1.4142)}


def place(depth, cid, a=1.0, b=0.0, c=0.0, d=1.0, tx=0.0, ty=0.0, name=None):
    f1 = 0x02 | 0x04 | (0x20 if name else 0)
    body = struct.pack('<BHH', f1, depth, cid) + matrix(a, b, c, d, tw(tx), tw(ty))
    if name:
        body += name.encode() + b'\x00'
    return tag(26, body)


def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + tags + show_frame() + end_tag())


def snap(t):  # TSNAP: round half down
    return math.ceil(t - 0.5)


def first_px(e):  # pixel-centre rule, .5 tie included: first pixel whose centre >= e
    return math.ceil(e - 0.5)


def build():
    defs, places, cells = b'', b'', []
    ids = [0]
    dep = [0]

    def new_id():
        ids[0] += 1
        return ids[0]

    def put(cid, **m):
        nonlocal places
        dep[0] += 1
        places += place(dep[0], cid, **m)

    # shared shapes
    rx = new_id(); p = Path(); rect_path(p, 5.25, 5, 20, 20, fill0=1)
    defs += define_shape3(rx, p, [solid(0x008000)])
    ry = new_id(); p = Path(); rect_path(p, 5, 5.25, 20, 20, fill0=1)
    defs += define_shape3(ry, p, [solid(0x0000FF)])
    tri = new_id(); p = Path(); p.move(5, 2, fill0=1); p.line(35, 20); p.line(5, 38); p.line(5, 2)
    defs += define_shape3(tri, p, [solid(0xFF0000)])
    for col, f in enumerate(FRACS):
        put(rx, tx=40 * col + f, ty=0)
        cells.append(dict(row=0, col=col, what='x TSNAP rect', fx=f,
                          left_px_centre_rule=first_px(40 * col + f + 5.25),
                          left_px_tsnap=first_px(40 * col + snap(40 * col + f) - 40 * col + 5.25)))
        put(ry, tx=40 * col, ty=40 + f)
        cells.append(dict(row=1, col=col, what='y TSNAP rect', fy=f,
                          top_px_centre_rule=first_px(40 + f + 5.25), top_px_tsnap=first_px(snap(40 + f) + 5.25)))
        put(tri, tx=40 * col + f, ty=80)
        cells.append(dict(row=2, col=col, what='slanted TSNAP triangle', fx=f))
    # row 3: nesting
    for col, (pf, cf) in enumerate(NEST):
        sp = new_id()
        defs += sprite(sp, place(1, rx, tx=cf, ty=cf))
        put(sp, tx=40 * col + pf, ty=120 + pf)
        X = 40 * col + pf + cf
        cells.append(dict(row=3, col=col, what='nested TSNAP', pf=pf, cf=cf,
                          left_px_centre_rule=first_px(X + 5.25),
                          left_px_snap_world=first_px(snap(X) + 5.25),
                          left_px_snap_per_level=first_px(snap(40 * col + pf) + snap(cf) + 5.25)))
    # row 4: static 45-degree X strokes
    for col, w in enumerate(WIDTHS):
        sid = new_id(); p = Path()
        p.move(6, 6, line=1); p.line(34, 34); p.move(34, 6, line=1); p.line(6, 34)
        defs += define_shape3(sid, p, [], [line3(w, 0x000000)], margin=w)
        put(sid, tx=40 * col, ty=160)
        cells.append(dict(row=4, col=col, what='static 45deg X stroke', width=w,
                          row_span_perpendicular=round(w * math.sqrt(2), 3), row_span_minor_axis=w))
    # row 5
    for col, off in ((0, 0.5), (1, 0.0)):
        sid = new_id(); p = Path(); rect_path(p, 6, 6, 28, 28, fill0=1, line=1)
        defs += define_shape3(sid, p, [solid(0xFF0000)], [line3(3, 0x000000)], margin=2)
        put(sid, tx=40 * col + off, ty=200 + off)
        cells.append(dict(row=5, col=col, what='3px stroke + fill rect (drawing_order shape)', place_frac=off))
    for col, key in ((2, 'para41'), (3, 'para51'), (4, 'rot81')):
        a, b, c, d = MATS[key]
        sid = new_id(); p = Path(); rect_path(p, 0, 0, 8, 8, line=1)
        defs += define_shape3(sid, p, [], [line3(4, 0x000000)], margin=2)
        xs = [a * u + c * v for u, v in ((0, 0), (8, 0), (0, 8), (8, 8))]
        put(sid, a=a, b=b, c=c, d=d, tx=40 * col + 20 - (min(xs) + max(xs)) / 2, ty=200 + 6)
        cells.append(dict(row=5, col=col, what='4px stroke square under acid-stroke-0 matrix ' + key, matrix=[a, b, c, d]))
    sid = new_id(); p = Path(); rect_path(p, 5.5, 5.5, 20, 20, fill0=1)
    defs += define_shape3(sid, p, [solid(0x008000)])
    put(sid, tx=280, ty=200)
    cells.append(dict(row=5, col=7, what='static rect 5.5..25.5 (vertex .5 tie)'))
    cells.append(dict(row=5, col=5, what='AVM1 Drawing API lineStyle(5) 45deg line (4,4)-(36,36)'))
    cells.append(dict(row=5, col=6, what='AVM1 Drawing API filled rect 5.5..25.5 (vertex .5 tie)'))

    # frame-1 actions: _quality = "LOW"; Drawing-API cells
    def mc(name):
        return push(name) + GET_VARIABLE

    def call(name, method, *args):
        code = b''
        for v in reversed(args):
            code += push(v)
        return code + push(len(args)) + mc(name) + push(method) + CALL_METHOD + POP

    def setm(name, prop, v):
        return mc(name) + push(prop) + push(v) + SET_MEMBER

    act = push('_quality', 'LOW') + SET_VARIABLE
    act += push(1000, 'd1', 2) + push('this') + GET_VARIABLE + push('createEmptyMovieClip') + CALL_METHOD + POP
    act += setm('d1', '_x', 200) + setm('d1', '_y', 200)
    act += call('d1', 'lineStyle', 5, 0x0000FF, 100) + call('d1', 'moveTo', 4, 4) + call('d1', 'lineTo', 36, 36)
    act += push(1001, 'd2', 2) + push('this') + GET_VARIABLE + push('createEmptyMovieClip') + CALL_METHOD + POP
    act += setm('d2', '_x', 240) + setm('d2', '_y', 200)
    act += call('d2', 'beginFill', 0x008000, 100) + call('d2', 'moveTo', 5.5, 5.5) + call('d2', 'lineTo', 25.5, 5.5)
    act += call('d2', 'lineTo', 25.5, 25.5) + call('d2', 'lineTo', 5.5, 25.5) + call('d2', 'lineTo', 5.5, 5.5)
    act += call('d2', 'endFill')

    W, H = 320 * 20, 240 * 20
    nb = max(W.bit_length(), H.bit_length()) + 1
    hdr = Bits().u(nb, 5).s(0, nb).s(W, nb).s(0, nb).s(H, nb).bytes()
    tags = tag(9, bytes([255, 255, 255])) + defs + places + do_action(act) + show_frame() + end_tag()
    body = hdr + struct.pack('<H', 30 << 8) + struct.pack('<H', 1) + tags
    out = HERE / 'test.swf'
    out.write_bytes(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
    (HERE / 'cells.json').write_text(json.dumps(cells, indent=1) + '\n')
    print('wrote', out, 8 + len(body), 'bytes,', len(cells), 'cells')


if __name__ == '__main__':
    build()
