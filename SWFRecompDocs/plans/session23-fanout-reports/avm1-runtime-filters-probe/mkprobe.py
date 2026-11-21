# Hand AVM1 assembler for the avm1-runtime-filters probe (MTASC is not in the
# cloud). Usage: python3 mkprobe.py out.swf
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

a = b''
# A: placed sprite + runtime GlowFilter (blue, blur 10, strength 3, quality 1)
a += setp(['p'], 'filters', arr(newfilter('GlowFilter', [i(0x0000FF), i(1), i(10), i(10), i(3), i(1)])))
a += trace(push(s('A ')) + path(['p', 'filters']) + push(s('length')) + GETMEM + b'\x21')  # StringAdd
# B: value semantics: assign, then mutate the array's filter -> render keeps blur 2
a += push(s('arr')) + arr(newfilter('BlurFilter', [i(2), i(2), i(1)])) + SETVAR
a += setp(['q'], 'filters', push(s('arr')) + GETVAR)
a += path(['arr', 0]) + push(s('blurX'), i(40)) + SETMEM
a += path(['arr', 0]) + push(s('blurY'), i(40)) + SETMEM
a += trace(push(s('B ')) + path(['q', 'filters', 0]) + push(s('blurX')) + GETMEM + b'\x21')
# C: assign then clear with null -> no shadow, getter answers []
a += setp(['r'], 'filters', arr(newfilter('DropShadowFilter', [i(8), i(45), i(0), i(1), i(4), i(4), i(1), i(1)])))
a += setp(['r'], 'filters', push(NULL))
a += trace(push(s('C ')) + path(['r', 'filters']) + push(s('length')) + GETMEM + b'\x21')
# D: dynamic clip, two overlapping parts, _alpha 50, DropShadow -> group alpha
a += call(['_root'], 'createEmptyMovieClip', [s('dd'), i(10)])
a += setp(['dd'], '_x', push(i(40))); a += setp(['dd'], '_y', push(i(170)))
a += call(['dd'], 'createEmptyMovieClip', [s('p1'), i(1)])
a += rect(['dd', 'p1'], 0, 0, 80, 50, 0x00AA00)
a += call(['dd'], 'createEmptyMovieClip', [s('p2'), i(2)])
a += rect(['dd', 'p2'], 40, 25, 80, 50, 0x00AA00)
a += setp(['dd'], '_alpha', push(i(50)))
a += setp(['dd'], DYN_PROP, arr(newfilter('DropShadowFilter', [i(8), i(45), i(0), i(1), i(4), i(4), i(1), i(1)])))
# E: dynamic clip, BevelFilter (defaults), no alpha
a += call(['_root'], 'createEmptyMovieClip', [s('ee'), i(11)])
a += setp(['ee'], '_x', push(i(300))); a += setp(['ee'], '_y', push(i(170)))
a += rect(['ee'], 0, 0, 100, 80, 0x8888FF)
a += setp(['ee'], DYN_PROP, arr(newfilter('BevelFilter', [i(5), i(45), i(0xFFFFFF), i(1), i(0), i(1), i(6), i(6), i(2), i(1)])))
a += b'\x00'

body = rectrec(0, 550 * 20, 0, 300 * 20) + struct.pack('<HH', 30 << 8, 1)
body += tag(9, b'\xff\xff\xff')
body += shape(1, 80, 60, (255, 0, 0)) + sprite(2, 1)
body += place(1, 2, 40, 40, 'p') + place(2, 2, 200, 40, 'q') + place(3, 2, 360, 40, 'r')
body += tag(12, a) + tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1], 'wb').write(swf)
