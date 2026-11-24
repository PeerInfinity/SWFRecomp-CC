#!/usr/bin/env python3
"""avm1_timer_clock_model: the AVM1 setInterval/setTimeout clock (processTimers
/ actionTimerSetInterval in SWFModernRuntime/src/actionmodern/timer.c), at
10 fps (100 ms frames, so every delay boundary is exact):

  F1  setInterval(fz, 0)            a 0 delay REPEATS (10 ms floor): 3 fires in
                                    the first update, then fz clears itself
  F2  setInterval(fa, 30), setTimeout(fb, 20), setTimeout(fe, 100)
                                    earliest due time first (b@20 before
                                    a@30,60,90 — not slot/creation order);
                                    e@100 is NOT due in the update whose clock
                                    reaches exactly 100 ms (strict <) -> F3;
                                    fb's setTimeout(fn, 0) is created against
                                    the current clock, so it fires next update
  F4  setInterval(fc, 10), setInterval(fc, 13)
                                    every due fire runs, catching up (no
                                    per-update cap: s27 w2b-timers-tail; Flash
                                    fired 70 due one-shots in one update,
                                    regression/avm1_timer_overflow): F5 sees
                                    9+7 = 16 (10..90 / 13..91), F6 and F7 see
                                    10+8 = 18. Ruffle's MAX_TICKS = 10 ("for
                                    sanity") gave cnt=10 each frame.
  F7  clears both; F8 sees cnt=0.

s26 w2-timer-semantics; F5-F7 re-derived s27 w2b-timers-tail without the
MAX_TICKS cap. GOLDEN IS ANALYTIC (Ruffle-source-derived; the Ruffle
exporter never fires timers; a Flash capture of this SWF is requested in
session27-fanout-reports/w2b-timers-tail-report.md -- Flash's real-time clock
may jitter F5-F7 by a fire): core/src/timer.rs Timers::update_timers /
add_timer (MIN_INTERVAL 10, MAX_TICKS 10 [dropped], TIMER_SCALE 1000, `tick_time <
cur_time`), avm1/globals.rs create_timer (coerce_to_i32), tests/framework
runner.rs (run_frame then update_timers(frame_time) per tick). Computed by a
line-for-line simulation of that model INCLUDING std BinaryHeap tie order
(the fixture has no observable ties). A Ruffle test-runner confirmation is
requested under LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session26-fanout-reports/w2-timer-semantics-report.md.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa

T = trace_concat
FRAME = get('_root._currentframe')


def setroot(name, code):
    """_root.name = <code>"""
    return push('_root') + GETVAR + push(name) + code + SETMEM


def incr(name):
    return setroot(name, get('_root.' + name) + push(1) + ADD2)


def clear(name):
    return get('_root.' + name) + push(1, 'clearInterval') + CALLF + POP


def if_eq(name, val, body):
    # if (_root.name == val) body   (If jumps over body when NOT equal)
    cond = get('_root.' + name) + push(val) + EQ2 + op(0x12)  # Not
    return cond + op(0x9d, struct.pack('<h', len(body))) + body


def start(var, kind, fn, delay):
    """_root.var = kind(fn, delay)   (var None: discard the id)"""
    call = push(delay) + fn + push(2, kind) + CALLF
    return setroot(var, call) if var else call + POP


fz = deffunc1('', [], incr('zn') + T('z', get('_root.zn'), ' f', FRAME) + if_eq('zn', 3, clear('z')))
fa = deffunc1('', [], incr('an') + T('a', get('_root.an'), ' f', FRAME) + if_eq('an', 4, clear('a')))
fn = deffunc1('', [], T('n f', FRAME))
fb = deffunc1('', [], T('b f', FRAME) + start(None, 'setTimeout', fn, 0))
fe = deffunc1('', [], T('e f', FRAME))
fc = deffunc1('', [], incr('cnt'))


def cnt_frame(n, extra=b''):
    return T('F%d cnt=' % n, get('_root.cnt')) + setroot('cnt', push(0)) + extra


frames = [
    T('F1') + setroot('zn', push(0)) + start('z', 'setInterval', fz, 0),
    T('F2') + setroot('an', push(0)) + start('a', 'setInterval', fa, 30)
    + start(None, 'setTimeout', fb, 20) + start(None, 'setTimeout', fe, 100),
    T('F3'),
    T('F4') + setroot('cnt', push(0)) + start('c1', 'setInterval', fc, 10) + start('c2', 'setInterval', fc, 13),
    cnt_frame(5),
    cnt_frame(6),
    cnt_frame(7, clear('c1') + clear('c2')),
    cnt_frame(8),
    T('F9 end') + STOP,
]
open(sys.argv[1], 'wb').write(swf(7, b'', [doaction(f) for f in frames], fps=10))
