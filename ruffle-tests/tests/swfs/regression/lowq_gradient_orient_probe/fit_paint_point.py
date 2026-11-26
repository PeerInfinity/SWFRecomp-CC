#!/usr/bin/env python3
"""Fit Flash quality=LOW gradient paint point from a capture of this probe.

usage: fit_paint_point.py IMAGE.png [cells.json]

Linear cells: with u(x, y) = 256 * t(x, y) at the pixel's TOP-LEFT corner,
model index = floor(u + s); s = 256 * (alpha*ox + beta*oy) + delta, where
(ox, oy) is the paint point inside the pixel (0,0 = top-left corner,
0.5,0.5 = centre) and delta a lookup bias. Each interior pixel bounds s to
an interval; per cell we report the feasible interval (or the best-fit s and
its miss count), then least-squares (ox, oy, delta) across cells.
Radial cells: grid-search (ox, oy) in 1/16 px with index = floor(256 t).
"""
import json, math, pathlib, sys
import numpy as np
from PIL import Image

img = np.asarray(Image.open(sys.argv[1]).convert('RGB')).astype(int)
cells = json.loads(pathlib.Path(sys.argv[2] if len(sys.argv) > 2 else
                                pathlib.Path(__file__).with_name('cells.json')).read_text())


def inside_mask(poly, margin=1.5):
    H, W = img.shape[:2]
    ys, xs = np.mgrid[0:H, 0:W]
    ok = np.ones((H, W), bool)
    n = len(poly)
    # signed area for orientation
    area = sum(poly[i][0] * poly[(i + 1) % n][1] - poly[(i + 1) % n][0] * poly[i][1] for i in range(n))
    sg = 1 if area > 0 else -1
    for cx, cy in [(0, 0), (1, 0), (0, 1), (1, 1)]:
        px, py = xs + cx, ys + cy
        for i in range(n):
            x0, y0 = poly[i]; x1, y1 = poly[(i + 1) % n]
            ex, ey = x1 - x0, y1 - y0
            L = math.hypot(ex, ey)
            d = sg * (ex * (py - y0) - ey * (px - x0)) / L
            ok &= d > margin
    return ok


def grad_inv(m):
    a, b, c, d, tx, ty = m
    det = a * d - b * c
    return a, b, c, d, tx, ty, det


def gcoords(m, X, Y):
    a, b, c, d, tx, ty, det = grad_inv(m)
    dx, dy = X - tx, Y - ty
    gx = (d * dx - c * dy) / det
    gy = (-b * dx + a * dy) / det
    return gx, gy


rows = []
for c in cells:
    mask = inside_mask(c['poly_stage_px'])
    ys, xs = np.nonzero(mask)
    v = img[ys, xs]
    m = c['grad_to_stage_px']
    if c['kind'] == 'linear' and c.get('spread', 0):
        gx, _ = gcoords(m, xs.astype(float), ys.astype(float))
        u = (gx + 16384) / 32768 * 256
        val = v[:, 0]
        res = []
        for s in np.arange(-4, 4.0001, 1 / 64):
            j = np.floor(u + s)
            if c['spread'] == 2:
                k = np.mod(j, 256)
            else:
                j = np.mod(j, 512); k = np.where(j > 255, 511 - j, j)
            res.append((int(np.sum(k != val)), s))
        # s28 lowq-corner-rule law: s = (grad_u_local . T_local) / 256
        gl = c['grad_px']; ga, gb, gc_, gd, gtx, gty = gl; gdet = ga * gd - gb * gc_
        dul_dx = 256 / 32768 * gd / gdet; dul_dy = 256 / 32768 * (-gc_) / gdet
        s_law = (dul_dx * gtx + dul_dy * gty) / 256
        j = np.floor(u + s_law)
        if c['spread'] == 2:
            k = np.mod(j, 256)
        else:
            j = np.mod(j, 512); k = np.where(j > 255, 511 - j, j)
        law_miss = int(np.sum(k != val))
        best = min(r[0] for r in res)
        ss = [r[1] for r in res if r[0] == best]
        print(f"{c['name']:16s} spread={c['spread']} best miss={best}/{len(xs)}  s in [{min(ss):+.3f},{max(ss):+.3f}]  LAW s={s_law:+.3f} miss={law_miss}")
        continue
    if c['kind'] == 'linear':
        gx, _ = gcoords(m, xs.astype(float), ys.astype(float))
        u = (gx + 16384) / 32768 * 256
        a, b, cc, d, tx, ty, det = grad_inv(m)
        # du/dx, du/dy
        alpha = 256 / 32768 * (d) / det
        beta = 256 / 32768 * (-cc) / det
        step = len(c['stops']) == 4
        if step:
            white = v[:, 0] > 127
            # white iff u + s >= 128
            lo = np.max(np.where(white, 128 - u, -1e9))
            hi = np.min(np.where(~white, 128 - u, 1e9))
        else:
            val = v[:, 0]
            sel = (val > 0) & (val < 255)
            lo = np.max(np.where(sel, val - u, -1e9))
            hi = np.min(np.where(sel, val + 1 - u, 1e9))
        if lo <= hi:
            s = (lo + hi) / 2; miss = 0
        else:
            cand = np.linspace(min(lo, hi) - 2, max(lo, hi) + 2, 801)
            if step:
                pred = lambda s: (u + s >= 128)
                miss_of = lambda s: int(np.sum(pred(s) != white))
            else:
                miss_of = lambda s: int(np.sum(np.abs(np.clip(np.floor(u + s), 0, 255) - val)[sel] > 0))
            ms = [miss_of(s) for s in cand]
            s = cand[int(np.argmin(ms))]; miss = min(ms)
        rows.append((c['name'], alpha, beta, lo, hi, s, miss, len(xs)))
        print(f"{c['name']:16s} alpha={alpha:+.3f} beta={beta:+.3f}  s in [{lo:+.3f},{hi:+.3f}]"
              f"  s={s:+.3f} miss={miss}/{len(xs)}")
    elif c['kind'] == 'radial':
        best = None
        for oy in np.arange(-1, 1.001, 1 / 16):
            for ox in np.arange(-1, 1.001, 1 / 16):
                gx, gy = gcoords(m, xs + ox, ys + oy)
                t = np.sqrt(gx * gx + gy * gy) / 16384
                pred = np.clip(np.floor(t * 256), 0, 255)
                err = int(np.sum(np.abs(pred - v[:, 0]) > 0))
                if best is None or err < best[0]:
                    best = (err, ox, oy)
        print(f"{c['name']:16s} radial best ox={best[1]:+.4f} oy={best[2]:+.4f} miss={best[0]}/{len(xs)}")

A = np.array([[r[1], r[2], 1.0] for r in rows if r[6] == 0])
y = np.array([r[5] for r in rows if r[6] == 0])
if len(y) >= 3:
    sol, *_ = np.linalg.lstsq(A, y, rcond=None)
    res = y - A @ sol
    print(f"\nLSQ over {len(y)} exact cells: ox={sol[0]:+.4f} oy={sol[1]:+.4f} delta={sol[2]:+.4f}"
          f"  max|res|={np.max(np.abs(res)):.3f}")
    for r, e in zip([r for r in rows if r[6] == 0], res):
        print(f"   {r[0]:16s} res={e:+.3f} (interval width {r[4]-r[3]:.3f})")
