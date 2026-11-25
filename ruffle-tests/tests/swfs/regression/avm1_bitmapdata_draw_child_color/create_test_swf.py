#!/usr/bin/env python3
"""avm1_bitmapdata_draw_child_color: AVM1 BitmapData.draw() of a holder whose
CHILD clip carries its own colour transform (s27 w2-draw-cx-text, LOCAL ORACLE
REQUEST, FLASH trace). Pins the child-cx composition this slot added to
action.c rasterizeMovieClipToBitmap (it used to pass the draw() cx down
unchanged, so a descendant's Color never tinted).

Each child draws a 40x20 red (0xFF0000) Drawing-API rect; the probe reads the
centre of an opaque blue (0x0000FF) 40x20 BitmapData.
  1. draw(h1)  h1 > c1 (Color(c).setRGB(0x00FF00))        expect 65280 (0x00FF00)
  2. draw(h2)  h2 > c (Color(c).setTransform({rb:0,gb:255,ra:0}))   65280
  3. draw(h3)  h3 > c (c._alpha = 50)                     8323200 (0x7F0080)
  4. draw(h4, m, ct) h4 > c (Color setRGB 0x00FF00), ct = (1,1,1,1, 0,0,255,0)
                                                          expect 65535 (0x00FFFF)
  5. draw(c1) of the tinted child ITSELF (its own transform is ignored) 16711680
LANDED (s27 w2b-draw-text-tint): output.txt is Flash Player 32's trace
(session27-fanout-reports/w2-local-oracles/w2-draw-cx-text/). Line 3: Flash
composites the child at its _alpha over the OPAQUE target, with the fixed-8
cx alpha 255*128>>8 = 127 (red 0x7F, blue 0x80).
Usage: create_test_swf.py [path to regression/_lib]   (writes test.swf here)
"""
import pathlib, sys
HERE = pathlib.Path(__file__).resolve().parent
LIB = pathlib.Path(sys.argv[1]) if len(sys.argv) > 1 else (
    HERE.parents[4] / 'ruffle-tests' / 'tests' / 'swfs' / 'regression' / '_lib')
sys.path.insert(0, str(LIB))
from avm1asm import *  # noqa

NEW_METHOD = bytes([0x53])
INIT_OBJECT = bytes([0x43])

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

def obj(**kv):
    code = b''
    for k, v in kv.items():
        code += push(k, v)
    return code + push(len(kv)) + INIT_OBJECT

def red_rect(path):
    return (call_method(path, 'beginFill', 0xFF0000)
            + call_method(path, 'moveTo', 0, 0) + call_method(path, 'lineTo', 40, 0)
            + call_method(path, 'lineTo', 40, 20) + call_method(path, 'lineTo', 0, 20)
            + call_method(path, 'lineTo', 0, 0) + call_method(path, 'endFill'))

def holder(h, depth):
    # Unique child names: AVM1 Color resolves its target by instance NAME in
    # our runtime (colorGetMCName), so four children all called `c` would all
    # alias h1.c (an s27 w2-draw-cx-text lead, not what this fixture probes).
    c = 'c' + h[1:]
    return (call_method(get_var('this'), 'createEmptyMovieClip', h, depth)
            + call_method(get_var(h), 'createEmptyMovieClip', c, 1)
            + red_rect(get_path(h, c)))

def probe(label, bd):
    return trace_expr(label, call_method(get_var(bd), 'getPixel', 20, 10, discard=False))

def newbd(name):
    return set_var(name, new_cls('display', 'BitmapData', 40, 20, False, 0x0000FF))

a = b''
a += holder('h1', 1)
a += set_var('k1', new_global('Color', get_path('h1', 'c1'))) + call_method(get_var('k1'), 'setRGB', 0x00FF00)
a += newbd('b1') + call_method(get_var('b1'), 'draw', get_var('h1')) + probe('1 draw(h>setRGB c)=', 'b1')
a += holder('h2', 2)
a += set_var('k2', new_global('Color', get_path('h2', 'c2')))
a += call_method(get_var('k2'), 'setTransform', obj(ra=0, rb=0, gb=255))
a += newbd('b2') + call_method(get_var('b2'), 'draw', get_var('h2')) + probe('2 draw(h>setTransform c)=', 'b2')
a += holder('h3', 3)
a += set_member(get_path('h3', 'c3'), '_alpha', 50)
a += newbd('b3') + call_method(get_var('b3'), 'draw', get_var('h3')) + probe('3 draw(h>_alpha50 c)=', 'b3')
a += holder('h4', 4)
a += set_var('k4', new_global('Color', get_path('h4', 'c4'))) + call_method(get_var('k4'), 'setRGB', 0x00FF00)
a += set_var('ct', new_cls('geom', 'ColorTransform', 1, 1, 1, 1, 0, 0, 255, 0))
a += newbd('b4') + call_method(get_var('b4'), 'draw', get_var('h4'), new_cls('geom', 'Matrix'), get_var('ct'))
a += probe('4 draw(h>setRGB c,m,ct)=', 'b4')
a += newbd('b5') + call_method(get_var('b5'), 'draw', get_path('h1', 'c1')) + probe('5 draw(tinted c itself)=', 'b5')
a += STOP
swf_file(HERE / 'test.swf', [do_action(a)], version=8, w=100, h=100)
