import math
import numpy as np
r=math.radians(30)
fields={'rot90':(0,1,-1,0,1400,200),'rot30':(math.cos(r),math.sin(r),-math.sin(r),math.cos(r),2200,600),'shear':(1,0,0.5,1,200,2600)}
def labels(H=200,W=200):
    lab=np.full((H,W),'bg',dtype=object)
    for name,(a,b,c,dd,tx,ty) in fields.items():
        det=a*dd-b*c
        for y in range(H):
            for x in range(W):
                X=(x+0.5)*20-tx; Y=(y+0.5)*20-ty
                lx=( dd*X - c*Y)/det; ly=(-b*X + a*Y)/det
                if -40<=lx<=1440 and -40<=ly<=1140:
                    dist=min(abs(lx),abs(lx-1400),abs(ly),abs(ly-1100))
                    inside=(0<lx<1400 and 0<ly<1100)
                    lab[y,x]=name+(':border' if dist<=30 else (':glyphs' if inside else ':out'))
    return lab
