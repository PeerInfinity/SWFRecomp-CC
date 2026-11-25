from m import *
import sys
def flat(B,x,y,o):
    # support of a sample near offset o (+-1 texel window) is constant
    x0=x+math.floor(o[0])-1; y0=y+math.floor(o[1])-1
    vals={Bget(B,x0+a,y0+b) for a in range(4) for b in range(4)}
    return len(vals)==1, (vals.pop() if len(vals)==1 else None)
def sidefit(lab, rng=10):
    s=lab[-1]; B=[[p>>24 for p in r] for r in grid(F,'blur3 '+s)]
    fg=grid(F,lab); H=len(fg); W=len(fg[0])
    dist=float(lab.split()[1][1:]); ang=int(lab.split()[2][1:])
    n=(math.cos(math.radians(ang))*dist, math.sin(math.radians(ang))*dist)
    out=[]
    for side in (1,-1):
        o=(side*n[0],side*n[1]); other=(-o[0],-o[1])
        px=[]
        for y in range(H):
          for x in range(W):
            f,v=flat(B,x,y,other)
            if not f: continue
            fv,_=flat(B,x,y,o)
            if fv: continue
            px.append((x,y,side*dval(fg[y][x])+v if side==1 else v-dval(fg[y][x])))
        # side==1: d = SL - v  -> SL = d+v ; side==-1: d = v - SR -> SR = v - d
        res=[]
        for i in range(-rng,rng+1):
          for j in range(-rng,rng+1):
            ox=round(o[0]*256)/256+i/256; oy=round(o[1]*256)/256+j/256
            e=sum(1 for (x,y,t) in px if samp(B,x,y,ox,oy,0,'')!=t)
            res.append((e,i,j))
        res.sort()
        out.append((side,len(px),res[:4]))
    print(lab,'nom*256',[round(v*256,2) for v in n],out,flush=True)
labs=sys.argv[1:] or ['bevel d%s a%d %s'%(d,a,s) for s in 'KR' for d in ('2','1.5','3') for a in (200,45,135)]
for l in labs: sidefit(l)
