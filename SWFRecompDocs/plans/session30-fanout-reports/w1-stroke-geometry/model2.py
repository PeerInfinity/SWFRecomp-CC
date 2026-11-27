import numpy as np, sys
from PIL import Image
from shapely.geometry import LineString, Polygon, box
from shapely.ops import unary_union
from shapely import affinity
sys.path.insert(0,'/tmp/claude-0/sp')
from shapes import load
G=np.asarray(Image.open('/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/from_shumway/acid/acid-shapes/output.expected.png').convert('RGB')).astype(int)
O=np.asarray(Image.open(__import__('os').environ.get('OURS','/tmp/claude-0/sp/shapes_before.png')).convert('RGB')).astype(int)
def qp(p0,c,p1,n=200):
    t=np.linspace(0,1,n)[:,None]
    return (1-t)**2*np.array(p0)+2*(1-t)*t*np.array(c)+t*t*np.array(p1)
def centreline(s):
    pts=[];cur=None
    for c in s['cmds']:
        if c[0]=='M': cur=(c[1],c[2]); pts.append(np.array([cur]))
        elif c[0]=='L': cur=(c[1],c[2]); pts.append(np.array([cur]))
        else: pts.append(qp(cur,(c[1],c[2]),(c[3],c[4]))[1:]); cur=(c[3],c[4])
    return np.concatenate(pts)+np.array([s['tx'],s['ty']])
def region_exact(s):
    return LineString(centreline(s)).buffer(s['w']/2, quad_segs=64)
def raster(reg):
    x0,y0,x1,y1=reg.bounds; x0=int(np.floor(x0));y0=int(np.floor(y0));x1=int(np.ceil(x1))+1;y1=int(np.ceil(y1))+1
    cov=np.zeros((y1-y0,x1-x0))
    for yi in range(y0,y1):
        for j in range(4):
            yy=yi+j/4
            inter=reg.intersection(LineString([(x0-1,yy),(x1+1,yy)]))
            if inter.is_empty: continue
            geoms=getattr(inter,'geoms',[inter])
            for g in geoms:
                if g.geom_type!='LineString': continue
                xs=[p[0] for p in g.coords]; a,b=min(xs),max(xs)
                for px in range(int(np.floor(a)),int(np.ceil(b))):
                    l=min(b,px+1)-max(a,px)
                    if l>0: cov[yi-y0,px-x0]+=l/4
    return np.floor(16*cov+1e-9),x0,y0
def colour(s): return np.array([(s['col']>>16)&255,(s['col']>>8)&255,s['col']&255])
def evaluate(regfn, S):
    regs=[regfn(s) for s in S]
    out=np.zeros_like(G); owner=np.zeros(G.shape[:2],int)
    for k,(s,r) in enumerate(zip(S,regs)):
        n,x0,y0=raster(r); h,w=n.shape
        M=np.floor(colour(s)[None,None]*n[...,None]/16)
        H,W=G.shape[:2]
        cy0=max(y0,0);cx0=max(x0,0);cy1=min(y0+h,H);cx1=min(x0+w,W)
        n=n[cy0-y0:cy1-y0,cx0-x0:cx1-x0]; M=M[cy0-y0:cy1-y0,cx0-x0:cx1-x0]
        sl=(slice(cy0,cy1),slice(cx0,cx1))
        m=n>0
        out[sl][m]=M[m]; owner[sl][m]+=1
    return out,owner
