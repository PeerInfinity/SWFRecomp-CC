from load import *
import math,sys
F=load(FL);O=load(OU)
def Bget(B,x,y):
    if 0<=y<len(B) and 0<=x<len(B[0]): return B[y][x]
    return 0
def samp(B,x,y,fx,fy,W,mode):
    # x,y integer base; fx,fy fractional in [0,1) -> weights quantized to 1/W
    x0=math.floor(fx); y0=math.floor(fy)
    tx=fx-x0; ty=fy-y0
    X=x+x0; Y=y+y0
    if W:
        wx=int(tx*W+0.5) if mode=='r' else int(tx*W); wy=int(ty*W+0.5) if mode=='r' else int(ty*W)
        a=Bget(B,X,Y)*(W-wx)+Bget(B,X+1,Y)*wx
        b=Bget(B,X,Y+1)*(W-wx)+Bget(B,X+1,Y+1)*wx
        v=a*(W-wy)+b*wy
        return v//(W*W)
    a=Bget(B,X,Y)*(1-tx)+Bget(B,X+1,Y)*tx
    b=Bget(B,X,Y+1)*(1-tx)+Bget(B,X+1,Y+1)*tx
    return math.floor(a*(1-ty)+b*ty+1e-9)
def run(offq, W, mode, show=False, cases=None):
    tot=0
    res={}
    for s in 'KR':
      B=[[p>>24 for p in r] for r in grid(F,'blur3 '+s)]
      for dist in ('2','1.5','3'):
        for ang in (200,45,0,90,135):
          lab='bevel d%s a%d %s'%(dist,ang,s)
          if cases and lab not in cases: continue
          fg=grid(F,lab)
          ox=math.cos(math.radians(ang))*float(dist); oy=math.sin(math.radians(ang))*float(dist)
          ox,oy=offq(ox),offq(oy)
          n=0
          for y in range(len(fg)):
            for x in range(len(fg[0])):
              bl=samp(B,x,y,ox,oy,W,mode); br=samp(B,x,y,-ox,-oy,W,mode)
              d=bl-br; d=max(-255,min(255,d))
              if d!=dval(fg[y][x]):
                  n+=1
                  if show: print(lab,x,y,'model',d,'flash',dval(fg[y][x]),bl,br)
          res[lab]=n; tot+=n
    return tot,res
