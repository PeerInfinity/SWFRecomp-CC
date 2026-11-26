exec(open('model.py').read())
kf=lambda t:1+t/2 if t<.999 else 1.0
def edge_mask(a,b,H=200,W=200,dist=1.8,trim=3):
    (ax,ay),(bx,by)=a,b; L=math.hypot(bx-ax,by-ay); ux,uy=(bx-ax)/L,(by-ay)/L
    yy,xx=np.mgrid[0:H,0:W]+0.5
    s=(xx-ax)*ux+(yy-ay)*uy; d=-(xx-ax)*uy+(yy-ay)*ux
    return (s>trim)&(s<L-trim)&(np.abs(d)<dist)
