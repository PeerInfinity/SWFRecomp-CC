import sys
sys.path.insert(0, '.')
from avm1asm import *
T = trace_concat
def setroot(name, code): return push('_root') + GETVAR + push(name) + code + SETMEM
meth, extra = sys.argv[2], sys.argv[3:]
args = [int(x) for x in extra]
call = push(*reversed(args)) if args else b''
f1 = T('f1') + STOP + setroot('inf', call + push(10, meth) + get('_root') + push(3 + len(args), 'setInterval') + CALLF) + T('inf=', get('_root.inf'))
f2 = T('f2 cf=', get('_root._currentframe')) + get('_root.inf') + push(1, 'clearInterval') + CALLF + POP + STOP
f3 = T('f3 cf=', get('_root._currentframe')) + get('_root.inf') + push(1, 'clearInterval') + CALLF + POP + STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2), doaction(f3)], fps=10))
