#!/usr/bin/env python3
"""avm1_timer_root_goto_stopped_nf: _root.nextFrame() from a setInterval callback (root stopped): as
avm1_timer_root_goto_stopped_gs.

s27 w2-timers-land. GOLDEN = real Flash Player 32 (LNX 32,0,0,465) trace of
this SWF, coordinator-run (SWFRecompDocs/plans/session27-fanout-reports/
w1-local-oracles/w1-timers-robustness/timer_root_goto_stopped_nf/flash.wrapped.txt). Ruffle is NOT an
oracle here: its exporter fires no timers and runs DoInitActions at preload.

Usage: create_test_swf.py <out.swf> nf
"""
import sys
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *
T = trace_concat
def setroot(name, code): return push('_root') + GETVAR + push(name) + code + SETMEM
mode = sys.argv[2]
body = callm('_root', 'nextFrame') if mode == 'nf' else callm('_root', 'gotoAndStop', 3)
foo = deffunc1('', [], body + T('after cf=', get('_root._currentframe')))
f1 = T('f1') + STOP + setroot('foo', foo) + setroot('inf', push(10, 'foo') + get('_root') + push(3, 'setInterval') + CALLF) + setroot('fn', push(10) + foo + push(2, 'setInterval') + CALLF) + get('_root.fn') + push(1, 'clearInterval') + CALLF + POP
f2 = T('f2 cf=', get('_root._currentframe')) + get('_root.inf') + push(1, 'clearInterval') + CALLF + POP + STOP
f3 = T('f3 cf=', get('_root._currentframe')) + get('_root.inf') + push(1, 'clearInterval') + CALLF + POP + STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2), doaction(f3)], fps=10))
