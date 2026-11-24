"""s27 w1-applyfilter-tail item 5: ColorMatrix leftovers (three PlaceObject3 fixtures).

Library copied verbatim from regression/avm1_po3_color_matrix_live/create_test_swf.py.

avm1_po3_cm_live_under_cxform (SWF 10, no script): grey 200 60x40 at (10,10) with
  filters [CM x2, CM x0.5] AND a placement cxform rgb mult 0.5 (128/256).
  - cxform applied AFTER the filter passes (Ruffle: the cache is drawn with the
    object's colour transform at the blit): 200 -> 255 -> 128 -> 64.
  - cxform folded/applied BEFORE (ours today, PlaceCmCompose keeps the fold when
    the placement cx is not identity): 200*.5*2*.5 = 100.
  Control at (110,10): the same chain without a cxform (live today): 128.
avm1_po3_cm_alpha_bias_edge (SWF 10): red 59x39 at a .5 offset, CM alpha
  A' = 0.5*A + 64 (alpha bias > 0 stays FOLDED today). Ruffle caches + snaps a
  filtered object and computes A' per unpremultiplied texel: crisp (255,64,64)
  over white; the fold gives the same interior with a half-coverage AA rim.
avm1_po3_cm_folded_clear (SWF 8): sprite g (red) with one exact CM (R<->B swap,
  folded into the cxform at recompile time); frame 1 runs g.filters = [].
  Ruffle set_filters drops the authored list: g renders RED. h keeps it: BLUE.
"""
import struct, pathlib
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
class Bits:
    def __init__(s): s.b = ''
    def u(s, v, n): s.b += format(v & ((1 << n) - 1), '0%db' % n) if n else ''
    def bytes(s):
        b = s.b + '0' * ((8 - len(s.b) % 8) % 8)
        return bytes(int(b[k:k+8], 2) for k in range(0, len(b), 8))
def nbits(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n-1)) <= v < (1 << (n-1))): n += 1
    return n
def rectrec(x0, x1, y0, y1):
    b = Bits(); n = nbits(x0, x1, y0, y1); b.u(n, 5)
    for v in (x0, x1, y0, y1): b.u(v, n)
    return b.bytes()
def matrix(tx, ty, sx=None, sy=None):
    b = Bits()
    if sx is not None:
        b.u(1, 1); A = int(sx * 65536); D = int(sy * 65536); n = nbits(A, D); b.u(n, 5); b.u(A, n); b.u(D, n)
    else: b.u(0, 1)
    b.u(0, 1); n = nbits(tx, ty); b.u(n, 5); b.u(tx, n); b.u(ty, n)
    return b.bytes()
def cxform_alpha(mult=None, add=None):
    # mult/add: 4-tuples (r,g,b,a), mult in 8.8 (256 = 1.0)
    b = Bits(); b.u(1 if add else 0, 1); b.u(1 if mult else 0, 1)
    vals = list(mult or ()) + list(add or ())
    n = max(nbits(*vals), 2) if vals else 1; b.u(n, 4)
    for v in vals: b.u(v, n)
    return b.bytes()
def shape(cid, rects, rgba):
    """DefineShape3 with one solid RGBA fill and one or more rects (px, may be fractional)."""
    T = lambda v: int(round(v * 20))
    xs = [T(r[0]) for r in rects] + [T(r[0] + r[2]) for r in rects]
    ys = [T(r[1]) for r in rects] + [T(r[1] + r[3]) for r in rects]
    body = struct.pack('<H', cid) + rectrec(min(xs), max(xs), min(ys), max(ys))
    body += b'\x01\x00' + bytes(rgba) + b'\x00'
    b = Bits(); b.u(1, 4); b.u(0, 4)
    first = True
    for (x, y, w, h) in rects:
        X, Y, W, H = T(x), T(y), T(w), T(h)
        b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1 if first else 0, 1); b.u(1, 1)
        n = nbits(X, Y); b.u(n, 5); b.u(X, n); b.u(Y, n)
        if first: b.u(1, 1)
        first = False
        for dx, dy in [(W, 0), (0, H), (-W, 0), (0, -H)]:
            n = max(nbits(dx, dy), 2); b.u(1, 1); b.u(1, 1); b.u(n - 2, 4)
            if dx == 0: b.u(0, 1); b.u(1, 1); b.u(dy, n)
            else: b.u(0, 1); b.u(0, 1); b.u(dx, n)
    b.u(0, 6)
    return tag(32, body + b.bytes())
def blur(bx, by, passes=1):
    return bytes([1]) + struct.pack('<II', int(bx * 65536), int(by * 65536)) + bytes([(passes << 3)])
def colormatrix(m20):
    return bytes([6]) + struct.pack('<20f', *m20)
def place3(depth, cid, tx=0, ty=0, cx=None, filters=None, blend=None, name=None, sx=None, sy=None):
    f1 = 0x02 | 0x04 | (0x08 if cx else 0) | (0x20 if name else 0)
    f2 = (0x01 if filters else 0) | (0x02 if blend else 0)
    body = bytes([f1, f2]) + struct.pack('<HH', depth, cid) + matrix(int(tx * 20), int(ty * 20), sx, sy)
    if cx: body += cx
    if name: body += name.encode() + b'\0'
    if filters: body += bytes([len(filters)]) + b''.join(filters)
    if blend: body += bytes([blend])
    return tag(70, body)
def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + b''.join(tags) + tag(1, b'') + tag(0, b''))
def movie(tags, w=200, h=150, bg=(255, 255, 255), ver=10):
    t = [tag(69, bytes([0, 0, 0, 0])), tag(9, bytes(bg))] + tags + [tag(1, b''), tag(0, b'')]
    body = rectrec(0, w * 20, 0, h * 20) + struct.pack('<BBH', 0, 30, 1) + b''.join(t)
    return b'FWS' + bytes([ver]) + struct.pack('<I', 8 + len(body)) + body

RED = (255, 0, 0, 255); GREY = (200, 200, 200, 255)
SWAP_RB = [0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0]
ABIAS   = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,255, 0,0,0,1,128]
TWICE   = [2,0,0,0,0, 0,2,0,0,0, 0,0,2,0,0, 0,0,0,1,0]
HALF    = [.5,0,0,0,0, 0,.5,0,0,0, 0,0,.5,0,0, 0,0,0,1,0]
AFROMR  = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, .5,0,0,0,0]
SHAPES = [shape(1, [(0, 0, 60, 40)], RED),
          shape(2, [(0, 0, 20, 40), (40, 0, 20, 40)], RED),
          shape(3, [(0, 0, 60, 40)], GREY),
          shape(4, [(0.5, 0.5, 59, 39)], RED)]
PLACES = [place3(1, 1, 10, 10, filters=[colormatrix(SWAP_RB)]),
          place3(2, 2, 110, 10, filters=[colormatrix(ABIAS)]),
          place3(3, 3, 10, 80, filters=[colormatrix(TWICE), colormatrix(HALF)]),
          place3(4, 4, 110, 80, filters=[colormatrix(AFROMR)])]

# ---- AVM1 (frame-1 `g.filters = []`) ----
def s_(x): return b'\x00' + x.encode() + b'\x00'
def i_(x): return b'\x07' + struct.pack('<i', x)
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
CLEAR_G = (push(s_('g')) + b'\x1c' + push(s_('filters')) + push(i_(0)) + b'\x42' + b'\x4f'
           + push(s_('done')) + b'\x26' + b'\x00')


CXHALF = cxform_alpha(mult=(128, 128, 128, 256))
AHALFB = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,0,.5,64]
if __name__ == '__main__':
    here = pathlib.Path(__file__).resolve().parent
    (here / 'avm1_po3_cm_live_under_cxform' / 'test.swf').write_bytes(movie(
        [shape(3, [(0, 0, 60, 40)], GREY),
         place3(1, 3, 10, 10, cx=CXHALF, filters=[colormatrix(TWICE), colormatrix(HALF)]),
         place3(2, 3, 110, 10, filters=[colormatrix(TWICE), colormatrix(HALF)])]))
    (here / 'avm1_po3_cm_alpha_bias_edge' / 'test.swf').write_bytes(movie(
        [shape(4, [(0.5, 0.5, 59, 39)], RED), place3(1, 4, 110, 80, filters=[colormatrix(AHALFB)])]))
    (here / 'avm1_po3_cm_folded_clear' / 'test.swf').write_bytes(movie(
        [shape(1, [(0, 0, 60, 40)], RED), sprite(10, [place3(1, 1)]),
         place3(1, 10, 10, 10, filters=[colormatrix(SWAP_RB)], name='g'),
         place3(2, 10, 110, 10, filters=[colormatrix(SWAP_RB)], name='h'),
         tag(12, CLEAR_G)], ver=8))
