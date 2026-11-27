"""avm1_edittext_rotated_paragraph: a 200-glyph rotated multiline EditText (coverage-run budget stress).

s29 w2-text-coverage-land. Skewed AVM1 text draws through tag.c tf_cpu_cov_fill
(Flash HIGH's 4-sub-scanline / exact-x coverage rule), which emits pixel runs.
The w1-text-pixels prototype drew one alpha rect per run: one draw call and one
dynamic colour slot each, against MAX_DYNAMIC_RECTS = 4096 per frame
(render_webgpu.c), so a rotated paragraph silently lost its tail. This field has
10 lines x 20 glyphs at 15 px, rotated 30 deg: ~2x that budget in runs. The
landing batches a field's runs into ONE render_webgpu_draw_cov_runs draw (per-
vertex colour slots, one per coverage level), so every glyph must be present:
SWF_TF_CPU_COV_STATS=1 prints "runs drawn N, fallbacks 0, failed 0".
Same square-glyph DefineFont2 as ../avm1_edittext_placed_cxform (glyph 'I').
Golden: none yet (image comparison = skip) until a FLASH Player 32 capture is
archived (s29 w2-text-coverage-land LOCAL ORACLE REQUEST F1).
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


def edittext_multiline(cid, fid, color, text, w_tw, h_tw, fh_tw):
    b = struct.pack("<H", cid) + base.rect(0, w_tw, 0, h_tw)
    b += bytes([0x80 | 0x20 | 0x04 | 0x01,      # HasText | Multiline | HasTextColor | HasFont
                0x08 | 0x01 | 0x10 | 0x20])     # Border | UseOutlines | NoSelect | HasLayout
    b += struct.pack("<HH", fid, fh_tw)
    b += bytes(color) + b"\xff"
    b += bytes([0]) + struct.pack("<HHHh", 0, 0, 0, 0)
    b += base.s("")
    b += base.s(text)
    return tag_(37, b)


tag_ = base.tag
text = "\r".join(["I" * 20] * 10)               # 200 glyphs
r = math.radians(30)
tags = [base.tag(9, b'\xff\xff\xff'), base.font2(1),
        edittext_multiline(5, 1, (0, 0, 0), text, 3100, 3100, 300),
        place(1, 5, matrix(math.cos(r), math.sin(r), -math.sin(r), math.cos(r), 1800, 300)),
        base.tag(1, b''), base.tag(0, b'')]
body = base.rect(0, 4800, 0, 4800) + struct.pack('<HH', 30 << 8, 1) + b''.join(tags)
(HERE / 'test.swf').write_bytes(b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body)
print('ok')
