import json,subprocess,sys
old,new=sys.argv[1:3]
def load(ref):
    files=subprocess.run(['git','ls-tree','-r','--name-only',ref,'ruffle-tests/tests/swfs'],capture_output=True,text=True).stdout.split()
    out={}
    for f in files:
        if not f.endswith('/_results/results.json'): continue
        suite=f.split('/')[3]
        d=json.loads(subprocess.run(['git','show',f'{ref}:{f}'],capture_output=True,text=True).stdout)
        tests=d.get('tests',d) if isinstance(d,dict) else d
        it=tests.items() if isinstance(tests,dict) else [(t.get('test'),t) for t in tests]
        for n,t in it:
            out[f'{suite}/{n}']=t.get('status') if isinstance(t,dict) else t
    return out
a,b=load(old),load(new)
eff={'pass','ruffle_matched'}
for k in sorted(set(a)&set(b)):
    if a[k]!=b[k]: print(f'{a[k]:>16} -> {b[k]:<16} {k}')
