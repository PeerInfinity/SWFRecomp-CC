#!/usr/bin/env python3
"""avm1_goto_skipped_init_call: the FLUSH POINT of goto-queued DoInitActions.
Frame 1: _root.gotoAndPlay(3), then a call to a user function g (traces
'g f3'), then 'f1 after g'. Frames 2/3 carry DoInitActions. Flash runs the
queued inits (init2/init3) at the RETURN of g -- after g's body, before the
rest of the issuing script; with no call after the goto they run after the
issuing script (regression/avm1_goto_skipped_init_script).
Owner: tag.c tagDrainGotoInitActions / tagFlushGotoInitsAtCallReturn, called
from action.c actionCallFunction / actionCallMethod.

s27 w2b-timers-tail. GOLDEN = real Flash Player 32 (LNX 32,0,0,465) DIRECT
trace of this SWF, coordinator-run (SWFRecompDocs/plans/session27-fanout-reports/
w2-local-oracles/w2-timers-land/goto_skipped_init_call/flash.direct.txt).
Ruffle is NOT an oracle here: it runs DoInitActions at preload.

Usage: create_test_swf.py <out.swf>
"""
import sys, struct
import os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *
T = trace_concat
def initact(cid, code): return tag(59, struct.pack('<H', cid) + code + b'\0')
spr = lambda cid: sprite(cid, [b''])
g = deffunc1('', [], T('g f', get('_root._currentframe')))
f1 = doaction(push('_root') + GETVAR + push('g') + g + SETMEM + T('f1') + callm('_root', 'gotoAndPlay', 3)
              + push(0, 'g') + CALLF + POP + T('f1 after g'))
f2 = spr(2) + export(2, 'e2') + initact(2, T('init2 f', get('_root._currentframe'))) + doaction(T('f2'))
f3 = spr(3) + export(3, 'e3') + initact(3, T('init3 f', get('_root._currentframe'))) + doaction(T('f3') + STOP)
open(sys.argv[1], 'wb').write(swf(8, b'', [f1, f2, f3, doaction(T('f4'))], fps=10))
