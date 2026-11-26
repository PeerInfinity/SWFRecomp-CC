exec(open('full.py').read())
from matplotlib.path import Path
def raster_grid(polys,N=4,phy=0.0,phx=0.5,H=200,W=200):
    sy=(np.arange(H)[:,None]+(np.arange(N)+phy)[None,:]/N).reshape(-1)
    sx=(np.arange(W)[:,None]+(np.arange(N)+phx)[None,:]/N).reshape(-1)
    YY,XX=np.meshgrid(sy,sx,indexing='ij'); pts=np.c_[XX.ravel(),YY.ravel()]
    ink=np.zeros(len(pts),bool)
    for p in polys: ink|=Path(p).contains_points(pts)
    return ink.reshape(H,N,W,N).sum(axis=(1,3))
