"""s29 coordinator: W1/W2 FLASH fixtures for w1-text-pixels (built from regression/avm1_edittext_placed_cxform helpers)."""
import pathlib, struct, sys, math
HERE = pathlib.Path(__file__).resolve().parent
REG = HERE.parents[4] / 'ruffle-tests/tests/swfs/regression'
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
write(HERE / 'W1_color/test.swf', 200, 200, [base.tag(9, b'\xff\xff\xff'), base.font2(1), base.edittext(5, 1, (0xCC, 0x33, 0x00), 'II'), grey,
    place(1, 10, matrix(1, 0, 0, 1, 0, 0)),
    place(2, 5, matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), 2200, 600)),
    place(3, 5, matrix(1, 0, 0.5, 1, 200, 2600)),
    place(4, 5, matrix(0, 1, -1, 0, 1400, 200))])
# W2: slanted 1px stroke, slanted hairline, slanted filled triangle (all black)
s1 = shape(11, [], [(20, (0, 0, 0))], [(0, 1, [(t(10.3), t(10.1)), (t(180.7), t(95.4))])])
s2 = shape(12, [], [(0, (0, 0, 0))], [(0, 1, [(t(10.3), t(110.1)), (t(180.7), t(195.4))])])
s3 = shape(13, [(0, 0, 0)], [], [(1, 0, [(t(200.2), t(20.3)), (t(380.6), t(60.7)), (t(250.4), t(190.9)), (t(200.2), t(20.3))])])
write(HERE / 'W2_shapes/test.swf', 400, 220, [base.tag(9, b'\xff\xff\xff'), s1, s2, s3,
    place(1, 11, matrix(1, 0, 0, 1, 0, 0)), place(2, 12, matrix(1, 0, 0, 1, 0, 0)), place(3, 13, matrix(1, 0, 0, 1, 0, 0))])
for d in ('W1_color', 'W2_shapes'):
    (HERE / d / 'test.toml').write_text('num_ticks = 1\n\n[image_comparisons.output]\ntolerance = 0\n\n[player_options]\nwith_renderer = { optional = false }\n')
print('ok')
