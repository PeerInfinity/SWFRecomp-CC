"""regression/avm1_edittext_rotated_color: the s29 W1 FLASH fixture (coordinator mkswf.py, W1 part, verbatim).

The avm1_edittext_rotated_glyphs layout (90 deg, rot30, shear 0.5 fields + a 2nd 90 deg field)
with text colour 0xCC3300 and a 0x808080 rect (90..200, 20..140 px) behind the rot30 field.
Golden output.expected.png = FP32 LNX capture (SWFRecomp-CC-history:SWFRecompDocs/plans/session29-fanout-reports/w1-local-oracles/
w1-text-pixels/W1_color/flash.png). Run: python3 create_test_swf.py  (writes test.swf here).
"""
import pathlib, struct, sys, math
HERE = pathlib.Path(__file__).resolve().parent
REG = HERE.parent
sys.path.insert(0, str(REG / 'avm1_edittext_placed_cxform'))
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
def shape(sid, fills, lines, paths):
    """paths: list of (fill0_idx, line_idx, [(x,y) twips absolute...]) polylines."""
    allp = [p for _, _, pts in paths for p in pts]
    xs = [p[0] for p in allp]; ys = [p[1] for p in allp]
    b = base.rect(min(xs) - 40, max(xs) + 40, min(ys) - 40, max(ys) + 40)
    out = struct.pack('<H', sid) + b
    out += bytes([len(fills)]) + b''.join(bytes([0]) + bytes(c) for c in fills)
    out += bytes([len(lines)]) + b''.join(struct.pack('<H', wdt) + bytes(c) for wdt, c in lines)
    w = base.BW(); nf, nl = 2, 2
    w.u(nf, 4); w.u(nl, 4)
    cx = cy = 0
    for f0, li, pts in paths:
        x0, y0 = pts[0]
        w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(1, 1); w.u(1, 1)  # lineStyle, fill0, moveTo
        nb = base.nbits_s(x0, y0); w.u(nb, 5); w.sb(x0, nb); w.sb(y0, nb)
        w.u(f0, nf); w.u(li, nl)
        cx, cy = x0, y0
        for x, y in pts[1:]:
            dx, dy = x - cx, y - cy
            nb = max(base.nbits_s(dx, dy), 2)
            w.u(1, 1); w.u(1, 1); w.u(nb - 2, 4); w.u(1, 1); w.sb(dx, nb); w.sb(dy, nb)
            cx, cy = x, y
    w.u(0, 6)
    return base.tag(2, out + w.bytes())
def write(path, w_px, h_px, tags):
    body = base.rect(0, w_px * 20, 0, h_px * 20) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags + [base.tag(1, b''), base.tag(0, b'')])
    path.write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
t = lambda px: int(round(px * 20))
r = math.radians(30)
# W1: rotated_glyphs layout, text colour CC3300, a mid-grey rect behind the rot30 field (depth 1 < 2)
grey = shape(10, [(0x80, 0x80, 0x80)], [], [(1, 0, [(t(90), t(20)), (t(200), t(20)), (t(200), t(140)), (t(90), t(140)), (t(90), t(20))])])
write(HERE / 'test.swf', 200, 200, [base.tag(9, b'\xff\xff\xff'), base.font2(1), base.edittext(5, 1, (0xCC, 0x33, 0x00), 'II'), grey,
    place(1, 10, matrix(1, 0, 0, 1, 0, 0)),
    place(2, 5, matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), 2200, 600)),
    place(3, 5, matrix(1, 0, 0.5, 1, 200, 2600)),
    place(4, 5, matrix(0, 1, -1, 0, 1400, 200))])
print('ok')
