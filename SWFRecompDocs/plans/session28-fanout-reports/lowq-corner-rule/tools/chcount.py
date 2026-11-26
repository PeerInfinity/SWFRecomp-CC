import sys,numpy as np
from PIL import Image
a=np.asarray(Image.open(sys.argv[1]).convert('RGBA')).astype(int)
b=np.asarray(Image.open(sys.argv[2]).convert('RGBA')).astype(int)
tol=int(sys.argv[3])
if a.shape!=b.shape: print('size'); sys.exit()
d=np.abs(a-b)[...,:3]
print(int((d>tol).sum()), int((d>tol).any(2).sum()))
