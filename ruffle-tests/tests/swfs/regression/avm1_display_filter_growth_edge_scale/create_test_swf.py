#!/usr/bin/env python3
"""FLASH IMAGE ORACLE PROBE (s28 w1-filter-residuals): display-object filter
growth near the stage edge and under scale (prices the GPU display-filter
growth NO-GO of record, s27 w2b-filter-kernels-residual task 3).

AVM1 (SWF 8, PlaceObject3 filters, no script), 400x300 white stage, 1 frame:
  A  depth 1: black 40x40 at x=-20..20, y=20 (HALF OFF the LEFT edge),
     GlowFilter red, blur 16x16, strength 2, quality 2.
     -> does the off-stage half glow onto the stage (cache rect not clipped
        to the stage), and how far does the halo reach (2.1*16 vs 2.1*16/2)?
  B  depth 2: black 40x40 at x=380..420, y=20 (HALF OFF the RIGHT edge),
     DropShadow blue, blur 8x8, angle 180 deg, distance 30, strength 1, q 1.
     -> the shadow is thrown back onto the stage from the off-stage half
        (from_shumway/acid/acid-filter class).
  C  depth 3: black 20x20 placed at (60,100) with matrix scale 3 (60x60),
     GlowFilter green, blur 10x10, strength 1, quality 1.
     -> is the blur in stage px (Flash: object scale does not scale filters)?
  D  depth 4: black 20x20 at (220,100), scale 3, DropShadow black blur 6x6,
     angle 45, distance 10, strength 1, quality 2 (offset 7.07 px: also the
     fractional-offset rule of w2b_shadow_shape_a50, under scale).
  E  depth 5: sprite (matrix scale 2) holding a 15x15 black square with
     GlowFilter red blur 8x8, strength 1, q 1, sprite at (40,200) -> (40..70).
     -> a PARENT scale on a filtered child.
  F  depth 6: black 10x10 at (180,250), GlowFilter red blurX 60 blurY 0,
     strength 255, quality 9: a horizontal TAIL-LENGTH readout (strength 255
     paints every blur level >= 1 full red). Flash's floored 9-pass box chain
     predicts a tail of 98 px beyond each edge (x = 82 .. 287); ours renders
     101 (79 .. 290). NOTE: under the floored box chain the tail can never
     reach the applyFilter growth ceil(4.4*60/2) = 132, so this row measures
     kernel taps, not a clip; a clip is not observable on an unscaled object.
GOLDEN (s28 w2-filter-residuals-land): output.expected.png is the FP32 LNX
capture. Graded per case: A halo reaches x = 0 in both (levels +-4); B the
thrown-back shadow matches in extent (interior alpha 253 ours vs 255 Flash);
C and E exact (filters are in stage px: object and parent scale do not scale
the blur); D the fractional-offset shadow (bilinear) residual is blur levels
only (max 4); F Flash x = 82..287 == the floored 9-pass box-chain prediction,
ours 79..291. test.toml budgets the residual.
Usage: create_test_swf.py [out.swf]
"""
import math, os, struct, sys

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
def matrix(tx, ty, sc=None):
    b = Bits()
    if sc is not None:
        b.u(1, 1); A = int(sc * 65536); n = nbits(A, A); b.u(n, 5); b.u(A, n); b.u(A, n)
    else: b.u(0, 1)
    b.u(0, 1); n = nbits(tx, ty); b.u(n, 5); b.u(tx, n); b.u(ty, n)
    return b.bytes()
def shape(cid, w, h):
    W, H = w * 20, h * 20
    body = struct.pack('<H', cid) + rectrec(0, W, 0, H) + b'\x01\x00\x00\x00\x00\x00'
    b = Bits(); b.u(1, 4); b.u(0, 4)
    b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1, 1); b.u(1, 1)
    n = nbits(0, 0); b.u(n, 5); b.u(0, n); b.u(0, n); b.u(1, 1)
    for dx, dy in [(W, 0), (0, H), (-W, 0), (0, -H)]:
        n = max(nbits(dx, dy), 2); b.u(1, 1); b.u(1, 1); b.u(n - 2, 4)
        if dx == 0: b.u(0, 1); b.u(1, 1); b.u(dy, n)
        else: b.u(0, 1); b.u(0, 1); b.u(dx, n)
    b.u(0, 6)
    return tag(2, body + b.bytes())
FX = lambda v: struct.pack('<i', int(round(v * 65536)))
F8 = lambda v: struct.pack('<H', int(round(v * 256)))
def glow(rgba, bx, by, st, q):
    return b'\x02' + bytes(rgba) + FX(bx) + FX(by) + F8(st) + bytes([0x20 | q])
def shadow(rgba, bx, by, ang_deg, dist, st, q):
    return (b'\x00' + bytes(rgba) + FX(bx) + FX(by) + FX(math.radians(ang_deg)) + FX(dist)
            + F8(st) + bytes([0x20 | q]))
def place3(depth, cid, x, y, sc=None, filters=None):
    f1 = 0x02 | 0x04
    f2 = 0x01 if filters else 0
    body = bytes([f1, f2]) + struct.pack('<HH', depth, cid) + matrix(int(x * 20), int(y * 20), sc)
    if filters: body += bytes([len(filters)]) + b''.join(filters)
    return tag(70, body)
def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + b''.join(tags) + tag(1, b'') + tag(0, b''))

RED, BLUE, GREEN, BLACK = (255, 0, 0, 255), (0, 0, 255, 255), (0, 255, 0, 255), (0, 0, 0, 255)
tags = [tag(69, struct.pack('<I', 0)), tag(9, b'\xff\xff\xff'),
        shape(1, 40, 40), shape(2, 20, 20), shape(3, 15, 15), shape(4, 10, 10),
        sprite(10, [place3(1, 3, 0, 0, filters=[glow(RED, 8, 8, 1, 1)])])]
tags += [
    place3(1, 1, -20, 20, filters=[glow(RED, 16, 16, 2, 2)]),                       # A
    place3(2, 1, 380, 20, filters=[shadow(BLUE, 8, 8, 180, 30, 1, 1)]),             # B
    place3(3, 2, 60, 100, sc=3, filters=[glow(GREEN, 10, 10, 1, 1)]),               # C
    place3(4, 2, 220, 100, sc=3, filters=[shadow(BLACK, 6, 6, 45, 10, 1, 2)]),      # D
    place3(5, 10, 40, 200, sc=2),                                                   # E
    place3(6, 4, 180, 250, filters=[glow(RED, 60, 0, 255, 9)]),                     # F
]
body = rectrec(0, 400 * 20, 0, 300 * 20) + struct.pack('<BBH', 0, 30, 1) + b''.join(tags) + tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf')
open(out, 'wb').write(swf); print('wrote', out)
