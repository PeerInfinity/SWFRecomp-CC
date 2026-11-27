#!/usr/bin/env python3
"""avm1_attach_timeline_frame_order: on a natural advance, in what order do the
frame scripts of timeline-placed vs attachMovie'd clips run?

Sprite T (3 frames, loops): every frame traces `_name + " fN"`.
Sprite P (3 frames, loops): f1 places a timeline T child `pt` (depth 1) and
   (first time only) attaches T `pa` at depth 5 into itself; every frame traces.
Root (6 frames, root traces "root fN" in every frame script):
  f1: timeline T t10@10, T t30@30, P p40@40; DoAction attaches a5@5 (below),
      a20@20 (between), a50@50 (above), then P ap60@60 (attached holder).
  f2: timeline T t15@15 (after the attaches, between depths);
      DoAction attaches a25@25.
  f3..f5: root traces only; f6: stop.
Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct,
window-pinned), 2 captures byte-identical; the clips loop forever, so the
golden is the first 82 lines = ticks 1..6 (num_frames = 6), ending "root f6".
Flash's rule, every cell: ONE exec list, newest instantiation first, _root
last (= Ruffle avm1/runtime.rs clip_exec_list). Timeline, nested and attached
clips interleave by creation order, not by kind or depth (a5@5 runs before
p40@40); an attached clip is instantiated BEFORE its own frame-0 children
(ap60.pt runs before ap60); clips created on tick 2 (t15 placed, then a25
attached by root f2) run newest-first at the head of the list from tick 3.
A clip's first frame script (placement / attach) runs in queue order at its
creation point, not in exec-list order.
Regenerate:  python3 create_test_swf.py
"""
import sys
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (tag, define_sprite, define_shape_rect, do_action, swf_file,  # noqa: E402
                     call_method, get_var, get_path, place_object2, trace_expr,
                     trace_str, push, set_var, if_, STOP, GET_VARIABLE)

SHAPE, T, P = 1, 2, 3
defs = define_shape_rect(SHAPE, 4, 4, (0, 0, 255))


def tr(n):
    return do_action(trace_expr(get_path('this', '_name'), f' f{n}'))


defs += define_sprite(T, [place_object2(1, SHAPE, tx=0, ty=0) + tr(1), tr(2), tr(3)])

# P f1: if (!this.done) { this.done = true; this.attachMovie("T","pa",5); }
attach_pa = (push('done', True) + b'\x1d'  # local-ish var 'done' on this clip
             + call_method(get_var('this'), 'attachMovie', 'T', 'pa', 5))
p_f1 = (trace_expr(get_path('this', '_name'), ' f1')
        + get_var('done') + if_(len(attach_pa)) + attach_pa)
defs += define_sprite(P, [place_object2(1, T, name='pt', tx=0, ty=0) + do_action(p_f1),
                          tr(2), tr(3)])
defs += tag(56, struct.pack('<HH', 2, T) + b'T\x00' + struct.pack('<H', P) + b'P\x00')


def att(link, name, depth):
    return call_method(get_var('_root'), 'attachMovie', link, name, depth)


f1 = (trace_str('root f1') + att('T', 'a5', 5) + att('T', 'a20', 20)
      + att('T', 'a50', 50) + att('P', 'ap60', 60))
f2 = trace_str('root f2') + att('T', 'a25', 25)
frames = [place_object2(10, T, name='t10', tx=10, ty=10)
          + place_object2(30, T, name='t30', tx=30, ty=10)
          + place_object2(40, P, name='p40', tx=40, ty=10) + do_action(f1),
          place_object2(15, T, name='t15', tx=15, ty=30) + do_action(f2),
          do_action(trace_str('root f3')),
          do_action(trace_str('root f4')),
          do_action(trace_str('root f5')),
          do_action(trace_str('root f6') + STOP)]
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
