#!/usr/bin/env python3
"""regression/lowq_glyph_probe_df2 (+ _df3): Flash Player 32 LOW EditText glyph probe.

Pins the LOW text-field layout rules of s30 w2-lowq-land (tag.c tf_glyph_quarter_snap,
LOW arm): the field's translation snaps half-even, then each glyph pen rounds half-even
on its FIELD-LOCAL offset. Goldens = FP32 LNX LOW draw() captures (s30 w1-lowq-residues
FLASH request 1). Writes test.swf (this dir) and test_df3.swf: copy that one to
../lowq_glyph_probe_df3/test.swf (byte-identical to the shipped one).

s30 w1-lowq-residues: Flash LOW glyph-raster probe (FLASH request 1).

AVM1, SWF 8, 480x600, white. The frame-1 DoAction sets `_quality = "LOW"`, so a
direct pinned capture is LOW whatever the stub does.

The font is the embedded DefineFont2 of from_gnash/misc-ming.all/place_object_test
(Bitstream Vera Sans, the font of the three FP32 LOW goldens this rule was fitted
on: place_object_test, shape_test, morph_test1), copied byte for byte (re-id'd
to 1). It is a real gnash/Ming font that FP32 already draws (no synthetic-font
trap).

Fields: DefineEditText, UseOutlines, ReadOnly, NoSelect, no border, black,
NO CSMTextSettings (plain, non-FlashType), one line each:
  rows 0-3: 12 px text at field x = 10 + {0, .25, .5, .75} px  (pen rounding:
            the fit says half-UP to whole px; ties at .5 decide half-up vs -even)
  rows 4-9: the same string at 18 / 24 / 36 / 48 / 72 / 96 px at integer x
            (curve rule: the fit says quadratic edges draw as their CHORD at
            12 px, max curve deviation 0.34 px; the larger sizes bound the
            deviation threshold at which Flash starts subdividing)
Text: "aceosgb@&S 2369" (curve-heavy glyphs).

Second SWF, test_df3.swf (build_v3): the same idea with text_field_mask's DefineFont3.

Usage: python3 create_test_swf.py  (reads the corpus place_object_test SWF;
run download_tests.sh from_gnash first). Writes test.swf next to this file.
"""
import pathlib, struct, sys, zlib

HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parents[4]
SRC = REPO / 'ruffle-tests/tests/swfs/from_gnash/misc-ming.all/place_object_test/test.swf'
SRC3 = REPO / 'ruffle-tests/tests/swfs/visual/simple_shapes/text_field_mask/test.swf'
TEXT = 'aceosgb@&S 2369'


def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 0x3F, len(body)) + body


class Bits:
    def __init__(self): self.v, self.n = 0, 0
    def put(self, val, n):
        self.v = (self.v << n) | (val & ((1 << n) - 1)); self.n += n
    def bytes(self):
        pad = (-self.n) % 8
        return (self.v << pad).to_bytes((self.n + pad) // 8, 'big')


def nbits_s(*vals):
    n = 1
    for v in vals:
        n = max(n, (v if v >= 0 else ~v).bit_length() + 1)
    return n


def rect(x0, x1, y0, y1):
    n = nbits_s(x0, x1, y0, y1); b = Bits(); b.put(n, 5)
    for v in (x0, x1, y0, y1): b.put(v, n)
    return b.bytes()


def matrix_t(tx, ty):
    n = nbits_s(tx, ty); b = Bits(); b.put(0, 1); b.put(0, 1); b.put(n, 5); b.put(tx, n); b.put(ty, n)
    return b.bytes()


def font_tag(src=SRC, code=48, glyphs=None):
    d = src.read_bytes()
    d = d[:8] + zlib.decompress(d[8:]) if d[:3] == b'CWS' else d
    nb = d[8] >> 3; p = 8 + (5 + 4 * nb + 7) // 8 + 4
    while p < len(d):
        h = struct.unpack_from('<H', d, p)[0]; c, l = h >> 6, h & 63; p += 2
        if l == 63: l = struct.unpack_from('<I', d, p)[0]; p += 4
        if c == code:
            body = bytearray(d[p:p + l]); body[0:2] = struct.pack('<H', 1)
            return tag(code, bytes(body))
        p += l
    raise SystemExit('no font tag %d in %s' % (code, src))


def edit_text(cid, height_px, width_px):
    h = int(round(height_px * 20))
    body = struct.pack('<H', cid) + rect(0, width_px * 20, 0, int(height_px * 1.6 * 20) + 80)
    f1 = 0x80 | 0x08 | 0x04 | 0x01          # HasText ReadOnly HasTextColor HasFont
    f2 = 0x10 | 0x01                        # NoSelect UseOutlines
    body += bytes([f1, f2]) + struct.pack('<HH', 1, h) + bytes([0, 0, 0, 255])
    body += b'\x00' + TEXT.encode() + b'\x00'
    return tag(37, body)


def place(depth, cid, tx_px, ty_px):
    return tag(26, struct.pack('<BHH', 0x06, depth, cid) + matrix_t(int(round(tx_px * 20)), int(round(ty_px * 20))))


def do_quality_low():
    # ActionPush "_quality" "LOW"; ActionSetVariable; End
    s1, s2 = b'_quality\x00', b'LOW\x00'
    push = bytes([0x96]) + struct.pack('<H', 2 + len(s1) + len(s2)) + b'\x00' + s1 + b'\x00' + s2
    return tag(12, push + bytes([0x1D, 0x00]))


def build_v3():
    """test_df3.swf: text_field_mask's DefineFont3 (whose 'W' pens at x.5 FP32 rounds
    half-EVEN / down, 180.5 -> 180, where gnash's DefineFont2 'a' at 10.5 rounds UP).
    Plain (non-HTML) fields, text 'WWWWWWWW' at 64 px and 'WAWAWWAAWAWA' at 12 / 24 px (the font has only 'A' and 'W'), field
    x = 2 + {0, .25, .5, .75} px (W advance 59.5 px puts every other W on .5)."""
    global TEXT
    tags = tag(69, struct.pack('<I', 0)) + tag(9, bytes([255, 255, 255])) + do_quality_low() + font_tag(SRC3, 75)
    cid, depth, y = 10, 1, 4.0
    for txt, sz, fxs in (('WAWAWWAAWAWA', 12, (0.0, 0.25, 0.5, 0.75)), ('WAWAWWAAWAWA', 24, (0.0, 0.5)),
                         ('WWWWWWWW', 64, (0.0, 0.25, 0.5, 0.75))):
        for fx in fxs:
            TEXT = txt
            tags += edit_text(cid, sz, 470) + place(depth, cid, 2 + fx, y); cid += 1; depth += 1; y += sz * 1.25 + 2
    tags += tag(1, b'') + tag(0, b'')
    body = rect(0, 480 * 20, 0, 600 * 20) + struct.pack('<HH', 30 << 8, 1) + tags
    swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
    (HERE / 'test_df3.swf').write_bytes(swf)
    print('wrote', HERE / 'test_df3.swf', len(swf), 'bytes; last row y', y)


def build():
    tags = tag(69, struct.pack('<I', 0)) + tag(9, bytes([255, 255, 255])) + do_quality_low() + font_tag()
    cid, depth, y = 10, 1, 4.0
    for fx in (0.0, 0.25, 0.5, 0.75):
        tags += edit_text(cid, 12, 300) + place(depth, cid, 10 + fx, y); cid += 1; depth += 1; y += 20
    for sz in (18, 24, 36, 48, 72, 96):
        w = 470
        tags += edit_text(cid, sz, w) + place(depth, cid, 5, y); cid += 1; depth += 1; y += sz * 1.25 + 2
        if y > 600: break
    tags += tag(1, b'') + tag(0, b'')
    body = rect(0, 480 * 20, 0, 600 * 20)[0:] + struct.pack('<HH', 30 << 8, 1) + tags
    swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
    (HERE / 'test.swf').write_bytes(swf)
    print('wrote', HERE / 'test.swf', len(swf), 'bytes; last row y', y)


if __name__ == '__main__':
    build()
    build_v3()
