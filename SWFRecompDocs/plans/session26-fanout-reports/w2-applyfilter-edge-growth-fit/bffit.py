from bqfit import *
FE=np.asarray(Image.open('/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/visual/filters/blur_fractional/output.expected.png').convert('RGB')).astype(int)[...,0]
def kernf(size,fracmode):
    fs=np.float32(size)
    if not fs>1: return None
    r=(fs-np.float32(1))*np.float32(0.5); mf=np.ceil(r)-np.float32(1)
    fr=float(r-mf)
    if fracmode=='q255': fr=np.floor(fr*255)/255
    if fracmode=='q256': fr=np.floor(fr*256)/256
    if fracmode=='r256': fr=np.floor(fr*256+0.5)/256
    return int(mf), fr, float(fs)
def runF(fracmode,edge,div='fs',opaque=False,tol=0,show=False):
    tot=0;tab=[]
    for row in range(10):
        line=[]
        for col in range(10):
            size=np.float64(row)+np.float64(col)*0.1
            k=kernf(size,fracmode); r=R0.copy(); a=A0.copy()
            if k:
                m,fr,fs=k
                d=fs if div=='fs' else (2*m+1+2*fr)
                md=lambda s,e,m_,f_,fs_: np.floor((s+fr*e)/d+1e-9)
                r=hpass(r,k,md,edge); a=hpass(a,k,md,edge)
                if opaque: a=np.full_like(a,255.0)
            out=np.clip(r+255-a,0,255)
            e=FE[row*80:row*80+80,col*80:col*80+80]
            c=int((np.abs(out-e)>tol).sum()); line.append(c); tot+=c
        tab.append(line)
    if show:
        for l in tab: print(l)
    return tot
for fm in ['exact','q255','q256','r256']:
    for edge in ['clamp','zero']:
        for div in ['fs','wsum']:
            print(fm,edge,div,runF(fm,edge,div),'opaque',runF(fm,edge,div,True))
