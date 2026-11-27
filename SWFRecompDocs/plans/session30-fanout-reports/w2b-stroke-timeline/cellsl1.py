import sys
from PIL import Image
g,a,b=[Image.open(p).convert('L').load() for p in sys.argv[1:4]]
tot=[0,0]
for row,y0 in ((26,9480),(27,9840)):
  r=[]
  for k in range(8):
    X0=int((120+k*522.5)/20)-4; Y0=int(y0/20)-4
    A=sum(abs(a[x,y]-g[x,y]) for y in range(Y0,Y0+20) for x in range(X0,X0+26))
    B=sum(abs(b[x,y]-g[x,y]) for y in range(Y0,Y0+20) for x in range(X0,X0+26))
    r.append((A,B)); tot[0]+=A; tot[1]+=B
  print(row, r)
print(tot)
