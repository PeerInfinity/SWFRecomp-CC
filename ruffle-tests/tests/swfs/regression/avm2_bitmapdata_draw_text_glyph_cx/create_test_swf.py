#!/usr/bin/env python3
"""AVM2 BitmapData.draw() of a TextField: glyph and box colour under a tint,
DEVICE vs EMBEDDED font (s27 w2b-draw-text-tint).

Usage: create_test_swf.py [out.swf]   (default: test.swf beside this script)

This is a no-mxmlc TWIN of Test.as (the s27 w2-draw-cx-text oracle request,
kept beside this script). Flash Player 32 traced the mxmlc build of Test.as
(SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/w2-local-oracles/w2-draw-cx-text/
avm2_bitmapdata_draw_text_glyph_cx/flash.direct.txt); that SWF was not
archived and the cloud has no mxmlc, so this script emits the same API calls
in the same order from a hand-assembled script-init ABC.

The embedded font is NOT synthetic: the DefineFont3 ("TestFont", DejaVu Sans,
U+0020-U+007E) and DefineFontName tags are copied byte-for-byte from the
mxmlc-built ../avm2_bitmapdata_draw_textfield/test.swf, the same [Embed] that
Test.as declares. Like the mxmlc build, nothing calls Font.registerFont: Flash
resolves an embedded DefineFont3 by name.

Glyph probes (G*) count EXACT solid pixels on a transparent 200x60 target:
glyphs are red 0xFF0000; the tint (0,1,1,1, 0,255,0,0) turns red into green.
Box probes (X*) read the centre pixel of an opaque-blue 40x20 target behind a
textless field with a red background.

Flash's answer: a DEVICE field draws no solid glyph pixel and its box is never
tinted; an EMBEDDED field's glyphs AND box follow the draw ct, a descendant
cx and holder+ct.
"""
import os
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
NS = ['', 'flash.display', 'flash.geom', 'flash.text']


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

    def _idx(self, pool, v):
        if v not in pool:
            pool.append(v)
        return pool.index(v)

    def string(self, s): return self._idx(self.strings, s)
    def name(self, n): return self._idx(self.names, n)
    def int_(self, v): return self._idx(self.ints, v)
    def double(self, v): return self._idx(self.doubles, v)


class Code:
    def __init__(self, abc):
        self.abc = abc
        self.b = bytearray()

    def op(self, *bs):
        self.b += bytes(bs)

    def push(self, v):
        a = self.abc
        if v is None:
            self.op(0x20)
        elif isinstance(v, bool):
            self.op(0x26 if v else 0x27)
        elif isinstance(v, str):
            self.op(0x2c); self.b += u30(a.string(v))
        elif isinstance(v, float):
            self.op(0x2f); self.b += u30(a.double(v))
        elif -128 <= v < 128:
            self.op(0x24, v & 0xFF)
        elif -0x80000000 <= v < 0x80000000:
            self.op(0x2d); self.b += u30(a.int_(v))
        else:
            self.op(0x2f); self.b += u30(a.double(float(v)))

    def get(self, i): self.op(0x62); self.b += u30(i)
    def set(self, i): self.op(0x63); self.b += u30(i)
    def getp(self, n): self.op(0x66); self.b += u30(self.abc.name(n))
    def setp(self, n): self.op(0x61); self.b += u30(self.abc.name(n))

    def new(self, cls, args):
        self.op(0x5d); self.b += u30(self.abc.name(cls))
        for v in args:
            self.push(v)
        self.op(0x4a); self.b += u30(self.abc.name(cls)) + u30(len(args))

    def call(self, n, argc): self.op(0x46); self.b += u30(self.abc.name(n)) + u30(argc)
    def callv(self, n, argc): self.op(0x4f); self.b += u30(self.abc.name(n)) + u30(argc)

    def trace_top(self, emit):
        self.op(0x5d); self.b += u30(self.abc.name('trace'))
        emit()
        self.callv('trace', 1)

    def if_eq_skip(self, emit_lhs, rhs, body):
        """if (lhs == rhs) body  (ifne over body)"""
        emit_lhs(); self.push(rhs)
        self.op(0x14); j = len(self.b); self.b += s24(0)
        body()
        self.b[j:j + 3] = s24(len(self.b) - (j + 3))

    def loop(self, var_i, count, body):
        self.push(0); self.set(var_i)
        self.op(0x10); jpos = len(self.b); self.b += s24(0)
        top = len(self.b)
        self.op(0x09)
        body()
        self.get(var_i); self.op(0x91); self.set(var_i)
        self.b[jpos:jpos + 3] = s24(len(self.b) - (jpos + 3))
        self.get(var_i); self.push(count)
        self.op(0x15); here = len(self.b) + 3
        self.b += s24(top - here)


BD, TF, H, X, Y, RED, GREEN, CT = 1, 2, 3, 4, 5, 6, 7, 8
NLOCALS = 9


def build_code(abc):
    c = Code(abc)
    c.op(0xd0, 0x30)

    def tint():
        c.new('ColorTransform', [0, 1, 1, 1, 0, 255, 0, 0])

    def glyph_field(embed):
        c.new('TextField', []); c.set(TF)
        c.get(TF); c.push(embed); c.setp('embedFonts')
        c.get(TF); c.push(False); c.setp('selectable')
        c.get(TF); c.push(200); c.setp('width')
        c.get(TF); c.push(60); c.setp('height')
        c.get(TF)
        c.new('TextFormat', ['TestFont' if embed else '_sans', 40, 0xFF0000, True])
        c.setp('defaultTextFormat')
        c.get(TF); c.push('WMW'); c.setp('text')

    def box_field(embed):
        c.new('TextField', []); c.set(TF)
        c.get(TF); c.push(embed); c.setp('embedFonts')
        c.get(TF); c.push(40); c.setp('width')
        c.get(TF); c.push(20); c.setp('height')
        c.get(TF); c.push(True); c.setp('background')
        c.get(TF); c.push(0xFF0000); c.setp('backgroundColor')

    def holder(tinted):
        # returns with the holder in H; the source local is then H
        c.new('Sprite', []); c.set(H)
        if tinted:
            c.get(TF); c.getp('transform'); tint(); c.setp('colorTransform')
        c.get(H); c.get(TF); c.callv('addChild', 1)

    def draw(src, with_ct):
        c.get(BD); c.get(src); c.push(None)
        if with_ct:
            tint()
        else:
            c.push(None)
        c.callv('draw', 3)

    def glyphs(label, src, with_ct):
        c.new('BitmapData', [200, 60, True, 0]); c.set(BD)
        draw(src, with_ct)
        c.push(False); c.set(RED); c.push(False); c.set(GREEN)

        def inner():
            def px():
                c.get(BD); c.get(X); c.get(Y); c.call('getPixel32', 2)
            c.if_eq_skip(px, 0xFFFF0000, lambda: (c.push(True), c.set(RED)))
            c.if_eq_skip(px, 0xFF00FF00, lambda: (c.push(True), c.set(GREEN)))
        c.loop(Y, 60, lambda: c.loop(X, 200, inner))

        def msg():
            c.push(label + ' red='); c.get(RED); c.op(0xa0)
            c.push(' green='); c.op(0xa0); c.get(GREEN); c.op(0xa0)
        c.trace_top(msg)

    def box(label, src, with_ct):
        c.new('BitmapData', [40, 20, False, 0x0000FF]); c.set(BD)
        draw(src, with_ct)

        def msg():
            c.push(label + ' = ')
            c.get(BD); c.push(20); c.push(10); c.call('getPixel', 2)
            c.push(16); c.call('toString', 1)
            c.op(0xa0)
        c.trace_top(msg)

    for embed in (False, True):
        k = 'embed' if embed else 'device'
        glyph_field(embed); glyphs('G %s draw(tf)' % k, TF, False)
        glyph_field(embed); glyphs('G %s draw(tf,ct)' % k, TF, True)
        glyph_field(embed); holder(True); glyphs('G %s draw(h>tinted tf)' % k, H, False)
        glyph_field(embed); holder(False); glyphs('G %s draw(h>tf,ct)' % k, H, True)
        box_field(embed); box('X %s box draw(tf)' % k, TF, False)
        box_field(embed); box('X %s box draw(tf,ct)' % k, TF, True)
        box_field(embed); holder(True); box('X %s box draw(h>tinted tf)' % k, H, False)
        box_field(embed); holder(False); box('X %s box draw(h>tf,ct)' % k, H, True)
    c.op(0x47)
    return bytes(c.b)


def build_abc():
    abc = Abc()
    build_code(abc)                        # intern everything
    code = build_code(abc)
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
    out += u30(1) + u30(0) + u30(24) + u30(NLOCALS) + u30(0) + u30(4)
    out += u30(len(code)) + code
    out += u30(0) + u30(0)
    return bytes(out)


def tag(code, payload):
    if len(payload) >= 63:
        return struct.pack('<HI', (code << 6) | 63, len(payload)) + payload
    return struct.pack('<H', (code << 6) | len(payload)) + payload


def font_tags():
    """DefineFont3 (75) + DefineFontName (88), verbatim from the mxmlc SWF."""
    d = open(os.path.join(HERE, '..', 'avm2_bitmapdata_draw_textfield',
                          'test.swf'), 'rb').read()
    if d[:3] == b'CWS':
        d = d[:8] + zlib.decompress(d[8:])
    nb = d[8] >> 3
    p = 8 + (5 + 4 * nb + 7) // 8 + 4
    out = b''
    while p < len(d):
        h = struct.unpack('<H', d[p:p + 2])[0]
        code, ln, hp = h >> 6, h & 63, 2
        if ln == 63:
            ln, hp = struct.unpack('<I', d[p + 2:p + 6])[0], 6
        if code in (75, 88):
            out += d[p:p + hp + ln]
        p += hp + ln
        if code == 0:
            break
    assert out, 'font tags not found'
    return out


def build_swf():
    abc = build_abc()
    rect = bytes([0x78, 0x00, 0x05, 0x5F, 0x00, 0x00, 0x0F, 0xA0, 0x00])  # 550x400
    body = rect + struct.pack('<HH', 30 << 8, 1)
    body += tag(69, struct.pack('<I', 0x08))
    body += font_tags()
    body += tag(82, struct.pack('<I', 0) + b'drawtextcx\x00' + abc)
    body += tag(1, b'')
    body += tag(0, b'')
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, 'test.swf')
    open(out, 'wb').write(build_swf())
    print('wrote', out)
