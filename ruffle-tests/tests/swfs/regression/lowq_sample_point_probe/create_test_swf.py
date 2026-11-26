#!/usr/bin/env python3
"""Regenerate test.swf for lowq_sample_point_probe (s28 w2-lowq-sample-point).

A static-timeline (AVM1, SWF 8) re-expression of the s28 w1 Flash probe
`session28-fanout-reports/w1-avm2-vector-flash-fixtures/lowq_sample_point/Test.as`
(the AS3 SWF the coordinator captured in Flash 32 is not archived in the repo,
and the cloud has no AS3 compiler). Every cell has the same geometry, in
twips, as the AS3 Drawing-API original; the stage is 240x160, white, and the
test renders at quality=low (test.toml).

Golden: `output.expected.png` = Flash Player 32 LNX, draw() capture, quality
LOW, tick 1, of the AS3 original (`w1-local-oracles/w1-avm2-vector-flash/
lowq_sample_point.low.png`, screen == draw()).

Differences from the AS3 original (documented, not hidden):
- the two 8x8 checker Bitmaps (row 3, x 164 / 200.5) are shapes with a
  clipped, non-smoothed bitmap fill (fill type 0x43) instead of Bitmap
  display objects;
- the scrollRect cell (x 40-80, y 120-160) is omitted: AVM1 scrollRect
  stores whole pixels in our runtime and the cell does not reproduce; its
  region is masked to white in output.expected.png (the Flash capture with
  that cell blanked);
- the cacheAsBitmap cell uses PlaceObject3's BitmapCache flag;
- drawCircle is expanded as Flash's 8 quadratic segments.
"""
import math, pathlib, struct, sys, zlib

HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (tag, Bits, show_frame, end_tag, do_action, push,  # noqa: E402
                     GET_VARIABLE, GET_MEMBER, SET_MEMBER, _rec)

NEW_METHOD = _rec(0x53)


def nbits_s(*vals):
    n = 1
    for v in vals:
        n = max(n, (v if v >= 0 else ~v).bit_length() + 1)
    return n


def matrix(a=1.0, b=0.0, c=0.0, d=1.0, tx=0, ty=0):
    w = Bits()
    if (a, d) != (1.0, 1.0):
        A, D = int(round(a * 65536)), int(round(d * 65536))
        n = nbits_s(A, D)
        w.u(1, 1).u(n, 5).s(A, n).s(D, n)
    else:
        w.u(0, 1)
    if (b, c) != (0.0, 0.0):
        B, C = int(round(b * 65536)), int(round(c * 65536))
        n = nbits_s(B, C)
        w.u(1, 1).u(n, 5).s(B, n).s(C, n)
    else:
        w.u(0, 1)
    n = nbits_s(tx, ty) if (tx or ty) else 0
    w.u(n, 5)
    if n:
        w.s(tx, n).s(ty, n)
    return w.bytes()


def rect(x0, x1, y0, y1):
    n = nbits_s(x0, x1, y0, y1)
    return Bits().u(n, 5).s(x0, n).s(x1, n).s(y0, n).s(y1, n).bytes()


def tw(v):
    return int(round(v * 20))


class Path:
    """Shape records in twips. Commands: ('m',x,y) ('l',x,y) ('c',cx,cy,ax,ay)
    with absolute px coordinates; fill/line style changes at moves."""

    def __init__(self):
        self.cmds = []

    def move(self, x, y, fill0=None, fill1=None, line=None):
        self.cmds.append(('m', tw(x), tw(y), fill0, fill1, line))

    def line(self, x, y):
        self.cmds.append(('l', tw(x), tw(y)))

    def curve(self, cx, cy, ax, ay):
        self.cmds.append(('c', tw(cx), tw(cy), tw(ax), tw(ay)))

    def records(self, nfill, nline):
        fb = max(1, nfill.bit_length())
        lb = max(0, nline.bit_length())
        w = Bits().u(fb, 4).u(lb, 4)
        px = py = 0
        for cmd in self.cmds:
            if cmd[0] == 'm':
                _, x, y, f0, f1, ln = cmd
                w.u(0, 1).u(0, 1)
                w.u(ln is not None, 1).u(f1 is not None, 1).u(f0 is not None, 1).u(1, 1)
                n = nbits_s(x, y)
                w.u(n, 5).s(x, n).s(y, n)
                if f0 is not None:
                    w.u(f0, fb)
                if f1 is not None:
                    w.u(f1, fb)
                if ln is not None:
                    w.u(ln, lb)
                px, py = x, y
            elif cmd[0] == 'l':
                _, x, y = cmd
                dx, dy = x - px, y - py
                n = max(2, nbits_s(dx, dy))
                w.u(1, 1).u(1, 1).u(n - 2, 4).u(1, 1).s(dx, n).s(dy, n)
                px, py = x, y
            else:
                _, cx, cy, ax, ay = cmd
                v = (cx - px, cy - py, ax - cx, ay - cy)
                n = max(2, nbits_s(*v))
                w.u(1, 1).u(0, 1).u(n - 2, 4)
                for q in v:
                    w.s(q, n)
                px, py = ax, ay
        w.u(0, 6)
        return w.bytes()

    def bounds(self, margin=0):
        xs, ys = [], []
        for cmd in self.cmds:
            pts = cmd[1:3] if cmd[0] in 'ml' else cmd[1:5]
            xs += pts[0::2]
            ys += pts[1::2]
        m = tw(margin)
        return min(xs) - m, max(xs) + m, min(ys) - m, max(ys) + m


def rgba(c, a=255):
    return bytes([(c >> 16) & 255, (c >> 8) & 255, c & 255, a])


def solid(c):
    return b'\x00' + rgba(c)


def gradient(kind, mtx, stops, spread=0, focal=None):
    t = {'linear': 0x10, 'radial': 0x12, 'focal': 0x13}[kind]
    g = bytes([(spread << 6) | len(stops)])
    for r, c in stops:
        g += bytes([r]) + rgba(c)
    if focal is not None:
        g += struct.pack('<h', focal)
    return bytes([t]) + mtx + g


def gradient_box(w, h, rot, x, y):
    a = w / 1638.4 * math.cos(rot)
    b = h / 1638.4 * math.sin(rot)
    c = -w / 1638.4 * math.sin(rot)
    d = h / 1638.4 * math.cos(rot)
    return matrix(a, b, c, d, tw(x + w / 2), tw(y + h / 2))


def define_shape3(sid, path, fills, lines=(), margin=0):
    body = struct.pack('<H', sid) + rect(*path.bounds(margin))
    body += bytes([len(fills)]) + b''.join(fills)
    body += bytes([len(lines)]) + b''.join(lines)
    body += path.records(len(fills), len(lines))
    return tag(32, body)


def define_shape4(sid, path, fills):
    b = rect(*path.bounds())
    body = struct.pack('<H', sid) + b + b + bytes([0])
    body += bytes([len(fills)]) + b''.join(fills) + bytes([0])
    body += path.records(len(fills), 0)
    return tag(83, body)


def line3(width_px, c):
    return struct.pack('<H', tw(width_px)) + rgba(c)


def place3(depth, cid, tx, ty, name=None, cab=False):
    f1 = 0x02 | 0x04 | (0x20 if name else 0)
    f2 = 0x04 if cab else 0
    d = struct.pack('<BBH', f1, f2, depth) + struct.pack('<H', cid)
    d += matrix(tx=tw(tx), ty=tw(ty))
    if name:
        d += name.encode() + b'\x00'
    if cab:
        d += b'\x01'
    return tag(70, d)


def rect_path(p, x, y, w, h, **st):
    p.move(x, y, **st)
    p.line(x + w, y)
    p.line(x + w, y + h)
    p.line(x, y + h)
    p.line(x, y)


def circle_path(p, cx, cy, r, **st):
    # Flash's drawCircle: 8 quadratic segments, control at r / cos(pi/8).
    k = r / math.cos(math.pi / 8)
    p.move(cx + r, cy, **st)
    for i in range(8):
        a0 = i * math.pi / 4
        am = a0 + math.pi / 8
        a1 = a0 + math.pi / 4
        p.curve(cx + k * math.cos(am), cy + k * math.sin(am), cx + r * math.cos(a1), cy + r * math.sin(a1))


def build():
    defs, places = b'', b''
    sid = [0]
    depth = [0]

    def add(tagfn, x, y, **pl):
        nonlocal defs, places
        sid[0] += 1
        depth[0] += 1
        defs += tagfn(sid[0])
        places += place3(depth[0], sid[0], x, y, **pl)

    # Row 0: fills
    p = Path(); p.move(20, 2, fill0=1); p.line(38, 20); p.line(20, 38); p.line(2, 20); p.line(20, 2)
    add(lambda i, p=p: define_shape3(i, p, [solid(0xFF0000)]), 0, 0)
    p = Path(); p.move(5, 2, fill0=1); p.line(15, 38); p.line(35, 2); p.line(5, 2)
    add(lambda i, p=p: define_shape3(i, p, [solid(0x0000FF)]), 40, 0)
    for k, o in enumerate([0.0, 0.25, 0.5, 0.75]):
        p = Path(); rect_path(p, 5 + o, 5 + o, 20, 20, fill0=1)
        add(lambda i, p=p: define_shape3(i, p, [solid(0x008000)]), 80 + k * 40, 0)
    # Row 1: strokes 1 / 2 / 4 / hairline at x.0 and x.5
    for k, wd in enumerate([1, 2, 4, 0]):
        p = Path(); rect_path(p, 5, 5, 12, 25, line=1); rect_path(p, 22.5, 5.5, 12, 25, line=1)
        add(lambda i, p=p, wd=wd: define_shape3(i, p, [], [line3(wd, 0)], margin=max(wd, 1)), k * 40, 40)
    p = Path(); circle_path(p, 20, 20, 13, line=1)
    add(lambda i, p=p: define_shape3(i, p, [], [line3(3, 0)], margin=3), 160, 40)
    p = Path(); p.move(3, 3, line=1); p.line(37, 20); p.line(3, 37)
    add(lambda i, p=p: define_shape3(i, p, [], [line3(2, 0)], margin=2), 200, 40)
    # Row 2: gradients
    bw = [(0, 0x000000), (255, 0xFFFFFF)]
    rb = [(0, 0xFF0000), (255, 0x0000FF)]
    for k, (kind, rot, stops, spread, focal) in enumerate([
            ('linear', 0, bw, 0, None), ('linear', math.pi / 2, bw, 0, None),
            ('radial', 0, rb, 0, None), ('focal', 0, rb, 2, int(0.6 * 256))]):
        p = Path(); rect_path(p, 4, 4, 32, 32, fill0=1)
        f = gradient(kind, gradient_box(32, 32, rot, 4, 4), stops, spread, focal)
        fn = define_shape4 if kind == 'focal' else define_shape3
        add(lambda i, p=p, f=f, fn=fn: fn(i, p, [f]), k * 40, 80)
    # Row 3: bitmap (8x8 checker, magenta on white)
    sid[0] += 1
    bmp = sid[0]
    px = b''
    for y in range(8):
        for x in range(8):
            px += b'\xff' + (rgba(0xFF00FF)[:3] if ((x + y) & 1) == 0 else b'\xff\xff\xff')
    defs += tag(20, struct.pack('<HBHH', bmp, 5, 8, 8) + zlib.compress(px))

    def bmfill(t, a, b, c, d, tx, ty):
        return bytes([t]) + struct.pack('<H', bmp) + matrix(a * 20, b * 20, c * 20, d * 20, tw(tx), tw(ty))
    # "Bitmap" cells: 32x32 clipped non-smoothed fill, scale 4
    for x, y in [(164, 124), (200.5, 124.5)]:
        p = Path(); rect_path(p, 0, 0, 32, 32, fill0=1)
        add(lambda i, p=p: define_shape3(i, p, [bmfill(0x43, 4, 0, 0, 4, 0, 0)]), x, y)
    # cacheAsBitmap cell
    p = Path(); rect_path(p, 0, 0, 25, 25, fill0=1)
    add(lambda i, p=p: define_shape3(i, p, [solid(0x00AAFF)]), 7.5, 127.5, cab=True)
    # (scrollRect cell omitted: AVM1 scrollRect does not reproduce the AS3 cell; see the docstring)
    # bitmap fills
    for x, m in [(80, (4, 0, 0, 4, 0.5, 0.5)), (120, (3, 1, -1, 3, 10, 0))]:
        p = Path(); rect_path(p, 2, 2, 34, 34, fill0=1)
        add(lambda i, p=p, m=m: define_shape3(i, p, [bmfill(0x42, *m)]), x, 120)

    W, H = 240 * 20, 160 * 20
    tags = tag(69, struct.pack('<I', 0)) + tag(9, bytes([255, 255, 255]))
    tags += defs + places + show_frame() + end_tag()
    body = rect(0, W, 0, H) + struct.pack('<H', 30 << 8) + struct.pack('<H', 1) + tags
    out = HERE / 'test.swf'
    out.write_bytes(b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body)
    print('wrote', out, 8 + len(body))


if __name__ == '__main__':
    build()
