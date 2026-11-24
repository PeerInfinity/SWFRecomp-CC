#!/usr/bin/env python3
"""avm1_edittext_cut_copy_selection: TextControl Copy / Cut act on the
selection, not the whole text; with a collapsed caret both are no-ops (the
clipboard keeps its previous content and the text is untouched).

s27 w1-avm1-leftovers item 5. Ruffle edit_text.rs is_text_control_applicable
(Copy|Cut need !password && !selection.is_caret()) and text_control_input
(Copy: clipboard = text[sel]; Cut: same, then replace_text(sel, "") and
caret at sel.start, changed = true -> onChanged).

Golden: analytic (Ruffle edit_text.rs). Needs TextControl (clipboard) input,
which the Flash oracle cannot replay; Ruffle test-runner confirmation is a
standing LOCAL ORACLE REQUEST (s27 w2-avm1-leftovers-land report).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
caret = callm('Selection', 'getCaretIndex', keep=True)


def sel(a, b):
    return callm('Selection', 'setSelection', a, b)


def report(tag):
    return T(tag, get('tf.text'), ' caret=', caret)


onchg = deffunc2('', [], T('changed: ', get('tf.text')), nregs=1, flags=0, first_param_reg=0)
f1 = (
    callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('text', 'ABCDE') + SETMEM
    + get('tf') + push('onChanged') + onchg + SETMEM
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + sel(1, 3)
    + report('f1: ')
)
# input: Copy (clipboard = "BC")
f2 = report('f2 after Copy [1,3): ') + sel(0, 0)
# input: Paste at 0
f3 = report('f3 after Paste at 0: ') + sel(2, 4)
# input: Cut [2,4)
f4 = report('f4 after Cut [2,4): ') + sel(3, 3)
# input: Cut, Copy with a collapsed caret (no-ops)
f5 = report('f5 after caret Cut+Copy: ') + sel(0, 0)
# input: Paste at 0 (clipboard still the Cut text)
f6 = report('f6 after Paste at 0: ') + STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f) for f in (f1, f2, f3, f4, f5, f6)]))
