def glyph_polys(fname, q=0, dx=0, dy=0):
    a,b,c,d,tx,ty=M[fname]
    out=[]
    for gx in (140,640):
        loc=[(gx,140),(gx+300,140),(gx+300,840),(gx,840)]
        P=[((a*x+c*y+tx)/20+dx,(b*x+d*y+ty)/20+dy) for x,y in loc]
        if q: P=[(round(x/q)*q,round(y/q)*q) for x,y in P]
        out.append(P)
    return out
