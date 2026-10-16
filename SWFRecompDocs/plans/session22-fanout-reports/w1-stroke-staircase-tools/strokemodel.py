"""Stroke geometry models: 'ours' (swf.cpp drawLines replica) vs 'ruffle' (lyon-like, float px).
Rasterize at pixel centres (no AA, quality=low) into a boolean mask."""
import math
import numpy as np

FH = None  # frame height twips, set by caller


def levien(x0, y0, cx, cy, x1, y1, tol):
    """lyon_geom quadratic flattening t schedule (float32-ish but in double)."""
    if x0 == x1 and y0 == y1:
        return [1.0]
    bx, by = x1 - x0, y1 - y0
    len2 = bx * bx + by * by
    cross = (cx - x0) * by - (cy - y0) * bx
    if len2 > 0 and cross * cross / len2 <= tol * tol * 4.0:
        return [1.0]
    ddx = 2 * cx - x0 - x1; ddy = 2 * cy - y0 - y1
    crs = (x1 - x0) * ddy - (y1 - y0) * ddx
    if crs == 0:
        return [1.0]
    inv = 1.0 / crs
    pf = ((cx - x0) * ddx + (cy - y0) * ddy) * inv
    pt = ((x1 - cx) * ddx + (y1 - cy) * ddy) * inv
    scale = abs(crs) / (math.hypot(ddx, ddy) * abs(pt - pf))
    I = lambda x: x / (1 - 0.67 + math.sqrt(math.sqrt(0.67 ** 4 + 0.25 * x * x)))
    Iv = lambda x: x * (1 - 0.39 + math.sqrt(0.39 ** 2 + 0.25 * x * x))
    a0 = I(pf); a2 = I(pt); diff = a2 - a0
    u0 = Iv(a0); u2 = Iv(a2)
    count = math.ceil(0.5 * abs(diff) * math.sqrt(scale / tol))
    if not math.isfinite(count) or count < 1:
        return [1.0]
    count = min(count, 64)
    step = diff / count
    ts = []
    for i in range(1, count + 1):
        if i < count:
            u = Iv(a0 + step * i); ts.append((u - u0) / (u2 - u0))
        else:
            ts.append(1.0)
    return ts


def flatten_path(segs, mode, tol_twips=2.0):
    """segs in SWF twips (y down). Returns list of float points (twips, y down)."""
    pts = [(float(segs[0][1]), float(segs[0][2]))]
    for s in segs:
        if s[0] == 'L':
            pts.append((float(s[3]), float(s[4])))
        else:
            _, x0, y0, cx, cy, x1, y1 = s
            if mode == 'ours':
                # internal y-up frame: yi = FH - y ; truncation toward zero
                Y0, CY, Y1 = FH - y0, FH - cy, FH - y1
                ts = levien(x0, Y0, cx, CY, x1, Y1, tol_twips)
                for t in ts:
                    u = 1 - t
                    px = int(np.float32(u * u * x0 + 2 * u * t * cx + t * t * x1))
                    py = int(np.float32(u * u * Y0 + 2 * u * t * CY + t * t * Y1))
                    if t == 1.0:
                        px, py = x1, Y1
                    pts.append((float(px), float(FH - py)))
            else:
                ts = levien(x0, y0, cx, cy, x1, y1, tol_twips)
                for t in ts:
                    u = 1 - t
                    pts.append((u * u * x0 + 2 * u * t * cx + t * t * x1, u * u * y0 + 2 * u * t * cy + t * t * y1))
    return pts


def stroke_tris(pts, hw, mode, closed, nmid=5, rnd=None):
    """Triangles of a stroke. mode 'ours' rounds offset vertices to integer twips (internal y-up frame)."""
    if rnd is None:
        rnd = (mode == 'ours')
    tris = []
    if mode == 'ours':
        P = [(x, FH - y) for x, y in pts]  # internal y-up
    else:
        P = list(pts)
    R = (lambda v: float(round_half_away(v))) if rnd else (lambda v: v)

    def off(p, ang):
        return (R(p[0] + hw * math.cos(ang)), R(p[1] + hw * math.sin(ang)))

    def join(a, b, c):
        ab = (b[0] - a[0], b[1] - a[1]); bc = (c[0] - b[0], c[1] - b[1])
        cr = ab[0] * bc[1] - ab[1] * bc[0]
        o = math.pi / 2 if cr < 0 else -math.pi / 2
        a1 = math.atan2(ab[1], ab[0]) + o; a2 = math.atan2(bc[1], bc[0]) + o
        d = a2 - a1
        if d > math.pi: a2 -= 2 * math.pi
        elif d < -math.pi: a2 += 2 * math.pi
        s, e = min(a1, a2), max(a1, a2)
        n = nmid
        dl = (e - s) / n
        last = off(b, s)
        ang = s + dl
        while ang < e and dl > 0:
            q = off(b, ang); tris.append((b, last, q)); last = q; ang += dl
        tris.append((b, last, off(b, e)))

    def cap(a, b):
        ang = math.atan2(b[1] - a[1], b[0] - a[0])
        s = ang + math.pi / 2; e = s + math.pi
        dl = (e - s) / nmid
        last = off(a, s); t = s + dl
        while t < e:
            q = off(a, t); tris.append((a, last, q)); last = q; t += dl
        tris.append((a, last, off(a, e)))

    for i in range(1, len(P)):
        a, b = P[i - 1], P[i]
        if a == b:
            continue
        if i > 1:
            join(P[i - 2], a, b)
        ang = math.atan2(b[1] - a[1], b[0] - a[0]) - math.pi / 2
        v0 = off(a, ang); v2 = off(b, ang); v1 = off(a, ang + math.pi); v3 = off(b, ang + math.pi)
        tris.append((v0, v1, v2)); tris.append((v3, v1, v2))
    if closed and len(P) > 2:
        join(P[-2], P[0], P[1])
    elif len(P) > 1:
        cap(P[0], P[1]); cap(P[-1], P[-2])
    if mode == 'ours':
        tris = [tuple((x, FH - y) for x, y in t) for t in tris]
    return tris


def round_half_away(v):
    return math.floor(v + 0.5) if v >= 0 else -math.floor(-v + 0.5)


def raster(tris, W, H, ox, oy, scale=1 / 20.0):
    """Pixel-centre coverage; tris in twips; device = twips*scale + (ox,oy)."""
    m = np.zeros((H, W), bool)
    for t in tris:
        p = [(x * scale + ox, y * scale + oy) for x, y in t]
        xs = [q[0] for q in p]; ys = [q[1] for q in p]
        x0 = max(int(math.floor(min(xs) - 0.5)), 0); x1 = min(int(math.ceil(max(xs) + 0.5)), W - 1)
        y0 = max(int(math.floor(min(ys) - 0.5)), 0); y1 = min(int(math.ceil(max(ys) + 0.5)), H - 1)
        if x1 < x0 or y1 < y0:
            continue
        X, Y = np.meshgrid(np.arange(x0, x1 + 1) + 0.5, np.arange(y0, y1 + 1) + 0.5)
        (ax, ay), (bx, by), (cx, cy) = p
        area = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax)
        if area == 0:
            continue
        if area < 0:
            (bx, by), (cx, cy) = (cx, cy), (bx, by)
        e0 = (bx - ax) * (Y - ay) - (by - ay) * (X - ax)
        e1 = (cx - bx) * (Y - by) - (cy - by) * (X - bx)
        e2 = (ax - cx) * (Y - cy) - (ay - cy) * (X - cx)
        inside = (e0 >= 0) & (e1 >= 0) & (e2 >= 0)
        m[y0:y1 + 1, x0:x1 + 1] |= inside
    return m
