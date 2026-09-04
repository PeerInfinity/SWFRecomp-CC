#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_bitmap_fill.

WHAT THIS PINS DOWN
-------------------
The PIXEL half of the multi-SWF render slice: a loaded child's static bitmap
reaching the GPU, and its shape's fill style naming the right slot.

Two independent movie-local indices have to move together for a child's
bitmap-filled shape to draw:

  * the static bitmap SLOT. `render_webgpu_upload_bitmap` numbers slots from a
    single cursor and `build_static_bitmap_pools` dimensions the size-class
    texture pools ONCE, at the root's `finalizeBitmaps()` -- which runs at the
    end of the root's tagInit, long before a child's `defineBitmap` arrives at
    loadMovie time. Both gates were measured shut on
    regression/avm1_parent_child_bitmap. The fix declares every linked movie's
    bitmaps from static descriptors (`bitmap_descs` in draws.c) before the
    pools are built.
  * the fill style's baked index. `((uninv & 0xFFFF) << 16) | bitmap_id` is
    written into the VERTEX at recompile time (SWFRecomp/src/swf.cpp
    parseFillStyles), so no draw-time argument can reach it; the combined
    vertex table re-bases the style word as it copies each movie's vertices.

There is NO trace-visible assertion for either: every AS-visible read of a
child bitmap goes through the metadata tables (fixed in earlier slices), so
nothing in ActionScript can observe the renderer's slot table. This test is
graded by [image_comparisons.output] against a Ruffle golden, and its trace
output only proves the movie ran.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + spliced tags, 200x200 stage)
        4x4 RED  bitmap -> shape, px (20,120)-(80,180)   <- CONTROL
        holder          createEmptyMovieClip, loadMovie("child.swf")
    child.swf        (AVM1, SWF6, hand-built, 200x200 stage)
        2x2 BLUE bitmap -> shape, px (120,120)-(180,180) <- DISCRIMINATOR

Both movies hold exactly ONE bitmap and ONE shape, so both name slot 0 and
vertex 0 of their own arrays -- the collision that makes a wrong-array read
land on real, in-bounds data instead of on garbage. Every bitmap is a single
FLAT colour, so nearest-vs-linear sampling and any sub-pixel fill placement are
invisible and the comparison is exact at tolerance 0; the fills repeat rather
than clamp for the same reason.

    master   red square only, blue square absent
    fixed    red AND blue

Regenerate:  python3 create_test_swf.py
Golden:      RUFFLE_LOCAL_FETCH_DIR=<dir with armorgames.com/child.swf> \\
             ~/CC/ruffle/target/release/exporter test.swf output.expected.png \\
             -s -f 1 --skipframes 5 --trace-log output.txt
"""
import struct
import subprocess
import sys
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
T = 20   # twips per pixel


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


def matrix(scale, tx, ty):
    """MATRIX with a uniform scale (FIXED 16.16) and a twips translation."""
    b = Bits()
    fx = int(round(scale * 65536.0))
    nb = max(sbits_needed(fx), 1)
    b.u(1, 1)            # HasScale
    b.u(nb, 5)
    b.s(fx, nb)
    b.s(fx, nb)
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


def define_shape_bitmap(shape_id, x0, y0, x1, y1, bitmap_id, bitmap_px):
    """DefineShape (tag 2): one rectangle filled with a REPEATING, non-smoothed
    bitmap fill (type 0x42). Coordinates in TWIPS; bitmap_px is the bitmap's
    width in pixels, used to scale one bitmap pixel onto the box."""
    box_px = (x1 - x0) / float(T)
    body = bytearray()
    body += struct.pack('<H', shape_id)
    body += rect(x0, x1, y0, y1)
    body.append(1)                  # FillStyleCount = 1
    body.append(0x42)               # repeating, non-smoothed bitmap fill
    body += struct.pack('<H', bitmap_id)
    body += matrix(box_px / float(bitmap_px), x0, y0)
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


def place_object2(depth, char_id, name=None):
    flags = 0x02 | 0x04             # HasCharacter | HasMatrix
    if name:
        flags |= 0x20               # HasName
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += MATRIX_IDENTITY
    if name:
        body += name.encode('ascii') + b'\x00'
    return tag(26, bytes(body))


# ---- child.swf ----------------------------------------------------------

CHILD_BITMAP_ID = 1
CHILD_SHAPE_ID = 2
CHILD_BM_W = 2
CHILD_ARGB = (0xFF, 0x00, 0x00, 0xFF)   # opaque blue
CHILD_BOX = (120, 120, 180, 180)        # px


def build_child(path):
    x0, y0, x1, y1 = CHILD_BOX
    tags = b''
    tags += lossless2(CHILD_BITMAP_ID, CHILD_BM_W, CHILD_BM_W, CHILD_ARGB)
    tags += define_shape_bitmap(CHILD_SHAPE_ID, x0 * T, y0 * T, x1 * T, y1 * T,
                                CHILD_BITMAP_ID, CHILD_BM_W)
    # Depth 3, not 1: our runtime still shares ONE display list between a
    # parent and a loaded child (the Route 1 sub-arc), so a child placing at
    # the parent's depth 1 is dropped outright.
    tags += place_object2(3, CHILD_SHAPE_ID, name='sub')
    tags += tag(1, b'')                     # ShowFrame
    tags += tag(0, b'')                     # End

    stage = rect(0, 200 * T, 0, 200 * T)
    body = stage + struct.pack('<H', 24 << 8) + struct.pack('<H', 1) + tags
    data = b'FWS' + struct.pack('<BI', 6, 8 + len(body)) + body
    path.write_bytes(data)
    print('Created %s (%d bytes, blue bitmap fill %s)' % (path, len(data), CHILD_BOX))


# ---- test.swf (MTASC + spliced tags) ------------------------------------

PARENT_BITMAP_ID = 900
PARENT_SHAPE_ID = 901
PARENT_BM_W = 4
PARENT_ARGB = (0xFF, 0xFF, 0x00, 0x00)  # opaque red
PARENT_BOX = (20, 120, 80, 180)         # px


def read_swf(path):
    raw = path.read_bytes()
    sig, version = raw[:3], raw[3]
    body = raw[8:]
    if sig == b'CWS':
        body = zlib.decompress(body)
    elif sig != b'FWS':
        raise SystemExit('%s: unsupported signature %r' % (path, sig))
    nbits = body[0] >> 3
    rect_len = (5 + 4 * nbits + 7) // 8
    return version, body[:rect_len + 4], body[rect_len + 4:]


def splice_before_first_showframe(path, extra):
    version, prefix, tag_bytes = read_swf(path)
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        hdr = 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos + 2:pos + 6])[0]
            hdr = 6
        if code == 1:
            break
        if code == 0:
            raise SystemExit('%s: no ShowFrame tag' % path)
        pos += hdr + length
    else:
        raise SystemExit('%s: ran off the end looking for ShowFrame' % path)
    body = prefix + tag_bytes[:pos] + extra + tag_bytes[pos:]
    path.write_bytes(b'FWS' + struct.pack('<BI', version, 8 + len(body)) + body)


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:200:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)

    x0, y0, x1, y1 = PARENT_BOX
    extra = b''
    extra += tag(9, bytes((255, 255, 255)))      # SetBackgroundColor white
    extra += lossless2(PARENT_BITMAP_ID, PARENT_BM_W, PARENT_BM_W, PARENT_ARGB)
    extra += define_shape_bitmap(PARENT_SHAPE_ID, x0 * T, y0 * T, x1 * T, y1 * T,
                                 PARENT_BITMAP_ID, PARENT_BM_W)
    extra += place_object2(1, PARENT_SHAPE_ID, name='ctl')
    splice_before_first_showframe(path, extra)
    print('Created %s (%d bytes, red bitmap fill %s spliced in)'
          % (path, path.stat().st_size, PARENT_BOX))


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
