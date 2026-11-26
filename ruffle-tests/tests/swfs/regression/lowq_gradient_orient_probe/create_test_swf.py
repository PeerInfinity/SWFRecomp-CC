#!/usr/bin/env python3
"""Regenerate test.swf (+ cells.json) for lowq_gradient_orient_probe (s28 lowq-corner-rule).

Where does Flash Player's quality=LOW rasteriser evaluate GRADIENT paint, per
gradient type and orientation? The s28 w2 probe (lowq_sample_point_probe) only
had axis-aligned, increasing 32-px linear ramps plus one radial; the corner rule
fitted on it (paint at the pixel's top-left corner) broke the rotated linear
fill of visual/simple_shapes/gradients/gradients. This probe varies:

  row 0  smooth black->white 32-px linear ramp, rotation 0/30/45/60/90/135/180/315
  row 1  hard-step ramp (black <128, white >=128) at the same rotations
  row 2  mirrored / non-uniform / long ramps, and ramps under rotated, scaled and
         mirrored PlaceObject matrices
  row 3  fractional shape offsets (span-start dependence) at rotation 0 and 30
  row 4  radial / focal controls (centred, fractional centre, focal 0.6,
         non-uniform rotated, rotated placement) + 3 rotated hard steps
  row 5  hard-step ramp at 10/20/70/100/160/200/250/290 degrees
  rows 6-7  reflect / repeat spreads, skewed (non-orthogonal) matrices, and
         visual/simple_shapes/gradients/gradients' reflect matrix itself
  row 8  that matrix at its real stage translation (pad / reflect / repeat)

AVM1 SWF 8, static timeline, 320x360, white background, quality=low
(test.toml). cells.json records every cell's gradient->stage-pixel matrix and
shape polygon, for fitting the paint point (lowq-corner-rule-report.md).

Golden: output.expected.png = Flash Player 32 LNX draw() capture at quality
LOW, tick 1 (tools/flash-oracle/run_image.py --quality low).
"""
import json, math, pathlib, struct, sys

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import tag, Bits, show_frame, end_tag  # noqa: E402


def nbits_s(*vals):
    n = 1
    for v in vals:
        n = max(n, (v if v >= 0 else ~v).bit_length() + 1)
    return n


def fx(v):
    return int(round(v * 65536))


def matrix(a=1.0, b=0.0, c=0.0, d=1.0, tx=0, ty=0):
    """SWF MATRIX: x' = a x + c y + tx, y' = b x + d y + ty (tx, ty twips)."""
    w = Bits()
    if (a, d) != (1.0, 1.0):
        A, D = fx(a), fx(d)
        n = nbits_s(A, D)
        w.u(1, 1).u(n, 5).s(A, n).s(D, n)
    else:
        w.u(0, 1)
    if (b, c) != (0.0, 0.0):
        B, C = fx(b), fx(c)
        n = nbits_s(B, C)
        w.u(1, 1).u(n, 5).s(B, n).s(C, n)
    else:
        w.u(0, 1)
    n = nbits_s(tx, ty) if (tx or ty) else 0
    w.u(n, 5)
    if n:
        w.s(tx, n).s(ty, n)
    return w.bytes()


def q(m):
    """Quantise (a, b, c, d, tx_px, ty_px) the way the SWF stores it."""
    a, b, c, d, tx, ty = m
    return (fx(a) / 65536, fx(b) / 65536, fx(c) / 65536, fx(d) / 65536,
            round(tx * 20) / 20, round(ty * 20) / 20)


def compose(p, g):
    """p o g for (a, b, c, d, tx, ty) in px units."""
    pa, pb, pc, pd, ptx, pty = p
    ga, gb, gc, gd, gtx, gty = g
    return (pa * ga + pc * gb, pb * ga + pd * gb, pa * gc + pc * gd, pb * gc + pd * gd,
            pa * gtx + pc * gty + ptx, pb * gtx + pd * gty + pty)


def rect_bits(x0, x1, y0, y1):
    n = nbits_s(x0, x1, y0, y1)
    return Bits().u(n, 5).s(x0, n).s(x1, n).s(y0, n).s(y1, n).bytes()


def tw(v):
    return int(round(v * 20))


def rgba(c, a=255):
    return bytes([(c >> 16) & 255, (c >> 8) & 255, c & 255, a])


def shape_rect(sid, x, y, w, h, fill, shape4=False):
    """One filled rectangle in local px; fill = FILLSTYLE bytes."""
    x0, y0, x1, y1 = tw(x), tw(y), tw(x + w), tw(y + h)
    b = rect_bits(x0, x1, y0, y1)
    rec = Bits().u(1, 4).u(0, 4)
    n = nbits_s(x0, y0)
    rec.u(0, 1).u(0, 1).u(0, 1).u(0, 1).u(1, 1).u(1, 1).u(n, 5).s(x0, n).s(y0, n).u(1, 1)
    px, py = x0, y0
    for nx, ny in [(x1, y0), (x1, y1), (x0, y1), (x0, y0)]:
        dx, dy = nx - px, ny - py
        n = max(2, nbits_s(dx, dy))
        rec.u(1, 1).u(1, 1).u(n - 2, 4).u(1, 1).s(dx, n).s(dy, n)
        px, py = nx, ny
    rec.u(0, 6)
    if shape4:
        body = struct.pack('<H', sid) + b + b + bytes([0]) + bytes([1]) + fill + bytes([0])
        return tag(83, body + rec.bytes())
    body = struct.pack('<H', sid) + b + bytes([1]) + fill + bytes([0]) + rec.bytes()
    return tag(32, body)


def grad_fill(kind, gm, stops, spread=0, focal=None):
    t = {'linear': 0x10, 'radial': 0x12, 'focal': 0x13}[kind]
    a, b, c, d, tx, ty = gm
    g = bytes([(spread << 6) | len(stops)])
    for r, col in stops:
        g += bytes([r]) + rgba(col)
    if focal is not None:
        g += struct.pack('<h', int(round(focal * 256)))
    return bytes([t]) + matrix(a, b, c, d, tw(tx), tw(ty)) + g


def gbox(w, h, rot_deg, cx, cy):
    """Gradient matrix (px units) mapping the -16384..16384 square to a w x h
    box rotated by rot_deg about (cx, cy). Negative w / h mirror."""
    r = math.radians(rot_deg)
    sx, sy = w / 1638.4, h / 1638.4
    return (sx * math.cos(r), sx * math.sin(r), -sy * math.sin(r), sy * math.cos(r), cx, cy)


def place3(depth, cid, m):
    a, b, c, d, tx, ty = m
    f1 = 0x02 | 0x04
    dd = struct.pack('<BBH', f1, 0, depth) + struct.pack('<H', cid)
    dd += matrix(a, b, c, d, tw(tx), tw(ty))
    return tag(70, dd)


BW = [(0, 0x000000), (255, 0xFFFFFF)]
STEP = [(0, 0x000000), (127, 0x000000), (128, 0xFFFFFF), (255, 0xFFFFFF)]
RB = [(0, 0xFF0000), (255, 0x0000FF)]
ROTS = [0, 30, 45, 60, 90, 135, 180, 315]


def cells():
    """(name, kind, stops, gradient matrix px (shape-local), rect (x,y,w,h) local,
    placement matrix px, focal, spread)."""
    out = []

    def add(name, kind, stops, gm, col, row, rect=(4, 4, 32, 32), place=None, focal=None, spread=0):
        ox, oy = col * 40, row * 40
        pl = place if place is not None else (1.0, 0.0, 0.0, 1.0, 0.0, 0.0)
        pl = (pl[0], pl[1], pl[2], pl[3], pl[4] + ox, pl[5] + oy)
        out.append(dict(name=name, kind=kind, stops=stops, gm=gm, rect=rect, place=pl,
                        focal=focal, spread=spread, col=col, row=row))

    for i, r in enumerate(ROTS):
        add(f'lin_r{r}', 'linear', BW, gbox(32, 32, r, 20, 20), i, 0)
        add(f'step_r{r}', 'linear', STEP, gbox(32, 32, r, 20, 20), i, 1)
    # row 2
    add('lin_mirx_r0', 'linear', BW, gbox(-32, 32, 0, 20, 20), 0, 2)
    add('lin_mirx_r30', 'linear', BW, gbox(-32, 32, 30, 20, 20), 1, 2)
    add('lin_aniso_r30', 'linear', BW, gbox(64, 16, 30, 20, 20), 2, 2)
    add('lin_long_r0', 'linear', BW, gbox(320, 32, 0, 20, 20), 3, 2)
    add('lin_long_r30', 'linear', BW, gbox(320, 32, 30, 20, 20), 4, 2)
    c30, s30 = math.cos(math.radians(30)), math.sin(math.radians(30))
    add('lin_place_rot30', 'linear', BW, gbox(32, 32, 0, 0, 0), 5, 2,
        rect=(-13, -13, 26, 26), place=(c30, s30, -s30, c30, 20, 20))
    add('lin_place_x2', 'linear', BW, gbox(16, 16, 0, 0, 0), 6, 2,
        rect=(-8, -8, 16, 16), place=(2.0, 0.0, 0.0, 2.0, 20, 20))
    add('lin_place_mirx', 'linear', BW, gbox(32, 32, 0, 0, 0), 7, 2,
        rect=(-16, -16, 32, 32), place=(-1.0, 0.0, 0.0, 1.0, 20, 20))
    # row 3: fractional shape offsets, gradient fixed
    for i, o in enumerate([0.25, 0.5, 0.75]):
        add(f'lin_r0_off{o}', 'linear', BW, gbox(32, 32, 0, 20, 20), i, 3, rect=(4 + o, 4 + o, 31, 31))
        add(f'lin_r30_off{o}', 'linear', BW, gbox(32, 32, 30, 20, 20), 3 + i, 3, rect=(4 + o, 4 + o, 31, 31))
    add('lin_r0_gfrac', 'linear', BW, gbox(32, 32, 0, 20.3, 20.7), 6, 3)
    add('lin_r30_gfrac', 'linear', BW, gbox(32, 32, 30, 20.3, 20.7), 7, 3)
    # row 4: radial / focal controls + rotated steps
    add('rad_c', 'radial', BW, gbox(32, 32, 0, 20, 20), 0, 4)
    add('rad_frac', 'radial', BW, gbox(32, 32, 0, 20.3, 20.7), 1, 4)
    add('focal_06', 'focal', RB, gbox(32, 32, 0, 20, 20), 2, 4, focal=0.6)
    add('rad_aniso_r30', 'radial', BW, gbox(48, 24, 30, 20, 20), 3, 4)
    add('rad_place_rot30', 'radial', BW, gbox(32, 32, 0, 0, 0), 4, 4,
        rect=(-13, -13, 26, 26), place=(c30, s30, -s30, c30, 20, 20))
    for i, r in enumerate([5, 85, 120]):
        add(f'step_r{r}', 'linear', STEP, gbox(32, 32, r, 20, 20), 5 + i, 4)
    for i, r in enumerate([10, 20, 70, 100, 160, 200, 250, 290]):
        add(f'step_r{r}', 'linear', STEP, gbox(32, 32, r, 20, 20), i, 5)
    # rows 6-7: spread modes and skewed (non-orthogonal) matrices
    # gradients/gradients' reflect fill matrix (a, b, c, d) = (0.0623, -0.1640, 0.1080, 0.0947)
    G = (0.06233215332031250, -0.1640167236328125, 0.1079559326171875, 0.09469604492187500)
    Gs = tuple(v / 4 for v in G)  # quarter size: ~50-px period
    add('refl_r0', 'linear', BW, gbox(32, 32, 0, 20, 20), 0, 6, spread=1)
    add('refl_r30', 'linear', BW, gbox(16, 32, 30, 20, 20), 1, 6, spread=1)
    add('rep_r0', 'linear', BW, gbox(16, 32, 0, 20, 20), 2, 6, spread=2)
    add('rep_r30', 'linear', BW, gbox(16, 32, 30, 20, 20), 3, 6, spread=2)
    add('pad_skewG4', 'linear', BW, Gs + (20.7, 20.75), 4, 6)
    add('refl_skewG4', 'linear', BW, Gs + (20.7, 20.75), 5, 6, spread=1)
    add('pad_skew', 'linear', BW, (0.015, 0.006, 0.012, 0.02, 20, 20), 6, 6)
    add('refl_skew', 'linear', BW, (0.015, 0.006, 0.012, 0.02, 20, 20), 7, 6, spread=1)
    add('pad_G', 'linear', BW, G + (20.7, 20.75), 0, 7)
    add('refl_G', 'linear', BW, G + (20.7, 20.75), 1, 7, spread=1)
    add('rep_G', 'linear', BW, G + (20.7, 20.75), 2, 7, spread=2)
    add('pad_G_t0', 'linear', BW, G + (20, 20), 3, 7)
    add('refl_r0_n', 'linear', BW, gbox(8, 32, 0, 20, 20), 4, 7, spread=1)
    add('rep_r0_n', 'linear', BW, gbox(8, 32, 0, 20, 20), 5, 7, spread=2)
    add('refl_r90', 'linear', BW, gbox(16, 32, 90, 20, 20), 6, 7, spread=1)
    add('refl_rad', 'radial', BW, gbox(16, 16, 0, 20, 20), 7, 7, spread=1)
    # row 8: gradients' matrix with its real stage translation (276.7, 198.75),
    # cells at stage (x, 324); placement identity in the last four
    for i, (kind_sp, ident) in enumerate([(0, False), (1, False), (2, False), (0, True), (1, True), (2, True)]):
        nm = ['pad', 'refl', 'rep'][kind_sp] + ('_Gfar_id' if ident else '_Gfar')
        if ident:
            add(nm, 'linear', BW, G + (276.7, 198.75), i, 8,
                rect=(i * 40 + 4, 324, 32, 32), place=(1.0, 0.0, 0.0, 1.0, -i * 40, -320), spread=kind_sp)
        else:
            add(nm, 'linear', BW, G + (276.7 - i * 40, 198.75 - 320), i, 8, spread=kind_sp)
    add('refl_Gfar_big', 'linear', BW, G + (276.7 - 240, 198.75 - 320), 6, 8, rect=(4, 4, 72, 32), spread=1)
    return out


def build():
    defs, places, meta = b'', b'', []
    for i, c in enumerate(cells()):
        sid = i + 1
        gm = q(c['gm'])
        pl = q(c['place'])
        fill = grad_fill(c['kind'], gm, c['stops'], c['spread'], c['focal'])
        defs += shape_rect(sid, *c['rect'], fill, shape4=(c['kind'] == 'focal'))
        places += place3(sid, sid, pl)
        x, y, w, h = c['rect']
        corners = [(x, y), (x + w, y), (x + w, y + h), (x, y + h)]
        poly = [(pl[0] * u + pl[2] * v + pl[4], pl[1] * u + pl[3] * v + pl[5]) for u, v in corners]
        meta.append(dict(name=c['name'], kind=c['kind'], stops=c['stops'], focal=c['focal'], spread=c['spread'],
                         col=c['col'], row=c['row'],
                         grad_px=(gm[0] / 20, gm[1] / 20, gm[2] / 20, gm[3] / 20, gm[4], gm[5]), place_px=pl,
                         grad_to_stage_px=compose(pl, (gm[0] / 20, gm[1] / 20, gm[2] / 20, gm[3] / 20, gm[4], gm[5])),
                         poly_stage_px=poly))
    W, H = 320 * 20, 360 * 20
    tags = tag(69, struct.pack('<I', 0)) + tag(9, bytes([255, 255, 255]))
    tags += defs + places + show_frame() + end_tag()
    body = rect_bits(0, W, 0, H) + struct.pack('<H', 30 << 8) + struct.pack('<H', 1) + tags
    (HERE / 'test.swf').write_bytes(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
    (HERE / 'cells.json').write_text(json.dumps(meta, indent=1) + '\n')
    print('wrote', HERE / 'test.swf', 8 + len(body), len(meta), 'cells')


if __name__ == '__main__':
    build()
