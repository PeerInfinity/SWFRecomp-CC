#!/usr/bin/env python3
"""Predict per-side stroke-edge offset (px, + = fatter than exact) for a
quadratic-offset stroker model: each quad split into pieces; each piece's offset
is a quad with endpoints offset by +-hw along the normals and control at the
intersection of the offset tangent lines.  Subdivision rules:
  fixed:N         N equal-t pieces
  angle:DEG       recursive halving until tangent turn <= DEG
  flat:TOL        recursive halving until device flatness (ctrl-to-chord-mid/2) <= TOL px
"""
import sys, re, numpy as np
from scipy.spatial import cKDTree
sys.path.insert(0, __file__.rsplit('/', 1)[0])
from side import SHAPES, quad, dquad, cells_from_trace


def split(p0, c, p1, t=0.5):
    a = p0 + (c - p0)*t; b = c + (p1 - c)*t; m = a + (b - a)*t
    return (p0, a, m), (m, b, p1)


def turn(p0, c, p1):
    d0 = c - p0; d1 = p1 - c
    a = np.arctan2(d0[0]*d1[1]-d0[1]*d1[0], d0@d1)
    return abs(a)


def pieces(q, rule, depth=0):
    kind, val = rule
    p0, c, p1 = q
    if kind == 'fixed':
        out = []; cur = q
        for i in range(int(val), 1, -1):
            a, b = split(*cur, 1.0/i); out.append(a); cur = b
        out.append(cur); return out
    if depth < 12:
        if kind == 'angle' and turn(p0, c, p1) > np.radians(val):
            a, b = split(p0, c, p1); return pieces(a, rule, depth+1) + pieces(b, rule, depth+1)
        if kind == 'flat' and np.linalg.norm(c - (p0+p1)/2)/2 > val:
            a, b = split(p0, c, p1); return pieces(a, rule, depth+1) + pieces(b, rule, depth+1)
    return [q]


def offq(p0, c, p1, h):
    t0 = c - p0; t1 = p1 - c
    if np.linalg.norm(t0) < 1e-9: t0 = p1 - p0
    if np.linalg.norm(t1) < 1e-9: t1 = p1 - p0
    n0 = np.array([-t0[1], t0[0]])/np.linalg.norm(t0)
    n1 = np.array([-t1[1], t1[0]])/np.linalg.norm(t1)
    a0 = p0 + n0*h; a1 = p1 + n1*h
    # intersect a0 + s t0, a1 + u t1
    M = np.array([t0, -t1]).T
    det = np.linalg.det(M)
    if abs(det) < 1e-12: cc = (a0+a1)/2
    else:
        s, u = np.linalg.solve(M, a1 - a0); cc = a0 + s*t0
    return a0, cc, a1


def predict(cell, rule):
    s, hw = cell['s'], cell['w']*cell['s']/2
    tx, ty = cell['x'], cell['y']
    cen = []; segs = []
    for (p0, c, p1) in SHAPES[cell['k']]:
        P = [np.array(p)*s + (tx, ty) for p in (p0, c, p1)]
        t = np.linspace(0, 1, 20000); cen.append(quad(*P, t)); segs.append(P)
    cen_all = np.concatenate(cen); tree = cKDTree(cen_all)
    nc = len(segs)
    tlab = np.concatenate([np.stack([np.full(20000, i), np.linspace(0, 1, 20000)], 1) for i in range(nc)])
    res = {'convex': [0, 0], 'concave': [0, 0]}
    for ci, P in enumerate(segs):
        d2 = 2*(P[0] - 2*P[1] + P[2]); d1m = P[2]-P[0]
        csign = np.sign(d1m[0]*d2[1]-d1m[1]*d2[0])   # constant for a quad
        for sgn in (+1, -1):
            # left normal n = (-ty, tx); cross(T, n) = +1 -> left side is concave iff csign > 0
            side = 'concave' if sgn*csign > 0 else 'convex'
            for pc in pieces(tuple(np.array(x, float) for x in P), rule):
                a0, cc, a1 = offq(*pc, sgn*hw)
                tt = np.linspace(0, 1, 400)
                o = quad(a0, cc, a1, tt)
                d, idx = tree.query(o)
                lab = tlab[idx]
                keep = ~(((lab[:, 0] == 0) & (lab[:, 1] < 0.02)) | ((lab[:, 0] == nc-1) & (lab[:, 1] > 0.98)) |
                         ((nc > 1) & (((lab[:, 0] == 0) & (lab[:, 1] > 0.98)) | ((lab[:, 0] == 1) & (lab[:, 1] < 0.02)))))
                # on the concave side when hw > R, the offset swallowtail point may be nearest
                # to another centreline part; keep the sign by projecting onto the normal side
                dl = np.r_[np.hypot(*np.diff(o, axis=0).T), 0]
                res[side][0] += np.sum(((d - hw)*dl)[keep]); res[side][1] += np.sum(dl[keep])
    return {k: v[0]/max(v[1], 1e-9) for k, v in res.items()}


if __name__ == '__main__':
    traces = sys.argv[1:]
    rules = [('fixed', 1), ('fixed', 2), ('angle', 45), ('angle', 30), ('angle', 22.5), ('flat', 0.5), ('flat', 1), ('flat', 2)]
    for tr in traces:
        for cell in cells_from_trace(tr):
            if cell['f'] != 0: continue
            lab = "w%g s%g k%d" % (cell['w'], cell['s'], cell['k'])
            out = []
            for r in rules:
                p = predict(cell, r)
                out.append("%s%g %+.2f/%+.2f" % (r[0][0], r[1], p['convex'], p['concave']))
            print("%-14s " % lab + "  ".join(out))
