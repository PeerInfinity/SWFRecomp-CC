#!/usr/bin/env python3
"""crop.py PNG x0 y0 w h : print coverage (0-9, # = full) of a crop."""
import sys
from PIL import Image
im = Image.open(sys.argv[1]).convert("L"); x0, y0, w, h = map(int, sys.argv[2:6])
for y in range(y0, y0 + h):
    print("%4d " % y + "".join("." if im.getpixel((x, y)) > 250 else ("#" if im.getpixel((x, y)) < 5 else str(min(9, int((255 - im.getpixel((x, y))) / 25.6)))) for x in range(x0, x0 + w)))
