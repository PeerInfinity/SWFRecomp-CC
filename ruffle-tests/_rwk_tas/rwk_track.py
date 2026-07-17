#!/usr/bin/env python3
"""Track player world position across a dumped RWK run.

Camera scroll via FFT phase correlation between consecutive frames
(screen = 2*(world - scroll), so frame shift = -2*dscroll). Anchored on the
kitty blob (world center ~(168,1032)) in the first frame it is visible.
Player = tan blob (154,143,120)/(134,124,102). Prints world tile positions.
"""
import sys, os
import numpy as np
from PIL import Image

S = "/tmp/claude-1000/-home-robert-CC-SWFRecomp-CC/3723b0cd-94f4-4a46-bec2-939e57820ae3/scratchpad"
RUN = sys.argv[1] if len(sys.argv) > 1 else f"{S}/rwk_run"
T0 = int(sys.argv[2]) if len(sys.argv) > 2 else 276
T1 = int(sys.argv[3]) if len(sys.argv) > 3 else None

def load(t):
    p = f"{RUN}/f{t:03d}.ppm"
    if not os.path.exists(p): return None
    return np.asarray(Image.open(p).convert("RGB"), dtype=np.float32)

def blob(im, mask_fn, min_px=30):
    m = mask_fn(im)
    ys, xs = np.nonzero(m)
    if len(ys) < min_px: return None
    return (float(xs.mean()), float(ys.mean()))

def kitty_mask(im):
    r, g, b = im[:,:,0], im[:,:,1], im[:,:,2]
    return (r > 200) & (g > 100) & (g < 190) & (b < 90)  # orange

def player_mask(im):
    r, g, b = im[:,:,0], im[:,:,1], im[:,:,2]
    return (np.abs(r-154) < 12) & (np.abs(g-143) < 12) & (np.abs(b-120) < 12) \
         | (np.abs(r-134) < 10) & (np.abs(g-124) < 10) & (np.abs(b-102) < 10)

def shift(a, b):
    # phase correlation on green channel, mid region (skip HUD/logo)
    A = np.fft.rfft2(a[80:440, 40:600, 1])
    B = np.fft.rfft2(b[80:440, 40:600, 1])
    R = A * np.conj(B)
    R /= np.abs(R) + 1e-9
    c = np.fft.irfft2(R)
    py, px = np.unravel_index(np.argmax(c), c.shape)
    if py > c.shape[0]//2: py -= c.shape[0]
    if px > c.shape[1]//2: px -= c.shape[1]
    return px, py  # b is a shifted by (px,py): b(x) = a(x - s) → camera moved +s/...

prev = load(T0)
scroll = None
t = T0
out = []
while prev is not None:
    if scroll is None:
        k = blob(prev, kitty_mask)
        if k is not None:
            scroll = (168 - k[0]/2, 1032 - k[1]/2)
    if scroll is not None:
        p = blob(prev, player_mask)
        if p is not None:
            wx = scroll[0] + p[0]/2
            wy = scroll[1] + p[1]/2
            out.append((t, wx, wy))
    nxt = load(t+1)
    if nxt is None: break
    dx, dy = shift(prev, nxt)
    if scroll is not None:
        scroll = (scroll[0] - dx/2, scroll[1] - dy/2)
    prev = nxt
    t += 1
    if T1 and t >= T1: break

last = None
for t, wx, wy in out:
    tile = (wx/16, wy/16)
    key = (round(tile[0]*2)/2, round(tile[1]*2)/2)
    if key != last:
        print(f"t={t:4d} world=({wx:6.1f},{wy:6.1f}) tile=({tile[0]:5.2f},{tile[1]:5.2f})")
        last = key
