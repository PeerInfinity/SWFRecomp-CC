# gate.py LIST TAG [LEGS]: one SWF_KEEP_BUILD_DIR build per row with the patch, then env legs via rerun.
import sys,os,subprocess,shutil,re
S=os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests'); import verify_output as vo
lst,tag=sys.argv[1],sys.argv[2]
ALL=[(k,v.split() if v else []) for k,v in (x.split(':',1) for x in os.environ['GATE_LEGS'].split(';'))]
extra=os.environ.get('GATE_EXTRA','').split()
LEGS=[(n,e+extra) for n,e in ALL]
R='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'
fn=f'{S}/gate_{tag}.txt'; open(fn,'a').close()
done=set(l.split()[0] for l in open(fn) if l.strip()); out=open(fn,'a')
for t in [l.strip() for l in open(lst) if l.strip() and not l.startswith('#')]:
    if t in done: continue
    suite,name=os.path.dirname(t),os.path.basename(t); td=f'{R}/{t}'
    if not os.path.isdir(td): out.write(f'{t} MISSING\n'); out.flush(); continue
    bd=f'{S}/b/{tag}/'+t.replace('/','_'); shutil.rmtree(bd,ignore_errors=True); os.makedirs(bd)
    env=os.environ.copy(); env['SWF_KEEP_BUILD_DIR']=bd; env['SWFRECOMP_COMPILE_TIMEOUT']='2400'
    rec=['--recompile'] if os.environ.get('GATE_RECOMPILE') else []
    subprocess.run(['python3','/home/user/SWFRecomp-CC/ruffle-tests/verify_output.py',f'--tests-dir={R}/{suite}',f'--test={name}','--mode=graphics']+rec,env=env,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL)
    ic=vo.parse_image_comparisons(vo.Path(td)); ic=ic[0] if isinstance(ic,tuple) else ic
    dirs={}
    for ln,e in LEGS:
        m=f'{S}/leg/{tag}_{ln}/'+t.replace('/','_'); shutil.rmtree(m,ignore_errors=True)
        try: subprocess.run(['python3',f'{S}/bin/rerun.py',td,bd,m]+e,stdout=subprocess.DEVNULL,timeout=180)
        except Exception: pass
        dirs[ln]=m
    for cmp,cfg in ic.items():
        exp=f'{td}/{cfg.get("png_name",cmp)}.expected.png'; res={}; md={}
        for ln,_ in LEGS:
            a=f'{dirs[ln]}/{cmp}.png'
            if not os.path.exists(a) or not os.path.exists(exp): res[ln]='NA'; md[ln]=None; continue
            md[ln]=open(a,'rb').read()
            tmp=f'{S}/tmpcmp_{tag}.png'; shutil.copy(a,tmp)
            try:
                p,msg,mx,st=vo.compare_images(tmp,exp,cfg['checks'],config_error=cfg.get('config_error'))
                mm=re.search(r'(\d+) outliers',msg or ''); res[ln]=('P' if p else 'F')+(mm.group(1) if mm else '?')
            except Exception as ex: res[ln]='ERR'
        mv=''.join(k for k,_ in LEGS[1:] if md[k]!=md['M'])
        out.write(f'{t} {cmp} '+' '.join(f'{k}={res[k]}' for k,_ in LEGS)+(' same' if not mv else ' MOVED:'+mv)+'\n'); out.flush()
    for f in os.listdir(bd):
        if f.endswith(('.o','.c','.h','.inc','.a')):
            try: os.remove(os.path.join(bd,f))
            except: pass
