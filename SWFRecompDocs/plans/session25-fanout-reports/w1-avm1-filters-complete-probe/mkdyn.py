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
CASES = os.environ.get('CASES', 'ABCDEG') + ('F' if os.environ.get('WITH_GRADIENT') else '')
def tr(label, codepath, prop):
    return trace(push(s(label)) + path(codepath) + push(i(prop) if isinstance(prop, int) else s(prop)) + GETMEM + b'\x21')
a = b''
if 'A' in CASES:
    # A (item 4): dynamic clip whose ONLY content is an attachBitmap bitmap + GlowFilter(blue).
    a += call(['_root'], 'createEmptyMovieClip', [s('bb'), i(10)])
    a += setp(['bb'], '_x', push(i(40))); a += setp(['bb'], '_y', push(i(40)))
    a += push(s('bmd')) + new('display', 'BitmapData', [i(60), i(40), b'\x05\x00', i(0xFF0000)]) + SETVAR
    a += push(i(1)) + push(s('bmd')) + GETVAR + push(i(2)) + path(['bb']) + push(s('attachBitmap')) + CALLM + POP
    a += setp(['bb'], 'filters', arr(new('filters', 'GlowFilter', [i(0x0000FF), i(1), i(10), i(10), i(3), i(1)])))
    a += tr('A ', ['bb', 'filters'], 'length')
if 'B' in CASES:
    # B (item 3, placed): timeline sprite p + runtime ColorMatrixFilter halving RGB -> (127/128,0,0)
    a += setp(['p'], 'filters', arr(new('filters', 'ColorMatrixFilter', [CM_HALF])))
    a += tr('B ', ['p', 'filters', 0, 'matrix'], 'length')
if 'C' in CASES:
    # C (item 3, dynamic): Drawing-API clip, red rect, ColorMatrix swapping R and B -> blue
    a += call(['_root'], 'createEmptyMovieClip', [s('cc'), i(11)])
    a += setp(['cc'], '_x', push(i(360))); a += setp(['cc'], '_y', push(i(40)))
    a += rect(['cc'], 0, 0, 80, 60, 0xFF0000)
    a += setp(['cc'], 'filters', arr(new('filters', 'ColorMatrixFilter', [CM_SWAP])))
    a += tr('C ', ['cc', 'filters', 0, 'matrix'], 0)
if 'D' in CASES:
    # D (item 3, chain order): placed sprite q, [Glow(blue), CM_SWAP] -> Flash: box blue, halo RED
    a += setp(['q'], 'filters', arr(new('filters', 'GlowFilter', [i(0x0000FF), i(1), i(10), i(10), i(3), i(1)]),
                                   new('filters', 'ColorMatrixFilter', [CM_SWAP])))
    a += tr('D.n ', ['q', 'filters'], 'length')
    a += tr('D.0.blurX ', ['q', 'filters', 0], 'blurX')
    a += tr('D.1.matrix.n ', ['q', 'filters', 1, 'matrix'], 'length')
if 'E' in CASES:
    # E (item 5): dynamic Drawing-API clip, black Glow, then Color.setRGB(0x00FF00):
    #   the colour transform applies to the FILTER OUTPUT -> green box AND green halo.
    a += call(['_root'], 'createEmptyMovieClip', [s('ee'), i(12)])
    a += setp(['ee'], '_x', push(i(40))); a += setp(['ee'], '_y', push(i(180)))
    a += rect(['ee'], 0, 0, 80, 60, 0xFF0000)
    a += setp(['ee'], 'filters', arr(new('filters', 'GlowFilter', [i(0x000000), i(1), i(12), i(12), i(4), i(1)])))
    a += push(s('col')) + newglobal('Color', [s('ee')]) + SETVAR
    a += call(['col'], 'setRGB', [i(0x00FF00)])
    a += tr('E ', ['ee', 'filters'], 'length')
if 'G' in CASES:
    # G (item 5 control, NO filter): dynamic Drawing-API clip + Color.setRGB(0x00FF00) -> solid green.
    a += call(['_root'], 'createEmptyMovieClip', [s('gg'), i(13)])
    a += setp(['gg'], '_x', push(i(200))); a += setp(['gg'], '_y', push(i(300)))
    a += rect(['gg'], 0, 0, 80, 60, 0xFF0000)
    a += push(s('col2')) + newglobal('Color', [s('gg')]) + SETVAR
    a += call(['col2'], 'setRGB', [i(0x00FF00)])
if 'F' in CASES:
    # F (item 6): placed sprite r, GradientGlowFilter(0, 45, [white,blue,red], [0,1,1], [0,128,255],
    #   16, 16, 2, 1, "outer"). Ruffle's wgpu renderer does NOT implement GradientGlow (it passes
    #   the source through), so a Ruffle golden of this case is NOT a Flash oracle.
    a += setp(['r'], 'filters', arr(new('filters', 'GradientGlowFilter',
            [i(0), i(45), ('code', arr(push(i(0xFFFFFF)), push(i(0x0000FF)), push(i(0xFF0000)))),
             ('code', arr(push(i(0)), push(i(1)), push(i(1)))), ('code', arr(push(i(0)), push(i(128)), push(i(255)))),
             i(16), i(16), i(2), i(1), s('outer'), b'\x05\x00'])))
    a += tr('F.n ', ['r', 'filters'], 'length')
    a += tr('F.0.colors.n ', ['r', 'filters', 0, 'colors'], 'length')
    a += tr('F.0.type ', ['r', 'filters', 0], 'type')
a += b'\x00'

body = rectrec(0, 550 * 20, 0, 400 * 20) + struct.pack('<HH', 30 << 8, 1)
body += tag(9, b'\xff\xff\xff')
body += shape(1, 80, 60, (255, 0, 0)) + sprite(2, 1)
body += place(1, 2, 200, 40, 'p') + place(2, 2, 200, 180, 'q') + place(3, 2, 360, 180, 'r')
body += tag(12, a) + tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
open(sys.argv[1], 'wb').write(swf)
