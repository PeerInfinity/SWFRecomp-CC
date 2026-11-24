#!/usr/bin/env python3
"""avm1_browser_gated_depth: createEmptyMovieClip (CallFunction form),
getInstanceAtDepth (both forms), duplicateMovieClip (method form), and _width
on an empty clip.

s27 w1-browser-avm1-gaps: each of these was a no-op `#else` arm (or, for
_width, a raw `mc->width = v`) in the browser-WASM build. Corpus Flash goldens
for the same rules: avm1/movieclip_get_instance_at_depth,
avm1/create_empty_movie_clip, avm1/duplicate_movie_clip.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def setm(path, prop, value_code):
    return get(path) + push(prop) + value_code + SETMEM


f1 = (
    callf('createEmptyMovieClip', 'e1', 3)
    + T('cf e1=', typeof_('e1'), ' depth=', callm('e1', 'getDepth', keep=True))
    + callm('this', 'createEmptyMovieClip', 'e2', 4)
    + T('cm giad(4)=', callm('this', 'getInstanceAtDepth', 4, keep=True))
    + T('cf giad(3)=', callf('getInstanceAtDepth', 3, keep=True))
    + T('cm giad(99)=', callm('this', 'getInstanceAtDepth', 99, keep=True))
    + setm('e2', 'marker', push('m2'))
    + push('d') + callm('e2', 'duplicateMovieClip', 'e3', 7, keep=True) + SETVAR
    + T('dup ret=', get('d'), ' e3=', typeof_('e3'), ' depth=', callm('e3', 'getDepth', keep=True))
    + T('e3 marker=', get('e3.marker'), ' giad(7)=', callm('this', 'getInstanceAtDepth', 7, keep=True))
    # _width on an empty clip: no bounds -> both scales collapse to 0.
    + setm('e1', '_width', push(50))
    + T('e1 w=', get('e1._width'), ' xs=', get('e1._xscale'), ' ys=', get('e1._yscale'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
