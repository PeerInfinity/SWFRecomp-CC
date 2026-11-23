import numpy as np
from PIL import Image
from flashblur import pass1d_v, kernel
T='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/avm2/bitmapdata_filter_sourcerect/'
E=np.asarray(Image.open(T+'output.expected.png').convert('RGB')).astype(int)
A=np.asarray(Image.open(T+'output.actual.png').convert('RGB')).astype(int)
print('stage bg',E[5,5], E[240,5])
src=np.zeros((200,200,4)); src[...]=[255,255,0,0]; src[50:100,50:100]=[255,0,0,0]
def blur(buf):
    k=kernel(4.0)
    c=np.moveaxis(pass1d_v(np.moveaxis(buf,1,0),k,'fs','floor',False),0,1)
    return pass1d_v(c,k,'fs','floor',False)
def variant(v,grow=True,P=2):
    sx,sy,w,h=70,50,100,100
    buf=np.zeros((h+2*P,w+2*P,4))
    for y in range(-P,h+P):
        for x in range(-P,w+P):
            X,Y=sx+x,sy+y
            inside_rect= 0<=x<w and 0<=y<h
            inside_bmp= X<200 and Y<200 and X>=0 and Y>=0
            if inside_rect or (v=='B' and inside_bmp): buf[y+P,x+P]=src[Y,X]
    out=blur(buf)
    if not grow: out=out[P:P+h,P:P+w]; g=0
    else: g=P
    dst=np.zeros((200,200,4)); dst[...]=[255,0,255,0]
    for y in range(out.shape[0]):
        for x in range(out.shape[1]):
            X,Y=10-g+x,30-g+y
            if 0<=X<200 and 0<=Y<200: dst[Y,X]=out[y,x]
    a=dst[...,0:1]; return (dst[...,1:4]+255*(255-a)/255).round().astype(int)
for v in ['A','B']:
    for grow in [True,False]:
        c=variant(v,grow); e=E[20:220,20:220]
        d=np.abs(c-e); print(v,grow,'>5:',int((d>5).sum()),'>1:',int((d>1).sum()))
d=np.abs(A[20:220,20:220]-E[20:220,20:220]); print('actual >5', int((d>5).sum()))
