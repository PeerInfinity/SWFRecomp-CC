import json,subprocess,sys
ref,stem=sys.argv[1],sys.argv[2]
files=subprocess.run(['git','ls-tree','-r','--name-only',ref],capture_output=True,text=True).stdout.split()
out={}
for f in files:
    if f.endswith('_results/%s.json'%stem):
        suite=f.split('/_results')[0].split('swfs/')[1]
        d=json.loads(subprocess.run(['git','show',f'{ref}:{f}'],capture_output=True,text=True).stdout)
        res=d.get('tests',d.get('results',d))
        it=res.items() if isinstance(res,dict) else [(x.get('test') or x.get('name'),x) for x in res]
        for k,v in it:
            if isinstance(v,dict) and 'status' in v: out[suite+'/'+k]=v['status']
json.dump(out,sys.stdout)
