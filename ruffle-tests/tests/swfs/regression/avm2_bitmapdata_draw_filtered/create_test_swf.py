#!/usr/bin/env python3
"""AVM2 BitmapData.draw() of a Sprite that carries its own filters.

Usage: create_test_swf.py [out.swf]   (default: test.swf beside this script)

s26 w2-avm2-applyfilter-kernels. Flash renders a drawn display object WITH its
own filters (the avm2/bitmapdata_draw_filters Flash golden shows its
ColorMatrixFilter in the drawn bitmap); Ruffle does NOT (operations.rs draw:
use_bitmap_cache false). Before s26 our CPU draw() ran only ColorMatrix; it
now also runs Blur / Glow / DropShadow / Bevel / Convolution through the
applyFilter kernels. Each row draws a 10x10 opaque red square at (10,10) into
a 30x30 transparent BitmapData and traces row y=15 and column x=15.

The expected output must come from FLASH (not the Ruffle exporter, which
ignores the filters by design); see the w2 report's LOCAL ORACLE REQUESTS.
Until then output.txt is OUR output, marked provisional in test.toml.
"""
import os
import struct
import sys

NS = ['', 'flash.display', 'flash.filters', 'flash.geom']


def u30(v):
    out = bytearray()
    while True:
        b = v & 0x7F
        v >>= 7
        if v:
            out.append(b | 0x80)
        else:
            out.append(b)
            return bytes(out)


def s24(v):
    return struct.pack('<i', v)[:3]


class Abc:
    def __init__(self):
        self.strings = [None]
        self.names = [None]
        self.ints = [None]
        self.doubles = [None]

    def string(self, s):
        if s not in self.strings:
            self.strings.append(s)
        return self.strings.index(s)

    def name(self, n):
        if n not in self.names:
            self.names.append(n)
        return self.names.index(n)

    def int_(self, v):
        if v not in self.ints:
            self.ints.append(v)
        return self.ints.index(v)

    def double(self, v):
        if v not in self.doubles:
            self.doubles.append(v)
        return self.doubles.index(v)


class Code:
    def __init__(self, abc):
        self.abc = abc
        self.b = bytearray()

    def op(self, *bs):
        self.b += bytes(bs)

    def push(self, v):
        a = self.abc
        if isinstance(v, bool):
            self.op(0x26 if v else 0x27)
        elif isinstance(v, str):
            self.op(0x2c); self.b += u30(a.string(v))
        elif isinstance(v, float):
            self.op(0x2f); self.b += u30(a.double(v))
        elif isinstance(v, int):
            if -128 <= v < 128:
                self.op(0x24, v & 0xFF)
            elif -0x80000000 <= v < 0x80000000:
                self.op(0x2d); self.b += u30(a.int_(v))
            else:
                self.op(0x2f); self.b += u30(a.double(float(v)))
        else:
            raise TypeError(v)

    def getlocal(self, i):
        self.op(0x62); self.b += u30(i)

    def setlocal(self, i):
        self.op(0x63); self.b += u30(i)

    def new(self, cls, args):
        self.op(0x5d); self.b += u30(self.abc.name(cls))      # findpropstrict
        for v in args:
            self.push(v)
        self.op(0x4a); self.b += u30(self.abc.name(cls)) + u30(len(args))

    def getproperty(self, n):
        self.op(0x66); self.b += u30(self.abc.name(n))

    def callproperty(self, n, argc):
        self.op(0x46); self.b += u30(self.abc.name(n)) + u30(argc)

    def callpropvoid(self, n, argc):
        self.op(0x4f); self.b += u30(self.abc.name(n)) + u30(argc)

    def loop(self, var_i, start, count, body):
        self.push(start); self.setlocal(var_i)
        self.op(0x10); jpos = len(self.b); self.b += s24(0)
        top = len(self.b)
        self.op(0x09)
        body()
        self.getlocal(var_i); self.op(0x91); self.setlocal(var_i)
        cond = len(self.b)
        self.b[jpos:jpos + 3] = s24(cond - (jpos + 3))
        self.getlocal(var_i); self.push(count)
        self.op(0x15); here = len(self.b) + 3
        self.b += s24(top - here)


SIZE = 30

CASES = [
    ('none', None, []),
    ('blur', 'BlurFilter', [4, 4, 1]),
    ('glow', 'GlowFilter', [0x0000FF, 1.0, 6, 6, 2, 1]),
    ('dropshadow', 'DropShadowFilter', [4, 45, 0, 1.0, 4, 4, 1, 1]),
    ('bevel', 'BevelFilter', []),
    ('convolution', 'ConvolutionFilter', [3, 3, [1, 1, 1, 1, 1, 1, 1, 1, 1], 9]),
]

# s27 w2b-filter-kernels-residual: the regression/ copy HOLDS these cases back
# (their Flash rows are 1-2 levels off a still-unresolved bevel sample, see
# SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/w2b-filter-kernels-residual-report.md). Every case
# runs on fresh objects, so dropping one leaves the others' Flash lines as
# captured; output.txt is the Flash capture minus the held cases' lines.
# Set HELD = () to rebuild the full Flash probe. s28 w2-filter-residuals-land
# restored the held bevel case(s) (fb_bevel_offset closes them; was ('bevel',)).
HELD = ()
CASES = [c for c in CASES if c[0] not in HELD]


def build_code(abc):
    c = Code(abc)
    BD, SP, I, S, G = 1, 2, 3, 4, 5
    c.op(0xd0, 0x30)
    for (label, cls, args) in CASES:
        c.new('Sprite', []); c.setlocal(SP)
        c.getlocal(SP); c.getproperty('graphics'); c.setlocal(G)
        c.getlocal(G); c.push(0xFF0000); c.callpropvoid('beginFill', 1)
        c.getlocal(G); c.push(10); c.push(10); c.push(10); c.push(10)
        c.callpropvoid('drawRect', 4)
        c.getlocal(G); c.callpropvoid('endFill', 0)
        if cls is not None:
            c.getlocal(SP)
            plain = [a for a in args if not isinstance(a, list)]
            # constructor args, an inline array literal where given
            c.op(0x5d); c.b += u30(abc.name(cls))
            for a in args:
                if isinstance(a, list):
                    for v in a:
                        c.push(v)
                    c.op(0x56); c.b += u30(len(a))          # newarray
                else:
                    c.push(a)
            c.op(0x4a); c.b += u30(abc.name(cls)) + u30(len(args))
            c.op(0x56); c.b += u30(1)                       # [filter]
            c.op(0x61); c.b += u30(abc.name('filters'))     # setproperty
        c.new('BitmapData', [SIZE, SIZE, True, 0]); c.setlocal(BD)
        c.getlocal(BD); c.getlocal(SP); c.callpropvoid('draw', 1)
        for axis in ('y', 'x'):
            c.push(label + ' ' + axis + '=15:'); c.setlocal(S)
            def body():
                c.getlocal(S); c.push(' '); c.op(0xa0)
                c.getlocal(BD)
                if axis == 'y':
                    c.getlocal(I); c.push(15)
                else:
                    c.push(15); c.getlocal(I)
                c.callproperty('getPixel32', 2)
                c.push(16); c.callproperty('toString', 1)
                c.op(0xa0); c.setlocal(S)
            c.loop(I, 0, SIZE, body)
            c.op(0x5d); c.b += u30(abc.name('trace'))
            c.getlocal(S)
            c.callpropvoid('trace', 1)
    c.op(0x5d); c.b += u30(abc.name('trace'))
    c.push('done')
    c.callpropvoid('trace', 1)
    c.op(0x47)
    return bytes(c.b), G + 1


def build_abc():
    abc = Abc()
    build_code(abc)                        # intern everything
    code, nlocals = build_code(abc)
    for n in abc.names[1:]:
        abc.string(n)
    for n in NS:
        abc.string(n)
    out = bytearray(struct.pack('<HH', 16, 46))
    out += u30(len(abc.ints))
    for v in abc.ints[1:]:
        out += u30(v & 0xFFFFFFFF) if v >= 0 else u30(v & 0xFFFFFFFF)
    out += u30(0)                                     # uints
    out += u30(len(abc.doubles))
    for v in abc.doubles[1:]:
        out += struct.pack('<d', v)
    out += u30(len(abc.strings))
    for s in abc.strings[1:]:
        b = s.encode('utf-8')
        out += u30(len(b)) + b
    out += u30(len(NS) + 1)                           # namespaces
    for n in NS:
        out += bytes([0x16]) + u30(abc.string(n))     # PackageNamespace
    out += u30(2) + u30(len(NS)) + b''.join(u30(i + 1) for i in range(len(NS)))
    out += u30(len(abc.names))
    for n in abc.names[1:]:
        out += bytes([0x09]) + u30(abc.string(n)) + u30(1)   # Multiname(name, nsset 1)
    out += u30(1) + u30(0) + u30(0) + u30(0) + bytes([0])    # 1 method
    out += u30(0) + u30(0)                                   # metadata, classes
    out += u30(1) + u30(0) + u30(0)                          # script 0
    out += u30(1) + u30(0) + u30(24) + u30(nlocals) + u30(0) + u30(1)
    out += u30(len(code)) + code
    out += u30(0) + u30(0)
    return bytes(out)


def tag(code, payload):
    if len(payload) >= 63:
        return struct.pack('<HI', (code << 6) | 63, len(payload)) + payload
    return struct.pack('<H', (code << 6) | len(payload)) + payload


def build_swf():
    abc = build_abc()
    rect = bytes([0x78, 0x00, 0x05, 0x5F, 0x00, 0x00, 0x0F, 0xA0, 0x00])  # 550x400
    body = rect + struct.pack('<HH', 30 << 8, 1)
    body += tag(69, struct.pack('<I', 0x08))
    body += tag(82, struct.pack('<I', 0) + b'drawfilt\x00' + abc)
    body += tag(1, b'')
    body += tag(0, b'')
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), 'test.swf')
    open(out, 'wb').write(build_swf())
    print('wrote', out)
