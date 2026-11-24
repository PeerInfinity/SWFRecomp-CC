#!/usr/bin/env python3
"""avm1_textfield_attached_depth_order: a createTextField field paints at its
own AS depth among attached clips and empty-clip drawings, and a field inside
an empty holder paints with that holder (s27 w2-holder-drawing-full; Flash/
Ruffle paint an EditText from render_self, inside its parent's child walk).
Fields carry no text, only `background` (no font, no glyphs).

Exported sprite `sq` (id 3) = one red 100x100 DefineShape square at (0,0).
  T1: _root.createTextField("f1",5,20,20,160,80) blue background;
      _root.attachMovie("sq","s1",6) at (60,40) -> red OVER blue.
  T2: h = createEmptyMovieClip("h",7) at (220,20); h.createTextField("f2",1,
      0,0,160,80) green background; _root.attachMovie("sq","s2",8) at
      (260,40) -> red OVER green.
  T3: d = createEmptyMovieClip("d",9) at (20,160) draws a yellow 160x80 rect;
      _root.createTextField("f3",10,60,180,160,80) magenta background ->
      magenta OVER yellow.
  T4 (control): _root.attachMovie("sq","s4",11) at (220,160);
      _root.createTextField("f4",12,260,180,120,80) cyan -> cyan OVER red.
Before s27 w2-holder-drawing-full every such field painted in the REST pass,
after all attached clips (T1, T2 wrong) but before the late Drawing-API pass
(T3 wrong). Golden: hand.expected.png (hand-drawn rects; LOCAL ORACLE
REQUEST: Flash).
Usage: create_test_swf.py <out.swf>
"""
import os, struct, sys
here = os.path.dirname(os.path.abspath(__file__))
# The sibling generator (regression/avm1_holder_drawing_under_children) is a
# script, not a module: pull its helpers. Found next to this dir once landed in
# regression/, else via the repo root (fixture parked under session27 reports).
cands = [os.path.join(here, '..', 'avm1_holder_drawing_under_children', 'create_test_swf.py')]
d = here
while d != os.path.dirname(d):
    cands.append(os.path.join(d, 'ruffle-tests', 'tests', 'swfs', 'regression',
                              'avm1_holder_drawing_under_children', 'create_test_swf.py'))
    d = os.path.dirname(d)
src = open(next(c for c in cands if os.path.exists(c))).read()
helpers = src[src.index('def tag('):src.index('sq = sprite(')]
g = {'struct': struct, 'sys': sys}
exec(helpers, g)
tag, s, push, call, setprop, draw_rect, empty, attach, sprite, place, square_shape, rect_bytes = (
    g[k] for k in ('tag', 's', 'push', 'call', 'setprop', 'draw_rect', 'empty', 'attach',
                   'sprite', 'place', 'square_shape', 'rect_bytes'))
GETVAR, SETMEM, GETMEM, TRACE, STOP, SHOW = b'\x1c', b'\x4f', b'\x4e', b'\x26', b'\x07', g['SHOW']

def field_props(owner, name, rgb):  # owner.name.background = true; .backgroundColor = rgb
    tgt = push(owner) + GETVAR + push(name) + GETMEM
    return (tgt + push('background') + b'\x96\x02\x00\x05\x01' + SETMEM
            + tgt + push('backgroundColor', rgb) + SETMEM)

def tf(owner, name, depth, x, y, w, h, rgb):
    return call(owner, 'createTextField', name, depth, x, y, w, h) + field_props(owner, name, rgb)

def at(name, x, y):
    return setprop(name, '_x', x) + setprop(name, '_y', y)

sq = sprite(3, [place(1, 1)])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('sq'))
T1 = tf('_root', 'f1', 5, 20, 20, 160, 80, 0x0000ff) + attach('_root', 'sq', 's1', 6) + at('s1', 60, 40)
T2 = (empty('h', 7) + at('h', 220, 20) + tf('h', 'f2', 1, 0, 0, 160, 80, 0x00ff00)
      + attach('_root', 'sq', 's2', 8) + at('s2', 260, 40))
T3 = (empty('d', 9) + at('d', 20, 160) + draw_rect('d', 0xffff00, 160, 80)
      + tf('_root', 'f3', 10, 60, 180, 160, 80, 0xff00ff))
T4 = attach('_root', 'sq', 's4', 11) + at('s4', 220, 160) + tf('_root', 'f4', 12, 260, 180, 120, 80, 0x00ffff)
acts = T1 + T2 + T3 + T4 + push('drawn') + TRACE + STOP
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + square_shape(1, 100, (255, 0, 0))
        + sq + exp + tag(12, acts + b'\0') + SHOW + tag(0, b''))
hdr_rest = rect_bytes(0, 8000, 0, 6000) + struct.pack('<HH', 30 << 8, 1)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
