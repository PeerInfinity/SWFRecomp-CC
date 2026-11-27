import sys, os, subprocess, hashlib, pathlib, tempfile, shutil
sys.path.insert(0,'ruffle-tests'); import verify_output as vo
root=pathlib.Path('ruffle-tests/tests/swfs').resolve()
BIN=str(vo.RECOMP_BIN.resolve()); CFG=vo.RECOMP_CONFIG.read_text()
tests=[l.strip() for l in open('/tmp/claude-0/st/nonlow_tests.txt')]+[l.strip() for l in open('/tmp/claude-0/st/trace_tests.txt')]
def run(swf,tol):
    with tempfile.TemporaryDirectory() as td:
        td=pathlib.Path(td); shutil.copy2(swf,td/'test.swf')
        (td/'config.toml').write_text(CFG.replace('output_scripts_folder = "RecompiledScripts"','output_scripts_folder = "RecompiledScripts"\nchild_movie = true'))
        env=dict(os.environ); env['SWFRECOMP_CURVE_TOL_TWIPS']=tol
        subprocess.run([BIN,str(td/'config.toml')],cwd=td,env=env,capture_output=True,timeout=300)
        h=hashlib.md5()
        for sub in ('RecompiledTags','RecompiledScripts'):
            for f in sorted((td/sub).rglob('*')) if (td/sub).exists() else []:
                if f.is_file(): h.update(f.name.encode()); h.update(f.read_bytes())
        return h.hexdigest()
for t in tests:
    d=root/t
    kids=[p for p in d.rglob('*.swf') if p.name!='test.swf' and 'Recompiled' not in str(p)]
    for k in kids:
        if run(k,'2')!=run(k,'0.2'): print("CHANGED",t,k.relative_to(d),flush=True)
print("done")
