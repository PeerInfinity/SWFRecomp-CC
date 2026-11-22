# s25 w1-avm1-filters-complete dynamic/CM probe. Helpers copied from s23 avm1-runtime-filters-probe/mkprobe.py.
# Usage: python3 mkdyn.py out.swf
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

# Case selection: CASES env (default ABCDEG; F = GradientGlow is opt-in, see below).
#   Fixture cut matching the s25 prototype:   CASES=ABD
#   Fixture cut needing the dynamic-cxform channel (item 5): CASES=CEG
a = b''
# H: nested — parent hh (dynamic) setTransform {ra:0, rb:0, ga:0, gb:0, ba:0, bb:255} (blue), child hc draws red -> blue
a += call(['_root'], 'createEmptyMovieClip', [s('hh'), i(20)])
a += setp(['hh'], '_x', push(i(40))); a += setp(['hh'], '_y', push(i(40)))
a += call(['hh'], 'createEmptyMovieClip', [s('hc'), i(1)])
a += rect(['hh', 'hc'], 0, 0, 80, 60, 0xFF0000)
a += push(s('ct')) + newglobal('Object', []) + SETVAR
for k, v in [('ra', 0), ('ga', 0), ('ba', 0), ('rb', 0), ('gb', 0), ('bb', 255)]:
    a += setp(['ct'], k, push(i(v)))
a += push(s('colh')) + newglobal('Color', [s('hh')]) + SETVAR
a += push(s('ct')) + GETVAR + push(i(1)) + path(['colh']) + push(s('setTransform')) + CALLM + POP
# I: transform.colorTransform = new ColorTransform(0,0,0,1, 0,255,255,0) -> cyan
a += call(['_root'], 'createEmptyMovieClip', [s('ii'), i(21)])
a += setp(['ii'], '_x', push(i(200))); a += setp(['ii'], '_y', push(i(40)))
a += rect(['ii'], 0, 0, 80, 60, 0xFF0000)
a += path(['ii', 'transform']) + push(s('colorTransform')) + new('geom', 'ColorTransform', [i(0), i(0), i(0), i(1), i(0), i(255), i(255), i(0)]) + SETMEM
# J: attachBitmap red BitmapData + setRGB(0x00FF00) -> green
a += call(['_root'], 'createEmptyMovieClip', [s('jj'), i(22)])
a += setp(['jj'], '_x', push(i(360))); a += setp(['jj'], '_y', push(i(40)))
a += push(s('bmd')) + new('display', 'BitmapData', [i(80), i(60), b'\x05\x00', i(0xFF0000)]) + SETVAR
a += push(i(1)) + push(s('bmd')) + GETVAR + push(i(2)) + path(['jj']) + push(s('attachBitmap')) + CALLM + POP
a += push(s('colj')) + newglobal('Color', [s('jj')]) + SETVAR
a += call(['colj'], 'setRGB', [i(0x00FF00)])
# K: _alpha 50 + setRGB(0x0000FF) on drawing -> (127,127,255) on white
a += call(['_root'], 'createEmptyMovieClip', [s('kk'), i(23)])
a += setp(['kk'], '_x', push(i(40))); a += setp(['kk'], '_y', push(i(200)))
a += rect(['kk'], 0, 0, 80, 60, 0xFF0000)
a += setp(['kk'], '_alpha', push(i(50)))
a += push(s('colk')) + newglobal('Color', [s('kk')]) + SETVAR
a += call(['colk'], 'setRGB', [i(0x0000FF)])
# L: J with _xscale (xform slot path) + _alpha 50 -> green at half alpha (127,255,127)
a += call(['_root'], 'createEmptyMovieClip', [s('ll'), i(24)])
a += setp(['ll'], '_x', push(i(200))); a += setp(['ll'], '_y', push(i(200)))
a += push(i(1)) + push(s('bmd')) + GETVAR + push(i(2)) + path(['ll']) + push(s('attachBitmap')) + CALLM + POP
a += setp(['ll'], '_alpha', push(i(50)))
a += push(s('coll')) + newglobal('Color', [s('ll')]) + SETVAR
a += call(['coll'], 'setRGB', [i(0x00FF00)])
a += trace(push(s('done')))
a += b'\x00'
body = rectrec(0, 550 * 20, 0, 400 * 20) + struct.pack('<HH', 30 << 8, 1)
body += tag(9, b'\xff\xff\xff')
body += tag(12, a) + tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1], 'wb').write(swf)
