"""regression/avm1_applyfilter_{blur,glow,bevel,convolution}: AVM1
BitmapData.applyFilter per filter kind, graded against FLASH PLAYER 32.

Each SWF (SWF 8, 200x150, white stage) builds a 40x40 transparent source with a
red 20x20 square at (10,10) and a blue 8x8 square at (14,14), applies ONE
filter twice -- into a TRANSPARENT 80x80 target at destPoint (20,20), and into an
OPAQUE white 80x80 target at destPoint (20,20) -- attaches the two targets at
stage (10,10) and (100,10), and traces the return values and 14 getPixel32
probes. Built by s27 w2-applyfilter-cm (fixtures + bridge, cceb5133a); landed by
s27 w2b-avm1-applyfilter-flash with the coordinator's FP32 captures
(session27-fanout-reports/w2-local-oracles/w2-applyfilter-cm/<name>/flash.{txt,png})
as output.txt / output.expected.png. Flash rules they pin (action.c
bitmapDataApplyFilter, avm1_filter_kernels.c):
  - an OPAQUE target refuses Glow / DropShadow / Bevel / GradientGlow /
    GradientBevel with -6 and stays untouched (glow, bevel: `opaque ret -6`,
    every `dop` probe -1);
  - Blur into an OPAQUE target stores the premultiplied word WITH its alpha
    (getPixel32 0x6B640005 vs the transparent twin's 0x6BEE000C, 0 on the
    grown rim) and displays it ignoring that alpha (black rim);
  - Convolution into an opaque target applies normally.
The dropshadow / gradientglow / gradientbevel twins (same generator, KINDS
below) are not landed yet: see the w2b-avm1-applyfilter-flash report.
Regenerate: python3 create_test_swf.py   (writes ../avm1_applyfilter_<kind>/test.swf
for every kind whose directory exists)
"""
import struct, sys, os

def s(x): return b'\x00' + x.encode() + b'\x00'
def i(x): return b'\x07' + struct.pack('<i', x)
def d(x): return b'\x06' + struct.pack('<d', x)[4:] + struct.pack('<d', x)[:4]
TRUE = b'\x05\x01'
NULL = b'\x02'
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
GETVAR=b'\x1c'; SETVAR=b'\x1d'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; CALLM=b'\x52'; POP=b'\x17'
NEWM=b'\x53'; INITARR=b'\x42'; TRACE=b'\x26'
def path(names):
    out = push(s(names[0])) + GETVAR
    for n in names[1:]:
        out += push(i(n) if isinstance(n, int) else s(n)) + GETMEM
    return out
def call(objpath, method, args):
    out = push(*[a for a in reversed(args)]) + push(i(len(args)))
    out += path(objpath) + push(s(method)) + CALLM + POP
    return out
def setp(objpath, prop, valcode):
    return path(objpath) + push(s(prop)) + valcode + SETMEM
def newfilter(cls, args):
    # new flash.filters.<cls>(args...)  -> leaves the object on the stack
    out = push(*[a for a in reversed(args)]) + push(i(len(args)))
    out += push(s('flash')) + GETVAR + push(s('filters')) + GETMEM + push(s(cls)) + NEWM
    return out
def arr(*elem_codes):
    # [e0, e1, ...]: InitArray pops count then elements (first popped = e0)
    out = b''.join(reversed(elem_codes)) + push(i(len(elem_codes))) + INITARR
    return out
def trace(code): return code + TRACE
def rect(p, x, y, w, h, color):
    o = call(p, 'beginFill', [i(color), i(100)])
    o += call(p, 'moveTo', [i(x), i(y)])
    for (px, py) in [(x+w, y), (x+w, y+h), (x, y+h), (x, y)]: o += call(p, 'lineTo', [i(px), i(py)])
    o += call(p, 'endFill', [])
    return o

class Bits:
    def __init__(s): s.b = ''
    def u(s, v, n): s.b += format(v & ((1 << n) - 1), '0%db' % n) if n else ''
    def sb(s, v, n): s.u(v, n)
    def bytes(s):
        b = s.b + '0' * ((8 - len(s.b) % 8) % 8)
        return bytes(int(b[k:k+8], 2) for k in range(0, len(b), 8))
def nbits(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n-1)) <= v < (1 << (n-1))): n += 1
    return n
def rectrec(x0, x1, y0, y1):
    b = Bits(); n = nbits(x0, x1, y0, y1); b.u(n, 5)
    for v in (x0, x1, y0, y1): b.sb(v, n)
    return b.bytes()
def matrix(tx, ty):
    b = Bits(); b.u(0, 1); b.u(0, 1); n = nbits(tx, ty); b.u(n, 5); b.sb(tx, n); b.sb(ty, n)
    return b.bytes()
def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
def shape(cid, w, h, rgb):
    W, H = w * 20, h * 20
    body = struct.pack('<H', cid) + rectrec(0, W, 0, H)
    body += b'\x01\x00' + bytes(rgb) + b'\x00'      # 1 solid fill, 0 lines
    b = Bits(); b.u(1, 4); b.u(0, 4)                # NumFillBits=1, NumLineBits=0
    # style change: moveTo(0,0), fill0 = 1
    b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1, 1); b.u(1, 1)
    n = nbits(0, 0); b.u(n, 5); b.sb(0, n); b.sb(0, n); b.u(1, 1)
    for dx, dy in [(W, 0), (0, H), (-W, 0), (0, -H)]:
        n = max(nbits(dx, dy), 2); b.u(1, 1); b.u(1, 1); b.u(n - 2, 4)
        if dx == 0: b.u(0, 1); b.u(1, 1); b.sb(dy, n)
        else: b.u(0, 1); b.u(0, 1); b.sb(dx, n)
    b.u(0, 6)
    return tag(2, body + b.bytes())
def place(depth, cid, tx, ty, name):
    body = bytes([0x20 | 0x04 | 0x02]) + struct.pack('<HH', depth, cid) + matrix(tx * 20, ty * 20) + s(name)[1:]
    return tag(26, body)
def sprite(sid, inner_cid):
    inner = tag(26, bytes([0x02 | 0x04]) + struct.pack('<HH', 1, inner_cid) + matrix(0, 0)) + tag(1, b'') + tag(0, b'')
    return tag(39, struct.pack('<HH', sid, 1) + inner)

def new(pkg, cls, args):
    # each arg: a push ITEM (from s/i/d/...) or full action CODE (tuple ('code', bytes))
    out = b''.join(a[1] if isinstance(a, tuple) else push(a) for a in reversed(args)) + push(i(len(args)))
    out += push(s('flash')) + GETVAR + push(s(pkg)) + GETMEM + push(s(cls)) + NEWM
    return out
def newglobal(cls, args):
    return push(*[a for a in reversed(args)]) + push(i(len(args)), s(cls)) + b'\x40'  # NewObject
def callv(objpath, method, args):   # call, keep result on stack
    return push(*[a for a in reversed(args)]) + push(i(len(args))) + path(objpath) + push(s(method)) + CALLM

ADD2=b'\x47'; LESS2=b'\x48'; BITAND=b'\x60'; BITRSHIFT=b'\x64'; NOT=b'\x12'
def tracecat(label, code): return trace(push(s(label)) + code + ADD2)
def alpha_of(code):  # (px >> 24) & 255
    return code + push(i(24)) + BITRSHIFT + push(i(255)) + BITAND
def bmd(name, w, h, transparent, color):
    return push(s(name)) + new('display', 'BitmapData', [i(w), i(h), TRUE if transparent else b'\x05\x00', d(float(color))]) + SETVAR
def fillrect(bname, x, y, w, h, color):
    return (push(d(float(color))) + new('geom', 'Rectangle', [i(x), i(y), i(w), i(h)]) + push(i(2))
            + path([bname]) + push(s('fillRect')) + CALLM + POP)
def apply(label, dname, sname, filtcode, dx=0, dy=0):
    o = filtcode
    o += new('geom', 'Point', [i(dx), i(dy)])
    o += path([sname, 'rectangle'])
    o += path([sname])
    o += push(i(4)) + path([dname]) + push(s('applyFilter')) + CALLM
    return push(s('r')) + o + SETVAR + tracecat(label + ' ret ', push(s('r')) + GETVAR)
def px(label, bname, x, y):
    return tracecat(label + ' ', callv([bname], 'getPixel32', [i(x), i(y)]))
def alpha_lt(label, bname, x, y, lim):   # trace(label + (alpha < lim))
    return tracecat(label + ' ', alpha_of(callv([bname], 'getPixel32', [i(x), i(y)])) + push(i(lim)) + LESS2)
def alpha_gt0(label, bname, x, y):       # trace(label + (0 < alpha))
    return tracecat(label + ' ', push(i(0)) + alpha_of(callv([bname], 'getPixel32', [i(x), i(y)])) + LESS2)
FALSE = b'\x05\x00'
def red_square(name):
    return bmd(name, 20, 20, True, 0) + fillrect(name, 5, 5, 10, 10, 0xFFFF0000)


import pathlib
def attach(bname, clip, depth, x, y):
    o = push(i(depth), s(clip), i(2)) + path(['_root']) + push(s('createEmptyMovieClip')) + CALLM + POP
    o += setp([clip], '_x', push(i(x))) + setp([clip], '_y', push(i(y)))
    o += push(i(1)) + push(s(bname)) + GETVAR + push(i(2)) + path([clip]) + push(s('attachBitmap')) + CALLM + POP
    return o
def gradarr(vals, conv=d):
    return ('code', arr(*[push(conv(float(v))) for v in vals]))
KINDS = {
  'blur':   new('filters', 'BlurFilter', [d(6.0), d(6.0), i(2)]),
  'glow':   new('filters', 'GlowFilter', [i(0x00FF00), d(1.0), d(8.0), d(8.0), d(2.0), i(2), FALSE, FALSE]),
  'dropshadow': new('filters', 'DropShadowFilter', [d(5.0), d(45.0), i(0), d(0.8), d(6.0), d(6.0), d(1.0), i(2), FALSE, FALSE, FALSE]),
  'bevel':  new('filters', 'BevelFilter', [d(4.0), d(45.0), i(0xFFFFFF), d(1.0), i(0), d(1.0), d(6.0), d(6.0), d(1.0), i(2), s('inner'), FALSE]),
  'convolution': new('filters', 'ConvolutionFilter', [i(3), i(3), gradarr([0,-1,0, -1,5,-1, 0,-1,0]), d(1.0), d(0.0), TRUE, FALSE, i(0x00FF00), d(1.0)]),
  'gradientglow': new('filters', 'GradientGlowFilter', [d(4.0), d(45.0), gradarr([0xFFFFFF, 0xFF0000, 0xFFFF00]), gradarr([0, 1, 1]), gradarr([0, 128, 255]), d(8.0), d(8.0), d(1.0), i(2), s('outer'), FALSE]),
  'gradientbevel': new('filters', 'GradientBevelFilter', [d(4.0), d(45.0), gradarr([0xFFFFFF, 0xFF0000, 0x0000FF]), gradarr([1, 0, 1]), gradarr([0, 128, 255]), d(6.0), d(6.0), d(1.0), i(2), s('inner'), FALSE]),
}
here = pathlib.Path(__file__).resolve().parent.parent
for kind, fcode in KINDS.items():
    a = trace(push(s('start ' + kind)))
    a += bmd('src', 40, 40, True, 0) + fillrect('src', 10, 10, 20, 20, 0xFFFF0000) + fillrect('src', 14, 14, 8, 8, 0xFF0000FF)
    a += bmd('dt', 80, 80, True, 0) + bmd('dop', 80, 80, False, 0xFFFFFFFF)
    a += apply('transparent', 'dt', 'src', fcode, 20, 20)
    a += apply('opaque', 'dop', 'src', fcode, 20, 20)
    for (x, y) in [(20, 20), (29, 40), (35, 35), (40, 40), (50, 50), (52, 40), (60, 60)]:
        a += px('dt %d,%d' % (x, y), 'dt', x, y) + px('dop %d,%d' % (x, y), 'dop', x, y)
    a += attach('dt', 't', 1, 10, 10) + attach('dop', 'o', 2, 100, 10)
    a += trace(push(s('done')))
    doaction = tag(12, a + b'\x00')
    swf = rectrec(0, 200*20, 0, 150*20) + struct.pack('<HH', 30 << 8, 1)
    swf += tag(9, b'\xff\xff\xff') + doaction + tag(1, b'') + tag(0, b'')
    out = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(swf)) + swf
    dd = here / ('avm1_applyfilter_' + kind)
    if not dd.is_dir(): continue
    (dd / 'test.swf').write_bytes(out)
