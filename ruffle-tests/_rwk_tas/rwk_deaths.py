#!/usr/bin/env python3
"""Detect deaths/camera-snaps: mean abs diff between consecutive frames."""
import sys, os
import numpy as np
from PIL import Image
S = os.path.dirname(os.path.abspath(__file__))
RUN = sys.argv[1] if len(sys.argv) > 1 else f"{S}/rwk_run"
T0, T1 = int(sys.argv[2]), int(sys.argv[3])
prev = None
for t in range(T0, T1):
    p = f"{RUN}/f{t:03d}.ppm"
    if not os.path.exists(p): break
    im = np.asarray(Image.open(p).convert("RGB"), dtype=np.float32)
    if prev is not None:
        d = np.abs(im - prev).mean()
        if d > 18:
            print(f"t={t} JUMP mad={d:.1f}")
    prev = im
