"""Simulator of timer models for the avm1_timer_clock_model fixture.
model='ruffle'  : core/src/timer.rs incl. std BinaryHeap tie order
model='ours_new': id-ordered ties (the patch)
model='ours_old': origin/master processTimers (elapsed>=delay, slot order, 0-delay fires once)
"""
import sys
FPS=10
FRAME_MS=1000.0/FPS

class RHeap:  # Rust std BinaryHeap (max-heap on key; key = -tick)
    def __init__(s): s.d=[]
    def gt(s,a,b): return a['tick']<b['tick']   # a > b in reversed ord
    def le(s,a,b): return not s.gt(a,b)
    def sift_up(s,start,pos):
        el=s.d[pos]
        while pos>start:
            par=(pos-1)//2
            if s.le(el,s.d[par]): break
            s.d[pos]=s.d[par]; pos=par
        s.d[pos]=el; return pos
    def sift_down_range(s,pos,end):
        el=s.d[pos]; child=2*pos+1
        while child<=end-2 if end>=2 else False:
            child+= 1 if s.le(s.d[child],s.d[child+1]) else 0
            if not s.gt(s.d[child],el) and True:
                # hole.element() >= hole.get(child) -> return
                if not s.gt(s.d[child],el): s.d[pos]=el; return
            s.d[pos]=s.d[child]; pos=child; child=2*pos+1
        if child==end-1 and s.gt(s.d[child],el):
            s.d[pos]=s.d[child]; pos=child
        s.d[pos]=el
    def push(s,x): s.d.append(x); s.sift_up(0,len(s.d)-1)
    def peek(s): return s.d[0] if s.d else None
    def pop(s):
        item=s.d.pop()
        if s.d:
            item,s.d[0]=s.d[0],item
            # sift_down_to_bottom(0)
            end=len(s.d); pos=0; el=s.d[0]; child=1
            while end>=2 and child<=end-2:
                child+= 1 if s.le(s.d[child],s.d[child+1]) else 0
                s.d[pos]=s.d[child]; pos=child; child=2*pos+1
            if child==end-1: s.d[pos]=s.d[child]; pos=child
            s.d[pos]=el
            s.sift_up(0,pos)
        return item
    def peek_mut_done(s): s.sift_down_range(0,len(s.d))
    def retain(s,f):
        n=len(s.d); rb=n; i=0; nd=[]
        for e in s.d:
            if not f(e) and i<rb: rb=i
            elif f(e): nd.append(e)
            i+=1
        s.d=nd
        if rb==len(s.d): return
        tail=len(s.d)-rb
        import math
        if rb<tail: better=True
        else: better= 2*len(s.d) < tail*int(math.log2(rb))
        if better:
            k=len(s.d)//2
            while k>0:
                k-=1; s.sift_down_range(k,len(s.d))
        else:
            for j in range(rb,len(s.d)): s.sift_up(0,j)
    def __len__(s): return len(s.d)
    def ids(s): return [t['id'] for t in s.d]

class Player:
    def __init__(s,model):
        s.model=model; s.cur=0; s.nid=0; s.out=[]; s.vars={}
        s.heap=RHeap(); s.list=[]   # list for ours models (slot order)
        s.frame=0
    def add(s,cb,delay,timeout):
        s.nid+=1; i=s.nid
        if s.model=='ours_old':
            s.list.append(dict(id=i,cb=cb,delay=float(delay),el=0.0,timeout=timeout))
        else:
            iv=max(int(delay),10)*1000
            t=dict(id=i,cb=cb,tick=s.cur+iv,iv=iv,timeout=timeout)
            if s.model=='ruffle': s.heap.push(t)
            else: s.list.append(t)
        return i
    def clear(s,i):
        if s.model=='ruffle': s.heap.retain(lambda t:t['id']!=i)
        else: s.list=[t for t in s.list if t['id']!=i]
    def update(s):
        if s.model=='ours_old':
            for t in s.list: t['el']+=FRAME_MS
            lim=10000
            while True:
                lim-=1
                if lim<=0: break
                fired=False
                for t in list(s.list):
                    if t not in s.list: continue
                    if t['el']<t['delay']: continue
                    t['cb'](s); fired=True
                    if t in s.list:
                        if not t['timeout']:
                            t['el']-=t['delay']
                            if t['delay']<=0: s.list.remove(t)
                        else: s.list.remove(t)
                    break
                if not fired: break
            return
        s.cur+=int(FRAME_MS*1000)
        ticks=0
        while True:
            if s.model=='ruffle':
                t=s.heap.peek()
            else:
                t=min(s.list,key=lambda x:(x['tick'],x['id'])) if s.list else None
            if t is None or not (t['tick']<s.cur): break
            ticks+=1
            if ticks>10: s.cur=t['tick']-100; break
            eid=t['id']; t['cb'](s)
            if s.model=='ruffle':
                if not len(s.heap): break
                top=s.heap.peek()
                if top['id']==eid:
                    if top['timeout']: s.heap.pop()
                    else: top['tick']+=top['iv']; s.heap.peek_mut_done()
            else:
                if t in s.list:
                    if t['timeout']: s.list.remove(t)
                    else: t['tick']+=t['iv']
    def trace(s,x): s.out.append(x)

def run(model, frames, nframes):
    p=Player(model)
    for f in range(1,nframes+1):
        p.frame=f
        if f in frames: frames[f](p)
        p.update()
    return p.out
