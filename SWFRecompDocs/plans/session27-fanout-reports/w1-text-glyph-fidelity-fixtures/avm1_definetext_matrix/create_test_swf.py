#!/usr/bin/env python3
"""avm1_definetext_matrix: DefineText's own TextMatrix scales/rotates its glyphs.

s27 w1-text-glyph-fidelity item 2. Ruffle text.rs render_self pushes
`text_transform` and then, per glyph, Matrix{a=d=height/em, tx/ty=pen}, so a
glyph's matrix is TextMatrix * glyph. The AVM1 recompiler (swf.cpp DefineText)
emitted {a=d=height/em, b/c = TextMatrix b/c unscaled, tx = T.tx + pen}: the
TextMatrix scale is overwritten, its rotation is not applied to the glyph
scale nor to the pen. (The AVM2 arm, abc_timeline.cpp parseDefineText, keeps
only the translation.)

Square-glyph DefineFont2 of ../avm1_edittext_placed_cxform ('I' = x 100..400,
y -700..0 em units, 1024 em). Three DefineTexts, "II" at height 1024 (1 em
unit = 1 twip), black, placed at identity:
  char 20  TextMatrix scale (2, 1),  translate (200, 1000)
  char 21  TextMatrix rotate +90 deg (a=0 b=1 c=-1 d=0), translate (2600, 400)
  char 22  TextMatrix identity, translate (200, 2400)   (control)
Expected (exact pixel-aligned squares, stage px):
  char 20: glyphs x 20..50 and 70..100, y 15..50
  char 21: glyphs (x' = -y, y' = x): x 130..165, y 25..40 and 50..65
  char 22: glyphs x 15..30 and 40..55, y 85..120
"""
import pathlib, struct, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'avm1_edittext_placed_cxform'))   # valid once landed in regression/
import create_test_swf as base   # noqa

def matrix(a, b, c, d, tx, ty):
    w = base.BW()
    A, B, C, D = (int(round(v * 65536)) for v in (a, b, c, d))
    if (A, D) != (65536, 65536):
        w.u(1, 1); nb = base.nbits_s(A, D); w.u(nb, 5); w.sb(A, nb); w.sb(D, nb)
    else:
        w.u(0, 1)
    if B or C:
        w.u(1, 1); nb = base.nbits_s(B, C); w.u(nb, 5); w.sb(B, nb); w.sb(C, nb)
    else:
        w.u(0, 1)
    nb = base.nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()

def definetext(cid, m):
    b = struct.pack('<H', cid) + base.rect(-2000, 2000, -2000, 2000) + m
    b += bytes([1, 10])                          # GlyphBits 1, AdvanceBits 10
    b += bytes([0x80 | 0x08 | 0x04]) + struct.pack('<H', 1) + bytes([0, 0, 0])
    b += struct.pack('<H', 1024) + bytes([2])    # height, 2 glyphs
    w = base.BW()
    for _ in range(2):
        w.u(0, 1); w.sb(500, 10)
    b += w.bytes() + bytes([0])
    return base.tag(11, b)

def place(depth, cid):
    return base.tag(26, bytes([0x06]) + struct.pack('<HH', depth, cid) + matrix(1, 0, 0, 1, 0, 0))

tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1),
        definetext(20, matrix(2, 0, 0, 1, 200, 1000)),
        definetext(21, matrix(0, 1, -1, 0, 2600, 400)),
        definetext(22, matrix(1, 0, 0, 1, 200, 2400)),
        place(1, 20), place(2, 21), place(3, 22),
        base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 4000, 0, 3000) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
