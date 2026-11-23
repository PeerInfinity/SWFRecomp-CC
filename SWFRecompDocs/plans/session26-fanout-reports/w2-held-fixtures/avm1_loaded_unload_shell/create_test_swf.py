#!/usr/bin/env python3
r"""Build test.swf + child.swf for regression/avm1_loaded_unload_shell
(s26 w2-loaded-shell-phase2, phase 5).

WHAT THIS PINS DOWN
-------------------
**unloadMovie() on a clip-target holder takes the loaded movie's children away
at once.** Since phase 1 (a6a696bf2) a clip target's movie places into the
holder's own list (the "shell", MovieClip.loaded_dl_shell). The unload paths
only unregistered the playhead, so the movie stopped advancing but its
children stayed in the shell: still resolvable as `h.a` and still rendered.
Ruffle avm1_unload_movie (non-root) -> transform_to_unloaded_state ->
replace_with_movie(empty movie) replaces the clip's ChildContainer
synchronously.

THE SHAPE
---------
    parent test.swf (SWF8, 6 frames)
      f1: createEmptyMovieClip h@1; h.loadMovie("child.swf")
          createEmptyMovieClip g@2; g.loadMovie("child.swf")    (control)
      f3: trace a:<typeof h.a> ; h.unloadMovie() ; trace b:<typeof h.a>
      f4..f6: trace t<N> h:<typeof h.a> g:<typeof g.a>
    child.swf (SWF8, 2 frames): f1 places sprite "a" (a red box) + "c1",
                                f2 "c2"

  * `b:` must already be undefined (synchronous for a non-root clip).
  * `h:` stays undefined on later ticks; `g:` (never unloaded) stays movieclip.
  * after the unload h's movie no longer traces (only g's c1/c2 continue).

GOLDEN: output.txt is PREDICTED; see LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-report.md.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F401,F403


def typeof_of(*path):
    return get_path(*path) + TYPEOF


def parent():
    f1 = b''
    for name, depth in (('h', 1), ('g', 2)):
        f1 += call_method(get_var('_root'), 'createEmptyMovieClip', name, depth)
        f1 += call_method(get_var(name), 'loadMovie', 'child.swf')
    frames = [do_action(f1), do_action(trace_expr('t', get_path('_root', '_currentframe')))]
    f3 = trace_expr('a:', typeof_of('h', 'a'))
    f3 += call_method(get_var('h'), 'unloadMovie')
    f3 += trace_expr('b:', typeof_of('h', 'a'))
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
    swf_file(HERE / 'child.swf', [
        place_object2(1, char_id=2, name='a', tx=200, ty=200) + do_action(trace_str('c1')),
        do_action(trace_str('c2')),
    ], version=8, prefix=defs)


if __name__ == '__main__':
    child()
    parent()
