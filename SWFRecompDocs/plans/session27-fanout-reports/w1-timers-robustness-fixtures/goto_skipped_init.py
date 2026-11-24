import sys, struct
sys.path.insert(0, '.')
from avm1asm import *
T = trace_concat
def initact(cid, code): return tag(59, struct.pack('<H', cid) + code + b'\0')
spr = lambda cid: sprite(cid, [b''])
mode = sys.argv[2]
cb = deffunc1('', [], get('_root.iid') + push(1, 'clearInterval') + CALLF + POP + T('cb') + callm('_root', 'gotoAndPlay', 3) + T('cb after f', get('_root._currentframe')))
if mode == 'script':
    f1 = doaction(T('f1') + callm('_root', 'gotoAndPlay', 3) + T('f1 after f', get('_root._currentframe')))
elif mode == 'timer':
    f1 = doaction(T('f1') + STOP + push('_root') + GETVAR + push('iid') + push(0) + cb + push(2, 'setInterval') + CALLF + SETMEM)
f2 = spr(2) + export(2, 'e2') + initact(2, T('init2 f', get('_root._currentframe'))) + doaction(T('f2'))
f3 = spr(3) + export(3, 'e3') + initact(3, T('init3 f', get('_root._currentframe'))) + doaction(T('f3') + STOP)
f4 = doaction(T('f4'))
open(sys.argv[1], 'wb').write(swf(8, b'', [f1, f2, f3, f4], fps=10))
