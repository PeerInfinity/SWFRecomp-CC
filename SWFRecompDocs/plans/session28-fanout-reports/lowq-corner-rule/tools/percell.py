import sys, json, numpy as np
from PIL import Image
a=np.asarray(Image.open(sys.argv[1]).convert('RGB')).astype(int)
b=np.asarray(Image.open(sys.argv[2]).convert('RGB')).astype(int)
cells=json.load(open(sys.argv[3])); tol=int(sys.argv[4]) if len(sys.argv)>4 else 2
d=np.abs(a-b)
for c in cells:
    x0,y0=c['col']*40,c['row']*40
    blk=d[y0:y0+40,x0:x0+40]
    n=int((blk>tol).any(axis=2).sum()); ch=int((blk>tol).sum())
    if n: 
        ys,xs=np.nonzero((blk>tol).any(axis=2))
        print(f"{c['name']:16s} px={n:4d} ch={ch:4d} max={blk.max():3d}  sample=({xs[0]},{ys[0]}) A={a[y0+ys[0],x0+xs[0]]} B={b[y0+ys[0],x0+xs[0]]}")
