from s7 import runq
import math
for c in (0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5):
    t,r=runq(lambda v,c=c: math.floor(v*256+c+1e-9)/256 if abs(v)>1e-9 else 0.0)
    print(c,t,{k:v for k,v in r.items() if v},flush=True)
