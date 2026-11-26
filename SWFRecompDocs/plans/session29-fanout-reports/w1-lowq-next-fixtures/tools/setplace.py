"""Rewrite the translation of root PlaceObject2 tags (by depth) in an SWF. usage: in out depth:tx:ty[,...] (px)"""
import sys, zlib, struct
sys.path.insert(0, sys.argv[0].rsplit('/',1)[0])
inp,outp,spec=sys.argv[1:4]
want={int(a):(float(b),float(c)) for a,b,c in (s.split(':') for s in spec.split(','))}
d=open(inp,'rb').read(); b=bytearray(zlib.decompress(d[8:]) if d[:1]==b'C' else d[8:])
class BW:
    def __init__(s): s.bits=[]
    def ub(s,n,v):
        for i in range(n-1,-1,-1): s.bits.append((v>>i)&1)
    def sb(s,n,v): s.ub(n,v&((1<<n)-1))
    def bytes(s):
        while len(s.bits)%8: s.bits.append(0)
        return bytes(int(''.join(map(str,s.bits[i:i+8])),2) for i in range(0,len(s.bits),8))
from swfshapes import Bits
nb=(b[0]>>3); pos=(5+4*nb+7)//8+4
out=bytearray(b[:pos])
while pos<len(b):
    h=struct.unpack_from('<H',b,pos)[0]; code=h>>6; ln=h&63; hl=2
    if ln==63: ln=struct.unpack_from('<I',b,pos+2)[0]; hl=6
    body=bytes(b[pos+hl:pos+hl+ln]); pos+=hl+ln
    if code==26 and (body[0]&4):
        fl=body[0]; depth=struct.unpack_from('<H',body,1)[0]; o=3+(2 if fl&2 else 0)
        if depth in want:
            bt=Bits(body,o); w=BW()
            hs=bt.ub(1); w.ub(1,hs)
            if hs: n=bt.ub(5); w.ub(5,n); w.sb(n,bt.sb(n)); w.sb(n,bt.sb(n))
            hr=bt.ub(1); w.ub(1,hr)
            if hr: n=bt.ub(5); w.ub(5,n); w.sb(n,bt.sb(n)); w.sb(n,bt.sb(n))
            n=bt.ub(5); bt.sb(n); bt.sb(n); bt.align()
            tx,ty=[round(v*20) for v in want[depth]]; n2=max(abs(tx),abs(ty)).bit_length()+1
            w.ub(5,n2); w.sb(n2,tx); w.sb(n2,ty)
            body=body[:o]+w.bytes()+body[bt.p>>3:]; ln=len(body)
            print('patched depth',depth,want[depth])
    out+=struct.pack('<HI',(code<<6)|63,ln)+body if ln>=63 else struct.pack('<H',(code<<6)|ln)+body
hdr=bytearray(b'FWS'+d[3:4]+struct.pack('<I',len(out)+8))
open(outp,'wb').write(bytes(hdr+out))
