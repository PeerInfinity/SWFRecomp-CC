"""Flash quality=LOW gradient paint model evaluator (s28 lowq-corner-rule)."""
import sys, json, math, numpy as np
from PIL import Image
def comp(p, g):
    pa,pb,pc,pd,ptx,pty=p; ga,gb,gc,gd,gtx,gty=g
    return (pa*ga+pc*gb,pb*ga+pd*gb,pa*gc+pc*gd,pb*gc+pd*gd,pa*gtx+pc*gty+ptx,pb*gtx+pd*gty+pty)
def snap(v, mode):
    return {'none': v, 'round': math.floor(v + 0.5), 'floor': math.floor(v), 'rhalfdown': math.ceil(v - 0.5)}[mode]
def predict(c, xs, ys, psnap='round', tscale=255/256, lin_bias=-0.002, rad_bias=0.5):
    pl = list(c['place_px']); pl[4] = snap(pl[4], psnap); pl[5] = snap(pl[5], psnap)
    gl = list(c['grad_px'])
    if c.get('spread', 0): gl[4] *= tscale; gl[5] *= tscale
    a,b,cc,d,tx,ty = comp(pl, gl); det = a*d-b*cc
    dx = xs - tx; dy = ys - ty
    gx = (d*dx - cc*dy)/det; gy = (-b*dx + a*dy)/det
    if c['kind'] == 'linear': u = (gx + 16384)/32768*256; j = np.floor(u + lin_bias)
    else: u = np.sqrt(gx*gx+gy*gy)/16384*256; j = np.floor(u + rad_bias)
    sp = c.get('spread', 0)
    if sp == 1: j = np.mod(j, 512); j = np.where(j > 255, 511 - j, j)
    elif sp == 2: j = np.mod(j, 256)
    return np.clip(j, 0, 255)
if __name__ == '__main__':
    f = np.asarray(Image.open(sys.argv[1]).convert('L')).astype(int)
    cells = json.load(open(sys.argv[2]))
    modes = sys.argv[3].split(',') if len(sys.argv) > 3 else ['none', 'round', 'floor']
    tot = {m: 0 for m in modes}
    for c in cells:
        if c['kind'] == 'focal' or len(c['stops']) != 2 or 'place_px' not in c: continue
        x0, y0 = c['col']*40 + 7, c['row']*40 + 7
        ys, xs = np.mgrid[y0:y0+26, x0:x0+26]
        if abs(c['place_px'][1]) > 1e-6: ys, xs = np.mgrid[y0+4:y0+22, x0+4:x0+22]
        v = f[ys, xs]
        res = []
        for m in modes:
            k = predict(c, xs, ys, psnap=m)
            n = int((k != v).sum()); tot[m] += n
            res.append(f'{m}:{n}')
        print(f"{c['name']:18s} {v.size:4d}  " + '  '.join(res))
    print('TOTAL', tot)
