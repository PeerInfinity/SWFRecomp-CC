from m import *
def runq(qf, show=None):
    tot=0;res={}
    for s in 'KR':
      B=[[p>>24 for p in r] for r in grid(F,'blur3 '+s)]
      for dist in ('2','1.5','3'):
        for ang in (200,45,0,90,135):
          lab='bevel d%s a%d %s'%(dist,ang,s); fg=grid(F,lab)
          ox=math.cos(math.radians(ang))*float(dist); oy=math.sin(math.radians(ang))*float(dist)
          ox=qf(ox); oy=qf(oy)
          n=0
          for y in range(len(fg)):
            for x in range(len(fg[0])):
              d=samp(B,x,y,ox,oy,0,'')-samp(B,x,y,-ox,-oy,0,'')
              if d!=dval(fg[y][x]):
                n+=1
                if show==lab: print(lab,x,y,d,dval(fg[y][x]))
          res[lab]=n; tot+=n
    return tot,res
def nonint(v):
    r=round(v*256)
    return (r+ (1 if abs(v*256-r)>1e-6 else 0))/256
def nonzero(v):
    r=round(v*256)
    return (r+(1 if r!=0 else 0))/256
for nm,q in (('nonint',nonint),('nonzero',nonzero)):
    t,r=runq(q); print(nm,t); print({k:v for k,v in r.items() if v})
