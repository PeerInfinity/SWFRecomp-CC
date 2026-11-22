# Find SWFs whose DefineSprite bodies carry PlaceObject3 filter lists that the
# recompiler's sprite arm truncates (count>1, or a ColorMatrix/Convolution/gradient filter).
import sys, os, zlib, struct
def tags(d, p, end):
    while p < end:
        if p + 2 > end: return
        h = struct.unpack('<H', d[p:p+2])[0]; c = h >> 6; l = h & 63; p += 2
        if l == 63: l = struct.unpack('<I', d[p:p+4])[0]; p += 4
        yield c, p, l; p += l
        if c == 0: return
def skip_matrix(d, p):
    bits = ''.join(format(b, '08b') for b in d[p:p+40]); i = 0
    if bits[i] == '1':
        i += 1; n = int(bits[i:i+5], 2); i += 5 + 2*n
    else: i += 1
    if bits[i] == '1':
        i += 1; n = int(bits[i:i+5], 2); i += 5 + 2*n
    else: i += 1
    n = int(bits[i:i+5], 2); i += 5 + 2*n
    return p + (i + 7)//8
def skip_cxform_alpha(d, p):
    bits = ''.join(format(b, '08b') for b in d[p:p+40]); i = 0
    ha = bits[0] == '1'; hm = bits[1] == '1'; n = int(bits[2:6], 2); i = 6
    if hm: i += 4*n
    if ha: i += 4*n
    return p + (i + 7)//8
FSIZE = {0: 23, 1: 9, 2: 15, 3: 27}
def filters_of(d, p, l):
    end = p + l
    f1 = d[p]; f2 = d[p+1]; p += 2 + 2
    if not (f2 & 1): return None
    if f2 & 0x08 or (f2 & 0x10 and f1 & 0x02):
        while d[p] != 0: p += 1
        p += 1
    if f1 & 0x02: p += 2
    if f1 & 0x04: p = skip_matrix(d, p)
    if f1 & 0x08: p = skip_cxform_alpha(d, p)
    if f1 & 0x10: p += 2
    if f1 & 0x20:
        while d[p] != 0: p += 1
        p += 1
    if f1 & 0x40: p += 2
    n = d[p]; p += 1; out = []
    for _ in range(n):
        fid = d[p]; p += 1; out.append(fid)
        if fid in FSIZE: p += FSIZE[fid]
        elif fid == 6: p += 80
        elif fid == 5:
            mx, my = d[p], d[p+1]; p += 2 + 8 + 4*mx*my + 4 + 1
        elif fid in (4, 7):
            nc = d[p]; p += 1 + nc*5 + 19
        else: return out
    return out
def scan(path):
    d = open(path, 'rb').read()
    if d[:3] == b'CWS': d = d[:8] + zlib.decompress(d[8:])
    elif d[:3] != b'FWS': return []
    nb = d[8] >> 3; p = 8 + (5 + 4*nb + 7)//8 + 4
    hits = []
    for c, tp, tl in tags(d, p, len(d)):
        if c == 39:
            for c2, p2, l2 in tags(d, tp + 4, tp + tl):
                if c2 == 70:
                    try: fl = filters_of(d, p2, l2)
                    except Exception: fl = ['?']
                    if fl and (len(fl) > 1 or fl[0] not in (0, 1, 2, 3)):
                        hits.append(fl)
    return hits
root = sys.argv[1]
for dp, dn, fn in os.walk(root):
    for f in fn:
        if f.endswith('.swf'):
            try: h = scan(os.path.join(dp, f))
            except Exception as e: h = []
            if h: print(os.path.relpath(os.path.join(dp, f), root), h[:6], len(h))
