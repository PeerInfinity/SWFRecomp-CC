import flashblur
from glowfit import *
flashblur.QUANT='floor'
tot=0
for i,(bx,by,q,dx,dy) in cells.items():
    kx=kernel(bx);ky=kernel(by); ex=q*(kx[0]+1); ey=q*(ky[0]+1)
    s=score(composite(place(fblur(SRC,bx,by,q,max(ex,ey)),dx-ex,dy-ey),i),i)[0]; print(i,'blur',s); tot+=s
for i,(k,dx,dy,kw) in specs.items():
    o=glowlike(k,P,offmode='bil',**kw)
    bx=kw.get('bx',6); kx=kernel(bx); reach=kx[0]+1
    d=4.0; a=np.deg2rad(45.0); ox=int(np.cos(a)*d)  # trunc
    if k=='glow': g=(reach,reach,reach,reach)
    elif k=='ds': g=(max(0,reach-ox),max(0,reach-ox),reach+ox,reach+ox)  # l,t,r,b
    else: g=(reach+ox,)*4
    sub=o[P-g[1]:P+100+g[3], P-g[0]:P+100+g[2]]
    s=score(composite(place(sub,dx-g[0],dy-g[1]),i),i)[0]; print(i,k,g,s); tot+=s
print('total (cell 7 conv already 0):',tot)
