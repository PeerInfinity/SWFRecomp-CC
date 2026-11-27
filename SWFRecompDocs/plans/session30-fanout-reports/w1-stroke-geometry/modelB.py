import sys; sys.path.insert(0,'/tmp/claude-0/sp')
import numpy as np
from model2 import *
from shapely.geometry import Point, Polygon, LineString
from shapely.ops import unary_union
def split_quad(p0,c,p1,k):
    # equal-parameter split into k quads
    P0=np.array(p0,float);C=np.array(c,float);P1=np.array(p1,float)
    def B(t): return (1-t)**2*P0+2*(1-t)*t*C+t*t*P1
    def D(t): return 2*(1-t)*(C-P0)+2*t*(P1-C)
    out=[]
    for i in range(k):
        a=i/k;b=(i+1)/k
        pa=B(a);pb=B(b); ca=pa+(b-a)/2*D(a)
        out.append((pa,ca,pb))
    return out
def unit(v):
    l=np.hypot(*v); return v/l if l>1e-12 else v*0
def offset_quad(pa,c,pb,d):
    t0=unit(c-pa); t1=unit(pb-c)
    if np.hypot(*(c-pa))<1e-9: t0=unit(pb-pa)
    if np.hypot(*(pb-c))<1e-9: t1=unit(pb-pa)
    n0=np.array([-t0[1],t0[0]]); n1=np.array([-t1[1],t1[0]])
    qa=pa+d*n0; qb=pb+d*n1
    # control = intersection of lines qa + s t0 and qb + u t1
    den=t0[0]*t1[1]-t0[1]*t1[0]
    if abs(den)<1e-9: qc=(qa+qb)/2
    else:
        w=qb-qa; s=(w[0]*t1[1]-w[1]*t1[0])/den; qc=qa+s*t0
    return qa,qc,qb
MODE=None
def piece_region(pa,c,pb,hw):
    o=offset_quad(pa,c,pb,hw); i=offset_quad(pa,c,pb,-hw)
    po=qp(*o,n=100); pi=qp(*i,n=100)[::-1]
    poly=Polygon(np.concatenate([po,pi]))
    if not poly.is_valid: poly=poly.buffer(0)
    return poly
def region_B(s, k=1, kfn=None):
    hw=s['w']/2; T=np.array([s['tx'],s['ty']])
    parts=[];cur=None; pts=[]
    for cm in s['cmds']:
        if cm[0]=='M': cur=np.array(cm[1:3]); pts.append(cur)
        else:
            c=np.array(cm[1:3]); p1=np.array(cm[3:5])
            kk=kfn(cur,c,p1) if kfn else k
            for (pa,ca,pb) in split_quad(cur,c,p1,kk):
                parts.append(piece_region(pa+T,ca+T,pb+T,hw)); 
                parts.append(Point(*(pa+T)).buffer(hw,quad_segs=64))
            cur=p1; pts.append(cur)
    parts.append(Point(*(cur+T)).buffer(hw,quad_segs=64))
    return unary_union(parts)
