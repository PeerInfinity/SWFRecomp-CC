#!/usr/bin/env python3
"""avm1_browser_gated_textfield: createTextField (CallFunction AND CallMethod
forms), TextField _width/_height twip truncation, setNewTextFormat, and
getBounds of a text field.

s27 w1-browser-avm1-gaps. Every row here is served by an action.c arm that was
`#if NO_GRAPHICS || OFFSCREEN_RENDER` with a no-op `#else` (browser-WASM pushed
undefined / skipped the twip rule / returned the 6710886.35 sentinel). The
native legs lock the semantics; the browser arm must match. Corpus Flash
goldens for the same rules: avm1/movieclip_create_text_field (h = 3.9),
avm1/movieclip_getbounds.

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat


def setm(path, prop, value_code):
    return get(path) + push(prop) + value_code + SETMEM


def callmc(target, meth, *arg_codes, keep=False):
    """target.meth(args) where each arg is code leaving one value."""
    code = b''.join(reversed(arg_codes)) + push(len(arg_codes)) + get(target) + push(meth) + CALLM
    return code if keep else code + POP


f1 = (
    # CallFunction form (bare call): SWF8 returns the new field.
    push('r') + callf('createTextField', 'tfA', 5, 10, 20, 30, 40, keep=True) + SETVAR
    + T('cf typeof r=', typeof_('r'), ' tfA=', typeof_('tfA'))
    + T('cf tfA x=', get('tfA._x'), ' y=', get('tfA._y'), ' w=', get('tfA._width'), ' h=', get('tfA._height'))
    + T('cf tfA depth=', callm('tfA', 'getDepth', keep=True))
    # CallMethod form.
    + callm('this', 'createTextField', 'tfB', 6, 1, 2, 3, 4)
    + T('cm tfB=', typeof_('tfB'), ' depth=', callm('tfB', 'getDepth', keep=True))
    # _width/_height on a TextField: direct dimension, truncated to whole twips.
    + setm('tfB', '_height', push(3.95)) + setm('tfB', '_width', push(10.07))
    + T('tfB w=', get('tfB._width'), ' h=', get('tfB._height'), ' xs=', get('tfB._xscale'))
    # setNewTextFormat -> getNewTextFormat round trip.
    + push('fmt') + push(0, 'TextFormat') + NEWOBJ + SETVAR
    + setm('fmt', 'color', push(0xFF0000)) + setm('fmt', 'size', push(17))
    + callmc('tfB', 'setNewTextFormat', get('fmt'))
    + push('nf') + callm('tfB', 'getNewTextFormat', keep=True) + SETVAR
    + T('newfmt color=', get('nf.color'), ' size=', get('nf.size'))
    # getBounds of a text field in its parent's space.
    + push('b') + callmc('tfA', 'getBounds', get('_root'), keep=True) + SETVAR
    + T('tfA bounds ', get('b.xMin'), ',', get('b.yMin'), ',', get('b.xMax'), ',', get('b.yMax'))
    + STOP
)
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
