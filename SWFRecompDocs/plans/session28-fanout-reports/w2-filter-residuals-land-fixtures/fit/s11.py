from s10 import *
def feas(lab, rng=6):
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
            px.append((x,y,dval(fg[y][x])+v if side==1 else v-dval(fg[y][x])))
        res=[]
        bx=round(o[0]*256); by=round(o[1]*256)
        for i in range(-rng,rng+1):
          for j in range(-rng,rng+1):
            e=sum(1 for (x,y,t) in px if samp(B,x,y,(bx+i)/256,(by+j)/256,0,'')!=t)
            res.append((e,bx+i,by+j))
        m=min(r[0] for r in res)
        xs=sorted({r[1] for r in res if r[0]==m}); ys=sorted({r[2] for r in res if r[0]==m})
        out.append('side%+d nom(%.2f,%.2f) err%d x%s y%s'%(side,o[0]*256,o[1]*256,m,xs,ys))
    print(lab,' | '.join(out),flush=True)
import sys
labs=sys.argv[1:] or ['bevel d%s a%d %s'%(d,a,s) for s in 'KR' for d in ('2','1.5','3') for a in (200,45,135)]
for l in labs: feas(l)
