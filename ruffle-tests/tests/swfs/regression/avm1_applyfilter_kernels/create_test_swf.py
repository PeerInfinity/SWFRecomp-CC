"""avm1_applyfilter_kernels (s27 w2-applyfilter-cm).

AVM1 BitmapData.applyFilter ran only ColorMatrixFilter; every other kind
returned 0 and left the target untouched. It now runs the AVM2 CPU kernels
(actionmodern/avm1_filter_kernels.c -> avm2_bitmap.c fb_apply_grown /
bd_apply_convolution), as Ruffle runs one apply_filter for both VMs.

Every probe is ANALYTIC (independent of the kernels' exact blur arithmetic):
  blur   opaque uniform 0xFF336699 source: an interior pixel keeps the colour,
         an edge pixel loses alpha (Flash blurs against transparent outside
         the bitmap).
  glow   outer glow of an opaque red square: the interior stays red, a far
         corner stays empty, the pixel next to the square gets glow alpha.
  shadow DropShadow(distance 4, 45 deg, blur 0): interior red, shadow below
         right of the square, nothing above left.
  conv   1x1 ConvolutionFilter [1], divisor 1, bias 16, preserveAlpha: every
         channel + 16 -> 0xFF4376A9.
  self   b.applyFilter(b, ...) with a blur: the uniform interior is unchanged.
Regenerate byte-identically: python3 create_test_swf.py
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

a = trace(push(s('start')))
# blur
a += bmd('b', 20, 20, False, 0xFF336699) + bmd('d', 20, 20, True, 0)
a += apply('blur', 'd', 'b', new('filters', 'BlurFilter', [d(2.0), d(2.0), i(1)]))
a += px('blur c', 'd', 10, 10) + alpha_lt('blur edge a<255', 'd', 0, 10, 255)
# glow (outer, green)
a += red_square('g') + bmd('gd', 20, 20, True, 0)
a += apply('glow', 'gd', 'g', new('filters', 'GlowFilter', [i(0x00FF00), d(1.0), d(4.0), d(4.0), d(2.0), i(1), FALSE, FALSE]))
a += px('glow c', 'gd', 10, 10) + px('glow far', 'gd', 0, 0) + alpha_gt0('glow halo a>0', 'gd', 4, 10)
# drop shadow, blur 0
a += red_square('h') + bmd('hd', 20, 20, True, 0)
a += apply('shadow', 'hd', 'h', new('filters', 'DropShadowFilter', [d(4.0), d(45.0), i(0), d(1.0), d(0.0), d(0.0), d(1.0), i(1), FALSE, FALSE, FALSE]))
a += px('shadow c', 'hd', 10, 10) + alpha_gt0('shadow br a>0', 'hd', 16, 16) + px('shadow tl', 'hd', 2, 2)
# convolution 1x1 + bias
a += bmd('c', 8, 8, False, 0xFF336699) + bmd('cd', 8, 8, True, 0)
a += apply('conv', 'cd', 'c', new('filters', 'ConvolutionFilter', [i(1), i(1), ('code', arr(push(d(1.0)))), d(1.0), d(16.0), TRUE, TRUE]))
a += px('conv c', 'cd', 4, 4)
# in place
a += bmd('e', 20, 20, False, 0xFF336699)
a += apply('self', 'e', 'e', new('filters', 'BlurFilter', [d(2.0), d(2.0), i(1)]))
a += px('self c', 'e', 10, 10)
a += trace(push(s('done')))
doaction = tag(12, a + b'\x00')
swf = rectrec(0, 200*20, 0, 150*20) + struct.pack('<HH', 30 << 8, 1)
swf += tag(9, b'\xff\xff\xff') + doaction + tag(1, b'') + tag(0, b'')
out = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(swf)) + swf
open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf'), 'wb').write(out)
