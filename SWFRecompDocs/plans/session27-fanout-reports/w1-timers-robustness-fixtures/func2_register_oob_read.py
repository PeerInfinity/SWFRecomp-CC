import sys
sys.path.insert(0, '.')
from avm1asm import *
T = trace_concat
def store(n): return op(0x87, bytes([n]))
# top level: global r1 = "G1", r3 = "G3"
top = push('G1') + store(1) + POP + push('G3') + store(3) + POP
# f: RegisterCount 2 (r0,r1 local).  read r1 (local, undefined), read r3 (past count), write r3 = 'L3', read r3
fbody = (T('in f: r1=', push(Reg(1))) + T('in f: r3=', push(Reg(3)))
         + push('L3') + store(3) + POP + T('in f after store: r3=', push(Reg(3))))
f = deffunc2('f', [], fbody, nregs=2)
# g: RegisterCount 0 (no locals)
gbody = T('in g: r1=', push(Reg(1))) + push('L1') + store(1) + POP
g = deffunc2('g', [], gbody, nregs=0)
main = top + f + g + callf('f') + T('top: r3=', push(Reg(3))) + callf('g') + T('top: r1=', push(Reg(1))) + STOP
open(sys.argv[1], 'wb').write(swf(int(sys.argv[2]), b'', [doaction(main)], fps=10))
