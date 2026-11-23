#!/usr/bin/env python3
"""avm1_edittext_html_delete_runs: Backspace / Delete in an HTML input field
keep the remaining <font> runs (the deleted characters' runs shrink; no other
character changes format).

s26 w2-avm1-text-resolve item 5a. Ruffle edit_text.rs TextControlCode::
Backspace / Delete -> replace_text(from, to, "") -> FormatSpans::replace_text
(drains the cut spans, inserts an empty span, normalize() drops it). Flash
and Ruffle agree that a deletion never reformats the surviving text.
input.json: Backspace at the end (removes "D"), then -- after onChanged moves
the caret to 0 -- Delete (removes "A").

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, '..', '..', 'w1-avm1-dispatch-scope-fixtures'))
from avm1asm import *  # noqa

T = trace_concat


def col(i):
    return push(i + 1, i) + push(2) + get('tf') + push('getTextFormat') + CALLM + push('color') + GETMEM


branch = (T('  c2=', col(2))
          + push(0, 0) + push(2, 'Selection') + GETVAR + push('setSelection') + CALLM + POP)
onchg = deffunc2('', [], T('changed: text=', get('tf.text'), ' c0=', col(0), ' c1=', col(1),
                            ' n=', get('tf.length'))
                 + get('tf') + push('length') + GETMEM + push(3) + EQ2
                 + op(0x12)  # Not
                 + op(0x9d, struct.pack('<h', len(branch)))
                 + branch,
                 nregs=1, flags=0, first_param_reg=0)
f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('html', True) + SETMEM
    + get('tf') + push('htmlText', "<font color='#FF0000'>AB</font><font color='#0000FF'>CD</font>") + SETMEM
    + get('tf') + push('onChanged') + onchg + SETMEM
    + T('before: c0=', col(0), ' c1=', col(1), ' c2=', col(2), ' c3=', col(3))
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + push(4, 4) + push(2, 'Selection') + GETVAR + push('setSelection') + CALLM + POP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(b'')] + [doaction(b'')] * 2 + [doaction(STOP)]))
