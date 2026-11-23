#!/usr/bin/env python3
"""avm1_set_new_text_format_color: setNewTextFormat({color}) changes only the
format of FUTURE text: existing spans keep their colour (getTextFormat and the
rendered pixels), textColor reads the new-text-format colour (Ruffle
text_field.rs text_color -> new_text_format().color), and the next `text =`
takes it.

s26 w1-avm1-dispatch-scope item 5. Trace-only: every row already matches
Ruffle on master. The defect is render-side (a plain field draws with
dynamic_props textColor, which our setNewTextFormat arm overwrites, so "AB"
turns red); a pixel twin needs an EMBEDDED font (device text does not render
in the exporter or in a cloud graphics build).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def fmt_color(obj, idx):
    return push(idx) + push(1) + get(obj) + push('getTextFormat') + CALLM + push('color') + GETMEM


f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('text', 'AB') + SETMEM
    + push('red') + push(0, 'TextFormat') + NEWOBJ + SETVAR
    + get('red') + push('color', 0xFF0000) + SETMEM
    + get('red') + push('size', 24) + SETMEM
    + get('red') + push(1) + get('tf') + push('setNewTextFormat') + CALLM + POP
    + T('textColor=', get('tf.textColor'))
    + T('span0.color=', fmt_color('tf', 0))
    + T('newfmt.color=', push(0) + get('tf') + push('getNewTextFormat') + CALLM + push('color') + GETMEM)
    + callm('this', 'createTextField', 'tf2', 2, 10, 60, 200, 40)
    + get('red') + push(1) + get('tf2') + push('setNewTextFormat') + CALLM + POP
    + get('tf2') + push('text', 'CD') + SETMEM
    + T('tf2 span0.color=', fmt_color('tf2', 0))
)
f2 = STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2)], w=220, h=110))
