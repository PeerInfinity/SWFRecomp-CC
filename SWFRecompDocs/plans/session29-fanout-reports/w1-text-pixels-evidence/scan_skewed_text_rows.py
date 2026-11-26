import os, zlib, struct, sys, glob
def swfbody(p):
    b=open(p,'rb').read()
    if b[:3]==b'CWS': return b[:8]+zlib.decompress(b[8:])
    if b[:3]==b'FWS': return b
    return None
def tags(b, i=None):
    if i is None:
        nb=b[8]>>3; rl=(5+4*nb+7)//8; i=8+rl+4
    while i+2<=len(b):
        h=struct.unpack('<H',b[i:i+2])[0]; t=h>>6; L=h&63; i+=2
        if L==63: L=struct.unpack('<I',b[i:i+4])[0]; i+=4
        yield t,b[i:i+L]; i+=L
        if t==0: break
def scan(b):
    et=False; rot=False; doabc=False
    def walk(b, start=None):
        nonlocal et,rot,doabc
        for t,d in tags(b, start):
            if t==37: et=True
            if t in (82,72): doabc=True
            if t in (26,70) and len(d)>3:
                fl=d[0]; off=1 if t==26 else 2
                off+=2
                if fl&2: off+=2
                if fl&4 and off<len(d):
                    # matrix: hasScale bit then rotate
                    bits=int.from_bytes(d[off:off+20],'big'); nbit=len(d[off:off+20])*8
                    pos=0
                    def rd(n):
                        nonlocal pos; v=(bits>>(nbit-pos-n))&((1<<n)-1); pos+=n; return v
                    if rd(1): n=rd(5); rd(n); rd(n)
                    if rd(1): rot=True
            if t==39: walk(d, 4)
    walk(b)
    return et, rot or (b'_rotation' in b) or (b'rotation' in b) or (b'matrix' in b.lower()), doabc, (b'createTextField' in b)
out=[]
for toml in glob.glob('**/test.toml',recursive=True):
    s=open(toml).read()
    if 'image_comparisons' not in s: continue
    d=os.path.dirname(toml); swf=os.path.join(d,'test.swf')
    if not os.path.exists(swf): continue
    b=swfbody(swf)
    if not b: continue
    try: et,rot,abc,ctf=scan(b)
    except Exception as e: et=rot=abc=ctf=False
    if (et or ctf) and rot and not abc: out.append(d)
print(len(out)); print('\n'.join(sorted(out)))
