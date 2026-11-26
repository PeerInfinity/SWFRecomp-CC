#!/usr/bin/env python3
"""avm1_timer_clock_model, BOUND-CHECK form (s29 w1-timers-goto, item 1).

Replaces the s26/s27 analytic golden (raw per-callback traces and exact
catch-up counts cnt=16/18/18). Three direct FP32 captures (s28,
session28-fanout-reports/w1-local-oracles/new-timer-rows/
regression__avm1_timer_clock_model/) differ from each other: the near-tie
callbacks of F2 reorder against the F3 boundary run to run, and F5-F7 count
10 or 12 (Flash polls its timers every ~16-20 ms while idle; it neither
catches up to every 1 ms due time nor fires once per frame). So this form
prints only facts that held in ALL THREE captures, and turns the counts into
range checks. Same scenario and timings as before, at 10 fps:

  F1  setInterval(fz, 0)          a 0 delay REPEATS (10 ms floor): z1..z3 all
                                  fire in frame 1, then fz clears itself (raw
                                  traces kept: identical in all 3 captures)
  F2  setInterval(fa, 30), setTimeout(fb, 20), setTimeout(fe, 100);
                                  fb creates setTimeout(fn, 0)
  F3  `F3 b=1 n=1 a2=true`        b, n and >= 2 fires of a have run before
                                  F3's DoAction. n is a 0-delay timeout made
                                  INSIDE b's callback at ~20 ms: Flash runs it
                                  in the same frame (FP32 3/3 `n f2`); it is
                                  due 10 ms after b's own time, not after the
                                  frame's end.
  F4  `F4 a=4 e=1`                fa's 4th fire (~120 ms) and fe (100 ms) have
                                  both run (exact position vs the F3 boundary
                                  is wall-clock jitter, not checked)
  F4  setInterval(fc, 10), setInterval(fc, 13)
  F5-F7 `F<n> lo=true hi=true`    5 < cnt < 21 fires per 100 ms frame: FP32
                                  10/12; ideal 1 ms catch-up 16/18; a
                                  once-per-update model (cnt=2) or a runaway
                                  fails
  F7  clears both; F8 `cnt=0`.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
FRAME = get('_root._currentframe')
LESS2 = op(0x48)


def setroot(name, code):
    return push('_root') + GETVAR + push(name) + code + SETMEM


def incr(name):
    return setroot(name, get('_root.' + name) + push(1) + ADD2)


def clear(name):
    return get('_root.' + name) + push(1, 'clearInterval') + CALLF + POP


def if_eq(name, val, body):
    cond = get('_root.' + name) + push(val) + EQ2 + op(0x12)  # Not
    return cond + op(0x9d, struct.pack('<h', len(body))) + body


def start(var, kind, fn, delay):
    call = push(delay) + fn + push(2, kind) + CALLF
    return setroot(var, call) if var else call + POP


fz = deffunc1('', [], incr('zn') + T('z', get('_root.zn'), ' f', FRAME) + if_eq('zn', 3, clear('z')))
fa = deffunc1('', [], incr('an') + if_eq('an', 4, clear('a')))
fn = deffunc1('', [], setroot('nd', push(1)))
fb = deffunc1('', [], setroot('bd', push(1)) + start(None, 'setTimeout', fn, 0))
fe = deffunc1('', [], setroot('ed', push(1)))
fc = deffunc1('', [], incr('cnt'))


def cnt_frame(n, extra=b''):
    lo = push(5) + get('_root.cnt') + LESS2          # 5 < cnt
    hi = get('_root.cnt') + push(21) + LESS2         # cnt < 21
    return T('F%d lo=' % n, lo, ' hi=', hi) + setroot('cnt', push(0)) + extra


frames = [
    T('F1') + setroot('zn', push(0)) + start('z', 'setInterval', fz, 0),
    T('F2') + setroot('an', push(0)) + start('a', 'setInterval', fa, 30)
    + start(None, 'setTimeout', fb, 20) + start(None, 'setTimeout', fe, 100),
    T('F3 b=', get('_root.bd'), ' n=', get('_root.nd'), ' a2=', push(1) + get('_root.an') + LESS2),
    T('F4 a=', get('_root.an'), ' e=', get('_root.ed'))
    + setroot('cnt', push(0)) + start('c1', 'setInterval', fc, 10) + start('c2', 'setInterval', fc, 13),
    cnt_frame(5),
    cnt_frame(6),
    cnt_frame(7, clear('c1') + clear('c2')),
    T('F8 cnt=', get('_root.cnt')),
    T('F9 end') + STOP,
]
open(sys.argv[1], 'wb').write(swf(7, b'', [doaction(f) for f in frames], fps=10))
