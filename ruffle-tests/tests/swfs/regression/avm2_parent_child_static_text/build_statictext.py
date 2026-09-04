#!/usr/bin/env python3
"""Splice a hand-authored DefineFont3 + DefineText + PlaceObject2 into an mxmlc SWF.

Parameterised twin of regression/avm2_static_text/build_statictext.py: the same
one-glyph font and two-glyph text record, but the glyph's CHARACTER CODE, the
text COLOUR and the pen X are given on the command line, so a parent and a
loaded child can each carry a static text that is distinguishable from the
other's. mxmlc does not readily emit a placed static DefineText from AS3, so the
font + text geometry is emitted as raw SWF tag bytes and spliced into frame 1 of
an mxmlc base.

The font (id 256) has ONE glyph: a filled square spanning the full EM box
[0,20480]x[0,20480] font units (em_square = 20480 for DefineFont3). The DefineText
(id 257) places that glyph TWICE in one record at text height 400 twips
(scale = 400/20480), colour --color, pen offset (--penx, 400) twips, with an
800-twip advance between the two glyphs. Exact-by-construction field-local rects
(px = twips/20, glyph square 0..20480 font units -> 0..400 twips = 20px), for
--penx P:
  glyph0: x [P/20, P/20+20]px      y [20,40]px
  glyph1: x [P/20+40, P/20+60]px   y [20,40]px   (pen P+800)
Placed at depth 1 (identity matrix) on the root.

usage: build_statictext.py IN.swf OUT.swf --code 65 --color ff0000 --penx 200
"""
import sys, zlib, struct


FONT_ID = 256   # 0x0100 — well above any mxmlc-assigned id
TEXT_ID = 257   # 0x0101
EM = 20480      # DefineFont3 EM square


# ---- bit writer (MSB-first, SWF convention) ------------------------------
class Bits:
    def __init__(self):
        self.acc = 0; self.n = 0; self.out = bytearray()
    def u(self, val, bits):
        for i in range(bits - 1, -1, -1):
            self.acc = (self.acc << 1) | ((val >> i) & 1); self.n += 1
            if self.n == 8:
                self.out.append(self.acc); self.acc = 0; self.n = 0
    def s(self, val, bits):
        if val < 0: val = (1 << bits) + val
        self.u(val, bits)
    def align(self):
        if self.n: self.out.append(self.acc << (8 - self.n)); self.acc = 0; self.n = 0
    def bytes(self):
        self.align(); return bytes(self.out)


def sbits_needed(*vals):
    m = 1
    for v in vals:
        b = v.bit_length() + 1 if v >= 0 else (~v).bit_length() + 1
        m = max(m, b)
    return m


def rect(xmin, xmax, ymin, ymax):
    nb = 0
    for v in (xmin, xmax, ymin, ymax):
        nb = max(nb, sbits_needed(v))
    b = Bits(); b.u(nb, 5)
    for v in (xmin, xmax, ymin, ymax): b.s(v, nb)
    return b.bytes()


def matrix_translate(tx, ty):
    b = Bits()
    b.u(0, 1)  # HasScale
    b.u(0, 1)  # HasRotate
    nb = sbits_needed(tx, ty)
    b.u(nb, 5); b.s(tx, nb); b.s(ty, nb)
    return b.bytes()


def tag(code, data):
    n = len(data)
    if n < 0x3f:
        return struct.pack('<H', (code << 6) | n) + data
    return struct.pack('<H', (code << 6) | 0x3f) + struct.pack('<I', n) + data


# ---- glyph SHAPE: a filled square [0,S]x[0,S], fill style 1 --------------
def glyph_square(S):
    b = Bits()
    b.u(1, 4)   # NumFillBits = 1
    b.u(0, 4)   # NumLineBits = 0
    # StyleChangeRecord: MoveTo(0,0) + FillStyle0 = 1
    b.u(0, 1)   # TypeFlag=0 (non-edge)
    b.u(0, 1)   # StateNewStyles
    b.u(0, 1)   # StateLineStyle
    b.u(0, 1)   # StateFillStyle1
    b.u(1, 1)   # StateFillStyle0
    b.u(1, 1)   # StateMoveTo
    b.u(sbits_needed(0), 5); b.s(0, sbits_needed(0)); b.s(0, sbits_needed(0))
    b.u(1, 1)   # FillStyle0 index = 1 (NumFillBits=1)
    # StraightEdgeRecords: (S,0) (0,S) (-S,0) (0,-S)
    for (dx, dy) in [(S, 0), (0, S), (-S, 0), (0, -S)]:
        nb = sbits_needed(dx, dy)
        if nb < 2: nb = 2
        b.u(1, 1)       # TypeFlag=1 (edge)
        b.u(1, 1)       # StraightFlag=1
        b.u(nb - 2, 4)  # NumBits
        b.u(1, 1)       # GeneralLineFlag=1
        b.s(dx, nb); b.s(dy, nb)
    b.u(0, 6)           # EndShapeRecord
    return b.bytes()


def define_font3(code):
    shape = glyph_square(EM)
    body = bytearray()
    body += struct.pack('<H', FONT_ID)
    body.append(0x08)          # FontFlags: WideOffsets (codes are wide for FONT3)
    body.append(0)             # LanguageCode
    body.append(0)             # FontNameLen (no name)
    body += struct.pack('<H', 1)  # NumGlyphs = 1
    # OffsetTable (1 x u32) + CodeTableOffset (u32) = 8 bytes header from offtab.
    glyph0_off = 8
    code_table_off = 8 + len(shape)
    body += struct.pack('<I', glyph0_off)
    body += struct.pack('<I', code_table_off)
    body += shape
    body += struct.pack('<H', code)  # CodeTable: glyph 0 -> the given char
    return tag(75, bytes(body))      # DefineFont3


def define_text(color, pen_x):
    GLYPH_BITS = 4
    ADV_BITS = 12
    body = bytearray()
    body += struct.pack('<H', TEXT_ID)
    # TextBounds: the two 400-twip glyph cells from the pen, plus a margin.
    body += rect(pen_x - 200, pen_x + 1400, 0, 1000)
    body += matrix_translate(0, 0)        # identity text matrix
    body.append(GLYPH_BITS)
    body.append(ADV_BITS)
    # One TEXTRECORD (StyleChange): font + colour + x/y offset, 2 glyphs.
    body.append(0x80 | 0x08 | 0x04 | 0x02 | 0x01)  # type=1, HasFont/Color/Y/X
    body += struct.pack('<H', FONT_ID)    # FontID
    body += bytes(((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF))
    body += struct.pack('<h', pen_x)      # XOffset twips
    body += struct.pack('<h', 400)        # YOffset twips (baseline)
    body += struct.pack('<H', 400)        # TextHeight twips (scale = 400/20480)
    body.append(2)                        # GlyphCount
    gb = Bits()
    gb.u(0, GLYPH_BITS); gb.s(800, ADV_BITS)  # glyph 0, advance 800 twips
    gb.u(0, GLYPH_BITS); gb.s(0, ADV_BITS)    # glyph 0, advance 0
    body += gb.bytes()
    body.append(0)                        # end-of-records
    return tag(11, bytes(body))           # DefineText


def place_object2(depth, char_id, tx, ty):
    flags = (1 << 2) | (1 << 1)  # HasMatrix | HasCharacter
    body = bytearray()
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    body += matrix_translate(tx, ty)
    return tag(26, bytes(body))


# ---- read base SWF, splice, write out ------------------------------------
def read_swf(path):
    raw = open(path, 'rb').read()
    sig = raw[:3]
    if sig == b'CWS':
        body = zlib.decompress(raw[8:])
    elif sig == b'FWS':
        body = raw[8:]
    else:
        raise SystemExit("unsupported SWF signature %r" % sig)
    return raw[3], body


def parse_after_header(body):
    nb = body[0] >> 3
    total_bits = 5 + 4 * nb
    rect_len = (total_bits + 7) // 8
    pos = rect_len + 2 + 2  # + FrameRate + FrameCount
    return body[:pos], pos


def iter_tags(body, pos):
    tags = []
    while pos < len(body):
        (rh,) = struct.unpack_from('<H', body, pos); pos += 2
        code = rh >> 6; length = rh & 0x3f
        if length == 0x3f:
            (length,) = struct.unpack_from('<I', body, pos); pos += 4
        data = body[pos:pos + length]; pos += length
        tags.append((code, data))
        if code == 0:
            break
    return tags


def parse_args(argv):
    inp, outp = argv[1], argv[2]
    opts = {'--code': '65', '--color': 'ff0000', '--penx': '200'}
    i = 3
    while i < len(argv):
        if argv[i] not in opts:
            raise SystemExit("unknown option %r" % argv[i])
        opts[argv[i]] = argv[i + 1]
        i += 2
    return inp, outp, int(opts['--code']), int(opts['--color'], 16), \
        int(opts['--penx'])


def main():
    inp, outp, code, color, pen_x = parse_args(sys.argv)
    version, body = read_swf(inp)
    header, pos = parse_after_header(body)
    tags = iter_tags(body, pos)

    new_tags = [define_font3(code), define_text(color, pen_x),
                place_object2(1, TEXT_ID, 0, 0)]

    out_tags = bytearray()
    inserted = False
    for (tcode, data) in tags:
        if tcode == 1 and not inserted:  # first ShowFrame — insert before it
            for nt in new_tags:
                out_tags += nt
            inserted = True
        out_tags += tag(tcode, data)
    if not inserted:
        raise SystemExit("no ShowFrame found in base SWF")

    new_body = header + bytes(out_tags)
    file_len = 8 + len(new_body)
    out = b'FWS' + bytes((version,)) + struct.pack('<I', file_len) + new_body
    open(outp, 'wb').write(out)
    print("font id=%d text id=%d code=%d color=%06x penx=%d, %d tags, %d bytes"
          % (FONT_ID, TEXT_ID, code, color, pen_x,
             len(tags) + len(new_tags), file_len))


if __name__ == '__main__':
    main()
