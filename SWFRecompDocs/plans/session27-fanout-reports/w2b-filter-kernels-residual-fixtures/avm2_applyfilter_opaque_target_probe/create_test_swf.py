#!/usr/bin/env python3
"""FLASH ORACLE PROBE (s27 w2b-filter-kernels-residual): applyFilter onto an
OPAQUE target. The gradient probe's `blur trans->opaque` row (Flash ff1e253b
over a WHITE target) fits `c + (dst * (255 - a)) >> 8` -- but a white target
cannot tell "composited over the destination pixel" from "composited over
white". This probe blurs the same transparent source onto opaque targets of
four colours and traces rows y=6 and y=10 (the partial-alpha blur ring), plus
ColorMatrix (alpha-halving) and Convolution (divisor 2) onto an opaque target,
whose partial alphas take the copy arm rather than fb_write_grid.

Usage: create_test_swf.py [out.swf]. output.txt is OUR output (provisional)
until the Flash capture replaces it.
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


SIZE = 20
ROWS = (6, 10)
GC = [0xFF0000, 0x00FF00, 0x0000FF]
GA = [0.0, 0.5, 1.0]
GR = [0, 128, 255]
BC = [0xFFFFFF, 0xFF0000, 0x000000]
BA = [1.0, 0.0, 1.0]
CM = [0.5, 0, 0, 0, 0,  0, 1, 0, 0, 0,  0, 0, 1, 0, 0,  0, 0, 0, 1, 0]

CM_A = [1, 0, 0, 0, 0,  0, 1, 0, 0, 0,  0, 0, 1, 0, 0,  0, 0, 0, 0.5, 0]
# (label, source kind, target colour (None = transparent), filter class, args, trace rows?)
CASES = [
    ('blur ->transparent', 'T', None, 'BlurFilter', [4, 4, 1], True),
    ('blur ->white', 'T', 0xFFFFFFFF, 'BlurFilter', [4, 4, 1], True),
    ('blur ->336699', 'T', 0xFF336699, 'BlurFilter', [4, 4, 1], True),
    ('blur ->black', 'T', 0xFF000000, 'BlurFilter', [4, 4, 1], True),
    ('blur ->ff8000', 'T', 0xFFFF8000, 'BlurFilter', [4, 4, 1], True),
    ('colormatrix alpha.5 ->336699', 'T', 0xFF336699, 'ColorMatrixFilter', [CM_A], True),
    ('convolution /2 ->336699', 'T', 0xFF336699, 'ConvolutionFilter', [3, 3, [0, 0, 0, 0, 1, 0, 0, 0, 0], 2], True),
]



def push_arg(c, a):
    if isinstance(a, list):
        for v in a:
            c.push(v)
        c.op(0x56); c.b += u30(len(a))          # newarray
    else:
        c.push(a)


def build_code(abc):
    c = Code(abc)
    SRC, OSRC, DST, I, S, E = 1, 2, 3, 4, 5, 6
    excs = []
    c.op(0xd0, 0x30)                       # getlocal0; pushscope
    c.new('BitmapData', [SIZE, SIZE, True, 0]); c.setlocal(SRC)
    c.new('BitmapData', [SIZE, SIZE, False, 0xFF336699]); c.setlocal(OSRC)
    for (x, y, w, h, col) in ((5, 5, 10, 10, 0x993366FF), (8, 8, 4, 4, 0xFF000000)):
        c.getlocal(SRC); c.new('Rectangle', [x, y, w, h]); c.push(col)
        c.callpropvoid('fillRect', 2)
    c.getlocal(OSRC); c.new('Rectangle', [8, 8, 4, 4]); c.push(0xFF000000)
    c.callpropvoid('fillRect', 2)
    def trace_top():                       # trace(<string on stack>) via local S
        c.setlocal(S)
        c.op(0x5d); c.b += u30(abc.name('trace'))
        c.getlocal(S)
        c.callpropvoid('trace', 1)
    for (label, sk, tcol, cls, args, rows) in CASES:
        frm = len(c.b)
        c.new('BitmapData', [SIZE, SIZE, tcol is None, 0 if tcol is None else tcol])
        c.setlocal(DST)
        c.getlocal(DST)
        c.getlocal(SRC if sk == 'T' else OSRC)
        c.getlocal(SRC); c.getproperty('rect')
        c.new('Point', [0, 0])
        c.op(0x5d); c.b += u30(abc.name(cls))
        for a in args:
            push_arg(c, a)
        c.op(0x4a); c.b += u30(abc.name(cls)) + u30(len(args))
        c.callpropvoid('applyFilter', 4)
        if rows:
            for y in ROWS:
                c.push(label + ' y=' + str(y) + ':'); c.setlocal(S)
                def body():
                    c.getlocal(S); c.push(' '); c.op(0xa0)
                    c.getlocal(DST); c.getlocal(I); c.push(y)
                    c.callproperty('getPixel32', 2)
                    c.push(16); c.callproperty('toString', 1)
                    c.op(0xa0); c.setlocal(S)
                c.loop(I, 0, SIZE, body)
                c.getlocal(S); trace_top()
        else:
            c.push(label + ': ok ')
            c.getlocal(DST); c.push(10); c.push(10)
            c.callproperty('getPixel32', 2)
            c.push(16); c.callproperty('toString', 1)
            c.op(0xa0); trace_top()
        to = len(c.b)
        c.op(0x10); jpos = len(c.b); c.b += s24(0)          # jump over the handler
        target = len(c.b)
        c.setlocal(E)
        c.op(0xd0, 0x30)                                    # re-push the global scope
        c.push(label + ': err '); c.getlocal(E); c.getproperty('errorID')
        c.op(0xa0); trace_top()
        after = len(c.b)
        c.b[jpos:jpos + 3] = s24(after - (jpos + 3))
        excs.append((frm, to, target))
    c.op(0x5d); c.b += u30(abc.name('trace'))
    c.push('done')
    c.callpropvoid('trace', 1)
    c.op(0x47)
    return bytes(c.b), E + 1, excs


def build_abc():
    abc = Abc()
    build_code(abc)                        # intern everything
    code, nlocals, excs = build_code(abc)
    for n in abc.names[1:]:
        abc.string(n)
    for n in NS:
        abc.string(n)
    out = bytearray(struct.pack('<HH', 16, 46))
    out += u30(len(abc.ints))
    for v in abc.ints[1:]:
        out += u30(v & 0xFFFFFFFF)
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
    out += u30(1) + u30(0) + u30(40) + u30(nlocals) + u30(0) + u30(1)
    out += u30(len(code)) + code
    out += u30(len(excs))
    for (f, t, tg) in excs:
        out += u30(f) + u30(t) + u30(tg) + u30(0) + u30(0)   # catch (e:*) {}
    out += u30(0)                                            # traits
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
    body += tag(82, struct.pack('<I', 0) + b'opaqueprobe\x00' + abc)
    body += tag(1, b'')
    body += tag(0, b'')
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), 'test.swf')
    open(out, 'wb').write(build_swf())
    print('wrote', out)
