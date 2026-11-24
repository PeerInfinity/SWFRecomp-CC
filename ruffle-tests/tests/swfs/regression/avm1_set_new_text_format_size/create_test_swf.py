#!/usr/bin/env python3
"""avm1_set_new_text_format_size: setNewTextFormat({size, font}) only formats
text inserted LATER; the existing text keeps its size/face, so textWidth /
textHeight / getTextFormat(0) are unchanged until the next `text =`.

s27 w1-avm1-leftovers item 4 (s26 landed the colour half). Ruffle
text_field.rs set_new_text_format -> EditText::set_new_text_format only
stores the format; replace_text uses it for new text.

Golden: Flash Player 32 trace, with Linux Flash's default device font name
`Times` replaced by `Times New Roman` (the Windows/corpus spelling, e.g.
avm1/edittext_default_format). The argument is a PLAIN object built with
InitObject, not a TextFormat: Flash 32 and the Ruffle exporter both ignore it
entirely (getNewTextFormat().size stays 12, metrics unchanged). The deferral
of a REAL TextFormat's size/font is not pinned here (Flash oracle pending).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat


def fmt0(prop):
    return push(0, 1) + get('tf') + push('getTextFormat') + CALLM + push(prop) + GETMEM


def report(tag):
    return T(tag, ' size0=', fmt0('size'), ' font0=', fmt0('font'),
             ' nsize=', push(0) + get('tf') + push('getNewTextFormat') + CALLM + push('size') + GETMEM)


newfmt = push('size', 40, 'font', '_serif', 2) + INITOBJ
f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 300, 100)
    + get('tf') + push('text', 'AB') + SETMEM
    + report('before')
    + push('w0') + get('tf.textWidth') + SETVAR
    + push('h0') + get('tf.textHeight') + SETVAR
    + newfmt + push(1) + get('tf') + push('setNewTextFormat') + CALLM + POP
    + report('after setNewTextFormat')
    + T('unchanged w=', get('tf.textWidth') + get('w0') + op(0x49), ' h=', get('tf.textHeight') + get('h0') + op(0x49))
    + get('tf') + push('text', 'AB') + SETMEM
    + report('after text=')
    + T('grew h=', get('tf.textHeight') + get('h0') + op(0x48) + op(0x12))   # !(h < h0)... Less2 then Not
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
