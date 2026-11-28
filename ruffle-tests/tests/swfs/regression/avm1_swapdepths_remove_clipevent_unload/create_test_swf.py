#!/usr/bin/env python3
"""avm1_swapdepths_remove_clipevent_unload: a TIMELINE-placed root clip with
onClipEvent(unload) + onClipEvent(enterFrame) is moved to a positive depth with
swapDepths(10) and then removed with removeMovieClip() from a root frame script.

Rows:
  * `c ef N`     -- c's enterFrame handler (N = tick, set by the root scripts);
  * `c unload`   -- c's onClipEvent(unload) must fire exactly once, on the
                    removal tick (it is queued at removeMovieClip time);
  * after the remove, c must be gone (`typeof c` = "", no more `c ef`);
  * control `k`: same handlers but NOT swapped -- removeMovieClip on a negative
    (timeline) depth is a no-op, so k lives on and keeps its enterFrame.

Found s30 browser-clip-event-order: the browser's ng_queue_slot_unload_events
was a no-op stub (graphics_stubs.c), so `c unload` never printed in the
browser. Fixed s30 browser-pending-finalize.

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).
Hand-assembled SWF 8 (MTASC cannot emit onClipEvent clip actions).
Regenerate:  python3 create_test_swf.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F403

root = get_var('_root')
SPR = 1
defs = define_sprite(SPR, [b''])


def handlers(nm):
    return [(EV_ENTER_FRAME, trace_expr(nm + ' ef ', get_path('_root', 't'))),
            (EV_UNLOAD, trace_expr(nm + ' unload t=', get_path('_root', 't'),
                                   ' typeof=', get_path('_root', nm) + TYPEOF))]


def tick(n):
    return set_member(root, 't', push(n))


f1 = (place_object2(1, char_id=SPR, name='c', tx=0, ty=0, clip_actions=handlers('c'))
      + place_object2(2, char_id=SPR, name='k', tx=0, ty=0, clip_actions=handlers('k'))
      + do_action(tick(1) + trace_str('f1')))
f2 = do_action(tick(2)
               + trace_expr('c depth=', call_method(get_path('_root', 'c'), 'getDepth', discard=False))
               + call_method(get_path('_root', 'c'), 'swapDepths', 10)
               + trace_expr('c depth after swap=', call_method(get_path('_root', 'c'), 'getDepth', discard=False))
               + call_method(get_path('_root', 'c'), 'removeMovieClip')
               + trace_expr('c after remove=', get_path('_root', 'c') + TYPEOF)
               + call_method(get_path('_root', 'k'), 'removeMovieClip')
               + trace_expr('k after remove (no swap)=', get_path('_root', 'k') + TYPEOF))
f3 = do_action(tick(3) + trace_expr('f3 c=', get_path('_root', 'c') + TYPEOF,
                                    ' k=', get_path('_root', 'k') + TYPEOF))
f4 = do_action(tick(4) + trace_str('f4') + STOP)
swf_file(HERE / 'test.swf', [f1, f2, f3, f4], version=8, frame_rate=10, prefix=defs)
