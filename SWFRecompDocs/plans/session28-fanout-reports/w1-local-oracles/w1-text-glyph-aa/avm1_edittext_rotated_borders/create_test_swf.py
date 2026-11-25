#!/usr/bin/env python3
"""avm1_edittext_rotated_borders (s28 coordinator, for w1-text-glyph-aa LOCAL ORACLE REQUEST 2).

Five bordered EMPTY embedded-font EditTexts (70x55 px box, regression/avm1_edittext_placed_cxform's edittext()),
rotated 15/30/45/60 deg and sheared c=0.5, to pin Flash's rotated text-box border hairline weight
(tf_border_line_segment's skewed arm). Run from the repo root.
"""
import pathlib, struct, sys, math
HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE
while not (ROOT / 'ruffle-tests').is_dir(): ROOT = ROOT.parent
sys.path.insert(0, str(ROOT / 'ruffle-tests/tests/swfs/regression/avm1_edittext_placed_cxform'))
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
def rot(deg, tx, ty):
    r = math.radians(deg); return matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), tx, ty)
tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1), base.edittext(5, 1, (0, 0, 0), ''),
        place(1, 5, rot(15, 1300, 300)), place(2, 5, rot(30, 3300, 300)), place(3, 5, rot(45, 5300, 300)),
        place(4, 5, rot(60, 1300, 2300)), place(5, 5, matrix(1, 0, 0.5, 1, 3300, 2300)),
        base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 6000, 0, 4000) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
