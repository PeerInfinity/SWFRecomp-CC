#!/usr/bin/env python3
"""avm1_edittext_html_typed_runs: typing into an HTML input field keeps the
existing <font> runs; the typed character takes the format of the span after
the caret, or the new-text format at the end of the text.

s26 w1-avm1-dispatch-scope item 5. GOLDEN IS ANALYTIC (Ruffle-source-derived:
the exporter has no input). Ruffle core/src/html/text_format.rs
FormatSpans::replace_text: `new_tf = spans.get(end_pos).text_format()`, else
`default_format` when appending. input.json types "C" at the caret (2 = end)
and then "D" at 0.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def col(i):
    return push(i + 1, i) + push(2) + get('tf') + push('getTextFormat') + CALLM + push('color') + GETMEM


onchg = deffunc2('', [], T('changed: text=', get('tf.text'), ' c0=', col(0), ' c1=', col(1), ' c2=', col(2),
                            ' n=', get('tf.length'))
                 + get('tf') + push('length') + GETMEM + push(3) + EQ2
                 + op(0x12)  # Not
                 + op(0x9d, struct.pack('<h', len(push(0, 0) + push(2, 'Selection') + GETVAR + push('setSelection') + CALLM + POP)))
                 + push(0, 0) + push(2, 'Selection') + GETVAR + push('setSelection') + CALLM + POP,
                 nregs=1, flags=0, first_param_reg=0)
f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('html', True) + SETMEM
    + get('tf') + push('htmlText', "<font color='#FF0000'>AB</font>") + SETMEM
    + get('tf') + push('onChanged') + onchg + SETMEM
    + T('before: c0=', col(0), ' c1=', col(1))
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + push(2, 2) + push(2, 'Selection') + GETVAR + push('setSelection') + CALLM + POP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(b'')] + [doaction(b'')] * 2 + [doaction(STOP)]))
