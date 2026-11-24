#!/usr/bin/env python3
"""avm1_clone_depth_removed_reuse: a removed clone is forgotten by the
clone-depth table. m.duplicateMovieClip("a", 100); a.removeMovieClip();
m.duplicateMovieClip("a", 200); m.duplicateMovieClip("b", 100). Depth 100 is
empty when "b" takes it, so the live "a" (depth 200) must survive. The table
kept the removed clone's (100, "a") entry, so "b" evicted the LIVE "a" by name
(typeof a = undefined). Owner: tag_stubs.c ng_clone_forget, called from the
immediate arms of action.c actionRemoveSprite / MovieClip.removeMovieClip.

s27 w2-timers-land. GOLDEN IS ANALYTIC (Flash depth semantics: a clone only
replaces the occupant of ITS depth); a Flash Player capture is requested under
LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session27-fanout-reports/w2-timers-land-report.md.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
defs = sprite(1, [b'']) + place(1, 1, 'm')
f1 = callm('_root.m', 'duplicateMovieClip', 'a', 100)
f1 += T('a1: ', typeof_('_root.a'), ' d=', get('_root.a._name'))
f1 += callm('_root.a', 'removeMovieClip')
f1 += T('removed: ', typeof_('_root.a'))
f1 += callm('_root.m', 'duplicateMovieClip', 'a', 200)
f1 += callm('_root.m', 'duplicateMovieClip', 'b', 100)
f1 += T('after b@100: a=', typeof_('_root.a'), ' b=', typeof_('_root.b'))
f1 += callm('_root.m', 'duplicateMovieClip', 'c', 200)
f1 += T('after c@200: a=', typeof_('_root.a'), ' c=', typeof_('_root.c'))
open(sys.argv[1], 'wb').write(swf(8, defs, [doaction(f1 + STOP)], fps=10))
