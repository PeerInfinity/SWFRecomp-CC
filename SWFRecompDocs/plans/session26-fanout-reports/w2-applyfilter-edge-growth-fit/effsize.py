exec(open('bffit.py').read().split('for fm in')[0])
def cellerr(row,col,eff,tol=0):
    k=kernf(eff,'exact')
    e=FE[row*80:row*80+80,col*80:col*80+80]
    if not k: out=R0
    else:
        m,fr,fs=k
        md=lambda s,e_,m_,f_,fs_: np.floor((s+fr*e_)/fs+1e-9)
        out=hpass(R0.copy(),k,md,'zero')
    return int((np.abs(out-e)>tol).sum())
for row in range(1,10):
    line=[]
    for col in range(10):
        size=row+col*0.1
        cands=np.round(np.arange(max(1.0,size-0.6),size+0.61,0.025),4)
        errs=[(cellerr(row,col,c),c) for c in cands]
        best=min(errs)
        line.append(f'{size:.1f}->{best[1]:.3f}({best[0]})')
    print(' '.join(line))

def q6(size):
    if size<=0: return size
    e=np.floor(np.log2(size)); step=2.0**(e-5)
    return np.floor(size/step+1e-9)*step
