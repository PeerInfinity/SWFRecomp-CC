#!/usr/bin/env python3
"""avm1_create_text_field_depth: MovieClip.createTextField (CallMethod form)
stores its depth, ToStrings a numeric name, and replaces the previous
occupant of (parent, depth) -- as does createEmptyMovieClip over a text field.

s26 w1-avm1-dispatch-scope items 4 + 6. Ruffle core/src/avm1/globals/
movie_clip.rs create_text_field: name = args[0].coerce_to_string, depth =
args[1].coerce_to_f64 as i32 ... movie_clip.replace_at_depth(text_field, depth).

Usage: create_test_swf.py <out.swf>
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat
f1 = (
    callm('this', 'createTextField', 'tf', 7, 0, 0, 10, 10)
    + T('tf depth=', callm('tf', 'getDepth', keep=True))
    + T('gnhd=', callm('this', 'getNextHighestDepth', keep=True))
    + callm('this', 'createTextField', 'tf2', 7, 0, 0, 10, 10)
    + T('after tf2: tf=', typeof_('tf'), ' tf2=', typeof_('tf2'))
    + T('giad7=', callm('this', 'getInstanceAtDepth', 7, keep=True))
    + callm('this', 'createEmptyMovieClip', 'm', 7)
    + T('after m: tf2=', typeof_('tf2'), ' m=', typeof_('m'), ' m.depth=', callm('m', 'getDepth', keep=True))
    + callm('this', 'createTextField', 3, 9, 0, 0, 10, 10)
    + T('num name: ', push('_root') + GETVAR + push('3') + GETMEM + TYPEOF)
    + T('num depth=', push('_root') + GETVAR + push('3') + GETMEM + push(0) + push('getDepth') + op(0x52))
    + callm('this', 'createEmptyMovieClip', 'm2', 11)
    + callm('this', 'createTextField', 'tf3', 11, 0, 0, 10, 10)
    + T('tf over mc: m2=', typeof_('m2'), ' tf3=', typeof_('tf3'))
    + T('gnhd2=', callm('this', 'getNextHighestDepth', keep=True))
    + STOP
)
# fix the getDepth call: args count must precede receiver -> rebuild explicitly
f1 = f1.replace(push('_root') + GETVAR + push('3') + GETMEM + push(0) + push('getDepth') + op(0x52),
                push(0) + push('_root') + GETVAR + push('3') + GETMEM + push('getDepth') + op(0x52))
open(sys.argv[1], 'wb').write(swf(8, b'', [doaction(f1)]))
