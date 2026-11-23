import numpy as np,sys
from PIL import Image
T='/home/user/SWFRecomp-CC/ruffle-tests/tests/swfs/visual/filters/blur_quality/'
E=np.asarray(Image.open(T+'output.expected.png').convert('RGB')).astype(int)[...,0]
S=np.asarray(Image.open(T+'image.png').convert('RGBA')).astype(int)
R0=S[...,0].astype(float); A0=S[...,3].astype(float)
def kern(size):
    fs=np.float32(size)
    if not fs>1: return None
    r=(fs-np.float32(1))*np.float32(0.5); mf=np.ceil(r)-np.float32(1)
    return int(mf), float(r-mf), float(fs)
def hpass(a,k,mode,edge='clamp'):
    m,frac,fs=k
    n=a.shape[1]
    if edge=='clamp': pad=np.concatenate([np.repeat(a[:,:1],m+1,1),a,np.repeat(a[:,-1:],m+1,1)],1)
    else: pad=np.concatenate([np.zeros((a.shape[0],m+1)),a,np.zeros((a.shape[0],m+1))],1)
    s=np.zeros_like(a)
    for t in range(-m,m+1): s=s+pad[:,m+1+t:m+1+t+n]
    e=pad[:,0:n]+pad[:,2*m+2:2*m+2+n]
    return mode(s,e,m,frac,fs)
modes={
 'ruffleq': lambda s,e,m,fr,fs: np.floor((255*s+np.floor(fr*255)*e)/(255*fs)),
 'unq_floor': lambda s,e,m,fr,fs: np.floor((s+fr*e)/fs+1e-9),
}
def run(mode,edge='clamp',tol=0,verbose=False):
    tot=0; table=[]
    for row in range(10):
        line=[]
        for col in range(10):
            k=kern(row); r=R0.copy(); a=A0.copy()
            if k:
                for _ in range(col): r=hpass(r,k,mode,edge); a=hpass(a,k,mode,edge)
            out=np.clip(r+255-a,0,255)
            e=E[row*80:row*80+80,col*80:col*80+80]
            c=int((np.abs(out-e)>tol).sum()); line.append(c); tot+=c
        table.append(line)
    if verbose:
        for l in table: print(l)
    return tot
if __name__=='__main__':
    for name,md in modes.items():
        print(name, run(md), run(md,tol=1))
