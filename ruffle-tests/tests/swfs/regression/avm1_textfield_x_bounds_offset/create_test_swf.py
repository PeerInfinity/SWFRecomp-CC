#!/usr/bin/env python3
"""avm1_textfield_x_bounds_offset: a TextField's _x/_y include its DefineEditText
bounds min (scaled): `_x = tx + xscale * bounds.xmin` (Ruffle edit_text.rs
`x()`/`bounds_x_offset`; Flash-verified by gnash misc-ming EmbeddedFontTest:
tf1 at tx=50 px with xmin=-2 px reads `_x == 48`, at xscale 16 `_x == 18`).
The setter subtracts the same offset.

Flash-IDE fields always carry xmin = ymin = -2 px (the 2 px gutter). The
s26 n-exec-order slice found N's HUD field (inside an attachMovie'd clip)
reading `_x` = 2 where Ruffle reads 0. Rows: a root-placed field, a
scaled root-placed field, the same field nested in a timeline-placed sprite,
and nested in an attachMovie'd copy of that sprite; then a setter round trip
on the attached one.

Expected output: Ruffle exporter (local build) --frames 3 trace.

Usage: create_test_swf.py <out.swf>
"""
import struct
import sys


def tag(code, data):
    if len(data) < 63:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data


def s(x):
    return x.encode() + b'\0'


def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str):
            b += b'\x00' + s(it)
        elif isinstance(it, int):
            b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b


GETVAR = b'\x1c'
GETMEM = b'\x4e'
SETMEM = b'\x4f'
ADD2 = b'\x47'
TRACE = b'\x26'
STOP = b'\x07'
POP = b'\x17'
CALLM = b'\x52'


def bits_signed(v, n):
    return '{:0{}b}'.format(v & ((1 << n) - 1), n)


def nbits(*vals):
    n = 1
    for v in vals:
        while not (-(1 << (n - 1)) <= v < (1 << (n - 1))):
            n += 1
    return n


def rect(x0, x1, y0, y1):
    n = nbits(x0, x1, y0, y1)
    b = '{:05b}'.format(n) + ''.join(bits_signed(v, n) for v in (x0, x1, y0, y1))
    b += '0' * ((8 - len(b) % 8) % 8)
    return int(b, 2).to_bytes(len(b) // 8, 'big')


def matrix(tx, ty, sx=None):
    b = ''
    if sx is not None:
        v = int(sx * 65536)
        n = nbits(v, 65536)
        b += '1' + '{:05b}'.format(n) + bits_signed(v, n) + bits_signed(65536, n)
    else:
        b += '0'
    b += '0'
    n = nbits(tx, ty)
    b += '{:05b}'.format(n) + bits_signed(tx, n) + bits_signed(ty, n)
    b += '0' * ((8 - len(b) % 8) % 8)
    return int(b, 2).to_bytes(len(b) // 8, 'big')


def place(depth, cid, name, mtx):
    return tag(26, bytes([0x02 | 0x04 | 0x20]) + struct.pack('<HH', depth, cid) + mtx + s(name))


def edittext(cid):  # IDE-style bounds: 2 px gutter on the min sides; no font/text
    return tag(37, struct.pack('<H', cid) + rect(-40, 2040, -40, 400) + struct.pack('<H', 0) + s(''))


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


def getpath(path):
    parts = path.split('.')
    b = push('_root') + GETVAR
    for p in parts:
        b += push(p) + GETMEM
    return b


def tr(path, prop):
    *obj, last = path.split('.')
    b = push(path + '.' + prop + '=') + getpath(path) + push(prop) + GETMEM + ADD2 + TRACE
    return b


def setp(path, prop, v):
    return getpath(path) + push(prop, v) + SETMEM


def attach(lib, name, depth):
    return push(depth, name, lib, 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP


holder = sprite(3, [place(1, 2, 'fld', matrix(200, 200))])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('holder'))
rows = b''
for p in ('f1', 'f2', 's.fld', 'h.fld'):
    rows += tr(p, '_x') + tr(p, '_y')
rows += setp('h.fld', '_x', 10) + tr('h.fld', '_x') + setp('f1', '_y', 7) + tr('f1', '_y')
frames = [place(1, 2, 'f1', matrix(1000, 600)) + place(2, 2, 'f2', matrix(1000, 2000, 2.0))
          + place(3, 3, 's', matrix(0, 4000))
          + tag(12, attach('holder', 'h', 10) + b'\0'),
          tag(12, rows + STOP + b'\0')]
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + edittext(2) + holder + exp
        + b''.join(f + SHOW for f in frames) + tag(0, b''))
hdr_rest = rect(0, 4000, 0, 3000) + struct.pack('<HH', 30 << 8, len(frames))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
