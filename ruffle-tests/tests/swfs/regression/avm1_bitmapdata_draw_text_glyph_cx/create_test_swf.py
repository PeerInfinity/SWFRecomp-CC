#!/usr/bin/env python3
"""avm1_bitmapdata_draw_text_glyph_cx: Flash characterization of DEVICE-font
glyph colour in AVM1 BitmapData.draw() (s27 w2-draw-cx-text, LOCAL ORACLE
REQUEST, FLASH trace). LANDED s27 w2b-draw-text-tint: output.txt = Flash's trace.

Red bold 40px "WMW" (_sans) is drawn onto a transparent BitmapData; the
glyphs' solid interior pixels are counted EXACTLY with
BitmapData.threshold(..., "==", colour) (AA edges ignored), so each line says
whether any fully-covered red (0xFFFF0000) / green (0xFF00FF00) pixel exists.
The tint is ColorTransform(0,1,1,1, 0,255,0,0) / Color.setRGB(0x00FF00):
red -> green.
  1. draw(tf)
  2. draw(tf, m, ct)
  3. draw(h)   h > c (Color(c).setRGB(0x00FF00)) > field
  4. draw(h2, m, ct)  h2 > field
Usage: create_test_swf.py [path to regression/_lib]   (writes test.swf here)
"""
import pathlib, sys
HERE = pathlib.Path(__file__).resolve().parent
LIB = pathlib.Path(sys.argv[1]) if len(sys.argv) > 1 else (
    HERE.parents[4] / 'ruffle-tests' / 'tests' / 'swfs' / 'regression' / '_lib')
sys.path.insert(0, str(LIB))
from avm1asm import *  # noqa

NEW_METHOD = bytes([0x53])
GREATER = bytes([0x67])

def new_cls(pkg, cls, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    code += push(len(args)) + get_path('flash', pkg) + push(cls) + NEW_METHOD
    return code

def new_global(cls, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    code += push(len(args)) + push(cls) + bytes([0x40])

    return code

def field(path_code):
    a = set_member(path_code, 'text', 'WMW')
    a += set_var('fmt', new_global('TextFormat'))
    a += set_member(get_var('fmt'), 'font', '_sans')
    a += set_member(get_var('fmt'), 'size', 40)
    a += set_member(get_var('fmt'), 'bold', True)
    a += set_member(get_var('fmt'), 'color', 0xFF0000)
    a += call_method(path_code, 'setTextFormat', get_var('fmt'))
    return a

def count(bd, colour):
    # bd.threshold(bd, bd.rectangle, new Point(0,0), "==", c, c, 0xFFFFFFFF, false) > 0
    return call_method(get_var(bd), 'threshold', get_var(bd), get_path(bd, 'rectangle'),
                       new_cls('geom', 'Point', 0, 0), '==', colour, colour,
                       -1, False, discard=False) + push(0) + GREATER

def probe(label, bd):
    return trace_expr(label, ' red=', count(bd, -65536), ' green=', count(bd, -16711936))

def newbd(name):
    return set_var(name, new_cls('display', 'BitmapData', 200, 60, True, 0))

this = get_var('this')
a = b''
a += call_method(this, 'createTextField', 'tf', 1, 0, 0, 200, 60)
a += field(get_var('tf'))
a += set_var('ct', new_cls('geom', 'ColorTransform', 0, 1, 1, 1, 0, 255, 0, 0))
a += newbd('b1') + call_method(get_var('b1'), 'draw', get_var('tf'))
a += probe('draw(tf)', 'b1')
a += newbd('b2') + call_method(get_var('b2'), 'draw', get_var('tf'), new_cls('geom', 'Matrix'), get_var('ct'))
a += probe('draw(tf,m,ct)', 'b2')
a += call_method(this, 'createEmptyMovieClip', 'h', 2)
a += call_method(get_var('h'), 'createEmptyMovieClip', 'c', 1)
a += call_method(get_path('h', 'c'), 'createTextField', 't', 1, 0, 0, 200, 60)
a += field(get_path('h', 'c', 't'))
a += set_var('col', new_global('Color', get_path('h', 'c')))
a += call_method(get_var('col'), 'setRGB', 0x00FF00)
a += newbd('b3') + call_method(get_var('b3'), 'draw', get_var('h'))
a += probe('draw(h>Color c>tf)', 'b3')
a += call_method(this, 'createEmptyMovieClip', 'h2', 3)
a += call_method(get_var('h2'), 'createTextField', 't', 1, 0, 0, 200, 60)
a += field(get_path('h2', 't'))
a += newbd('b4') + call_method(get_var('b4'), 'draw', get_var('h2'), new_cls('geom', 'Matrix'), get_var('ct'))
a += probe('draw(h2>tf,m,ct)', 'b4')
a += STOP
swf_file(HERE / 'test.swf', [do_action(a)], version=8, w=200, h=100)
