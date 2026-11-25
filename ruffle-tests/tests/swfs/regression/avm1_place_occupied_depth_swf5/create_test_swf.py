#!/usr/bin/env python3
"""avm1_place_occupied_depth_swf5: Flash's SWF-5 keep-both rule for a
PlaceObject (Move=0) onto an OCCUPIED depth (s28 w2-occupied-depth).

Flash 32 (direct pinned) on gnash misc-ming place_object_test (SWF 5) keeps
BOTH objects at one depth, the newcomer BEHIND the occupant (`#passed: 7`);
the same SWF patched to v6+ refuses the newcomer. Flash prints no
"Failed to place object" line in either case (that is a Ruffle log line).

Two pairs, all placed on frame 1 of the root timeline (SWF 5, 200x100):
  depth 5: shape sa (red 40x40 at 10,10), then shape sb (black at 30,30)
  depth 7: sprite ma (blue 40x40 at 100,10), then sprite mb (green at 120,30)
Expected image: red over black, blue over green (each newcomer behind).
Trace: shape names alias the parent (typeof movieclip, sa == sb == _level0);
sprite newcomer is a real clip with its own name/target/_x and the
occupant's getDepth().

Golden: HELD — output.txt / output.expected.png are SWFRecomp's own output
(placeholder) until the coordinator's FLASH run replaces them
(w2-occupied-depth report, LOCAL ORACLE REQUESTS).
"""
import pathlib, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: F401,F403

defs = (define_shape_rect(1, 40, 40, (255, 0, 0)) + define_shape_rect(2, 40, 40, (0, 0, 0))
        + define_shape_rect(3, 40, 40, (0, 0, 255)) + define_shape_rect(4, 40, 40, (0, 255, 0))
        + define_sprite(10, [place_object2(1, 3, tx=0, ty=0)])
        + define_sprite(11, [place_object2(1, 4, tx=0, ty=0)]))

def typeof_(name):
    return get_var(name) + TYPEOF

def depth(name):
    return call_method(get_var(name), 'getDepth', discard=False)

act = (trace_expr('typeof(sa)=', typeof_('sa'), ' typeof(sb)=', typeof_('sb'))
       + trace_expr('sa==sb: ', get_var('sa') + get_var('sb') + EQUALS2,
                    ' sb==_level0: ', get_var('sb') + get_var('_level0') + EQUALS2)
       + trace_expr('typeof(ma)=', typeof_('ma'), ' typeof(mb)=', typeof_('mb'))
       + trace_expr('ma._name=', get_path('ma', '_name'), ' mb._name=', get_path('mb', '_name'))
       + trace_expr('ma.getDepth()=', depth('ma'), ' mb.getDepth()=', depth('mb'))
       + trace_expr('mb=', get_var('mb') + TARGET_PATH, ' mb._x=', get_path('mb', '_x'),
                    ' ma._x=', get_path('ma', '_x'))
       + STOP)

frame1 = (place_object2(5, 1, name='sa', tx=200, ty=200)
          + place_object2(5, 2, name='sb', tx=600, ty=600)
          + place_object2(7, 10, name='ma', tx=2000, ty=200)
          + place_object2(7, 11, name='mb', tx=2400, ty=600)
          + do_action(act))

swf_file(HERE / 'test.swf', [frame1], version=5, w=200, h=100, prefix=defs)
