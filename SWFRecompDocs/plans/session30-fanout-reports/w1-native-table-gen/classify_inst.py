import sys, re, collections
def parse(p):
    blocks=collections.OrderedDict(); cur=None
    for l in open(p).read().split('\n'):
        m=re.match(r'^(\S.*?), instance=\[(.*)\], type=\[(.*)\]$', l)
        if m:
            k=m.group(1); i=2
            while k in blocks: k=f"{m.group(1)}#{i}"; i+=1
            cur=k; blocks[cur]={'hdr':(m.group(2),m.group(3)),'m':[]}
        elif l.startswith('  ') and cur:
            mm=re.match(r'  (.*?)((?:, own)?(?:, DONT_ENUM)?(?:, READ_ONLY)?(?:, DONT_DELETE)?), type=\[(.*)\]$', l)
            if mm: blocks[cur]['m'].append((mm.group(1),mm.group(2),mm.group(3)))
    return blocks
E=parse(sys.argv[1]); A=parse(sys.argv[2]); H=collections.Counter(); ex=collections.defaultdict(list)
def note(c,s):
    H[c]+=1
    if len(ex[c])<8: ex[c].append(s)
for k,b in E.items():
    if k not in A: note('instance_missing',k); continue
    a=A[k]
    if a['hdr']!=b['hdr']: note('header(value/typeof) differs',f"{k}: {b['hdr']} vs {a['hdr']}")
    ed={x[0]:x for x in b['m']}; ad={x[0]:x for x in a['m']}
    for n,f,t in b['m']:
        if n not in ad: note('member_missing',f"{k}.{n}"); continue
        _,af,at=ad[n]
        for fl in ('own','DONT_ENUM','READ_ONLY','DONT_DELETE'):
            if ((', '+fl) in f)!=((', '+fl) in af): note(f"flag_{fl}_{'missing' if (', '+fl) in f else 'extra'}",f"{k}.{n}")
        if t!=at: note(f"type:{t}<-{at}",f"{k}.{n}")
    for n,f,t in a['m']:
        if n not in ed: note('member_extra' + (':__proto__/__constructor__' if n in ('__proto__','__constructor__') else ''),f"{k}.{n}")
    ek=[x[0] for x in b['m'] if x[0] in ad]; ak=[x[0] for x in a['m'] if x[0] in ed]
    if ek!=ak: note('order_block',k)
for k in A:
    if k not in E: note('instance_extra',k)
for k,v in H.most_common(): print(f"{v:6d} {k}")
if '--detail' in sys.argv:
    for k in ex: print('---',k); [print('   ',s) for s in ex[k]]
