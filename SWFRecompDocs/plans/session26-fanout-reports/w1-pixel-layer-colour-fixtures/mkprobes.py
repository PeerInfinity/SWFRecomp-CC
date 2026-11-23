#!/usr/bin/env python3
# s26 w1-pixel-layer-colour probes. Usage: mkprobes.py OUTDIR  (writes OUTDIR/<probe>/{test.swf,test.toml,output.txt})
import struct, sys, os, pathlib

def tag(code, body):
    if len(body) < 63: return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body
class Bits:
    def __init__(s): s.b = ''
    def u(s, v, n): s.b += format(v & ((1 << n) - 1), '0%db' % n) if n else ''
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
    for v in (x0, x1, y0, y1): b.u(v, n)
    return b.bytes()
def matrix(tx, ty, sx=None, sy=None):
    b = Bits()
    if sx is not None:
        b.u(1, 1); A = int(sx * 65536); D = int(sy * 65536); n = nbits(A, D); b.u(n, 5); b.u(A, n); b.u(D, n)
    else: b.u(0, 1)
    b.u(0, 1); n = nbits(tx, ty); b.u(n, 5); b.u(tx, n); b.u(ty, n)
    return b.bytes()
def cxform_alpha(mult=None, add=None):
    # mult/add: 4-tuples (r,g,b,a), mult in 8.8 (256 = 1.0)
    b = Bits(); b.u(1 if add else 0, 1); b.u(1 if mult else 0, 1)
    vals = list(mult or ()) + list(add or ())
    n = max(nbits(*vals), 2) if vals else 1; b.u(n, 4)
    for v in vals: b.u(v, n)
    return b.bytes()
def shape(cid, rects, rgba):
    """DefineShape3 with one solid RGBA fill and one or more rects (px, may be fractional)."""
    T = lambda v: int(round(v * 20))
    xs = [T(r[0]) for r in rects] + [T(r[0] + r[2]) for r in rects]
    ys = [T(r[1]) for r in rects] + [T(r[1] + r[3]) for r in rects]
    body = struct.pack('<H', cid) + rectrec(min(xs), max(xs), min(ys), max(ys))
    body += b'\x01\x00' + bytes(rgba) + b'\x00'
    b = Bits(); b.u(1, 4); b.u(0, 4)
    first = True
    for (x, y, w, h) in rects:
        X, Y, W, H = T(x), T(y), T(w), T(h)
        b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(0, 1); b.u(1 if first else 0, 1); b.u(1, 1)
        n = nbits(X, Y); b.u(n, 5); b.u(X, n); b.u(Y, n)
        if first: b.u(1, 1)
        first = False
        for dx, dy in [(W, 0), (0, H), (-W, 0), (0, -H)]:
            n = max(nbits(dx, dy), 2); b.u(1, 1); b.u(1, 1); b.u(n - 2, 4)
            if dx == 0: b.u(0, 1); b.u(1, 1); b.u(dy, n)
            else: b.u(0, 1); b.u(0, 1); b.u(dx, n)
    b.u(0, 6)
    return tag(32, body + b.bytes())
def blur(bx, by, passes=1):
    return bytes([1]) + struct.pack('<II', int(bx * 65536), int(by * 65536)) + bytes([(passes << 3)])
def colormatrix(m20):
    return bytes([6]) + struct.pack('<20f', *m20)
def place3(depth, cid, tx=0, ty=0, cx=None, filters=None, blend=None, name=None, sx=None, sy=None):
    f1 = 0x02 | 0x04 | (0x08 if cx else 0) | (0x20 if name else 0)
    f2 = (0x01 if filters else 0) | (0x02 if blend else 0)
    body = bytes([f1, f2]) + struct.pack('<HH', depth, cid) + matrix(int(tx * 20), int(ty * 20), sx, sy)
    if cx: body += cx
    if name: body += name.encode() + b'\0'
    if filters: body += bytes([len(filters)]) + b''.join(filters)
    if blend: body += bytes([blend])
    return tag(70, body)
def sprite(sid, tags):
    return tag(39, struct.pack('<HH', sid, 1) + b''.join(tags) + tag(1, b'') + tag(0, b''))
def movie(tags, w=200, h=150, bg=(255, 255, 255), ver=10):
    t = [tag(69, bytes([0, 0, 0, 0])), tag(9, bytes(bg))] + tags + [tag(1, b''), tag(0, b'')]
    body = rectrec(0, w * 20, 0, h * 20) + struct.pack('<BBH', 0, 30, 1) + b''.join(t)
    return b'FWS' + bytes([ver]) + struct.pack('<I', 8 + len(body)) + body

# ---------------- AVM1 helpers (from s25 mkdyn2.py) ----------------
def s(x): return b'\x00' + x.encode() + b'\x00'
def i(x): return b'\x07' + struct.pack('<i', x)
def d(x): return b'\x06' + struct.pack('<d', x)[4:] + struct.pack('<d', x)[:4]
def push(*items):
    body = b''.join(items); return b'\x96' + struct.pack('<H', len(body)) + body
GETVAR=b'\x1c'; SETVAR=b'\x1d'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; CALLM=b'\x52'; POP=b'\x17'; NEWM=b'\x53'; INITARR=b'\x42'; TRACE=b'\x26'
def path(names):
    out = push(s(names[0])) + GETVAR
    for n in names[1:]: out += push(s(n)) + GETMEM
    return out
def call(objpath, method, args):
    return push(*reversed(args)) + push(i(len(args))) + path(objpath) + push(s(method)) + CALLM + POP
def setp(objpath, prop, valcode): return path(objpath) + push(s(prop)) + valcode + SETMEM
def newglobal(cls, args): return push(*reversed(args)) + push(i(len(args)), s(cls)) + b'\x40'
def drect(p, x, y, w, h, color, alpha=100):
    o = call(p, 'beginFill', [i(color), i(alpha)]) + call(p, 'moveTo', [i(x), i(y)])
    for (px, py) in [(x+w, y), (x+w, y+h), (x, y+h), (x, y)]: o += call(p, 'lineTo', [i(px), i(py)])
    return o + call(p, 'endFill', [])

RED=(255,0,0,255); BLUE=(0,0,255,255); GREEN=(0,255,0,255)
P = {}
# ---- N1: filtered child inside a layered group ----
def n1(blend):
    return movie([shape(1, [(20, 20, 80, 60)], RED), shape(2, [(0, 0, 60, 60)], BLUE), shape(3, [(0, 0, 50, 40)], GREEN),
                  sprite(10, [place3(1, 1), place3(2, 2, 70, 40, filters=[blur(4, 4)]), place3(3, 3, 120, 70)]),
                  place3(1, 10, blend=blend)])
P['n1_layer_blur'] = n1(2)
P['n1_multiply_blur'] = n1(3)
P['n1_control_blur'] = n1(None)      # same content, normal blend (reference)
# ---- N3: group alpha on a LAYER with overlapping opaque children ----
def n3(blend):
    return movie([shape(1, [(20, 20, 80, 60)], RED), shape(2, [(60, 40, 80, 70)], BLUE),
                  sprite(10, [place3(1, 1), place3(2, 2)]),
                  place3(1, 10, cx=cxform_alpha(mult=(256, 256, 256, 128)), blend=blend)])
P['n3_layer_alpha'] = n3(2)
P['n3_normal_alpha'] = n3(None)      # reference: no layer => per-child alpha (overlap shows red)
# ---- ColorMatrix (timeline PlaceObject3) ----
SWAP_RB = [0,0,1,0,0, 0,1,0,0,0, 1,0,0,0,0, 0,0,0,1,0]
ABIAS   = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,255, 0,0,0,1,128]
TWICE   = [2,0,0,0,0, 0,2,0,0,0, 0,0,2,0,0, 0,0,0,1,0]
HALF    = [.5,0,0,0,0, 0,.5,0,0,0, 0,0,.5,0,0, 0,0,0,1,0]
AFROMR  = [1,0,0,0,0, 0,1,0,0,0, 0,0,1,0,0, .5,0,0,0,0]
GREY=(200,200,200,255)
P['cm_offdiag'] = movie([
    shape(1, [(0, 0, 60, 40)], RED),
    shape(2, [(0, 0, 20, 40), (40, 0, 20, 40)], RED),        # two bars with a gap: bounds include the gap
    shape(3, [(0, 0, 60, 40)], GREY),
    shape(4, [(0.5, 0.5, 59, 39)], RED),                      # AA edges
    place3(1, 1, 10, 10, filters=[colormatrix(SWAP_RB)]),
    place3(2, 2, 110, 10, filters=[colormatrix(ABIAS)]),
    place3(3, 3, 10, 80, filters=[colormatrix(TWICE), colormatrix(HALF)]),
    place3(4, 4, 110, 80, filters=[colormatrix(AFROMR)]),
])
# ---- colour on Drawing-API content of placed clips (AVM1) ----
def placed_drawing():
    tags = [sprite(10, []),     # empty sprite: script draws into it
            shape(1, [(0, 0, 10, 10)], GREEN)]
    BLUEX = cxform_alpha(mult=(0, 0, 0, 256), add=(0, 0, 255, 0))
    tags += [place3(1, 10, 10, 10, cx=BLUEX, name='pa'),           # A: placed with blue-tint cxform, draws red
             place3(2, 10, 110, 10, name='pb'),                    # B: placed plain, Color.setRGB(green), draws red
             place3(3, 10, 210, 10, name='pc'),                    # C: placed, _alpha 50, draws red (control: fold)
             place3(4, 10, 310, 10, cx=BLUEX, name='pd'),          # D: placed blue tint, dynamic child draws red
             place3(5, 10, 10, 110, name='pe', sx=2, sy=2),        # E: placed at scale 2, dynamic child draws 20x15
             place3(6, 10, 110, 110, cx=cxform_alpha(mult=(256,256,256,128)), name='pf'),  # F: placed alpha .5 cxform, draws red
             ]
    a = b''
    a += drect(['pa'], 0, 0, 80, 60, 0xFF0000)
    a += drect(['pb'], 0, 0, 80, 60, 0xFF0000)
    a += push(s('cb')) + newglobal('Color', [s('pb')]) + SETVAR + call(['cb'], 'setRGB', [i(0x00FF00)])
    a += drect(['pc'], 0, 0, 80, 60, 0xFF0000) + setp(['pc'], '_alpha', push(i(50)))
    a += call(['pd'], 'createEmptyMovieClip', [s('c'), i(1)]) + drect(['pd', 'c'], 0, 0, 80, 60, 0xFF0000)
    a += call(['pe'], 'createEmptyMovieClip', [s('c'), i(1)]) + drect(['pe', 'c'], 0, 0, 20, 15, 0xFF0000)
    a += drect(['pf'], 0, 0, 80, 60, 0xFF0000)
    a += push(s('done')) + TRACE + b'\x00'
    tags.append(tag(12, a))
    return movie(tags, w=400, h=200, ver=8)
P['placed_drawing_color'] = placed_drawing()

if __name__ == '__main__':
    out = pathlib.Path(sys.argv[1])
    for k, v in P.items():
        dd = out / k; dd.mkdir(parents=True, exist_ok=True)
        (dd / 'test.swf').write_bytes(v)
        (dd / 'output.txt').write_text('done\n' if k == 'placed_drawing_color' else '')
        (dd / 'test.toml').write_text('num_ticks = 1\n\n[image_comparisons.output]\ntolerance = 1\n\n[player_options]\nwith_renderer = { optional = false, quality = "high" }\n')
    print('\n'.join(P))
