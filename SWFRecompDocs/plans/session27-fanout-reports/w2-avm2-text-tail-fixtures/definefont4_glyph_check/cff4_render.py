#!/usr/bin/env python3
# s27 w2-avm2-text-tail: rasterise the recompiler-emitted DefineFont4 outlines
# (avm2_cff4_outline_0 in RecompiledABC/abc_timeline.c) with PIL and diff them
# against visual/definefont4/output.expected.png.
# usage: cff4_render.py <abc_timeline.c> <expected.png> [size x0 base1 base2]
import re, sys
from PIL import Image, ImageDraw, ImageChops
src=open(sys.argv[1]).read()
def arr(name, conv):
    m=re.search(r'%s\[\] = \{([^}]*)\}'%re.escape(name), src)
    return [conv(x.strip().rstrip('f')) for x in m.group(1).split(',') if x.strip()]
p='avm2_cff4_outline_0'
codes=arr(p+'_codes',int); adv=arr(p+'_advances',int); pts=arr(p+'_pts',float)
ps=arr(p+'_pt_start',int); ce=arr(p+'_contour_ends',int); cs=arr(p+'_contour_start',int)
idx={c:i for i,c in enumerate(codes)}
def draw_text(img, text, x0, base, size, upem=1000):
    s=size/upem; x=x0
    for ch in text:
        g=idx.get(ord(ch))
        if g is None: continue
        mask=Image.new('L',img.size,0)
        for k in range(cs[g],cs[g+1]):
            a=ps[g] if k==cs[g] else ce[k-1]; b=ce[k]
            poly=[(x+pts[2*i]*s, base+pts[2*i+1]*s) for i in range(a,b)]
            m=Image.new('L',img.size,0); ImageDraw.Draw(m).polygon(poly,fill=255)
            mask=ImageChops.logical_xor(mask.convert('1'),m.convert('1')).convert('L')
        img.paste((0,0,0),(0,0),mask)
        x+=adv[g]*s
    return x
exp=Image.open(sys.argv[2]).convert('RGB')
W,H=exp.size
best=None
for size in [float(sys.argv[3])] if len(sys.argv)>3 else [40,42,44,46,48]:
    img=Image.new('RGB',(W,H),(255,255,255))
    draw_text(img,"This is a TLF using",float(sys.argv[4]) if len(sys.argv)>4 else 28,float(sys.argv[5]) if len(sys.argv)>5 else 62,size)
    draw_text(img,"DefineFont4.",float(sys.argv[4]) if len(sys.argv)>4 else 28,float(sys.argv[6]) if len(sys.argv)>6 else 120,size)
    d=ImageChops.difference(img,exp).convert('L')
    n=sum(1 for v in d.getdata() if v>128)
    print(size,n)
    img.save('/tmp/claude-0/sp/cff4_%g.png'%size)
print(''.join(chr(c) for c in codes))
g=idx[ord('D')]; ys=[pts[2*i+1] for i in range(ps[g],ps[g+1])]; xs=[pts[2*i] for i in range(ps[g],ps[g+1])]
print('D bbox units', min(xs),max(xs),min(ys),max(ys), 'adv', adv[g])
g=idx[ord('T')]; xs=[pts[2*i] for i in range(ps[g],ps[g+1])]; print('T minx', min(xs))
for t in ["This is a TLF using","DefineFont4."]:
    w=sum(adv[idx[ord(c)]] for c in t); print(t, 'adv units', w)
g=idx[ord('g')]; xs=[pts[2*i] for i in range(ps[g],ps[g+1])]; print('g maxx', max(xs), 'adv',adv[g])
g=idx[ord('.')]; xs=[pts[2*i] for i in range(ps[g],ps[g+1])]; print('. maxx', max(xs), 'adv',adv[g])
