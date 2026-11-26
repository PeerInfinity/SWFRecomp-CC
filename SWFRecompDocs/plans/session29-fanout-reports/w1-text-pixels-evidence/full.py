exec(open('edgefit.py').read()); exec(open('glyph.py').read())
M['rot90']=(0,1,-1,0,1400,200)
def border_polys(fname,q=0.25):
    P=corners(*M[fname],snap=False)
    if q: P=[(round(x/q)*q,round(y/q)*q) for x,y in P]
    polys=[]
    for i in range(4):
        a,b=P[i],P[(i+1)%4]; dx,dy=b[0]-a[0],b[1]-a[1]
        if abs(dx)<1e-6 or abs(dy)<1e-6:
            # axis-aligned hairline: the pixel row/col right/below the line, ends extended to cover the corner pixel
            x0,x1=sorted((a[0],b[0])); y0,y1=sorted((a[1],b[1]))
            if abs(dy)<1e-6: polys.append([(x0,y0),(x1+1,y0),(x1+1,y0+1),(x0,y0+1)])
            else: polys.append([(x0,y0),(x0+1,y0),(x0+1,y1+1),(x0,y1+1)])
        else:
            t=min(abs(dx),abs(dy))/max(abs(dx),abs(dy))
            polys.append(seg_poly(a,b,1+t/2 if t<.999 else 1.0))
    return polys
def model_image(phy=0.0,q=0.25):
    n=np.zeros((200,200),int)
    for f in ['rot90','rot30','shear']:
        n=np.maximum(n,raster(border_polys(f,q),phy=phy))
        n=np.maximum(n,raster(glyph_polys(f,q),phy=phy))
    return np.clip(255-16*n,0,255)
