import zlib,struct,sys
sys.path.insert(0,'SWFRecompDocs/plans/session30-fanout-reports/w2-lowq-land-fixtures/tools')
def tags(path):
  d=open(path,'rb').read()
  if d[:3]==b'CWS': d=d[:8]+zlib.decompress(d[8:])
  nb=d[8]>>3; p=8+(5+4*nb+7)//8+4
  out=[]
  def walk(p,end):
    while p<end:
      h=struct.unpack('<H',d[p:p+2])[0]; c=h>>6; l=h&63; p+=2
      if l==63: l=struct.unpack('<I',d[p:p+4])[0]; p+=4
      out.append((c,d[p:p+l]))
      if c==39: walk(p+4,p+l)
      p+=l
  walk(p,len(d)); return out
def font2(b):
  fid,fl=struct.unpack('<HB',b[:3]); q=4; nl=b[q]; q+=1; name=b[q:q+nl]; q+=nl
  n=struct.unpack('<H',b[q:q+2])[0]; q+=2
  wide=fl&8
  offs=[struct.unpack('<I' if wide else '<H',b[q+i*(4 if wide else 2):q+(i+1)*(4 if wide else 2)])[0] for i in range(n)]
  q0=q; q+=n*(4 if wide else 2); ctoff=struct.unpack('<I' if wide else '<H',b[q:q+(4 if wide else 2)])[0]
  q=q0+ctoff
  codes=[struct.unpack('<H',b[q+2*i:q+2*i+2])[0] for i in range(n)]; q+=2*n
  asc,desc,lead=struct.unpack('<hhh',b[q:q+6]); q+=6
  adv=[struct.unpack('<h',b[q+2*i:q+2*i+2])[0] for i in range(n)]
  return fid,fl,dict(zip(codes,adv)),(asc,desc,lead)
if __name__=='__main__':
  for c,b in tags(sys.argv[1]):
    if c==48:
      fid,fl,adv,m=font2(b); print('font',fid,hex(fl),m); print({chr(k):v for k,v in adv.items()})
