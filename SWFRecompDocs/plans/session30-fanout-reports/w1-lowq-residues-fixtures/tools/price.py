import sys,math,re,shutil; sys.path.insert(0,'/tmp/claude-0/-home-user-SWFRecomp-CC/870fe2e7-0bcb-5076-b47c-a792697b7708/scratchpad/bin')
from model import *
from PIL import Image
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests'); import verify_output as vo
S='/tmp/claude-0/-home-user-SWFRecomp-CC/870fe2e7-0bcb-5076-b47c-a792697b7708/scratchpad'
HU=lambda v: math.floor(v+0.5); RI=lambda v: float(np.rint(v))
def model_mask(swf,G,W,H,penf,mode,par):
    fonts=load_fonts(swf); fid=list(fonts)[0]; GG=[]
    for g in G:
        gg=dict(g); gg['x']=penf(g['x']/20)*20; gg['y']=penf(g['y']/20)*20; GG.append(gg)
    return render(GG,fonts,fid,W,H,mode,par,'lowq',pen='raw')
def price(testdir,cmp,ours_png,G,rows,variants):
    ic=vo.parse_image_comparisons(vo.Path(testdir)); ic=ic[0] if isinstance(ic,tuple) else ic
    cfg=ic[cmp]; exp=f'{testdir}/{cfg.get("png_name",cmp)}.expected.png'
    im=Image.open(ours_png).convert('RGBA'); a=np.asarray(im).copy(); H,W=a.shape[:2]
    ink=(np.asarray(im.convert('L'))<128)
    out={}
    for nm,(pf,mode,par) in variants.items():
        b=a.copy()
        if pf is not None:
            m=model_mask(testdir+'/test.swf',G,W,H,pf,mode,par)
            y0,y1=rows
            reg=b[y0:y1]; inkr=ink[y0:y1]; mr=m[y0:y1]
            reg[inkr & ~mr]=[255,255,255,255]; reg[mr]=[0,0,0,255]
        p=f'{S}/price_tmp.png'; Image.fromarray(b).save(p)
        ok,msg,mx,st=vo.compare_images(p,exp,cfg['checks'])
        mm=re.search(r'(\d+) outliers',msg or ''); out[nm]=('P' if ok else 'F')+(mm.group(1) if mm else '0')
    return out
V={'before':(None,None,None),'fine_rint(=gpu model)':(RI,'n',16),'chord_rint':(RI,'n',1),'pen_halfup_only':(HU,'n',16),'chord_halfup':(HU,'n',1)}
