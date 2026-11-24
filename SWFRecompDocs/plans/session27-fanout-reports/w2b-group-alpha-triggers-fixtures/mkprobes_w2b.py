#!/usr/bin/env python3
"""s27 w2b-group-alpha-triggers: Flash-oracle probes for the group-alpha paths
the five w2 probes do not reach (REAL filters, chains, ancestor alpha above a
filter, trivial blends, alpha offsets on a filter / complex blend).
Scene = the n3 scene (sprite 10: opaque red (20,20,80,60) under opaque blue
(60,40,80,70)) on a 200x150 white stage unless noted. Pixel probes:
  (80,50) overlap: grouped = blue only at the group alpha;
  (30,30) red only; (120,100) blue only; filter halos just outside the rects.
Usage: mkprobes_w2b.py OUTDIR [avm2]   (writes OUTDIR/<probe>.swf)
The helpers are the regression fixture generator's (group_alpha_filter_cm).
"""
import runpy, struct, sys, pathlib
HERE = pathlib.Path(__file__).resolve().parent
G = runpy.run_path(str(HERE.parents[3] / 'ruffle-tests/tests/swfs/regression/group_alpha_filter_cm/create_test_swf.py'), run_name='lib')
tag, place3, shape, sprite, cxform_alpha = G['tag'], G['place3'], G['shape'], G['sprite'], G['cxform_alpha']
rectrec, DOABC, scene, A50 = G['rectrec'], G['DOABC'], G['scene'], G['A50']
fx = lambda v: struct.pack('<i', int(round(v * 65536)))
fx8 = lambda v: struct.pack('<h', int(round(v * 256)))
def glow(rgba, b, st, passes=1, inner=0, knock=0):
    return bytes([2]) + bytes(rgba) + fx(b) + fx(b) + fx8(st) + bytes([(inner << 7) | (knock << 6) | (1 << 5) | passes])
def shadow(rgba, b, ang, dist, st, passes=1):
    return bytes([0]) + bytes(rgba) + fx(b) + fx(b) + fx(ang) + fx(dist) + fx8(st) + bytes([(1 << 5) | passes])
def blur(b, passes=1):
    return bytes([1]) + fx(b) + fx(b) + bytes([passes << 3])
GREEN = (0, 255, 0, 255); BLACK = (0, 0, 0, 255)
RED = (255, 0, 0, 255)
P = {
 # glow halo must not show through the rects; overlap blue only
 'w2b_glow_a50':      lambda: scene() + [place3(1, 10, cx=A50, filters=[glow(GREEN, 8, 2)])],
 # root SHAPE with a drop shadow: the shadow must not show through the rect
 'w2b_shadow_shape_a50': lambda: [shape(1, [(20, 20, 80, 60)], RED), place3(1, 1, cx=A50, filters=[shadow(BLACK, 4, 0.785398, 12, 1)])],
 'w2b_blur_a50':      lambda: scene() + [place3(1, 10, cx=A50, filters=[blur(4)])],
 'w2b_chain_a50':     lambda: scene() + [place3(1, 10, cx=A50, filters=[blur(4), glow(GREEN, 6, 2)])],
 # 50% parent above a glowing child: does the ancestor alpha group at the filter?
 'w2b_glow_inner':    lambda: scene() + [sprite(11, [place3(1, 10, filters=[glow(GREEN, 8, 2)])]), place3(1, 11, cx=A50)],
 # trivial blend groups (SCREEN on white is white: use a grey stage via a grey rect)
 'w2b_add_a50':       lambda: scene() + [place3(1, 10, cx=A50, blend=8)],
 'w2b_multiply_aadd': lambda: scene() + [place3(1, 10, cx=cxform_alpha(mult=(256, 256, 256, 256), add=(0, 0, 0, -128)), blend=3)],
 'w2b_filter_aadd':   lambda: scene() + [place3(1, 10, cx=cxform_alpha(mult=(256, 256, 256, 256), add=(0, 0, 0, -128)), filters=[glow(GREEN, 8, 2)])],
}
def build(name, avm2=False):
    tags = P[name]()
    t = [tag(69, bytes([0x08 if avm2 else 0, 0, 0, 0])), tag(9, bytes((255, 255, 255)))]
    if avm2: t.append(DOABC)
    t += tags + [tag(1, b''), tag(0, b'')]
    body = rectrec(0, 4000, 0, 3000) + struct.pack('<BBH', 0, 30, 1) + b''.join(t)
    return b'FWS' + bytes([10]) + struct.pack('<I', 8 + len(body)) + body
if __name__ == '__main__':
    out = pathlib.Path(sys.argv[1]); out.mkdir(parents=True, exist_ok=True)
    avm2 = len(sys.argv) > 2 and sys.argv[2] == 'avm2'
    for k in P:
        n = ('avm2_' + k) if avm2 else k
        (out / (n + '.swf')).write_bytes(build(k, avm2)); print('wrote', n)
