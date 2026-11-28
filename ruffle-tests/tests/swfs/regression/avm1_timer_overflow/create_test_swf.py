#!/usr/bin/env python3
"""avm1_timer_overflow: 70 live setTimeout(fn, 10) at once: ids past the old
fixed 64-entry table (MAX_TIMERS) are returned and fire (timer.c timerFreeSlot
growth), and ALL 70 fire in the first timer update: Flash has no per-update
fire cap (Ruffle's Timers::MAX_TICKS = 10 is Ruffle's own "sanity" limit,
which timer.c used to port: n=10,20,...,60,70 on frames 2-8). This is the w1
SWF (traces 'n=' on frames 2-9) byte-for-byte; the s27 w2-timers-land
stable-prefix variant (frames 2-9 empty) is retired now that timer.c drops
the cap (s27 w2b-timers-tail).

GOLDEN = real Flash Player 32 (LNX 32,0,0,465) trace of this SWF,
coordinator-run (SWFRecomp-CC-history:SWFRecompDocs/plans/session27-fanout-reports/
w1-local-oracles/w1-timers-robustness/caps_timers/flash.wrapped.txt,
identical to flash.direct.txt), verbatim. Ruffle is NOT an oracle here: its
exporter fires no timers.

Usage: create_test_swf.py <out.swf> timers
"""
import sys
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *
T = trace_concat
def setroot(name, code): return push('_root') + GETVAR + push(name) + code + SETMEM
kind = sys.argv[2]
N = 140 if kind == 'clone' else 70
if kind == 'clone':
    defs = sprite(1, [b'']) + place(1, 1, 'm')
    f1 = b''
    for i in range(N):
        f1 += callm('_root.m', 'duplicateMovieClip', 'c%d' % i, 100 + i)
    f1 += T('c139: ', typeof_('_root.c139'))
    for i in (5, 135):
        f1 += callm('_root.m', 'duplicateMovieClip', 'z%d' % i, 100 + i)
        f1 += T('after z%d at depth %d: typeof c%d = ' % (i, 100 + i, i), typeof_('_root.c%d' % i), ' z=', typeof_('_root.z%d' % i))
    frames = [f1 + STOP]
elif kind == 'timers':
    defs = b''
    fn = deffunc1('', [], setroot('n', get('_root.n') + push(1) + ADD2))
    f1 = setroot('n', push(0)) + setroot('fn', fn)
    for i in range(N):
        f1 += setroot('id%d' % i, push(10) + get('_root.fn') + push(2, 'setTimeout') + CALLF)
    f1 += T('id0=', get('_root.id0'), ' id63=', get('_root.id63'), ' id64=', get('_root.id64'), ' id69=', get('_root.id69'))
    frames = [f1] + [T('n=', get('_root.n'))] * 8 + [T('end n=', get('_root.n')) + STOP]
elif kind == 'watch':
    defs = b''
    h = deffunc1('', ['p', 'o', 'v'], setroot('wc', get('_root.wc') + push(1) + ADD2) + push('v') + GETVAR + RETURN)
    f1 = setroot('wc', push(0)) + setroot('h', h)
    for i in range(N):
        f1 += setroot('o%d' % i, push(0, 'Object') + NEWOBJ)
        f1 += setroot('r%d' % i, get('_root.h') + push('x', 2) + get('_root.o%d' % i) + push('watch') + CALLM)
    f1 += T('r0=', get('_root.r0'), ' r63=', get('_root.r63'), ' r64=', get('_root.r64'), ' r69=', get('_root.r69'))
    for i in range(N):
        f1 += push('_root') + GETVAR + push('o%d' % i) + GETMEM + push('x', 1) + SETMEM
    f1 += T('wc=', get('_root.wc'), ' o69.x=', get('_root.o69.x'))
    frames = [f1 + STOP]
open(sys.argv[1], 'wb').write(swf(8, defs, [doaction(f) for f in frames], fps=10))
