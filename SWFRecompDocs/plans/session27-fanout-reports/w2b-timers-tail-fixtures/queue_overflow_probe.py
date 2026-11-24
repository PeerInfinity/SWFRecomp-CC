"""Flash-oracle probe (s27 w2b-timers-tail, LOCAL ORACLE REQUEST): the
deferred-unload and deferred-failed-load queues past their old fixed caps
(MAX_DEFERRED_UNLOADS 32, MAX_DEFERRED_FAILED_LOADS 16; now growable).
Frame 1: 40 createEmptyMovieClip u0..u39 -> unloadMovie() each; 24
createEmptyMovieClip f0..f23 -> loadMovie("missing_<i>.swf") each (no such
file). Frame 2: trace _totalframes / _framesloaded of the first and the
over-cap entries (u0, u31, u32, u39; f0, f15, f16, f23). With the old caps
the over-cap clips kept their frame-1 state. Run with --wrapped? NO: direct.
Usage: python3 queue_overflow_probe.py out.swf
"""
import sys
sys.path.insert(0, '.')
from avm1asm import *
T = trace_concat
f1 = b''
for i in range(40):
    f1 += callm('_root', 'createEmptyMovieClip', 'u%d' % i, 10 + i)
    f1 += callm('_root.u%d' % i, 'unloadMovie')
for i in range(24):
    f1 += callm('_root', 'createEmptyMovieClip', 'f%d' % i, 100 + i)
    f1 += callm('_root.f%d' % i, 'loadMovie', 'missing_%d.swf' % i)
f1 += T('f1 u32 tf=', get('_root.u32._totalframes'), ' f16 tf=', get('_root.f16._totalframes'))
f2 = b''
for n in ('u0', 'u31', 'u32', 'u39', 'f0', 'f15', 'f16', 'f23'):
    f2 += T(n, ' tf=', get('_root.%s._totalframes' % n), ' fl=', get('_root.%s._framesloaded' % n))
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2 + STOP)], fps=10))
