import sys,re,numpy as np
from PIL import Image
xml=open(sys.argv[1]).read()
fl=np.asarray(Image.open(sys.argv[2]).convert('RGB')).astype(float)
ou=np.asarray(Image.open(sys.argv[3]).convert('RGB')).astype(float)
blk=re.search(r'(<LinearGradient spreadMode="1".*?</LinearGradient>)',xml,re.S).group(1)
kv=dict(re.findall(r'(\w+)="([^"]*)"',re.search(r'<Transform ([^/]*)/>',blk).group(1)))
a=float(kv.get('scaleX',1));d=float(kv.get('scaleY',1));c=float(kv.get('skewY',0));b=float(kv.get('skewX',0))
tx=float(kv['transX'])/20;ty=float(kv['transY'])/20
H,W=fl.shape[:2]; ys,xs=np.mgrid[0:H,0:W].astype(float)
det=a*d-b*c
def tval(ox,oy):
    dx=(xs+ox-tx)*20;dy=(ys+oy-ty)*20
    gx=(d*dx-c*dy)/det
    return (gx+16384)/32768
def refl(t):
    t=np.mod(t,2.0); return np.where(t>1,2-t,t)
c0=np.array([255,0,0.]);c1=np.array([0,255,255.])
def img(ox,oy,mode):
    t=tval(ox,oy)
    if mode=='refl_then_floor': u=np.clip(np.floor(refl(t)*256-0.002),0,255)
    elif mode=='floor_then_refl':  # index in 512-period
        k=np.floor(t*256-0.002); k=np.mod(k,512); u=np.where(k>255,511-k,k)
    elif mode=='lerp': u=refl(t)*255
    f=u/255
    return np.round(c0+(c1-c0)*f[...,None])
roi=np.zeros((H,W),bool); roi[45:290,65:480]=True
roi&=(np.abs(fl[...,0]+fl[...,1]-255)<=3)&(np.abs(fl[...,1]-fl[...,2])<=1)
print('roi px',roi.sum())
for mode in ['refl_then_floor','floor_then_refl','lerp']:
  best=[]
  for oy in np.arange(-2,2.01,0.125):
    for ox in np.arange(-2,2.01,0.125):
        P=img(ox,oy,mode); e=(np.abs(P-fl)>0).any(axis=2)[roi].sum(); best.append((e,ox,oy))
  best.sort(); print(mode,'flash best',best[:3])
  best=[]
  for oy in np.arange(-2,2.01,0.125):
    for ox in np.arange(-2,2.01,0.125):
        P=img(ox,oy,mode); e=(np.abs(P-ou)>0).any(axis=2)[roi].sum(); best.append((e,ox,oy))
  best.sort(); print(mode,'ours best',best[:3])
