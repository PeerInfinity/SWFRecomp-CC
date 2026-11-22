# L1 probe: SWF-authored (PlaceObject3) filters on clips NESTED in a sprite vs
# at root depth, read back through the AVM1 `filters` getter.
# Usage: python3 mkl1.py out.swf
import struct, sys

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


def cxform(mult, add):
    b = Bits(); vals = list(mult) + list(add); n = nbits(*vals)
    b.u(1, 1); b.u(1, 1); b.u(n, 4)
    for v in vals: b.u(v, n)
    return b.bytes()
def place3cx(depth, cid, tx, ty, name, filters, cx):
    f1 = 0x20 | 0x08 | 0x04 | 0x02
    body = bytes([f1, 0x01]) + struct.pack('<HH', depth, cid) + matrix(tx * 20, ty * 20) + cx + s(name)[1:]
    body += bytes([len(filters)]) + b''.join(filters)
    return tag(70, body)
def f_ggl(cols, ratios, bx, by, ang, dist, st, flags):
    out = b'\x04' + bytes([len(cols)])
    for c in cols: out += bytes(c)
    out += bytes(ratios) + FX(bx) + FX(by) + FX(ang) + FX(dist) + F8(st) + bytes([flags])
    return out
SWAP = f_cm([0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0])
HALF = f_cm([0.5,0,0,0,0, 0,0.5,0,0,0, 0,0,0.5,0,0, 0,0,0,1,0])
CX = cxform((256, 256, 128, 256), (64, 0, 0, 0))   # B*0.5, R+64
NOCX = cxform((256, 256, 256, 256), (0, 0, 0, 0))
# GradientGlow, outer (inner=0), knockout 0, composite 1, onTop 1, passes 2 -> 0x20|0x10|2
GG = f_ggl([(255,255,255,0),(0,0,255,255),(0,255,0,255)], [0,128,255], 8, 8, 0.785398, 0, 2, 0x20 | 0x10 | 2)
body = rectrec(0, 550 * 20, 0, 400 * 20) + struct.pack('<HH', 30 << 8, 2)
body += tag(69, struct.pack('<I', 0x00))
body += tag(9, b'\xff\xff\xff')
body += shape(1, 40, 30, (255, 0, 0))
body += sprite(2, [tag(26, bytes([0x04 | 0x02]) + struct.pack('<HH', 1, 1) + matrix(0, 0))])
body += sprite(3, [place3cx(1, 2, 0, 0, 'cxcm', [SWAP], CX),
                   place3cx(2, 2, 80, 0, 'cm2', [SWAP, HALF], NOCX),
                   place3cx(3, 2, 160, 0, 'gg', [GG], NOCX)])
body += place3(1, 3, 40, 40, 'outer', [])
body += place3cx(2, 2, 40, 200, 'rcxcm', [SWAP], CX)
body += place3cx(3, 2, 120, 200, 'rcm2', [SWAP, HALF], NOCX)
body += place3cx(4, 2, 200, 200, 'rgg', [GG], NOCX)
body += tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1], 'wb').write(swf)
