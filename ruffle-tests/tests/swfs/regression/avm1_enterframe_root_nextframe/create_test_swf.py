#!/usr/bin/env python3
"""avm1_enterframe_root_nextframe (s29 w1-timers-goto, item 4): root
nextFrame()/prevFrame() issued from _root.onEnterFrame, both as the bare
OPCODES (NextFrame 0x04 / PrevFrame 0x05) and as METHOD calls
(_root.nextFrame() / _root.prevFrame(), CallMethod), on a stopped and on a
playing root. Companion of regression/avm1_enterframe_root_goto_opcode (s28:
Flash moves the playhead INLINE for GotoFrame inside onEnterFrame and runs the
target frame's DoAction right after the handler returns).

SWF 8, 12 fps, 8 root frames; every frame's DoAction traces `f<n> cf=<cf>`;
frame 1 stops (its setup runs on the first visit only). onEnterFrame (call k) traces `ef<k> cf=`, then:
  k=1  NextFrame opcode       (stopped root, 1 -> 2)   then `after next cf=`
  k=2  _root.nextFrame()      (stopped root, 2 -> 3)   then `after mnext cf=`
  k=3  PrevFrame opcode       (stopped root, 3 -> 2)   then `after prev cf=`
  k=4  _root.prevFrame()      (stopped root, 2 -> 1)   then `after mprev cf=`
  k=5  play()
  k=7  NextFrame opcode on a PLAYING root              then `after pnext cf=`
  k=9  stop(); onEnterFrame = 0 (end)
Flash prediction (from the GotoFrame capture): each `after` line shows the
target frame, the target frame's `f<n>` line follows the handler in the same
tick, and nextFrame/prevFrame stop the root.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
NOT = op(0x12)
CF = get('_root._currentframe')


def setroot(name, code):
    return push('_root') + GETVAR + push(name) + code + SETMEM


def if_eq(path, val, body):
    cond = get(path) + push(val) + EQ2 + NOT
    return cond + op(0x9d, struct.pack('<h', len(body))) + body


K = get('_root.k')
ef = (setroot('k', K + push(1) + ADD2) + T('ef', K, ' cf=', CF)
      + if_eq('_root.k', 1, op(0x04) + T('after next cf=', CF))
      + if_eq('_root.k', 2, callm('_root', 'nextFrame') + T('after mnext cf=', CF))
      + if_eq('_root.k', 3, op(0x05) + T('after prev cf=', CF))
      + if_eq('_root.k', 4, callm('_root', 'prevFrame') + T('after mprev cf=', CF))
      + if_eq('_root.k', 5, op(0x06))
      + if_eq('_root.k', 7, op(0x04) + T('after pnext cf=', CF))
      + if_eq('_root.k', 9, STOP + setroot('onEnterFrame', push(0))))
frames = []
for n in range(1, 9):
    a = T('f%d cf=' % n, CF)
    if n == 1:
        # first visit only (k=4 prevFrame()s back here): if (!_root.inited) {...}
        body = setroot('inited', push(1)) + setroot('k', push(0)) + setroot('onEnterFrame', deffunc1('', [], ef))
        a += get('_root.inited') + op(0x9d, struct.pack('<h', len(body))) + body + STOP
    frames.append(doaction(a))
open(sys.argv[1], 'wb').write(swf(8, b'', frames, fps=12))
