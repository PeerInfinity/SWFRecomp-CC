import sys,os,re,hashlib,glob
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as V
from pathlib import Path
legs=sys.argv[1:]  # e.g. base f01
for t in open('/tmp/claude-0/sp/list.txt').read().split():
    safe=t.replace('/','_'); td=Path('/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs')/t
    ic=V.parse_image_comparisons(td); ic=ic[0] if isinstance(ic,tuple) else ic
    for name,c in ic.items():
        exp=td/f'{name}.expected.png'
        row=[]
        md=[]
        for L in legs:
            p=f'/tmp/claude-0/sw/{safe}/{L}/{name}.png'
            if not os.path.exists(p) or not exp.exists(): row.append('n/a'); md.append(None); continue
            ok,msg,mx,st=V.compare_images(p,str(exp),c['checks'])
            bind=[x for x in st.get('checks',[]) if not x.get('passed',True)]
            b=bind[0] if bind else st['checks'][-1] if st.get('checks') else {}
            row.append(f"{'P' if ok else 'F'} t{b.get('tolerance')}:{b.get('outliers')}/{b.get('max_outliers')}")
            md.append(hashlib.md5(open(p,'rb').read()).hexdigest()[:8])
        same='same' if len(set(md))==1 else 'DIFF'
        print(f'{t}[{name}]', ' | '.join(row), same)
