#!/usr/bin/env python3
"""avm1_attached_clip_selfgoto_trace: an attachMovie'd clip's OWN frame
scripts navigate it: frame 2 does gotoAndPlay(4), frame 5 does
gotoAndStop(6). The root traces the clip's _currentframe every frame.

This pins WHEN the self-goto's target frame shows and when its DoAction runs.
CI applies an attached root's self-goto in ng_apply_pending_sprite_self_gotos
(right after the post-frame-func SCRIPT drain). The browser used a separate
deferred pass in tagShowFrame (advance_attached_clip_frames) until s28
browser-attached-goto routed it through the same apply pass.

Golden: Flash Player 32 projector (tools/flash-oracle/run_trace.py, direct).

Regenerate:  python3 create_test_swf.py
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (tag, define_sprite, do_action, swf_file, call_method,  # noqa: E402
                     get_var, get_path, set_member, push, trace_expr, trace_str,
                     STOP, PLAY, goto_frame)
import struct  # noqa: E402

HOLDER = 1
defs = define_sprite(HOLDER, [
    do_action(trace_str('a f1')),
    do_action(trace_str('a f2') + goto_frame(3) + PLAY),
    do_action(trace_str('a f3 (skipped)')),
    do_action(trace_expr('a f4 cf=', get_path('this', '_currentframe'))),
    do_action(trace_str('a f5') + goto_frame(5)),
    do_action(trace_expr('a f6 cf=', get_path('this', '_currentframe'))),
])
defs += tag(56, struct.pack('<HH', 1, HOLDER) + b'holder\x00')

frames = []
f1 = call_method(get_var('_root'), 'attachMovie', 'holder', 'h', 1)
f1 += trace_expr('root f1 h.cf=', get_path('h', '_currentframe'))
frames.append(do_action(f1))
for n in range(2, 10):
    body = trace_expr('root f%d h.cf=' % n, get_path('h', '_currentframe'))
    if n == 9:
        body += STOP
    frames.append(do_action(body))
swf_file(HERE / 'test.swf', frames, version=8, w=200, h=150, prefix=defs)
