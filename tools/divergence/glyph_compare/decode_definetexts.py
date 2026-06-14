#!/usr/bin/env python3
"""Decode every DefineText tag's glyph sequence + (optionally) map to chars.

Useful for confirming what text a DefineText actually renders. For Tetris this
is how we proved NO DefineText spells "tetris" (the title is DefineShape 26),
and that DefineText 13 = "loading", 18 = "play", 21 = "high scores", etc.

If --font-grid-order is given (the glyph->char reading of make_glyph_grid output,
left-to-right top-to-bottom), each glyph index is annotated with its char.

Usage:
    python3 decode_definetexts.py <input.swf>
"""
import argparse
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import swf_lib as S


class BR:
    def __init__(self, b, p):
        self.b, self.byte, self.bit = b, p, 0

    def u(self, n):
        v = 0
        for _ in range(n):
            v = (v << 1) | ((self.b[self.byte] >> (7 - self.bit)) & 1)
            self.bit += 1
            if self.bit == 8:
                self.bit = 0
                self.byte += 1
        return v

    def align(self):
        if self.bit:
            self.bit = 0
            self.byte += 1


def parse_definetext(b, start, end):
    p = start + 2                                    # skip charID
    nb = (b[p] >> 3) & 0x1F
    p += (5 + nb * 4 + 7) // 8                       # text bounds RECT
    br = BR(b, p)                                    # text MATRIX
    if br.u(1):
        n = br.u(5); br.u(n); br.u(n)
    if br.u(1):
        n = br.u(5); br.u(n); br.u(n)
    nt = br.u(5); br.u(nt); br.u(nt)
    br.align()
    p = br.byte
    glyphbits, advbits = b[p], b[p + 1]
    p += 2
    glyphs, font = [], None
    while p < end:
        flags = b[p]
        if flags == 0:
            break
        if flags & 0x80:                             # style change
            p += 1
            hasf, hasc, hasy, hasx = flags & 0x08, flags & 0x04, flags & 0x02, flags & 0x01
            if hasf:
                font = struct.unpack('<H', b[p:p + 2])[0]; p += 2
            if hasc:
                p += 3
            if hasx:
                p += 2
            if hasy:
                p += 2
            if hasf:
                p += 2
        else:                                        # glyph record
            cnt = flags & 0x7F
            p += 1
            br = BR(b, p)
            for _ in range(cnt):
                gi = br.u(glyphbits); br.u(advbits); glyphs.append(gi)
            br.align()
            p = br.byte
    return font, glyphs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("input_swf", type=Path)
    args = ap.parse_args()
    data = S.decompress(args.input_swf.read_bytes())
    for code, p, hs, ln in S.iter_tags(data):
        if code == S.DEFINE_TEXT:
            cid = struct.unpack('<H', data[p + hs:p + hs + 2])[0]
            font, glyphs = parse_definetext(data, p + hs, p + hs + ln)
            print(f"DefineText {cid}: font={font} glyphs={glyphs}")


if __name__ == "__main__":
    main()
