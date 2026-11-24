#!/usr/bin/env python3
"""avm1_browser_gated_color: Color.getRGB and the flash.geom.Transform
concatenated getters on a dynamic clip.

s27 w1-browser-avm1-gaps: colorGetRGB, transformConcatMatrixGetter and
transformConcatCTGetter returned undefined in the browser-WASM build (no-op
`#else` arms). Corpus Flash goldens for the same rules: avm1/color,
avm1/transform.

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
    callm('this', 'createEmptyMovieClip', 'c1', 1)
    + callm('c1', 'createEmptyMovieClip', 'c2', 1)
    + push('col') + get('c1.c2') + push(1, 'Color') + NEWOBJ + SETVAR
    + callm('col', 'setRGB', 0x336699)
    + T('getRGB=', callm('col', 'getRGB', keep=True))
    + setm('c1', '_x', push(10)) + setm('c1', '_xscale', push(200))
    + setm('c1.c2', '_y', push(5))
    + push('cm') + get('c1.c2.transform.concatenatedMatrix') + SETVAR
    + T('cm a=', get('cm.a'), ' d=', get('cm.d'), ' tx=', get('cm.tx'), ' ty=', get('cm.ty'))
    + push('ct') + get('c1.c2.transform.concatenatedColorTransform') + SETVAR
    + T('ct rm=', get('ct.redMultiplier'), ' ro=', get('ct.redOffset'), ' go=', get('ct.greenOffset'), ' bo=', get('ct.blueOffset'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
