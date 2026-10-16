# For each test: recompile test.swf (and sibling .swf children) with BEFORE and AFTER recompiler
# binaries, compare the generated RecompiledTags trees. Prints CHANGED / SAME / FAIL.
import sys, os, subprocess, shutil, hashlib, glob
from concurrent.futures import ThreadPoolExecutor
S=os.path.dirname(os.path.abspath(__file__)); ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'
CFG='/home/user/SWFRecomp-CC/ruffle-tests/_shared/config.toml'
def tree_hash(d):
    h=hashlib.md5()
    for f in sorted(glob.glob(d+'/**/*',recursive=True)):
        if os.path.isfile(f): h.update(f[len(d):].encode()); h.update(open(f,'rb').read())
    return h.hexdigest()
def run(binname, swf, wd):
    shutil.rmtree(wd, ignore_errors=True); os.makedirs(wd); shutil.copy(swf, wd+'/test.swf')
    p=subprocess.run(['bash','-c','ulimit -v 4194304; exec "$@"','--',S+'/'+binname,CFG],cwd=wd,capture_output=True,timeout=900)
    if p.returncode: return 'FAIL%d'%p.returncode
    return tree_hash(wd+'/RecompiledTags')
def one(t):
    swfs=sorted(glob.glob(os.path.join(ROOT,t,'*.swf')))
    if not swfs: return t,'NOSWF'
    res=[]
    for sw in swfs:
        k=t.replace('/','__')+'__'+os.path.basename(sw)
        a=run(os.environ.get('RB','SWFRecomp.before'),sw,S+'/rd/'+k+'/b'); b=run(os.environ.get('RA','SWFRecomp.after'),sw,S+'/rd/'+k+'/a')
        shutil.rmtree(S+'/rd/'+k,ignore_errors=True)
        res.append('FAIL' if 'FAIL' in a+b else ('CHANGED' if a!=b else 'SAME'))
    st='FAIL' if 'FAIL' in res else ('CHANGED' if 'CHANGED' in res else 'SAME')
    return t, st+('' if len(swfs)==1 else ' (%d swfs)'%len(swfs))
tests=[l.split()[0] for l in open(sys.argv[1]) if l.strip() and not l.startswith('#')]
with ThreadPoolExecutor(int(sys.argv[2]) if len(sys.argv)>2 else 3) as ex:
    for t,st in ex.map(one,tests): print(st, t, flush=True)
