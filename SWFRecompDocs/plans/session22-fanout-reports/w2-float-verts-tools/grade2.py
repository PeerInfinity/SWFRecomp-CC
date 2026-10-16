# Grade before/after captures against goldens with verify_output.compare_images (CI's own function).
import sys, os, json, pathlib
sys.path.insert(0, '/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as vo
from PIL import Image, ImageChops
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'; CI='/tmp/claude-0/ir/images'; RC='/home/user/SWFRecomp-CC/.render_canary'
rows={}
for r in json.load(open('/tmp/claude-0/imgrows.json')): rows[(r[0]+'/'+r[1], r[2])]=r
def same(p,q):
    if not (os.path.exists(p) and os.path.exists(q)): return None
    a=Image.open(p).convert('RGBA'); b=Image.open(q).convert('RGBA')
    return a.size==b.size and ImageChops.difference(a,b).getbbox(alpha_only=False) is None
def g(p,exp,c):
    if not os.path.exists(p): return 'n/a',None
    ok,msg,md,st=vo.compare_images(p,exp,c['checks'],c.get('config_error'))
    return ('PASS ' if ok else 'FAIL ')+'%s/%s'%(st.get('outliers','?'),st.get('max_outliers','?')), ok
tests=[l.split()[0] for l in open(sys.argv[1]) if l.strip()]
for t in tests:
    td=os.path.join(ROOT,t)
    try: comps=vo.parse_image_comparisons(pathlib.Path(td)).items()
    except Exception as e: print(t,'ERR',e); continue
    for name,c in comps:
        exp=os.path.join(td,name+'.expected.png')
        if not os.path.exists(exp): print(t,name,'noexp'); continue
        b,bok=g(f'{RC}/before/{t}/{name}.png',exp,c); a,aok=g(f'{RC}/after/{t}/{name}.png',exp,c)
        s=same(f'{RC}/before/{t}/{name}.png',f'{RC}/after/{t}/{name}.png')
        ci=os.path.join(CI,t,name+'.actual.png'); cs=same(ci,f'{RC}/before/{t}/{name}.png')
        r=rows.get((t,name)); cist=r[3] if r else '-'
        flip='FLIP+' if (bok is False and aok) else ('FLIP-' if (bok and aok is False) else '')
        print(' | '.join([t,name,'ci='+cist,'before '+b,'after '+a,'ident' if s else ('MOVED' if s is False else 'n/a'),'ci-png:'+('-' if cs is None else ('=' if cs else 'DIFF')),flip]))
