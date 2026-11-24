#!/usr/bin/env python3
"""avm1_bitmapdata_draw_edittext: AVM1 BitmapData.draw() of a TextField.

s27 w1-text-glyph-fidelity item 4 (playbook s25 "draw() of a tinted
EditText"). AVM1 rasterizeMovieClipToBitmap (action.c) walks a clip's
Drawing-API paths, its timeline shapes/static text (bd1_draw_timeline_entry,
which skips DefineEditText characters) and its child clips; a TextField
(MC_IS_TEXTFIELD) contributes nothing, so draw() of a field, or of a clip
holding one, paints no background, border or glyphs. It also passes the
draw colorTransform down unchanged, so a descendant's own Color never tints.

Probes read the field BACKGROUND (a solid fill) at the field centre, on an
opaque blue BitmapData (0x0000FF = 255):
  1. bd.draw(tf)                      -> 16711680 (0xFF0000, the background)
  2. bd.draw(tf, new Matrix(), ct)    ct = ColorTransform(0,1,1,1, 0,255,0,0)
                                       -> 16711680 (NOT tinted)
  3. bd.draw(h)   h > c (Color(c).setRGB(0x00FF00)) > field
                                       -> 16711680 (NOT tinted)
output.txt is FLASH PLAYER 32's trace (s27 coordinator oracle,
SWFRecompDocs/plans/session27-fanout-reports/w1-local-oracles/
w1-text-glyph-fidelity/avm1_bitmapdata_draw_edittext/flash.txt): in draw()
neither the draw colorTransform nor an ancestor's Color tints a TextField's
background. The w1 by-construction golden (and Ruffle's exporter, oracle.txt)
said 65280 on lines 2-3; Flash overrules both. Fixed by s27 w2-draw-cx-text
(action.c bd1_draw_textfield_box).

Usage: create_test_swf.py   (writes test.swf next to this file)
"""
import pathlib, struct, sys
HERE = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import *  # noqa

NEW_METHOD = bytes([0x53])
INIT_OBJ = None

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
    code += push(len(args)) + push(cls) + bytes([0x40])   # ActionNewObject
    return code

def field_setup(path_code):
    return (set_member(path_code, 'background', True)
            + set_member(path_code, 'backgroundColor', 0xFF0000))

def probe(label, bd):
    return trace_expr(label, call_method(get_var(bd), 'getPixel', 20, 10, discard=False))

this = get_var('this')
a = b''
a += call_method(this, 'createTextField', 'tf', 1, 0, 0, 40, 20)
a += field_setup(get_var('tf'))
a += set_var('bd', new_cls('display', 'BitmapData', 40, 20, False, 0x0000FF))
a += call_method(get_var('bd'), 'draw', get_var('tf'))
a += probe('draw(tf)=', 'bd')
a += set_var('ct', new_cls('geom', 'ColorTransform', 0, 1, 1, 1, 0, 255, 0, 0))
a += set_var('bd2', new_cls('display', 'BitmapData', 40, 20, False, 0x0000FF))
a += call_method(get_var('bd2'), 'draw', get_var('tf'), new_cls('geom', 'Matrix'), get_var('ct'))
a += probe('draw(tf,m,ct)=', 'bd2')
a += call_method(this, 'createEmptyMovieClip', 'h', 2)
a += call_method(get_var('h'), 'createEmptyMovieClip', 'c', 1)
a += call_method(get_path('h', 'c'), 'createTextField', 't', 1, 0, 0, 40, 20)
a += field_setup(get_path('h', 'c', 't'))
a += set_var('col', new_global('Color', get_path('h', 'c')))
a += call_method(get_var('col'), 'setRGB', 0x00FF00)
a += set_var('bd3', new_cls('display', 'BitmapData', 40, 20, False, 0x0000FF))
a += call_method(get_var('bd3'), 'draw', get_var('h'))
a += probe('draw(h)=', 'bd3')
a += STOP
swf_file(HERE / 'test.swf', [do_action(a)], version=8, w=100, h=100)
