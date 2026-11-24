#!/usr/bin/env python3
"""avm1_attached_clip_selfgoto_child_parent: sprites placed by an
attachMovie'd clip's timeline when its OWN frame script self-gotos
(gotoAndPlay) to the frame that places them must get MovieClips parented to
THAT clip, never to _root.

Sibling of avm1_attached_clip_timeline_child_parent (natural advance). This
one reaches the goto-rebuild child-init block in
tag.c ng_apply_pending_sprite_self_gotos (s27 n-l2l4-pixel-pass goal 2),
which resolved the parent by the entry's instance name, else _root; an
attached clip's entry has no instance name.

Layout: exported sprite "holder" (4 frames). Frame 1 empty; frame 2 runs
gotoAndPlay(4); frame 3 empty (skipped); frame 4 places "kid" (a sprite
holding a red 20x20 square) and "bone" (a sprite placing a blue 40x4 rect
with a=1, d=0: collapsed, invisible), then stops. Root frame 1 attaches it
at (100, 60); root frame 6 traces.

Golden: Ruffle exporter frame 5 (one instance per shape); the Flash Player
oracle (tools/flash-oracle) is checked against it (see output.txt notes in
SWFRecompDocs/plans/n-l2l4-pixel-pass-report.md).

Regenerate:  python3 create_test_swf.py
Golden:      WGPU_BACKEND=vulkan ~/CC/ruffle/target/release/exporter -s -f 6 test.swf out  (keep out/5.png)
"""
import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent / '_lib'))
from avm1asm import (Bits, tag, define_sprite, define_shape_rect, do_action,  # noqa: E402
                     swf_file, place_object2, call_method, get_var, get_path,
                     set_member, push, trace_expr, concat, STOP,
                     goto_frame, PLAY)

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
    do_action(goto_frame(3) + PLAY),
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
swf_file(HERE / 'test.swf', [do_action(f1), b'', b'', b'', b'', do_action(f4)],
         version=8, w=200, h=150, prefix=defs)
