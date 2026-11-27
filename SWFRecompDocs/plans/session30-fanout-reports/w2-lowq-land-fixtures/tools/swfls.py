import sys,zlib,struct
class BR:
  def __init__(s,b,p=0): s.b=b; s.p=p*8
  def u(s,n):
    v=0
    for _ in range(n): v=(v<<1)|((s.b[s.p>>3]>>(7-(s.p&7)))&1); s.p+=1
    return v
  def s_(s,n):
    v=s.u(n); return v-(1<<n) if n and v>>(n-1) else v
  def align(s): s.p=(s.p+7)//8*8
def rect(br):
  n=br.u(5); return [br.s_(n) for _ in range(4)]
def matrix(br):
  m=[1,0,0,1,0,0]
  if br.u(1): n=br.u(5); m[0]=br.s_(n)/65536; m[3]=br.s_(n)/65536
  if br.u(1): n=br.u(5); m[1]=br.s_(n)/65536; m[2]=br.s_(n)/65536
  n=br.u(5); m[4]=br.s_(n); m[5]=br.s_(n); br.align(); return m
d=open(sys.argv[1],'rb').read()
if d[:3]==b'CWS': d=d[:8]+zlib.decompress(d[8:])
br=BR(d,8); print("stage",rect(br)); br.align(); p=br.p//8+4
def walk(d,p,end,ind=''):
  while p<end:
    h=struct.unpack('<H',d[p:p+2])[0]; c=h>>6; l=h&63; p+=2
    if l==63: l=struct.unpack('<I',d[p:p+4])[0]; p+=4
    b=d[p:p+l]
    if c in (2,22,32,83):
      cid=struct.unpack('<H',b[:2])[0]; r=BR(b,2); print(ind,'DefineShape',c,'id',cid,'bounds',rect(r))
    elif c in (26,70):
      fl=b[0]; q=1; fl2=0
      if c==70: fl2=b[1]; q=2
      dep=struct.unpack('<H',b[q:q+2])[0]; q+=2
      if c==70 and (fl2&8 or (fl2&16 and fl&2)): pass
      cid=None
      if c==70 and fl2&8:
        e=b.index(0,q); q=e+1
      if fl&2: cid=struct.unpack('<H',b[q:q+2])[0]; q+=2
      m=None
      if fl&4: r=BR(b,q); m=matrix(r); q=r.p//8
      print(ind,'Place',c,'depth',dep,'id',cid,'m',m,'flags',hex(fl),hex(fl2), 'name' if fl&32 else '')
    elif c==39:
      sid=struct.unpack('<H',b[:2])[0]; print(ind,'DefineSprite',sid); walk(d,p+4,p+l,ind+'  ')
    elif c==1: print(ind,'ShowFrame')
    elif c in (12,59,82): print(ind,'Action tag',c,len(b))
    elif c==0: pass
    else: print(ind,'tag',c,len(b))
    p+=l
walk(d,p,len(d))
