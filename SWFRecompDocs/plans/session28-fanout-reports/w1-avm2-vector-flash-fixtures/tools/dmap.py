import sys
from PIL import Image
import numpy as np
from collections import deque
def load(p): return np.asarray(Image.open(p).convert('RGBA')).astype(int)
d=sys.argv[1]; tol=int(sys.argv[2]); out=sys.argv[3]
e=load(d+'/output.expected.png'); a=load(d+'/output.actual.png')
r=None
try: r=load(d+'/output.ruffle.png')
except: pass
diff=np.abs(e-a).max(axis=2); m=diff>tol
print('size',e.shape,'outliers',m.sum(),'max',diff.max())
if r is not None and r.shape==e.shape:
    print('ours-vs-ruffle',(np.abs(r-a).max(axis=2)>tol).sum(),' ruffle-vs-flash',(np.abs(r-e).max(axis=2)>tol).sum())
# components (8-conn, dilate 2)
H,W=m.shape; lab=np.zeros((H,W),int); comps=[]
ys,xs=np.nonzero(m)
for y0,x0 in zip(ys,xs):
    if lab[y0,x0]: continue
    q=deque([(y0,x0)]); lab[y0,x0]=len(comps)+1; pts=[]
    while q:
        y,x=q.popleft(); pts.append((y,x))
        for dy in range(-3,4):
            for dx in range(-3,4):
                yy,xx=y+dy,x+dx
                if 0<=yy<H and 0<=xx<W and m[yy,xx] and not lab[yy,xx]:
                    lab[yy,xx]=len(comps)+1; q.append((yy,xx))
    comps.append(pts)
comps.sort(key=lambda p:-len(p))
for pts in comps[:25]:
    P=np.array(pts); y,x=P[0]
    dm=max(diff[p[0],p[1]] for p in pts)
    print(f'n={len(pts):5d} bbox x{P[:,1].min()}-{P[:,1].max()} y{P[:,0].min()}-{P[:,0].max()} max={dm} e.g.({x},{y}) gold={tuple(e[y,x])} ours={tuple(a[y,x])}')
print('ncomps',len(comps))
sc=int(sys.argv[4]) if len(sys.argv)>4 else 1
vis=np.concatenate([e[:,:,:3],a[:,:,:3],np.stack([np.where(m,255,diff*4).clip(0,255)]*3,2)],1).astype(np.uint8)
Image.fromarray(vis).resize((vis.shape[1]*sc,vis.shape[0]*sc),Image.NEAREST).save(out)
