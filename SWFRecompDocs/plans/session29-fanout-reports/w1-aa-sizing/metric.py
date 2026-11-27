import sys,os,glob
import numpy as np
from PIL import Image
S='/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad'
R='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/'
legs=sys.argv[2:]
for t in open(sys.argv[1]).read().split():
    slug=t.replace('/','_')
    for p in sorted(glob.glob(f'{S}/png/{legs[0]}/{slug}/*.png')):
        n=os.path.basename(p)[:-4]
        if 'difference' in n: continue
        e=R+t+f'/{n}.expected.png'
        if not os.path.exists(e): continue
        E=np.asarray(Image.open(e).convert('RGBA'),dtype=np.int32)
        out=[]
        for leg in legs:
            q=f'{S}/png/{leg}/{slug}/{n}.png'
            if not os.path.exists(q): out.append('-');continue
            A=np.asarray(Image.open(q).convert('RGBA'),dtype=np.int32)
            if A.shape!=E.shape: out.append('shape');continue
            d=np.abs(A-E)
            out.append(f"{leg}: L1={d.sum()} >0:{(d>0).sum()} >8:{(d>8).sum()} >32:{(d>32).sum()} >128:{(d>128).sum()}")
        print(t,n,' | '.join(out))
