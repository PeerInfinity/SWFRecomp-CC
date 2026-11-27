# rerun.py TESTDIR BUILDDIR OUTDIR [K=V ...] : re-execute test_run, write PNGs to OUTDIR
import sys,os,subprocess
sys.path.insert(0,'/home/user/SWFRecomp-CC/ruffle-tests')
import verify_output as vo
td,bd,od=sys.argv[1:4]; os.makedirs(od,exist_ok=True)
ic=vo.parse_image_comparisons(vo.Path(td))
if isinstance(ic,tuple): ic=ic[0]
tr=[]
for n,c in ic.items():
    t=c['trigger']
    if t[0]=='last_frame': tr.append(f'{n}:last_frame')
    elif t[0]=='specific_iteration': tr.append(f'{n}:iteration:{t[1]}')
    elif t[0]=='fs_command': tr.append(f'{n}:fs_command')
env=os.environ.copy(); env.setdefault('TZ','NPT-5:45')
env.update(CAPTURE_TRIGGERS=','.join(tr),CAPTURE_OUTPUT_DIR=od,VK_ICD_FILENAMES='/usr/share/vulkan/icd.d/lvp_icd.json',VK_DRIVER_FILES='/usr/share/vulkan/icd.d/lvp_icd.json')
for kv in sys.argv[4:]:
    k,v=kv.split('=',1); env[k]=v
cmd=[os.path.join(bd,'test_run')]
ev=os.path.join(bd,'input_events.txt')
if os.path.exists(ev): cmd.append(ev)
subprocess.run(cmd,env=env,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL,timeout=60)
print(' '.join(sorted(os.listdir(od))))
