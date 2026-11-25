exec(open(__import__('os').path.join(__import__('os').path.dirname(__import__('os').path.abspath(__file__)),'bevel3.py')).read().split("best=[]")[0])
def apR(img,horiz,k,div):
  m,fr,fs=k; out=[[0]*W for _ in range(W)]
  g=lambda y,x: img[y][x] if 0<=x<W and 0<=y<W else 0
  for y in range(W):
    for x in range(W):
      s=sum((g(y,x+t) if horiz else g(y+t,x)) for t in range(-m,m+1))
      e=(g(y,x-m-1)+g(y,x+m+1)) if horiz else (g(y-m-1,x)+g(y+m+1,x))
      out[y][x]=max(0,min(255,div(s+fr*e,fs)))
  return out
divs={
 'exact':lambda v,fs: math.floor(v/fs+1e-9),
 'rcp16t':lambda v,fs: (int(round(v*256))*(65536//int(round(fs*256))))>>16 if False else math.floor(v*math.floor(65536/fs)/65536),
 'rcp8t':lambda v,fs: math.floor(v*math.floor(256/fs)/256),
 'rcp15t':lambda v,fs: math.floor(v*math.floor(32768/fs)/32768),
 'rcp24t':lambda v,fs: math.floor(v*math.floor((1<<24)/fs)/(1<<24)),
 'rcp12t':lambda v,fs: math.floor(v*math.floor(4096/fs)/4096),
 'rcp10t':lambda v,fs: math.floor(v*math.floor(1024/fs)/1024),
}
for nm,dv in divs.items():
  k=kern(3); B2=apR(apR(A,1,k,dv),0,k,dv)
  bad=0; lst=[]
  for x,y,fa in pts:
    d=math.floor(lvl(B2,x+M+cx,y+M+cy)+1e-6)-math.floor(lvl(B2,x+M-cx,y+M-cy)+1e-6)
    al=191 if d>=0 else 127
    if math.floor(min(255,abs(d)*2)*(al+1)/256+1e-9)!=fa: bad+=1; lst.append((y,x))
  print(nm,bad,lst[:8])
