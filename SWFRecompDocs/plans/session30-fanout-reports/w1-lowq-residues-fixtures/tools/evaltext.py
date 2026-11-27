import sys,math; sys.path.insert(0,'/tmp/claude-0/-home-user-SWFRecomp-CC/870fe2e7-0bcb-5076-b47c-a792697b7708/scratchpad/bin')
from model import *
import model
from PIL import Image
def evaluate(swf,dump,ours_png,flash_png,ylim=None,firstline=False,verbose=True):
    fonts=load_fonts(swf); G=last_frame(load_dump(dump))
    if firstline: G=[g for g in G if g['y']==G[0]['y']]
    fid=list(fonts)[0]
    a=np.asarray(Image.open(ours_png).convert('L')).astype(int); f=np.asarray(Image.open(flash_png).convert('L')).astype(int)
    H,W=a.shape
    ys=[g['y']/20 for g in G]; y0=max(int(min(ys))-14,0); y1=min(int(max(ys))+5,H)
    if ylim: y0,y1=ylim
    ours=(a<128); fl=(f<128)
    res={}
    def run(penf,mode,par):
        GG=[]
        for g in G:
            gg=dict(g); gg['x']=penf(g['x']/20)*20; gg['y']=penf(g['y']/20)*20; GG.append(gg)
        return render(GG,fonts,fid,W,H,mode,par,'lowq',pen='raw')
    HU=lambda v: math.floor(v+0.5); RI=lambda v: float(np.rint(v))
    res['gpu']=(ours[y0:y1]!=fl[y0:y1]).sum()
    for nm,pf,mode,par in (('fine_rint',RI,'n',16),('chord_rint',RI,'n',1),('chord_halfup',HU,'n',1),('fine_halfup',HU,'n',16)):
        m=run(pf,mode,par); res[nm]=(m[y0:y1]!=fl[y0:y1]).sum()
    if verbose: print(res,'rows',y0,y1)
    return res
