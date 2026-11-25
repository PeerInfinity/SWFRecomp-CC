#!/usr/bin/env python3
r"""s28 w1-loaded-shell-residuals: a loaded movie's OWN bare gotoAndPlay. Flash
(avm1_loaded_bare_goto capture) runs a gotoAndStop target's DoAction on the NEXT
tick, after the root's script. This pins the PLAY form: on the tick the deferred
target script runs, does the movie ALSO advance (target+1's script in the same
tick), and what does _currentframe read in between?

    parent test.swf (SWF8, 12 frames): f1 createEmptyMovieClip h@1; h.loadMovie(child.swf)
                                       f2..f12 trace "p<N> h<h._currentframe>"; f12 stop
    child.swf 4 frames: "c1" | "c2" | "c3" + gotoAndPlay(2) (bare GotoFrame + Play) | "c4"

Golden: FLASH trace request (direct mode).
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

def parent():
    f1 = call_method(get_var('_root'), 'createEmptyMovieClip', 'h', 1)
    f1 += call_method(get_var('h'), 'loadMovie', 'child.swf')
    f1 += trace_str('p1')
    frames = [do_action(f1)]
    for n in range(2, 13):
        code = trace_expr('p', get_path('_root', '_currentframe'), ' h', get_path('h', '_currentframe'))
        if n == 12:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8)

def children():
    swf_file(HERE / 'child.swf', [do_action(trace_str('c1')), do_action(trace_str('c2')),
                                  do_action(trace_str('c3') + goto_frame(1) + PLAY),
                                  do_action(trace_str('c4'))], version=8)

if __name__ == '__main__':
    children(); parent()
