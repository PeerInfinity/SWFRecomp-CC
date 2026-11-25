#!/usr/bin/env python3
r"""s28 w1-loaded-shell-residuals: which order does Flash run two LOADED movies'
frames in when the holder CREATED later is the one LOADED earlier?

    parent test.swf (SWF8, 12 frames)
      f1: createEmptyMovieClip h1@1, h2@2 ; h2.loadMovie(childB.swf)
      f3: h1.loadMovie(childA.swf)
      f2..f12: trace "p<N> a<h1._currentframe> b<h2._currentframe>"
      f12: stop
    childA.swf 2 frames: "a1" | "a2"   (loops)
    childB.swf 2 frames: "b1" | "b2"   (loops)

Once both play, each tick prints one a-line and one b-line:
  * newest LOAD first (h1 loaded later)         -> aN before bN
  * newest HOLDER first (AVM1 execution list)   -> bN before aN
  * issue / depth order                          -> aN before bN only via depth
Golden: FLASH trace request (direct mode).
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

def parent():
    f1 = b''
    f1 += call_method(get_var('_root'), 'createEmptyMovieClip', 'h1', 1)
    f1 += call_method(get_var('_root'), 'createEmptyMovieClip', 'h2', 2)
    f1 += call_method(get_var('h2'), 'loadMovie', 'childB.swf')
    f1 += trace_str('p1')
    frames = [do_action(f1)]
    for n in range(2, 13):
        code = b''
        if n == 3:
            code += call_method(get_var('h1'), 'loadMovie', 'childA.swf')
        code += trace_expr('p', get_path('_root', '_currentframe'),
                           ' a', get_path('h1', '_currentframe'),
                           ' b', get_path('h2', '_currentframe'))
        if n == 12:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8)

def children():
    swf_file(HERE / 'childA.swf', [do_action(trace_str('a1')), do_action(trace_str('a2'))], version=8)
    swf_file(HERE / 'childB.swf', [do_action(trace_str('b1')), do_action(trace_str('b2'))], version=8)

if __name__ == '__main__':
    children(); parent()
