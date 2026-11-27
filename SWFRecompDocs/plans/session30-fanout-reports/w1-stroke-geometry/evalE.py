import sys; sys.path.insert(0,'/tmp/claude-0/sp')
from evalC import *
# exclude occluded rows rel y<0
ok=M_.copy()
for i,s in enumerate(S):
    y0=int(s['ty']); sel=(lab==i); sel[y0:,:]=False; ok&=~sel
dO=np.abs(O-G).max(2)
for f in sys.argv[1:]:
    out=np.load(f); dM=np.abs(out-G).max(2); dMO=np.abs(out-O).max(2)
    print(f,'vsG',' '.join(f't{t}:{(dM[ok]>t).sum()}' for t in (16,32,64,128)),'L1',dM[ok].sum(),'| vsOurs L1',dMO[ok].sum())
print('ours vsG',' '.join(f't{t}:{(dO[ok]>t).sum()}' for t in (16,32,64,128)),'L1',dO[ok].sum())
