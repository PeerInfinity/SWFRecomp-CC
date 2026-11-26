#!/usr/bin/env python3
# s28 n-drawapi-stroke-snap: list image tests (dirs with test.toml image_comparisons) whose SWF
# calls the Drawing API lineStyle / GraphicsStroke.  Usage: scan_linestyle.py ruffle-tests/tests/swfs
import sys, os, zlib, lzma, re
root = sys.argv[1]
for dp, dn, fn in os.walk(root):
    if 'test.toml' not in fn or 'test.swf' not in fn: continue
    t = open(os.path.join(dp, 'test.toml'), errors='replace').read()
    if 'image_comparisons' not in t: continue
    d = open(os.path.join(dp, 'test.swf'), 'rb').read()
    try:
        if d[:3] == b'CWS': body = zlib.decompress(d[8:])
        elif d[:3] == b'ZWS': body = lzma.LZMADecompressor(lzma.FORMAT_RAW, filters=[{"id": lzma.FILTER_LZMA1, **lzma._decode_filter_properties(lzma.FILTER_LZMA1, d[12:17])}]).decompress(d[17:])
        else: body = d[8:]
    except Exception as e:
        body = b''
    if b'lineStyle' in body or b'GraphicsStroke' in body:
        print(os.path.relpath(dp, root))
