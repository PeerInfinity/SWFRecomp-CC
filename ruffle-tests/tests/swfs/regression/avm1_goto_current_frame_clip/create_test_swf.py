#!/usr/bin/env python3
"""avm1_goto_current_frame_clip: mc.gotoAndStop(current) / mc.gotoAndPlay(current)
on an attachMovie'd clip (h, n) AND a timeline-placed clip (t) whose current
frame re-places children.

Sprite S (3 frames, every frame script traces and stops):
  f1: place child sprites a (depth 1), b (depth 2, y=10), c (depth 3, y=20)
  f2: MOVE depth 1 to x=50; RemoveObject depth 3 (c); place NEW d (depth 4,
      x=5) and e (depth 5, x=7); DoAction
  f3: stop (no trace)
Root:
  f1: t placed by the timeline; attachMovie h; attachMovie n then
      n.gotoAndStop(1) in the same script (N's tileMC pattern)
  f2: h/t.gotoAndStop(2) (a real goto)
  f3: script mutates a._x, b._y, d._y, e._x; then gotoAndStop(2) again
      (current frame, the Doodle Jump breakable pattern)
  f4: gotoAndPlay(2) (current frame)
  f5..f6: observe (does the clip play on? does f2 re-run?)

Question pinned: does a goto to the frame the clip already shows re-run the
frame's tags / DoAction (CI's ng_gotoFrameByMC same-frame branch) or only
stop/play (the browser guard, Ruffle's AVM1 no_op_goto)?

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).
Regenerate:  python3 create_test_swf.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (tag, define_sprite, define_shape_rect, do_action, swf_file,  # noqa: E402
                     call_method, get_var, get_path, set_member, place_object2,
                     remove_object2, push, trace_expr, TYPEOF, STOP)
import struct  # noqa: E402

SHAPE, CHILD, S = 1, 2, 3
defs = define_shape_rect(SHAPE, 10, 10, (0, 0, 255))
defs += define_sprite(CHILD, [place_object2(1, SHAPE, tx=0, ty=0)])


def me(label):
    return do_action(trace_expr(get_path('this', '_name'), ' ' + label + ' run') + STOP)


defs += define_sprite(S, [
    place_object2(1, CHILD, name='a', tx=0, ty=0)
    + place_object2(2, CHILD, name='b', tx=0, ty=200)
    + place_object2(3, CHILD, name='c', tx=0, ty=400)
    + me('S f1'),
    place_object2(1, tx=1000, ty=0, move=True)
    + remove_object2(3)
    + place_object2(4, CHILD, name='d', tx=100, ty=0)
    + place_object2(5, CHILD, name='e', tx=140, ty=0)
    + me('S f2'),
    # f3 traces nothing: the dumps' cf=3 shows the play-on. (Flash runs the
    # newer attached h's frame script before timeline t's on a natural
    # advance; CI runs t first -- an advance-order question outside this
    # fixture, s29 browser-gotoandstop-current report.)
    do_action(STOP),
])
defs += tag(56, struct.pack('<HH', 1, S) + b'S\x00')


def dump(tagname, c):
    return trace_expr(
        tagname + ' ' + c + ' cf=', get_path(c, '_currentframe'),
        ' a.x=', get_path(c, 'a', '_x'),
        ' b.y=', get_path(c, 'b', '_y'),
        ' c=', get_path(c, 'c') + TYPEOF,
        ' d=', get_path(c, 'd') + TYPEOF, ' d.y=', get_path(c, 'd', '_y'),
        ' e.x=', get_path(c, 'e', '_x'))


def each(fn):
    return b''.join(fn(c) for c in ('h', 't'))


def goto(method, frame):
    return lambda c: call_method(get_var(c), method, frame)


def mutate(c):
    code = set_member(get_path(c, 'a'), '_x', 99)
    code += set_member(get_path(c, 'b'), '_y', 77)
    # d: script-made property edit only. (Script-REMOVING a sprite's timeline
    # child -- swapDepths(100) + removeMovieClip -- is a separate CI defect,
    # pinned by regression/avm1_nested_child_swapdepths_remove.)
    code += set_member(get_path(c, 'd'), '_y', 55)
    code += set_member(get_path(c, 'e'), '_x', 33)
    return code


frames = []
f1 = call_method(get_var('_root'), 'attachMovie', 'S', 'h', 1)
f1 += call_method(get_var('_root'), 'attachMovie', 'S', 'n', 2)
f1 += set_member(get_var('n'), '_x', 100)
f1 += call_method(get_var('n'), 'gotoAndStop', 1)
f1 += each(lambda c: dump('r1', c)) + dump('r1', 'n')
frames.append(place_object2(10, S, name='t', tx=0, ty=1000) + do_action(f1))

f2 = each(goto('gotoAndStop', 2)) + each(lambda c: dump('r2', c)) + dump('r2', 'n')
frames.append(do_action(f2))

f3 = each(mutate) + each(lambda c: dump('r3 pre', c))
f3 += each(goto('gotoAndStop', 2)) + each(lambda c: dump('r3 post', c))
frames.append(do_action(f3))

f4 = each(lambda c: dump('r4 pre', c))
f4 += each(goto('gotoAndPlay', 2)) + each(lambda c: dump('r4 post', c))
frames.append(do_action(f4))

frames.append(do_action(each(lambda c: dump('r5', c))))
frames.append(do_action(each(lambda c: dump('r6', c)) + STOP))
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
