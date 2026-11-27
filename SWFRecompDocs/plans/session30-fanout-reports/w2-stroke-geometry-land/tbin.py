import sys, numpy as np
sys.path.insert(0, sys.argv[0].rsplit('/',1)[0])
import side
from PIL import Image
from scipy.spatial import cKDTree
tr, png = sys.argv[1], sys.argv[2]; extra = sys.argv[3:]
im = np.asarray(Image.open(png).convert('RGB')).astype(float)
ims = [np.asarray(Image.open(p).convert('RGB')).astype(float) for p in extra]
for cell in side.cells_from_trace(tr):
    if cell['f']!=0: continue
    s, hw = cell['s'], cell['w']*cell['s']/2; tx,ty=cell['x'],cell['y']
    print("cell w%g s%g k%d"%(cell['w'],s,cell['k']))
    for ci,(p0,c,p1) in enumerate(side.SHAPES[cell['k']]):
        P0=np.array(p0)*s+(tx,ty); C=np.array(c)*s+(tx,ty); P1=np.array(p1)*s+(tx,ty)
        n=40000; t=np.linspace(0,1,n); q=side.quad(P0,C,P1,t); d1=side.dquad(P0,C,P1,t); d2=2*(P0-2*C+P1)
        cs=np.sign(d1[:,0]*d2[1]-d1[:,1]*d2[0]); kap=np.abs(d1[:,0]*d2[1]-d1[:,1]*d2[0])/np.hypot(*d1.T)**3
        # all curves in tree for nearest; but only take pixels whose nearest is this curve
        allq=[]; 
        for (a,b,cc) in side.SHAPES[cell['k']]:
            allq.append(side.quad(np.array(a)*s+(tx,ty),np.array(b)*s+(tx,ty),np.array(cc)*s+(tx,ty),t))
        tree=cKDTree(np.concatenate(allq))
        x0,y0=q.min(0)-hw-3; x1,y1=q.max(0)+hw+3
        X,Y=np.meshgrid(np.arange(int(x0),int(x1)+1),np.arange(int(y0),int(y1)+1))
        Pp=np.stack([X.ravel()+.5,Y.ravel()+.5],1); d,idx=tree.query(Pp)
        own=(idx//n)==ci; band=own&(np.abs(d-hw)<1.2); ii=idx[band]%n
        Pb=Pp[band]; o=(np.arange(16)+.5)/16-.5; OX,OY=np.meshgrid(o,o)
        sub=(Pb[:,None,:]+np.stack([OX.ravel(),OY.ravel()],1)[None]).reshape(-1,2); ds,_=tree.query(sub)
        cex=(ds<=hw).reshape(len(Pb),-1).mean(1)
        v=Pb-q[ii]; cr=d1[ii,0]*v[:,1]-d1[ii,1]*v[:,0]; cvx=np.sign(cr)!=cs[ii]
        xs=X.ravel()[band]; ys=Y.ravel()[band]
        covs=[im[ys,xs,1]/208]+[m[ys,xs,1]/208 for m in ims]
        tb=(t[ii]*10).astype(int).clip(0,9)
        seg=np.r_[0,np.hypot(*np.diff(q,axis=0).T)]
        row=[]
        for b in range(10):
            m=(tb==b)&cvx; L=np.sum((seg*(1+hw*kap))[(t>=b/10)&(t<(b+1)/10)])
            Rr=1/np.mean(kap[(t>=b/10)&(t<(b+1)/10)])
            row.append("t%d R%.0f "%(b,Rr)+"/".join("%+.2f"%((cv[m].sum()-cex[m].sum())/L) for cv in covs))
        print(" curve%d convex: "%ci+"  ".join(row))
