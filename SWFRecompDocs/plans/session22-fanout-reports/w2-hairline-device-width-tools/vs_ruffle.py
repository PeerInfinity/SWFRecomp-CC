import sys,os
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests'); import verify_output as vo
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'; RC='/home/user/SWFRecomp-CC/.render_canary'
t,name=sys.argv[1],sys.argv[2]
for L in sys.argv[3].split(','):
  p=f'{RC}/{L}/{t}/{name}.png'
  for ref in ('expected','ruffle'):
    r=os.path.join(ROOT,t,f'{name}.{ref}.png')
    if os.path.exists(r):
      for tol in (0,5,40):
        ok,msg,md,st=vo.compare_images(p,r,[{'tolerance':tol,'max_outliers':0}],None)
        print(L,ref,'tol',tol,[c.get('outliers') for c in st.get('checks',[st])])
