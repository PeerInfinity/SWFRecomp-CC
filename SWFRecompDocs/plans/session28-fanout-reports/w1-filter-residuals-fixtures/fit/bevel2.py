exec(open(__import__('os').path.join(__import__('os').path.dirname(__import__('os').path.abspath(__file__)),'bevel.py')).read().split('run(2,200')[0])
def shift(img,ox,oy,mode):
  out=[[0]*W for _ in range(W)]
  g=lambda X,Y: img[Y][X] if 0<=X<W and 0<=Y<W else 0
  for y in range(W):
    for x in range(W):
      px,py=x+ox,y+oy; x0=math.floor(px); y0=math.floor(py); tx=px-x0; ty=py-y0
      v=(g(x0,y0)*(1-tx)+g(x0+1,y0)*tx)*(1-ty)+(g(x0,y0+1)*(1-tx)+g(x0+1,y0+1)*tx)*ty
      out[y][x]=math.floor(v+1e-6) if mode=='f' else round(v)
  return out
def blurI(I,b,q):
  k=kern(b); B=I
  for p in range(q): B=ap(B,1,k)
  for p in range(q): B=ap(B,0,k)
  return B
FL={6:"0 0 2cff00ff 5fff00ff 7fff00ff 7fff00ff 7bff00ff 5cff00ff 3aff00ff 32ff00ff 2bff00ff 23ff00ff fffff00 5bffff00 a8ffff00 a9ffff00 6dffff00 33ffff00 0 0",10:"0 0 2cff00ff 5fff00ff 7fff00ff 7fff00ff 7fff00ff 78ff00ff 4aff00ff 11ff00ff 40ffff00 94ffff00 bffefe00 bffefe00 bffefe00 bffefe00 8effff00 42ffff00 0 0"}
a=f32(math.radians(200)); cx=f32(math.cos(a)*2); cy=f32(math.sin(a)*2)
for mode in ['f','r']:
  L=blurI(shift(A,cx,cy,mode),3,1); R=blurI(shift(A,-cx,-cy,mode),3,1)
  bad=0
  for y,row in FL.items():
    for x,v in enumerate(row.split()):
      fa=int(v,16)>>24; d=L[y+M][x+M]-R[y+M][x+M]
      al=191 if d>=0 else 127
      ga=math.floor(min(255,abs(d)*2)*(al+1)/256+1e-9)
      if ga!=fa: bad+=1; print(mode,y,x,d,ga,fa)
  print(mode,'bad',bad)
