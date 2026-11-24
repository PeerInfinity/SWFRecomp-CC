#!/usr/bin/env python3
r"""s27 w1-per-movie-dl-phase3: delivery-tick-insensitive rewrite of the held
s26 fixture avm1_loaded_unload_shell. Only the parent traces, from frame 3 on,
so no row depends on the load-delivery tick or the intra-tick order.

Ruffle (current source, 1e604fa87 and the Feb-2026 build alike): a movie that a
loader put into a clip is a ROOT clip (`replace_with_movie(.., is_root=true,
..)` in loader.rs `movie_loader_data`), so `avm1_unload_movie` takes its
`is_root()` arm and defers `avm1_unload` + `transform_to_unloaded_state` to a
spawned future, i.e. to the next update. Ruffle's own comment there records
that Flash applies the unloaded state ONE FRAME after unloadMovie even for a
non-root clip (`movieclip_library_state_values`). So `b:` (read right after
h.unloadMovie() in the same script) is still movieclip; t4 is undefined.
"""
import sys
from pathlib import Path
HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

def typeof_of(*path):
    return get_path(*path) + TYPEOF

def parent():
    f1 = b''
    for name, depth in (('h', 1), ('g', 2)):
        f1 += call_method(get_var('_root'), 'createEmptyMovieClip', name, depth)
        f1 += call_method(get_var(name), 'loadMovie', 'child.swf')
    frames = [do_action(f1), do_action(b'')]
    f3 = trace_expr('a:', typeof_of('h', 'a'))
    f3 += call_method(get_var('h'), 'unloadMovie')
    f3 += trace_expr('b:', typeof_of('h', 'a'), ' g:', typeof_of('g', 'a'))
    frames.append(do_action(f3))
    for n in (4, 5, 6):
        code = trace_expr('t', get_path('_root', '_currentframe'),
                          ' h:', typeof_of('h', 'a'), ' g:', typeof_of('g', 'a'))
        if n == 6:
            code += STOP
        frames.append(do_action(code))
    swf_file(HERE / 'test.swf', frames, version=8)

def child():
    defs = define_shape_rect(1, 40, 40, (255, 0, 0)) + define_sprite(2, [place_object2(1, char_id=1, tx=0, ty=0)])
    swf_file(HERE / 'child.swf', [place_object2(1, char_id=2, name='a', tx=200, ty=200), b''],
             version=8, prefix=defs)

if __name__ == '__main__':
    child(); parent()
