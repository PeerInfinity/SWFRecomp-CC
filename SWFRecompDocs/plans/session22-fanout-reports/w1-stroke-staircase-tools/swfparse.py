"""Minimal SWF parser: DefineShape1-4 records, DefineSprite, PlaceObject2/3 matrices (frame 1)."""
import zlib, struct, sys

class Bits:
    def __init__(s, data, pos=0):
        s.d = data; s.p = pos * 8
    def align(s):
        s.p = (s.p + 7) & ~7
    @property
    def byte(s):
        s.align(); return s.p // 8
    def ub(s, n):
        v = 0
        for _ in range(n):
            v = (v << 1) | ((s.d[s.p >> 3] >> (7 - (s.p & 7))) & 1); s.p += 1
        return v
    def sb(s, n):
        if n == 0: return 0
        v = s.ub(n)
        if v & (1 << (n - 1)): v -= 1 << n
        return v
    def u8(s):
        s.align(); v = s.d[s.p >> 3]; s.p += 8; return v
    def u16(s):
        s.align(); v = struct.unpack_from('<H', s.d, s.p >> 3)[0]; s.p += 16; return v
    def u32(s):
        s.align(); v = struct.unpack_from('<I', s.d, s.p >> 3)[0]; s.p += 32; return v

def matrix(b):
    b.align()
    a = d = 1.0; bb = c = 0.0
    if b.ub(1):
        n = b.ub(5); a = b.sb(n) / 65536.0; d = b.sb(n) / 65536.0
    if b.ub(1):
        n = b.ub(5); bb = b.sb(n) / 65536.0; c = b.sb(n) / 65536.0
    n = b.ub(5); tx = b.sb(n); ty = b.sb(n)
    return (a, bb, c, d, tx, ty)  # x' = a*x + c*y + tx ; y' = bb*x + d*y + ty

def rgb(b, alpha):
    r, g, bl = b.u8(), b.u8(), b.u8()
    a = b.u8() if alpha else 255
    return (r, g, bl, a)

def skip_gradient(b, ver, focal):
    matrix(b); b.align()
    b.ub(2); b.ub(2); n = b.ub(4)
    for _ in range(n):
        b.u8(); rgb(b, ver >= 3)
    if focal: b.u16()

def fillstyles(b, ver):
    n = b.u8()
    if n == 0xff and ver >= 2: n = b.u16()
    out = []
    for _ in range(n):
        t = b.u8()
        if t == 0: out.append(('solid', rgb(b, ver >= 3)))
        elif t in (0x10, 0x12, 0x13): skip_gradient(b, ver, t == 0x13); out.append(('grad', t))
        elif t in (0x40, 0x41, 0x42, 0x43): b.u16(); matrix(b); out.append(('bmp', t))
        else: raise ValueError('fill type %x' % t)
    return out

def linestyles(b, ver):
    n = b.u8()
    if n == 0xff and ver >= 2: n = b.u16()
    out = []
    for _ in range(n):
        w = b.u16()
        if ver == 4:
            b.align()
            sc = b.ub(2); js = b.ub(2); hasfill = b.ub(1); nohs = b.ub(1); novs = b.ub(1); pix = b.ub(1)
            b.ub(5); nocl = b.ub(1); ec = b.ub(2)
            ml = None
            if js == 2: ml = b.u16() / 256.0
            if hasfill: f = fillstyles_one(b, ver); col = f
            else: col = rgb(b, True)
            out.append(dict(width=w, start_cap=sc, end_cap=ec, join=js, miter=ml, color=col, pixelhinting=pix, noclose=nocl))
        else:
            out.append(dict(width=w, start_cap=0, end_cap=0, join=0, miter=None, color=rgb(b, ver >= 3), pixelhinting=0, noclose=0))
    return out

def fillstyles_one(b, ver):
    t = b.u8()
    if t == 0: return ('solid', rgb(b, True))
    if t in (0x10, 0x12, 0x13): skip_gradient(b, ver, t == 0x13); return ('grad', t)
    b.u16(); matrix(b); return ('bmp', t)

def shape(data, ver):
    """returns dict(bounds, fills, lines, edges=[(x0,y0, kind, ...)] with style ids"""
    b = Bits(data)
    cid = b.u16()
    rect(b)
    if ver == 4:
        rect(b); b.u8()
    fills = fillstyles(b, ver); lines = linestyles(b, ver)
    b.align(); nf = b.ub(4); nl = b.ub(4)
    x = y = 0; f0 = f1 = ln = 0
    paths = []  # each: dict(f0,f1,line,styles(fills,lines),segs=[...]) segments: ('L',x0,y0,x1,y1) or ('Q',x0,y0,cx,cy,x1,y1)
    cur = None
    def newpath():
        nonlocal cur
        cur = dict(f0=f0, f1=f1, line=ln, fills=fills, lines=lines, segs=[])
        paths.append(cur)
    newpath()
    while True:
        if b.ub(1) == 0:
            fl = b.ub(5)
            if fl == 0: break
            if fl & 1:
                n = b.ub(5); x = b.sb(n); y = b.sb(n)
            if fl & 2: f0 = b.ub(nf)
            if fl & 4: f1 = b.ub(nf)
            if fl & 8: ln = b.ub(nl)
            if fl & 16:
                fills = fillstyles(b, ver); lines = linestyles(b, ver); b.align(); nf = b.ub(4); nl = b.ub(4)
            newpath()
        else:
            if b.ub(1):
                n = b.ub(4) + 2
                if b.ub(1): dx = b.sb(n); dy = b.sb(n)
                else:
                    if b.ub(1): dx = 0; dy = b.sb(n)
                    else: dx = b.sb(n); dy = 0
                cur['segs'].append(('L', x, y, x + dx, y + dy)); x += dx; y += dy
            else:
                n = b.ub(4) + 2
                cx = x + b.sb(n); cy = y + b.sb(n); ax = cx + b.sb(n); ay = cy + b.sb(n)
                cur['segs'].append(('Q', x, y, cx, cy, ax, ay)); x, y = ax, ay
    return cid, [p for p in paths if p['segs']]

def rect(b):
    b.align(); n = b.ub(5); return [b.sb(n) for _ in range(4)]

def tags(data, pos, end):
    while pos < end:
        h = struct.unpack_from('<H', data, pos)[0]; pos += 2
        code = h >> 6; ln = h & 0x3f
        if ln == 0x3f: ln = struct.unpack_from('<I', data, pos)[0]; pos += 4
        yield code, data[pos:pos + ln]
        pos += ln

def load(path):
    raw = open(path, 'rb').read()
    if raw[:3] == b'CWS': data = raw[:8] + zlib.decompress(raw[8:])
    elif raw[:3] == b'FWS': data = raw
    else: raise ValueError('unsupported ' + str(raw[:3]))
    b = Bits(data, 8); r = rect(b); p = b.byte
    fr = struct.unpack_from('<H', data, p)[0]; cnt = struct.unpack_from('<H', data, p + 2)[0]
    return data, r, p + 4

SHAPE_TAGS = {2: 1, 22: 2, 32: 3, 83: 4}

def place(code, d):
    b = Bits(d)
    if code == 26 or code == 70:
        f = b.u8(); f2 = b.u8() if code == 70 else 0
        depth = b.u16()
        if code == 70 and (f2 & 8 or (f2 & 16 and f & 2)):
            # class name
            pass
        cid = b.u16() if f & 2 else None
        m = matrix(b) if f & 4 else None
        return dict(depth=depth, cid=cid, m=m, flags=f, flags2=f2)
    if code == 4:
        cid = b.u16(); depth = b.u16(); m = matrix(b)
        return dict(depth=depth, cid=cid, m=m, flags=0, flags2=0)

def parse(path):
    data, r, p = load(path)
    shapes = {}; sprites = {}; root = []
    frame = 0
    for code, d in tags(data, p, len(data)):
        if code in SHAPE_TAGS:
            cid, ps = shape(d, SHAPE_TAGS[code]); shapes[cid] = ps
        elif code == 39:
            sid = struct.unpack_from('<H', d, 0)[0]
            lst = []; fr = 0
            for c2, d2 in tags(d, 4, len(d)):
                if c2 == 1: fr += 1
                if fr == 0 and c2 in (4, 26, 70): lst.append(place(c2, d2))
            sprites[sid] = lst
        elif code == 1: frame += 1
        elif frame == 0 and code in (4, 26, 70): root.append(place(code, d))
    return dict(rect=r, shapes=shapes, sprites=sprites, root=root)

if __name__ == '__main__':
    s = parse(sys.argv[1])
    print('rect', s['rect'])
    for cid, ps in s['shapes'].items():
        lw = set()
        for p in ps:
            if p['line']: lw.add(p['lines'][p['line'] - 1]['width'])
        print('shape', cid, 'paths', len(ps), 'line widths', lw, 'segs', sum(len(p['segs']) for p in ps))
    for sid, l in s['sprites'].items(): print('sprite', sid, l)
    print('root', s['root'])
