# Re-score the w1 CPU glyph model on the FP32 df2 probe with the corrected layout
# (ceil advances, field origin snapped, pen local half-even).
import sys, math, numpy as np
from PIL import Image
T='/home/user/SWFRecomp-CC/SWFRecompDocs/plans/session30-fanout-reports/w1-lowq-residues-fixtures/tools'
sys.path.insert(0,T)
from font2 import load_fonts
import model
S='/tmp/claude-0/-home-user-SWFRecomp-CC/9f5d0a45-dc80-5b9b-bb82-13f383148892/scratchpad'
R='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/regression/lowq_glyph_probe_df2'
fonts=load_fonts(R+'/test.swf'); f=fonts[1]
ADV={'a':627,'c':563,'e':630,'o':626,'s':533,'g':650,'b':650,'@':1024,'&':798,'S':650,' ':325,'2':651,'3':651,'6':651,'9':651}
ASC=950; TEXT='aceosgb@&S 2369'
def heven(v): return float(np.rint(v))
rows=[]; y=4.0
for k in range(4): rows.append((12,10+k*.25,y)); y+=20
for sz in (18,24,36,48,72,96):
  rows.append((sz,5,y)); y+=sz*1.25+2
def G_for(sz,fx,fy,pen):
  sc=sz*20/1024; ox=heven(fx); oy=heven(fy); G=[]; lx=2.0
  by=oy+heven(2+math.floor(ASC*sz*20/1024)/20.0)  # baseline: trunc twips ascent
  for ch in TEXT:
    px=ox+(heven(lx) if pen=='local' else lx)
    G.append(dict(cp=ord(ch),x=px*20,y=by*20,scale=sc))
    a=math.floor(ADV[ch]*sz*20/1024)/20.0
    lx+=math.ceil(a)
  return G
fl=np.asarray(Image.open(R+'/output.expected.png').convert('L')).astype(int)<128
ours=np.asarray(Image.open(S+'/probe/df2_both/output.png').convert('L')).astype(int)<128
W,H=480,600
res={}
for name,mode,par in (('fine16','n',16),('chord','n',1),('tol0.1','tol',0.1),('tol0.25','tol',0.25),('tol0.5','tol',0.5),('tol1','tol',1.0)):
  out=[]
  for sz,fx,fy in rows:
    G=G_for(sz,fx,fy,'local')
    m=model.render(G,fonts,1,W,H,mode,par,pen='raw')
    y0=int(fy); y1=min(H,int(fy+sz*1.6+4))
    out.append((int((m[y0:y1]!=fl[y0:y1]).sum()), int((m[y0:y1]!=ours[y0:y1]).sum())))
  res[name]=out
  print(name,'vsFlash',[o[0] for o in out],'sum',sum(o[0] for o in out),'| vsOurs',[o[1] for o in out])
print('ours vsFlash',[int((ours[int(fy):min(H,int(fy+sz*1.6+4))]!=fl[int(fy):min(H,int(fy+sz*1.6+4))]).sum()) for sz,fx,fy in rows])
