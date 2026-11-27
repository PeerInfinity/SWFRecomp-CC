import sys; sys.path.insert(0,'.')
import numpy as np
from font2 import *
from glyphs import *
def flatten_contour(c, mode, par, sc):
    # c in glyph units; returns pts in glyph units
    pts=[]; x=y=None
    for e in c:
        if e[0]=='M': x,y=e[1],e[2]; pts.append((x,y))
        elif e[0]=='L': x,y=e[1],e[2]; pts.append((x,y))
        else:
            cx,cy,x1,y1=e[1:]
            if mode=='n': n=par
            elif mode=='tol':  # device-px tolerance: deviation of control pt from chord /4 ~ max error
                dev=abs((cx-(x+x1)/2)**2+(cy-(y+y1)/2)**2)**0.5*sc/20/2  # max curve dev in px (half the control offset)
                n=1
                while dev/(n*n) > par: n+=1
            elif mode=='rec':
                n=1; dev=abs((cx-(x+x1)/2)**2+(cy-(y+y1)/2)**2)**0.5*sc/20/2
                while dev/(n*n) > par: n*=2
            for s in range(1,n+1):
                t=s/n; it=1-t
                pts.append((it*it*x+2*it*t*cx+t*t*x1, it*it*y+2*it*t*cy+t*t*y1))
            x,y=x1,y1
    return pts
def raster_polys(polys,W,H,ymode='lowq',xtie='incl',sy=0.5):
    m=np.zeros((H,W),bool)
    edges=[]
    for P in polys:
        Q=list(P)
        if ymode=='lowq': Q=[(p[0],lowq_y(p[1])) for p in Q]
        n=len(Q)
        for i in range(n):
            a=Q[i]; b=Q[(i+1)%n]
            if a[1]==b[1]: continue
            edges.append((a,b))
    if not edges: return m
    ymin=max(int(np.floor(min(min(a[1],b[1]) for a,b in edges)))-1,0); ymax=min(int(np.ceil(max(max(a[1],b[1]) for a,b in edges)))+1,H)
    for j in range(ymin,ymax):
        yc=j+sy; xs=[]
        for a,b in edges:
            y0,y1=a[1],b[1]
            if (y0<=yc<y1) or (y1<=yc<y0):
                t=(yc-y0)/(y1-y0); xs.append(a[0]+t*(b[0]-a[0]))
        xs.sort()
        for k in range(0,len(xs)-1,2):
            x0,x1=xs[k],xs[k+1]
            # pixels i with centre in [x0,x1)
            i0=int(np.ceil(x0-0.5)); i1=int(np.ceil(x1-0.5))
            i0=max(i0,0); i1=min(i1,W)
            if i1>i0: m[j,i0:i1]^=True
    return m
def render(G,fonts,fid,W,H,mode,par,ymode='lowq',pen='rint',sy=0.5):
    f=fonts[fid]; polys=[]
    for g in G:
        gl=f['glyphs'][f['codes'].index(g['cp'])] if g['cp'] in f['codes'] else None
        if gl is None: continue
        sc=g['scale']
        px=round(g['x']/20)*20 if pen=='rint' else g['x']; py=round(g['y']/20)*20 if pen=='rint' else g['y']
        if pen=='dump':  # use dumped first vertex offset? fallback rint
            pass
        for c in gl:
            pts=flatten_contour(c,mode,par,sc)
            polys.append([((u*sc+px)/20,(v*sc+py)/20) for u,v in pts])
    # even-odd across all polys: XOR per-glyph is wrong across overlapping glyphs; do per glyph-set union
    return raster_polys(polys,W,H,ymode,sy=sy)
