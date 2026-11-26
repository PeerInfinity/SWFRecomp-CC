import sys,re,numpy as np
from PIL import Image
exec(open('fitreflect.py').read().split("roi=np.zeros")[0].replace("ou=np.asarray(Image.open(sys.argv[3]).convert('RGB')).astype(float)",""))
t=tval(0,0)  # corner
# per pixel: Flash index k = R-channel decode: u = (255-R) for red->cyan (R=255-u)
k=255-fl[...,0]
# unfold reflect: candidate unfolded index from t
period=np.floor(t)  # which half: t in [0,1): direct; [1,2): reflected; [-1,0): reflected
U=t*256
for ty0 in range(50,290,40):
  row=[]
  for tx0 in range(70,480,50):
    sl=(slice(ty0,ty0+40),slice(tx0,tx0+50))
    tt=t[sl];kk=k[sl];m=(np.abs(fl[sl][...,0]+fl[sl][...,1]-255)<=0)&(kk>2)&(kk<253)
    tm=np.mod(tt,2); refl=tm>1
    # direct: k=floor(256 tm + s) ; reflected: k = floor(256*(2-tm) + s') 
    ud=np.where(refl,256*(2-tm),256*tm)
    v=kk-ud
    if m.sum()<50: row.append('   .  '); continue
    lo=np.max((kk-ud)[m]); hi=np.min((kk+1-ud)[m])
    row.append(f"{np.median((kk+0.5-ud)[m]):+.2f}{'*' if lo<=hi else ' '}")
  print(ty0,' '.join(row))
