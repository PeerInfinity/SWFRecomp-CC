import math,sys,itertools
exec(open(sys.argv[2]).read().split("base=score")[0])
FL=[[None]*80 for _ in range(80)]
pts=[]
for dy in range(80):
  for dx in range(80):
    sx,sy=dx-20,dy-20
    if 10<=sx<30 and 10<=sy<30: continue
    pts.append((dx,dy,sx+M,sy+M,255-f[dx+10,dy+10][0]))
g=lambda X,Y: B[Y][X] if 0<=X<W and 0<=Y<W else 0
def offq(q,mode):
  if q is None: return offf
  v=off*q
  return (math.floor(v) if mode=='f' else round(v))/q
def samp(px,py,wq,form):
  x0=math.floor(px); y0=math.floor(py); tx=px-x0; ty=py-y0
  if wq:
    tx=math.floor(tx*wq+1e-9); ty=math.floor(ty*wq+1e-9)
    if form=='fix':
      top=g(x0,y0)*(wq-tx)+g(x0+1,y0)*tx; bot=g(x0,y0+1)*(wq-tx)+g(x0+1,y0+1)*tx
      return (top*(wq-ty)+bot*ty)//(wq*wq)
    if form=='fixr':
      top=g(x0,y0)*(wq-tx)+g(x0+1,y0)*tx; bot=g(x0,y0+1)*(wq-tx)+g(x0+1,y0+1)*tx
      return (top*(wq-ty)+bot*ty + wq*wq//2)//(wq*wq)
    if form=='sep':  # x then floor then y
      top=(g(x0,y0)*(wq-tx)+g(x0+1,y0)*tx)//wq; bot=(g(x0,y0+1)*(wq-tx)+g(x0+1,y0+1)*tx)//wq
      return (top*(wq-ty)+bot*ty)//wq
    tx/=wq; ty/=wq
  v=(g(x0,y0)*(1-tx)+g(x0+1,y0)*tx)*(1-ty)+(g(x0,y0+1)*(1-tx)+g(x0+1,y0+1)*tx)*ty
  return math.floor(v+1e-6) if form!='round' else round(v)
res=[]
for q,mode in [(None,'-'),(20,'f'),(20,'r'),(16,'f'),(16,'r'),(32,'f'),(32,'r'),(64,'f'),(64,'r'),(256,'f'),(256,'r'),(8,'f'),(8,'r'),(4,'r')]:
  o_=offq(q,mode)
  for wq,form in [(None,'flt'),(None,'round'),(256,'fix'),(256,'fixr'),(256,'sep'),(16,'fix'),(16,'sep'),(16,'fixr'),(32,'fix'),(64,'fix'),(128,'fix'),(65536,'fix')]:
    for am in ['p1','255','r']:
      bad=0
      for dx,dy,x,y,fl in pts:
        lv=samp(x-o_,y-o_,wq,form)
        ga = math.floor(lv*205/256+1e-9) if am=='p1' else (math.floor(lv*204/255+1e-9) if am=='255' else (lv*205)>>8)
        if am=='r': ga=(lv*204+127)//255
        if ga!=fl: bad+=1
      res.append((bad,q,mode,wq,form,am))
res.sort(key=lambda r:r[0]); [print(r) for r in res[:15]]
