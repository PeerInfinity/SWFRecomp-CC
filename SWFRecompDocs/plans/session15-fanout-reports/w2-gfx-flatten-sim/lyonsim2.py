import math
from lyonsim import lyon_count, approx_parabola_integral, approx_parabola_inv_integral, ours_count, arc_quad

def lyon_params(frm,ctrl,to,tolerance):
    (x0,y0),(cx,cy),(x1,y1)=frm,ctrl,to
    ddx=2*cx-x0-x1; ddy=2*cy-y0-y1
    crs=(x1-x0)*ddy-(y1-y0)*ddx
    inv=1.0/crs
    pf=((cx-x0)*ddx+(cy-y0)*ddy)*inv
    pt=((x1-cx)*ddx+(y1-cy)*ddy)*inv
    scale=abs(crs)/(math.sqrt(ddx*ddx+ddy*ddy)*abs(pt-pf))
    i_f=approx_parabola_integral(pf); i_t=approx_parabola_integral(pt)
    idiff=i_t-i_f
    inv_f=approx_parabola_inv_integral(i_f); inv_t=approx_parabola_inv_integral(i_t)
    div=1.0/(inv_t-inv_f)
    cnt=math.ceil(0.5*abs(idiff)*math.sqrt(scale/tolerance))
    step=idiff/cnt
    return cnt,i_f,step,inv_f,div

def lyon_ts(frm,ctrl,to,tol):
    cnt,i_f,step,inv_f,div=lyon_params(frm,ctrl,to,tol)
    ts=[]
    for i in range(1,cnt):
        u=approx_parabola_inv_integral(i_f+step*i)
        ts.append((u-inv_f)*div)
    ts.append(1.0)
    return ts

def sample(frm,ctrl,to,t):
    u=1-t
    return (u*u*frm[0]+2*u*t*ctrl[0]+t*t*to[0], u*u*frm[1]+2*u*t*ctrl[1]+t*t*to[1])

def max_radial_err(R, ts, frm, ctrl, to):
    """max inward radial error (px) of the inscribed polygon vs the true arc"""
    pts=[frm]+[sample(frm,ctrl,to,t) for t in ts]
    worst=0.0
    for a,b in zip(pts[:-1],pts[1:]):
        # sample the chord densely, measure R - |p|
        for k in range(1,40):
            s=k/40.0
            p=(a[0]+(b[0]-a[0])*s, a[1]+(b[1]-a[1])*s)
            worst=max(worst, R-math.hypot(p[0],p[1]))
    return worst

print("%7s %5s | %-22s | %-22s | %-22s | %-22s"%("R_px","arc","lyon(tol .1)","base f6 tol1tw","legA f1 tol1tw","legB f6 tol2tw / AB f1 tol2tw"))
print("%7s %5s | %5s %8s | %5s %8s | %5s %8s | %5s %8s"%("","","n","err_px","n","err_px","n","err_px","n","err_px"))
for R in [5,10,20,39.5,80,160]:
    for arcdeg in [90,45,30]:
        f,c,t=arc_quad(R,arcdeg/2.0)
        lts=lyon_ts(f,c,t,0.1)
        le=max_radial_err(R,lts,f,c,t); ln=len(lts)
        fT=(f[0]*20,f[1]*20); cT=(c[0]*20,c[1]*20); tT=(t[0]*20,t[1]*20)
        res=[]
        for tol,fl in [(1.0,6),(1.0,1),(2.0,1)]:
            n=ours_count(fT,cT,tT,tol,fl)
            ts=[i/float(n) for i in range(1,n+1)]
            res.append((n,max_radial_err(R,ts,f,c,t)))
        print("%7s %5s | %5d %8.4f | %5d %8.4f | %5d %8.4f | %5d %8.4f"%(
            R,arcdeg,ln,le,res[0][0],res[0][1],res[1][0],res[1][1],res[2][0],res[2][1]))

print()
print("Levien-vs-uniform vertex displacement at EQUAL count (px):")
for R in [20,39.5,80]:
    for arcdeg in [90,45]:
        f,c,t=arc_quad(R,arcdeg/2.0)
        lts=lyon_ts(f,c,t,0.1); n=len(lts)
        uts=[i/float(n) for i in range(1,n+1)]
        d=max(math.dist(sample(f,c,t,a),sample(f,c,t,b)) for a,b in zip(lts,uts))
        print("  R=%-6s arc=%-4s n=%-3d max vertex move %.4f px"%(R,arcdeg,n,d))
