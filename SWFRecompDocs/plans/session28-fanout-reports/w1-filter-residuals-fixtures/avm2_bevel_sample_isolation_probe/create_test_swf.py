#!/usr/bin/env python3
"""FLASH ORACLE PROBE (s28 w1-filter-residuals): isolate the BevelFilter sample.

Goal: read Flash's blurred alpha grid B and the bevel difference d = b_l - b_r
per pixel, so the last bevel residual (s27 w2b-filter-kernels-residual: 4 px in
glow_kernels, 1 in draw_filtered, 2 in gradientbevel; every one a pixel where
floor(B(x+o)) - floor(B(x-o)) is one level off Flash) can be fitted offline.

Sources (transparent BitmapData):
  K = the glow_kernels source (20x20: 0x993366FF 10x10 at (5,5), 0xFF000000 4x4 at (8,8)).
  R = 32x20 ramp: columns x = 4..27 filled rows 4..15 with alpha 10*(x-3) (black).
Cases (applyFilter into a fresh transparent target of the same size, destPoint 0,0):
  blur3 / blur4 on K and R: BlurFilter(b, b, 1)        -> Flash's B grid, every row.
  bevel on K and R: BevelFilter(dist, ang, 0xFFFFFF, 1, 0x000000, 1, 3, 3, 1, 1,
      'full', knockout=true): with knockout + full the bare bevel is written,
      alpha = |d| (strength 1, alpha 1: fb_glow_amount is the identity) and the
      colour gives the sign (white = highlight, d >= 0; black = shadow).
      dist in (2, 1.5, 3), ang in (200, 45, 0, 90, 135).
Every case dumps EVERY row: "<label> y=<y>: <getPixel32 hex> ...".
Usage: create_test_swf.py [out.swf]. output.txt in this dir is OUR output
(provisional) until the Flash capture replaces it.
"""
import os, runpy, struct, sys, pathlib
HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parents[4]
G = runpy.run_path(str(ROOT / 'ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/create_test_swf.py'), run_name='lib')
Abc, Code, u30, tag = G['Abc'], G['Code'], G['u30'], G['tag']
NS = G['NS']

SOURCES = {
    'K': (20, 20, [(5, 5, 10, 10, 0x993366FF), (8, 8, 4, 4, 0xFF000000)]),
    'R': (32, 20, [(x, 4, 1, 12, (10 * (x - 3)) << 24) for x in range(4, 28)]),
}
CASES = []
for src in ('K', 'R'):
    for b in (3, 4):
        CASES.append((src, 'blur%d %s' % (b, src), 'BlurFilter', [b, b, 1]))
    for dist in (2, 1.5, 3):
        for ang in (200, 45, 0, 90, 135):
            CASES.append((src, 'bevel d%s a%d %s' % (dist, ang, src), 'BevelFilter',
                          [float(dist), ang, 0xFFFFFF, 1.0, 0x000000, 1.0, 3, 3, 1, 1, 'full', True]))

def build_code(abc):
    c = Code(abc)
    DST, I, S, SRCK, SRCR = 1, 2, 3, 4, 5
    slot = {'K': SRCK, 'R': SRCR}
    c.op(0xd0, 0x30)
    for k, (w, h, fills) in SOURCES.items():
        c.new('BitmapData', [w, h, True, 0]); c.setlocal(slot[k])
        for (x, y, fw, fh, col) in fills:
            c.getlocal(slot[k]); c.new('Rectangle', [x, y, fw, fh]); c.push(col)
            c.callpropvoid('fillRect', 2)
    for (src, label, cls, args) in CASES:
        w, h, _ = SOURCES[src]
        c.new('BitmapData', [w, h, True, 0]); c.setlocal(DST)
        c.getlocal(DST); c.getlocal(slot[src]); c.getlocal(slot[src]); c.getproperty('rect')
        c.new('Point', [0, 0]); c.new(cls, args); c.callpropvoid('applyFilter', 4)
        for y in range(h):
            c.push(label + ' y=' + str(y) + ':'); c.setlocal(S)
            def body():
                c.getlocal(S); c.push(' '); c.op(0xa0)
                c.getlocal(DST); c.getlocal(I); c.push(y)
                c.callproperty('getPixel32', 2)
                c.push(16); c.callproperty('toString', 1)
                c.op(0xa0); c.setlocal(S)
            c.loop(I, 0, w, body)
            c.op(0x5d); c.b += u30(abc.name('trace')); c.getlocal(S); c.callpropvoid('trace', 1)
    c.op(0x5d); c.b += u30(abc.name('trace')); c.push('done'); c.callpropvoid('trace', 1)
    c.op(0x47)
    return bytes(c.b), SRCR + 1

G['build_code'] = build_code
# build_abc looks build_code up in its own module globals
G['build_abc'].__globals__['build_code'] = build_code
if __name__ == '__main__':
    out = sys.argv[1] if len(sys.argv) > 1 else str(HERE / 'test.swf')
    open(out, 'wb').write(G['build_swf']())
    print('wrote', out)
