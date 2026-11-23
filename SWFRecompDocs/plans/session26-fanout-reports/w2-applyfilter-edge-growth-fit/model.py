import numpy as np
from PIL import Image
T='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/avm2/bitmapdata_applyfilter_destpoint_edges/'
def load(n): return np.asarray(Image.open(T+n).convert('RGB')).astype(np.int64)
E=load('output.expected.png'); A=load('output.actual.png'); RU=load('output.ruffle.png')
def cell(img,i): return img[(i//6)*100:(i//6)*100+100,(i%6)*100:(i%6)*100+100]
def make_src():
    s=np.zeros((100,100,4),np.int64) # premul A,R,G,B
    def fill(x,y,w,h,a,r,g,b):
        pm=lambda c:(c*a+127)//255
        s[y:y+h,x:x+w]=[a,pm(r),pm(g),pm(b)]
    for row in range(10):
        for col in range(10):
            rd=(row+1)/10; cd=(col+1)/10
            fill(col*10,row*10,10,10,int(0.8*255)&255,int((1-rd)*255)&255,int(rd*255)&255,int(cd*255)&255)
    fill(48,5,4,90,255,0,0,0); fill(5,48,90,4,255,0,0,0)
    return s
SRC=make_src()
def bg(i):
    b=np.zeros((100,100,3),np.int64)
    ox=(i%6)*100; oy=(i//6)*100
    for y in range(100):
        for x in range(100):
            X=ox+x;Y=oy+y
            cx=X//9; cy=Y//9
            b[y,x]=0xBB if (cx+cy)%2==0 else 0xEE
    return b
BG=[bg(i) for i in range(14)]
def composite(dst,i):
    # dst premul A,R,G,B 100x100
    a=dst[...,0:1]
    return dst[...,1:4]+ (BG[i]*(255-a)+127)//255
def score(model_rgb,i,ref=E,tol=1):
    d=np.abs(model_rgb-cell(ref,i)); return int((d>tol).sum()), int((d>tol).any(2).sum())
def kernel(size):
    fs=np.float32(min(size,255.0))
    if not fs>1: return None
    radius=(fs-np.float32(1))*np.float32(0.5)
    mf=np.ceil(radius)-np.float32(1)
    return int(mf), int(np.floor((radius-mf)*np.float32(255))), float(fs)
