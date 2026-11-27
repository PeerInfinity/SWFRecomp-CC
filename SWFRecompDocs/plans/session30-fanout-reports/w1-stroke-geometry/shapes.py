import re
def load(path='/tmp/claude-0/sp/dump2.txt'):
    shapes=[]; cur=None
    for ln in open(path):
        if not ln.startswith('GFXD'): continue
        t=ln.split()
        if t[1]=='ls':
            cur={'w':float(t[2]),'col':int(t[3],16),'cmds':[],'tx':None,'ty':None}; shapes.append(cur)
        elif t[1]=='mv': cur['cmds'].append(('M',float(t[2]),float(t[3])))
        elif t[1]=='ln': cur['cmds'].append(('L',float(t[2]),float(t[3])))
        elif t[1]=='bf': cur and cur.setdefault('fill',int(t[2],16))
        elif t[1]=='cv': cur['cmds'].append(('Q',float(t[2]),float(t[3]),float(t[4]),float(t[5])))
        elif t[1]=='sx': cur['tx']=int(t[2])/20
        elif t[1]=='sy': cur['ty']=int(t[2])/20
    return shapes
if __name__=='__main__':
    S=load(); sq=[s for s in S if any(c[0]=='Q' for c in s['cmds'])]
    print(len(S),len(sq))
    for s in sq[:5]: print(s)
    print(min(s['ty'] for s in sq), max(s['ty'] for s in sq))
