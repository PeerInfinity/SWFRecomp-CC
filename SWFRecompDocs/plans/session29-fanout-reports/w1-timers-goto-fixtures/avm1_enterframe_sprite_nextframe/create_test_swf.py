#!/usr/bin/env python3
"""avm1_enterframe_sprite_nextframe (s29 w1-timers-goto, item 4, sprite
variant): a 4-frame sprite `s` (frame 1 stops; every frame traces
`s f<n> cf=<s._currentframe>`) whose own onEnterFrame calls
this.nextFrame() / this.prevFrame() (CallMethod) and, via a with(s) block,
the bare NextFrame / PrevFrame OPCODES. Root: 1 frame, stopped.

onEnterFrame (call k) traces `sef<k> cf=`, then:
  k=1  this.nextFrame()   (1 -> 2)  `after mnext cf=`
  k=2  NextFrame opcode in with(this) / tellTarget-equivalent  (2 -> 3)  `after next cf=`
  k=3  this.prevFrame()   (3 -> 2)  `after mprev cf=`
  k=4  PrevFrame opcode   (2 -> 1)  `after prev cf=`
  k=6  delete (onEnterFrame = 0)
The opcodes run under SetTarget("/s") (what `tellTarget("s") { nextFrame(); }`
compiles to), so they address the sprite, not the root.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
NOT = op(0x12)
SCF = get('_root.s._currentframe')


def setroot(name, code):
    return push('_root') + GETVAR + push(name) + code + SETMEM


def if_eq(path, val, body):
    cond = get(path) + push(val) + EQ2 + NOT
    return cond + op(0x9d, struct.pack('<h', len(body))) + body


K = get('_root.k')
ef = (setroot('k', K + push(1) + ADD2) + T('sef', K, ' cf=', SCF)
      + if_eq('_root.k', 1, callm('this', 'nextFrame') + T('after mnext cf=', SCF))
      + if_eq('_root.k', 2, settarget('/s') + op(0x04) + settarget('') + T('after next cf=', SCF))
      + if_eq('_root.k', 3, callm('this', 'prevFrame') + T('after mprev cf=', SCF))
      + if_eq('_root.k', 4, settarget('/s') + op(0x05) + settarget('') + T('after prev cf=', SCF))
      + if_eq('_root.k', 6, push('_root') + GETVAR + push('s') + GETMEM + push('onEnterFrame', 0) + SETMEM))
sframes = []
for n in range(1, 5):
    a = T('s f%d cf=' % n, get('this._currentframe'))
    if n == 1:
        a += STOP
    sframes.append(doaction(a))
spr = sprite(1, sframes)
root = (place(1, 1, 's') + doaction(setroot('k', push(0))
        + push('_root') + GETVAR + push('s') + GETMEM + push('onEnterFrame') + deffunc1('', [], ef) + SETMEM
        + T('root f1') + STOP))
open(sys.argv[1], 'wb').write(swf(8, spr, [root], fps=12))
