# per-cell isotropic stroke width estimate: ink_area / device centreline perimeter
import re, sys, math
from PIL import Image
T_DIR = sys.argv[1]
imgs = sys.argv[2:]
src = open(T_DIR + '/RecompiledTags/draws.c').read()
blk = src[src.index('transform_data['):src.index('color_data')]
nums = [float(x.rstrip('f')) for x in re.findall(r'-?[\d.]+(?:e-?\d+)?f?', blk.split('=', 1)[1])]
T = [nums[i*16:(i+1)*16] for i in range(len(nums)//16)]
main = open(T_DIR + '/RecompiledTags/tagMain.c').read()
pl = re.findall(r'tagPlaceObject2\(app_context, (\d+), CHARID\((\d+)\), (\d+),', main)
rowof = {2: 'NORM', 4: 'NoV', 6: 'NoH', 8: 'both', 10: 'both1'}
wid = {2: 4, 4: 4, 6: 4, 8: 4, 10: 1}
ims = [Image.open(f).convert('RGB') for f in imgs]
W, H = ims[0].size
px = [im.load() for im in ims]
def ink(p, x, y):
    r, g, b = p[x, y]
    return 1 - g / 255.0
cols = {}
rows = []
for depth, ch, tid in pl:
    ch = int(ch); tid = int(tid)
    if ch not in rowof: continue
    m = T[tid]; a, b, c, d, tx, ty = m[0], m[1], m[4], m[5], m[12], m[13]
    pts = [(a*x + c*y + tx, b*x + d*y + ty) for x, y in [(0,0),(640,0),(640,640),(0,640)]]
    pts = [(X/20, Y/20) for X, Y in pts]
    P = sum(math.dist(pts[i], pts[(i+1) % 4]) for i in range(4))
    x0 = int(min(p[0] for p in pts)) - 12; x1 = int(max(p[0] for p in pts)) + 12
    y0 = int(min(p[1] for p in pts)) - 12; y1 = int(max(p[1] for p in pts)) + 12
    x0 = max(x0, 0); y0 = max(y0, 0); x1 = min(x1, W-1); y1 = min(y1, H-1)
    # rule prediction
    vx = a + c; vy = b + d
    s = {'NORM': math.hypot(vx, vy)/math.sqrt(2), 'NoV': abs(vx), 'NoH': abs(vy), 'both': 1, 'both1': 1}[rowof[ch]]
    pred = max(wid[ch]*s, 1)
    est = [sum(ink(p, x, y) for x in range(x0, x1) for y in range(y0, y1)) / P for p in px]
    rows.append((rowof[ch], round(tx/20), 'M=[%.2f %.2f;%.2f %.2f]' % (a, c, b, d), pred, est))
order = ['NORM', 'NoV', 'NoH', 'both', 'both1']
rows.sort(key=lambda r: (order.index(r[0]), r[1]))
print('row   col  M                       rule  ' + '  '.join('img%d' % i for i in range(len(imgs))))
for r in rows:
    print('%-5s %4d %-24s %5.2f ' % r[:4] + '  '.join('%5.2f' % e for e in r[4]))
