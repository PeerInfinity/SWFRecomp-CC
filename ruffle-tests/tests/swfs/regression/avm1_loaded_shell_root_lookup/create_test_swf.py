#!/usr/bin/env python3
r"""s27 w1-per-movie-dl-phase3 probe: while a loaded movie's frame runs (its
list swapped in as the active display list), does a ROOT-timeline child
resolve through _root? Shell holder (createEmptyMovieClip) and timeline
holder. Rows are traced from the CHILD's frame 1 and 2, so they run inside the
swap. `px` is a root timeline sprite; the child also places its own `q`.
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

def parent():
    defs = define_sprite(2, [b''])
    f1 = place_object2(1, char_id=2, name='px', tx=0, ty=0)
    f1 += place_object2(2, char_id=2, name='th', tx=0, ty=0)
    f1 += do_action(call_method(get_var('_root'), 'createEmptyMovieClip', 'h', 1)
                    + call_method(get_var('h'), 'loadMovie', 'child.swf')
                    + call_method(get_var('th'), 'loadMovie', 'child.swf'))
    frames = [f1] + [do_action(b'')] * 3 + [do_action(STOP)]
    swf_file(HERE / 'test.swf', frames, version=8, prefix=defs)

def child():
    defs = define_sprite(1, [b''])
    row = trace_expr('r:', get_path('_root', 'px') + TYPEOF, ' s:', get_var('/px') + TYPEOF,
                     ' q:', get_var('q') + TYPEOF, ' tq:', get_path('this', 'q') + TYPEOF)
    f1 = place_object2(1, char_id=1, name='q', tx=0, ty=0) + do_action(row)
    swf_file(HERE / 'child.swf', [f1, do_action(row + STOP)], version=8, prefix=defs)

if __name__ == '__main__':
    child(); parent()
