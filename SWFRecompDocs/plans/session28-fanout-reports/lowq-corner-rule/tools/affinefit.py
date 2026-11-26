import sys,re,numpy as np
from PIL import Image
exec(open('fitreflect.py').read().split("roi=np.zeros")[0].replace("ou=np.asarray(Image.open(sys.argv[3]).convert('RGB')).astype(float)",""))
t=tval(0,0); U=t*256
k=255-fl[...,0]
m=(np.abs(fl[...,0]+fl[...,1]-255)==0)&(fl[...,1]==fl[...,2])&(k>3)&(k<252)
m[:45]=False; m[290:]=False; m[:,:65]=False; m[:,480:]=False
Um=np.mod(U,512)
j=np.where(Um>=256,511-k,k)
J=j+np.floor(U/512)*512
yy,xx=np.nonzero(m)
y=J[m]+0.5
A=np.stack([xx,yy,np.ones_like(xx)],1).astype(float)
sol,*_=np.linalg.lstsq(A,y,rcond=None)
# true coefficients at corner
dUdx=(U[100,201]-U[100,200]);dUdy=(U[101,200]-U[100,200]);U0=U[0,0]
print('true  A=%.6f B=%.6f C=%.4f'%(dUdx,dUdy,U0))
print('flash A=%.6f B=%.6f C=%.4f'%tuple(sol), 'res max', np.max(np.abs(y-A@sol)))
print('model frac at (0,0): ', sol[2]-U0)
