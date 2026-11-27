import os,sys; sys.path.insert(0,'.')
from evalC import *
from classify import nearest, segs
A=np.load(sys.argv[1])
ys,xs=np.where(M_)
acc={}
for y,x in zip(ys,xs):
    s=S[lab[y,x]]
    if y<s['ty']: continue
    c=colour(s).astype(float)
    kg=(G[y,x]*c).sum()/(c*c).sum(); ko=(O[y,x]*c).sum()/(c*c).sum(); ka=(A[y,x]*c).sum()/(c*c).sum()
    if (kg<0.03 and ko<0.03) or (kg>0.97 and ko>0.97): continue
    p=np.array([x+0.5-s['tx'],y+0.5-s['ty']])
    d,k,t,kap,side=nearest(s,p)
    if d<1.0: continue
    a,cc,b=segs(s)[k]; dd=b-a
    if os.environ.get('SEL')=='L' and (abs(dd[0])<1e-9 or abs(dd[1])<1e-9): continue
    if t<0.02 or t>0.98: key=('end',)
    else:
        R=1/max(abs(kap),1e-6)
        key=('concave' if side>0 else 'convex' if side<0 else 'straight', 'R<10' if R<10 else 'R<30' if R<30 else 'R>=30')
    acc.setdefault(key,[]).append((ka-ko,kg-ko,kg-ka))
for k in sorted(acc): v=np.array(acc[k]); print(k,len(v),'A-O %+.3f  G-O %+.3f  G-A %+.3f'%tuple(v.mean(0)))
