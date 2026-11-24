#!/usr/bin/env python3
r"""s27 w1-per-movie-dl-phase3: delivery-tick-insensitive rewrite of the held
s26 fixture avm1_loaded_shell_consumers. The only Ruffle-runner disagreement
there was ONE extra leading `cx` (our load lands a tick earlier). Here the
child clip's enterFrame bumps _root.n instead of tracing, and the parent
traces the per-tick DELTA from frame 3 on: one enterFrame per tick for a live
shell child is all that row grades, whenever the load landed.
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa
SUBTRACT = bytes([0x0B])

def parent():
    defs = define_sprite(2, [b''])
    f1 = place_object2(2, char_id=2, name='px', tx=0, ty=0)
    f1 += do_action(set_var('n', push(0)) + set_var('m', push(0))
                    + call_method(get_var('_root'), 'createEmptyMovieClip', 'h', 1)
                    + call_method(get_var('h'), 'loadMovie', 'child.swf'))
    frames = [f1, do_action(set_var('m', get_var('n')))]
    for n in range(3, 7):
        code = trace_expr('t', get_path('_root', '_currentframe'), ' d:', get_var('n') + get_var('m') + SUBTRACT)
        code += set_var('m', get_var('n'))
        code += for_in_concat(get_var('h'), 's') + trace_expr('in:', get_var('s'))
        code += trace_expr('ev:', get_var('h.a') + TYPEOF,
                           ' sl:', get_var('/h/b') + TYPEOF,
                           ' sp:', get_var('/px') + TYPEOF,
                           ' tp:', get_path('h', 'a') + TARGET_PATH)
        if n == 6:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8, prefix=defs)

def child():
    defs = define_sprite(1, [b''])
    bump = set_member(get_var('_root'), 'n', concat(get_path('_root', 'n')) + push(1) + ADD2)
    f1 = place_object2(1, char_id=1, name='a', tx=0, ty=0, clip_actions=[(EV_ENTER_FRAME, bump)])
    f1 += place_object2(2, char_id=1, name='b', tx=0, ty=0)
    swf_file(HERE / 'child.swf', [f1], version=8, prefix=defs)

if __name__ == '__main__':
    child(); parent()
