import sys
from PIL import Image
import numpy as np
def load(p): return 255-np.asarray(Image.open(p).convert('L'),dtype=float)
F=load(sys.argv[1]); others=[(n,load(p)) for n,p in zip(sys.argv[2::2],sys.argv[3::2])]
H,W=F.shape
rowink=F.sum(1)>0
bands=[];y=0
while y<H:
  if rowink[y]:
    y0=y
    while y<H and rowink[y]: y+=1
    bands.append((y0,y))
  else: y+=1
for (y0,y1) in bands:
  col=F[y0:y1].sum(0)>0
  words=[];x=0
  while x<W:
    if col[x]:
      x0=x;gap=0
      while x<W and gap<5:
        gap = 0 if col[x] else gap+1; x+=1
      words.append((x0,x-gap))
    else: x+=1
  line=[]
  for (a,b) in words:
    f=F[y0-2:y1+2,a-4:b+4]
    res=[]
    for n,O in others:
      best=None
      for dy in (-2,-1,0,1,2):
       for dx in range(-4,5):
        o=O[y0-2+dy:y1+2+dy,a-4+dx:b+4+dx]
        e=np.abs(o-f).sum()
        if best is None or e<best[0]: best=(e,dx,dy)
      e0=np.abs(O[y0-2:y1+2,a-4:b+4]-f).sum()
      res.append(f'{n}:{best[1]:+d},{best[2]:+d}({int(e0/1000)}k)')
    line.append(f'[{a}-{b}] '+' '.join(res))
  print(f'band y{y0}-{y1}:'); print('   '+'\n   '.join(line))
