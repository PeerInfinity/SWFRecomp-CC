# per-edge stroke width: ink in a strip of length L along each edge midpoint / L
import re, sys, math
from PIL import Image
T_DIR = sys.argv[1]; imgs = sys.argv[2:]
src = open(T_DIR + '/RecompiledTags/draws.c').read()
blk = src[src.index('transform_data['):src.index('color_data')]
nums = [float(x.rstrip('f')) for x in re.findall(r'-?[\d.]+(?:e-?\d+)?f?', blk.split('=', 1)[1])]
T = [nums[i*16:(i+1)*16] for i in range(len(nums)//16)]
main = open(T_DIR + '/RecompiledTags/tagMain.c').read()
pl = re.findall(r'tagPlaceObject2\(app_context, (\d+), CHARID\((\d+)\), (\d+),', main)
rowof = {2: 'NORM', 4: 'NoV', 6: 'NoH', 8: 'both', 10: 'both1'}
wid = {2: 4, 4: 4, 6: 4, 8: 4, 10: 1}
ims = [Image.open(f).convert('RGB') for f in imgs]; px = [im.load() for im in ims]
W, H = ims[0].size
def ink(p, x, y):
    return 1 - p[x, y][1] / 255.0
L = 10; R = 11
rows = []
for depth, ch, tid in pl:
    ch = int(ch); tid = int(tid)
    if ch not in rowof: continue
    m = T[tid]; a, b, c, d, tx, ty = m[0], m[1], m[4], m[5], m[12], m[13]
    pts = [((a*x + c*y + tx)/20, (b*x + d*y + ty)/20) for x, y in [(0,0),(640,0),(640,640),(0,640)]]
    vx = a + c; vy = b + d
    s = {'NORM': math.hypot(vx, vy)/math.sqrt(2), 'NoV': abs(vx), 'NoH': abs(vy), 'both': 1, 'both1': 1}[rowof[ch]]
    pred = max(wid[ch]*s, 1)
    res = []
    for p in px:
        ws = []
        for i in range(4):
            P0 = pts[i]; P1 = pts[(i+1) % 4]
            mx, my = (P0[0]+P1[0])/2, (P0[1]+P1[1])/2
            ln = math.dist(P0, P1); tx_, ty_ = (P1[0]-P0[0])/ln, (P1[1]-P0[1])/ln
            nx, ny = -ty_, tx_
            tot = 0
            for X in range(int(mx-20), int(mx+21)):
                for Y in range(int(my-20), int(my+21)):
                    if not (0 <= X < W and 0 <= Y < H): continue
                    dx, dy = X+0.5-mx, Y+0.5-my
                    s_ = dx*tx_ + dy*ty_; u = dx*nx + dy*ny
                    if abs(s_) <= L/2 and abs(u) <= R:
                        tot += ink(p, X, Y)
            ws.append(tot / L)
        res.append(ws)
    rows.append((rowof[ch], round(tx/20), 'M=[%.2f %.2f;%.2f %.2f]' % (a, c, b, d), pred, res))
order = ['NORM', 'NoV', 'NoH', 'both', 'both1']
rows.sort(key=lambda r: (order.index(r[0]), r[1]))
for r in rows:
    print('%-5s %4d %-24s %5.2f | ' % r[:4] + ' | '.join(' '.join('%5.2f' % w for w in ws) for ws in r[4]))
