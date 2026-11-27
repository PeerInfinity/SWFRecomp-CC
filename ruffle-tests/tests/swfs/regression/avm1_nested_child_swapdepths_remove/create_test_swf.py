#!/usr/bin/env python3
"""avm1_nested_child_swapdepths_remove: a TIMELINE child (d) of a sprite --
attached (h) and timeline-placed (t) -- is moved with d.swapDepths(100) and
then removed with d.removeMovieClip(); a sibling (a) left at its timeline
depth ignores removeMovieClip.

Found s29 browser-gotoandstop-current (while building
avm1_goto_current_frame_clip): every build kept `h.d` alive, because swapDepths
(ng_updateDisplayDepth) and removeMovieClip only touched the GLOBAL display
list by name, so the entry in the parent sprite's display list never moved or
cleared and `h.d` re-resolved to it. Fixed s30 browser-nested-swapdepths-remove
(tag_stubs.c ng_nestedUpdateDisplayDepth / ng_nestedRemoveDisplayEntry).

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).
Regenerate:  python3 create_test_swf.py
"""
import sys
import struct
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F403
SHAPE, CHILD, S = 1, 2, 3
defs = define_shape_rect(SHAPE, 10, 10, (0, 0, 255))
defs += define_sprite(CHILD, [place_object2(1, SHAPE, tx=0, ty=0)])
defs += define_sprite(S, [place_object2(1, CHILD, name='a', tx=0, ty=0) + place_object2(4, CHILD, name='d', tx=100, ty=0) + do_action(STOP)])
defs += tag(56, struct.pack('<HH', 1, S) + b'S\x00')
def probe(c):
    code = trace_expr(c+' d depth=', call_method(get_path(c,'d'),'getDepth',discard=False))
    code += call_method(get_path(c, 'd'), 'swapDepths', 100)
    code += trace_expr(c+' d depth after swap=', call_method(get_path(c,'d'),'getDepth',discard=False))
    code += call_method(get_path(c, 'd'), 'removeMovieClip')
    code += trace_expr(c+' d after remove=', get_path(c,'d')+TYPEOF)
    code += call_method(get_path(c, 'a'), 'removeMovieClip')
    code += trace_expr(c+' a after remove (no swap)=', get_path(c,'a')+TYPEOF)
    return code
f1 = call_method(get_var('_root'), 'attachMovie', 'S', 'h', 1)
frames=[place_object2(10, S, name='t', tx=0, ty=1000) + do_action(f1), do_action(probe('h')+probe('t')+STOP)]
swf_file(HERE/'test.swf', frames, version=8, w=200, h=150, prefix=defs)
