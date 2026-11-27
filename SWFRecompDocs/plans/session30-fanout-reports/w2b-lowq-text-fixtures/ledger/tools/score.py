import sys
from PIL import Image
import numpy as np
ref=np.asarray(Image.open(sys.argv[1]).convert('RGB'),dtype=int)
for p in sys.argv[2:]:
  a=np.asarray(Image.open(p).convert('RGB'),dtype=int); d=np.abs(a-ref)
  print(p.split('/')[-3:], ' '.join(f't{t}={(d>t).sum()}' for t in (0,16,64)))
