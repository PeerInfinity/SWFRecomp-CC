#!/usr/bin/env python3
"""avm1_device_edittext_xscale: a timeline-placed DefineEditText DEVICE-font
field (UseOutlines = 0) reports textWidth in its local space: the layout
width times d/a of its concatenated matrix (device text keeps its aspect
ratio), as createTextField (-2) fields already do since s25.

s26 w1-avm1-dispatch-scope item 7. Ruffle display_object/edit_text.rs
measure_text -> layout_to_local_matrix() * text_size, with
Matrix::scale(device_font_scale_x = m.d / m.a, 1) for FontType::Device.
Rows trace the raw width and a +-1 px ratio check so the test does not hang
on device-face metrics.

Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), '..'))
from avm1asm import *  # noqa

T = trace_concat

name = b'_sans'
font = tag(48, struct.pack('<HBB', 2, 0, 0) + bytes([len(name)]) + name + struct.pack('<HH', 0, 2))
flags1 = 0x80 | 0x01          # HasText | HasFont   (no wrap, not multiline)
flags2 = 0x00                 # device text (UseOutlines = 0)
et = tag(37, struct.pack('<H', 3) + rect(0, 4000, 0, 600) + bytes([flags1, flags2])
         + struct.pack('<HH', 2, 240) + s('') + s('Hello device world'))


def near(expr_code, ref_code, factor_num, factor_den):
    # Math.abs(expr * den - ref * num) <= den  (within one pixel of ref*num/den)
    return (expr_code + push(factor_den) + op(0x0c)  # Multiply
            + ref_code + push(factor_num) + op(0x0c) + op(0x0b)  # Subtract
            + push(1, 'Math') + GETVAR + push('abs') + CALLM
            + push(factor_den) + op(0x67) + op(0x12))  # Greater2, Not  -> (abs <= den)


def setxy(xs, ys):
    return (get('t') + push('_xscale', xs) + SETMEM + get('t') + push('_yscale', ys) + SETMEM)


f1 = (
    push('w0') + get('t.textWidth') + SETVAR
    + T('w 100/100 = ', get('w0'))
    + setxy(200, 100) + T('w 200/100 = ', get('t.textWidth'))
    + T('  ~ w0/2: ', near(get('t.textWidth'), get('w0'), 1, 2))
    + setxy(100, 200) + T('w 100/200 = ', get('t.textWidth'))
    + T('  ~ w0*2: ', near(get('t.textWidth'), get('w0'), 2, 1))
    + setxy(200, 200) + T('w 200/200 = ', get('t.textWidth'))
    + T('  ~ w0: ', near(get('t.textWidth'), get('w0'), 1, 1))
    + STOP
)
root = [place(1, 3, 't', x=10, y=10) + doaction(f1)]
open(sys.argv[1], 'wb').write(swf(8, font + et, root, w=300, h=100))
