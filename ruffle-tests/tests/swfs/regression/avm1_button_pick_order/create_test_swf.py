#!/usr/bin/env python3
"""avm1_button_pick_order: which DefineButton2 wins the mouse pick, and the
order of rollOut/rollOver at a hand-off (s26 w2-attached-holder-render).

Pins down (Flash/Ruffle: one topmost interactive object; the OLD button's
rollOut fires before the NEW button's rollOver):
  1. An attachMovie'd clip `m` (AS depth 1 -> above every timeline depth)
     over a ROOT TIMELINE button `T` at the same place: `m`'s button wins,
     `T` never fires.
  2. Two attached clips at the same place, `lo` attached FIRST at depth 3,
     `hi` attached SECOND at depth 5: `hi` (higher depth) wins, although
     child_mc_cache holds `lo` first.
  3. A direct hand-off between two adjacent ROOT timeline buttons, `X`
     (depth 2) -> `Y` (depth 3; the top-down walk visits Y first): X rollOut
     must precede Y rollOver.
  4. A hand-off from an attached button (`hi`) to a timeline button (`X`).
Each button's condition actions trace `this + " <name> <event>"`.

Before s26 the CI modes walked the root display list first and the attached
clips in creation order, firing transitions as each button was visited.

Expected output: predicted from Flash/Ruffle semantics; ORACLE REQUESTED
(Ruffle test runner with input.json, w2-attached-holder-render report).

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


GETVAR, SETMEM, CALLM, POP, ADD2, TRACE, STOP = b'\x1c', b'\x4f', b'\x52', b'\x17', b'\x47', b'\x26', b'\x07'


def doaction(a):
    return tag(12, a + b'\0')


SHOW = tag(1, b'')


def sbits(v, n):
    return format(v & ((1 << n) - 1), '0%db' % n)


def matrix(tx, ty):  # translate-only MATRIX (pixels)
    tx, ty = tx * 20, ty * 20
    nb = max(abs(tx).bit_length(), abs(ty).bit_length()) + 1
    bits = '0' + '0' + '{:05b}'.format(nb) + sbits(tx, nb) + sbits(ty, nb)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')


def square_shape(sid, px, rgb):
    w = px * 20
    nb = (w).bit_length() + 1
    bits = '{:05b}'.format(nb) + ''.join(sbits(v, nb) for v in (0, w, 0, w))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
    body = struct.pack('<H', sid) + rect + b'\x01\x00' + bytes(rgb) + b'\x00'
    b = '0001' + '0000' + '0' + '0' + '0' + '0' + '1' + '1' + '00001' + '0' + '0' + '1'
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        b += '1' + '1' + format(nb - 2, '04b') + '1' + sbits(dx, nb) + sbits(dy, nb)
    b += '000000'
    b += '0' * ((8 - len(b) % 8) % 8)
    body += int(b, 2).to_bytes(len(b) // 8, 'big')
    return tag(2, body)


def trace_this(label):  # trace(this + label)
    return push('this') + GETVAR + push(label) + ADD2 + TRACE


CONDS = [(0x01, 'rollOver'), (0x02, 'rollOut'), (0x04, 'press'), (0x08, 'release')]


def button2(bid, shape_id, name):
    rec = bytes([0x0f]) + struct.pack('<HH', shape_id, 1) + b'\x00' + b'\x00'
    recs = rec + b'\x00'
    acts = b''
    for i, (flag, ev) in enumerate(CONDS):
        a = trace_this(' %s %s' % (name, ev)) + b'\x00'
        body = bytes([flag, 0]) + a
        size = 0 if i == len(CONDS) - 1 else 2 + len(body)
        acts += struct.pack('<H', size) + body
    return tag(34, struct.pack('<HB', bid, 0) + struct.pack('<H', 2 + len(recs)) + recs + acts)


def place(depth, cid):
    return tag(26, bytes([0x02]) + struct.pack('<HH', depth, cid))


def place_at(depth, cid, tx, ty):
    return tag(26, bytes([0x02 | 0x04]) + struct.pack('<HH', depth, cid) + matrix(tx, ty))


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


def setprop(target, prop, val):
    return push(target) + GETVAR + push(prop, val) + SETMEM


def attach(name, export, depth, x, y):
    return (push(depth, name, export, 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP
            + setprop(name, '_x', x) + setprop(name, '_y', y))


defs = square_shape(1, 100, (255, 0, 0))
# timeline buttons T, X, Y and the buttons inside exported sprites A, L, H
for bid, nm in ((10, 'T'), (11, 'X'), (12, 'Y'), (13, 'A'), (14, 'L'), (15, 'H')):
    defs += button2(bid, 1, nm)
for sid, bid in ((20, 13), (21, 14), (22, 15)):
    defs += sprite(sid, [place(1, bid)])
exports = [(20, 'A'), (21, 'L'), (22, 'H')]
defs += tag(56, struct.pack('<H', len(exports)) + b''.join(struct.pack('<H', c) + s(n) for c, n in exports))

root_f1 = (place_at(1, 10, 50, 50) + place_at(2, 11, 200, 50) + place_at(3, 12, 300, 50)
           + doaction(attach('m', 'A', 1, 50, 50)
                      + attach('lo', 'L', 3, 50, 180)
                      + attach('hi', 'H', 5, 50, 180)
                      + push('attached') + TRACE + STOP))
body = tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + defs + root_f1 + SHOW + tag(0, b'')
nb = 15
bits = '{:05b}'.format(nb) + ''.join('{:015b}'.format(v) for v in (0, 8000, 0, 6000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, 1)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
