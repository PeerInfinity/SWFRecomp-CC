#!/usr/bin/env python3
"""List image-comparison tests whose SWF has timeline strokes (DefineShape1-4
line styles with width > 0 in the initial LINESTYLEARRAY; morph/glyph strokes
excluded as the runtime pass skips them). usage: scan_strokes.py ROOT"""
import sys, os, zlib, struct, lzma, re
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "../../../tools"))
from scan_swf import body

class R:
    def __init__(s, b, p=0): s.b, s.p, s.bit = b, p, 0
    def ub(s, n):
        v = 0
        for _ in range(n):
            byte = s.b[s.p]; v = (v << 1) | ((byte >> (7 - s.bit)) & 1); s.bit += 1
            if s.bit == 8: s.bit = 0; s.p += 1
        return v
    def align(s):
        if s.bit: s.bit = 0; s.p += 1
    def u8(s): s.align(); v = s.b[s.p]; s.p += 1; return v
    def u16(s): s.align(); v = struct.unpack_from("<H", s.b, s.p)[0]; s.p += 2; return v
    def rect(s): s.align(); n = s.ub(5); s.ub(4 * n); s.align()
    def matrix(s):
        s.align()
        if s.ub(1): n = s.ub(5); s.ub(2 * n)
        if s.ub(1): n = s.ub(5); s.ub(2 * n)
        n = s.ub(5); s.ub(2 * n); s.align()

def fillstyles(r, ver):
    n = r.u8()
    if n == 0xFF and ver >= 2: n = r.u16()
    for _ in range(n):
        t = r.u8()
        if t == 0: r.p += 4 if ver >= 3 else 3
        elif t in (0x10, 0x12, 0x13):
            r.matrix(); f = r.u8(); cnt = f & 15
            r.p += cnt * (5 if ver >= 3 else 4)
            if t == 0x13: r.p += 2
        elif t in (0x40, 0x41, 0x42, 0x43): r.p += 2; r.matrix()
        else: raise ValueError("fill %x" % t)

def linestyles(r, ver):
    n = r.u8()
    if n == 0xFF: n = r.u16()
    ws = []
    for _ in range(n):
        w = r.u16(); ws.append(w)
        if ver == 4:
            f1 = r.u8(); f2 = r.u8()
            if ((f1 >> 4) & 3) == 2: r.p += 2
            if (f1 >> 3) & 1:
                fillstyles_one(r)
            else: r.p += 4
        else: r.p += 4 if ver >= 3 else 3
    return ws

def fillstyles_one(r):
    t = r.u8()
    if t == 0: r.p += 4
    elif t in (0x10, 0x12, 0x13):
        r.matrix(); f = r.u8(); r.p += (f & 15) * 5
        if t == 0x13: r.p += 2
    else: r.p += 2; r.matrix()

def scan(path):
    b = body(path)
    if b is None: return None
    r = R(b); r.rect(); r.p += 4
    out = []
    while r.p + 2 <= len(b):
        h = struct.unpack_from("<H", b, r.p)[0]; r.p += 2
        code, ln = h >> 6, h & 63
        if ln == 63: ln = struct.unpack_from("<I", b, r.p)[0]; r.p += 4
        start = r.p
        if code == 0: break
        ver = {2: 1, 22: 2, 32: 3, 83: 4}.get(code)
        if ver:
            try:
                rr = R(b, start + 2); rr.rect()
                if ver == 4: rr.rect(); rr.p += 1
                fillstyles(rr, ver); ws = linestyles(rr, ver)
                out += [w for w in ws if w > 0]
            except Exception:
                out.append(-1)
        r.p = start + ln
    return out

root = sys.argv[1]
for dp, dn, fn in os.walk(root):
    dn[:] = [d for d in dn if not d.startswith(("Recompiled", "_"))]
    if "test.toml" in fn and "test.swf" in fn:
        toml = open(os.path.join(dp, "test.toml")).read()
        if "image_comparisons" not in toml: continue
        ws = scan(os.path.join(dp, "test.swf"))
        if ws:
            thin = sum(1 for w in ws if 0 < w <= 66)
            print("%s\tstrokes=%d\tthin<=3.3px=%d\tunparsed=%d" % (os.path.relpath(dp, root), len(ws), thin, ws.count(-1)))
