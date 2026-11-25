import math,struct
f32=lambda v: struct.unpack('f',struct.pack('f',v))[0]
N=20; M=12; W=N+2*M
A=[[0]*W for _ in range(W)]
for y in range(5,15):
  for x in range(5,15): A[y+M][x+M]=153
for y in range(8,12):
  for x in range(8,12): A[y+M][x+M]=255
def kern(size): r=(size-1)/2; m=math.ceil(r)-1; return m, r-m, size
def ap(img,horiz,k):
  m,fr,fs=k; out=[[0]*W for _ in range(W)]
  g=lambda y,x: img[y][x] if 0<=x<W and 0<=y<W else 0
  for y in range(W):
    for x in range(W):
      s=sum((g(y,x+t) if horiz else g(y+t,x)) for t in range(-m,m+1))
      e=(g(y,x-m-1)+g(y,x+m+1)) if horiz else (g(y-m-1,x)+g(y+m+1,x))
      out[y][x]=max(0,min(255,math.floor((s+fr*e)/fs+1e-9)))
  return out
def blur(b,q):
  B=A;k=kern(b)
  for p in range(q): B=ap(B,1,k)
  for p in range(q): B=ap(B,0,k)
  return B
def lvl(B,px,py):
  x0=math.floor(px); y0=math.floor(py); tx=px-x0; ty=py-y0
  g=lambda X,Y: B[Y][X] if 0<=X<W and 0<=Y<W else 0
  v=(g(x0,y0)*(1-tx)+g(x0+1,y0)*tx)*(1-ty)+(g(x0,y0+1)*(1-tx)+g(x0+1,y0+1)*tx)*ty
  return v
import sys
def run(dist,ang,b,q,st,hl_a,sh_a,flash_rows):
  B=blur(b,q); a=f32(math.radians(ang)); cx=f32(math.cos(a)*dist); cy=f32(math.sin(a)*dist)
  print('off',cx,cy)
  for y,row in flash_rows.items():
    vals=row.split()
    for x in range(N):
      fv=int(vals[x],16); fa=fv>>24
      vl=lvl(B,x+M+cx,y+M+cy); vr=lvl(B,x+M-cx,y+M-cy)
      d=math.floor(vl+1e-6)-math.floor(vr+1e-6)
      al=hl_a if d>=0 else sh_a
      ga=math.floor(min(255,abs(d)*st)*(al+1)/256+1e-9)
      flag='' if ga==fa else ' <<<'
      if flag or (x in (6,7,8,9)): print(y,x,'bl %.3f br %.3f fd %.3f d %d ga %d flashA %d %s'%(vl,vr,vl-vr,d,ga,fa,flag))
run(2,200,3,1,2,191,127,{6:"0 0 2cff00ff 5fff00ff 7fff00ff 7fff00ff 7bff00ff 5cff00ff 3aff00ff 32ff00ff 2bff00ff 23ff00ff fffff00 5bffff00 a8ffff00 a9ffff00 6dffff00 33ffff00 0 0",10:"0 0 2cff00ff 5fff00ff 7fff00ff 7fff00ff 7fff00ff 78ff00ff 4aff00ff 11ff00ff 40ffff00 94ffff00 bffefe00 bffefe00 bffefe00 bffefe00 8effff00 42ffff00 0 0"})
