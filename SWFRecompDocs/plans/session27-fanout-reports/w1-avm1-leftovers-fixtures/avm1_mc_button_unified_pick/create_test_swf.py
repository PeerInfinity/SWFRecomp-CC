#!/usr/bin/env python3
"""avm1_mc_button_unified_pick: AS-handler MovieClips (onPress / onRelease /
onRollOver / onRollOut) and DefineButton2 buttons share ONE mouse pick: only
the topmost interactive object under the pointer gets the event.

s27 w1-avm1-leftovers item 1. Ruffle player.rs run_mouse_pick ->
mouse_pick_avm1 walks the render list top-down and returns the FIRST
interactive hit: a DefineButton (avm1_button.rs) or a button-mode clip
(movie_clip.rs: a clip with button handlers returns itself before recursing,
so its children never pick). One target per event.
Zones (100x100 px squares):
  Z1 (0,0)     DefineButton B1 (depth 1) under clip m1 (depth 2)  -> m1 only
  Z2 (200,0)   clip m2 (depth 3) under DefineButton B2 (depth 4)  -> B2 only
  Z3 (0,200)   clip lo (depth 5) under clip hi (depth 6)          -> hi only
  Z4 (200,200) clip par (depth 7) holding clip kid, both handlers -> par only
Each zone: move in, press, release, move out (to the empty (150,150)).

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from avm1asm import *  # noqa


def sbits(v, n):
    return format(v & ((1 << n) - 1), '0%db' % n)


def square_shape(sid, px, rgb):
    w = px * 20
    nb = w.bit_length() + 1
    body = struct.pack('<H', sid) + rect(0, w, 0, w) + b'\x01\x00' + bytes(rgb) + b'\x00'
    b = '0001' + '0000' + '0' + '0' + '0' + '0' + '1' + '1' + '00001' + '0' + '0' + '1'
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        b += '1' + '1' + format(nb - 2, '04b') + '1' + sbits(dx, nb) + sbits(dy, nb)
    b += '000000'
    b += '0' * ((8 - len(b) % 8) % 8)
    return tag(2, body + int(b, 2).to_bytes(len(b) // 8, 'big'))


def trace_this(label):
    return push('this') + GETVAR + push(label) + ADD2 + TRACE


CONDS = [(0x01, 'rollOver'), (0x02, 'rollOut'), (0x04, 'press'), (0x08, 'release')]


def button2(bid, shape_id, name):
    recs = bytes([0x0f]) + struct.pack('<HH', shape_id, 1) + b'\x00' + b'\x00' + b'\x00'
    acts = b''
    for i, (flag, ev) in enumerate(CONDS):
        body = bytes([flag, 0]) + trace_this(' %s %s' % (name, ev)) + b'\x00'
        size = 0 if i == len(CONDS) - 1 else 2 + len(body)
        acts += struct.pack('<H', size) + body
    return tag(34, struct.pack('<HB', bid, 0) + struct.pack('<H', 2 + len(recs)) + recs + acts)


kid = sprite(22, [tag(26, bytes([0x02]) + struct.pack('<HH', 1, 2))])            # blue 50px clip
defs = (square_shape(1, 100, (255, 0, 0)) + square_shape(2, 50, (0, 0, 255))
        + button2(10, 1, 'B1') + button2(11, 1, 'B2')
        + sprite(20, [tag(26, bytes([0x02]) + struct.pack('<HH', 1, 1))])        # red 100px clip
        + kid
        + sprite(21, [tag(26, bytes([0x02]) + struct.pack('<HH', 1, 1)) + place(2, 22, 'kid', 25, 25)]))


def bt_place(depth, cid, x, y):
    return tag(26, bytes([0x02 | 0x04]) + struct.pack('<HH', depth, cid) + matrix_translate(x, y)) if (x or y) \
        else tag(26, bytes([0x02]) + struct.pack('<HH', depth, cid))


def handlers(path):
    code = b''
    for ev in ('onRollOver', 'onRollOut', 'onPress', 'onRelease'):
        code += get(path) + push(ev) + deffunc1('', [], trace_this(' ' + ev)) + SETMEM
    return code


root_f1 = (bt_place(1, 10, 0, 0) + place(2, 20, 'm1')
           + place(3, 20, 'm2', 200, 0) + bt_place(4, 11, 200, 0)
           + place(5, 20, 'lo', 0, 200) + place(6, 20, 'hi', 0, 200)
           + place(7, 21, 'par', 200, 200)
           + doaction(handlers('m1') + handlers('m2') + handlers('lo') + handlers('hi')
                      + handlers('par') + handlers('par.kid') + push('ready') + TRACE + STOP))
open(sys.argv[1], 'wb').write(swf(8, defs, [root_f1]))
