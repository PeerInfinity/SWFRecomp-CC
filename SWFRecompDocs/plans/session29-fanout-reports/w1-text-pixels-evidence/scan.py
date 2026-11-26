import numpy as np, math
from PIL import Image
F=np.asarray(Image.open('flash.png').convert('L')).astype(int)
nF=np.clip(np.round((255-F)/16.0),0,16).astype(int)
def poly_x_intervals(poly, y):
    xs=[]
    n=len(poly)
    for i in range(n):
        (x0,y0),(x1,y1)=poly[i],poly[(i+1)%n]
        if (y0<=y<y1) or (y1<=y<y0):
            xs.append(x0+(y-y0)*(x1-x0)/(y1-y0))
    xs.sort()
    return [(xs[i],xs[i+1]) for i in range(0,len(xs)-1,2)]
def union(iv):
    iv=sorted(iv); out=[]
    for a,b in iv:
        if out and a<=out[-1][1]: out[-1]=(out[-1][0],max(out[-1][1],b))
        else: out.append((a,b))
    return out
def raster(polys, H=200, W=200, N=4, phy=0.5, quant='round'):
    cov=np.zeros((H,W))
    for y in range(H):
        for j in range(N):
            ys=y+(j+phy)/N
            iv=[]
            for p in polys: iv+=poly_x_intervals(p,ys)
            for a,b in union(iv):
                a=max(a,0); b=min(b,W)
                xa,xb=int(math.floor(a)),int(math.floor(b))
                for x in range(xa,min(xb,W-1)+1):
                    o=min(b,x+1)-max(a,x)
                    if o>0: cov[y,x]+=o/N
    n=cov*16
    return np.clip(np.floor(n+0.5) if quant=='round' else (np.floor(n+1e-9) if quant=='floor' else np.ceil(n-1e-9)),0,16).astype(int)
def seg_poly(a,b,k,ox=0.0,oy=0.0,ext=0.0):
    (ax,ay),(bx,by)=a,b
    dx,dy=bx-ax,by-ay
    if abs(dy)>abs(dx): wx,wy=k,0.0
    else: wx,wy=0.0,k
    ax+=ox; bx+=ox; ay+=oy; by+=oy
    return [(ax-wx/2,ay-wy/2),(bx-wx/2,by-wy/2),(bx+wx/2,by+wy/2),(ax+wx/2,ay+wy/2)]
