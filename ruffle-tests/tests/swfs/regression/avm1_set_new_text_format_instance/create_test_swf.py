#!/usr/bin/env python3
"""avm1_set_new_text_format_instance: setNewTextFormat({size, font}) only formats
text inserted LATER; the existing text keeps its size/face, so textWidth /
textHeight / getTextFormat(0) are unchanged until the next `text =`.

s27 w1-avm1-leftovers item 4 (s26 landed the colour half). Ruffle
text_field.rs set_new_text_format -> EditText::set_new_text_format only
stores the format; replace_text uses it for new text.

TWIN of regression/avm1_set_new_text_format_size with a REAL TextFormat
(`new TextFormat()`, size 40, font _serif) instead of a plain object. Golden:
analytic (Ruffle set_new_text_format stores the format; existing text keeps its
size until the next `text =`), CONFIRMED by Flash Player 32 direct mode (s27
w2-local-oracles/w2-avm1-leftovers-land) except the Linux projector's default
device-font token `Times`, swapped back to the Windows `Times New Roman` every
corpus golden reads. Landed by s27 w2b-avm1-text-edit.

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


newfmt = (push('_f', 0, 'TextFormat') + NEWOBJ + SETVAR
          + get('_f') + push('size', 40) + SETMEM + get('_f') + push('font', '_serif') + SETMEM
          + get('_f'))
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
