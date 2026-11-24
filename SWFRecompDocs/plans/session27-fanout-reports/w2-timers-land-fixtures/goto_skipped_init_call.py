"""Flash-oracle probe for the goto-init flush point (s27 w2-timers-land report,
action_execution_order_test12). Frame 1: _root.gotoAndPlay(3), then a call to
a function g (traces 'g'), then 'f1 after g'. Frames 2/3 carry DoInitActions.
If Flash prints init2/init3 before 'g', the queued inits flush at a function
call; after 'f1 after g', they run after the issuing script (current model).
Usage (from this folder): python3 goto_skipped_init_call.py out.swf
"""
import sys, struct
sys.path.insert(0, '.')
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
