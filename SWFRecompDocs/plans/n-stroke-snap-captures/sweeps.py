#!/usr/bin/env python3
"""Spec builders for the stroke-snap sweeps. usage: sweeps.py NAME > spec.json"""
import json, sys, math
def grid(widths, offs, mk, cw=26, rh_=20, rw=16, rhh=10, **kw):
    items = []
    for r, lw in enumerate(widths):
        for c, o in enumerate(offs):
            m = mk(10 + c * cw, 10 + r * rh_, o)
            it = dict(lw=lw, rw=rw, rh=rhh, m=m, label="o=%s" % (o,)); it.update(kw)
            items.append(it)
    return dict(w=10 + len(offs) * cw + 10, h=10 + len(widths) * rh_ + 10, items=items)
W1 = [1, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 70, 80]
OFF = list(range(0, 20, 2))
ident = lambda x, y, o: [1, 0, 0, 1, x * 20 + o, y * 20 + o]
S = {}
S["w_v1"] = lambda: grid(W1, OFF, ident)
S["w_v4"] = lambda: grid(W1, OFF, ident, v=4)
S["w_v4hint"] = lambda: grid(W1, OFF, ident, v=4, hint=1)
for sc in (0.5, 2, 3):
    S["sc%s" % sc] = (lambda sc: lambda: grid([1, 10, 20, 30, 40] if sc > 1 else [1, 20, 40, 60, 80], OFF,
        lambda x, y, o: [sc, 0, 0, sc, x * 20 + o, y * 20 + o], rw=int(16 / sc) if sc > 1 else 16,
        rhh=int(10 / sc) if sc > 1 else 10, cw=26 if sc <= 1 else 26, rh_=20 if sc <= 1 else 20))(sc)
W2 = [18, 19, 20, 21, 22, 23, 24, 38, 39, 40, 41, 42, 58, 59, 60, 61, 62, 64, 66, 68, 72, 76, 79, 100]
OFF5 = list(range(0, 20, 1))
S["w2_v1"] = lambda: grid(W2, OFF5, ident)
S["w2_hint"] = lambda: grid(W2, OFF5, ident, v=4, hint=1)
def rot(widths, angles, cw=44, **kw):
    items = []
    for r, lw in enumerate(widths):
        for c, ang in enumerate(angles):
            t = math.radians(ang); co, si = math.cos(t), math.sin(t)
            x, y = 12 + c * cw, 12 + r * cw
            it = dict(lw=lw, rw=24, rh=24, m=[co, si, -si, co, x * 20 + 3, y * 20 + 3], label="a=%s" % ang); it.update(kw)
            items.append(it)
    return dict(w=24 + len(angles) * cw, h=24 + len(widths) * cw, items=items)
S["rot"] = lambda: rot([1, 20, 30, 40, 60], [0, 0.5, 2, 10, 30, 45, 90])
S["rot_hint"] = lambda: rot([1, 20, 30, 40, 60], [0, 0.5, 2, 10, 30, 45, 90], v=4, hint=1)
S["curve"] = lambda: rot([1, 20, 30, 40, 60], [0, 0.5, 2, 10, 30, 45, 90], curve=1)
# scale sweeps: device-width = lw*scale; rect sized so device size ~16x10
def scl(sx, sy, widths, **kw):
    return grid(widths, OFF5, lambda x, y, o: [sx, 0, 0, sy, x * 20 + o, y * 20 + o],
                rw=max(2, round(16 / sx)), rhh=max(2, round(10 / sy)), **kw)
S["sc_half"] = lambda: scl(0.5, 0.5, [1, 20, 40, 44, 46, 50, 80, 84, 120, 124, 160])
S["sc_2"] = lambda: scl(2, 2, [1, 5, 10, 11, 12, 15, 20, 21, 22, 30, 31, 40])
S["sc_x2"] = lambda: scl(2, 1, [1, 10, 15, 20, 30, 40])
S["sc_y2"] = lambda: scl(1, 2, [1, 10, 15, 20, 30, 40])
S["sc_2_none"] = lambda: scl(2, 2, [1, 10, 15, 20, 30, 40], v=4, noh=1, nov=1)
S["sc_2_noh"] = lambda: scl(2, 2, [1, 10, 15, 20, 30, 40], v=4, noh=1)
S["sc_2_nov"] = lambda: scl(2, 2, [1, 10, 15, 20, 30, 40], v=4, nov=1)
S["sc_x2_none"] = lambda: scl(2, 1, [1, 10, 15, 20, 30, 40], v=4, noh=1, nov=1)
def combo():
    """One-SWF regression matrix (regression/avm1_stroke_pixel_snap_matrix)."""
    offs = [0, 3, 5, 8, 10, 13, 15, 18]
    rows = []
    for lw in (1, 20, 22, 23, 30, 40, 45, 60, 64, 80):
        rows.append((lw, 1, 1, 0, {}))
    for lw in (25, 35, 45, 80):
        rows.append((lw, 1, 1, 0, dict(v=4, hint=1)))
    for lw in (10, 15, 20):
        rows.append((lw, 2, 2, 0, {}))
    for lw in (20, 30, 40):
        rows.append((lw, 2, 1, 0, {}))
    for lw in (20, 40):
        rows.append((lw, 2, 2, 0, dict(v=4, noh=1, nov=1)))
    for lw in (20, 40):
        rows.append((lw, 1, 1, 90, {}))
    for lw in (20, 40):
        rows.append((lw, 1, 1, 10, {}))
    for lw in (20, 40):
        rows.append((lw, 1, 1, 0, dict(curve=1)))
    items = []; y = 6
    for lw, sx, sy, ang, kw in rows:
        t = math.radians(ang); co, si = math.cos(t), math.sin(t)
        rw, rh = round(16 / sx), round(10 / sy)
        for c, o in enumerate(offs):
            x = 6 + c * 26
            if ang == 90:
                m = [0, sy, -sx, 0, (x + 12) * 20 + o, y * 20 + o]
            else:
                m = [sx * co, sx * si, -sy * si, sy * co, x * 20 + o, y * 20 + o]
            it = dict(lw=lw, rw=rw, rh=rh, m=m, label="o=%d" % o); it.update(kw)
            items.append(it)
        y += 18
    return dict(w=6 + len(offs) * 26, h=y + 6, items=items)
S["combo"] = combo
if __name__ == "__main__":
    print(json.dumps(S[sys.argv[1]]()))
