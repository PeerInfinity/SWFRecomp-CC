#!/usr/bin/env python3
"""regression/avm2_applyfilter_bevel_sample: BitmapData.applyFilter BevelFilter
SAMPLE OFFSET, graded against FLASH PLAYER 32.

Landed by s28 w2-filter-residuals-land from the s28 w1-filter-residuals
isolation probe (session28-fanout-reports/w1-filter-residuals-fixtures/
avm2_bevel_sample_isolation_probe); output.txt is the coordinator's FP32 LNX
capture (w1-local-oracles/w1-filter-residuals/
avm2_bevel_sample_isolation_probe.flash32.txt), the lines of the cases kept
here copied verbatim (each case is independent: fresh target, same sources).

Sources (transparent BitmapData):
  K = the glow_kernels source (20x20: 0x993366FF 10x10 at (5,5), 0xFF000000 4x4 at (8,8)).
  R = 32x20 ramp: columns x = 4..27 filled rows 4..15 with alpha 10*(x-3) (black).
Cases: blur3 / blur4 = BlurFilter(b, b, 1) (Flash's blurred grid B, which the
bevel samples), and BevelFilter(dist, ang, 0xFFFFFF, 1, 0, 1, 3, 3, 1, 1,
'full', knockout) -- the bare bevel: alpha = |b_l - b_r|, white = highlight.
Pins avm2_bitmap.c fb_bevel_offset: integral offset components exact (the
Fixed16 angle snapped, trig in double: a0 / a90), fractional ones
floor(o * 256 + 1.4) / 256.
EXCLUDED: the 12 cases where that rule is still off Flash (177 px over the
full probe, d 1.5 at 135 deg is 137 of them; see the s28 w2 report). Restore
them by emptying EXCLUDE once the sample rule is exact.
Usage: create_test_swf.py [out.swf]
"""
import os, runpy, struct, sys, pathlib
HERE = pathlib.Path(__file__).resolve().parent
G = runpy.run_path(str(HERE.parent / 'avm2_applyfilter_glow_kernels/create_test_swf.py'), run_name='lib')
Abc, Code, u30, tag = G['Abc'], G['Code'], G['u30'], G['tag']
NS = G['NS']

SOURCES = {
    'K': (20, 20, [(5, 5, 10, 10, 0x993366FF), (8, 8, 4, 4, 0xFF000000)]),
    'R': (32, 20, [(x, 4, 1, 12, (10 * (x - 3)) << 24) for x in range(4, 28)]),
}
EXCLUDE = ['bevel d1.5 a135 K', 'bevel d1.5 a135 R', 'bevel d1.5 a200 R', 'bevel d2 a135 K', 'bevel d2 a135 R', 'bevel d2 a200 K', 'bevel d2 a200 R', 'bevel d2 a45 R', 'bevel d3 a135 K', 'bevel d3 a135 R', 'bevel d3 a200 R', 'bevel d3 a45 R']
CASES = []
for src in ('K', 'R'):
    for b in (3, 4):
        CASES.append((src, 'blur%d %s' % (b, src), 'BlurFilter', [b, b, 1]))
    for dist in (2, 1.5, 3):
        for ang in (200, 45, 0, 90, 135):
            if 'bevel d%s a%d %s' % (dist, ang, src) in EXCLUDE: continue
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
