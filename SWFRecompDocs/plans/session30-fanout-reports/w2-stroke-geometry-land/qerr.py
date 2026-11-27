import sys, numpy as np
sys.path.insert(0, sys.argv[0].rsplit('/',1)[0])
import side, qoff
from scipy.spatial import cKDTree

def dev_piece(pc, h, tree):
    a0,cc,a1 = qoff.offq(*pc, h)
    o = side.quad(a0,cc,a1,np.linspace(0,1,200)); d,_ = tree.query(o)
    return np.max(np.abs(d-abs(h)))

def pieces_err(pc, h, tree, tau, depth=0, mode='max'):
    if depth < 10:
        if mode=='max': e = dev_piece(pc, h, tree)
        else:
            a0,cc,a1 = qoff.offq(*pc, h); m = side.quad(a0,cc,a1,np.array([0.5])); e = abs(tree.query(m)[0][0]-abs(h))
        if e > tau:
            a,b = qoff.split(*pc); return pieces_err(a,h,tree,tau,depth+1,mode)+pieces_err(b,h,tree,tau,depth+1,mode)
    return [pc]

tr = sys.argv[1]; taus=[float(x) for x in sys.argv[2].split(',')]; mode=sys.argv[3] if len(sys.argv)>3 else 'max'
for cell in side.cells_from_trace(tr):
    if cell['f']!=0: continue
    s, hw = cell['s'], cell['w']*cell['s']/2; tx,ty=cell['x'],cell['y']
    print("cell w%g s%g k%d"%(cell['w'],s,cell['k']))
    for ci,(p0,c,p1) in enumerate(side.SHAPES[cell['k']]):
        P=[np.array(p,float)*s+(tx,ty) for p in (p0,c,p1)]
        n=20000; t=np.linspace(0,1,n); q=side.quad(*P,t); tree=cKDTree(q)
        d2=2*(P[0]-2*P[1]+P[2]); d1=P[2]-P[0]; cs=np.sign(d1[0]*d2[1]-d1[1]*d2[0])
        sg = -1 if cs>0 else +1   # convex side normal sign
        for tau in taus:
            pcs = pieces_err(tuple(P), sg*hw, tree, tau, mode=mode)
            bins=np.zeros(10); w=np.zeros(10)
            for pc in pcs:
                a0,cc,a1=qoff.offq(*pc, sg*hw); o=side.quad(a0,cc,a1,np.linspace(0,1,400))
                d,idx=tree.query(o); tb=(t[idx]*10).astype(int).clip(0,9)
                dl=np.r_[np.hypot(*np.diff(o,axis=0).T),0]
                np.add.at(bins,tb,(d-hw)*dl); np.add.at(w,tb,dl)
            print(" curve%d tau%g n%d: "%(ci,tau,len(pcs))+" ".join("%+.2f"%(b/max(ww,1e-9)) for b,ww in zip(bins,w)))
