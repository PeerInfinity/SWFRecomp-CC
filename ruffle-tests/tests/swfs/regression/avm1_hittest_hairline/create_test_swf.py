#!/usr/bin/env python3
"""avm1_hittest_hairline: MovieClip.hitTest(x, y, true) against committed
Drawing-API strokes. A hairline (lineStyle(0)) is hit within half a SCREEN
pixel of its centreline at any clip scale; a thick line within half its width.

s26 w1-avm1-dispatch-scope item 3. Ruffle core/src/drawing.rs Drawing::hit_test
-> render/src/shape_utils.rs draw_command_stroke_hit_test: half-width =
0.5 * max(width, stroke_minimum_width(local_matrix)), min width = 20 twips *
max-axis scale of the global->local matrix (= 1 screen px).

Frame 1 draws, frame 2 tests (so graphics mode has rendered the strokes once),
frame 3 repeats the tests with the clip scaled x4.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def ht(clip, x, y):
    return T('%s.hitTest(%s, %s)=' % (clip, x, y), callm(clip, 'hitTest', x, y, True, keep=True))


f1 = (
    callm('_root', 'createEmptyMovieClip', 'h', 1)
    + callm('h', 'lineStyle', 0, 0, 100)
    + callm('h', 'moveTo', 100, 100) + callm('h', 'lineTo', 200, 100)
    + callm('h', 'moveTo', 100, 150) + callm('h', 'lineTo', 200, 200)
    + callm('_root', 'createEmptyMovieClip', 'k', 2)
    + callm('k', 'lineStyle', 10, 0, 100)
    + callm('k', 'moveTo', 100, 250) + callm('k', 'lineTo', 200, 250)
    # committed (endFill) diagonal hairline
    + callm('_root', 'createEmptyMovieClip', 'hc', 3)
    + callm('hc', 'lineStyle', 0, 0, 100)
    + callm('hc', 'moveTo', 300, 150) + callm('hc', 'lineTo', 400, 200)
    + callm('hc', 'endFill')
    # committed filled square with a hairline border
    + callm('_root', 'createEmptyMovieClip', 'sq', 4)
    + callm('sq', 'lineStyle', 0, 0, 100)
    + callm('sq', 'beginFill', 0xff0000, 100)
    + callm('sq', 'moveTo', 300, 300) + callm('sq', 'lineTo', 400, 300)
    + callm('sq', 'lineTo', 400, 400) + callm('sq', 'lineTo', 300, 400)
    + callm('sq', 'lineTo', 300, 300) + callm('sq', 'endFill')
)
tests = (
    ht('h', 150, 100) + ht('h', 150, 100.4) + ht('h', 150, 100.7) + ht('h', 150, 99.6)
    + ht('h', 150, 101) + ht('h', 150, 175) + ht('h', 150, 175.6) + ht('h', 210, 100)
    + ht('k', 150, 254.5) + ht('k', 150, 255.5) + ht('k', 204, 250) + ht('k', 206, 250)
    + ht('hc', 350, 175) + ht('hc', 350, 175.4) + ht('hc', 350, 175.7) + ht('hc', 350, 174.6)
    + ht('sq', 350, 350) + ht('sq', 350, 400) + ht('sq', 400, 350) + ht('sq', 400, 400)
    + ht('sq', 350, 300) + ht('sq', 300, 350)
)
f2 = T('-- identity') + tests
scaled = (
    push('h') + GETVAR + push('_xscale', 400) + SETMEM
    + push('h') + GETVAR + push('_yscale', 400) + SETMEM
)
# h scaled x4 about (0,0): the 100..200 x 100 line maps to 400..800 x 400.
f3 = scaled
f4 = (T('-- scaled x4') + ht('h', 600, 400) + ht('h', 600, 400.3) + ht('h', 600, 400.7)
      + ht('h', 600, 401.5) + STOP)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1), doaction(f2), doaction(f3), doaction(f4)], w=900, h=900))
