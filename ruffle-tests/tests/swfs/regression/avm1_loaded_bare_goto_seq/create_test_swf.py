#!/usr/bin/env python3
r"""s27 w1-per-movie-dl-phase3: delivery-tick-INSENSITIVE rewrite of the held
s26 fixture avm1_loaded_bare_goto. Same three child movies and the same bare
gotos, but no row depends on WHEN a load lands in the tick or on the order of
sibling movies / root within a tick (the two things Ruffle and our runtime
disagree on, and the Flash order is not pinned by any corpus row). Each child
appends to its own log on _root; the parent appends its own frame numbers;
everything is traced once on the parent's frame 10.

  P: 1..10 once each  -> no child goto leaked to the root playhead
  h: c1,c2,c3,c2, pinned at 2   (bare gotoAndStop(2) from frame 3 runs frame 2's DoAction)
  g: d1,d2, pinned at 2         (bare nextFrame() from frame 1 moves AND stops; d3 never)
  k: e1, at 1                   (bare goto to the current frame, and the parent's
                                 k.gotoAndStop(1), are no-ops)
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

def app(var, s):
    return set_member(get_var('_root'), var, concat(get_path('_root', var), s))

def parent():
    f1 = b''
    for v in ('Lh', 'Lg', 'Lk', 'P'):
        f1 += set_var(v, push(''))
    for name, depth, url in (('h', 1, 'child.swf'), ('g', 2, 'child2.swf'), ('k', 3, 'child3.swf')):
        f1 += call_method(get_var('_root'), 'createEmptyMovieClip', name, depth)
        f1 += call_method(get_var(name), 'loadMovie', url)
    f1 += app('P', '1,')
    frames = [do_action(f1)]
    for n in range(2, 11):
        code = set_member(get_var('_root'), 'P', concat(get_path('_root', 'P'), get_path('_root', '_currentframe'), ','))
        if n == 5:
            code += call_method(get_var('k'), 'gotoAndStop', 1)
        if n == 10:
            code += trace_expr('P:', get_var('P'))
            for h, v in (('h', 'Lh'), ('g', 'Lg'), ('k', 'Lk')):
                code += trace_expr(h + ':', get_var(v), ' cf:', get_path(h, '_currentframe'))
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8)

def children():
    swf_file(HERE / 'child.swf', [do_action(app('Lh', 'c1,')), do_action(app('Lh', 'c2,')),
                                  do_action(app('Lh', 'c3,') + goto_frame(1) + STOP)], version=8)
    swf_file(HERE / 'child2.swf', [do_action(app('Lg', 'd1,') + NEXT_FRAME), do_action(app('Lg', 'd2,')),
                                   do_action(app('Lg', 'd3,'))], version=8)
    swf_file(HERE / 'child3.swf', [do_action(app('Lk', 'e1,') + goto_frame(0) + STOP)], version=8)

if __name__ == '__main__':
    children(); parent()
