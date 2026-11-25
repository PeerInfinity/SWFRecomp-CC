#!/usr/bin/env python3
"""avm1_sprite_goto_script_overflow: 20 timeline sprites, each sent to its
frame 2 from ONE root script (tellTarget + gotoAndStop, and a second wave via
MovieClip.gotoAndStop). Every sprite's frame-2 DoAction must run once (Flash
queues the target frame's actions per goto). s28 w1-leads item 2: the
deferred sprite-script queue (sprite_frame_scripts.c, MAX_PENDING_SPRITE_SCRIPTS
= 16) dropped entries past 16 between flushes.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys
import struct

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

N = 20
T = trace_concat
GOTO = lambda f: op(0x81, struct.pack('<H', f))  # GotoFrame (0-based)
sp_f1 = doaction(STOP)
sp_f2 = doaction(T('f2 ', get('this._name')) + STOP)
sp_f3 = doaction(T('f3 ', get('this._name')) + STOP)
defs = sprite(1, [sp_f1, sp_f2, sp_f3])
# Sprite 2: its OWN frame-1 script issues 20 self-gotos (alternating frames 2
# and 3): these are the gotos that go through the pending sprite-script queue.
loop_f1 = b''
for i in range(N):
    loop_f1 += GOTO(1 + (i % 2)) + push('k') + GETVAR + push(1) + ADD2 + push('k') + op(0x4d) + SETVAR
loop_f1 = doaction(push('k', 0) + SETVAR + loop_f1 + T('L self-goto wave issued k=', get('k')))
lp2 = doaction(T('L2 ', get('this._name')) + STOP)
lp3 = doaction(T('L3 ', get('this._name')) + STOP)
defs += sprite(2, [loop_f1, lp2, lp3])
places = b''.join(place(i + 1, 1, 's%d' % i) for i in range(N)) + place(100, 2, 'L')
r1 = b''
for i in range(N):
    r1 += settarget('s%d' % i) + GOTO(1) + settarget('')
r1 += T('root tellTarget wave issued')
for i in range(N):
    r1 += callm('s%d' % i, 'gotoAndStop', 3)
r1 += T('root method wave issued')
f1 = places + doaction(r1)
f2 = doaction(T('root frame 2'))
f3 = doaction(T('root frame 3') + STOP)
open(sys.argv[1], 'wb').write(swf(8, defs, [f1, f2, f3]))
