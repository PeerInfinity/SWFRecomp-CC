exec(open('scan.py').read())
import math
lab=np.load('lab.npy',allow_pickle=True)
r=math.radians(30)
def corners(a,b,c,d,tx,ty,w=70,h=55,snap=True,tsnap=True):
    A,B,C,D=a*w,b*w,c*h,d*h
    TX=tx/20; TY=ty/20
    if tsnap: TX=math.trunc(TX+0.1); TY=math.trunc(TY+0.1)
    if snap:
        if abs(C)<.001 or abs(D)<.001: A=round(A-.35); B=round(B-.35)
        if abs(A)<.001 or abs(B)<.001: C=round(C-.35); D=round(D-.35)
    return [(TX,TY),(TX+A,TY+B),(TX+A+C,TY+B+D),(TX+C,TY+D)]
M={'rot30':(math.cos(r),math.sin(r),-math.sin(r),math.cos(r),2200,600),'shear':(1,0,0.5,1,200,2600)}
def field_polys(P,kf,ox,oy):
    polys=[]
    for i in range(4):
        a,b=P[i],P[(i+1)%4]
        dx,dy=b[0]-a[0],b[1]-a[1]
        if abs(dx)<1e-6 or abs(dy)<1e-6:
            # axis aligned: Ruffle model, 1px on the row/col below/right of line
            polys.append(seg_poly(a,b,1.0,0.5,0.5))
        else:
            t=min(abs(dx),abs(dy))/max(abs(dx),abs(dy))
            polys.append(seg_poly(a,b,kf(t),ox,oy))
    return polys
