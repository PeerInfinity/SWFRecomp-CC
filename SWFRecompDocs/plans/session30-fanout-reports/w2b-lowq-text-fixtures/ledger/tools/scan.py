import sys,os,re,zlib,struct
sys.path.insert(0,os.path.dirname(__file__)); import df2
root='ruffle-tests/tests/swfs'
for dp,dn,fn in os.walk(root):
  if 'test.toml' not in fn: continue
  t=open(os.path.join(dp,'test.toml')).read()
  if 'image_comparisons' not in t: continue
  low=re.search(r'quality\s*=\s*"low"',t) is not None
  swfs=[f for f in fn if f.endswith('.swf')]
  if not swfs: continue
  p=os.path.join(dp,'test.swf' if 'test.swf' in swfs else swfs[0])
  try:
    d=open(p,'rb').read(); ver=d[3]
    tg=df2.tags(p)
  except Exception as e: continue
  fonts=[]
  for c,b in tg:
    if c in (48,75):
      fl=b[2]; nl=b[4]; n=struct.unpack('<H',b[5+nl:7+nl])[0]
      fonts.append((c,hex(fl),n))
  et=sum(1 for c,b in tg if c==37)
  if low and any(c in (48,) and n>0 for c,fl,n in fonts):
    print(('LOW ' if low else 'HIGH'), ver, dp[len(root)+1:], fonts, 'edit',et)
