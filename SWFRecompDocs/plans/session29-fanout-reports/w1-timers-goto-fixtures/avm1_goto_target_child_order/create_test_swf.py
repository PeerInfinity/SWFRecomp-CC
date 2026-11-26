#!/usr/bin/env python3
"""avm1_goto_target_child_order (s29 w1-timers-goto, item 3): the order of a
goto TARGET frame's actions when that frame is
    DoAction A / PlaceObject2 c1, c2 (a sprite whose frame 1 traces) / DoAction B.

A natural advance into such a frame runs A, c1, c2, B (tag order; ours and
Ruffle agree). gnash misc-swfc.all/gotoFrameFromInterval{,2} (FLASH golden)
show Flash keeps TAG order when the frame is reached by a root gotoAndPlay
from a setInterval callback; Ruffle (known_failure) and SWFRecomp before s29
ran A, B, c1, c2 (parent's DoActions first, then the children placed on the
target frame: Ruffle movie_clip.rs run_goto "Finally, run frames for children
that are placed on this frame").

Variants (argv[1]):
  normal      F1 -> natural advance into the target frame (control)
  gotoscript  F1's DoAction: GotoFrame(2) (frame 3, skipping frame 2)
  interval    F1: setInterval(50 ms) whose callback does gotoAndPlay(3)
Every variant prints `A cf=`, `child c1`, `child c2`, `B c1=<typeof _root.c1>`
in the order the player runs them.

Usage: create_test_swf.py <variant> <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
mode, out = sys.argv[1], sys.argv[2]
spr = sprite(1, [doaction(T('child ', get('this._name')))])
target = [doaction(T('A cf=', get('_root._currentframe'))) + place(1, 1, 'c1') + place(2, 1, 'c2')
          + doaction(T('B c1=', typeof_('_root.c1')) + STOP)]
if mode == 'normal':
    frames = [doaction(T('F1'))] + target
elif mode == 'gotoscript':
    frames = [doaction(T('F1') + op(0x81, struct.pack('<H', 2)) + T('after goto')),
              doaction(T('F2 never'))] + target
elif mode == 'interval':
    fn = deffunc1('', [], T('tick cf=', get('_root._currentframe'))
                  + get('_root.iv') + push(1, 'clearInterval') + CALLF + POP
                  + push(3, 1, 'gotoAndPlay') + CALLF + POP + T('after goto'))
    frames = [doaction(T('F1') + push('_root') + GETVAR + push('iv') + push(50) + fn
                       + push(2, 'setInterval') + CALLF + SETMEM + STOP),
              doaction(T('F2 never'))] + target
else:
    raise SystemExit('variant?')
open(out, 'wb').write(swf(7, spr, frames, fps=10))
