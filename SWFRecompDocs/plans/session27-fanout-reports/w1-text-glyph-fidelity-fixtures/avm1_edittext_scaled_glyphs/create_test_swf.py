#!/usr/bin/env python3
"""avm1_edittext_scaled_glyphs: a scaled/rotated timeline EditText scales its glyph run.

s27 w1-text-glyph-fidelity item 1. actionIterateTextFieldGlyphs (action.c)
composes only parent TRANSLATIONS ("scale/rotation composition is deferred"),
and TextFieldGlyphInfo carries no matrix, so tag.c textfield_glyph_render_cb
draws the glyphs of a scaled field at scale 1 while the box (TextFieldRenderInfo
m_a..m_ty) is scaled: the text spills out of / shrinks inside its border.
Ruffle: world * layout_to_local * translate(lbox origin) * glyph(a=d=height/em),
each Matrix*Matrix rounding the rhs translation to whole twips.

Square-glyph DefineFont2 of ../avm1_edittext_placed_cxform (one 'I' = x 100..400,
y -700..0 em units, FontHeight 1024 twips = 1 em unit per twip), black "II",
bordered, at three placements:
  depth 1  scale 2       at (200, 200)
  depth 2  scale 0.5     at (3000, 200)
  depth 3  scale (1.5, 1) at (200, 2600)
Golden: Ruffle exporter (LOCAL ORACLE REQUEST).
"""
import pathlib, struct, sys
HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parent / 'avm1_edittext_placed_cxform'   # valid once landed in regression/
sys.path.insert(0, str(REPO))
import create_test_swf as base   # noqa  (font2, edittext, tag, BW, nbits_s, rect)

def matrix(sx, sy, tx, ty):
    w = base.BW(); w.u(1, 1)
    a, d = int(round(sx * 65536)), int(round(sy * 65536))
    nb = base.nbits_s(a, d); w.u(nb, 5); w.sb(a, nb); w.sb(d, nb)
    w.u(0, 1)
    nb = base.nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()

def place(depth, cid, m):
    return base.tag(26, bytes([0x06]) + struct.pack('<HH', depth, cid) + m)

tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1), base.edittext(5, 1, (0, 0, 0), 'II'),
        place(1, 5, matrix(2, 2, 200, 200)),
        place(2, 5, matrix(0.5, 0.5, 3000, 200)),
        place(3, 5, matrix(1.5, 1, 200, 2600)),
        base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 4000, 0, 4000) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
