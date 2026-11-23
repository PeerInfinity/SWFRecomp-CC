from variants import *
def fblur(src,bx,by,q,P):
    """src premul (H,W,4) ints; returns grown by P each side, Flash model"""
    H,W=src.shape[:2]
    c=np.zeros((H+2*P,W+2*P,4)); c[P:P+H,P:P+W]=src
    kx=kernel(bx);ky=kernel(by)
    if kx:
        for _ in range(q): c=np.moveaxis(pass1d_v(np.moveaxis(c,1,0),kx,'fs','floor',False),0,1)
    if ky:
        for _ in range(q): c=pass1d_v(c,ky,'fs','floor',False)
    return c.astype(np.int64)
f32=np.float32
QUANT=None
def sat(v): return np.clip(v,f32(0),f32(1))
def store(c): return np.floor(sat(c)*f32(255)+f32(0.5)).astype(np.int64)
def glowlike(kind,P,bx=6,by=6,q=1,strength=2.0,color=(255,0,0),alpha=1.0,dist=4.0,ang=45.0,
             inner=False,knockout=False,hide=False,color2=(255,255,255),alpha2=1.0,btype=1,offmode='floor'):
    B=fblur(SRC,bx,by,q,P)[...,0].astype(f32)/f32(255)
    H,W=B.shape
    D=np.zeros((H,W,4),f32); D[P:P+100,P:P+100]=SRC.astype(f32)/f32(255)  # A,R,G,B
    a_=f32(np.deg2rad(ang))
    offx=offy=f32(0)
    if kind=='ds': offx=-(np.cos(a_)*f32(dist)); offy=-(np.sin(a_)*f32(dist))
    if kind=='bevel': offx=np.cos(a_)*f32(dist); offy=np.sin(a_)*f32(dist)
    ys,xs=np.mgrid[0:H,0:W]
    def samp(ox,oy):
        if offmode.startswith('bil'):
            px=xs+float(ox); py=ys+float(oy)
            x0=np.floor(px).astype(int); y0=np.floor(py).astype(int); tx=px-x0; ty=py-y0
            if offmode=='bil8': tx=np.floor(tx*256)/256; ty=np.floor(ty*256)/256
            def g(yy,xx):
                ok=(xx>=0)&(xx<W)&(yy>=0)&(yy<H); o=np.zeros((H,W)); o[ok]=B[yy[ok],xx[ok]]; return o
            v=(g(y0,x0)*(1-tx)+g(y0,x0+1)*tx)*(1-ty)+(g(y0+1,x0)*(1-tx)+g(y0+1,x0+1)*tx)*ty
            if QUANT=='round': v=np.floor(v*255+0.5)/255
            elif QUANT=='floor': v=np.floor(v*255+1e-6)/255
            return v.astype(f32)
        if offmode=='floor':
            sx=np.floor(xs+f32(0.5)+ox).astype(int); sy=np.floor(ys+f32(0.5)+oy).astype(int)
        else:
            sx=xs+int(np.round(ox)); sy=ys+int(np.round(oy))
        ok=(sx>=0)&(sx<W)&(sy>=0)&(sy<H)
        out=np.zeros((H,W),f32); out[ok]=B[sy[ok],sx[ok]]; return out
    da=D[...,0]; dc=[D[...,1],D[...,2],D[...,3],D[...,0]]  # r,g,b,a
    st=f32(strength)
    gc=[f32(color[0]/255),f32(color[1]/255),f32(color[2]/255),f32(alpha)]
    if kind=='bevel':
        bl=samp(offx,offy); br=samp(-offx,-offy)
        ha=sat((bl-br)*st); sa=sat((br-bl)*st)
        hi=[f32(color2[0]/255)*f32(alpha2),f32(color2[1]/255)*f32(alpha2),f32(color2[2]/255)*f32(alpha2),f32(alpha2)]
        sh=[gc[0]*gc[3],gc[1]*gc[3],gc[2]*gc[3],gc[3]]
        g=[hi[i]*ha+sh[i]*sa for i in range(4)]
        outer=btype in (0,2); inn=btype in (1,2)
        c=[]
        for i in range(4):
            if inn and outer: c.append(g[i] if knockout else dc[i]-dc[i]*g[3]+g[i])
            elif inn: c.append(g[i]*da if knockout else g[i]*da+dc[i]*(f32(1)-g[3]))
            else: c.append(g[i]-g[i]*da if knockout else dc[i]+g[i]-g[i]*da)
    else:
        blur=samp(offx,offy); col=[gc[0],gc[1],gc[2],f32(1)]
        composite=not hide if kind=='ds' else True
        c=[]
        if inner:
            a=gc[3]*sat((f32(1)-blur)*st)
            for i in range(4): c.append(col[i]*a*da+dc[i]*(f32(1)-a) if (not knockout and composite) else col[i]*a*da)
        else:
            a=gc[3]*sat(blur*st)
            for i in range(4):
                if knockout: c.append(col[i]*a*(f32(1)-da))
                elif composite: c.append(col[i]*a*(f32(1)-da)+dc[i])
                else: c.append(col[i]*a)
    out=np.stack([store(c[3]),store(c[0]),store(c[1]),store(c[2])],-1)
    return out
