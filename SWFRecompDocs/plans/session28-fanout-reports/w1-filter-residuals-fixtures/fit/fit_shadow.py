import math,sys
from PIL import Image
D=sys.argv[1]
f=Image.open(D+'/output.expected.png').convert('RGB').load(); o=Image.open(D+'/output.actual.png').convert('RGB').load()
W,H=200,150
A=[[255 if (20<=x<100 and 20<=y<80) else 0 for x in range(W)] for y in range(H)]
wts=[0.5,1,1,1,0.5]
def bx(img,axis):
    out=[[0]*W for _ in range(H)]
    for y in range(H):
        for x in range(W):
            s=0
            for k,w in enumerate(wts):
                xx,yy=(x+k-2,y) if axis==0 else (x,y+k-2)
                if 0<=xx<W and 0<=yy<H: s+=w*img[yy][xx]
            out[y][x]=math.floor(s/4)
    return out
B=bx(bx(A,0),1)
d=12*math.cos(math.pi/4)  # 8.485
def samp(x,y,quant=None):
    sx=x-d; sy=y-d; ix=math.floor(sx); iy=math.floor(sy); fx=sx-ix; fy=sy-iy
    if quant: fx=math.floor(fx*quant)/quant; fy=math.floor(fy*quant)/quant
    g=lambda X,Y: B[Y][X] if 0<=X<W and 0<=Y<H else 0
    return (g(ix,iy)*(1-fx)*(1-fy)+g(ix+1,iy)*fx*(1-fy)+g(ix,iy+1)*(1-fx)*fy+g(ix+1,iy+1)*fx*fy)
def render(sfun):
    bad=0;mx=0
    for y in range(H):
        for x in range(W):
            if A[y][x]: continue
            s=sfun(x,y)
            g=255-round(s*128/256)   # 50% black shadow over white
            dd=abs(g-f[x,y][0]); mx=max(mx,dd); bad+= dd>1
    return bad,mx
for q in [None,256,64,16]:
    print('bilinear frac q',q, render(lambda x,y: samp(x,y,q)))
print('nearest(ours-model)', render(lambda x,y: (lambda X,Y: B[Y][X] if 0<=X<W and 0<=Y<H else 0)(x-8,y-8)))
# compare our model vs our actual
bad=0
for y in range(H):
  for x in range(W):
    if A[y][x]: continue
    X,Y=x-8,y-8; s=B[Y][X] if 0<=X<W and 0<=Y<H else 0
    if abs(255-round(s*128/256)-o[x,y][0])>1: bad+=1
print('nearest model vs OUR actual >1:',bad)
