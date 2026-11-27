import sys; import numpy as np; from PIL import Image
def g(f): return np.asarray(Image.open(f).convert('L')).astype(int)
a=g(sys.argv[1]); b=g(sys.argv[2])
# row bands from create_test_swf: rows 0-3 y=4+20k h=12; then sizes
bands=[]; y=4.0
for k in range(4): bands.append(('12px+%.2f'%(k*.25),int(y),int(y+12*1.6+4))); y+=20
for sz in (18,24,36,48,72,96):
  bands.append(('%dpx'%sz,int(y),int(y+sz*1.6+4))); y+=sz*1.25+2
  if y>600: break
def runs(col):
  r=[];inr=False
  for i,v in enumerate(col):
    if v and not inr: s=i;inr=True
    if not v and inr: r.append((s,i-1));inr=False
  if inr:r.append((s,len(col)-1))
  return r
for n,y0,y1 in bands:
  y1=min(y1,600); A=a[y0:y1]; B=b[y0:y1]
  ca=(A<160).any(0); cb=(B<160).any(0)
  ra=runs(ca); rb=runs(cb)
  d=(abs(A-B)>2).sum()
  print(n,y0,y1,'diff',d,'runsA',len(ra),'runsB',len(rb))
  print('  A',ra[:16]); print('  B',rb[:16])
