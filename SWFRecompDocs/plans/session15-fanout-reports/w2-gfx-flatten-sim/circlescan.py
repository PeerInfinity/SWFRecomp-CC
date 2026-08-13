import math, sys
sys.path.insert(0, __import__("os").path.dirname(__file__) or ".")
from lyonsim2 import lyon_ts, sample

CX, CY, R = 50.0, 50.0, 40.0
N = 8
kct = 1.0 / math.cos(math.pi / N)

def quads():
    out = []
    px, py = CX + R, CY
    for i in range(N):
        a0 = 2*math.pi*i/N; a1 = 2*math.pi*(i+1)/N; am = (a0+a1)*0.5
        ex, ey = CX + R*math.cos(a1), CY + R*math.sin(a1)
        cx, cy = CX + R*kct*math.cos(am), CY + R*kct*math.sin(am)
        out.append(((px, py), (cx, cy), (ex, ey)))
        px, py = ex, ey
    return out

def poly_ours(segs_rule):
    pts = []
    for f, c, t in quads():
        ts = segs_rule(f, c, t)
        for tt in ts:
            pts.append(sample(f, c, t, tt))
    return pts

def uniform(n):
    return lambda f, c, t: [i/float(n) for i in range(1, n+1)]

def bucketed(f, c, t):
    mx, my = (f[0]+t[0])*0.5, (f[1]+t[1])*0.5
    d = (c[0]-mx)**2 + (c[1]-my)**2
    n = 1 if d < 0.25 else 4 if d < 4.0 else 8 if d < 25.0 else 16
    return [i/float(n) for i in range(1, n+1)]

def lyon(f, c, t):
    return lyon_ts(f, c, t, 0.1)

def scan_row(pts, y):
    xs = []
    n = len(pts)
    for i in range(n):
        a, b = pts[i], pts[(i+1) % n]
        if (a[1] <= y < b[1]) or (b[1] <= y < a[1]):
            xs.append(a[0] + (b[0]-a[0])*(y-a[1])/(b[1]-a[1]))
    xs.sort()
    return xs

def filled(xs, w=120):
    return [x for x in range(w) if sum(1 for c in xs if c <= x+0.5) % 2 == 1]

for name, rule in (("bucketed(ours)", bucketed), ("lyon(ruffle)", lyon)):
    pts = poly_ours(rule)
    print(f"{name}: {len(pts)} vertices")
    for y in (10.5, 11.5, 12.5):
        xs = scan_row(pts, y)
        f = filled(xs)
        print(f"   y={y}: crossings {[round(v,3) for v in xs]}  filled x {min(f)}..{max(f)}")
xs_true = None
for y in (10.5, 11.5, 12.5):
    hw = math.sqrt(max(R*R - (CY-y)**2, 0))
    lo, hi = CX-hw, CX+hw
    f = [x for x in range(120) if lo <= x+0.5 <= hi]
    print(f"true circle y={y}: [{lo:.3f},{hi:.3f}] filled x {min(f)}..{max(f)}")
