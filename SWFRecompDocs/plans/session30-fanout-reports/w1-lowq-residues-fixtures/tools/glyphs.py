import numpy as np
def load_dump(p):
    L=open(p).read().split('\n'); G=[]; i=0
    while i<len(L):
        if L[i].startswith('G '):
            f=L[i].split(); n=int(f[6]); v=[tuple(map(float,L[i+1+k].split())) for k in range(n)]
            G.append(dict(cp=int(f[1]),gi=int(f[2]),scale=float(f[3]),x=float(f[4]),y=float(f[5]),v=v)); i+=1+n
        else: i+=1
    return G
def last_frame(G):
    # glyph list repeats per render; take the last block starting with the same (cp,x,y) as G[0]
    k0=(G[0]['cp'],G[0]['x'],G[0]['y']); starts=[i for i,g in enumerate(G) if (g['cp'],g['x'],g['y'])==k0]
    return G[starts[-1]:]
def raster_tris(tris,W,H,ox=0.5,oy=0.5):
    # tris: list of 3 (x,y) in px; pixel centre sampling, union (nonzero over tris)
    m=np.zeros((H,W),bool)
    for (a,b,c) in tris:
        xs=[a[0],b[0],c[0]]; ys=[a[1],b[1],c[1]]
        x0=max(int(np.floor(min(xs)))-1,0); x1=min(int(np.ceil(max(xs)))+1,W); y0=max(int(np.floor(min(ys)))-1,0); y1=min(int(np.ceil(max(ys)))+1,H)
        if x1<=x0 or y1<=y0: continue
        X,Y=np.meshgrid(np.arange(x0,x1)+ox,np.arange(y0,y1)+oy)
        def e(p,q): return (q[0]-p[0])*(Y-p[1])-(q[1]-p[1])*(X-p[0])
        d1,d2,d3=e(a,b),e(b,c),e(c,a)
        ins=((d1>=0)&(d2>=0)&(d3>=0))|((d1<=0)&(d2<=0)&(d3<=0))
        m[y0:y1,x0:x1]|=ins
    return m
def lowq_y(y): return min(y, np.ceil(y-0.5))+0.5
def tris_from(G, f=None):
    tris=[]
    for g in G:
        v=[(x/20,y/20) for x,y in g['v']]
        if f: v=[f(p) for p in v]
        tris+=[v[i:i+3] for i in range(0,len(v),3)]
    return tris
def raster_tl(tris,W,H,ox=0.5,oy=0.5):
    # D3D/Vulkan top-left rule, y-down
    m=np.zeros((H,W),bool)
    for (a,b,c) in tris:
        area=(b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0])
        if area==0: continue
        if area<0: b,c=c,b
        xs=[a[0],b[0],c[0]]; ys=[a[1],b[1],c[1]]
        x0=max(int(np.floor(min(xs)))-1,0); x1=min(int(np.ceil(max(xs)))+1,W); y0=max(int(np.floor(min(ys)))-1,0); y1=min(int(np.ceil(max(ys)))+1,H)
        if x1<=x0 or y1<=y0: continue
        X,Y=np.meshgrid(np.arange(x0,x1)+ox,np.arange(y0,y1)+oy)
        ok=np.ones(X.shape,bool)
        for p,q in ((a,b),(b,c),(c,a)):
            e=(q[0]-p[0])*(Y-p[1])-(q[1]-p[1])*(X-p[0])
            dx,dy=q[0]-p[0],q[1]-p[1]
            # with area>0 in y-down coords (clockwise visually), inside is e>0
            topleft=(dy==0 and dx>0) or (dy<0)
            ok&= (e>0) | ((e==0) & topleft)
        m[y0:y1,x0:x1]|=ok
    return m
