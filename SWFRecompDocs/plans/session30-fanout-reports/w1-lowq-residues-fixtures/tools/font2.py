import zlib,struct
class BR:
  def __init__(s,b,p=0): s.b=b; s.p=p*8
  def u(s,n):
    v=0
    for _ in range(n): v=(v<<1)|((s.b[s.p>>3]>>(7-(s.p&7)))&1); s.p+=1
    return v
  def s_(s,n):
    v=s.u(n); return v-(1<<n) if n and v>>(n-1) else v
def parse_glyph(b,off):
    br=BR(b,off); nf=br.u(4); nl=br.u(4)
    x=y=0; contours=[]; cur=None
    while True:
        if br.u(1)==0:
            fl=br.u(5)
            if fl==0: break
            if fl&1:
                n=br.u(5); x=br.s_(n); y=br.s_(n)
                cur=[('M',x,y)]; contours.append(cur)
            if fl&2: br.u(nf)
            if fl&4: br.u(nf)
            if fl&8: br.u(nl)
            if fl&16: raise Exception('newstyles in glyph')
        else:
            if cur is None: cur=[('M',x,y)]; contours.append(cur)
            if br.u(1):
                n=br.u(4)+2
                if br.u(1): dx=br.s_(n); dy=br.s_(n)
                elif br.u(1): dx=0; dy=br.s_(n)
                else: dx=br.s_(n); dy=0
                x+=dx; y+=dy; cur.append(('L',x,y))
            else:
                n=br.u(4)+2
                cx=x+br.s_(n); cy=y+br.s_(n); x=cx+br.s_(n); y=cy+br.s_(n)
                cur.append(('Q',cx,cy,x,y))
    return contours
def load_fonts(path):
    d=open(path,'rb').read()
    if d[:3]==b'CWS': d=d[:8]+zlib.decompress(d[8:])
    nb=d[8]>>3; p=8+(5+4*nb+7)//8+4; fonts={}
    while p<len(d):
        h=struct.unpack('<H',d[p:p+2])[0]; c=h>>6; l=h&63; p+=2
        if l==63: l=struct.unpack('<I',d[p:p+4])[0]; p+=4
        b=d[p:p+l]
        if c in (48,75):
            fid,fl=struct.unpack('<HB',b[:3]); q=4; nl=b[q]; q+=1+nl
            ng=struct.unpack('<H',b[q:q+2])[0]; q+=2; base=q
            wide=fl&8
            offs=[struct.unpack('<I' if wide else '<H',b[q+i*(4 if wide else 2):q+(i+1)*(4 if wide else 2)])[0] for i in range(ng)]
            q+= ng*(4 if wide else 2)
            cto=struct.unpack('<I' if wide else '<H',b[q:q+(4 if wide else 2)])[0]
            glyphs=[parse_glyph(b,base+o) for o in offs]
            cq=base+cto; wc=fl&4
            codes=[struct.unpack('<H',b[cq+2*i:cq+2*i+2])[0] if wc else b[cq+i] for i in range(ng)]
            fonts[fid]=dict(glyphs=glyphs,codes=codes,v3=(c==75),flags=fl)
        p+=l
        if c==0: break
    return fonts
