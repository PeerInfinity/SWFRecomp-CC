exec(open(__import__('os').path.join(__import__('os').path.dirname(__import__('os').path.abspath(__file__)),'bevel2.py')).read().split("a=f32(math.radians(200))")[0])
B=blur(3,1)
a=f32(math.radians(200)); cx=f32(math.cos(a)*2); cy=f32(math.sin(a)*2)
pts=[]
for y,row in FL.items():
  for x,v in enumerate(row.split()): pts.append((x,y,int(v,16)>>24))
def bad_for(lx,ly,rx,ry):
  b=0
  for x,y,fa in pts:
    d=math.floor(lvl(B,x+M+lx,y+M+ly)+1e-6)-math.floor(lvl(B,x+M+rx,y+M+ry)+1e-6)
    al=191 if d>=0 else 127
    if math.floor(min(255,abs(d)*2)*(al+1)/256+1e-9)!=fa: b+=1
  return b
best=[]
R=[i/64 for i in range(-12,13)]
for dlx in R:
  for dly in R:
    bl=bad_for(cx+dlx,cy+dly,-cx,-cy)
    best.append((bl,'L',dlx,dly))
for drx in R:
  for dry in R:
    best.append((bad_for(cx,cy,-cx+drx,-cy+dry),'R',drx,dry))
best.sort(key=lambda t:t[0]); print(best[:10])
# symmetric
sym=[]
for d1 in R:
  for d2 in R:
    sym.append((bad_for(cx+d1,cy+d2,-cx-d1,-cy-d2),d1,d2))
sym.sort(key=lambda t:t[0]); print('sym',sym[:8])
