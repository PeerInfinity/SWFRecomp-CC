#!/usr/bin/env python3
"""avm1_goto_current_frame_root: _root.gotoAndStop(current) / gotoAndPlay(current).

Root:
  f1: driver clip drv (onClipEvent(enterFrame)) placed; DoAction
  f2: places child r (x=10); DoAction traces, then once: r._x = 44,
      _root.gotoAndStop(2) from the frame's OWN script (current frame)
  f3: DoAction + stop
drv's enterFrame counts ticks; tick 3 calls _root.gotoAndStop(2) (root parked
on 2 = current frame), tick 5 sets r._y = 66 and calls _root.gotoAndPlay(2)
(current frame: Flash plays on to f3).

Pins whether a root goto to the shown frame re-places r / re-runs f2's
DoAction (it does not in Flash) and whether gotoAndPlay(current) plays.
drv removes itself on tick 8 so the log is bounded.

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).
Regenerate:  python3 create_test_swf.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (define_sprite, define_shape_rect, do_action, swf_file,  # noqa: E402
                     call_method, get_var, get_path, set_member, set_var, place_object2,
                     push, trace_expr, trace_str, if_, EQUALS2, ADD2, STOP,
                     EV_ENTER_FRAME, _rec)

NOT = _rec(0x12)
SHAPE, CHILD, DRV = 1, 2, 3
defs = define_shape_rect(SHAPE, 10, 10, (0, 128, 0))
defs += define_sprite(CHILD, [place_object2(1, SHAPE, tx=0, ty=0)])
defs += define_sprite(DRV, [b''])


def when(cond_code, body):
    """if (cond) body"""
    return cond_code + NOT + if_(len(body)) + body


def state(label):
    return trace_expr(label + ' cf=', get_path('_root', '_currentframe'),
                      ' r.x=', get_path('_root', 'r', '_x'),
                      ' r.y=', get_path('_root', 'r', '_y'))


tick = get_path('_root', 'tk')
ef = set_member(get_var('_root'), 'tk', tick + push(1) + ADD2)
ef += trace_expr('drv tick ', tick)
ef += state('  pre')
ef += when(tick + push(3) + EQUALS2,
           call_method(get_var('_root'), 'gotoAndStop', 2) + state('  after gotoAndStop(2)'))
ef += when(tick + push(5) + EQUALS2,
           set_member(get_path('_root', 'r'), '_y', 66)
           + call_method(get_var('_root'), 'gotoAndPlay', 2) + state('  after gotoAndPlay(2)'))
# bound the log: drv removes itself on tick 8
ef += when(tick + push(8) + EQUALS2,
           call_method(get_var('this'), 'swapDepths', 1000)
           + call_method(get_var('this'), 'removeMovieClip'))

frames = []
frames.append(place_object2(20, DRV, name='drv', clip_actions=[(EV_ENTER_FRAME, ef)])
              + do_action(set_var('tk', 0) + trace_str('root f1 run')))

f2 = state('root f2 run')
f2 += when(get_var('once') + NOT,
           set_var('once', True)
           + set_member(get_var('r'), '_x', 44)
           + call_method(get_var('_root'), 'gotoAndStop', 2)
           + state('root f2 after self gotoAndStop(2)'))
frames.append(place_object2(5, CHILD, name='r', tx=200, ty=0) + do_action(f2))
frames.append(do_action(state('root f3 run') + STOP))
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
