#!/usr/bin/env python3
"""embeddedfont_smalltext_probe (s30 w1-rm-avm1-gnash).
Writes two variants of gnash misc-ming.all/EmbeddedFontTest/test.swf (FP32
golden already = SmallText ON): smalltext_off.swf clears DefineFont2 flag 0x20
(SmallText) on every font; smalltext_on.swf is the original re-written as
uncompressed FWS (byte-identical tag stream). Decides whether FP32's
per-glyph ceil() in textWidth is SmallText-only or every embedded font.
Usage: make_variants.py <EmbeddedFontTest/test.swf> <outdir>"""
import sys, zlib, struct
src, out = sys.argv[1], sys.argv[2]
d = open(src, 'rb').read()
if d[:3] == b'CWS': d = b'FWS' + d[3:8] + zlib.decompress(d[8:])
def patch(clear):
    b = bytearray(d)
    nb = b[8] >> 3; o = 8 + (5 + 4 * nb + 7) // 8 + 4
    while o < len(b):
        h = struct.unpack('<H', b[o:o+2])[0]; code = h >> 6; ln = h & 63; o += 2
        if ln == 63: ln = struct.unpack('<I', b[o:o+4])[0]; o += 4
        if code == 48 and clear: b[o+2] &= ~0x20 & 0xff
        o += ln
    return bytes(b)
open(out + '/smalltext_on.swf', 'wb').write(patch(False))
open(out + '/smalltext_off.swf', 'wb').write(patch(True))
