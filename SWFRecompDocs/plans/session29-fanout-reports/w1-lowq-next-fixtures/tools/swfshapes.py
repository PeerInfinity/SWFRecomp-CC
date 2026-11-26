"""Minimal SWF dumper: DefineShape1-4 line styles + edges summary, PlaceObject2/3 matrices."""
import sys, zlib, struct
class Bits:
    def __init__(s,b,p=0): s.b=b; s.p=p*8
    def ub(s,n):
        v=0
        for _ in range(n):
            v=(v<<1)|((s.b[s.p>>3]>>(7-(s.p&7)))&1); s.p+=1
        return v
    def sb(s,n):
        v=s.ub(n)
        if n and v&(1<<(n-1)): v-=1<<n
        return v
    def align(s): s.p=(s.p+7)&~7
    def u8(s): s.align(); v=s.b[s.p>>3]; s.p+=8; return v
    def u16(s): s.align(); v=struct.unpack_from('<H',s.b,s.p>>3)[0]; s.p+=16; return v
    def u32(s): s.align(); v=struct.unpack_from('<I',s.b,s.p>>3)[0]; s.p+=32; return v
def rect(bt):
    n=bt.ub(5); r=[bt.sb(n) for _ in range(4)]; bt.align(); return r
def matrix(bt):
    bt.align(); sx=sy=1.0; r0=r1=0.0
    if bt.ub(1): n=bt.ub(5); sx=bt.sb(n)/65536; sy=bt.sb(n)/65536
    if bt.ub(1): n=bt.ub(5); r0=bt.sb(n)/65536; r1=bt.sb(n)/65536
    n=bt.ub(5); tx=bt.sb(n); ty=bt.sb(n); bt.align()
    return (sx,r0,r1,sy,tx/20,ty/20)
def skip_fill(bt,ver):
    t=bt.u8()
    if t==0: bt.p+=8*(4 if ver>=3 else 3)
    elif t in (0x10,0x12,0x13):
        matrix(bt); bt.align(); spread=bt.u8(); n=spread&15
        bt.p+=8*n*(5 if ver>=3 else 4)
        if t==0x13: bt.p+=16
    elif t in (0x40,0x41,0x42,0x43): bt.p+=16; matrix(bt)
    return t
def fillstyles(bt,ver):
    n=bt.u8()
    if n==0xff and ver>=2: n=bt.u16()
    return [skip_fill(bt,ver) for _ in range(n)]
def linestyles(bt,ver):
    n=bt.u8()
    if n==0xff and ver>=2: n=bt.u16()
    out=[]
    for _ in range(n):
        w=bt.u16()
        if ver==4:
            f=bt.u16(); flags=f
            if (f>>8)&0 : pass
            join=(f>>4)&3  # bits: startcap(2) join(2) hasfill nohscale novscale pixelhint | reserved(5) noclose endcap(2)
            b1=f&0xff; b2=f>>8
            startcap=(b1>>6)&3; join=(b1>>4)&3; hasfill=(b1>>3)&1; noh=(b1>>2)&1; nov=(b1>>1)&1; ph=b1&1
            if join==2: bt.u16()
            if hasfill: skip_fill(bt,ver); col=None
            else: col=bt.u32()
            out.append(dict(w=w/20,cap=startcap,join=join,nohs=noh,novs=nov,hint=ph))
        else:
            bt.p+=8*(4 if ver>=3 else 3); out.append(dict(w=w/20))
    return out
def shape(b,ver):
    bt=Bits(b); sid=bt.u16(); r=rect(bt)
    if ver==4: rect(bt); bt.u8()
    fs=fillstyles(bt,ver); ls=linestyles(bt,ver)
    nf=bt.ub(4); nl=bt.ub(4); x=y=0; edges=[]; cur_line=0
    while True:
        if bt.ub(1)==0:
            fl=bt.ub(5)
            if fl==0: break
            if fl&1: n=bt.ub(5); x=bt.sb(n); y=bt.sb(n)
            if fl&2: bt.ub(nf)
            if fl&4: bt.ub(nf)
            if fl&8: cur_line=bt.ub(nl)
            if fl&16:
                fs+=fillstyles(bt,ver); ls+=linestyles(bt,ver); nf=bt.ub(4); nl=bt.ub(4)
        else:
            if bt.ub(1):
                n=bt.ub(4)+2
                if bt.ub(1): dx=bt.sb(n); dy=bt.sb(n)
                elif bt.ub(1): dx=0; dy=bt.sb(n)
                else: dx=bt.sb(n); dy=0
                edges.append(('L',x/20,y/20,(x+dx)/20,(y+dy)/20,cur_line)); x+=dx; y+=dy
            else:
                n=bt.ub(4)+2; cx=x+bt.sb(n); cy=y+bt.sb(n); ax=cx+bt.sb(n); ay=cy+bt.sb(n)
                edges.append(('C',x/20,y/20,ax/20,ay/20,cur_line)); x,y=ax,ay
    return sid,[v/20 for v in r],fs,ls,edges
def main(p,full=False):
    d=open(p,'rb').read()
    b=zlib.decompress(d[8:]) if d[:1]==b'C' else d[8:]
    bt=Bits(b); r=rect(bt); pos=bt.p>>3; pos+=4
    print('version',d[3],'stage',[v/20 for v in r])
    tags(b,pos,full,'')
def tags(b,pos,full,ind):
    while pos<len(b):
        h=struct.unpack_from('<H',b,pos)[0]; pos+=2; code=h>>6; ln=h&63
        if ln==63: ln=struct.unpack_from('<I',b,pos)[0]; pos+=4
        body=b[pos:pos+ln]; pos+=ln
        if code in (2,22,32,83):
            ver={2:1,22:2,32:3,83:4}[code]
            sid,r,fs,ls,edges=shape(body,ver)
            print(ind+f'DefineShape{ver} id={sid} bounds={r} fills={fs} lines={ls} nedges={len(edges)}')
            if full:
                for e in edges: print('   ',e)
        elif code in (26,70):
            bt=Bits(body); fl=bt.u8()
            if code==70: bt.u8()
            depth=bt.u16(); cid=bt.u16() if fl&2 else None
            m=matrix(bt) if fl&4 else None
            print(ind+f'Place depth={depth} id={cid} m={m}')
        elif code==4:
            bt=Bits(body); cid=bt.u16(); depth=bt.u16(); print(f'Place1 depth={depth} id={cid} m={matrix(bt)}')
        elif code==39:
            sid,nf=struct.unpack_from('<HH',body,0); print(ind+f'DefineSprite id={sid} frames={nf}'); tags(body,4,full,ind+'  ')
        elif code==56:
            n=struct.unpack_from('<H',body,0)[0]; print(ind+'Export',body[2:].split(b'\0')[:4])
        elif code==1: print(ind+'ShowFrame')
        elif code==0: break
main(sys.argv[1], len(sys.argv)>2)
