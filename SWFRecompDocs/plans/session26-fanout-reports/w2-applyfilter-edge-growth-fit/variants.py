from model import *
import itertools
def pass1d_v(a,k,norm,rnd,qalpha):
    m,a255,fs=k
    n=a.shape[0]
    radius=(fs-1)/2
    alpha=a255/255.0 if qalpha else (radius-m)
    wsum=2*m+1+2*alpha
    div=fs if norm=='fs' else wsum
    pad=np.concatenate([np.zeros((m+1,)+a.shape[1:]),a,np.zeros((m+1,)+a.shape[1:])])
    out=np.zeros_like(a,dtype=float)
    for i in range(n):
        j=i+m+1
        s=pad[j-m:j+m+1].sum(0)+alpha*(pad[j-m-1]+pad[j+m+1])
        out[i]=s/div
    if rnd=='floor': out=np.floor(out+1e-9)
    elif rnd=='round': out=np.floor(out+0.5)
    return np.clip(out,0,255)
def blurv(src,bx,by,q,P,order='xy',**kw):
    pad=np.zeros((src.shape[0]+2*P,src.shape[1]+2*P,4))
    pad[P:P+100,P:P+100]=src
    kx=kernel(bx);ky=kernel(by);c=pad
    for _ in range(q):
        for ax in order:
            if ax=='x' and kx: c=np.moveaxis(pass1d_v(np.moveaxis(c,1,0),kx,**kw),0,1)
            if ax=='y' and ky: c=pass1d_v(c,ky,**kw)
    return c.astype(np.int64)
def place(img,dx,dy):
    d=np.zeros((100,100,4),np.int64)
    H,W=img.shape[:2]
    ys=slice(max(0,dy),min(100,dy+H)); xs=slice(max(0,dx),min(100,dx+W))
    d[ys,xs]=img[ys.start-dy:ys.stop-dy, xs.start-dx:xs.stop-dx]
    return d
cells={1:(4,4,1,5,5),2:(4,4,1,-10,-10),3:(8,8,2,-20,-5),8:(4,4,1,-50,-50),9:(4,4,1,-5,10),10:(4,4,1,10,-5),11:(4,4,1,-99,-99)}
if __name__=='__main__':
  for norm,rnd,qa,order in itertools.product(['fs','wsum'],['floor','round'],[True,False],['xy','yx']):
    tot=0;r=[]
    for i,(bx,by,q,dx,dy) in cells.items():
        P=10
        s=score(composite(place(blurv(SRC,bx,by,q,P,order,norm=norm,rnd=rnd,qalpha=qa),dx-P,dy-P),i),i)[0]
        r.append(s);tot+=s
    print(norm,rnd,qa,order,tot,r)
