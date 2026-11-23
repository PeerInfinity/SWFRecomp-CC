#!/usr/bin/env python3
"""s26 w1-pixel-layer-colour: proposed regression/ fixtures (wave 2 moves each
dir under ruffle-tests/tests/swfs/regression/). Usage: create_fixtures.py OUTDIR

1. layer_group_filtered_child (lead N1): two layered groups, each holding
   red rect / FILTERED blue rect / green rect (drawn in that order):
     left  = sprite placed with blend LAYER (2)
     right = sprite placed with blend MULTIPLY (3)
   White stage, so both blends reduce to normal-over: the golden is the plain
   render. The filter is a DropShadow with blur 0, distance 4, angle 0,
   strength 1 (a hard black copy 4 px right of the blue rect), so every edge
   is on a whole pixel and the golden is analytic.
   Bug (origin/master): the filter capture clears the group's offscreen
   (red rect lost) and resumes the MAIN surface; under MULTIPLY its blur
   ping-pong also overwrote the group's backdrop in filter_tex_b.
2. avm1_placed_drawing_color (lead: colour of Drawing-API content in placed
   clips + dynamic-under-placed colour + folded ColorMatrix alpha row).
   Each case draws a red 80x60 rect with the AVM1 Drawing API:
     A placed with CXFORM (mult 0,0,0,1; add 0,0,255,0)          -> blue
     B placed plain, new Color(pb).setRGB(0x00FF00)               -> green
     C placed plain, _alpha = 50                                  -> red @ .5 (control: already right)
     D placed with A's CXFORM; draws in a createEmptyMovieClip child -> blue
     F placed with CXFORM alpha mult 128/256                      -> red @ .5
     G timeline red DefineShape3 rect, PlaceObject3 ColorMatrix
       with alpha row (0.5, 0, 0, 0, 0) (A' = 0.5 R; a->a = 0)    -> red @ .5
   Goldens are analytic (0.5 alpha over white = 127.5: written as 127 on G,B;
   tolerance 1 absorbs the rounding); LOCAL ORACLE REQUEST asks for the Ruffle
   exporter render to replace them.
"""
import sys, pathlib, struct
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from mkprobes import *

def dropshadow0(dist, angle_rad=0.0, rgba=(0, 0, 0, 255)):
    # DROPSHADOWFILTER: RGBA, BlurX/Y FIXED, Angle FIXED, Distance FIXED,
    # Strength FIXED8, flags: inner(1) knockout(1) composite(1) passes(5)
    return (bytes([0]) + bytes(rgba) + struct.pack('<II', 0, 0)
            + struct.pack('<i', int(angle_rad * 65536)) + struct.pack('<i', int(dist * 65536))
            + struct.pack('<H', 256) + bytes([0x20 | 1]))

def fixture_layer():
    def group(sid, ox):
        return sprite(sid, [place3(1, 1, ox + 10, 20), place3(2, 2, ox + 40, 40, filters=[dropshadow0(4)]),
                            place3(3, 3, ox + 70, 70)])
    tags = [shape(1, [(0, 0, 50, 40)], RED), shape(2, [(0, 0, 40, 40)], BLUE), shape(3, [(0, 0, 30, 30)], GREEN),
            group(10, 0), group(11, 120), place3(1, 10, blend=2), place3(2, 11, blend=3)]
    return movie(tags, w=240, h=120)

def fixture_layer_avm2():
    """Variant 3 (avm2_layer_group_filtered_child): fixture 1 with
    FileAttributes.ActionScript3 and the s25 minimal DoABC (one script,
    init = getlocal0 / pushscope / returnvoid), so the same placements go
    through avm2_display.c (avm2_render_node blend arm + avm2_render_filtered).
    Same golden."""
    b = bytearray(fixture_layer())
    abc = (struct.pack("<HH", 16, 46) + bytes(7) + bytes([1, 0, 0, 0, 0])
           + bytes([0]) + bytes([0]) + bytes([1, 0, 0])
           + bytes([1, 0, 1, 1, 0, 1, 3, 0xD0, 0x30, 0x47, 0, 0]))
    doabc = tag(82, struct.pack("<I", 1) + b"\0" + abc)
    fa = tag(69, bytes([0, 0, 0, 0]))
    i0 = b.index(fa)
    b[i0:i0 + len(fa)] = tag(69, bytes([0x08, 0, 0, 0])) + doabc
    b[4:8] = struct.pack('<I', len(b))
    return bytes(b)

def golden_layer():
    from PIL import Image
    img = Image.new('RGBA', (240, 120), (255, 255, 255, 255)); px = img.load()
    def fill(x, y, w, h, c):
        for yy in range(y, y + h):
            for xx in range(x, x + w):
                if 0 <= xx < 240 and 0 <= yy < 120: px[xx, yy] = c
    for ox in (0, 120):
        fill(ox + 10, 20, 50, 40, (255, 0, 0, 255))
        fill(ox + 44, 40, 40, 40, (0, 0, 0, 255))      # hard shadow, +4 px
        fill(ox + 40, 40, 40, 40, (0, 0, 255, 255))
        fill(ox + 70, 70, 30, 30, (0, 255, 0, 255))
    return img

def fixture_placed():
    BLUEX = cxform_alpha(mult=(0, 0, 0, 256), add=(0, 0, 255, 0))
    tags = [sprite(10, []), shape(1, [(0, 0, 80, 60)], RED),
            place3(1, 10, 10, 10, cx=BLUEX, name='pa'),
            place3(2, 10, 110, 10, name='pb'),
            place3(3, 10, 210, 10, name='pc'),
            place3(4, 10, 310, 10, cx=BLUEX, name='pd'),
            place3(6, 10, 10, 110, cx=cxform_alpha(mult=(256, 256, 256, 128)), name='pf'),
            place3(7, 1, 110, 110, filters=[colormatrix(AFROMR)])]
    a = drect(['pa'], 0, 0, 80, 60, 0xFF0000)
    a += drect(['pb'], 0, 0, 80, 60, 0xFF0000)
    a += push(s('cb')) + newglobal('Color', [s('pb')]) + SETVAR + call(['cb'], 'setRGB', [i(0x00FF00)])
    a += drect(['pc'], 0, 0, 80, 60, 0xFF0000) + setp(['pc'], '_alpha', push(i(50)))
    a += call(['pd'], 'createEmptyMovieClip', [s('c'), i(1)]) + drect(['pd', 'c'], 0, 0, 80, 60, 0xFF0000)
    a += drect(['pf'], 0, 0, 80, 60, 0xFF0000)
    a += push(s('done')) + TRACE + b'\x00'
    tags.append(tag(12, a))
    return movie(tags, w=400, h=180, ver=8)

def golden_placed():
    from PIL import Image
    img = Image.new('RGBA', (400, 180), (255, 255, 255, 255)); px = img.load()
    half = (255, 127, 127, 255)
    for (x, y, c) in [(10, 10, (0, 0, 255, 255)), (110, 10, (0, 255, 0, 255)), (210, 10, half),
                      (310, 10, (0, 0, 255, 255)), (10, 110, half), (110, 110, half)]:
        for yy in range(y, y + 60):
            for xx in range(x, x + 80): px[xx, yy] = c
    return img

TOML = 'num_ticks = 1\n\n[image_comparisons.output]\ntolerance = 1\n\n[player_options]\nwith_renderer = { optional = false }\n'
if __name__ == '__main__':
    out = pathlib.Path(sys.argv[1])
    for name, swf, gold, trace in [('layer_group_filtered_child', fixture_layer(), golden_layer, ''),
                                   ('avm2_layer_group_filtered_child', fixture_layer_avm2(), golden_layer, ''),
                                   ('avm1_placed_drawing_color', fixture_placed(), golden_placed, 'done\n')]:
        d = out / name; d.mkdir(parents=True, exist_ok=True)
        (d / 'test.swf').write_bytes(swf); (d / 'output.txt').write_text(trace); (d / 'test.toml').write_text(TOML)
        gold().save(d / 'output.expected.png')
        print(d)
