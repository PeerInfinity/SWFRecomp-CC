#!/usr/bin/env python3
"""Scan SWFs: is_as3 (FileAttributes AS3 bit) + AVM1 payload tag byte counts.

Prints one line per SWF that has any payload tag, and a summary.
"""
import sys, zlib, struct, os

BITMAP_TAGS = {6: 'DefineBits', 20: 'DefineBitsLossless', 21: 'DefineBitsJPEG2',
               35: 'DefineBitsJPEG3', 36: 'DefineBitsLossless2', 90: 'DefineBitsJPEG4'}
SOUND_TAGS = {14: 'DefineSound', 19: 'SoundStreamBlock'}
VIDEO_TAGS = {61: 'VideoFrame'}

def body(path):
    with open(path, 'rb') as f:
        data = f.read()
    if len(data) < 8:
        return None
    sig = data[:3]
    if sig == b'FWS':
        return data[8:]
    if sig == b'CWS':
        try:
            return zlib.decompress(data[8:])
        except Exception:
            return None
    if sig == b'ZWS':
        try:
            import lzma
            # SWF LZMA: 4-byte compressed length, 5-byte props, then stream
            props = data[12:17]
            d = lzma.LZMADecompressor(format=lzma.FORMAT_RAW,
                                      filters=[lzma._decode_filter_properties(lzma.FILTER_LZMA1, props)])
            return d.decompress(data[17:])
        except Exception:
            return None
    return None

def scan(path):
    b = body(path)
    if b is None:
        return None
    # skip RECT
    if not b:
        return None
    nbits = b[0] >> 3
    total_bits = 5 + 4 * nbits
    p = (total_bits + 7) // 8
    p += 4  # framerate + framecount
    is_as3 = False
    counts = {}
    n = len(b)
    while p + 2 <= n:
        th = struct.unpack_from('<H', b, p)[0]; p += 2
        code = th >> 6
        length = th & 0x3F
        if length == 0x3F:
            if p + 4 > n: break
            length = struct.unpack_from('<I', b, p)[0]; p += 4
        if code == 0:
            break
        if code == 69 and length >= 1:   # FileAttributes
            if b[p] & 0x08:
                is_as3 = True
        if code in BITMAP_TAGS or code in SOUND_TAGS or code in VIDEO_TAGS:
            counts[code] = counts.get(code, (0, 0))
            c, sz = counts[code]
            counts[code] = (c + 1, sz + length)
        p += length
        if p > n: break
    return is_as3, counts

if __name__ == '__main__':
    roots = sys.argv[1:]
    as3_with = 0
    tot = 0
    for root in roots:
        for dirpath, _, files in os.walk(root):
            for fn in files:
                if not fn.endswith('.swf'):
                    continue
                fp = os.path.join(dirpath, fn)
                r = scan(fp)
                if r is None:
                    continue
                tot += 1
                is_as3, counts = r
                if not counts:
                    continue
                if is_as3:
                    as3_with += 1
                desc = ' '.join('%s=%d/%dB' % ({**BITMAP_TAGS, **SOUND_TAGS, **VIDEO_TAGS}[c], v[0], v[1])
                                for c, v in sorted(counts.items()))
                print('%s %s %s' % ('AS3' if is_as3 else 'AV1', fp, desc))
    print('# scanned %d swfs; AS3-with-payload: %d' % (tot, as3_with), file=sys.stderr)
