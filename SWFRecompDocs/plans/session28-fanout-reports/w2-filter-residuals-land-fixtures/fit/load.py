import math,collections
R='/home/user/SWFRecomp-CC/SWFRecompDocs/plans/session28-fanout-reports/'
FL=R+'w1-local-oracles/w1-filter-residuals/avm2_bevel_sample_isolation_probe.flash32.txt'
OU=R+'w1-filter-residuals-fixtures/avm2_bevel_sample_isolation_probe/output.txt'
def load(p):
    d=collections.defaultdict(dict)
    for l in open(p).read().splitlines():
        if ' y=' not in l: continue
        lab,rest=l.split(' y=');y,px=rest.split(':',1)
        d[lab][int(y)]=[int(v,16) for v in px.split()]
    return d
def grid(d,lab):
    g=d[lab]; return [g[y] for y in range(len(g))]
def dval(p):
    a=p>>24
    if a==0: return 0
    return a if ((p>>16)&0xff)>=0x80 else -a
