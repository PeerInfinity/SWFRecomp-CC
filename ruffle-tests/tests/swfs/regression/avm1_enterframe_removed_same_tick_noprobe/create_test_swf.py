#!/usr/bin/env python3
r"""Build test.swf for avm1_enterframe_removed_same_tick_noprobe (s28 w2-test12-land).

VARIANT of regression/avm1_enterframe_removed_same_tick: identical except root
frame 4 traces just "frame 4" (no typeof(a.k) probe).  The probe line is a
separate lead (a loop-back-removed onUnload child stays name-reachable in
Flash); this variant pins the enterFrame rule alone.  FLASH golden pending.

Original docstring:

WHAT THIS PINS DOWN
-------------------
Does a clip that is alive at the START of a tick get its onEnterFrame on the
tick whose timeline advance removes it?  Real Flash 32 does in gnash
misc-swfc.all/action_execution_order_test12 (prints output.fp10.txt: clips
mc2.mc21 / mc1.mc12, removed by their parent's loop-back, each fire once; mc1 /
mc2, removed by a root RemoveObject2, fire on that tick too).  Flash 9, Ruffle
(player.rs run_actions drops a queued action whose clip was removed) and our
runtime before the prototype do not.  Ruffle's avm1/clip_events golden says the
opposite for its RemoveObject2 case, so this fixture splits the shapes:

    a  : 2-frame sprite; its frame 2 places child "k" (1 frame).  The loop-back
         to a's frame 1 removes k.  k.onEnterFrame defined right after k exists.
    b  : 2-frame PLAYING sprite, removed by root RemoveObject2 (test12 mc1/mc2 shape)
    s  : 1-frame sprite, removed by root RemoveObject2 (clip_events shape)
    c  : 1-frame sprite with onClipEvent(enterFrame), removed by root RemoveObject2
    n  : 2-frame playing sprite, removed by root RemoveObject2, NO onUnload
    t  : 1-frame sprite, removed by root RemoveObject2, NO onUnload
    b, s carry onUnload so the EF-vs-unload order is visible.
  The same file is built at SWF 8 (this dir) and SWF 7 (../avm1_enterframe_removed_same_tick_swf7):
  test12 is SWF 7, clip_events SWF 15, movieclip_in_removed_button SWF 8.

Each handler traces `_root._currentframe` and the parent's `_currentframe`:
the values say whether the handler ran BEFORE the tick's advance
(k: a.cf=2) or after it as a not-dropped queued action (k: a.cf=1).
Root frames trace "frame N" to delimit ticks.
"""
import struct, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parents[4]
sys.path.insert(0, str(REPO / 'ruffle-tests/tests/swfs/regression/_lib'))
import avm1asm
from avm1asm import *  # noqa
_rec = avm1asm._rec

SHAPE = 1
SPR_K, SPR_A, SPR_B, SPR_S = 10, 11, 12, 13
VERSION = int(sys.argv[1]) if len(sys.argv) > 1 else 8
OUT = HERE
OUT.mkdir(exist_ok=True)


def define_function(body):
    return _rec(0x9B, b'\x00' + struct.pack('<H', 0) + struct.pack('<H', len(body))) + body


def assign_handler(obj_code, name, body):
    return obj_code + push(name) + define_function(body) + SET_MEMBER


def ef_body(label, path=None, key=' pcf='):
    pieces = [label + ' rf=', get_path('_root', '_currentframe')]
    if path:
        pieces += [key, get_path(*path, '_currentframe')]
    return trace_expr(*pieces)


prefix = define_shape_rect(SHAPE, 10, 10)
prefix += define_sprite(SPR_K, [place_object2(1, SHAPE)])
prefix += define_sprite(SPR_A, [b'', place_object2(1, SPR_K, name='k')])
prefix += define_sprite(SPR_B, [place_object2(1, SHAPE), b''])
prefix += define_sprite(SPR_S, [place_object2(1, SHAPE)])

c_actions = [(EV_ENTER_FRAME, trace_expr('c clipEvent(enterFrame) rf=', get_path('_root', '_currentframe')))]

frames = []
# root frame 1
frames.append(do_action(trace_str('frame 1')))
# root frame 2: place everything, define handlers
f2 = place_object2(1, SPR_A, name='a')
f2 += place_object2(2, SPR_B, name='b')
f2 += place_object2(3, SPR_S, name='s')
f2 += place_object2(4, SPR_S, name='c', clip_actions=c_actions)
f2 += place_object2(5, SPR_B, name='n')
f2 += place_object2(6, SPR_S, name='t')
f2 += do_action(
    trace_str('frame 2')
    + assign_handler(get_var('a'), 'onEnterFrame', ef_body('a EF', None))
    + assign_handler(get_var('b'), 'onEnterFrame', ef_body('b EF', ['b'], ' cf='))
    + assign_handler(get_var('s'), 'onEnterFrame', ef_body('s EF', None))
    + assign_handler(get_var('n'), 'onEnterFrame', ef_body('n EF', ['n'], ' cf='))
    + assign_handler(get_var('t'), 'onEnterFrame', ef_body('t EF', None))
    + assign_handler(get_var('b'), 'onUnload', trace_str('b unload'))
    + assign_handler(get_var('s'), 'onUnload', trace_str('s unload'))
)
frames.append(f2)
# root frame 3: a is on its frame 2 now, k exists
frames.append(do_action(
    trace_expr('frame 3 typeof(a.k)=', get_path('a', 'k') + TYPEOF)
    + assign_handler(get_path('a', 'k'), 'onEnterFrame', ef_body('k EF', ['_root', 'a'], ' a.cf='))
    + assign_handler(get_path('a', 'k'), 'onUnload', trace_expr('k unload a.cf=', get_path('_root', 'a', '_currentframe')))
))
# root frame 4: a looped back, k removed this tick
frames.append(do_action(trace_str('frame 4')))
# root frame 5: remove b, s, c
frames.append(remove_object2(2) + remove_object2(3) + remove_object2(4) + remove_object2(5) + remove_object2(6)
              + do_action(trace_expr('frame 5 typeof(b)=', get_var('b') + TYPEOF)))
# root frame 6: tidy up
frames.append(remove_object2(1) + do_action(trace_str('frame 6') + STOP))

swf_file(OUT / 'test.swf', frames, version=VERSION, prefix=prefix)
