import sys,os,glob,json
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as V
import numpy as np
from PIL import Image
from pathlib import Path
S='/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad'
R=Path('/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs')
def load(slug,cmp,i,j): return np.asarray(Image.open(f'{S}/frames/{slug}/{cmp}.{i}{j}.png').convert('RGBA'),dtype=np.uint32)
def grade(t,cmp,arr,tag):
    out=Path(S)/'compose'/t.replace('/','_'); out.mkdir(parents=True,exist_ok=True)
    p=out/f'{cmp}.{tag}.png'; Image.fromarray(arr,'RGBA').save(p)
    cfg=V.parse_image_comparisons(R/t)[cmp]
    rr=V.compare_images(p,R/t/f"{cfg.get('png_name',cmp)}.expected.png",cfg['checks']); ok=rr[0]; st=rr[-1]
    E=np.asarray(Image.open(R/t/f"{cfg.get('png_name',cmp)}.expected.png").convert('RGBA'),dtype=np.int32)
    L1=np.abs(arr.astype(np.int32)-E).sum()
    return f"{tag}: {'PASS' if ok else 'fail'} L1={L1} "+' '.join(f"t{c['tolerance']}:{c['outliers']}/{c['max_outliers']}" for c in st.get('checks',[]))
for t in open(sys.argv[1]).read().split():
    slug=t.replace('/','_')
    cmps=sorted({os.path.basename(p).rsplit('.',2)[0] for p in glob.glob(f'{S}/frames/{slug}/*.png')})
    for c in cmps:
        res=[]
        def avg(sel):
            fr=[load(slug,c,i,j) for i in range(8) for j in range(8) if sel(i,j)]
            return ((sum(fr)+len(fr)//2)//len(fr)).astype(np.uint8)
        res.append(grade(t,c,avg(lambda i,j:i%2==1 and j%2==1),'gridHalf'))
        res.append(grade(t,c,avg(lambda i,j:i%2==0 and j%2==0),'gridZero'))
        res.append(grade(t,c,avg(lambda i,j:True),'8x8'))
        res.append(grade(t,c,avg(lambda i,j:i%2==0 and j%2==1),'xZero_yHalf'))
        res.append(grade(t,c,avg(lambda i,j:i%2==1 and j%2==0),'xHalf_yZero'))
        print(t,c); [print('   ',r) for r in res]
