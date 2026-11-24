#!/usr/bin/env python3
"""avm1_edittext_maxchars_clips_insertion: typing into an input field with
maxChars clips the INSERTED text to the room left (maxChars - (length -
selection length)); with no room the keystroke is dropped (no edit, no
onChanged). The existing text is never truncated.

s27 w2-avm1-leftovers-land lead 6. Ruffle edit_text.rs available_chars /
text_input. Field: maxChars 5, text "ABCD", caret at 1; keys X Y Z.
  X -> "AXBCD" caret 2 (room 1) -> changed #1
  Y, Z -> no room: dropped, no onChanged.
  (master truncated the tail instead: "AXYBC" caret 3, then "AXYZB" caret 4,
  each with onChanged.)
Flash oracle: run_trace.py --type XYZ --type-after "ready".
Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
caret = callm('Selection', 'getCaretIndex', keep=True)

onchg = deffunc2('', [], (
    push('n') + get('n') + op(0x50) + SETVAR            # n = n + 1 (Increment)
    + T('changed #', get('n'), ': ', get('tf.text'), ' caret=', caret)
), nregs=1, flags=0, first_param_reg=0)
f1 = (
    push('n', 0) + SETVAR
    + callm('this', 'createTextField', 'tf', 1, 10, 10, 200, 40)
    + get('tf') + push('type', 'input') + SETMEM
    + get('tf') + push('maxChars', 5) + SETMEM
    + get('tf') + push('text', 'ABCD') + SETMEM
    + get('tf') + push('onChanged') + onchg + SETMEM
    + get('tf') + push(1, 'Selection') + GETVAR + push('setFocus') + CALLM + POP
    + callm('Selection', 'setSelection', 1, 1)
    + T('ready: ', get('tf.text'), ' caret=', caret)
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
