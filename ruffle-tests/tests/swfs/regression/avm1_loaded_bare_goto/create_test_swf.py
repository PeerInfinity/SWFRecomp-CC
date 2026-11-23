#!/usr/bin/env python3
r"""Build test.swf + child.swf + child2.swf + child3.swf for
regression/avm1_loaded_bare_goto (s26 w2-loaded-shell-phase2, phase 4).

WHAT THIS PINS DOWN
-------------------
**A bare (target-less) goto in a LOADED movie's own frame code moves THAT
movie's playhead, never the parent's.**

`gotoAndStop(2)` written in a loaded movie's frame script compiles to
ActionGotoFrame(1) + ActionStop with no target, and `nextFrame()` to
ActionNextFrame. Before the fix both reached the runtime's ROOT goto
(`actionGotoFrame` / `actionNextFrame` -> next_frame / manual_next_frame,
which are the MAIN movie's globals), so a child's own goto rewound or advanced
the parent: the "last frame rewinds parent" family through a different door.
The method form (`this.gotoAndStop`) was already routed in phase 1
(`actionChildMovieGoto`, a6a696bf2).

THE SHAPE
---------
    parent test.swf (SWF8, 10 frames, hand-assembled)
      f1: createEmptyMovieClip h@1, g@2, k@3
          h.loadMovie(child.swf) g.loadMovie(child2.swf) k.loadMovie(child3.swf)
      f2..f10: trace "p<_root._currentframe> h<..> g<..> k<..>"
      f5: also k.gotoAndStop(1)          (method form on a ONE-frame holder)
      f10: stop

    child.swf  (3 frames)  f1 "c1" | f2 "c2" | f3 "c3"; gotoAndStop(2)  (bare)
    child2.swf (3 frames)  f1 "d1"; nextFrame() (bare) | f2 "d2" | f3 "d3"
    child3.swf (1 frame)   f1 "e1"; gotoAndStop(1) (bare, on its only frame)

WHAT EACH ROW DISCRIMINATES
---------------------------
  * the `p<N>` sequence must run 2,3,...,10 exactly once each: any child goto
    that leaked to the root repeats or skips a parent frame (child3's
    goto(1) would rewind the parent to frame 1 and re-run the loads).
  * `h` must read 1,2,3 then pin at 2, with a second "c2" (Flash runs the
    goto target frame's DoAction).
  * `g` must pin at 2 after "d1","d2"; "d3" must never print.
  * `k` stays 1; neither the bare goto nor the parent's k.gotoAndStop(1)
    moves anything (a one-frame movie has no advance entry -- phase 4 bullet 3).

GOLDEN: output.txt is PREDICTED (SWFRecomp post-fix output, hand-checked
against the Flash rules above). LOCAL ORACLE REQUEST in
SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-report.md.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F401,F403


def parent():
    f1 = b''
    for name, depth, url in (('h', 1, 'child.swf'), ('g', 2, 'child2.swf'), ('k', 3, 'child3.swf')):
        f1 += call_method(get_var('_root'), 'createEmptyMovieClip', name, depth)
        f1 += call_method(get_var(name), 'loadMovie', url)
    f1 += trace_str('p1')
    frames = [do_action(f1)]
    for n in range(2, 11):
        code = b''
        if n == 5:
            code += call_method(get_var('k'), 'gotoAndStop', 1)
        code += trace_expr('p', get_path('_root', '_currentframe'),
                           ' h', get_path('h', '_currentframe'),
                           ' g', get_path('g', '_currentframe'),
                           ' k', get_path('k', '_currentframe'))
        if n == 10:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8)


def children():
    swf_file(HERE / 'child.swf', [
        do_action(trace_str('c1')),
        do_action(trace_str('c2')),
        do_action(trace_str('c3') + goto_frame(1) + STOP),
    ], version=8)
    swf_file(HERE / 'child2.swf', [
        do_action(trace_str('d1') + NEXT_FRAME),
        do_action(trace_str('d2')),
        do_action(trace_str('d3')),
    ], version=8)
    swf_file(HERE / 'child3.swf', [
        do_action(trace_str('e1') + goto_frame(0) + STOP),
    ], version=8)


if __name__ == '__main__':
    children()
    parent()
