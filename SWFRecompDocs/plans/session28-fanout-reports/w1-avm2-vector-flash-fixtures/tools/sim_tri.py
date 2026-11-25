# Simulate Flash HIGH-quality AA as NxN supersampling over the drawTriangles test geometry.
import sys, numpy as np
from PIL import Image
N=int(sys.argv[1]); OFF=sys.argv[2]  # 'center' or 'corner'
ROUND=sys.argv[3]  # floor|round
W,H=50,110
def orient(a,b,c): return (b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
shapes=[]  # list of (ox,oy, [ (color, [tris]) ])
def cull(tris,mode):
    if mode=='none': return tris
    out=[]
    for t in tris:
        o=orient(*t)
        if mode=='positive' and o>=0: continue
        if mode=='negative' and o<=0: continue
        out.append(t)
    return out
def T(v,idx=None):
    P=[(v[i],v[i+1]) for i in range(0,len(v),2)]
    if idx is None: return [tuple(P[i:i+3]) for i in range(0,len(P)//3*3,3)]
    out=[]
    for i in range(0,len(idx)//3*3,3):
        a,b,c=idx[i:i+3]
        if max(a,b,c)>=len(P): break
        out.append((P[a],P[b],P[c]))
    return out
R=(255,0,0);B=(0,0,255);C=(0,255,255);M=(255,0,255);Y=(255,255,0);G=(0,255,0)
sq=[0,0,0,10,10,0,10,10]
cases=[ [(R,T([0,0,10,0,10,10,0,0,0,10,10,10]))],
 [(B,T(sq,[0,2,3,0,1,3]))],
 [(C,T(sq,[0,2,3,0,6,7,0,1,3]))],
 [(R,T([0,0,0,10,0,0]))],
 [(M,cull(T(sq,[0,2,3,0,1,3]),'negative'))],
 [(Y,cull(T(sq,[0,2,3,0,1,3]),'positive'))],
 [(R,T(sq,[0,1,3]))],
 [(R,T(sq+[0]*8,[4,5,7,0,1,3]))],  # X,Y->NaN; approximate NaN vertex as 0
 [(R,T(sq,[0,1,3]))],
 [(R,T(sq,[0,0,0,0,1,3]))],
 [(R,T([0,0,0,10,10,0]))],
 [(R,T([0,0,0,10,10,0,0,0,0,0,0,0]))],
 [(R,T([0,0,0,10,10,0,0,0,0,10,10,10]))],
 [(R,T(sq,[0,1,2,0,1,3]))],
 [] ]
sid=0
for rep in range(2):
    for c in cases:
        shapes.append((10*(sid%5),10*(sid//5),c)); sid+=1
coords=[]
for y in [0,10,20,30,40,50]:
    for x in [0,10,20,30,40,50]: coords+= [x,y]
def rows(base,step):
    return [i for r in range(5) for c in range(5) for i in ()]
I1=[];I2=[]
for r in range(5):
    for c in range(5):
        a=r*6+c; I1+=[a,a+1,a+6]; I2+=[a,a+1,a+7]
g3=[1,12,7,2,13,14,8,16,3,5,3,11,6,17,11,9,10,15]
cy=[12,13,18,13,18,19,13,14,19,14,19,20,14,15,20,15,20,21,15,16,21,16,21,22,16,17,22,17,22,23]
smoke=[(R,T(coords,I1)),(B,T(coords,I2)),(G,T(coords,g3)),(Y,cull(T(coords,[18+i for i in g3]),'positive')),
       (C,cull(T(coords,cy),'positive')),(M,cull(T(coords,cy),'negative'))]
shapes.append((0,60,smoke))
# rasterize at sample level; units: samples in 1/(2N) px for center offsets
S=N
img=np.zeros((H*S,W*S,3))
if OFF.startswith('xy'): fx,fy=map(float,OFF[2:].split(',')); sx=(np.arange(W*S)+fx)/S; sy=(np.arange(H*S)+fy)/S
elif OFF=='center': sx=(np.arange(W*S)+0.5)/S; sy=(np.arange(H*S)+0.5)/S
else: sx=np.arange(W*S)/S; sy=np.arange(H*S)/S
X,Y=np.meshgrid(sx,sy)
def inside(tri,ox,oy):
    a,b,c=[(p[0]+ox,p[1]+oy) for p in tri]
    o=orient(a,b,c)
    if o==0: return np.zeros(X.shape,bool)
    if o<0: b,c=c,b
    res=np.ones(X.shape,bool)
    for p,q in ((a,b),(b,c),(c,a)):
        e=(q[0]-p[0])*(Y-p[1])-(q[1]-p[1])*(X-p[0])   # >0 inside (o>0 orientation, y-down)
        dx,dy=q[0]-p[0],q[1]-p[1]
        # top-left rule (y-down, edges of a 'positive' triangle): include ties on top or left edges
        tl = (dy==0 and dx<0) or (dy>0)   # guess; flip via argv
        if sys.argv[4]=='flip': tl = not tl
        res &= (e>0) | ((e==0) & tl)
    return res
for ox,oy,fills in shapes:
    for col,tris in fills:
        m=np.zeros(X.shape,bool)
        for t in tris: m|=inside(t,ox,oy)
        img[m]=col
px=img.reshape(H,S,W,S,3).mean(axis=(1,3))
px=np.floor(px) if ROUND=='floor' else np.round(px)
e=np.asarray(Image.open(sys.argv[5]).convert('RGB')).astype(int)
d=np.abs(px-e).max(axis=2)
print(N,OFF,ROUND,sys.argv[4],'outliers>1',(d>1).sum(),'exact',(d==0).sum(),'max',d.max())
ys,xs=np.nonzero(d>1)
for y,x in list(zip(ys,xs))[:int(sys.argv[6]) if len(sys.argv)>6 else 8]: print((x,y),e[y,x],px[y,x])
