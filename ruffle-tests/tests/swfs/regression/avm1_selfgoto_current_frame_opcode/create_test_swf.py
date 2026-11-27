#!/usr/bin/env python3
"""avm1_selfgoto_current_frame_opcode: a clip (attachMovie'd or timeline-placed) whose OWN
frame-1 script is the opcode pair GotoFrame(0) + Play (AS `gotoAndPlay(1)`)
while it already shows frame 1. Doodle Jump's `coin` (charId 2) and `Inverse`
(charId 17) item clips are exactly this (1-frame sprites); before c91637b7a the
same-frame branch of ng_gotoFrameByMC re-ran the frame, which re-queued the
script into the running drain -> an infinite loop (the s28 DJ browser freeze
after PLAY, s29 browser-dj-freeze report). The timeline-placed clips (c2, d2)
went through ng_gotoFrameCurrentSprite's record + queue and still looped
forever at c91637b7a in both native modes.

Sprite C (1 frame):  f1: trace(_name+" C f1"); gotoAndPlay(1)
Sprite D (2 frames): f1: trace(_name+" D f1 cf="+_currentframe); gotoAndPlay(1)
                     f2: stop()
Root: f1 places c2 (C) and d2 (D) on the timeline, then attaches c1 (C), d1 (D);
f2..f4 dump the clips' _currentframe; f4 stops.

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).
Regenerate:  python3 create_test_swf.py
"""
import sys
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (tag, define_sprite, define_shape_rect, do_action, swf_file,  # noqa: E402
                     call_method, get_var, get_path, place_object2, trace_expr,
                     goto_frame, PLAY, STOP)

SHAPE, C, D = 1, 2, 3
defs = define_shape_rect(SHAPE, 10, 10, (0, 0, 255))
defs += define_sprite(C, [
    place_object2(1, SHAPE, tx=0, ty=0)
    + do_action(trace_expr(get_path('this', '_name'), ' C f1') + goto_frame(0) + PLAY),
])
defs += define_sprite(D, [
    place_object2(1, SHAPE, tx=0, ty=0)
    + do_action(trace_expr(get_path('this', '_name'), ' D f1 cf=',
                           get_path('this', '_currentframe')) + goto_frame(0) + PLAY),
    # f2 traces nothing: on a natural advance Flash runs the newer attached
    # d1's script before timeline d2's and every build runs d2 first (s29
    # browser-gotoandstop-current report 5.2, an advance-order question outside
    # this fixture). The dumps' d1=2 / d2=2 show the play-on.
    do_action(STOP),
])
defs += tag(56, struct.pack('<HH', 2, C) + b'C\x00' + struct.pack('<H', D) + b'D\x00')


def dump(label):
    return trace_expr(label, ' c1=', get_path('c1', '_currentframe'),
                      ' d1=', get_path('d1', '_currentframe'),
                      ' c2=', get_path('c2', '_currentframe'),
                      ' d2=', get_path('d2', '_currentframe'))


f1 = call_method(get_var('_root'), 'attachMovie', 'C', 'c1', 1)
f1 += call_method(get_var('_root'), 'attachMovie', 'D', 'd1', 2)
f1 += dump('r1')
frames = [place_object2(10, C, name='c2', tx=50, ty=50)
          + place_object2(11, D, name='d2', tx=80, ty=50) + do_action(f1),
          do_action(dump('r2')),
          do_action(dump('r3')),
          do_action(dump('r4') + STOP)]
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
