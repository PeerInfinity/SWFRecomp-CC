"""avm1_applyfilter_convolution_not_cm (s27 w1-applyfilter-tail item 4).

AVM1 BitmapData.applyFilter used to treat ANY filter object with a `matrix`
array of >= 20 entries as a ColorMatrixFilter, so a 5x4 / 5x5 ConvolutionFilter
ran through the CM arm (a unit tap at index 12 = "B' = B, A' = 0" -> pixel 0).
Uniform 4x4 bitmaps make the expected convolution result independent of the
kernel centre convention: a single unit tap with clamp=true returns the source.
Regenerate byte-identically: python3 create_test_swf.py
"""
import struct, sys, os
DYN_PROP = 'filterz' if os.environ.get('NOFILT') else 'filters'

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
CM_HALF = ('code', arr(*[push(d(v)) for v in [0.5,0,0,0,0, 0,0.5,0,0,0, 0,0,0.5,0,0, 0,0,0,1,0]]))
CM_SWAP = ('code', arr(*[push(d(v)) for v in [0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0]]))


ADD2=b'\x47'; INITOBJ=b'\x43'
def tracecat(label, code): return trace(push(s(label)) + code + ADD2)
def uniform_bmd(name):
    return push(s(name)) + new('display', 'BitmapData', [i(4), i(4), TRUE, d(float(0xFF336699))]) + SETVAR
def apply_and_trace(label, bname, filtcode):
    # r = b.applyFilter(b, b.rectangle, new flash.geom.Point(0,0), F); trace(label+r); trace(label+b.getPixel32(1,1))
    o = push(s('f')) + filtcode + SETVAR
    o += push(s('f')) + GETVAR
    o += new('geom', 'Point', [i(0), i(0)])
    o += path([bname, 'rectangle'])
    o += path([bname])
    o += push(i(4)) + path([bname]) + push(s('applyFilter')) + CALLM
    o = o  # result on stack
    o2 = push(s('r')) + o + SETVAR
    o2 += tracecat(label + ' ret ', push(s('r')) + GETVAR)
    o2 += tracecat(label + ' px ', callv([bname], 'getPixel32', [i(1), i(1)]))
    return o2
def ident(n, center):
    return ('code', arr(*[push(d(1.0 if k == center else 0.0)) for k in range(n)]))
CM_SWAP_ARR = arr(*[push(d(v)) for v in [0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0]])
a = b''
a += trace(push(s('start')))
# 1: ConvolutionFilter 5x5 (25 entries), single unit tap, divisor 1, clamp: a uniform bitmap is unchanged
a += uniform_bmd('b1')
a += apply_and_trace('conv5x5', 'b1', new('filters', 'ConvolutionFilter', [i(5), i(5), ident(25, 12), d(1.0), d(0.0), TRUE, TRUE]))
# 2: ConvolutionFilter 5x4 (exactly 20 entries) -- the CM-length collision
a += uniform_bmd('b2')
a += apply_and_trace('conv5x4', 'b2', new('filters', 'ConvolutionFilter', [i(5), i(4), ident(20, 12), d(1.0), d(0.0), TRUE, TRUE]))
# 3: control, a real ColorMatrixFilter swapping R and B: 0xFF336699 -> 0xFF996633
a += uniform_bmd('b3')
a += apply_and_trace('cmswap', 'b3', new('filters', 'ColorMatrixFilter', [('code', CM_SWAP_ARR)]))
# 4: a bare object with a 20-entry matrix is not a filter (Ruffle: -1, untouched)
a += uniform_bmd('b4')
a += apply_and_trace('plainobj', 'b4', push(s('matrix')) + CM_SWAP_ARR + push(i(1)) + INITOBJ)
a += trace(push(s('done')))
doaction = tag(12, a + b'\x00')
swf = rectrec(0, 200*20, 0, 150*20) + struct.pack('<HH', 30 << 8, 1)
swf += tag(9, b'\xff\xff\xff') + doaction + tag(1, b'') + tag(0, b'')
out = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(swf)) + swf
open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf'), 'wb').write(out)
