#!/usr/bin/env python3
"""Build test.swf for regression/avm1_bitmap_nearest_tie_stage.

GOLDEN: output.expected.png is Flash Player 32's own render (LNX 32,0,0,465,
AS3 draw() wrapper of the stage, coordinator-run s27; archived at
SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/
w2-jpeg-flash-decode/avm1_bitmap_nearest_tie_stage/flash.png). It equals the
ties-UP prediction at 0 px (ties-down: 80 px). Fixed by s27 w2b-jpeg-refine:
render_webgpu.c bitmap_nearest_clamp / bitmap_nearest_repeat (textureLoad of
floor(coord + NEAREST_TIE)); before it, lavapipe's Nearest sampler resolved
the ties neither way (52 px off the Flash golden).

WHAT THIS PINS DOWN (s27 w2-jpeg-flash-decode, brief item 3)
-------------------------------------------------------------
The nearest-sampling TIE rule of a NON-SMOOTHED clipped bitmap fill (0x43)
drawn ON STAGE (the GPU path, render_webgpu.c's Nearest sampler), at a scale
of exactly 1.5. With pixel centres at (i + 0.5), the texel coordinate
    t = (i + 0.5 - offset) / 1.5
is an exact integer on every third pixel (i - offset = 1, 4, 7, ...).
  * ties UP   (floor(t))           : Flash's rule on the CPU draw() path,
                                     measured on avm2/pixelbender_dithering
                                     (s27 w1-drift, d3b6d71b8).
  * ties DOWN (floor(t - epsilon)) : Ruffle's GPU sampler (the old s26 rule).
The bitmap is lossless (no JPEG decode in the loop) and every texel has a
unique colour, so each tie row/column is visible.

Stage 40x40 px, white. Bitmap 8x8 ARGB, texel (c, r) = (32*c, 32*r, 0x80).
Shape: 12x12 px square at (8, 8) px, fill matrix scale 1.5 (both axes),
translate (8, 8) px, fill type 0x43 (clipped, non-smoothed).
predict_*.png next to this file are the two candidate rules' renders.

Regenerate:  python3 create_test_swf.py   (writes test.swf + predict_*.png)
"""
import struct
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
T = 20
STAGE = 40
OFF = 8            # px
SCALE = 1.5
BW = BH = 8


class Bits:
    def __init__(self):
        self.acc = 0; self.n = 0; self.out = bytearray()
    def u(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.acc = (self.acc << 1) | ((val >> i) & 1); self.n += 1
            if self.n == 8:
                self.out.append(self.acc); self.acc = 0; self.n = 0
    def s(self, val, bits):
        self.u(val + (1 << bits) if val < 0 else val, bits)
    def bytes(self):
        if self.n:
            self.out.append(self.acc << (8 - self.n)); self.acc = 0; self.n = 0
        return bytes(self.out)


def nbits(*vals):
    m = 1
    for v in vals:
        m = max(m, v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1)
    return m


def rect(x0, x1, y0, y1):
    nb = nbits(x0, x1, y0, y1); b = Bits(); b.u(nb, 5)
    for v in (x0, x1, y0, y1): b.s(v, nb)
    return b.bytes()


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<H', (code << 6) | 0x3F) + struct.pack('<I', len(data)) + data


def matrix(scale, tx, ty):
    b = Bits(); fx = int(round(scale * 65536.0)); nb = nbits(fx)
    b.u(1, 1); b.u(nb, 5); b.s(fx, nb); b.s(fx, nb)
    b.u(0, 1)
    nt = nbits(tx, ty); b.u(nt, 5); b.s(tx, nt); b.s(ty, nt)
    return b.bytes()


def texel(c, r):
    return (32 * c, 32 * r, 0x80)


def lossless2(cid):
    px = bytearray()
    for r in range(BH):
        for c in range(BW):
            R, G, B = texel(c, r)
            px += bytes((0xFF, R, G, B))          # ARGB
    return tag(36, struct.pack('<HBHH', cid, 5, BW, BH) + zlib.compress(bytes(px), 9))


def shape(sid, bid):
    x0 = y0 = OFF * T
    x1 = y1 = (OFF + int(BW * SCALE)) * T
    body = bytearray(struct.pack('<H', sid)) + rect(x0, x1, y0, y1)
    body += bytes((1, 0x43)) + struct.pack('<H', bid) + matrix(SCALE * T, x0, y0)
    body.append(0)
    b = Bits(); b.u(1, 4); b.u(0, 4)
    b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1, 1); b.u(1, 1)
    nb = nbits(x0, y0); b.u(nb, 5); b.s(x0, nb); b.s(y0, nb); b.u(1, 1)
    w = x1 - x0
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        n2 = max(nbits(dx, dy), 2)
        b.u(1, 1); b.u(1, 1); b.u(n2 - 2, 4); b.u(1, 1); b.s(dx, n2); b.s(dy, n2)
    b.u(0, 6)
    return tag(2, bytes(body + b.bytes()))


def place(depth, cid):
    return tag(26, bytes((0x06,)) + struct.pack('<HH', depth, cid) + b'\x00')


def do_action_trace(msg):
    s = msg.encode() + b'\x00'
    acts = bytes((0x96,)) + struct.pack('<H', len(s) + 1) + b'\x00' + s + bytes((0x26, 0x07, 0x00))
    return tag(12, acts)


def build():
    body = rect(0, STAGE * T, 0, STAGE * T) + struct.pack('<HH', 30 << 8, 1)
    body += tag(9, bytes((0xFF, 0xFF, 0xFF)))
    body += lossless2(1) + shape(2, 1) + place(1, 2)
    body += do_action_trace('done') + tag(1, b'') + tag(0, b'')
    data = b'FWS' + bytes((8,)) + struct.pack('<I', 8 + len(body)) + body
    (HERE / 'test.swf').write_bytes(data)


def predict(rule):
    from PIL import Image
    eps = 1e-6 if rule == 'up' else -1e-6
    im = Image.new('RGB', (STAGE, STAGE), (255, 255, 255))
    n = int(BW * SCALE)
    import math
    for y in range(OFF, OFF + n):
        for x in range(OFF, OFF + n):
            u = math.floor((x + 0.5 - OFF) / SCALE + eps)
            v = math.floor((y + 0.5 - OFF) / SCALE + eps)
            im.putpixel((x, y), texel(u, v))
    im.save(HERE / f'predict_ties_{rule}.png')


if __name__ == '__main__':
    build()
    for r in ('up', 'down'):
        predict(r)
    (HERE / 'output.txt').write_text('done\n')
    (HERE / 'test.toml').write_text('num_frames = 1\n\n[image_comparisons.output]\ntolerance = 0\nmax_outliers = 0\n')
