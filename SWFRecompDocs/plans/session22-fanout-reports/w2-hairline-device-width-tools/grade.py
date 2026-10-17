import sys, os, pathlib, hashlib
sys.path.insert(0, '/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as vo
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'; RC='/home/user/SWFRecomp-CC/.render_canary'
labels=sys.argv[2].split(',')
def md5(p): return hashlib.md5(open(p,'rb').read()).hexdigest()[:8]
for t in [l.strip() for l in open(sys.argv[1]) if l.strip() and not l.startswith('#')]:
  for name,c in vo.parse_image_comparisons(pathlib.Path(ROOT,t)).items():
    exp=os.path.join(ROOT,t,name+'.expected.png'); out=[]
    for L in labels:
        p=f'{RC}/{L}/{t}/{name}.png'
        if not os.path.exists(p): out.append(L+' n/a'); continue
        if not os.path.exists(exp): out.append(L+' noexp '+md5(p)); continue
        ok,msg,md,st=vo.compare_images(p,exp,c['checks'],c.get('config_error'))
        out.append(L+' '+('P' if ok else 'F')+' '+','.join('%s/%s'%(k.get('outliers'),k.get('max_outliers')) for k in st.get('checks',[st]))+' '+md5(p))
    print(t.split('/')[-1],name,' | '.join(out))
