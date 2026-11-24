#!/usr/bin/env python3
"""avm1_watch_long_name: watch() on a property whose name is >= 64 UTF-8 bytes
fires its handler (Object.prototype.watch on an Object, and MovieClip.watch on
_root). The watch table stored the name truncated to a 64-byte buffer but
compared it by full length at set time, so the watcher never fired
(action.c WatchEntry.prop_name / WATCH_NAME_MAX).

s27 w2-timers-land. GOLDEN IS ANALYTIC (watch semantics: the handler runs on
each assignment with (prop, old, new) and its return value is stored); a Flash
Player capture is requested under LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session27-fanout-reports/w2-timers-land-report.md.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
def setroot(name, code): return push('_root') + GETVAR + push(name) + code + SETMEM
LONG = 'p' + 'x' * 69          # 70 chars
MID = 'q' + 'y' * 62           # 63 chars (fit the old buffer: control)
h = deffunc1('', ['p', 'o', 'v'], T('w ', push('p') + GETVAR, ' ', push('o') + GETVAR, '->', push('v') + GETVAR) + push('v') + GETVAR + RETURN)
f1 = setroot('h', h) + setroot('o', push(0, 'Object') + NEWOBJ)
for nm in (MID, LONG):
    f1 += setroot('r', get('_root.h') + push(nm, 2) + get('_root.o') + push('watch') + CALLM)
    f1 += T('watch len=%d r=' % len(nm), get('_root.r'))
    f1 += push('_root') + GETVAR + push('o') + GETMEM + push(nm, 1) + SETMEM
    f1 += push('_root') + GETVAR + push('o') + GETMEM + push(nm, 2) + SETMEM
# timeline (MovieClip.watch) arm
f1 += setroot('r', get('_root.h') + push(LONG, 2) + get('_root') + push('watch') + CALLM)
f1 += T('mc watch r=', get('_root.r'))
f1 += push('_root') + GETVAR + push(LONG, 5) + SETMEM
f1 += T('mc val=', push('_root') + GETVAR + push(LONG) + GETMEM)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1 + STOP)], fps=10))
