#!/usr/bin/env python3
"""avm1_jpeg3_alpha_bitmap: DefineBitsJPEG3 colour is PREMULTIPLIED by its alpha plane.

Pins (s26 w2-text-cx-jpeg3, acid-color-0 chain step 2): the recompiler
(SWFRecomp/src/swf.cpp, DefineBitsJPEG3/4 arm) emitted the JPEG's RGB as
STRAIGHT alpha, so the renderer premultiplied a second time and partially
transparent texels came out too dark. Flash (and Ruffle
render/src/utils.rs decode_define_bits_jpeg) treats the colour as
premultiplied and clamps each channel to alpha ("Flash Player clamps color to
the alpha value"), so a texel whose colour exceeds its alpha is clamped (an
a=0 texel with colour is invisible). Fixed by clamping + un-premultiplying at
emit.

Content (64x32 JPEG, quality 100, 4:4:4, flat rows so ringing is minimal):
  top half     premultiplied red, alpha ramp a = 4*x (x = column, 0..63),
               colour (a, 0, 0)        -> composite (a, 0, 255 - a) over blue
  bottom half  colour (255, 255, 255) with alpha = 0 on columns 0..31 (must
               be INVISIBLE: clamp) and alpha = 128 on columns 32..63
               (clamped to (128,128,128) premultiplied = 50 % white)
Drawn 1:1 with a CLIPPED, NON-SMOOTHED bitmap fill (fill type 0x43) at a
whole-pixel offset over a solid blue rectangle, so no sampling filter is
involved (premultiplied-vs-straight bilinear is a separate, unlanded step).

Expected PNG: Ruffle exporter (LOCAL ORACLE REQUEST in
SWFRecomp-CC-history:SWFRecompDocs/plans/session26-fanout-reports/w2-text-cx-jpeg3-report.md).
Needs Pillow to regenerate (JPEG encoder); the committed test.swf is the
source of truth.
"""
import io, pathlib, struct, zlib

from PIL import Image

HERE = pathlib.Path(__file__).resolve().parent
W, H = 64, 32


def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body


class BW:
    def __init__(s): s.bits = []
    def u(s, v, n):
        for i in range(n - 1, -1, -1): s.bits.append((v >> i) & 1)
    def sb(s, v, n): s.u(v & ((1 << n) - 1), n)
    def bytes(s):
        b = s.bits + [0] * ((-len(s.bits)) % 8)
        return bytes(int("".join(map(str, b[i:i + 8])), 2) for i in range(0, len(b), 8))


def nbits_s(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n - 1)) <= v < (1 << (n - 1))): n += 1
    return n


def rect(x0, x1, y0, y1):
    nb = nbits_s(x0, x1, y0, y1)
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()


def matrix(sx=None, tx=0, ty=0):
    w = BW()
    if sx is not None:
        w.u(1, 1); nb = nbits_s(sx); w.u(nb, 5); w.sb(sx, nb); w.sb(sx, nb)
    else:
        w.u(0, 1)
    w.u(0, 1)
    nb = nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()


def rect_shape(sid, x1, y1, fill):
    """DefineShape: one fill style, a closed 0..x1 x 0..y1 (twips) rectangle."""
    b = struct.pack("<H", sid) + rect(0, x1, 0, y1)
    b += bytes([1]) + fill + bytes([0])        # 1 fill style, 0 line styles
    w = BW()
    w.u(1, 4); w.u(0, 4)                       # NumFillBits=1 NumLineBits=0
    # TypeFlag 0, NewStyles 0, LineStyle 0, FillStyle1 0, FillStyle0 1, MoveTo 1
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)
    w.u(1, 5); w.sb(0, 1); w.sb(0, 1)          # MoveTo (0,0), 1-bit fields
    w.u(1, 1)                                  # FillStyle0 = 1
    def line(dx, dy):
        w.u(1, 1); w.u(1, 1)
        n = max(nbits_s(dx, dy), 2); w.u(n - 2, 4)
        w.u(0, 1)
        if dx != 0: w.u(0, 1); w.sb(dx, n)
        else: w.u(1, 1); w.sb(dy, n)
    line(x1, 0); line(0, y1); line(-x1, 0); line(0, -y1)
    w.u(0, 6)
    return tag(2, b + w.bytes())


def place2(depth, cid, tx, ty):
    return tag(26, bytes([0x02 | 0x04]) + struct.pack("<HH", depth, cid) + matrix(None, tx, ty))


def jpeg3(cid):
    img = Image.new("RGB", (W, H))
    alpha = bytearray(W * H)
    px = img.load()
    for y in range(H):
        for x in range(W):
            if y < H // 2:
                a = min(255, 4 * x)
                px[x, y] = (a, 0, 0)
            else:
                a = 0 if x < W // 2 else 128
                px[x, y] = (255, 255, 255)
            alpha[y * W + x] = a
    buf = io.BytesIO()
    img.save(buf, "JPEG", quality=100, subsampling=0)
    jpg = buf.getvalue()
    return tag(35, struct.pack("<HI", cid, len(jpg)) + jpg + zlib.compress(bytes(alpha), 9))


def build(path):
    tags = [tag(9, b"\xff\xff\xff")]
    tags.append(jpeg3(1))
    # blue background rectangle 0..120 x 0..60 px
    tags.append(rect_shape(2, 2400, 1200, bytes([0x00, 0, 0, 255])))
    # bitmap-filled 64x32 px rectangle: clipped non-smoothed fill, matrix
    # scale 20 (16.16 fixed) maps one bitmap pixel to 20 twips
    tags.append(rect_shape(3, W * 20, H * 20,
                           bytes([0x43]) + struct.pack("<H", 1) + matrix(20 << 16)))
    tags.append(place2(1, 2, 200, 200))
    tags.append(place2(2, 3, 400 + 200, 400 + 200))
    tags.append(tag(1, b""))
    tags.append(tag(0, b""))
    body = rect(0, 2800, 0, 1600) + struct.pack("<HH", 30 << 8, 1) + b"".join(tags)
    path.write_bytes(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(body)) + body)


if __name__ == "__main__":
    build(HERE / "test.swf")
    print("wrote", HERE / "test.swf")
