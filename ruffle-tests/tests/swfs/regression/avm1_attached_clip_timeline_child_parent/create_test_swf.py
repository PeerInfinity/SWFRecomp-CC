#!/usr/bin/env python3
"""avm1_attached_clip_timeline_child_parent: sprites that an attachMovie'd
clip's OWN timeline places (not at attach time, on a later frame) must get
MovieClips parented to THAT clip, never to _root.

Found on N's ninja (s27 n-ragdoll-strokes): the ninja is attachMovie'd into a
buffer and its run/land animation places new limb sprites as it plays.
`advance_sprite_frames` initialised those children with
`parent = actionFindMovieClipByName(obj->instance_name)`, else `_root`; an
attached clip's entry has no instance name, so every new limb got a second
MovieClip `_root.instanceNNN` / `_root.footL`. Two visible effects:
  - AS: `_root.kid` existed (Flash/Ruffle: undefined).
  - graphics (OFFSCREEN): the attached-clip pass composed each orphan at an
    identity matrix (drawn at the stage origin) and left the shared child
    entries pointing at dynamic transform slots, so the real compose read an
    IDENTITY local matrix for them. N's limb "bones" are placed with a
    degenerate d=0 matrix (invisible in Flash and Ruffle); losing it drew
    them as extra torso strokes.

Layout: exported sprite "holder" (2 frames). Frame 1 is empty; frame 2
places "kid" (a sprite holding a red 20x20 square) and "bone" (a sprite that
places a blue 40x4 rect with matrix a=1, d=0, i.e. collapsed: invisible),
then stops. Root frame 1 attaches it at (100, 60); root frame 4 traces.

The golden image is the Ruffle exporter's (one instance per shape, so
Ruffle's tessellation cache can't skew it); the Flash Player oracle
(tools/flash-oracle) agrees on what is drawn: the red square at (110, 70)
and nothing else.

Regenerate:  python3 create_test_swf.py
Golden:      WGPU_BACKEND=vulkan ~/CC/ruffle/target/release/exporter -s -f 4 test.swf out  (keep out/3.png)
"""
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (Bits, tag, define_sprite, define_shape_rect, do_action,  # noqa: E402
                     swf_file, place_object2, call_method, get_var, get_path,
                     set_member, push, trace_expr, concat, STOP)

RED, BLUE, KID, BONE, HOLDER = 1, 2, 3, 4, 5


def nbits(*vals):
    return max(max(abs(v).bit_length() for v in vals) + 1, 2)


def place_degenerate(depth, cid):
    """PlaceObject2 with matrix a=1, d=0 (HasScale), no translate."""
    a, d = 65536, 0
    n = nbits(a, d)
    m = Bits().u(1, 1).u(n, 5).s(a, n).s(d, n).u(0, 1).u(0, 5).bytes()
    return tag(26, struct.pack('<BHH', 0x02 | 0x04, depth, cid) + m)


defs = define_shape_rect(RED, 20, 20, (255, 0, 0))
defs += define_shape_rect(BLUE, 40, 4, (0, 0, 255))
defs += define_sprite(KID, [place_object2(1, RED, tx=0, ty=0)])
defs += define_sprite(BONE, [place_degenerate(1, BLUE)])
defs += define_sprite(HOLDER, [
    b'',
    place_object2(1, KID, name='kid', tx=200, ty=200)
    + place_object2(2, BONE, name='bone', tx=200, ty=800)
    + do_action(STOP),
])
defs += tag(56, struct.pack('<HH', 1, HOLDER) + b'holder\x00')

f1 = call_method(get_var('_root'), 'attachMovie', 'holder', 'h', 1)
f1 += set_member(get_var('h'), '_x', push(100.0))
f1 += set_member(get_var('h'), '_y', push(60.0))
TYPEOF = b'\x44'
f4 = trace_expr('h frame: ', get_path('h', '_currentframe'))
f4 += trace_expr('typeof _root.kid: ', get_path('_root', 'kid') + TYPEOF)
f4 += trace_expr('typeof _root.bone: ', get_path('_root', 'bone') + TYPEOF)
f4 += trace_expr('typeof h.kid: ', get_path('h', 'kid') + TYPEOF)
f4 += trace_expr('h.kid target: ', get_path('h', 'kid', '_target'))
f4 += trace_expr('h.bone target: ', get_path('h', 'bone', '_target'))
f4 += STOP
swf_file(HERE / 'test.swf', [do_action(f1), b'', b'', do_action(f4)],
         version=8, w=200, h=150, prefix=defs)
