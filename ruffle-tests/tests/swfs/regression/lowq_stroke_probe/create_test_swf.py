#!/usr/bin/env python3
"""s29 w2b-lowq-stroke: Flash LOW stroke-raster probe (LOCAL ORACLE REQUEST 1 of
w2-lowq-tsnap). AVM1, SWF 8, 640x560, white. The SWF sets `_quality = "LOW"`
itself (frame-1 DoAction), so a direct pinned capture is LOW whatever the stub.

Cells are 40x40 px (row r at y = 40 r, col c at x = 40 c) except row 11
(y = 440..560, 128-px cells). Every placement is on an EVEN integer unless the
cell says otherwise, so TSNAP (round half-even) is a no-op there. cells.json
lists every cell, its geometry and the pixel each candidate rule predicts.

 row 0   45-degree single line (6,6)->(34,34), w = 3 4 4.5 5 5.25 5.5 5.75 6;
         cols 8-15 the same line drawn in the reverse direction (34,34)->(6,6)
 row 1   30-degree line (cols 0-7) and 60-degree line (cols 8-15), same widths
 row 2   cols 0-7: w=5 at 0 / 26.565 / 45 deg, w=4 at 0 / 26.565, w=6 at
         0 / 26.565, w=4.5 at 0 deg; cols 8-15: AVM1 Drawing-API lineStyle at
         45 deg w = 3 4 4.5 5 5.5 6, and at 30 deg w = 5 6
 rows 3-5 stroke-only rect bands, rect (8+f, 8+f)-(32+f, 32+f), f = 0 .25 .5 .75:
         row 3 W=1 cw | W=1 ccw | W=2 cw | W=2 ccw   (4 fractions each)
         row 4 W=3 cw | W=3 ccw | W=4 cw | W=4 ccw
         row 5 W=5 cw | W=5 ccw | W=6 cw | W=6 ccw
 row 6   TSNAP ties: cols 0-7 a filled 20x20 rect placed at (40c + kx + .5,
         240 + ky + .5); cols 8-15 a sprite at (40c + kp + .5, 240 + kp + .5)
         holding the rect at (kc + .5, kc + .5)
 row 7   1-px noScale (noHScale + noVScale) 8x8 square under acid-stroke-0's
         para41 matrix (2, 0, -1.4142, 1.4142): cols 0-7 inside a sprite (the
         acid id-10 structure) at 8 translation fractions; cols 8-15 the shape
         placed directly
 row 8   the same under para51 (2, 0, +1.4142, 1.4142)
 row 9   filled 8x8 square inside a sprite, para41 (cols 0-7), para51 (8-15)
 row 10  cols 0-7: filled square rotated 30 deg, placed directly at x + f
         (f = 0 .25 .35 .45 .5 .55 .65 .75); cols 8-15: para41 sprite holding
         fill + 1-px noScale stroke square (one shape)
 row 11  acid-size: acid-stroke-0's shape 9 (32x32, 1-px noScale) in a sprite,
         5 cells: para41 (.05,.3), para51 (.75,.3), para41 (.55,.95),
         para51 (.55,.95), para41 (.25,.25)
"""
import json, math, pathlib, struct, sys

HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parents[4]
REG = REPO / 'ruffle-tests' / 'tests' / 'swfs' / 'regression'
sys.path.insert(0, str(REG / '_lib'))
sys.path.insert(0, str(REG / 'lowq_sample_point_probe'))
from avm1asm import tag, show_frame, end_tag, do_action, push, SET_VARIABLE, GET_VARIABLE, SET_MEMBER, CALL_METHOD, POP, Bits  # noqa
from create_test_swf import (matrix, rect, tw, Path, solid, define_shape3, line3, rect_path, rgba)  # noqa

W_STAGE, H_STAGE = 640, 560
WIDTHS = [3, 4, 4.5, 5, 5.25, 5.5, 5.75, 6]
RECT_FRACS = [0.0, 0.25, 0.5, 0.75]
FRACS8 = [(0.05, 0.3), (0.55, 0.95), (0.75, 0.3), (0.0, 0.0), (0.25, 0.25), (0.5, 0.5), (0.5, 0.0), (0.0, 0.5)]
ROT_FRACS = [0.0, 0.25, 0.35, 0.45, 0.5, 0.55, 0.65, 0.75]
TIE_K = [(0, 0), (1, 1), (2, 2), (3, 3), (0, 1), (1, 0), (2, 3), (3, 2)]
NEST_K = [(0, 0), (1, 0), (0, 1), (1, 1), (2, 1), (1, 2), (3, 3), (2, 2)]
MATS = {'para41': (2.0, 0.0, -1.4142, 1.4142), 'para51': (2.0, 0.0, 1.4142, 1.4142)}


def place(depth, cid, a=1.0, b=0.0, c=0.0, d=1.0, tx=0.0, ty=0.0):
    body = struct.pack('<BHH', 0x02 | 0x04, depth, cid) + matrix(a, b, c, d, tw(tx), tw(ty))
    return tag(26, body)


def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + tags + show_frame() + end_tag())


def line2(width_px, c, no_scale=False):
    """LINESTYLE2: round caps / round join, optional noHScale + noVScale."""
    f1 = 0x06 if no_scale else 0x00   # StartCap(2) Join(2) HasFill NoHScale NoVScale PixelHinting
    return struct.pack('<HBB', tw(width_px), f1, 0x00) + rgba(c)


def define_shape4(sid, path, fills, lines, margin=0):
    eb = rect(*path.bounds())
    body = struct.pack('<H', sid) + rect(*path.bounds(margin)) + eb
    flags = 0x01 if any(l[2] & 0x06 == 0 for l in lines) else 0
    flags |= 0x02 if any(l[2] & 0x06 for l in lines) else 0
    body += bytes([flags])
    body += bytes([len(fills)]) + b''.join(fills)
    body += bytes([len(lines)]) + b''.join(lines)
    body += path.records(len(fills), len(lines))
    return tag(83, body)


def rhe(x):  # round half to even on the twip grid
    q = round(x * 20) / 20
    return round(q)


def half_down(x):
    return math.ceil(round(x * 20) / 20 - 0.5)


def line_ends(theta_deg, cx=20.0, cy=20.0, half=14.0):
    t = math.radians(theta_deg)
    return (cx - half * math.cos(t), cy - half * math.sin(t), cx + half * math.cos(t), cy + half * math.sin(t))


def spans(w, theta_deg):
    t = math.radians(theta_deg)
    s, c = abs(math.sin(t)), abs(math.cos(t))
    out = {}
    # horizontal run per scanline (theta > 0) and vertical run per column (theta < 90)
    out['row_span_polygon'] = round(w / s, 3) if s > 1e-9 else None
    out['col_span_polygon'] = round(w / c, 3) if c > 1e-9 else None
    out['minor_axis_pen_span'] = w
    out['thin_clamp_span'] = min(w, 4) if w <= 5 else None
    return out


def band_predictions(c_lo, c_hi, W, cw):
    """Edges of a rect stroked cw (y-down: top -> right, right -> down, ...) or ccw.
    Each edge: centreline c, travel direction, and per rule the band [lo, hi).
    right_of_travel_w3: s29 w2-lowq-tsnap fit (W=3): p = rhe(c) for up / right
    travel, rhe(c) - 1 for down / left; pen = [p - 1, p + 2).
    right_of_travel_gen: band centre rhe(c) + r/2 (r = +1 when right-of-travel is
    +axis), W px wide, lo = ceil(centre - W/2) for odd W (exact for W = 3),
    lo = rhe(c) - W/2 + (r > 0) for even W (a guess).
    high_snap: HIGH stroke_snap_centre rule L = floor((E - 2W + 2) / 4)."""
    if cw:
        edges = [('top', c_lo, 'right'), ('right', c_hi, 'down'), ('bottom', c_hi, 'left'), ('left', c_lo, 'up')]
    else:
        edges = [('left', c_lo, 'down'), ('bottom', c_hi, 'right'), ('right', c_hi, 'up'), ('top', c_lo, 'left')]
    out = []
    for name, c, trav in edges:
        # right of travel in y-down: right -> +y, down -> -x, left -> -y, up -> +x
        r = {'right': +1, 'down': -1, 'left': -1, 'up': +1}[trav]
        p = rhe(c) if trav in ('up', 'right') else rhe(c) - 1
        e = {'edge': name, 'c': c, 'travel': trav, 'axis': 'y' if name in ('top', 'bottom') else 'x'}
        if W == 3:
            e['right_of_travel_w3'] = [p - 1, p + 2]
        cen = rhe(c) + 0.5 * r
        if W % 2:
            lo = math.ceil(cen - W / 2)
        else:
            lo = rhe(c) - W // 2 + (1 if r > 0 else 0)
        e['right_of_travel_gen'] = [lo, lo + W]
        E = math.floor(4 * c + 0.5)
        L = math.floor((E - 2 * W + 2) / 4)
        e['high_snap'] = [L, L + W]
        out.append(e)
    return out


def build():
    defs, places, cells, act_cells = b'', b'', [], []
    ids = [0]
    dep = [0]

    def new_id():
        ids[0] += 1
        return ids[0]

    def put(cid, **m):
        nonlocal places
        dep[0] += 1
        places += place(dep[0], cid, **m)

    def line_shape(x0, y0, x1, y1, w):
        sid = new_id(); p = Path()
        p.move(x0, y0, line=1); p.line(x1, y1)
        return sid, define_shape3(sid, p, [], [line3(w, 0x000000)], margin=w)

    # row 0: 45 deg, both directions
    for col, w in enumerate(WIDTHS):
        for half, rev in ((0, False), (1, True)):
            x0, y0, x1, y1 = (34, 34, 6, 6) if rev else (6, 6, 34, 34)
            sid, t = line_shape(x0, y0, x1, y1, w); defs += t
            c = col + 8 * half
            put(sid, tx=40 * c, ty=0)
            cells.append(dict(row=0, col=c, what='static 45deg line', width=w, theta=45, reverse=rev,
                              ends=[x0 + 40 * c, y0, x1 + 40 * c, y1], **spans(w, 45)))
    # row 1: 30 deg / 60 deg
    for col, w in enumerate(WIDTHS):
        for half, th in ((0, 30), (1, 60)):
            x0, y0, x1, y1 = line_ends(th)
            sid, t = line_shape(x0, y0, x1, y1, w); defs += t
            c = col + 8 * half
            put(sid, tx=40 * c, ty=40)
            cells.append(dict(row=1, col=c, what='static %ddeg line' % th, width=w, theta=th,
                              ends=[tw(x0) / 20 + 40 * c, tw(y0) / 20 + 40, tw(x1) / 20 + 40 * c, tw(y1) / 20 + 40],
                              **spans(w, th)))
    # row 2 cols 0-7: angle sweep
    sweep = [(5, 0), (5, 26.565), (5, 45), (4, 0), (4, 26.565), (6, 0), (6, 26.565), (4.5, 0)]
    for col, (w, th) in enumerate(sweep):
        x0, y0, x1, y1 = line_ends(th)
        sid, t = line_shape(x0, y0, x1, y1, w); defs += t
        put(sid, tx=40 * col, ty=80)
        cells.append(dict(row=2, col=col, what='static line angle sweep', width=w, theta=th,
                          ends=[tw(x0) / 20 + 40 * col, tw(y0) / 20 + 80, tw(x1) / 20 + 40 * col, tw(y1) / 20 + 80],
                          **spans(w, th)))
    # row 2 cols 8-15: Drawing API (actions below)
    dapi = [(3, 45), (4, 45), (4.5, 45), (5, 45), (5.5, 45), (6, 45), (5, 30), (6, 30)]
    for k, (w, th) in enumerate(dapi):
        col = 8 + k
        x0, y0, x1, y1 = line_ends(th)
        act_cells.append(('line', col, 80, w, (x0, y0, x1, y1)))
        cells.append(dict(row=2, col=col, what='AVM1 Drawing-API lineStyle line', width=w, theta=th,
                          ends=[x0 + 40 * col, y0 + 80, x1 + 40 * col, y1 + 80], **spans(w, th)))
    # rows 3-5: rect bands
    plan = [(3, [(1, True), (1, False), (2, True), (2, False)]),
            (4, [(3, True), (3, False), (4, True), (4, False)]),
            (5, [(5, True), (5, False), (6, True), (6, False)])]
    for row, groups in plan:
        for g, (W, cw) in enumerate(groups):
            for k, f in enumerate(RECT_FRACS):
                col = 4 * g + k
                sid = new_id(); p = Path()
                x0 = y0 = 8 + f
                x1 = y1 = 32 + f
                if cw:
                    rect_path(p, x0, y0, 24, 24, line=1)
                else:
                    p.move(x0, y0, line=1); p.line(x0, y1); p.line(x1, y1); p.line(x1, y0); p.line(x0, y0)
                defs += define_shape3(sid, p, [], [line3(W, 0x000000)], margin=W)
                put(sid, tx=40 * col, ty=40 * row)
                bx = band_predictions(40 * col + x0, 40 * col + x1, W, cw)
                by = band_predictions(40 * row + y0, 40 * row + y1, W, cw)
                edges = [e for e in bx if e['axis'] == 'x'] + [e for e in by if e['axis'] == 'y']
                cells.append(dict(row=row, col=col, what='stroke-only rect band', width=W,
                                  direction='cw' if cw else 'ccw', frac=f, edges=edges))
    # row 6: TSNAP ties (.5 on odd / even)
    rid = new_id(); p = Path(); rect_path(p, 5, 5, 20, 20, fill0=1)
    defs += define_shape3(rid, p, [solid(0x008000)])
    for col, (kx, ky) in enumerate(TIE_K):
        tx, ty = 40 * col + kx + 0.5, 240 + ky + 0.5
        put(rid, tx=tx, ty=ty)
        cells.append(dict(row=6, col=col, what='TSNAP .5 tie (fill rect 5..25 local)', tx=tx, ty=ty,
                          left_px_half_even=rhe(tx) + 5, top_px_half_even=rhe(ty) + 5,
                          left_px_half_down=half_down(tx) + 5, top_px_half_down=half_down(ty) + 5))
    for k, (kp, kc) in enumerate(NEST_K):
        col = 8 + k
        sp = new_id()
        defs += sprite(sp, place(1, rid, tx=kc + 0.5, ty=kc + 0.5))
        tx = 40 * col + kp + 0.5
        ty = 240 + kp + 0.5
        put(sp, tx=tx, ty=ty)
        cells.append(dict(row=6, col=col, what='nested TSNAP .5 ties', parent=[tx, ty], child=kc + 0.5,
                          left_px_per_level_half_even=rhe(tx) + rhe(kc + 0.5) + 5,
                          top_px_per_level_half_even=rhe(ty) + rhe(kc + 0.5) + 5,
                          left_px_per_level_half_down=half_down(tx) + half_down(kc + 0.5) + 5,
                          left_px_world_half_even=rhe(tx + kc + 0.5) + 5))

    # rows 7-10: sheared hairlines
    def sq_shape(n, stroke=None, fill=None, no_scale=True):
        sid = new_id(); p = Path()
        st = {}
        if fill is not None:
            st['fill0'] = 1
        if stroke is not None:
            st['line'] = 1
        rect_path(p, 0, 0, n, n, **st)
        fills = [solid(fill)] if fill is not None else []
        lines = [line2(stroke, 0x000000, no_scale)] if stroke is not None else []
        return sid, define_shape4(sid, p, fills, lines, margin=1)

    hair8, t = sq_shape(8, stroke=1.0); defs += t
    fill8, t = sq_shape(8, fill=0x0000FF); defs += t
    both8, t = sq_shape(8, stroke=1.0, fill=0x0000FF); defs += t
    sp_hair8 = new_id(); defs += sprite(sp_hair8, place(1, hair8))
    sp_fill8 = new_id(); defs += sprite(sp_fill8, place(1, fill8))
    sp_both8 = new_id(); defs += sprite(sp_both8, place(1, both8))

    def sheared(row, col, cid, key, fr, what, n=8, cw=40, ch=40, y0=None, x0=None):
        a, b, c, d = MATS[key]
        xs = [a * u + c * v for u, v in ((0, 0), (n, 0), (0, n), (n, n))]
        ys = [b * u + d * v for u, v in ((0, 0), (n, 0), (0, n), (n, n))]
        bx = (x0 if x0 is not None else 40 * col) + math.floor(cw / 2 - (min(xs) + max(xs)) / 2)
        by = (y0 if y0 is not None else 40 * row) + math.floor(ch / 2 - (min(ys) + max(ys)) / 2)
        bx -= bx % 2; by -= by % 2
        tx, ty = bx + fr[0], by + fr[1]
        put(cid, a=a, b=b, c=c, d=d, tx=tx, ty=ty)
        cells.append(dict(row=row, col=col, what=what, matrix=[a, b, c, d], tx=tx, ty=ty, frac=list(fr),
                          tsnap_half_even=[rhe(tx), rhe(ty)]))

    for k, fr in enumerate(FRACS8):
        sheared(7, k, sp_hair8, 'para41', fr, '1px noScale 8x8 square in sprite, para41')
        sheared(7, 8 + k, hair8, 'para41', fr, '1px noScale 8x8 square placed directly, para41')
        sheared(8, k, sp_hair8, 'para51', fr, '1px noScale 8x8 square in sprite, para51')
        sheared(8, 8 + k, hair8, 'para51', fr, '1px noScale 8x8 square placed directly, para51')
        sheared(9, k, sp_fill8, 'para41', fr, 'filled 8x8 square in sprite, para41')
        sheared(9, 8 + k, sp_fill8, 'para51', fr, 'filled 8x8 square in sprite, para51')
        sheared(10, 8 + k, sp_both8, 'para41', fr, 'fill + 1px noScale 8x8 square in sprite, para41')
    # row 10 cols 0-7: rotated fill, direct
    rot, t = sq_shape(16, fill=0xFF0000); defs += t
    ca, sa = math.cos(math.radians(30)), math.sin(math.radians(30))
    for k, f in enumerate(ROT_FRACS):
        tx, ty = 40 * k + 18 + f, 400 + 6
        put(rot, a=round(ca, 4), b=round(sa, 4), c=round(-sa, 4), d=round(ca, 4), tx=tx, ty=ty)
        cells.append(dict(row=10, col=k, what='filled 16x16 square rotated 30deg, direct', tx=tx, ty=ty,
                          matrix=[round(ca, 4), round(sa, 4), round(-sa, 4), round(ca, 4)],
                          tsnap_half_even=[rhe(tx), rhe(ty)]))
    # row 11: acid-size shape 9 in a sprite
    hair32, t = sq_shape(32, stroke=1.0); defs += t
    sp_hair32 = new_id(); defs += sprite(sp_hair32, place(1, hair32))
    acid = [('para41', (0.05, 0.3)), ('para51', (0.75, 0.3)), ('para41', (0.55, 0.95)),
            ('para51', (0.55, 0.95)), ('para41', (0.25, 0.25))]
    for k, (key, fr) in enumerate(acid):
        sheared(11, k, sp_hair32, key, fr, 'acid-stroke-0 shape 9 (32x32 1px noScale) in sprite, ' + key,
                n=32, cw=128, ch=120, x0=128 * k, y0=440)

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

    def num(v):
        return float(v) if v != int(v) else int(v)

    act = push('_quality', 'LOW') + SET_VARIABLE
    for i, (_, col, y, w, (x0, y0, x1, y1)) in enumerate(act_cells):
        nm = 'd%d' % i
        act += push(1000 + i, nm, 2) + push('this') + GET_VARIABLE + push('createEmptyMovieClip') + CALL_METHOD + POP
        act += setm(nm, '_x', 40 * col) + setm(nm, '_y', y)
        act += call(nm, 'lineStyle', num(w), 0x0000FF, 100)
        act += call(nm, 'moveTo', float(x0), float(y0)) + call(nm, 'lineTo', float(x1), float(y1))

    W, H = W_STAGE * 20, H_STAGE * 20
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
