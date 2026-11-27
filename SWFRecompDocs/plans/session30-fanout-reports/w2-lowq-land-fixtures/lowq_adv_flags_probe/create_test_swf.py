#!/usr/bin/env python3
"""s30 w2-lowq-land: which DefineEditText property switches Flash LOW's whole-px advance?

FP32 LOW (w1-local-oracles/w1-lowq-residues/df2) advances the gnash DefineFont2 field
of lowq_glyph_probe by ceil(advance px) at 12 px, but FP32 LOW's from_gnash morph_test1
xtrace field (SAME font, 12 px) keeps Ruffle's fractional (whole-twip) advance.
The two fields differ in WordWrap, NoSelect, HasTextColor and a variable binding.
One 12 px row per variant, text "aceosgb@&S 2369", field x = 10, rows 24 px apart:
  r0 probe flags (f1 0x8d, f2 0x11)        r4 + VariableName "v"
  r1 + WordWrap                           r5 gnash flags exactly (f1 0xc9, f2 0x01, var "_root.v")
  r2 - NoSelect                           r6 + Multiline
  r3 - HasTextColor                       r7 + WordWrap + Multiline
The SWF sets _quality = "LOW" itself. Reads the corpus place_object_test SWF for the font
(run download_tests.sh from_gnash first). Writes test.swf next to this file.
"""
import importlib.util, pathlib, struct
HERE = pathlib.Path(__file__).resolve().parent
G = HERE.parents[1] / 'w1-lowq-residues-fixtures/lowq_glyph_probe/create_test_swf.py'
spec = importlib.util.spec_from_file_location('g', G); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)
TEXT = b'aceosgb@&S 2369'

def edit_text(cid, f1, f2, var=b''):
    body = struct.pack('<H', cid) + g.rect(0, 300 * 20, 0, 40 * 20)
    body += bytes([f1, f2]) + struct.pack('<HH', 1, 240)
    if f1 & 0x04: body += bytes([0, 0, 0, 255])
    body += var + b'\x00' + TEXT + b'\x00'
    return g.tag(37, body)

ROWS = [(0x8d, 0x11, b''), (0xcd, 0x11, b''), (0x8d, 0x01, b''), (0x89, 0x11, b''),
        (0x8d, 0x11, b'v'), (0xc9, 0x01, b'_root.v'), (0xad, 0x11, b''), (0xed, 0x11, b'')]

def build():
    tags = g.tag(69, struct.pack('<I', 0)) + g.tag(9, bytes([255, 255, 255])) + g.do_quality_low() + g.font_tag()
    for i, (f1, f2, var) in enumerate(ROWS):
        tags += edit_text(10 + i, f1, f2, var) + g.place(1 + i, 10 + i, 10, 4 + 24 * i)
    tags += g.tag(1, b'') + g.tag(0, b'')
    body = g.rect(0, 480 * 20, 0, 220 * 20) + struct.pack('<HH', 30 << 8, 1) + tags
    swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
    (HERE / 'test.swf').write_bytes(swf)
    print('wrote', HERE / 'test.swf', len(swf), 'bytes')

if __name__ == '__main__':
    build()
