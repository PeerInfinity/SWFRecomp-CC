#!/usr/bin/env python3
"""avm1_timeline_selfgoto_child_replace: a TIMELINE sprite's own frame script
loops it back with gotoAndPlay(1), and the target frame re-places a child
sprite that the previous frame removed.

  k (2 frames): f1 traces `k f1 cf=`, f2 traces `k f2` and stops.
  s (3 frames): f1 places k as "k"; f2 removes it; f3 does gotoAndPlay(1).
  root: places s, then traces s._currentframe and s.k._currentframe for 9
  frames.

It pins the self-goto apply pass's replay tail (ng_apply_pending_sprite_
self_gotos, tag.c): the rebuilt target frame's NEW child must exist, run its
own frame-1 script, and advance from there, the same tick in every build.
CI runs process_sprite_needs_init for it; browser-WASM did not apply a timeline
sprite's self-goto at all before s30 browser-timeline-self-goto.

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).

Regenerate:  python3 create_test_swf.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (define_sprite, do_action, swf_file, place_object2,  # noqa: E402
                     remove_object2, get_path, trace_expr, trace_str,
                     STOP, PLAY, goto_frame)

K, S = 1, 2
defs = define_sprite(K, [
    do_action(trace_expr('k f1 cf=', get_path('this', '_currentframe'))),
    do_action(trace_str('k f2') + STOP),
])
defs += define_sprite(S, [
    place_object2(1, char_id=K, name='k') + do_action(trace_str('s f1')),
    remove_object2(1) + do_action(trace_str('s f2')),
    do_action(trace_str('s f3') + goto_frame(0) + PLAY),
])

frames = []
for n in range(1, 10):
    body = trace_expr('root f%d s.cf=' % n, get_path('s', '_currentframe'),
                       ' k.cf=', get_path('s', 'k', '_currentframe'))
    if n == 9:
        body += STOP
    fr = do_action(body)
    if n == 1:
        fr = place_object2(1, char_id=S, name='s') + fr
    frames.append(fr)
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
