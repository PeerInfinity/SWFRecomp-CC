import numpy as np, itertools
from PIL import Image
e=np.asarray(Image.open('avm2/graphics_gradients/output.expected.png').convert('RGB')).astype(int)
gold=e[10,5:20]
stops=[(0,(255,0,0),0.5),(255,(0,0,255),1.0)]
def ramp(premul, a0mode, rnd):
    a0 = {'trunc':127,'round':128,'f':127.5}[a0mode]
    out=[]
    for i in range(256):
        f=i/255
        a=a0+(255-a0)*f
        r=255*(1-f); b=255*f
        if premul:
            pr=(255*a0/255)*(1-f)  # red premult
            pb=255*f
            out.append((a, pr, 0, pb))
        else:
            out.append((a, r*a/255, 0, b*a/255))
    return out
def render(ox, premul, a0mode, idxmode):
    R=ramp(premul,a0mode,None); res=[]
    for x in range(5,20):
        t=(x+ox)/20
        i={'floor255':int(np.floor(t*255)),'round255':int(round(t*255)),'floor256':min(255,int(t*256))}[idxmode]
        a,pr,pg,pb=R[i]
        res.append([255-a+pr, 255-a+pg, 255-a+pb])
    return np.array(res)
best=[]
for ox,pm,a0,im in itertools.product([0,0.25,0.5],[0,1],['trunc','round','f'],['floor255','round255','floor256']):
    d=np.abs(render(ox,pm,a0,im)-gold)
    best.append((d.max(),d.sum(),ox,pm,a0,im))
best.sort()
for b in best[:8]: print(b)
