#!/usr/bin/env python3
r"""Build test.swf + child.swf for regression/avm1_loaded_timeline_holder
(s26 w2-loaded-shell-phase2, phase 3).

WHAT THIS PINS DOWN
-------------------
**A movie loaded into a TIMELINE-placed clip (the holder HAS a display_obj)
places its frame-1 children into that clip's own list, the same list its
frames 2..N use.** Before, both loaders ran frame 1 against whatever list was
active (the parent's), while actionAdvancePlayingLevels ran frames 2..N in the
holder's sprite list -- so frame 1's PlaceObject2 at depth 1 collided with
the PARENT's depth-1 clip (refused, "Failed to place object at depth 1."), and
the loaded movie's `x` was never its own.

THE SHAPE
---------
    parent test.swf (SWF8, 5 frames)
      f1: sprite `x`@1 at (10,0) ; empty sprite `t`@2 ; t.loadMovie(child.swf)
      f2..f5: trace t<N> tt:<typeof t.x> tf:<t._currentframe>
    child.swf (SWF8, 3 frames)
      f1: sprite `x`@1 at (30,0); trace c1 <x._x>
      f2: trace c2 <x._x>        f3: trace c3; stop()

  * `c1 30` / `c2 30`: the child's `x` is its own (not the parent's 10, and
    not undefined on frame 2 -- frames 2..N already used the holder's list).
  * no "Warning: Failed to place object at depth 1." line.
  * NOT asserted: the parent-side reads `t.x._x` / `_root.x._x`. They still
    alias (the `_x` getter and child-MC identity are keyed on the instance
    NAME, and root's `x` and the loaded movie's `x` share it); reported as a
    lead in the w2 report. Flash: 30 and 10.

GOLDEN: output.txt is PREDICTED; see LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-report.md.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parents[4] / 'ruffle-tests/tests/swfs/regression/_lib'))  # parked fixture
from avm1asm import *  # noqa: E402,F401,F403


def parent():
    defs = define_sprite(2, [b''])
    f1 = place_object2(1, char_id=2, name='x', tx=200, ty=0)
    f1 += place_object2(2, char_id=2, name='t', tx=0, ty=0)
    f1 += do_action(call_method(get_var('t'), 'loadMovie', 'child.swf'))
    frames = [f1]
    for n in range(2, 6):
        code = trace_expr('t', get_path('_root', '_currentframe'),
                          ' tt:', get_path('t', 'x') + TYPEOF,
                          ' tf:', get_path('t', '_currentframe'))
        if n == 5:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8, prefix=defs)


def child():
    defs = define_sprite(1, [b''])
    swf_file(HERE / 'child.swf', [
        place_object2(1, char_id=1, name='x', tx=600, ty=0)
        + do_action(trace_expr('c1 ', get_path('x', '_x'))),
        do_action(trace_expr('c2 ', get_path('x', '_x'))),
        do_action(trace_str('c3') + STOP),
    ], version=8, prefix=defs)


if __name__ == '__main__':
    child()
    parent()
