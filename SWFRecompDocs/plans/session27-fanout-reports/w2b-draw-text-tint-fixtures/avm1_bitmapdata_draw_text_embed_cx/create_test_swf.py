#!/usr/bin/env python3
"""avm1_bitmapdata_draw_text_embed_cx: the EMBEDDED-font twin of
regression/avm1_bitmapdata_draw_text_glyph_cx (s27 w2b-draw-text-tint, LOCAL
ORACLE REQUEST, FLASH trace). Not a landed fixture: output.txt must come from
Flash Player.

AVM2 Flash (avm2_bitmapdata_draw_text_glyph_cx) says an embedded field's
glyphs AND box follow the draw() ct, the field's own / an ancestor's cx and
holder + ct, while a device field draws no solid glyph pixel and its box is
never tinted. This asks the same of AVM1.

Font: the DefineFont3 "TestFont" (DejaVu Sans, U+0020-U+007E) + DefineFontName
tags copied byte-for-byte from the mxmlc-built
regression/avm2_bitmapdata_draw_textfield/test.swf (Flash-valid outlines, not
a synthetic square-glyph font), exported to AS as "TestFont".

G lines: red bold 40px "WMW" (embedFonts = true, font "TestFont") drawn onto a
transparent 200x60 BitmapData; solid (0xFFFF0000 / 0xFF00FF00) pixels are
counted exactly with threshold("=="). X lines: centre of an opaque-blue 40x20
BitmapData behind a textless 40x20 embedded field with a red background.
Tint: ColorTransform(0,1,1,1, 0,255,0,0) / Color.setRGB(0x00FF00).
  draw(tf) / draw(tf,m,ct) / draw(h>Color c>tf) / draw(h2>tf,m,ct)
Usage: create_test_swf.py [path to regression/_lib]   (writes test.swf here)
"""
import pathlib, struct, sys, zlib
HERE = pathlib.Path(__file__).resolve().parent
ROOT = HERE.parents[4]
REG = ROOT / 'ruffle-tests' / 'tests' / 'swfs' / 'regression'
LIB = pathlib.Path(sys.argv[1]) if len(sys.argv) > 1 else REG / '_lib'
sys.path.insert(0, str(LIB))
from avm1asm import *  # noqa

NEW_METHOD = bytes([0x53])
GREATER = bytes([0x67])


def font_tags():
    d = (REG / 'avm2_bitmapdata_draw_textfield' / 'test.swf').read_bytes()
    if d[:3] == b'CWS':
        d = d[:8] + zlib.decompress(d[8:])
    p = 8 + (5 + 4 * (d[8] >> 3) + 7) // 8 + 4
    out = b''
    while p < len(d):
        h = struct.unpack('<H', d[p:p + 2])[0]
        code, ln, hp = h >> 6, h & 63, 2
        if ln == 63:
            ln, hp = struct.unpack('<I', d[p + 2:p + 6])[0], 6
        if code in (75, 88):
            out += d[p:p + hp + ln]
        p += hp + ln
        if code == 0:
            break
    assert out
    # ExportAssets(1 -> "TestFont"): the font is char id 1 in that SWF.
    return out + tag(56, struct.pack('<HH', 1, 1) + b'TestFont\x00')


def new_cls(pkg, cls, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    return code + push(len(args)) + get_path('flash', pkg) + push(cls) + NEW_METHOD


def new_global(cls, *args):
    code = b''
    for a in reversed(args):
        code += a if isinstance(a, bytes) else push(a)
    return code + push(len(args)) + push(cls) + bytes([0x40])


def glyph_field(p):
    a = set_member(p, 'embedFonts', True)
    a += set_member(p, 'selectable', False)
    a += set_member(p, 'text', 'WMW')
    a += set_var('fmt', new_global('TextFormat'))
    a += set_member(get_var('fmt'), 'font', 'TestFont')
    a += set_member(get_var('fmt'), 'size', 40)
    a += set_member(get_var('fmt'), 'bold', True)
    a += set_member(get_var('fmt'), 'color', 0xFF0000)
    a += call_method(p, 'setTextFormat', get_var('fmt'))
    return a


def box_field(p):
    a = set_member(p, 'embedFonts', True)
    a += set_member(p, 'background', True)
    a += set_member(p, 'backgroundColor', 0xFF0000)
    return a


def count(bd, colour):
    return call_method(get_var(bd), 'threshold', get_var(bd), get_path(bd, 'rectangle'),
                       new_cls('geom', 'Point', 0, 0), '==', colour, colour,
                       -1, False, discard=False) + push(0) + GREATER


def gprobe(label, bd):
    return trace_expr(label, ' red=', count(bd, -65536), ' green=', count(bd, -16711936))


def xprobe(label, bd):
    return trace_expr(label, call_method(call_method(get_var(bd), 'getPixel', 20, 10,
                                                     discard=False),
                                         'toString', 16, discard=False))


this = get_var('this')
a = set_var('ct', new_cls('geom', 'ColorTransform', 0, 1, 1, 1, 0, 255, 0, 0))
depth = [1]


def variants(kind, w, h, make, probe, bdargs):
    global a
    pre = '%s embed ' % kind + ('box ' if kind == 'X' else '')
    d = depth[0]; depth[0] += 4
    n = kind.lower()
    # 1. draw(tf)
    a += call_method(this, 'createTextField', n + 'tf', d, 0, 0, w, h) + make(get_var(n + 'tf'))
    a += set_var('b', new_cls('display', 'BitmapData', *bdargs))
    a += call_method(get_var('b'), 'draw', get_var(n + 'tf')) + probe(pre + 'draw(tf)' + (' = ' if kind == 'X' else ''), 'b')
    # 2. draw(tf, m, ct)
    a += set_var('b', new_cls('display', 'BitmapData', *bdargs))
    a += call_method(get_var('b'), 'draw', get_var(n + 'tf'), new_cls('geom', 'Matrix'), get_var('ct'))
    a += probe(pre + 'draw(tf,m,ct)' + (' = ' if kind == 'X' else ''), 'b')
    # 3. draw(h > Color c > tf)
    h1, c1 = n + 'h', n + 'c'
    a += call_method(this, 'createEmptyMovieClip', h1, d + 1)
    a += call_method(get_var(h1), 'createEmptyMovieClip', c1, 1)
    a += call_method(get_path(h1, c1), 'createTextField', 't', 1, 0, 0, w, h)
    a += make(get_path(h1, c1, 't'))
    a += set_var('col', new_global('Color', get_path(h1, c1)))
    a += call_method(get_var('col'), 'setRGB', 0x00FF00)
    a += set_var('b', new_cls('display', 'BitmapData', *bdargs))
    a += call_method(get_var('b'), 'draw', get_var(h1))
    a += probe(pre + 'draw(h>Color c>tf)' + (' = ' if kind == 'X' else ''), 'b')
    # 4. draw(h2 > tf, m, ct)
    h2 = n + 'h2'
    a += call_method(this, 'createEmptyMovieClip', h2, d + 2)
    a += call_method(get_var(h2), 'createTextField', 't', 1, 0, 0, w, h)
    a += make(get_path(h2, 't'))
    a += set_var('b', new_cls('display', 'BitmapData', *bdargs))
    a += call_method(get_var('b'), 'draw', get_var(h2), new_cls('geom', 'Matrix'), get_var('ct'))
    a += probe(pre + 'draw(h2>tf,m,ct)' + (' = ' if kind == 'X' else ''), 'b')


variants('G', 200, 60, glyph_field, gprobe, (200, 60, True, 0))
variants('X', 40, 20, box_field, xprobe, (40, 20, False, 0x0000FF))
a += STOP
swf_file(HERE / 'test.swf', [do_action(a)], version=8, w=200, h=100, prefix=font_tags())
