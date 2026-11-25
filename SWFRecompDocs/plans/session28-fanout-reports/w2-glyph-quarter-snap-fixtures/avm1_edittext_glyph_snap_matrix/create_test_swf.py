#!/usr/bin/env python3
"""avm1_edittext_glyph_snap_matrix (s28 w2-glyph-quarter-snap, FLASH request F2).

Pins where Flash Player 32 applies its 1/4-px glyph outline snap when the field has a
non-identity world matrix (tag.c textfield_glyph_render_cb's tf_mm arm, unsnapped today).
The square 'I' glyph of ../avm1_edittext_placed_cxform's font at FontHeight 200 twips has
fractional glyph-local coordinates (x 19.53..78.13, y -136.72..0 twips), so a glyph-local
snap (115 -> 135 twips tall) and a device-space snap give different pixels:
  depth 1  identity           at (200, 200)    control: the landed identity-arm snap
  depth 2  scale 2.0          at (1800, 200)
  depth 3  scale 0.5          at (4800, 200)
  depth 4  rotate 30 deg      at (600, 2200)
  depth 5  scale 1.37         at (3000, 2300)
Bordered EMBEDDED-font fields, text 'IIII', stage 300 x 200. Run from anywhere in the repo.
"""
import pathlib, struct, sys, math
HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE
while not (ROOT / 'ruffle-tests').is_dir(): ROOT = ROOT.parent
sys.path.insert(0, str(ROOT / 'ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform'))
import create_test_swf as base
def edittext(cid, fid, height, text):
    b = struct.pack("<H", cid) + base.rect(0, 1400, 0, 1100)
    b += bytes([0x80 | 0x04 | 0x01, 0x08 | 0x01 | 0x10 | 0x20])   # HasText|HasTextColor|HasFont; Border|UseOutlines|NoSelect|HasLayout
    b += struct.pack("<HH", fid, height) + bytes((0, 0, 0)) + b"\xff"
    b += bytes([0]) + struct.pack("<HHHh", 0, 0, 0, 0)
    b += base.s("") + base.s(text)
    return base.tag(37, b)
def matrix(a, b, c, d, tx, ty):
    w = base.BW()
    if a != 1 or d != 1:
        w.u(1, 1); A, D = int(round(a * 65536)), int(round(d * 65536))
        nb = base.nbits_s(A, D); w.u(nb, 5); w.sb(A, nb); w.sb(D, nb)
    else: w.u(0, 1)
    B, C = int(round(b * 65536)), int(round(c * 65536))
    if B or C:
        w.u(1, 1); nb = base.nbits_s(B, C); w.u(nb, 5); w.sb(B, nb); w.sb(C, nb)
    else: w.u(0, 1)
    nb = base.nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()
def place(depth, cid, m): return base.tag(26, bytes([0x06]) + struct.pack('<HH', depth, cid) + m)
r = math.radians(30)
tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1), edittext(5, 1, 200, 'IIII'),
        place(1, 5, matrix(1, 0, 0, 1, 200, 200)), place(2, 5, matrix(2, 0, 0, 2, 1800, 200)),
        place(3, 5, matrix(0.5, 0, 0, 0.5, 4800, 200)),
        place(4, 5, matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), 600, 2200)),
        place(5, 5, matrix(1.37, 0, 0, 1.37, 3000, 2300)), base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 6000, 0, 4000) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
