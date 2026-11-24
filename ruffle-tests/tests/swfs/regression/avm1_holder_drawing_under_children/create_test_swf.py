#!/usr/bin/env python3
"""avm1_holder_drawing_under_children: a clip's Drawing-API content paints
BELOW its children, and an empty clip's drawing layers at its own depth among
attached siblings (s27 w1-render-bitmap-leads lead 1).

Exported sprite `sq` (id 3) = one red 100x100 DefineShape square at (0,0).
  A: h  = _root.createEmptyMovieClip("h", 2) at (20,20); h draws a blue
     200x100 rect; h.attachMovie("sq","c",1) -> red square at stage (20,20)
     must be ON TOP of the blue (Flash: Graphics under children).
  B: d  = _root.createEmptyMovieClip("d", 5) at (20,160) draws a green
     200x100 rect; _root.attachMovie("sq","t",6) at (60,180) -> red over green.
  C: _root.attachMovie("sq","u",7) at (260,20); e = createEmptyMovieClip("e",8)
     at (300,60) draws a blue 100x100 rect -> blue over red (control).
Golden: Ruffle exporter (LOCAL ORACLE REQUEST, s27 w1-render-bitmap-leads).
Usage: create_test_swf.py <out.swf> [cases]   (default "AC"; the sibling
fixture avm1_empty_clip_drawing_depth_order runs this script with "BC")
"""
import struct, sys

def tag(code, data):
    if len(data) < 63:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data

def s(x): return x.encode() + b'\0'

def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str): b += b'\x00' + s(it)
        else: b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b

GETVAR, SETMEM, CALLM, POP, TRACE, STOP, SETVAR = b'\x1c', b'\x4f', b'\x52', b'\x17', b'\x26', b'\x07', b'\x1d'
SHOW = tag(1, b'')

def rect_bytes(x0, x1, y0, y1):
    nb = max(v.bit_length() for v in (x0, x1, y0, y1)) + 1
    bits = '{:05b}'.format(nb) + ''.join(format(v, '0%db' % nb) for v in (x0, x1, y0, y1))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')

def square_shape(sid, px, rgb):
    w = px * 20
    nb = w.bit_length() + 1
    body = struct.pack('<H', sid) + rect_bytes(0, w, 0, w) + b'\x01\x00' + bytes(rgb) + b'\x00'
    b = '0001' + '0000' + '0' + '0' + '0' + '0' + '1' + '1' + '00001' + '0' + '0' + '1'
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        b += '1' + '1' + format(nb - 2, '04b') + '1' + format(dx & ((1 << nb) - 1), '0%db' % nb) + format(dy & ((1 << nb) - 1), '0%db' % nb)
    b += '000000'
    b += '0' * ((8 - len(b) % 8) % 8)
    return tag(2, body + int(b, 2).to_bytes(len(b) // 8, 'big'))

def call(target, method, *args):  # target.method(args...) ; result popped
    a = push(*reversed(args)) if args else b''
    return a + push(len(args), target) + GETVAR + push(method) + CALLM + POP

def setprop(target, prop, val):
    return push(target) + GETVAR + push(prop, val) + SETMEM

def draw_rect(t, rgb, w, h):
    return (call(t, 'beginFill', rgb) + call(t, 'moveTo', 0, 0) + call(t, 'lineTo', w, 0)
            + call(t, 'lineTo', w, h) + call(t, 'lineTo', 0, h) + call(t, 'lineTo', 0, 0) + call(t, 'endFill'))

def empty(name, depth):  # name = _root.createEmptyMovieClip(name, depth)
    return push(name, depth, name, 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLM + SETVAR

def attach(parent, sym, name, depth):
    return push(depth, name, sym, 3, parent) + GETVAR + push('attachMovie') + CALLM + POP

def sprite(cid, frames):
    return tag(39, struct.pack('<HH', cid, len(frames)) + b''.join(f + SHOW for f in frames) + tag(0, b''))

def place(depth, cid):
    return tag(26, bytes([0x02]) + struct.pack('<HH', depth, cid))

sq = sprite(3, [place(1, 1)])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('sq'))
cases = sys.argv[2] if len(sys.argv) > 2 else 'AC'
A = (empty('h', 2) + setprop('h', '_x', 20) + setprop('h', '_y', 20)
    + draw_rect('h', 0x0000ff, 200, 100) + attach('h', 'sq', 'c', 1))
B = (empty('d', 5) + setprop('d', '_x', 20) + setprop('d', '_y', 160)
    + draw_rect('d', 0x00ff00, 200, 100)
    + attach('_root', 'sq', 't', 6) + setprop('t', '_x', 60) + setprop('t', '_y', 180))
C = (attach('_root', 'sq', 'u', 7) + setprop('u', '_x', 260) + setprop('u', '_y', 20)
    + empty('e', 8) + setprop('e', '_x', 300) + setprop('e', '_y', 60)
    + draw_rect('e', 0x0000ff, 100, 100))
acts = b''.join({'A': A, 'B': B, 'C': C}[k] for k in cases) + push('drawn') + TRACE + STOP
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + square_shape(1, 100, (255, 0, 0))
        + sq + exp + tag(12, acts + b'\0') + SHOW + tag(0, b''))
hdr_rest = rect_bytes(0, 8000, 0, 6000) + struct.pack('<HH', 30 << 8, 1)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
