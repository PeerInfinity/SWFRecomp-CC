#!/usr/bin/env python3
"""avm1_type2_mc_receiver_dispatch: a DefineFunction2 body with PreloadThis
invoked with a MovieClip receiver by the non-CallMethod dispatch arms sees
`this` as that clip (this._name, this.v reads land on the clip).

s26 w1-avm1-dispatch-scope item 2 (s25 w2-netstream L2): the arms that pass a
MOVIECLIP this_var to a type-2 body need INV_EVENT_THIS_MC |
INV_MC_THIS_NULL_PTR, else the raw MovieClip* reaches the prologue as an
ASObject. Arms exercised: Object.watch callback on a clip, Function.call / Function.apply with a clip, AsBroadcaster listener clip,
MovieClip.prototype.addProperty getter on a clip, and the same body via a
CallMethod control row.

Each body: trace(tag + ": " + this._name + " v=" + this.v)  (this in r1).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
R1 = Reg(1)


def body(tagname, ret=None):
    b = T(tagname + ': ', push(R1) + push('_name') + GETMEM, ' v=', push(R1) + push('v') + GETMEM)
    if ret is not None:
        b += push(ret) + RETURN
    return b


def fn(tagname, ret=None, params=()):
    return deffunc2('', list(params), body(tagname, ret), nregs=8, flags=PRELOAD_THIS, first_param_reg=2)


def setmem(obj, prop, valcode):
    return get(obj) + push(prop) + valcode + SETMEM


f1 = (
    callm('_root', 'createEmptyMovieClip', 'mc', 1)
    + setmem('mc', 'v', push(7))
    # control: CallMethod
    + setmem('mc', 'ctl', fn('callmethod'))
    + callm('mc', 'ctl')
    # Function.call / apply
    + push('f') + fn('call/apply') + SETVAR
    + push('mc') + GETVAR + push(1) + get('f') + push('call') + CALLM + POP
)
f1 += push(0) + op(0x42)  # [] (InitArray with 0 elems)
f1 += push('mc') + GETVAR + push(2) + get('f') + push('apply') + CALLM + POP
# watch: mc.watch("w", fn); mc.w = 1
f1 += fn('watch', ret=1, params=('p', 'o', 'n'))
f1 = f1  # watch callback returns new value
f1 += push('w') + push(2) + get('mc') + push('watch') + CALLM + POP
f1 += setmem('mc', 'w', push(1))
# addProperty getter on the clip
f1 += push(NULL) + fn('getter', ret='g') + push('gp') + push(3) + get('mc') + push('addProperty') + CALLM + POP
f1 += T('getter->', get('mc.gp'))
# AsBroadcaster listener = clip
f1 += push('b') + push(0, 'Object') + NEWOBJ + SETVAR
f1 += get('b') + push(1) + get('AsBroadcaster') + push('initialize') + CALLM + POP
f1 += setmem('mc', 'onPing', fn('broadcast'))
f1 += get('mc') + push(1) + get('b') + push('addListener') + CALLM + POP
f1 += push('onPing') + push(1) + get('b') + push('broadcastMessage') + CALLM + POP
f1 += STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
