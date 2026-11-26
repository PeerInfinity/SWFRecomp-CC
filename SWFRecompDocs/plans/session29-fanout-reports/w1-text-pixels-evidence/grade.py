import sys
from PIL import Image
import numpy as np
lab=np.load('lab.npy',allow_pickle=True)
F=np.asarray(Image.open('flash.png').convert('RGB')).astype(int)
for name in sys.argv[1:]:
    A=np.asarray(Image.open(name).convert('RGB')).astype(int)
    d=np.abs(A-F); dm=d.max(axis=2)
    print(name,'px>2',(dm>2).sum(),'px>0',(dm>0).sum(),'L1/3',d.sum()//3,'ch>128',(d>128).sum(),'ch>16',(d>16).sum(),'ch>1',(d>1).sum(),'max',d.max())
    for k in sorted(set(lab.flatten())):
        mm=lab==k
        if (dm[mm]>2).sum(): print('   ',k,'px>2',(dm[mm]>2).sum(),'L1',d[mm].sum()//3)
