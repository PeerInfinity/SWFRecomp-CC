import sys; sys.path.insert(0,'/tmp/claude-0/sp')
from modelB import *
k=int(sys.argv[1])
S=[s for s in load() if len(s['cmds'])==3 and any(c[0]=='Q' for c in s['cmds'])]
out,owner=evaluate(lambda s: region_B(s,k),S)
np.save(f'/tmp/claude-0/sp/modelB{k}.npy',out)
