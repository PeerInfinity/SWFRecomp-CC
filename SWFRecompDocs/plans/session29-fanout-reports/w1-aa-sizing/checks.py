import json,sys,glob,os
S='/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad'
legs=sys.argv[1:]
files=sorted(glob.glob(f'{S}/res/{legs[-1]}/*.json'))
for f in files:
    slug=os.path.basename(f)[:-5]
    rows={}
    for leg in legs:
        p=f'{S}/res/{leg}/{slug}.json'
        if not os.path.exists(p): continue
        for t in json.load(open(p))['tests']:
            for c,r in (t.get('image_comparisons') or {}).items():
                st=r.get('stats',{})
                rows.setdefault(c,[]).append((leg,r['status'],st.get('max_diff'),[(k['tolerance'],k['max_outliers'],k['outliers']) for k in st.get('checks',[])]))
    for c,v in rows.items():
        print(slug,c,' | '.join(f"{l}:{s} max{m} "+' '.join(f"t{a}:{o}/{b}" for a,b,o in ck) for l,s,m,ck in v))
