import sys; sys.path.insert(0,'.')
from evalC import *
def segs(s):
    out=[];cur=None
    for c in s['cmds']:
        if c[0]=='M': cur=np.array(c[1:3])
        elif c[0]=='L':
            b=np.array(c[1:3]); out.append((cur,(cur+b)/2,b)); cur=b
        else: out.append((cur,np.array(c[1:3]),np.array(c[3:5]))); cur=np.array(c[3:5])
    return out
def nearest(s,p):
    best=None
    T=np.linspace(0,1,4001)
    for k,(a,c,b) in enumerate(segs(s)):
        P=(1-T)[:,None]**2*a+2*((1-T)*T)[:,None]*c+(T*T)[:,None]*b
        d=np.hypot(*(P-p).T); i=d.argmin()
        if best is None or d[i]<best[0]:
            t=T[i]; D=2*(1-t)*(c-a)+2*t*(b-c); DD=2*(a-2*c+b)
            cross=D[0]*DD[1]-D[1]*DD[0]; kappa=cross/np.hypot(*D)**3
            v=p-P[i]; side=np.sign(D[0]*v[1]-D[1]*v[0])*np.sign(cross)  # +1 = towards centre of curvature (inner)
            best=(d[i],k,t,kappa,side)
    return best
if __name__=='__main__':
    dO=np.abs(O-G).max(2)
    ys,xs=np.where((dO>64)&M_)
    res=[]
    for y,x in zip(ys,xs):
        s=S[lab[y,x]]
        if y-s['ty']<0: continue
        c=colour(s).astype(float); kg=(G[y,x]*c).sum()/(c*c).sum(); ko=(O[y,x]*c).sum()/(c*c).sum()
        p=np.array([x+0.5-s['tx'],y+0.5-s['ty']])
        d,k,t,kap,side=nearest(s,p)
        res.append((d,kg-ko,k,t,kap,side))
    res=np.array(res)
    for lo,hi in ((0,1.5),(1.5,2.0),(2.0,2.2),(2.2,3)):
        m=(res[:,0]>=lo)&(res[:,0]<hi)
        r=res[m]
        print(f'd[{lo},{hi}) n={m.sum()} G>O {np.sum(r[:,1]>0)} G<O {np.sum(r[:,1]<0)}')
    m=(res[:,0]>=2.15)&(res[:,1]>0)
    r=res[m]
    print('outside & Flash fatter: n',len(r),' inner-side',np.sum(r[:,5]>0),'outer-side',np.sum(r[:,5]<0))
    print(' |kappa| quartiles',np.percentile(np.abs(r[:,4]),[10,50,90]), ' radius med',np.median(1/np.abs(r[:,4])))
    print(' t hist',np.histogram(r[:,3],bins=10,range=(0,1))[0])
    m2=(res[:,0]<2.15)&(res[:,0]>1.6)
    print('all edge px kappa med',np.median(np.abs(res[m2][:,4])))
