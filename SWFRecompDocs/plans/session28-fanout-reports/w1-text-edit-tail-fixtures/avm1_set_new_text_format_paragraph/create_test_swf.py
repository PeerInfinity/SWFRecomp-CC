#!/usr/bin/env python3
"""avm1_set_new_text_format_paragraph: does setNewTextFormat leave the EXISTING
text's leading / margins / indent / blockIndent / letterSpacing alone (as it
does size/font, Flash-confirmed in regression/avm1_set_new_text_format_instance),
and does TYPED text pick them up?

s28 w1-text-edit-tail (b); lead from s27 w2b-avm1-text-edit "New unclaimed
leads". Multiline input field, text "AB\\rCD" (2 lines, device font).
  1. before: getTextFormat(0) paragraph keys; w0/h0 = textWidth/textHeight
  2. setNewTextFormat(TextFormat{leading 20, leftMargin 30, rightMargin 15,
     indent 10, blockIndent 5, letterSpacing 4}) -> getTextFormat(0),
     getNewTextFormat(), textWidth/textHeight == w0/h0 ?
  3. typed "E" at the end (Flash: run_trace.py --type E --type-after ready)
     -> onChanged: getTextFormat(0) and getTextFormat(5) (the typed char), h==h0
  4. text = "AB\\rCD" -> getTextFormat(0), h==h0, h>h0
Widths/heights are traced only as comparisons (device-font metrics differ
between hosts).

Candidates:
  Ruffle (edit_text.rs set_new_text_format -> TextSpans::set_default_format;
    replace_text at the end gives the typed text the default format; set_text
    rebuilds the spans from it): step 2 fmt0 all 0 and w/h unchanged; step 3
    fmt0 all 0, fmt5 the new values; step 4 fmt0 the new values, h grew.
  SWFRecomp master: getTextFormat keeps the span model (same as Ruffle) but
    the field-wide _tf_leading/_tf_leftMargin/_tf_letterSpacing/... layout keys
    are written at once, so textWidth/textHeight move at step 2.
Golden: FLASH (LOCAL ORACLE REQUEST). output.txt holds Ruffle's analytic
answer until the capture lands.
Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
KEYS = (('L', 'leading'), ('lm', 'leftMargin'), ('rm', 'rightMargin'),
        ('in', 'indent'), ('bi', 'blockIndent'), ('ls', 'letterSpacing'))


def fmt_at(idx, prop):
    return push(idx, 1) + get('tf') + push('getTextFormat') + CALLM + push(prop) + GETMEM


def nfmt(prop):
    return push(0) + get('tf') + push('getNewTextFormat') + CALLM + push(prop) + GETMEM


def fmt_line(tag, getter):
    parts = [tag]
    for i, (k, p) in enumerate(KEYS):
        parts += [(' ' if i else ' ') + k + '=', getter(p)]
    return T(*parts)


def cmp_line(tag):
    return T(tag, ' w==w0 ', get('tf.textWidth') + get('w0') + op(0x49),
             ' h==h0 ', get('tf.textHeight') + get('h0') + op(0x49),
             ' h>h0 ', get('h0') + get('tf.textHeight') + op(0x48))   # Less2(h0, h)


onchg = deffunc2('', [], (
    fmt_line('typed fmt0', lambda p: fmt_at(0, p))
    + fmt_line('typed fmt5', lambda p: fmt_at(5, p))
    + T('typed text=', get('tf.text'), ' len=', get('tf.length'))
    + cmp_line('typed')
    + get('tf') + push('text', 'AB\rCD') + SETMEM
    + fmt_line('after text= fmt0', lambda p: fmt_at(0, p))
    + cmp_line('after text=')
), nregs=1, flags=0, first_param_reg=0)

newfmt = (push('_f', 0, 'TextFormat') + NEWOBJ + SETVAR
          + get('_f') + push('leading', 20) + SETMEM
          + get('_f') + push('leftMargin', 30) + SETMEM
          + get('_f') + push('rightMargin', 15) + SETMEM
          + get('_f') + push('indent', 10) + SETMEM
          + get('_f') + push('blockIndent', 5) + SETMEM
          + get('_f') + push('letterSpacing', 4) + SETMEM
          + get('_f'))

f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 300, 150)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('multiline', True) + SETMEM
    + get('tf') + push('text', 'AB\rCD') + SETMEM
    + fmt_line('before fmt0', lambda p: fmt_at(0, p))
    + push('w0') + get('tf.textWidth') + SETVAR
    + push('h0') + get('tf.textHeight') + SETVAR
    + newfmt + push(1) + get('tf') + push('setNewTextFormat') + CALLM + POP
    + fmt_line('snf fmt0', lambda p: fmt_at(0, p))
    + fmt_line('snf new', nfmt)
    + cmp_line('snf')
    + get('tf') + push('onChanged') + onchg + SETMEM
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + callm('Selection', 'setSelection', 5, 5)
    + T('ready: caret=', callm('Selection', 'getCaretIndex', keep=True))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
