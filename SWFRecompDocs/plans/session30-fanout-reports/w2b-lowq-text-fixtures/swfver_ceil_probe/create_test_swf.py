#!/usr/bin/env python3
"""s30 w2b-lowq-text: is Flash LOW's whole-px DefineFont2 advance gated by the SWF VERSION?

Known FP32 data (all the same gnash DefineFont2, flags 0xa4 = HasLayout|SmallText|WideCodes, 12 px):
  regression/lowq_glyph_probe_df2 (SWF 8)             ceil advance  (direct)
  w2-lowq-land lowq_adv_flags_probe, 8 flag rows (SWF 8) ceil, every row (direct)
  from_gnash/misc-ming.all/BeginBitmapFill (SWF 8)    ceil          (s27 wrapper draw(), golden == FP32)
  from_gnash/misc-ming.all/EmbeddedFontTest (SWF 7)   textWidth = sum of ceil(adv px)  (trace, direct)
  from_gnash/misc-ming.all/morph_test1 (SWF 6)        FRACTIONAL    (s27 + s28 wrapper, LNX and WIN)
BeginBitmapFill and morph_test1 carry the byte-identical xtrace DefineEditText + font, so no field
property can be the switch; the SWF version (6 vs 7/8) is the remaining difference.

Writes test_v5.swf .. test_v8.swf (identical but for the header version; v8 adds FileAttributes).
Each: _quality = "LOW" in frame 1, 4 rows, field x = 10 px, rows 30 px apart:
  r0 probe field (flags 0x8d 0x11), text "aceosgb@&S 2369", font 1 (SmallText ON)
  r1 morph_test1's xtrace field bytes (0xc9 0x01, var "_root._trace_text"), text " - xtrace enabled -\\n", font 1
  r2 = r0 with font 2 (the same font, SmallText bit CLEARED)
  r3 = r1 with font 2 (var "_root._trace_text2")
Expected if the gate is "SWF >= 7": v5/v6 rows all fractional (ink starts 13,20,27,34,41,48,55,63,...),
v7/v8 r0/r1 ceil (13,21,28,36,44,51,59,67,79,...); r2/r3 say whether SmallText also gates it.
Reads the corpus place_object_test SWF for the font (run download_tests.sh from_gnash first).
"""
import importlib.util, pathlib, struct
HERE = pathlib.Path(__file__).resolve().parent
G = HERE.parents[1] / 'w1-lowq-residues-fixtures/lowq_glyph_probe/create_test_swf.py'
spec = importlib.util.spec_from_file_location('g', G); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)

def font(fid, smalltext):
    t = g.font_tag()                       # DefineFont2 id 1, long tag header
    hdr, body = t[:6], bytearray(t[6:])
    body[0:2] = struct.pack('<H', fid)
    if not smalltext: body[2] &= ~0x20 & 0xff
    return g.tag(48, bytes(body))

def edit_text(cid, fid, f1, f2, var, text):
    body = struct.pack('<H', cid) + g.rect(0, 300 * 20, 0, 28 * 20)
    body += bytes([f1, f2]) + struct.pack('<HH', fid, 240)
    if f1 & 0x04: body += bytes([0, 0, 0, 255])
    body += var + b'\x00' + text + b'\x00'
    return g.tag(37, body)

ROWS = [(1, 0x8d, 0x11, b'', b'aceosgb@&S 2369'),
        (1, 0xc9, 0x01, b'_root._trace_text', b' - xtrace enabled -\n'),
        (2, 0x8d, 0x11, b'', b'aceosgb@&S 2369'),
        (2, 0xc9, 0x01, b'_root._trace_text2', b' - xtrace enabled -\n')]

def build(ver):
    tags = (g.tag(69, struct.pack('<I', 0)) if ver >= 8 else b'') + g.tag(9, bytes([255, 255, 255]))
    tags += g.do_quality_low() + font(1, True) + font(2, False)
    for i, (fid, f1, f2, var, text) in enumerate(ROWS):
        tags += edit_text(10 + i, fid, f1, f2, var, text) + g.place(1 + i, 10 + i, 10, 4 + 30 * i)
    tags += g.tag(1, b'') + g.tag(0, b'')
    body = g.rect(0, 480 * 20, 0, 130 * 20) + struct.pack('<HH', 30 << 8, 1) + tags
    swf = b'FWS' + bytes([ver]) + struct.pack('<I', 8 + len(body)) + body
    out = HERE / ('test_v%d.swf' % ver)
    out.write_bytes(swf); print('wrote', out, len(swf), 'bytes')

if __name__ == '__main__':
    for v in (5, 6, 7, 8): build(v)
