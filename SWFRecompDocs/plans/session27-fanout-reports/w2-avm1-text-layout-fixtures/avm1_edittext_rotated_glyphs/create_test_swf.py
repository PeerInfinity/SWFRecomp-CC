#!/usr/bin/env python3
"""avm1_edittext_rotated_glyphs: a rotated / sheared timeline EditText rotates its glyph run.

s27 w2-avm1-text-layout (companion of avm1_edittext_scaled_glyphs). Before the
fix the AVM1 glyph run was translation-only (TextFieldGlyphInfo had no matrix),
so the glyphs drew upright and unscaled while the box rotated. Same square-glyph
"II" embedded-font bordered field as ../avm1_edittext_placed_cxform, placed:
  depth 1  rotate +90deg      at (1400, 200)
  depth 2  rotate +30deg      at (2200, 600)
  depth 3  shear  c = 0.5     at (200, 2600)
Golden: FLASH (LOCAL ORACLE REQUEST, s27 w2-avm1-text-layout). Embedded-font
text is not culled under rotation (only device text is).
"""
import pathlib, struct, sys, math
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / 'avm1_edittext_placed_cxform'))
import create_test_swf as base
def matrix(a, b, c, d, tx, ty):
    w = base.BW(); w.u(1, 1)
    A, D = int(round(a * 65536)), int(round(d * 65536))
    nb = base.nbits_s(A, D); w.u(nb, 5); w.sb(A, nb); w.sb(D, nb)
    B, C = int(round(b * 65536)), int(round(c * 65536))
    if B or C:
        w.u(1, 1); nb = base.nbits_s(B, C); w.u(nb, 5); w.sb(B, nb); w.sb(C, nb)
    else: w.u(0, 1)
    nb = base.nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()
def place(depth, cid, m):
    return base.tag(26, bytes([0x06]) + struct.pack('<HH', depth, cid) + m)
r = math.radians(30)
tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1), base.edittext(5, 1, (0, 0, 0), 'II'),
        place(1, 5, matrix(0, 1, -1, 0, 1400, 200)),
        place(2, 5, matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), 2200, 600)),
        place(3, 5, matrix(1, 0, 0.5, 1, 200, 2600)),
        base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 4000, 0, 4000) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
