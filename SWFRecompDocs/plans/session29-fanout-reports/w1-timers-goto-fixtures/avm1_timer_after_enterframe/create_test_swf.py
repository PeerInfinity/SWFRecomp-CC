#!/usr/bin/env python3
"""avm1_timer_after_enterframe (s29 w1-timers-goto, item 2): WHERE in an AVM1
tick does Flash check timers that became overdue during busy code?

Root, SWF 8, 10 fps (100 ms frames), 12 frames, root plays; every frame's
DoAction traces `F<n>`; _root.onEnterFrame traces `ef<k> cf=<_currentframe>`
(k = call count). Three probes, each a setTimeout(.., 10) followed by a
getTimer() busy-wait in the SAME handler, so the timer is overdue (by >= 30 ms)
when the handler returns. Flash never runs a timer re-entrantly inside AS, so
each probe is ordered by player structure, not by wall-clock luck:

  A  frame-3 DoAction:   setTimeout(TA, 10); busy 150 ms (> the frame period:
                         the next frame is overdue too when it returns)
  B  ef call #5:         setTimeout(TB, 10); busy 40 ms (< the frame period)
  C  ef call #8:         setTimeout(TC, 10); busy 150 ms (> the frame period)

Each timer traces `T? cf=<_currentframe> last=<last marker>`, where the last
marker is the most recent `F<n>` / `ef<k>` string. Candidate check points:
right after the handler (`last=` the handler's own marker, same cf), after the
rest of this tick's actions, in idle before the next advance (same cf), or
after the next advance but before its DoAction (cf+1, last= the old marker).
The golden must come from Flash (several runs: the ORDER should be stable,
nothing here depends on sub-frame timing).

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
GETTIME = op(0x34)
SUB = op(0x0b)
LESS2 = op(0x48)
NOT = op(0x12)


def setroot(name, code):
    return push('_root') + GETVAR + push(name) + code + SETMEM


def busy(ms):
    """_root.t0 = getTimer(); while (getTimer() - _root.t0 < ms) {}"""
    loop = GETTIME + get('_root.t0') + SUB + push(ms) + LESS2
    jump_back = -(len(loop) + 5)
    return setroot('t0', GETTIME) + loop + op(0x9d, struct.pack('<h', jump_back))


def mark(code_val):
    """trace(v); _root.last = v  (code_val leaves the marker on the stack)"""
    return setroot('last', code_val) + get('_root.last') + TRACE


def timer_fn(label):
    return deffunc1('', [], T(label + ' cf=', get('_root._currentframe'), ' last=', get('_root.last')))


def if_eq(path, val, body):
    cond = get(path) + push(val) + EQ2 + NOT
    return cond + op(0x9d, struct.pack('<h', len(body))) + body


def probe(label, ms):
    return (push(10) + timer_fn(label) + push(2, 'setTimeout') + CALLF + POP + busy(ms)
            + T(label + ' armed'))


EFK = get('_root.k')
ef_body = (setroot('k', EFK + push(1) + ADD2)
           + mark(push('ef') + EFK + ADD2 + push(' cf=') + ADD2 + get('_root._currentframe') + ADD2)
           + if_eq('_root.k', 5, probe('TB', 40))
           + if_eq('_root.k', 8, probe('TC', 150)))

frames = []
for n in range(1, 13):
    a = mark(push('F%d' % n))
    if n == 1:
        a += setroot('k', push(0)) + setroot('onEnterFrame', deffunc1('', [], ef_body))
    if n == 3:
        a += probe('TA', 150)
    if n == 12:
        a += STOP + setroot('onEnterFrame', push(UNDEF) if False else push(0))
    frames.append(doaction(a))
open(sys.argv[1], 'wb').write(swf(8, b'', frames, fps=10))
