import sys
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as V
from pathlib import Path
t=Path(sys.argv[2]) if len(sys.argv)>2 else Path('/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/from_shumway/acid/acid-shapes')
ic=V.parse_image_comparisons(t)
ic = ic[0] if isinstance(ic,tuple) else ic
name=sys.argv[3] if len(sys.argv)>3 else 'output'
c=ic[name]
exp = t/(f'{name}.expected.png')
ok,msg,md,st=V.compare_images(sys.argv[1], str(exp), c['checks'])
print('PASS' if ok else 'FAIL', ' '.join(f"t{x['tolerance']}:{x['outliers']}/{x['max_outliers']}" for x in st['checks']))
