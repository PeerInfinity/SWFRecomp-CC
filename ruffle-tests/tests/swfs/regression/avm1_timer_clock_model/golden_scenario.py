"""Prints the avm1_timer_clock_model trace under three timer models (ruffle =
core/src/timer.rs incl. std BinaryHeap tie order -> output.txt; ours_new = this
patch; ours_old = pre-patch processTimers). Usage: python3 golden_scenario.py"""
import sys; import os; sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ruffle_timer_sim import run
def V(p,k,d=0): return p.vars.get(k,d)
def fz(p):
    p.vars['zn']=V(p,'zn')+1; p.trace('z%d f%d'%(p.vars['zn'],p.frame))
    if p.vars['zn']==3: p.clear(p.vars['z'])
def fa(p):
    p.vars['an']=V(p,'an')+1; p.trace('a%d f%d'%(p.vars['an'],p.frame))
    if p.vars['an']==4: p.clear(p.vars['a'])
def fn2(p): p.trace('n f%d'%p.frame)
def fb(p):
    p.trace('b f%d'%p.frame); p.add(fn2,0,True)
def fe(p): p.trace('e f%d'%p.frame)
def fc(p): p.vars['cnt']=V(p,'cnt')+1
def F1(p): p.trace('F1'); p.vars['z']=p.add(fz,0,False)
def F2(p):
    p.trace('F2'); p.vars['a']=p.add(fa,30,False); p.add(fb,20,True); p.add(fe,100,True)
def F3(p): p.trace('F3')
def F4(p):
    p.trace('F4'); p.vars['cnt']=0; p.vars['c1']=p.add(fc,10,False); p.vars['c2']=p.add(fc,13,False)
def Fcnt(n,clear=False):
    def f(p):
        p.trace('F%d cnt=%d'%(n,V(p,'cnt'))); p.vars['cnt']=0
        if clear: p.clear(p.vars['c1']); p.clear(p.vars['c2'])
    return f
frames={1:F1,2:F2,3:F3,4:F4,5:Fcnt(5),6:Fcnt(6),7:Fcnt(7,True),8:Fcnt(8),9:lambda p:p.trace('F9 end')}
for m in ['ruffle','ours_new','ours_old']:
    o=run(m,frames,9)
    print('==',m); print('\n'.join(o))
