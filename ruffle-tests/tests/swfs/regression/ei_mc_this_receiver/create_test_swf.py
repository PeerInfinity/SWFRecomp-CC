#!/usr/bin/env python3
"""ei_mc_this_receiver: ExternalInterface.addCallback(name, clip, fn) calls fn
with `this` = the clip, for a DefineFunction2 (preload-this) and a plain
DefineFunction callback.

s26 w2-avm1-text-resolve (w1-avm1-dispatch-scope lead: the type-2 flag pair
missing in actionEI_callInternalInterface). Golden is ANALYTIC (Ruffle
core/src/external.rs Callback::Avm1 -> method.call(name, activation, this,
args) with the stored `this`; the exporter has no ExternalInterface host).
test_harness.c invokes "t2" then "t1" after frame 1.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'w1-avm1-dispatch-scope-fixtures'))
from avm1asm import *  # noqa

T = trace_concat
R1 = Reg(1)
f2 = deffunc2('', [], T('t2 this.v=', push(R1) + push('v') + GETMEM,
                         ' name=', push(R1) + push('_name') + GETMEM,
                         ' typeof=', push(R1) + TYPEOF) + push('ok2') + RETURN,
              nregs=2, flags=PRELOAD_THIS, first_param_reg=2)
f1 = deffunc1('', [], T('t1 this.v=', get('this.v'), ' name=', get('this._name'),
                         ' typeof=', push('this') + GETVAR + TYPEOF) + push('ok1') + RETURN)


def add_cb(name, fn):
    return (fn + push('m') + GETVAR + push(name, 3) + get('flash.external.ExternalInterface')
            + push('addCallback') + CALLM + POP)


main = (
    callm('_root', 'createEmptyMovieClip', 'm', 1)
    + get('m') + push('v', 7) + SETMEM
    + add_cb('t2', f2)
    + add_cb('t1', f1)
    + T('registered')
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(main)]))
