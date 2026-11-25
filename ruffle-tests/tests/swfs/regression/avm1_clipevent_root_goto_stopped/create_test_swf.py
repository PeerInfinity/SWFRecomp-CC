#!/usr/bin/env python3
"""avm1_clipevent_root_goto_stopped — a clip's onClipEvent(enterFrame) calls
`_root.gotoAndStop(3)` on a STOPPED root (Doodle Jump's game-over pattern:
`if (_root.gameOver) { ...; _root.gotoAndStop(3); }` in the hero's handler).

Pins down s28 browser-root-goto: the browser's method-form root goto used to run
only the skipped frames' tags and leave the target frame to the next tick's
frame func; since s28 it is the CI arm (ng_executeGotoTagsOnly + the main
loop's ng_runPendingRootGoto). Rows:
  * `ef n cf` — the handler, before and after the goto (n = tick count);
  * `f3 cf`   — frame 3's DoAction (runs in the goto tick, after the handler);
  * frame 2's DoAction must never run (`f2` absent);
  * frame 3 removes `c`, so its handler stops.
Expected output is the Flash 32 projector trace (tools/flash-oracle), never ours.
Hand-assembled SWF 8 (MTASC cannot emit onClipEvent clip actions).
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

root = get_var('_root')
handler = (set_member(root, 'n', get_path('_root', 'n') + push(1) + ADD2)
           + trace_expr('ef ', get_path('_root', 'n'), ' cf=', get_path('_root', '_currentframe'))
           + call_method(root, 'gotoAndStop', 3)
           + trace_expr('after cf=', get_path('_root', '_currentframe')))
defs = define_sprite(1, [b''])
f1 = (place_object2(1, char_id=1, name='c', tx=0, ty=0, clip_actions=[(EV_ENTER_FRAME, handler)])
      + do_action(set_member(root, 'n', 0) + trace_expr('f1 cf=', get_path('_root', '_currentframe')) + STOP))
f2 = do_action(trace_expr('f2 cf=', get_path('_root', '_currentframe')))
f3 = remove_object2(1) + do_action(trace_expr('f3 cf=', get_path('_root', '_currentframe'), ' c=', get_path('_root', 'c') + TYPEOF) + STOP)
swf_file(HERE / 'test.swf', [f1, f2, f3], version=8, frame_rate=10, prefix=defs)
