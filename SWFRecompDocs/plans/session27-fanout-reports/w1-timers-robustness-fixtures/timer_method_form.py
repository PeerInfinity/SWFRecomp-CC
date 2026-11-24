import sys, struct
sys.path.insert(0, '.')
from avm1asm import *
T = trace_concat
def setroot(name, code): return push('_root') + GETVAR + push(name) + code + SETMEM
# array receiver: _root.arr = new Array(); _root.arr.m = function(){ trace('arr m ' + this.length); clearInterval(_root.ia) }
arr_m = deffunc1('', [], T('arr m len=', get('this.length')) + get('_root.ia') + push(1, 'clearInterval') + CALLF + POP)
f1 = (T('f1')
  + setroot('arr', push(7, 1, 'Array') + NEWOBJ)
  + push('_root') + GETVAR + push('arr') + GETMEM + push('m') + arr_m + SETMEM
  + setroot('ia', push(10, 'm') + get('_root.arr') + push(3, 'setInterval') + CALLF)
  + T('ia=', get('_root.ia'))
  # clearInterval coercion: timer id + 2^32 must clear it (ToInt32)
  + STOP
  # MC native method: setInterval(_root, "nextFrame", 10)
  + setroot('inf', push(10, 'nextFrame') + get('_root') + push(3, 'setInterval') + CALLF)
  + T('inf=', get('_root.inf'))
)
t2fn = deffunc1('', [], T('t2 fired: clearInterval(id+2^32) did not clear it'))
f1 += setroot('t2', push(10) + t2fn + push(2, 'setInterval') + CALLF)
f1 += get('_root.t2') + push(4294967296.0) + ADD2 + push(1, 'clearInterval') + CALLF + POP
f1 += T('t2=', get('_root.t2'))
f2 = T('f2 reached via timer nextFrame') + get('_root.inf') + push(1, 'clearInterval') + CALLF + POP + STOP
f3 = T('f3')
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2), doaction(f3)], fps=10))
