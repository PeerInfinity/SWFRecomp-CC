#!/usr/bin/env python3
"""Build test.swf for regression/bitmap_pool_layer_cap.

WHAT THIS PINS DOWN
-------------------
render_webgpu.c keeps static bitmaps in 8 size-class texture arrays (pools).
Until the layer-cap slice, a static pool got ONE LAYER PER MEMBER with no cap,
so a movie with more than the device's `maxTextureArrayLayers` bitmaps in one
size class created an array over the limit. The texture is then invalid, so the
`fragment_sampler_bg` bind group is invalid, so every command buffer that binds
it is dropped: the movie keeps ticking and the canvas is BLACK. SwiftShader and
the WebGPU default limits grant 256 layers; real GPUs and lavapipe grant 2048,
which is why no native run ever saw it.

The fix plans pool membership against the device's real limits: a class that
would exceed them spills its largest members into the next larger pool.

THE SHAPE
---------
    test.swf  (AVM1, SWF8, hand-built, 400x320 stage, white background)
        300 DefineBitsLossless2 bitmaps, 2x2, one flat colour each
            -> size class 0 (max(w,h)+1 <= 64), cells of a 20x15 grid
        1 DefineBitsLossless2 bitmap, 100x1, flat colour
            -> size class 1, a strip under the grid (so the spill lands in a
               pool that already has a member, and grows its layer box)
        301 DefineShape rectangles, each filled with its own bitmap
            (repeating, non-smoothed, 0x42), placed at depths 1..301
        DoAction: trace("placed 301 bitmap shapes")

Every bitmap is a single flat colour, so nearest sampling and fill placement
are invisible and the comparison is exact at tolerance 0. Each cell has its
own colour, so a slot that names the wrong pool or layer shows as a wrong cell.

test.toml sets `[swfrecomp] gpu_max_texture_array_layers = 256`, which
verify_output.py turns into -DSWF_GPU_MAX_TEXTURE_ARRAY_LAYERS=256: the device
is requested with 256 layers (lavapipe would otherwise grant 2048) and the pool
planner honours it. 301 static bitmaps, 300 of them in class 0:

    before the fix   pool 0 = 300 layers > 256 -> invalid texture -> black
                     frame + a validation error per frame
    after            pool 0 = 256 layers, 44 spill into pool 1 (with the
                     strip), everything renders

The image comparison is graded under the knob, which is the point of the
test. (Image comparisons never gate trace pass/fail.)

Regenerate:  python3 create_test_swf.py
Golden:      ~/CC/ruffle/target/release/exporter test.swf output.expected.png \\
             -s -f 1 --skipframes 1
"""
import struct
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
T = 20   # twips per pixel

STAGE_W, STAGE_H = 400, 320
COLS, ROWS = 20, 15
CELL = 20                      # px
N_CELLS = COLS * ROWS          # 300 class-0 bitmaps
STRIP_W = 100                  # 100x1 -> class 1


class Bits:
    def __init__(self):
        self.acc = 0
        self.n = 0
        self.out = bytearray()

    def u(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.acc = (self.acc << 1) | ((val >> i) & 1)
            self.n += 1
            if self.n == 8:
                self.out.append(self.acc)
                self.acc = 0
                self.n = 0

    def s(self, val, bits):
        if val < 0:
            val = (1 << bits) + val
        self.u(val, bits)

    def bytes(self):
        if self.n:
            self.out.append(self.acc << (8 - self.n))
            self.acc = 0
            self.n = 0
        return bytes(self.out)


def sbits_needed(*vals):
    m = 1
    for v in vals:
        m = max(m, v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1)
    return m


def rect(xmin, xmax, ymin, ymax):
    nb = max(sbits_needed(v) for v in (xmin, xmax, ymin, ymax))
    b = Bits()
    b.u(nb, 5)
    for v in (xmin, xmax, ymin, ymax):
        b.s(v, nb)
    return b.bytes()


def tag(code, data):
    n = len(data)
    if n < 0x3F:
        return struct.pack('<H', (code << 6) | n) + data
    return struct.pack('<H', (code << 6) | 0x3F) + struct.pack('<I', n) + data


MATRIX_IDENTITY = bytes([0x00])


def matrix(sx, sy, tx, ty):
    """MATRIX with a scale (FIXED 16.16 each axis) and a twips translation."""
    b = Bits()
    fx = int(round(sx * 65536.0))
    fy = int(round(sy * 65536.0))
    nb = max(sbits_needed(fx, fy), 1)
    b.u(1, 1)            # HasScale
    b.u(nb, 5)
    b.s(fx, nb)
    b.s(fy, nb)
    b.u(0, 1)            # HasRotate
    ntb = max(sbits_needed(tx, ty), 1)
    b.u(ntb, 5)
    b.s(tx, ntb)
    b.s(ty, ntb)
    return b.bytes()


def lossless2(char_id, width, height, argb):
    """DefineBitsLossless2 (36), BitmapFormat 5 (32-bit ARGB), no colour table."""
    pixels = bytes(argb) * (width * height)
    body = (struct.pack('<HBHH', char_id, 5, width, height)
            + zlib.compress(pixels, 9))
    return tag(36, body)


def define_shape_bitmap(shape_id, x0, y0, x1, y1, bitmap_id, bm_w, bm_h):
    """DefineShape (tag 2): one rectangle filled with a REPEATING, non-smoothed
    bitmap fill (type 0x42), one bitmap stretched over the box. TWIPS."""
    body = bytearray()
    body += struct.pack('<H', shape_id)
    body += rect(x0, x1, y0, y1)
    body.append(1)                  # FillStyleCount = 1
    body.append(0x42)               # repeating, non-smoothed bitmap fill
    body += struct.pack('<H', bitmap_id)
    body += matrix((x1 - x0) / float(T) / bm_w, (y1 - y0) / float(T) / bm_h, x0, y0)
    body.append(0)                  # LineStyleCount = 0

    b = Bits()
    b.u(1, 4)                       # NumFillBits = 1
    b.u(0, 4)                       # NumLineBits = 0
    b.u(0, 1)                       # TypeFlag = 0 (non-edge)
    b.u(0, 1)                       # StateNewStyles
    b.u(0, 1)                       # StateLineStyle
    b.u(0, 1)                       # StateFillStyle1
    b.u(1, 1)                       # StateFillStyle0
    b.u(1, 1)                       # StateMoveTo
    nb = sbits_needed(x0, y0)
    b.u(nb, 5)
    b.s(x0, nb)
    b.s(y0, nb)
    b.u(1, 1)                       # FillStyle0 index = 1
    w, h = x1 - x0, y1 - y0
    for dx, dy in ((w, 0), (0, h), (-w, 0), (0, -h)):
        n2 = max(sbits_needed(dx, dy), 2)
        b.u(1, 1)                   # TypeFlag = 1 (edge)
        b.u(1, 1)                   # StraightFlag = 1
        b.u(n2 - 2, 4)              # NumBits
        b.u(1, 1)                   # GeneralLineFlag = 1
        b.s(dx, n2)
        b.s(dy, n2)
    b.u(0, 6)                       # EndShapeRecord
    body += b.bytes()
    return tag(2, bytes(body))


def place_object2(depth, char_id):
    body = bytearray()
    body.append(0x02 | 0x04)        # HasCharacter | HasMatrix
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += MATRIX_IDENTITY
    return tag(26, bytes(body))


def do_action_trace(text):
    s = text.encode('ascii') + b'\x00'
    push = bytes([0x96]) + struct.pack('<H', 1 + len(s)) + b'\x00' + s
    return tag(12, push + bytes([0x26, 0x00]))   # ActionTrace, End


def cell_argb(i):
    """Opaque, distinct per cell (column drives red, row green, index blue)."""
    col, row = i % COLS, i // COLS
    r = 30 + col * 11
    g = 30 + row * 15
    b = 40 + (i * 53) % 190
    return (0xFF, r, g, b)


def build(path):
    tags = b''
    tags += tag(9, bytes((255, 255, 255)))       # SetBackgroundColor white
    shapes = []
    for i in range(N_CELLS):
        bm_id, sh_id = 1 + i, 1001 + i
        col, row = i % COLS, i // COLS
        x0, y0 = col * CELL + 2, row * CELL + 2
        tags += lossless2(bm_id, 2, 2, cell_argb(i))
        tags += define_shape_bitmap(sh_id, x0 * T, y0 * T, (x0 + 16) * T,
                                    (y0 + 16) * T, bm_id, 2, 2)
        shapes.append(sh_id)
    strip_bm, strip_sh = 1 + N_CELLS, 1001 + N_CELLS
    tags += lossless2(strip_bm, STRIP_W, 1, (0xFF, 0x20, 0x20, 0x20))
    tags += define_shape_bitmap(strip_sh, 10 * T, 304 * T, 390 * T, 316 * T,
                                strip_bm, STRIP_W, 1)
    shapes.append(strip_sh)
    for depth, sh_id in enumerate(shapes, start=1):
        tags += place_object2(depth, sh_id)
    tags += do_action_trace('placed %d bitmap shapes' % len(shapes))
    tags += tag(1, b'')                          # ShowFrame
    tags += tag(1, b'')                          # ShowFrame (frame 2, same content)
    tags += tag(0, b'')                          # End

    stage = rect(0, STAGE_W * T, 0, STAGE_H * T)
    body = stage + struct.pack('<H', 30 << 8) + struct.pack('<H', 2) + tags
    data = b'FWS' + struct.pack('<BI', 8, 8 + len(body)) + body
    path.write_bytes(data)
    print('Created %s (%d bytes, %d bitmap shapes)' % (path, len(data), len(shapes)))


if __name__ == '__main__':
    build(HERE / 'test.swf')
