import math,sys
from PIL import Image
D=sys.argv[1]
f=Image.open(D+'/output.expected.png').convert('RGB').load(); o=Image.open(D+'/output.actual.png').convert('RGB').load()
print('stage(60,60) ours',o[60,60],'flash',f[60,60])
N=40; M=20  # margin
W=N+2*M
A=[[0]*W for _ in range(W)]
for y in range(10,30):
  for x in range(10,30): A[y+M][x+M]=255
def kern(size): r=(size-1)/2; m=math.ceil(r)-1; return m, r-m, size
def ap(img,horiz,k):
  m,fr,fs=k; out=[[0]*W for _ in range(W)]
  g=lambda y,x: img[y][x] if 0<=x<W and 0<=y<W else 0
  for y in range(W):
    for x in range(W):
      s=0; e=0
      for t in range(-m,m+1): s+= g(y,x+t) if horiz else g(y+t,x)
      e = (g(y,x-m-1)+g(y,x+m+1)) if horiz else (g(y-m-1,x)+g(y+m+1,x))
      out[y][x]=max(0,min(255,math.floor((s+fr*e)/fs+1e-9)))
  return out
k=kern(6.0); B=A
for p in range(2): B=ap(B,1,k)
for p in range(2): B=ap(B,0,k)
off=5*math.cos(math.radians(45))
import struct
offf=struct.unpack('f',struct.pack('f',off))[0]
def lvl(px,py,wq=None):
  x0=math.floor(px); y0=math.floor(py); tx=px-x0; ty=py-y0
  if wq: tx=math.floor(tx*wq)/wq; ty=math.floor(ty*wq)/wq
  g=lambda X,Y: B[Y][X] if 0<=X<W and 0<=Y<W else 0
  v=(g(x0,y0)*(1-tx)+g(x0+1,y0)*tx)*(1-ty)+(g(x0,y0+1)*(1-tx)+g(x0+1,y0+1)*tx)*ty
  return max(0,min(255,math.floor(v+1e-6)))
def ga_of(level, al=205/256): return math.floor(level*al+1e-9)
def score(fn):
  bad=[];
  for dy in range(0,80):
    for dx in range(0,80):
      sx,sy=dx-20,dy-20
      if 10<=sx<30 and 10<=sy<30: continue   # source covered
      sx_,sy_=sx+M,sy+M
      ga=fn(sx_,sy_)
      fl=255-f[dx+10,dy+10][0]
      if abs(ga-fl)>0: bad.append((dx,dy,ga,fl))
  return bad
base=score(lambda x,y: ga_of(lvl(x-offf,y-offf)))
print('base model mismatch(>0):',len(base), base[:12])
for wq in [256,128,64,32,16,8]:
  print('wq',wq,len(score(lambda x,y: ga_of(lvl(x-offf,y-offf,wq)))))
def score_o(fn):
  bad=[]
  for dy in range(0,80):
    for dx in range(0,80):
      sx,sy=dx-20,dy-20
      if 10<=sx<30 and 10<=sy<30: continue
      ga=fn(sx+M,sy+M); ol=255-o[dx+10,dy+10][0]
      if ga!=ol: bad.append((dx,dy,ga,ol))
  return bad
b=score_o(lambda x,y: ga_of(lvl(x-offf,y-offf)))
print('replica vs OURS:',len(b),b[:10])
print('map flash-ours, rows dy 26..66, cols dx 26..66 (. =0)')
for dy in range(26,67):
  row=''
  for dx in range(26,67):
    sx,sy=dx-20,dy-20
    if 10<=sx<30 and 10<=sy<30: row+='#'; continue
    dd=(255-f[dx+10,dy+10][0])-(255-o[dx+10,dy+10][0])
    row+= '.' if dd==0 else (str(dd) if dd>0 else 'abcdefghi'[-dd-1])
  print('%2d %s'%(dy,row))
