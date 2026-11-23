from model import *
def pass1d(arr,axis,k,mode='clamp'):
    m,a255,fs=k
    n=arr.shape[axis]
    a=np.moveaxis(arr,axis,0)
    idx=lambda j: np.clip(j,0,n-1)
    out=np.zeros_like(a)
    for i in range(n):
        s=sum(a[idx(i+t)] for t in range(-m,m+1))
        fr=a[idx(i-m-1)]+a[idx(i+m+1)]
        out[i]=np.clip(np.floor((255*s+a255*fr)/(255.0*fs)),0,255)
    return np.moveaxis(out,0,axis)
def ruffle_blur(src,bx,by,q):
    kx=kernel(bx);ky=kernel(by);c=src
    for _ in range(q):
        if kx: c=pass1d(c,1,kx)
        if ky: c=pass1d(c,0,ky)
    return c
def place(img,dx,dy):
    d=np.zeros((100,100,4),np.int64)
    H,W=img.shape[:2]
    for y in range(H):
        ty=y+dy
        if 0<=ty<100:
            for x in range(W):
                tx=x+dx
                if 0<=tx<100: d[ty,tx]=img[y,x]
    return d
cells={1:(4,4,1,5,5),2:(4,4,1,-10,-10),3:(8,8,2,-20,-5),8:(4,4,1,-50,-50),9:(4,4,1,-5,10),10:(4,4,1,10,-5),11:(4,4,1,-99,-99)}
print('cell0 ours',score(composite(SRC,0),0,A),'flash',score(composite(SRC,0),0))
for i,(bx,by,q,dx,dy) in cells.items():
    d=place(ruffle_blur(SRC,bx,by,q),dx,dy)
    c=composite(d,i)
    print(i,'model vs actual',score(c,i,A,0),'model vs flash',score(c,i))
