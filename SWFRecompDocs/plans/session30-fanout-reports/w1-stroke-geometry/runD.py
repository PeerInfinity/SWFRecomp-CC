import sys; sys.path.insert(0,'/tmp/claude-0/sp')
from model2 import *
d=float(sys.argv[1])
import os
SEL=os.environ.get('SEL','Q')
S=[s for s in load() if ('fill' not in s) and s['tx'] is not None and ((SEL=='Q' and [c[0] for c in s['cmds']]==['M','Q','Q']) or (SEL=='L' and [c[0] for c in s['cmds']]==['M','L','L','L','L']))]
out,owner=evaluate(lambda s: LineString(centreline(s)).buffer(s['w']/2+d, quad_segs=64),S)
np.save(f'/tmp/claude-0/sp/model{SEL}D{sys.argv[1]}.npy',out)
