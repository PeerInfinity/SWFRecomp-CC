import math

def approx_parabola_integral(x):
    d=0.67
    return x/(1.0-d+math.sqrt(math.sqrt(d**4+0.25*x*x)))

def approx_parabola_inv_integral(x):
    b=0.39
    return x*(1.0-b+math.sqrt(b*b+0.25*x*x))

def lyon_count(frm,ctrl,to,tolerance):
    (x0,y0),(cx,cy),(x1,y1)=frm,ctrl,to
    if frm==to: return 0
    dx,dy=x1-x0,y1-y0
    L2=dx*dx+dy*dy
    cross=(cx-x0)*dy-(cy-y0)*dx
    d2=cross*cross/L2 if L2>0 else 0.0
    if d2 <= tolerance*tolerance*4: return 0
    ddx=2*cx-x0-x1; ddy=2*cy-y0-y1
    crs=(x1-x0)*ddy-(y1-y0)*ddx
    if crs==0: return 0
    inv=1.0/crs
    pf=((cx-x0)*ddx+(cy-y0)*ddy)*inv
    pt=((x1-cx)*ddx+(y1-cy)*ddy)*inv
    scale=abs(crs)/(math.sqrt(ddx*ddx+ddy*ddy)*abs(pt-pf))
    i_f=approx_parabola_integral(pf); i_t=approx_parabola_integral(pt)
    idiff=i_t-i_f
    cnt=math.ceil(0.5*abs(idiff)*math.sqrt(scale/tolerance))
    return cnt

def ours_count(frm,ctrl,to,tol_twips,floor):
    (x0,y0),(cx,cy),(x1,y1)=frm,ctrl,to
    dvx=cx-0.5*(x0+x1); dvy=cy-0.5*(y0+y1)
    dev=0.5*math.hypot(dvx,dvy)
    n=float(floor)
    if dev>tol_twips:
        v=math.ceil(math.sqrt(dev/tol_twips))
        v=min(v,64.0)
        n=max(n,v)
    return int(n)

def arc_quad(R,half_deg):
    th=math.radians(half_deg)
    f=(R*math.cos(-th),R*math.sin(-th))
    t=(R*math.cos(th),R*math.sin(th))
    c=(R/math.cos(th),0.0)
    return f,c,t

hdr=("R_px","arc","dev_px","lyon","o(1tw,f6)","o(1tw,f1)","o(2tw,f1)","o(2tw,f6)")
print("%7s %6s %8s %5s %10s %10s %10s %10s"%hdr)
for R in [5,10,20,39.5,80,160,400]:
    for arcdeg in [90,45,30]:
        f,c,t=arc_quad(R,arcdeg/2.0)
        dv=abs(c[0]-0.5*(f[0]+t[0]))/2
        lc=lyon_count(f,c,t,0.1)
        fT=(f[0]*20,f[1]*20); cT=(c[0]*20,c[1]*20); tT=(t[0]*20,t[1]*20)
        o1=ours_count(fT,cT,tT,1.0,6)
        o2=ours_count(fT,cT,tT,1.0,1)
        o3=ours_count(fT,cT,tT,2.0,1)
        o4=ours_count(fT,cT,tT,2.0,6)
        print("%7s %6s %8.3f %5d %10d %10d %10d %10d"%(R,arcdeg,dv,lc,o1,o2,o3,o4))
