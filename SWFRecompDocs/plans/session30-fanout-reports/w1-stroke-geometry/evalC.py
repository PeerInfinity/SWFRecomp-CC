import sys; sys.path.insert(0,'/tmp/claude-0/sp')
import numpy as np
from model2 import G,O,load,colour
import os
SEL=os.environ.get('SEL','Q')
S=[s for s in load() if ('fill' not in s) and s['tx'] is not None and ((SEL=='Q' and [c[0] for c in s['cmds']]==['M','Q','Q']) or (SEL=='L' and [c[0] for c in s['cmds']]==['M','L','L','L','L']))]
H,W=G.shape[:2]
# label map: shape index by bbox (squiggle bbox +3), ambiguous -> -2
lab=-np.ones((H,W),int)
for i,s in enumerate(S):
    x0=int(s['tx'])-4;y0=int(s['ty'])-4;x1=int(s['tx'])+27;y1=int(s['ty'])+36
    x0=max(x0,0);y0=max(y0,0);x1=min(x1,W);y1=min(y1,H)
    sl=lab[y0:y1,x0:x1]; sl[sl>=0]=-2; sl[sl==-1]=i
def prop(P,c):
    k=(P*c).sum(-1)/(c*c).sum(); return np.abs(P-k[...,None]*c).max(-1)
def mask():
    m=np.zeros((H,W),bool)
    for i,s in enumerate(S):
        c=colour(s).astype(float)
        sel=lab==i
        ok=(prop(G.astype(float),c)<=10)&(prop(O.astype(float),c)<=10)
        m|=sel&ok
    return m
M_=mask()
if __name__=='__main__':
    print('sel',M_.sum())
    dO=np.abs(O-G).max(2)
    for f in sys.argv[1:]:
        out=np.load(f); dM=np.abs(out-G).max(2)
        print(f,' '.join(f't{t}: {(dM[M_]>t).sum()}' for t in (3,16,32,64,128)), ' L1',np.abs(out-G).max(2)[M_].sum())
    print('ours      ',' '.join(f't{t}: {(dO[M_]>t).sum()}' for t in (3,16,32,64,128)),' L1',dO[M_].sum())
