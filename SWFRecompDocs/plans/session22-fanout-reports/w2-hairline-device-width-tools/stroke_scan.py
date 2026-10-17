import sys, os, subprocess, shutil, glob, re
from concurrent.futures import ThreadPoolExecutor
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'
CFG='/home/user/SWFRecomp-CC/ruffle-tests/_shared/config.toml'
def one(t):
    out=[]
    for sw in sorted(glob.glob(os.path.join(ROOT,t,'*.swf'))):
        wd='/root/scan/wd/'+t.replace('/','__')+os.path.basename(sw)
        shutil.rmtree(wd,ignore_errors=True); os.makedirs(wd); shutil.copy(sw,wd+'/test.swf')
        p=subprocess.run(['bash','-c','ulimit -v 4194304; exec "$@"','--','/root/SWFRecomp.after',CFG],cwd=wd,capture_output=True,timeout=900)
        try:
            src=open(wd+'/RecompiledTags/draws.c',encoding='latin-1').read()
            n=int(re.search(r'stroke_run_count = (\d+)',src).group(1))
            m=re.search(r'stroke_run_data\[\d+\]\[5\] =\n\{\n(.*?)\n\};',src,re.S)
            thin=sum(1 for l in m.group(1).split('\n') if re.match(r'\s*\{ \d+, \d+, \d+, (\d+),',l) and int(re.match(r'\s*\{ \d+, \d+, \d+, (\d+),',l).group(1))<20) if n else 0
            out.append('%s:%d:%d'%(os.path.basename(sw),n,thin))
        except Exception as e: out.append('%s:ERR%d'%(os.path.basename(sw),p.returncode))
        shutil.rmtree(wd,ignore_errors=True)
    return t,' '.join(out)
tests=[l.strip() for l in open(sys.argv[1]) if l.strip()]
with ThreadPoolExecutor(4) as ex:
    for t,st in ex.map(one,tests): print(t,st,flush=True)
