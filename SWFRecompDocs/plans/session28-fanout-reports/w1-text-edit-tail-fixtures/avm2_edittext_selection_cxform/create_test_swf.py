#!/usr/bin/env python3
"""avm2_edittext_selection_cxform: is an EditText SELECTION BACKGROUND tinted by
the field's (and its parents') colorTransform?  (s28 w1-text-edit-tail (c);
reworks s27 w2-avm2-text-tail-fixtures/avm2_edittext_selection_cxform, whose
constructor touched `stage` and so threw under run_image.py's Loader wrapper.)

Usage: create_test_swf.py [out.swf]  (default: test.swf beside this script)
No mxmlc: a hand-assembled ABC with a document class `Test extends Sprite`
(SymbolClass 0 -> Test). Its constructor registers an ADDED_TO_STAGE closure and,
when `stage` is already set (direct run), dispatches that event itself; a
script slot `g_done` makes the closure run once. Test.as beside this script is
the same program in AS3 (build_swf.sh builds it with mxmlc, for the record).

The font is NOT synthetic: DefineFont3 "TestFont" (DejaVu Sans, U+0020-U+007E)
and DefineFontName are copied byte-for-byte from the mxmlc-built
regression/avm2_bitmapdata_draw_textfield/test.swf (Flash-validated there).

Rows (each "ababa", TestFont 20, setSelection(1,4) = "bab"):
  y=0   control, unfocused + alwaysShowSelection, no tint
  y=30  unfocused, field cx (0,0,0,1, 255,0,0,0)
  y=60  unfocused, field cx (1,1,1,1, 0,0,255,0)
  y=90  unfocused, PARENT Sprite cx (0,0,0,1, 255,0,255,0)
  y=120 FOCUSED (stage.focus), field cx (0,0,0,1, 0,200,0,0)
Read the rect colour in the gaps between glyphs:
  untinted (Ruffle) -> 0x555555 rows 0-3, 0x000000 row 4
  tinted (master)   -> row1 0xFF0000, row2 0x5555FF, row3 0xFF00FF, row4 0x00C800
"""
import os
import struct
import sys
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
NS = ['', 'flash.display', 'flash.geom', 'flash.text', 'flash.events']


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
        self.names = [None]      # ('m', name) multiname-nsset | ('q', ns_index, name) QName
        self.ints = [None]

    def _idx(self, pool, v):
        if v not in pool:
            pool.append(v)
        return pool.index(v)

    def string(self, s): return self._idx(self.strings, s)
    def name(self, n): return self._idx(self.names, ('m', n))
    def qname(self, ns, n): return self._idx(self.names, ('q', NS.index(ns), n))
    def int_(self, v): return self._idx(self.ints, v)


class Code:
    def __init__(self, abc):
        self.abc = abc
        self.b = bytearray()

    def op(self, *bs): self.b += bytes(bs)

    def push(self, v):
        if isinstance(v, bool):
            self.op(0x26 if v else 0x27)
        elif isinstance(v, str):
            self.op(0x2c); self.b += u30(self.abc.string(v))
        elif -128 <= v < 128:
            self.op(0x24, v & 0xFF)
        else:
            self.op(0x2d); self.b += u30(self.abc.int_(v))

    def get(self, i):
        if i <= 3: self.op(0xd0 + i)
        else: self.op(0x62); self.b += u30(i)

    def set(self, i):
        if i <= 3: self.op(0xd4 + i)
        else: self.op(0x63); self.b += u30(i)

    def mn(self, opc, n, *extra):
        self.op(opc); self.b += u30(self.abc.name(n))
        for e in extra: self.b += u30(e)

    def getp(self, n): self.mn(0x66, n)
    def setp(self, n): self.mn(0x61, n)
    def callv(self, n, argc): self.mn(0x4f, n, argc)
    def getlex(self, n): self.mn(0x60, n)

    def new(self, cls, args):
        self.mn(0x5d, cls)
        for v in args: self.push(v)
        self.mn(0x4a, cls, len(args))

    def jump_fwd(self, opc):
        self.op(opc); j = len(self.b); self.b += s24(0); return j

    def land(self, j): self.b[j:j + 3] = s24(len(self.b) - (j + 3))


E, ROOT, TF, HOLDER, T4, T1 = 1, 2, 3, 4, 5, 6


def script_init(abc):
    c = Code(abc)
    c.op(0xd0, 0x30)                                  # getlocal0; pushscope
    c.op(0x65); c.b += u30(0)                         # getscopeobject 0
    chain = ['Object', 'EventDispatcher', 'DisplayObject', 'InteractiveObject',
             'DisplayObjectContainer', 'Sprite']
    for n in chain:
        c.getlex(n); c.op(0x30)
    c.getlex('Sprite')
    c.op(0x58); c.b += u30(0)                         # newclass 0
    for _ in chain:
        c.op(0x1d)                                    # popscope
    c.op(0x68); c.b += u30(abc.qname('', 'Test'))     # initproperty Test
    c.op(0x47)
    return bytes(c.b)


def cinit(abc):
    c = Code(abc); c.op(0xd0, 0x30, 0x47); return bytes(c.b)


def iinit(abc):
    c = Code(abc)
    c.op(0xd0, 0x30)
    c.op(0xd0, 0x49, 0x00)                            # constructsuper 0
    c.op(0xd0); c.push('addedToStage')
    c.op(0x40); c.b += u30(3)                         # newfunction 3
    c.callv('addEventListener', 2)
    c.op(0xd0); c.getp('stage')
    j = c.jump_fwd(0x12)                              # iffalse
    c.op(0xd0); c.new('Event', ['addedToStage']); c.callv('dispatchEvent', 1)
    c.land(j)
    c.op(0x47)
    return bytes(c.b)


def handler(abc):
    c = Code(abc)
    c.getlex('g_done')
    j = c.jump_fwd(0x12)                              # iffalse go
    c.op(0x47)
    c.land(j)
    c.mn(0x5e, 'g_done'); c.push(True); c.setp('g_done')   # findproperty; setproperty
    c.get(E); c.getp('currentTarget'); c.set(ROOT)

    def row(parent, y, always):
        c.new('TextField', []); c.set(TF)
        c.get(TF); c.push(True); c.setp('embedFonts')
        c.get(TF); c.new('TextFormat', ['TestFont', 20]); c.setp('defaultTextFormat')
        c.get(TF); c.push(0); c.setp('x')
        c.get(TF); c.push(y); c.setp('y')
        c.get(TF); c.push(120); c.setp('width')
        c.get(TF); c.push(28); c.setp('height')
        c.get(TF); c.push('ababa'); c.setp('text')
        c.get(TF); c.push(always); c.setp('alwaysShowSelection')
        c.get(parent); c.get(TF); c.callv('addChild', 1)
        c.get(TF); c.push(1); c.push(4); c.callv('setSelection', 2)

    def tint(local, ct):
        c.get(local); c.getp('transform'); c.new('ColorTransform', ct); c.setp('colorTransform')

    row(ROOT, 0, True)
    row(ROOT, 30, True); c.get(TF); c.set(T1); tint(TF, [0, 0, 0, 1, 255, 0, 0, 0])
    row(ROOT, 60, True); tint(TF, [1, 1, 1, 1, 0, 0, 255, 0])
    c.new('Sprite', []); c.set(HOLDER)
    c.get(ROOT); c.get(HOLDER); c.callv('addChild', 1)
    tint(HOLDER, [0, 0, 0, 1, 255, 0, 255, 0])
    row(HOLDER, 90, True)
    row(ROOT, 120, False); c.get(TF); c.set(T4); tint(TF, [0, 0, 0, 1, 0, 200, 0, 0])
    c.get(ROOT); c.getp('stage'); c.get(T4); c.setp('focus')

    c.mn(0x5d, 'trace'); c.push('focus=')
    c.get(ROOT); c.getp('stage'); c.getp('focus'); c.get(T4); c.op(0xab); c.op(0xa0)
    c.callv('trace', 1)
    c.mn(0x5d, 'trace'); c.push('sel=')
    c.get(T1); c.getp('selectionBeginIndex'); c.op(0xa0); c.push(','); c.op(0xa0)
    c.get(T1); c.getp('selectionEndIndex'); c.op(0xa0)
    c.callv('trace', 1)
    c.op(0x47)
    return bytes(c.b)


def build_abc():
    abc = Abc()
    # method 0 script init, 1 cinit, 2 iinit, 3 handler(e)
    gens = [script_init, cinit, iinit, handler]
    for g in gens: g(abc)                             # intern
    codes = [g(abc) for g in gens]
    q_test = abc.qname('', 'Test'); q_sprite = abc.qname('flash.display', 'Sprite')
    q_done = abc.qname('', 'g_done')
    for kind, *rest in abc.names[1:]:
        abc.string(rest[-1])
    for n in NS: abc.string(n)
    out = bytearray(struct.pack('<HH', 16, 46))
    out += u30(len(abc.ints))
    for v in abc.ints[1:]: out += u30(v & 0xFFFFFFFF)
    out += u30(0) + u30(0)                            # uints, doubles
    out += u30(len(abc.strings))
    for s in abc.strings[1:]:
        b = s.encode('utf-8'); out += u30(len(b)) + b
    out += u30(len(NS) + 1)
    for n in NS: out += bytes([0x16]) + u30(abc.string(n))
    out += u30(2) + u30(len(NS)) + b''.join(u30(i + 1) for i in range(len(NS)))
    out += u30(len(abc.names))
    for kind, *rest in abc.names[1:]:
        if kind == 'm':
            out += bytes([0x09]) + u30(abc.string(rest[0])) + u30(1)
        else:
            out += bytes([0x07]) + u30(rest[0] + 1) + u30(abc.string(rest[1]))
    # methods
    out += u30(4)
    for pc in (0, 0, 0, 1):
        out += u30(pc) + u30(0) + b''.join(u30(0) for _ in range(pc)) + u30(0) + bytes([0])
    out += u30(0)                                     # metadata
    out += u30(1)                                     # classes
    out += u30(q_test) + u30(q_sprite) + bytes([0x01]) + u30(0) + u30(2) + u30(0)
    out += u30(1) + u30(0)                            # class_info: cinit 1, 0 traits
    out += u30(1) + u30(0)                            # 1 script, init method 0
    out += u30(2)
    out += u30(q_test) + bytes([0x04]) + u30(1) + u30(0)        # Class trait, slot 1, class 0
    out += u30(q_done) + bytes([0x00]) + u30(2) + u30(0) + u30(0)  # Slot g_done
    # bodies: (method, max_stack, locals, init_scope, max_scope)
    shape = [(0, 3, 1, 0, 8), (1, 1, 1, 7, 8), (2, 4, 1, 8, 9), (3, 10, 7, 9, 10)]
    out += u30(len(shape))
    for (m, ms, nl, isd, msd), code in zip(shape, codes):
        out += u30(m) + u30(ms) + u30(nl) + u30(isd) + u30(msd) + u30(len(code)) + code
        out += u30(0) + u30(0)
    return bytes(out)


def tag(code, payload):
    if len(payload) >= 63:
        return struct.pack('<HI', (code << 6) | 63, len(payload)) + payload
    return struct.pack('<H', (code << 6) | len(payload)) + payload


def font_tags():
    src = os.path.join(HERE, '..', '..', '..', '..', '..', 'ruffle-tests', 'tests', 'swfs',
                       'regression', 'avm2_bitmapdata_draw_textfield', 'test.swf')
    if not os.path.exists(src):
        src = os.environ['DRAW_TEXTFIELD_SWF']
    d = open(src, 'rb').read()
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
    rect = bytes([0x68, 0x00, 0x12, 0xC0, 0x00, 0x05, 0xDC, 0x00])   # 0..2400, 0..3000 twips (120x150)
    body = rect + struct.pack('<HH', 30 << 8, 1)
    body += tag(69, struct.pack('<I', 0x08))
    body += tag(9, b'\xff\xff\xff')
    body += font_tags()
    body += tag(82, struct.pack('<I', 1) + b'selcx\x00' + build_abc())
    body += tag(76, struct.pack('<HH', 1, 0) + b'Test\x00')
    body += tag(1, b'')
    body += tag(0, b'')
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body


if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else os.path.join(HERE, 'test.swf')
    open(out, 'wb').write(build_swf())
    print('wrote', out)
