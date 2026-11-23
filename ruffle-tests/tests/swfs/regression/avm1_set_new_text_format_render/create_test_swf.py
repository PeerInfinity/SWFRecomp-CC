#!/usr/bin/env python3
"""avm1_set_new_text_format_render: setNewTextFormat does NOT repaint the
text a field already holds; setTextFormat does.

s26 w2-avm1-text-resolve item 5b. Ruffle edit_text.rs set_new_text_format
only stores new_text_format (the textColor GETTER reads it, which is why
textColor traces red for f1), while the existing FormatSpans -- and so the
rendered glyph colour -- stay black. setTextFormat edits the spans.

Four borderless embedded-font EditText fields (one square "I" glyph,
pixel-aligned at FontHeight 1024 twips: see regression/
avm1_edittext_placed_cxform_script for the font), each holding black "II":
  f1  setNewTextFormat({color:red})                 -> stays black
  f2  setTextFormat({color:red})                    -> red
  f3  setTextFormat(0, {color:red})                 -> first I red, second black
  f4  setNewTextFormat({color:red}); text = "II"    -> red (assignment takes newfmt)

Expected PNG: Ruffle exporter (LOCAL ORACLE REQUEST in
SWFRecompDocs/plans/session26-fanout-reports/w2-avm1-text-resolve-report.md).
Usage: create_test_swf.py <out.swf>
"""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import avm1asm as A  # noqa


class BW:
    def __init__(s): s.bits = []
    def u(s, v, n):
        for i in range(n - 1, -1, -1): s.bits.append((v >> i) & 1)
    def sb(s, v, n): s.u(v & ((1 << n) - 1), n)
    def bytes(s):
        b = s.bits + [0] * ((-len(s.bits)) % 8)
        return bytes(int("".join(map(str, b[i:i + 8])), 2) for i in range(0, len(b), 8))


def nbits_s(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n - 1)) <= v < (1 << (n - 1))): n += 1
    return n


def rect(x0, x1, y0, y1):
    nb = nbits_s(x0, x1, y0, y1)
    w = BW(); w.u(nb, 5)
    for v in (x0, x1, y0, y1): w.sb(v, nb)
    return w.bytes()


def matrix_translate(tx, ty):
    w = BW(); w.u(0, 1); w.u(0, 1)
    nb = nbits_s(tx, ty); w.u(nb, 5); w.sb(tx, nb); w.sb(ty, nb)
    return w.bytes()


def place2(depth, cid, tx, ty, name):
    b = bytes([0x02 | 0x04 | 0x20]) + struct.pack("<HH", depth, cid) + matrix_translate(tx, ty) + A.s(name)
    return A.tag(26, b)


def font2(fid):
    w = BW()
    w.u(1, 4); w.u(0, 4)
    w.u(0, 1); w.u(0, 1); w.u(0, 1); w.u(1, 1); w.u(0, 1); w.u(1, 1)
    nb = nbits_s(100, -700); w.u(nb, 5); w.sb(100, nb); w.sb(-700, nb)
    w.u(1, 1)
    def line(dx, dy):
        w.u(1, 1); w.u(1, 1)
        n = max(nbits_s(dx, dy), 2); w.u(n - 2, 4)
        w.u(0, 1)
        if dx != 0: w.u(0, 1); w.sb(dx, n)
        else: w.u(1, 1); w.sb(dy, n)
    line(300, 0); line(0, 700); line(-300, 0); line(0, -700)
    w.u(0, 6)
    glyph = w.bytes()
    name = b"Sq"
    body = struct.pack("<H", fid) + bytes([0x80, 1, len(name)]) + name
    body += struct.pack("<H", 1)
    body += struct.pack("<HH", 4, 4 + len(glyph)) + glyph
    body += bytes([ord("I")])
    body += struct.pack("<HHh", 800, 200, 0)
    body += struct.pack("<h", 500)
    body += rect(100, 400, -700, 0)
    body += struct.pack("<H", 0)
    return A.tag(48, body)


def edittext(cid, fid):
    b = struct.pack("<H", cid) + rect(0, 1400, 0, 1100)
    b += bytes([0x80 | 0x04 | 0x01,            # HasText | HasTextColor | HasFont
                0x01 | 0x10 | 0x20])            # UseOutlines | NoSelect | HasLayout (no border)
    b += struct.pack("<HH", fid, 1024)
    b += bytes((0, 0, 0)) + b"\xff"
    b += bytes([0]) + struct.pack("<HHHh", 0, 0, 0, 0)
    b += A.s("")
    b += A.s("II")
    return A.tag(37, b)


RED = 0xFF0000


def fmt_red():
    # new TextFormat(); .color = red  -> leaves the object on the stack
    return A.push(0, 'TextFormat') + A.NEWOBJ + A.op(0x4c) + A.push('color', RED) + A.SETMEM


def callm_fmt(target, meth, pre_args=()):
    # target.meth(*pre_args, fmt)
    code = fmt_red()
    for a in reversed(pre_args):
        code += A.push(a)
    # stack: fmt, pre_args reversed...: args are pushed last-first, so fmt must be pushed first
    code += A.push(len(pre_args) + 1) + A.get(target) + A.push(meth) + A.CALLM + A.POP
    return code


T = A.trace_concat
script = (
    callm_fmt('f1', 'setNewTextFormat')
    + callm_fmt('f2', 'setTextFormat')
    + callm_fmt('f3', 'setTextFormat', (0,))
    + callm_fmt('f4', 'setNewTextFormat')
    + A.get('f4') + A.push('text', 'II') + A.SETMEM
    + T('f1 textColor=', A.get('f1.textColor'))
    + T('f1 span0.color=', A.push(1, 0, 2) + A.get('f1') + A.push('getTextFormat') + A.CALLM
        + A.push('color') + A.GETMEM)
    + T('f2 textColor=', A.get('f2.textColor'))
    + T('f3 textColor=', A.get('f3.textColor'))
    + T('f4 textColor=', A.get('f4.textColor'))
)

tags = [A.tag(9, b"\xff\xff\xff"), font2(1), edittext(5, 1)]
tags += [place2(1, 5, 200, 200, 'f1'), place2(2, 5, 1800, 200, 'f2'),
         place2(3, 5, 200, 1600, 'f3'), place2(4, 5, 1800, 1600, 'f4')]
tags += [A.doaction(script), A.SHOW, A.tag(0, b"")]
body = rect(0, 3600, 0, 3000) + struct.pack("<HH", 30 << 8, 1) + b"".join(tags)
open(sys.argv[1], 'wb').write(b"FWS" + bytes([8]) + struct.pack("<I", 8 + len(body)) + body)
