import sys, os
sys.path.insert(0, '/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as vo
from PIL import Image, ImageChops
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'; CI='/tmp/claude-0/ir/images'; RC='/home/user/SWFRecomp-CC/.render_canary'
labels=sys.argv[2:]; tests=[l.split()[0] for l in open(sys.argv[1]) if l.strip()]
def same(p,q):
    if not (os.path.exists(p) and os.path.exists(q)): return None
    a=Image.open(p).convert('RGBA'); b=Image.open(q).convert('RGBA')
    return a.size==b.size and ImageChops.difference(a,b).getbbox(alpha_only=False) is None
for t in tests:
    td=os.path.join(ROOT,t)
    for name,c in vo.parse_image_comparisons(__import__("pathlib").Path(td)).items():
        exp=os.path.join(td,name+'.expected.png'); out=[t,name]
        for L in labels:
            p=f'{RC}/{L}/{t}/{name}.png'
            if not os.path.exists(exp) or not os.path.exists(p): out.append('n/a'); continue
            ok,msg,md,st=vo.compare_images(p,exp,c['checks'],c.get('config_error'))
            out.append('%s%s/%s' % ('PASS ' if ok else '', st.get('outliers','?'), st.get('max_outliers','?')))
        if len(labels)>1:
            s=same(f'{RC}/{labels[0]}/{t}/{name}.png', f'{RC}/{labels[-1]}/{t}/{name}.png'); out.append('ident' if s else 'MOVED')
        ci=os.path.join(CI,t,name+'.actual.png')
        s=same(ci,f'{RC}/{labels[0]}/{t}/{name}.png'); out.append('ci:' + ('-' if s is None else ('=' if s else 'DIFF')))
        print(' | '.join(out))
