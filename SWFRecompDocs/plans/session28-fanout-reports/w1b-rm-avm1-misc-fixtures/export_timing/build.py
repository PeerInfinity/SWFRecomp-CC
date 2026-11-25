#!/usr/bin/env python3
"""Build the export-timing Flash probes from the corpus fixture
avm1/attach_movie_export_not_yet_run/test.swf (SWF6, FWS).

Question: FP32 prints `undefined` for a frame-1 attachMovie of a symbol whose
ExportAssets tag sits in frame 2. Is an export registered when the PLAYHEAD
reaches its frame, or when the PARSER has loaded it (i.e. one tick later even
with the playhead parked on frame 1)?

probe_stop.swf : frame 1 = stop(); onEnterFrame = function(){ trace(attachMovie("LateExport","e",5)); }
                 (frame 2 = ExportAssets + the fixture's own frame-2 script, never reached)
                 playhead model -> every tick prints `undefined`
                 parser model   -> `_level0.e` from some tick on
probe_play.swf : same frame-1 script without stop(): the playhead reaches frame 2
                 (fixture prints `_level0.fromFrame2`) and loops.

usage: build.py <path/to/attach_movie_export_not_yet_run/test.swf> <outdir>
"""
import struct, sys, os

def tags(d):
    nb = d[8] >> 3
    off = 8 + (5 + 4 * nb + 7) // 8 + 4
    hdr = d[:off]; i = off; out = []
    while i < len(d):
        h = d[i] | d[i + 1] << 8; t = h >> 6; l = h & 63; hs = 2
        if l == 63: l = int.from_bytes(d[i + 2:i + 6], 'little'); hs = 6
        out.append((t, d[i + hs:i + hs + l])); i += hs + l
        if t == 0: break
    return hdr, out

def tag(t, body):
    if len(body) < 63: return struct.pack('<H', (t << 6) | len(body)) + body
    return struct.pack('<HI', (t << 6) | 63, len(body)) + body

def push(*items):
    b = b''
    for it in items:
        if isinstance(it, int): b += b'\x07' + struct.pack('<i', it)
        else: b += b'\x00' + it.encode() + b'\x00'
    return b'\x96' + struct.pack('<H', len(b)) + b

def frame1(stop):
    body = push(5, 'e', 'LateExport', 3, 'attachMovie') + b'\x3d' + b'\x26'   # trace(attachMovie(...))
    fn = b'\x9b' + struct.pack('<H', 1 + 2 + 2) + b'\x00' + struct.pack('<H', 0) + struct.pack('<H', len(body)) + body
    code = (b'\x07' if stop else b'') + push('onEnterFrame') + fn + b'\x1d'     # onEnterFrame = function(){...}
    code += push('frame1 ran') + b'\x26' + b'\x00'
    return code

def build(src, outdir):
    d = open(src, 'rb').read()
    assert d[:3] == b'FWS', 'expected the uncompressed SWF6 fixture'
    hdr, ts = tags(d)
    for stop, name in ((True, 'probe_stop.swf'), (False, 'probe_play.swf')):
        out = b''; seen_do = False
        for t, body in ts:
            if t == 12 and not seen_do:
                body = frame1(stop); seen_do = True
            out += tag(t, body)
        swf = bytearray(hdr + out)
        struct.pack_into('<I', swf, 4, len(swf))
        open(os.path.join(outdir, name), 'wb').write(bytes(swf))
        print('wrote', name, len(swf))

if __name__ == '__main__':
    build(sys.argv[1], sys.argv[2])
