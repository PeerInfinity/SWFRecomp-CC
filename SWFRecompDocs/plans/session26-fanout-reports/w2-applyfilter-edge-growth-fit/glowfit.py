from flashblur import *
import sys
P=8
specs={4:('glow',-15,-15,{}),5:('ds',-10,-10,dict(bx=4,by=4,strength=1.0,color=(0,0,0))),
       6:('bevel',-10,-10,dict(bx=4,by=4,strength=1.0,color=(0,0,0))),12:('glow',-10,-10,{}),
       13:('ds',-10,-10,dict(bx=4,by=4,strength=1.0,color=(0,0,0)))}
for i,(k,dx,dy,kw) in specs.items():
    for om in ['floor','round']:
        o=glowlike(k,P,offmode=om,**kw)
        print(i,k,om,score(composite(place(o,dx-P,dy-P),i),i), 'nogrow', score(composite(place(o[P:P+100,P:P+100],dx,dy),i),i))
