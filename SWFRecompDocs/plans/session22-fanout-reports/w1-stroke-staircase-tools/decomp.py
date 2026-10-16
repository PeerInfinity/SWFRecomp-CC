import sys, numpy as np
from PIL import Image
import swfparse, strokemodel as sm
T='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/visual/'+sys.argv[1]
s=swfparse.parse(T+'/test.swf'); sm.FH=s['rect'][3]-s['rect'][2]
a=np.asarray(Image.open(T+'/output.actual.png').convert('RGB')).astype(int)
e=np.asarray(Image.open(T+'/output.expected.png').convert('RGB')).astype(int)
col=np.array([255,255,153]); X0,Y0,X1,Y1=map(int,sys.argv[2].split(','))
def mask(img):
    m=(img==col).all(2); z=np.zeros_like(m); z[Y0:Y1,X0:X1]=m[Y0:Y1,X0:X1]; return z
ma,me=mask(a),mask(e); H,W=ma.shape
paths=[p for p in s['shapes'][1] if p['line']]
ox,oy=float(sys.argv[3]),float(sys.argv[4])
for fl in ['ours','ruffle']:
  for rnd in [True,False]:
    tr=[]
    for p in paths:
        pts=sm.flatten_path(p['segs'],fl)
        tr+=sm.stroke_tris(pts,10.0,'ours' if rnd else 'ruffle',pts[0]==pts[-1],rnd=rnd)
    m=sm.raster(tr,W,H,ox,oy); m2=np.zeros_like(m); m2[Y0:Y1,X0:X1]=m[Y0:Y1,X0:X1]
    print('flatten=%-6s offset_round=%-5s  xor_vs_actual=%3d xor_vs_expected=%3d'%(fl,rnd,(m2^ma).sum(),(m2^me).sum()))
