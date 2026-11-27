import sys, pathlib, hashlib
sys.path.insert(0,'ruffle-tests')
import verify_output as vo
from PIL import Image, ImageChops
root=pathlib.Path('ruffle-tests/tests/swfs'); rc=pathlib.Path('.render_canary')
A,B,lst=sys.argv[1],sys.argv[2],sys.argv[3]
prov={}
def l1(p,e):
    a=Image.open(p).convert('RGBA'); g=Image.open(e).convert('RGBA')
    if a.size!=g.size: return None
    d=ImageChops.difference(a,g)
    return sum(i*c for band in d.split() for i,c in enumerate(band.histogram()))
for t in [l.strip() for l in open(lst) if l.strip()]:
    ic=vo.parse_image_comparisons(root/t)
    for k,c in ic.items():
        png=c.get('png_name',k)
        pa=rc/A/t/f"{k}.png"; pb=rc/B/t/f"{k}.png"
        if not pa.exists(): pa=rc/A/t/f"{png}.png"
        if not pb.exists(): pb=rc/B/t/f"{png}.png"
        if not (pa.exists() and pb.exists()): print(t,k,"MISSING"); continue
        if hashlib.md5(pa.read_bytes()).digest()==hashlib.md5(pb.read_bytes()).digest(): continue
        exp=root/t/f"{png}.expected.png"
        if not exp.exists(): print(f"{t} {k}: DIFFERS, no golden"); continue
        _,_,_,sa=vo.compare_images(pa,exp,c['checks']); okb,_,_,sb=vo.compare_images(pb,exp,c['checks'])
        oka=sa.get('failed_checks',1)==0 if 'failed_checks' in sa else None
        parts=[]
        for ca,cb in zip(sa.get('checks',[]),sb.get('checks',[])):
            parts.append(f"t{ca['tolerance']} {ca['outliers']}->{cb['outliers']}/{ca['max_outliers']}")
        la,lb=l1(pa,exp),l1(pb,exp)
        st=lambda s:'pass' if s.get('failed_checks',1)==0 else 'FAIL'
        print(f"{t} {k}: {st(sa)}->{st(sb)} | "+"; ".join(parts)+f" | L1 {la}->{lb} ({((lb-la)/la*100 if la else 0):+.2f}%)")
