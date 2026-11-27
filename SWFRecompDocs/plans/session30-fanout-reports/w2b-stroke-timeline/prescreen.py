import sys, os, subprocess, hashlib, pathlib, time, json, shutil
root = pathlib.Path('ruffle-tests/tests/swfs').resolve()
BIN = pathlib.Path('SWFRecomp/build/SWFRecomp').resolve()
CFG = pathlib.Path('ruffle-tests/_shared/config.toml').resolve()
legs = {'base': {}, 'shape': {'SWFRECOMP_CURVE_TOL_TWIPS': '0.2'}, 'font': {'SWFRECOMP_CURVE_TOL_TWIPS_FONT': '0.2'}}
if os.environ.get('LEGS2'): legs.pop('font')
tests = [l.strip() for l in open(sys.argv[1]) if l.strip()]
out = {}
for t in tests:
    d = root / t
    res = {}
    for leg, extra in legs.items():
        env = dict(os.environ); env.update(extra)
        for sub in ("RecompiledScripts", "RecompiledTags", "RecompiledABC"):
            shutil.rmtree(d / sub, ignore_errors=True)
        t0 = time.time()
        p = subprocess.run([str(BIN), str(CFG)], cwd=d, env=env, capture_output=True, timeout=600)
        dt = time.time() - t0
        h = hashlib.md5(); size = 0; dsize = 0
        for sub in ("RecompiledTags", "RecompiledScripts"):
            for f in sorted((d / sub).rglob('*')) if (d / sub).exists() else []:
                if f.is_file() and f.name != '.recomp_mode':
                    b = f.read_bytes(); h.update(f.name.encode()); h.update(b); size += len(b)
                    if f.name == 'draws.c': dsize = len(b)
        caps = p.stderr.count(b'LEVIEN_CAP')
        res[leg] = dict(md5=h.hexdigest(), size=size, draws=dsize, t=round(dt, 2), rc=p.returncode)
    out[t] = res
    print(t, res['base']['md5'] != res['shape']['md5'], res.get('font',res['base'])['md5'] != res['base']['md5'],
          res['base']['draws'], res['shape']['draws'], res['base']['t'], res['shape']['t'], flush=True)
json.dump(out, open(sys.argv[2], 'w'), indent=1)
