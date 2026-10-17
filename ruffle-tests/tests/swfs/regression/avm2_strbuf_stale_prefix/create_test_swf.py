#!/usr/bin/env python3
"""AVM2 append-in-place string buffers: stale prefixes keep their value.

Usage: create_test_swf.py [out.swf]   (default: test.swf beside this script)

Pins down `avm2_string_concat`'s append-in-place path (s22 w2-strbuf): a long
`s += x` writes x into s's buffer and returns a new header sharing it, so the
OLD header `p` (a prefix) loses its `utf8[len] == '\\0'`. Every row reads such a
stale prefix after a later append, through a different consumer (length,
equality, indexOf/lastIndexOf, charAt/slice, Number/parseInt, split, RegExp
match, a property key), plus two branches appended off one stale prefix (the
second must not clobber the first) and a stale prefix left behind while the
frontier keeps growing in place. A consumer that read `utf8` as a C string
would see the longer string (e.g. Number(q) = 75 instead of 7).

No mxmlc in the cloud, so the SWF is hand-assembled: one DoABC whose only
script's init method holds the whole test (top-level code, like the avmplus
acceptance tests). Expected output follows from ECMA-262/AS3 semantics; see the
w2-strbuf report's LOCAL ORACLE REQUESTS for the Ruffle confirmation.
"""
import os
import struct
import sys


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
        self.strings = [None]        # index 0 is implicit; never emitted
        self.multinames = [None]     # index 0 is implicit

    def string(self, s):
        if s not in self.strings:
            self.strings.append(s)
        return self.strings.index(s)

    def qname(self, name):
        key = ('q', name)
        if key not in self.multinames:
            self.multinames.append(key)
        return self.multinames.index(key)


class Code:
    def __init__(self, abc):
        self.abc = abc
        self.b = bytearray()

    def op(self, *bs):
        self.b += bytes(bs)

    def pushstring(self, s):
        self.op(0x2c); self.b += u30(self.abc.string(s))

    def pushshort(self, v):
        self.op(0x25); self.b += u30(v & 0xFFFFFFFF if v >= 0 else (v & 0x3FFFFFFF))

    def getlocal(self, i):
        self.op(0x62); self.b += u30(i)

    def setlocal(self, i):
        self.op(0x63); self.b += u30(i)

    def findpropstrict(self, n):
        self.op(0x5d); self.b += u30(self.abc.qname(n))

    def getlex(self, n):
        self.op(0x60); self.b += u30(self.abc.qname(n))

    def getproperty(self, n):
        self.op(0x66); self.b += u30(self.abc.qname(n))

    def callproperty(self, n, argc):
        self.op(0x46); self.b += u30(self.abc.qname(n)) + u30(argc)

    def callpropvoid(self, n, argc):
        self.op(0x4f); self.b += u30(self.abc.qname(n)) + u30(argc)

    def add(self):
        self.op(0xa0)

    def convert_s(self):
        self.op(0x70)

    def loop(self, var_i, count, body):
        # for (i = 0; i < count; i++) body()
        self.op(0x24, 0); self.setlocal(var_i)              # pushbyte 0
        self.op(0x10); jpos = len(self.b); self.b += s24(0)  # jump -> cond
        top = len(self.b)
        self.op(0x09)                                        # label
        body()
        self.getlocal(var_i); self.op(0x91); self.setlocal(var_i)  # increment
        cond = len(self.b)
        self.b[jpos:jpos + 3] = s24(cond - (jpos + 3))
        self.getlocal(var_i); self.pushshort(count)
        self.op(0x15); here = len(self.b) + 3                # iflt -> top
        self.b += s24(top - here)

    def trace_expr(self, emit):
        self.findpropstrict('trace')
        emit()
        self.callpropvoid('trace', 1)


N = 5000  # > AVM2_STRBUF_MIN_LEN (4096): the buffer path


def build_code(abc):
    c = Code(abc)
    S, P, I, Q, D, B, X1, X2, O = 1, 2, 3, 4, 5, 6, 7, 8, 9
    c.op(0xd0, 0x30)                       # getlocal0; pushscope

    # s = ""; for (i < N) s += "a"; p = s; s += "XYZ"
    c.pushstring(''); c.setlocal(S)
    def app_a():
        c.getlocal(S); c.pushstring('a'); c.add(); c.setlocal(S)
    c.loop(I, N, app_a)
    c.getlocal(S); c.setlocal(P)
    c.getlocal(S); c.pushstring('XYZ'); c.add(); c.setlocal(S)

    def row(label, emit):
        c.trace_expr(lambda: (c.pushstring(label), emit(), c.add()))

    row('p.length=', lambda: (c.getlocal(P), c.getproperty('length')))
    row('s.length=', lambda: (c.getlocal(S), c.getproperty('length')))
    row('p==prefix=', lambda: (c.getlocal(P), c.getlocal(S), c.op(0x24, 0),
                                c.getlocal(P), c.getproperty('length'),
                                c.callproperty('substr', 2), c.op(0xab)))
    row('p.indexOf(X)=', lambda: (c.getlocal(P), c.pushstring('X'),
                                   c.callproperty('indexOf', 1)))
    row('p.lastIndexOf(a)=', lambda: (c.getlocal(P), c.pushstring('a'),
                                       c.callproperty('lastIndexOf', 1)))
    row('p.slice(-3)=', lambda: (c.getlocal(P), c.op(0x24, 0xfd),
                                  c.callproperty('slice', 1)))
    row('p.charAt(N)=[', lambda: (c.getlocal(P), c.pushshort(N),
                                   c.callproperty('charAt', 1),
                                   c.pushstring(']'), c.add()))
    row('p.split(a).length=', lambda: (c.getlocal(P), c.pushstring('a'),
                                        c.callproperty('split', 1),
                                        c.getproperty('length')))
    row('p.match(a+$)=', lambda: (c.getlocal(P), c.findpropstrict('RegExp'),
                                   c.pushstring('a+$'),
                                   c.op(0x4a), c.b.extend(u30(abc.qname('RegExp')) + u30(1)),  # constructprop
                                   c.callproperty('match', 1),
                                   c.getproperty('0'), c.getproperty('length')))

    # Numbers: q = "   ...7" (N chars, leading StrWhiteSpace); d = q + "5"
    # (stale q). Spaces, not zeros: the number parser caps its digit copy.
    c.pushstring(''); c.setlocal(D)
    def app_0():
        c.getlocal(D); c.pushstring(' '); c.add(); c.setlocal(D)
    c.loop(I, N - 1, app_0)
    c.getlocal(D); c.pushstring('7'); c.add(); c.setlocal(Q)
    c.getlocal(Q); c.pushstring('5'); c.add(); c.setlocal(D)
    row('Number(q)=', lambda: (c.findpropstrict('Number'), c.getlocal(Q),
                                c.callproperty('Number', 1)))
    row('parseInt(q)=', lambda: (c.findpropstrict('parseInt'), c.getlocal(Q),
                                  c.callproperty('parseInt', 1)))
    row('Number(d)=', lambda: (c.findpropstrict('Number'), c.getlocal(D),
                                c.callproperty('Number', 1)))

    # Two branches off stale p: x1 = p + "1"; x2 = p + "2".
    c.getlocal(P); c.pushstring('1'); c.add(); c.setlocal(X1)
    c.getlocal(P); c.pushstring('2'); c.add(); c.setlocal(X2)
    row('x1.slice(-2)=', lambda: (c.getlocal(X1), c.op(0x24, 0xfe),
                                   c.callproperty('slice', 1)))
    row('x2.slice(-2)=', lambda: (c.getlocal(X2), c.op(0x24, 0xfe),
                                   c.callproperty('slice', 1)))
    row('s.slice(-4)=', lambda: (c.getlocal(S), c.op(0x24, 0xfc),
                                  c.callproperty('slice', 1)))

    # Property keys: o[p] = "P"; o[s] = "S"; distinct entries.
    c.op(0x55); c.b += u30(0); c.setlocal(O)              # newobject {}
    def setkey(var, val):
        c.getlocal(O); c.getlocal(var); c.pushstring(val)
        c.op(0x61); c.b += u30(abc.rt_multiname)          # setproperty [rt]
    def getkey(var):
        c.getlocal(O); c.getlocal(var)
        c.op(0x66); c.b += u30(abc.rt_multiname)          # getproperty [rt]
    setkey(P, 'P'); setkey(S, 'S')
    row('o[p]=', lambda: getkey(P))
    row('o[s]=', lambda: getkey(S))

    # Stale prefix after a frontier that keeps growing (in-place appends).
    c.getlocal(S); c.setlocal(B)
    def app_b():
        c.getlocal(S); c.pushstring('b'); c.add(); c.setlocal(S)
    c.loop(I, N, app_b)
    row('b.length=', lambda: (c.getlocal(B), c.getproperty('length')))
    row('b.slice(-3)=', lambda: (c.getlocal(B), c.op(0x24, 0xfd),
                                  c.callproperty('slice', 1)))
    row('s.length=', lambda: (c.getlocal(S), c.getproperty('length')))

    c.trace_expr(lambda: c.pushstring('done'))
    c.op(0x47)                                             # returnvoid
    return bytes(c.b), O + 1


def build_abc():
    abc = Abc()
    # Pass 1 interns every string/QName (with a placeholder index for the
    # runtime-name multiname); pass 2 re-emits the code against the final
    # pool, whose last multiname is a MultinameL over ns set [public].
    abc.rt_multiname = 0x7FFF
    build_code(abc)
    abc.rt_multiname = len(abc.multinames)
    code, nlocals = build_code(abc)

    out = bytearray()
    out += struct.pack('<HH', 16, 46)
    pool = bytearray()
    pool += u30(0) + u30(0) + u30(0)
    for (_, n) in abc.multinames[1:]:
        abc.string(n)
    pool += u30(len(abc.strings))
    for s in abc.strings[1:]:
        b = s.encode('utf-8')
        pool += u30(len(b)) + b
    pool += u30(2) + bytes([0x16]) + u30(abc.string(''))
    pool += u30(2) + u30(1) + u30(1)                 # ns set 1 = [public]
    pool += u30(len(abc.multinames) + 1)
    for (_, n) in abc.multinames[1:]:
        pool += bytes([0x07]) + u30(1) + u30(abc.string(n))
    pool += bytes([0x1B]) + u30(1)                   # MultinameL, ns set 1
    out += pool
    # methods: 1 (script init), no params, no name, no flags
    out += u30(1) + u30(0) + u30(0) + u30(0) + bytes([0])
    out += u30(0)                                    # metadata
    out += u30(0)                                    # classes
    out += u30(1) + u30(0) + u30(0)                  # script 0: init=0, no traits
    # method bodies
    out += u30(1)
    out += u30(0)                                    # method
    out += u30(16)                                   # max_stack
    out += u30(nlocals)                              # local_count
    out += u30(0) + u30(1)                           # init/max scope depth
    out += u30(len(code)) + code
    out += u30(0) + u30(0)                           # exceptions, traits
    return bytes(out)


def tag(code, payload):
    if len(payload) >= 63:
        return struct.pack('<HI', (code << 6) | 63, len(payload)) + payload
    return struct.pack('<H', (code << 6) | len(payload)) + payload


def build_swf():
    abc = build_abc()
    rect = bytes([0x78, 0x00, 0x05, 0x5F, 0x00, 0x00, 0x0F, 0xA0, 0x00])  # 0..550x400
    body = rect + struct.pack('<HH', 30 << 8, 1)
    body += tag(69, struct.pack('<I', 0x08))                 # FileAttributes: AS3
    body += tag(82, struct.pack('<I', 0) + b'strbuf\x00' + abc)  # DoABC2 (eager)
    body += tag(1, b'')                                      # ShowFrame
    body += tag(0, b'')
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        os.path.dirname(os.path.abspath(__file__)), 'test.swf')
    open(out, 'wb').write(build_swf())
    print('wrote', out)
