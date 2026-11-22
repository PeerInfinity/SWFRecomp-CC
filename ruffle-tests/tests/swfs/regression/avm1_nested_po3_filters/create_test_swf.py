"""regression/avm1_nested_po3_filters: SWF-authored PlaceObject3 filter lists on
clips NESTED in a DefineSprite vs the same lists at root depth (s25 w2-avm1-filters).

Three nested placements inside sprite `outer` ([Glow], [Blur, DropShadow],
[ColorMatrix halving RGB]) and their root-depth twins, read back through the AVM1
`filters` getter in frame 2 (3 ticks), and rendered.
Before: the recompiler's DefineSprite PlaceObject3 arm kept only the FIRST simple
filter (tagSetFilter) and skipped ColorMatrix, so `outer.two n=1`, its second
member read undefined, `outer.cm n=0`, and the nested row rendered without the
drop shadow and without the darkening. Fixed by swf.cpp emitSpriteFilterList
(per-site static list via tag.c tagBeginFilterListAt), the sprite-arm ColorMatrix
fold into the placement cxform, and the action.c `filters` getter reading the
entry's own filter_chain. After, the nested row (y 0-160) is pixel-identical to
the root row (y 160-320), as in Ruffle.

Expected trace and output.expected.png: local Ruffle exporter at 0ddd12b6a
(session25-fanout-reports/w1-avm1-filters-complete-oracle; render 1 frame, the
content is static from frame 1). Generator from s24 w1-avm1-tail-probe/mkl1.py.
Regenerate byte-identically: `python3 create_test_swf.py` (writes test.swf here).
"""
# L1 probe: SWF-authored (PlaceObject3) filters on clips NESTED in a sprite vs
# at root depth, read back through the AVM1 `filters` getter.
# Usage: python3 mkl1.py out.swf
import struct, sys, os

def s(x): return b'\x00' + x.encode() + b'\x00'
def i(x): return b'\x07' + struct.pack('<i', x)
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
GETVAR=b'\x1c'; GETMEM=b'\x4e'; TRACE=b'\x26'; ADD2=b'\x47'; STOP=b'\x07'
def path(names):
    out = push(s(names[0])) + GETVAR
    for n in names[1:]:
        out += push(i(n) if isinstance(n, int) else s(n)) + GETMEM
    return out
def cat(*codes):
    out = codes[0]
    for c in codes[1:]: out += c + ADD2
    return out
def trace(code): return code + TRACE

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
def matrix(tx, ty):
    b = Bits(); b.u(0, 1); b.u(0, 1); n = nbits(tx, ty); b.u(n, 5); b.u(tx, n); b.u(ty, n)
    return b.bytes()
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
def shape(cid, w, h, rgb):
    W, H = w * 20, h * 20
    body = struct.pack('<H', cid) + rectrec(0, W, 0, H)
    body += b'\x01\x00' + bytes(rgb) + b'\x00'
    b = Bits(); b.u(1, 4); b.u(0, 4)
    b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1, 1); b.u(1, 1)
    n = nbits(0, 0); b.u(n, 5); b.u(0, n); b.u(0, n); b.u(1, 1)
    for dx, dy in [(W, 0), (0, H), (-W, 0), (0, -H)]:
        n = max(nbits(dx, dy), 2); b.u(1, 1); b.u(1, 1); b.u(n - 2, 4)
        if dx == 0: b.u(0, 1); b.u(1, 1); b.u(dy, n)
        else: b.u(0, 1); b.u(0, 1); b.u(dx, n)
    b.u(0, 6)
    return tag(2, body + b.bytes())
FX = lambda v: struct.pack('<i', int(v * 65536))
F8 = lambda v: struct.pack('<H', int(v * 256))
def f_blur(bx, by): return b'\x01' + FX(bx) + FX(by) + bytes([1 << 3])
def f_glow(rgba, bx, by, st): return b'\x02' + bytes(rgba) + FX(bx) + FX(by) + F8(st) + bytes([0x20 | 1])
def f_ds(rgba, bx, by, ang, dist, st): return b'\x00' + bytes(rgba) + FX(bx) + FX(by) + FX(ang) + FX(dist) + F8(st) + bytes([0x20 | 1])
def f_cm(m): return b'\x06' + b''.join(struct.pack('<f', v) for v in m)
def place3(depth, cid, tx, ty, name, filters):
    f1 = 0x20 | 0x04 | 0x02
    body = bytes([f1, 0x01 if filters else 0]) + struct.pack('<HH', depth, cid) + matrix(tx * 20, ty * 20) + s(name)[1:]
    if filters: body += bytes([len(filters)]) + b''.join(filters)
    return tag(70, body)
def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + b''.join(tags) + tag(1, b'') + tag(0, b''))

GLOW = f_glow((0, 0, 255, 255), 6, 6, 2)
BLUR = f_blur(4, 4)
DS = f_ds((0, 0, 0, 255), 7, 7, 0.785398, 4, 1)
CM = f_cm([0.5,0,0,0,0, 0,0.5,0,0,0, 0,0,0.5,0,0, 0,0,0,1,0])

body = rectrec(0, 550 * 20, 0, 400 * 20) + struct.pack('<HH', 30 << 8, 2)
body += tag(69, struct.pack('<I', 0x00))          # FileAttributes: AS1/2 (no AS3 bit)
body += tag(9, b'\xff\xff\xff')
body += shape(1, 40, 30, (255, 0, 0))
body += sprite(2, [tag(26, bytes([0x04 | 0x02]) + struct.pack('<HH', 1, 1) + matrix(0, 0))])
body += sprite(3, [place3(1, 2, 0, 0, 'one', [GLOW]),
                   place3(2, 2, 60, 0, 'two', [BLUR, DS]),
                   place3(3, 2, 120, 0, 'cm', [CM])])
body += place3(1, 3, 40, 40, 'outer', [])
body += place3(2, 2, 40, 200, 'rootone', [GLOW])
body += place3(3, 2, 100, 200, 'roottwo', [BLUR, DS])
body += place3(4, 2, 160, 200, 'rootcm', [CM])
body += tag(1, b'')
a = b''
for nm in (['outer', 'one'], ['outer', 'two'], ['outer', 'cm'], ['rootone'], ['roottwo'], ['rootcm']):
    lab = '.'.join(nm)
    a += trace(cat(push(s(lab + ' n=')), path(nm + ['filters', 'length'])))
    a += trace(cat(push(s(lab + ' 0.blurX=')), path(nm + ['filters', 0, 'blurX']),
                   push(s(' 1.blurX=')), path(nm + ['filters', 1, 'blurX']),
                   push(s(' 0.matrix.length=')), path(nm + ['filters', 0, 'matrix', 'length'])))
a += STOP + b'\x00'
body += tag(12, a) + tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf'), 'wb').write(swf)
