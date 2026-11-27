# gate2.py LIST TAG : build once (all prototypes on), grade legs M (all off), L (tsnap-local only), P (all on)
import sys,os,subprocess,shutil,re
S='/tmp/claude-0/-home-user-SWFRecomp-CC/870fe2e7-0bcb-5076-b47c-a792697b7708/scratchpad'
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests'); import verify_output as vo
lst,tag=sys.argv[1],sys.argv[2]
LEGS=[('M',['SWF_LOWQ_TSNAP_LOCAL=0','SWF_LOWQ_TIE_EPS=0','SWF_TF_LOW_PEN_HALFUP=0']),('L',['SWF_LOWQ_TIE_EPS=0','SWF_TF_LOW_PEN_HALFUP=0']),('Y',['SWF_LOWQ_TSNAP_LOCAL=0','SWF_TF_LOW_PEN_HALFUP=0']),('H',['SWF_LOWQ_TSNAP_LOCAL=0','SWF_LOWQ_TIE_EPS=0'])]
R='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs'
fn=f'{S}/gate_{tag}.txt'; open(fn,'a').close()
done=set(l.split()[0] for l in open(fn) if l.strip()); out=open(fn,'a')
for t in [l.strip() for l in open(lst) if l.strip()]:
    if t in done: continue
    suite,name=os.path.dirname(t),os.path.basename(t); td=f'{R}/{t}'
    if not os.path.isdir(td): out.write(f'{t} MISSING\n'); out.flush(); continue
    subprocess.run([f'{S}/bin/rt.sh',suite,name,tag],stdout=subprocess.DEVNULL)
    bd=f'{S}/b/{tag}/'+t.replace('/','_')
    ic=vo.parse_image_comparisons(vo.Path(td)); ic=ic[0] if isinstance(ic,tuple) else ic
    dirs={}
    for ln,env in LEGS:
        m=f'{S}/leg/{tag}_{ln}/'+t.replace('/','_'); shutil.rmtree(m,ignore_errors=True)
        try: subprocess.run(['python3',f'{S}/bin/rerun.py',td,bd,m]+env,stdout=subprocess.DEVNULL,timeout=120)
        except Exception: pass
        dirs[ln]=m
    dirs['P']=bd
    for cmp,cfg in ic.items():
        exp=f'{td}/{cfg.get("png_name",cmp)}.expected.png'; res={}; md={}
        for ln in ('M','L','Y','H','P'):
            a=f'{dirs[ln]}/{cmp}.png'
            if not os.path.exists(a) or not os.path.exists(exp): res[ln]='NA'; md[ln]=None; continue
            md[ln]=open(a,'rb').read()
            tmp=f'{S}/tmpcmp_{tag}.png'; shutil.copy(a,tmp)
            try:
                p,msg,mx,st=vo.compare_images(tmp,exp,cfg['checks'],config_error=cfg.get('config_error'))
                mm=re.search(r'(\d+) outliers',msg or ''); res[ln]=('P' if p else 'F')+(mm.group(1) if mm else '?')
            except Exception: res[ln]='ERR'
        mv=''.join(k for k in ('L','Y','H','P') if md[k]!=md['M'])
        out.write(f'{t} {cmp} M={res["M"]} L={res["L"]} Y={res["Y"]} H={res["H"]} P={res["P"]} {"same" if not mv else "MOVED:"+mv}\n'); out.flush()
    for f in os.listdir(bd):
        if f.endswith(('.o','.c','.h','.inc')):
            try: os.remove(os.path.join(bd,f))
            except: pass
