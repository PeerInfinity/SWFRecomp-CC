#!/usr/bin/env python3
"""Grade before/after renders against Flash-LOW captures and goldens.

usage: grade.py COMPARE_JSON PNG_DIR BEFORE_DIR AFTER_DIR GOLDEN_ROOT [SWAP_ROOT] > table.json
Each row: channels (> row tolerance) for before->FL, after->FL, before->golden, after->golden,
pass flags vs golden (max_outliers in channels? Ruffle counts outlier PIXELS? see note).
Ruffle's metric: count of channel values > tolerance, compared with max_outliers.
"""
import json, sys, os
import numpy as np
from PIL import Image

cmpj, pngdir, bdir, adir, groot = sys.argv[1:6]
swaproot = sys.argv[6] if len(sys.argv) > 6 else None


def load(p):
    if not p or not os.path.exists(p):
        return None
    return np.asarray(Image.open(p).convert('RGBA')).astype(int)


def ch(a, b, tol, rgb_only=True):
    if a is None or b is None:
        return None
    if a.shape != b.shape:
        return 'size'
    d = np.abs(a - b)
    if rgb_only:
        d = d[..., :3]
    return int((d > tol).sum())


out = []
for r in json.load(open(cmpj)):
    t, c, tol, mo = r['test'], r['cmp'], r['tol'], r['max_outliers']
    key = t.replace('/', '__')
    mode = r.get('flash_mode', 'draw')
    fp = os.path.join(pngdir, f'{key}__{c}.screen.low.png' if mode == 'screen' else f'{key}__{c}.low.png')
    if not os.path.exists(fp):
        fp = os.path.join(pngdir, f'{key}__{c}.low.png')
    F = load(fp)
    B = load(os.path.join(bdir, key, f'{c}.actual.png'))
    A = load(os.path.join(adir, key, f'{c}.actual.png'))
    G = load(os.path.join(groot, t, f'{c}.expected.png'))
    S = load(os.path.join(swaproot, t, f'{c}.expected.png')) if swaproot else None
    row = dict(test=t, cmp=c, tol=tol, max_outliers=mo,
               B_F=ch(B, F, tol), A_F=ch(A, F, tol), B_g=ch(B, G, tol, False), A_g=ch(A, G, tol, False),
               A_B_exact=ch(A, B, 0, False), swapped=S is not None)
    if S is not None:
        row['B_s'] = ch(B, S, tol, False)
        row['A_s'] = ch(A, S, tol, False)
    out.append(row)
json.dump(out, sys.stdout, indent=1)
