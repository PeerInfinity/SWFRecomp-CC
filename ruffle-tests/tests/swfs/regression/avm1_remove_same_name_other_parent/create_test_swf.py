#!/usr/bin/env python3
r"""Build test.swf for regression/avm1_remove_same_name_other_parent
(s26 w2-loaded-shell-phase2: the general parent-blind invalidation lead).

WHAT THIS PINS DOWN
-------------------
**A timeline RemoveObject2 invalidates the clip IT removed, not a same-named
clip at the same depth under a different parent.**
`actionInvalidateCachedMovieClip(name, swf_depth)` used to take the first
live cached MovieClip with that (name, depth), whatever its parent. Two
sprites that each place a child `btn` at depth 1 share that key, so when one
sprite's timeline removes its `btn`, whichever `btn` was cached FIRST died.

THE SHAPE (SWF8, hand-assembled)
    sprite A (id 2): 1 frame, empty            -- the `btn` symbol
    sprite S1 (id 3): f1 place A as btn@1 | f2 RemoveObject2(1); stop()
    sprite S2 (id 4): f1 place A as btn@1 | f2 stop()
    root f1: place S2 as s2@1 THEN S1 as s1@2 (child clips are built eagerly
             in placement order, so s2's `btn` is the first-cached one)
             and set s2.btn.v = "keep", s1.btn.v = "gone"
    root f2..f4: trace s1:<typeof s1.btn> s2:<typeof s2.btn> n:<s2.btn._name>
                 v:<s2.btn.v>

  * from f2 on, s1.btn is undefined and s2.btn stays a movieclip named btn
    that still carries v:keep. The bug kills s2's cached clip; typeof/_name
    still look right (the next lookup rebuilds a fresh clip from s2's display
    entry) but the rebuilt clip has lost `v` -> v:undefined.

GOLDEN: output.txt is PREDICTED; see LOCAL ORACLE REQUESTS in
SWFRecomp-CC-history:SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-report.md.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F401,F403


def row(prefix):
    return trace_expr(prefix, ' s1:', get_path('s1', 'btn') + TYPEOF,
                      ' s2:', get_path('s2', 'btn') + TYPEOF,
                      ' n:', get_path('s2', 'btn', '_name'),
                      ' v:', get_path('s2', 'btn', 'v'))


def main():
    defs = define_sprite(2, [b''])
    defs += define_sprite(3, [place_object2(1, char_id=2, name='btn', tx=0, ty=0),
                              remove_object2(1) + do_action(STOP)])
    defs += define_sprite(4, [place_object2(1, char_id=2, name='btn', tx=0, ty=0),
                              do_action(STOP)])
    # s2 (the keeper) is placed FIRST so its `btn` is created and cached first:
    # child MovieClips are built eagerly in placement order.
    f1 = place_object2(1, char_id=4, name='s2', tx=0, ty=0)
    f1 += place_object2(2, char_id=3, name='s1', tx=0, ty=0)
    f1 += do_action(set_member(get_path('s2', 'btn'), 'v', 'keep')
                    + set_member(get_path('s1', 'btn'), 'v', 'gone')
                    + trace_expr('f1 s2:', get_path('s2', 'btn') + TYPEOF,
                               ' s1:', get_path('s1', 'btn') + TYPEOF))
                    
    frames = [f1, do_action(row('f2')), do_action(row('f3')), do_action(row('f4') + STOP)]
    swf_file(HERE / 'test.swf', frames, version=8, prefix=defs)


if __name__ == '__main__':
    main()
