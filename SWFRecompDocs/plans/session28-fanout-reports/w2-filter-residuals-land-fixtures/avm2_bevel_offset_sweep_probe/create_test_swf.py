#!/usr/bin/env python3
"""FLASH ORACLE PROBE (s28 w2-filter-residuals-land): BevelFilter sample-offset SWEEP.

fb_bevel_offset (avm2_bitmap.c) fits floor(o * 256 + 1.4) / 256 per fractional
axis on 18 of the 30 avm2_bevel_sample_isolation_probe cases; d 1.5 at 135 deg
lands on round(o) instead (137 px) and six d 2 / 3 cases keep <= 9 px. This
sweep (ramp source R only: every column a distinct alpha, so each sample is
well conditioned) gives the dense (distance, angle) grid needed to find the
real mechanism: dist in DISTS x ang in ANGS, plus blur3 R (B grid).
BevelFilter(dist, ang, 0xFFFFFF, 1, 0, 1, 3, 3, 1, 1, 'full', knockout=true):
alpha = |b_l - b_r|, white = highlight. output.txt = OUR output (provisional).
Usage: create_test_swf.py [out.swf]
"""
import os, runpy, struct, sys, pathlib
HERE = pathlib.Path(__file__).resolve().parent
G = runpy.run_path(str(HERE.parents[4] / 'ruffle-tests/tests/swfs/regression/avm2_applyfilter_glow_kernels/create_test_swf.py'), run_name='lib')
Abc, Code, u30, tag = G['Abc'], G['Code'], G['u30'], G['tag']
NS = G['NS']

SOURCES = {
    'K': (20, 20, [(5, 5, 10, 10, 0x993366FF), (8, 8, 4, 4, 0xFF000000)]),
    'R': (32, 20, [(x, 4, 1, 12, (10 * (x - 3)) << 24) for x in range(4, 28)]),
}
DISTS = (1.25, 1.5, 1.75, 2, 2.5, 3, 4)
ANGS = (15, 30, 45, 60, 75, 105, 120, 135, 150, 165, 200, 225, 250, 300, 330)
CASES = [('R', 'blur3 R', 'BlurFilter', [3, 3, 1])]
for dist in DISTS:
    for ang in ANGS:
        CASES.append(('R', 'bevel d%s a%d R' % (dist, ang), 'BevelFilter',
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
