import sys, numpy as np, itertools
from PIL import Image
import swfparse, strokemodel as sm
T='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/visual/'+sys.argv[1]
s=swfparse.parse(T+'/test.swf'); sm.FH=s['rect'][3]-s['rect'][2]
a=np.asarray(Image.open(T+'/output.actual.png').convert('RGB')).astype(int)
e=np.asarray(Image.open(T+'/output.expected.png').convert('RGB')).astype(int)
col=np.array([255,255,153])
X0,Y0,X1,Y1=map(int,sys.argv[2].split(','))
def mask(img):
    m=(img==col).all(2); z=np.zeros_like(m); z[Y0:Y1,X0:X1]=m[Y0:Y1,X0:X1]; return z
ma,me=mask(a),mask(e)
print('stroke px actual',ma.sum(),'expected',me.sum(),'xor',(ma^me).sum())
H,W=ma.shape
paths=[p for p in s['shapes'][1] if p['line']]
def tris(mode, **kw):
    out=[]
    for p in paths:
        pts=sm.flatten_path(p['segs'],mode)
        closed = pts[0]==pts[-1]
        out+=sm.stroke_tris(pts,10.0,mode,closed,**kw)
    return out
tx,ty=float(sys.argv[3]),float(sys.argv[4])
for mode in ['ours','ruffle']:
    tr=tris(mode)
    best=[]
    for dx in np.arange(-1,1.0001,0.05):
        for dy in np.arange(-1,1.0001,0.05):
            m=sm.raster(tr,W,H,tx+dx,ty+dy)
            m2=np.zeros_like(m); m2[Y0:Y1,X0:X1]=m[Y0:Y1,X0:X1]
            best.append(((m2^ma).sum(),(m2^me).sum(),round(dx,2),round(dy,2)))
    print(mode,'best vs actual',sorted(best)[:3])
    print(mode,'best vs expected',sorted(best,key=lambda b:b[1])[:3])
