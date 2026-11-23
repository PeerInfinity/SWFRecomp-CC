#!/usr/bin/env python3
"""avm1_timer_function_form_activation: the function form of setInterval /
setTimeout (`setInterval(fn, ms, args...)`) runs `fn` in a fresh local
activation: `var` (DefineLocal) stays local, `arguments` is bound by name,
`this` is undefined -- for a DefineFunction (type-1) and a DefineFunction2
(type-2, no preload flags) callback.

s26 w1-avm1-dispatch-scope item 2 (s25 w2-netstream L3).
GOLDEN IS ANALYTIC (Ruffle-source-derived; the Ruffle exporter never fires
timers): core/src/timer.rs TimerCallback::Avm1Function -> func.call(
"[Timer Callback]", activation, Avm1Value::Undefined, params) ->
avm1/function.rs Avm1Function::exec: child_scope = new_local_scope(...),
local_this = this (= undefined) unless PRELOAD/SUPPRESS_THIS, arguments
defined as a local unless SUPPRESS_ARGUMENTS.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def cb_body(tagname, local, clear_id):
    return (
        push(local, 5) + DEFLOCAL
        + T(tagname + ' ' + local + '=', get(local), ' n=', get('arguments.length'),
            ' a0=', get('a0'), ' this=', push('this') + GETVAR + TYPEOF)
        + push(clear_id) + GETVAR + push(1, 'clearInterval') + CALLF + POP
    )


t1 = deffunc1('', ['a0'], cb_body('t1', 'lx', 'id1'))
t2 = deffunc2('', ['a0'], cb_body('t2', 'ly', 'id2'), nregs=1, flags=0, first_param_reg=0)
f1 = (
    push('id1') + push('A') + push(10) + t1 + push(3, 'setInterval') + CALLF + SETVAR
    + push('id2') + push('B') + push(10) + t2 + push(3, 'setInterval') + CALLF + SETVAR
)
f_idle = b''
f_last = T('leak: lx=', push('lx') + GETVAR + TYPEOF, ' ly=', push('ly') + GETVAR + TYPEOF) + STOP
open(sys.argv[1], 'wb').write(swf(7, b'', [doaction(f1)] + [f_idle] * 8 + [doaction(f_last)], fps=12))
