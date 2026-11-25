#!/usr/bin/env python3
"""avm1_edittext_restrict_onchanged: does a TYPED key that TextField.restrict
filters out fire onChanged, and does it delete the selection?

s28 w1-text-edit-tail (a); lead from s27 w2b-avm1-text-edit "open".
Field: input, restrict "0-9", text "1234", focused, selection [1,3) ("23").
Typed keys (Flash: run_trace.py --type X5Y --type-after ready):
  X  filtered, with a selection
  5  allowed
  Y  filtered, at a bare caret
A root onEnterFrame poller traces "state: <text> sel=<b>,<e>" whenever the text
or selection changes, so the selection half is visible even when no onChanged
fires.

Candidate answers:
  SWFRecomp (master): X and Y are dropped before the edit: no onChanged, the
    selection survives; "5" replaces "23" -> 154 sel=2,2. 1 changed line.
  Ruffle (edit_text.rs text_input: filter_allowed -> "" -> replace_text(sel,"")
    -> on_changed): X DELETES "23" (14 sel=1,1) and fires onChanged; Y fires
    onChanged with nothing to delete. 3 changed lines.
  avm2/edittext_restrict_events (Kamil Jarosz, Flash-verified AVM2 corpus row):
    a filtered 'y' DOES dispatch `change` in AVM2.
Golden: FLASH (LOCAL ORACLE REQUEST; output.txt holds Ruffle's analytic answer
until the capture lands).
Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
NOT = op(0x12)
EQ2 = op(0x49)


def if_(cond, body):
    """if (cond) body  -> cond; Not; If(skip body)"""
    return cond + NOT + op(0x9d, struct.pack('<h', len(body))) + body


sel = (callm('Selection', 'getBeginIndex', keep=True), ',',
       callm('Selection', 'getEndIndex', keep=True))

onchg = deffunc2('', [], (
    push('n') + get('n') + op(0x50) + SETVAR
    + T('changed #', get('n'), ': ', get('tf.text'), ' sel=', *sel)
), nregs=1, flags=0, first_param_reg=0)

poll = deffunc2('', [], (
    push('s') + get('tf.text') + push(' sel=') + ADD2
    + callm('Selection', 'getBeginIndex', keep=True) + ADD2 + push(',') + ADD2
    + callm('Selection', 'getEndIndex', keep=True) + ADD2 + SETVAR
    + if_(get('s') + get('last') + EQ2 + NOT,
          T('state: ', get('s')) + push('last') + get('s') + SETVAR)
), nregs=1, flags=0, first_param_reg=0)

f1 = (
    push('n', 0) + SETVAR
    + callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('restrict', '0-9') + SETMEM
    + get('tf') + push('text', '1234') + SETMEM
    + get('tf') + push('onChanged') + onchg + SETMEM
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + callm('Selection', 'setSelection', 1, 3)
    + push('last') + get('tf.text') + push(' sel=') + ADD2
    + callm('Selection', 'getBeginIndex', keep=True) + ADD2 + push(',') + ADD2
    + callm('Selection', 'getEndIndex', keep=True) + ADD2 + SETVAR
    + T('ready: ', get('last'))
    + push('this') + GETVAR + push('onEnterFrame') + poll + SETMEM
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
