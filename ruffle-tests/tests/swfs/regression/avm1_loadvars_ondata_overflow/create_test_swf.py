#!/usr/bin/env python3
"""avm1_loadvars_ondata_overflow: 20 MovieClip.loadVariables() calls issued in
ONE frame must each fire their clip's onData (Flash fires one onData per
completed load). s28 w1-leads item 2: our deferred onData queue was a fixed
MAX_PENDING_FORM_DATA = 16 (action.c avm1QueueFormDataEvent) and silently
dropped the 17th..20th event.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

N = 20
T = trace_concat
ondata = deffunc1('', [], T('onData ', get('this._name'), ' a=', get('this.a')))
f1 = b''
for i in range(N):
    n = 'm%d' % i
    f1 += callm('this', 'createEmptyMovieClip', n, i + 1)
    f1 += get(n) + push('onData') + ondata + SETMEM
    f1 += callm(n, 'loadVariables', 'vars.txt')
f1 += T('frame 1 end')
f2 = T('frame 2')
f3 = T('frame 3') + STOP
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f) for f in (f1, f2, f3)]))
