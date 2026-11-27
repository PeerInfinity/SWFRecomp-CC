import json,sys,glob,os
S='/tmp/claude-0/-home-user-SWFRecomp-CC/7c6fbc93-ebf2-5450-8840-6b914ee464a6/scratchpad'
leg=sys.argv[1]
for f in sorted(glob.glob(f'{S}/res/{leg}/*.json')):
    d=json.load(open(f))
    for t in d['tests']:
        for c,r in (t.get('image_comparisons') or {}).items():
            st=r.get('stats',{})
            print('\t'.join(map(str,[os.path.basename(f)[:-5],c,r['status'],st.get('outliers'),st.get('max_outliers'),st.get('tolerance'),st.get('max_diff'),st.get('diff_channels')])))
