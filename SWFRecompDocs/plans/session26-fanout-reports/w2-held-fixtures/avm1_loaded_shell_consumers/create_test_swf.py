#!/usr/bin/env python3
r"""Build test.swf + child.swf for regression/avm1_loaded_shell_consumers
(s26 w2-loaded-shell-phase2, phase 2).

WHAT THIS PINS DOWN
-------------------
**The per-tick walks and name resolvers see a loaded movie's children in the
holder's own list (the "shell", phase 1 a6a696bf2), and ONLY there.**
Phase 1 moved a clip target's placements out of the parent's global display
list into the holder's shell and taught the renderer, getMember, the sprite
advance and the realloc rebase about it. Every other consumer still looked
only at the root list, so a loaded child was invisible to it (or, via the old
root-name fallback, visible under the wrong parent).

THE SHAPE
---------
    parent test.swf (SWF8, 6 frames)
      f1: timeline sprite `px`@1 ; createEmptyMovieClip h@1 ; h.loadMovie(child.swf)
      f2..f6: one row per consumer (below)
    child.swf (SWF8, 1 frame)
      sprite `a`@1 with onClipEvent(enterFrame){ trace("cx") }
      sprite `b`@2

ROWS
  * `cx` once per tick: clip-event enterFrame dispatch over the shell
    (tag.c collect_attached_standalone).
  * `in:` for (k in h): the holder enumerates its timeline children
    (ng_enumerateChildren). Order is a PREDICTION (Flash enumerates newest
    first) -- the oracle decides.
  * `ev:` typeof eval("h.a"), `sl:` typeof eval("/h/b"): string/slash path
    resolution through the holder (resolveSlashPathToMC); `sp:` eval("/px")
    is the root-list control.
  * (NOT asserted: `typeof _root.a` reads "movieclip" on the first tick and
    undefined after -- a pre-existing actionGetMemberImpl root-arm leak,
    reported as a lead in the w2 report; Flash gives undefined throughout.)
  * `tp:` targetPath(h.a) = _level0.h.a.

GOLDEN: output.txt is PREDICTED; see LOCAL ORACLE REQUESTS in
SWFRecompDocs/plans/session26-fanout-reports/w2-loaded-shell-phase2-report.md.
"""
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa: E402,F401,F403


def parent():
    defs = define_sprite(2, [b''])
    f1 = place_object2(1, char_id=2, name='px', tx=0, ty=0)
    f1 += do_action(call_method(get_var('_root'), 'createEmptyMovieClip', 'h', 1)
                    + call_method(get_var('h'), 'loadMovie', 'child.swf'))
    frames = [f1]
    for n in range(2, 7):
        code = trace_expr('t', get_path('_root', '_currentframe'))
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
    f1 = place_object2(1, char_id=1, name='a', tx=0, ty=0,
                       clip_actions=[(EV_ENTER_FRAME, trace_str('cx'))])
    f1 += place_object2(2, char_id=1, name='b', tx=0, ty=0)
    swf_file(HERE / 'child.swf', [f1], version=8, prefix=defs)


if __name__ == '__main__':
    child()
    parent()
