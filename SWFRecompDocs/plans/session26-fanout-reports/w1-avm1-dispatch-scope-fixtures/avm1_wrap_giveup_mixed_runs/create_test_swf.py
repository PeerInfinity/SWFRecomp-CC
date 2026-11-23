#!/usr/bin/env python3
"""avm1_wrap_giveup_mixed_runs: SWF<=7 word wrap gives up on a first word too
wide for the field (at most one character fits) and lays the line out
unbroken -- also for a field whose HTML runs mix font sizes (the
textHeight/scroll path of mixed runs), not only for plain text. A SWF8 twin
breaks the word per character.

s26 w1-avm1-dispatch-scope item 7. Ruffle core/src/html/layout.rs /
line_wrapping: `if line_end <= 1 { return None }` (give up) for swf < 8.

Usage: create_test_swf.py <out.swf> <swf_version>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
ver = int(sys.argv[2]) if len(sys.argv) > 2 else 7


def field(name, depth, html):
    code = callm('this', 'createTextField', name, depth, 10, 10, 12, 200)
    for k, v in (('multiline', True), ('wordWrap', True), ('html', True)):
        code += get(name) + push(k, v) + SETMEM
    return code + get(name) + push('htmlText', html) + SETMEM


f1 = (
    field('p', 1, "<font size='12'>HelloWorld</font>")
    + field('m', 2, "<font size='12'>Hello</font><font size='20'>World</font>")
    + T('plain: maxscroll=', get('p.maxscroll'), ' bottomScroll=', get('p.bottomScroll'))
    + T('mixed: maxscroll=', get('m.maxscroll'), ' bottomScroll=', get('m.bottomScroll'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(ver, b'', [doaction(f1)]))
