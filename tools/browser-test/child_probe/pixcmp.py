#!/usr/bin/env python3
"""Compare a captured framebuffer PNG to a golden, on RGB, per pixel.
(NOT ImageChops.getbbox: in Pillow >=10 getbbox() on an RGBA image is
alpha-only by default, so two fully-opaque images always report "no
difference" no matter how different their colours are.)"""
import sys
from PIL import Image
a = Image.open(sys.argv[1]).convert("RGB")
b = Image.open(sys.argv[2]).convert("RGB")
if a.size != b.size:
    print(f"SIZE MISMATCH {a.size} vs {b.size}"); sys.exit(1)
pa, pb = list(a.getdata()), list(b.getdata())
diff = [i for i, (x, y) in enumerate(zip(pa, pb)) if x != y]
if not diff:
    print(f"IDENTICAL ({a.size[0]}x{a.size[1]}, {len(pa)} px)")
else:
    mx = max(max(abs(pa[i][c]-pb[i][c]) for c in range(3)) for i in diff)
    xs = [i % a.size[0] for i in diff]; ys = [i // a.size[0] for i in diff]
    print(f"DIFFERS: {len(diff)}/{len(pa)} px, max channel delta {mx}, "
          f"bbox x[{min(xs)},{max(xs)}] y[{min(ys)},{max(ys)}]")
