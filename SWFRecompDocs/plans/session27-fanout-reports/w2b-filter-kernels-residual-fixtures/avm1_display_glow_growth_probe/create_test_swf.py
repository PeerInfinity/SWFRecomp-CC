#!/usr/bin/env python3
"""FLASH ORACLE PROBE (s27 w2b-filter-kernels-residual): display-object filter
growth. Does a DISPLAY GlowFilter clip its output at Flash's applyFilter growth
ceil(PASS_SCALES[q-1] * blur / 2) per side (measured on the avm2/
bitmapdata_applyfilter_blur Flash capture), or at ruffle's calculate_dest_rect
PASS_SCALES[q-1] * blur (what tag.c / avm2_display.c size the cache by)?

Seven rows, each a 20x20 black square (PlaceObject3, AVM1) with a HORIZONTAL
GlowFilter(red, alpha 1, blurX 80, blurY 0, strength 255, quality q) for
q = 6..12. Strength 255 turns any floored blur level >= 1 into full red, so the
red run's width is the blur's visible tail: ~2.66 sigma = 2.66 * 80 *
sqrt(q / 12) px per side, i.e. 150 / 162 / 174 / 184 / 194 / 204 / 213 for
q = 6..12, against the applyFilter growth ceil(sc * 40) = 152 / 160 / 168 /
176 / 184 / 200 / 240. So q = 8, 9, 10 (and 7, marginally) show a CUT tail
if the applyFilter rule applies to display filters, and an uncut one if
ruffle's rule (twice as wide) does.

Usage: create_test_swf.py [out.swf]. output.expected.png is OUR render
(provisional) until the Flash capture replaces it.
"""
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


body = rectrec(0, 600 * 20, 0, 240 * 20) + struct.pack('<HH', 30 << 8, 1)
body += tag(69, struct.pack('<I', 0x00))          # FileAttributes: AS1/2
body += tag(9, b'\xff\xff\xff')
body += shape(1, 20, 20, (0, 0, 0))
for k, q in enumerate(range(6, 13)):
    glow = b'\x02' + bytes((255, 0, 0, 255)) + FX(80) + FX(0) + F8(255) + bytes([0x20 | q])
    body += place3(k + 1, 1, 290, 10 + 32 * k, 'q%d' % q, [glow])
body += tag(12, push(s('done')) + TRACE + STOP + b'\x00')
body += tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf'), 'wb').write(swf)
