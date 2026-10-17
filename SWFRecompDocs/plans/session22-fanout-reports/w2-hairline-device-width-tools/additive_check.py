import sys, os, subprocess, shutil, glob, re, hashlib
from concurrent.futures import ThreadPoolExecutor
ROOT='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'; CFG='/home/user/SWFRecomp-CC/ruffle-tests/_shared/config.toml'
def gen(b,sw,wd):
    shutil.rmtree(wd,ignore_errors=True); os.makedirs(wd); shutil.copy(sw,wd+'/test.swf')
    subprocess.run(['bash','-c','ulimit -v 4194304; exec "$@"','--',b,CFG],cwd=wd,capture_output=True,timeout=900)
    h=hashlib.md5()
    for f in sorted(glob.glob(wd+'/Recompiled*/**/*',recursive=True)):
        if not os.path.isfile(f): continue
        t=open(f,'rb').read()
        if f.endswith('draws.c'):
            t=re.sub(rb'\nu32 stroke_run_count = \d+;\nu32 stroke_run_data\[.*?\n\};\nu32 stroke_centre_data\[.*?\n\};\n',b'\n',t,flags=re.S).replace(b'};\n\n\nu32 bitmap_descs',b'};\n\nu32 bitmap_descs')
        h.update(f[len(wd):].encode()); h.update(t)
    shutil.rmtree(wd,ignore_errors=True); return h.hexdigest()
def one(t):
    r=[]
    for sw in sorted(glob.glob(os.path.join(ROOT,t,'*.swf'))):
        k='/root/scan/ao/'+t.replace('/','_')+os.path.basename(sw)
        r.append(gen('/root/SWFRecomp.master',sw,k+'m')==gen('/root/SWFRecomp.after',sw,k+'a'))
    return t,all(r)
with ThreadPoolExecutor(4) as ex:
    for t,ok in ex.map(one,[l.strip() for l in open(sys.argv[1]) if l.strip()]): print('SAME' if ok else 'DIFF',t,flush=True)
