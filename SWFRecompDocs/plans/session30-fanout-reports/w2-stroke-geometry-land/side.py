#!/usr/bin/env python3
"""Per-side stroke edge offset for the w1-stroke-geometry FP32 probes.

For each probe cell: exact geometry (Minkowski of the quadratic centreline with a
disc of radius hw; AS3 default round caps/joins).  Edge-band pixels are classed
convex / concave / capjoin by the nearest centreline point.  For each class:
  off(X) = (sum cov_X - sum cov_exact) / L_side     [px, + = X is fatter]
cov from the G channel (0xD0 stroke on black).  cov_exact by 16x16 supersampling.
"""
import sys, re, numpy as np
from PIL import Image
from scipy.spatial import cKDTree

G = 0xD0
SHAPES = {0: [((0, 0), (20, 0), (20, 20)), ((20, 20), (10, 30), (0, 20))],
          1: [((0, 0), (10, 30), (20, 0))]}


def quad(p0, c, p1, t):
    p0, c, p1 = map(np.asarray, (p0, c, p1))
    u = 1 - t
    return (u*u)[:, None]*p0 + (2*u*t)[:, None]*c + (t*t)[:, None]*p1


def dquad(p0, c, p1, t):
    p0, c, p1 = map(np.asarray, (p0, c, p1))
    return (2*(1-t))[:, None]*(c-p0) + (2*t)[:, None]*(p1-c)


def cells_from_trace(path):
    out = []
    for line in open(path):
        m = re.match(r"w=(\S+) s=(\S+) k=(\S+) f=(\S+) at (\S+),(\S+)", line)
        if m:
            w, s, k, f, x, y = m.groups()
            out.append(dict(w=float(w), s=float(s), k=int(k), f=float(f), x=float(x), y=float(y)))
    return out


def analyse(cell, imgs, ss=16):
    s, hw = cell['s'], cell['w']*cell['s']/2
    tx, ty = cell['x'], cell['y']
    pts, info = [], []
    for ci, (p0, c, p1) in enumerate(SHAPES[cell['k']]):
        P0 = np.array(p0)*s + (tx, ty); C = np.array(c)*s + (tx, ty); P1 = np.array(p1)*s + (tx, ty)
        L = np.linalg.norm(C-P0) + np.linalg.norm(P1-C)
        n = int(L/0.03) + 10
        t = np.linspace(0, 1, n)
        q = quad(P0, C, P1, t); d1 = dquad(P0, C, P1, t)
        d2 = 2*(P0 - 2*C + P1)
        curv_sign = np.sign(d1[:, 0]*d2[1] - d1[:, 1]*d2[0])
        pts.append(q)
        info.append(np.stack([np.full(n, ci), t, d1[:, 0], d1[:, 1], curv_sign,
                              np.abs(d1[:, 0]*d2[1]-d1[:, 1]*d2[0]) / np.maximum(np.hypot(d1[:, 0], d1[:, 1])**3, 1e-12)], 1))
    pts = np.concatenate(pts); info = np.concatenate(info)
    tree = cKDTree(pts)
    nc = len(SHAPES[cell['k']])
    x0, y0 = pts.min(0) - hw - 3; x1, y1 = pts.max(0) + hw + 3
    xs = np.arange(int(np.floor(x0)), int(np.ceil(x1)))
    ys = np.arange(int(np.floor(y0)), int(np.ceil(y1)))
    X, Y = np.meshgrid(xs, ys)
    P = np.stack([X.ravel()+0.5, Y.ravel()+0.5], 1)
    d, idx = tree.query(P)
    band = np.abs(d - hw) < 1.2
    Pb = P[band]; ib = idx[band]
    # exact coverage by supersampling
    o = (np.arange(ss)+0.5)/ss - 0.5
    OX, OY = np.meshgrid(o, o)
    sub = (Pb[:, None, :] + np.stack([OX.ravel(), OY.ravel()], 1)[None]).reshape(-1, 2)
    ds, _ = tree.query(sub)
    cex = (ds <= hw).reshape(len(Pb), -1).mean(1)
    inf = info[ib]
    q = pts[ib]
    v = Pb - q
    cr = inf[:, 2]*v[:, 1] - inf[:, 3]*v[:, 0]
    concave = np.sign(cr) == inf[:, 4]
    tt = inf[:, 1]; cid = inf[:, 0]
    capjoin = ((cid == 0) & (tt < 0.02)) | ((cid == nc-1) & (tt > 0.98)) | ((nc > 1) & (((cid == 0) & (tt > 0.98)) | ((cid == 1) & (tt < 0.02))))
    cls = np.where(capjoin, 2, np.where(concave, 1, 0))
    # side lengths: arc length * (1 -/+ hw*kappa), t in [0.02,0.98]
    Ls = {0: 0.0, 1: 0.0}
    for ci in range(nc):
        m = (info[:, 0] == ci) & (info[:, 1] >= 0.02) & (info[:, 1] <= 0.98)
        seg = pts[m]; kap = info[m, 5]
        ds_ = np.r_[0, np.hypot(*np.diff(seg, axis=0).T)]
        Ls[0] += np.sum(ds_*(1 + hw*kap))  # convex: outer offset longer
        Ls[1] += np.sum(ds_*np.maximum(1 - hw*kap, 0))
    res = {}
    bi = np.nonzero(band)[0]
    for name, im in imgs.items():
        cov = im[Y.ravel()[band], X.ravel()[band], 1] / G
        r = {}
        for k, lab in ((0, 'convex'), (1, 'concave')):
            m = cls == k
            r[lab] = (cov[m].sum() - cex[m].sum()) / max(Ls[k], 1e-9)
        m = cls == 2
        r['capjoin_area'] = cov[m].sum() - cex[m].sum()
        res[name] = r
    return res, Ls


def main():
    trace, legs = sys.argv[1], sys.argv[2:]
    imgs = {}
    for leg in legs:
        name, p = leg.split('=')
        imgs[name] = np.asarray(Image.open(p).convert('RGB')).astype(float)
    print("%-26s %8s %8s | " % ("cell", "Lcvx", "Lccv") + " | ".join("%-24s" % n for n in imgs))
    for cell in cells_from_trace(trace):
        res, Ls = analyse(cell, imgs)
        lab = "w%g s%g k%d f%g" % (cell['w'], cell['s'], cell['k'], cell['f'])
        print("%-26s %8.1f %8.1f | " % (lab, Ls[0], Ls[1]) + " | ".join(
            "cvx %+.3f ccv %+.3f cj %+6.1f" % (r['convex'], r['concave'], r['capjoin_area']) for r in res.values()))


if __name__ == '__main__':
    main()
