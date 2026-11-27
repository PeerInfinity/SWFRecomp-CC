import json,glob,os,sys
S='/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad'
base={}
for l in open(S+'/allrows.tsv'):
    t,c,st,o,mo,tol,md,q,v,kf=l.rstrip('\n').split('\t'); base[(t,c)]=dict(st=st,o=o,mo=mo,q=q,v=v,kf=kf)
def leg(name):
    out={}
    for f in glob.glob(f'{S}/res/{name}/*.json'):
        d=json.load(open(f))
        for t in d['tests']:
            for c,r in (t.get('image_comparisons') or {}).items():
                st=r.get('stats',{})
                out[(os.path.basename(f)[:-5],c)]=(r['status'],st.get('outliers'),st.get('max_outliers'),st.get('tolerance'),st.get('max_diff'),st.get('diff_channels'))
    return out
sc=leg(sys.argv[1] if len(sys.argv)>1 else 'scF'); fl=leg('fl')
rows=[]
for (t,c),b in sorted(base.items()):
    k=(t.replace('/','_'),c)
    if k not in sc: continue
    s=sc[k]; f=fl.get(k)
    fl_st=f[0] if f else '-'
    rows.append((t,c,b['st'],b['o'],b['mo'],s[0],s[1],s[2],s[3],s[4],fl_st,b['v'],b['kf'],b['q']))
for r in rows: print('\t'.join(map(str,r)))
