#!/usr/bin/env python3
"""Regenerate test.swf for one of the s27 w2b-group-alpha-triggers fixtures
(AVM1 `group_alpha_<probe>` and AVM2 twin `avm2_group_alpha_<probe>`); the
variant is taken from the directory name.

Each is the s27 w2-layer-alpha-group probe scene
(SWFRecompDocs/plans/session27-fanout-reports/w2-layer-alpha-group-fixtures/
mkprobes_groups.py, byte-identical for the AVM1 variants): sprite 10 holds an
opaque red rect (20,20,80,60) under an opaque blue rect (60,40,80,70); it is
placed on a white 200x150 stage with a different TRANSPARENCY-GROUP trigger:
  filter_cm    identity ColorMatrixFilter + alpha 128/256   -> GROUPED
  multiply     blendMode MULTIPLY + alpha 128/256           -> GROUPED
  layer_aadd   blendMode LAYER, alpha mult 1, offset -128   -> GROUPED
  layer_inner  LAYER sprite (alpha 1) inside a 50% parent   -> GROUPED
  cab          cacheAsBitmap + alpha 128/256                -> PER CHILD
At the overlap (80,50) grouped = (128,128,255) (blue only; layer_aadd reads
(128,128,254)), per child = (128,65,192) for cab.

GOLDEN = Flash Player 32 (LNX 32,0,0,465) `run_image.py --screen`, num_ticks
1, quality high: SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/
w2-layer-alpha-group/n3g_<probe>/flash.screen.png (screen == draw() for all).
The AVM2 twins (FileAttributes.ActionScript3 + a minimal DoABC, the
avm2_layer_group_alpha recipe) use the same golden: a script-free timeline
renders the same under both VMs.
"""
import pathlib, struct, sys
HERE = pathlib.Path(__file__).resolve().parent

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


def place3(depth, cid, tx=0, ty=0, cx=None, filters=None, blend=None, cab=False):
    f1 = 0x02 | 0x04 | (0x08 if cx else 0)
    f2 = (0x01 if filters else 0) | (0x02 if blend else 0) | (0x04 if cab else 0)
    body = bytes([f1, f2]) + struct.pack('<HH', depth, cid) + matrix(int(tx * 20), int(ty * 20))
    if cx: body += cx
    if filters: body += bytes([len(filters)]) + b''.join(filters)
    if blend: body += bytes([blend])
    if cab: body += bytes([1])
    return tag(70, body)
def colormatrix(m20):
    return bytes([6]) + struct.pack('<20f', *m20)

RED = (255, 0, 0, 255); BLUE = (0, 0, 255, 255)
IDENT_CM = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, 0,0,0,1,0]
A50 = cxform_alpha(mult=(256, 256, 256, 128))

# minor 16, major 46; empty constant pool; 1 method (init: getlocal0 /
# pushscope / returnvoid), 1 script, no classes (avm2_layer_group_alpha).
ABC = (struct.pack("<HH", 16, 46) + bytes(7)
       + bytes([1, 0, 0, 0, 0]) + bytes([0]) + bytes([0])
       + bytes([1, 0, 0])
       + bytes([1, 0, 1, 1, 0, 1, 3, 0xD0, 0x30, 0x47, 0, 0]))
DOABC = tag(82, struct.pack("<I", 1) + b"\0" + ABC)

def scene():
    return [shape(1, [(20, 20, 80, 60)], RED), shape(2, [(60, 40, 80, 70)], BLUE),
            sprite(10, [place3(1, 1), place3(2, 2)])]
PROBES = {
    'filter_cm':   lambda: scene() + [place3(1, 10, cx=A50, filters=[colormatrix(IDENT_CM)])],
    'cab':         lambda: scene() + [place3(1, 10, cx=A50, cab=True)],
    'multiply':    lambda: scene() + [place3(1, 10, cx=A50, blend=3)],
    'layer_inner': lambda: scene() + [sprite(11, [place3(1, 10, blend=2)]), place3(1, 11, cx=A50)],
    'layer_aadd':  lambda: scene() + [place3(1, 10, cx=cxform_alpha(mult=(256, 256, 256, 256), add=(0, 0, 0, -128)), blend=2)],
}

def build(name):
    avm2 = name.startswith("avm2_")
    probe = name[len("avm2_"):] if avm2 else name
    probe = probe[len("group_alpha_"):]
    tags = PROBES[probe]()
    fa = 0x08 if avm2 else 0
    t = [tag(69, bytes([fa, 0, 0, 0])), tag(9, bytes((255, 255, 255)))]
    if avm2: t.append(DOABC)
    t += tags + [tag(1, b''), tag(0, b'')]
    body = rectrec(0, 200 * 20, 0, 150 * 20) + struct.pack('<BBH', 0, 30, 1) + b''.join(t)
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body

if __name__ == "__main__":
    name = sys.argv[1] if len(sys.argv) > 1 else HERE.name
    (HERE / "test.swf").write_bytes(build(name))
    print("wrote", HERE / "test.swf", name)
