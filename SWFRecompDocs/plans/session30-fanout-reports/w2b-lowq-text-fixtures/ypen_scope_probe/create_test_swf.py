#!/usr/bin/env python3
"""s30 w2b-lowq-text: which field property keeps Flash LOW's FIELD-LOCAL y pen rule?

FP32 LOW data: regression/lowq_glyph_probe_df2 (gnash DefineFont2, plain fields) at field y
108.5 / 140.5 puts the baseline at 132 / 175 = half-even(origin) + rint(local baseline 24.27 /
35.40) (the world rounding gives 133 / 176). text/style_changes_in_html field 5 (DefineFont3 +
DefineFontAlignZones, HTML, y 68.5, local baseline 29.16) puts it at 98 = the WORLD rounding of
97.66 (the local rule gives 68 + 29 = 97). x follows the local rule in both.
Rows (black text, _quality = "LOW" set in frame 1, field x = 10.25, every field y = EVEN + 0.5, so
local = world - 1 px on each row):
  r0 y  4.5  DF3 (style_changes_in_html font 1, with its align zones), plain, 30 px  "Regular and Regular"
  r1 y 44.5  same font, HTML ("<p>Regular and Regular</p>"), 30 px
  r2 y 84.5  same DF3 glyphs as a second font WITHOUT DefineFontAlignZones, plain, 30 px
  r3 y 124.5 gnash DefineFont2 (place_object_test), plain, 24 px  "aceosgb@&S 2369"
  r4 y 164.5 gnash DefineFont2, HTML, 24 px
Local-rule baselines: r0-r2 at y0-0.5 + 29, r3/r4 at y0-0.5 + 24; world: one px lower on every row.
Reads the corpus place_object_test and text/style_changes_in_html SWFs (download_tests.sh from_gnash text).
"""
import importlib.util, pathlib, struct, zlib
HERE = pathlib.Path(__file__).resolve().parent
REPO = HERE.parents[4]
G = HERE.parents[1] / 'w1-lowq-residues-fixtures/lowq_glyph_probe/create_test_swf.py'
spec = importlib.util.spec_from_file_location('g', G); g = importlib.util.module_from_spec(spec); spec.loader.exec_module(g)
STYLE = REPO / 'ruffle-tests/tests/swfs/text/style_changes_in_html/test.swf'

def raw_tags(path):
    d = path.read_bytes()
    if d[:3] == b'CWS': d = d[:8] + zlib.decompress(d[8:])
    nb = d[8] >> 3; p = 8 + (5 + 4 * nb + 7) // 8 + 4; out = []
    while p < len(d):
        h = struct.unpack_from('<H', d, p)[0]; c, l = h >> 6, h & 63; p += 2
        if l == 63: l = struct.unpack_from('<I', d, p)[0]; p += 4
        out.append((c, d[p:p + l])); p += l
    return out

def with_id(body, fid): b = bytearray(body); b[0:2] = struct.pack('<H', fid); return bytes(b)

def fonts():
    t = raw_tags(STYLE)
    df3 = next(b for c, b in t if c == 75 and struct.unpack_from('<H', b)[0] == 1)
    zones = next(b for c, b in t if c == 73 and struct.unpack_from('<H', b)[0] == 1)
    out = g.tag(75, with_id(df3, 1)) + g.tag(73, with_id(zones, 1))     # font 1: DF3 + zones
    out += g.tag(75, with_id(df3, 2))                                     # font 2: DF3, no zones
    gf = g.font_tag()                                                     # gnash DF2 (id 1, long header)
    out += g.tag(48, with_id(gf[6:], 3))                                  # font 3
    return out

def edit_text(cid, fid, px, html, text):
    body = struct.pack('<H', cid) + g.rect(0, 400 * 20, 0, 40 * 20)
    body += bytes([0x8d, 0x13 if html else 0x11]) + struct.pack('<HH', fid, px * 20) + bytes([0, 0, 0, 255])
    body += b'\x00' + text + b'\x00'
    return g.tag(37, body)

ROWS = [(1, 30, False, b'Regular and Regular', 4.5), (1, 30, True, b'<p>Regular and Regular</p>', 44.5),
        (2, 30, False, b'Regular and Regular', 84.5), (3, 24, False, b'aceosgb@&S 2369', 124.5),
        (3, 24, True, b'<p>aceosgb@&amp;S 2369</p>', 164.5)]

def build():
    tags = g.tag(69, struct.pack('<I', 0)) + g.tag(9, bytes([255, 255, 255])) + g.do_quality_low() + fonts()
    for i, (fid, px, html, text, y) in enumerate(ROWS):
        tags += edit_text(10 + i, fid, px, html, text) + g.place(1 + i, 10 + i, 10.25, y)
    tags += g.tag(1, b'') + g.tag(0, b'')
    body = g.rect(0, 480 * 20, 0, 210 * 20) + struct.pack('<HH', 30 << 8, 1) + tags
    swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
    (HERE / 'test.swf').write_bytes(swf); print('wrote', HERE / 'test.swf', len(swf), 'bytes')

if __name__ == '__main__':
    build()
