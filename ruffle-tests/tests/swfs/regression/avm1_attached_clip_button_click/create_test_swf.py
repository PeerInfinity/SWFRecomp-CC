#!/usr/bin/env python3
"""avm1_attached_clip_button_click: a DefineButton2 inside an attachMovie'd clip
receives mouse events (rollOver / press / release / rollOut) from input.json.

Two attached copies of exported sprite `menu` (one placed button, `btn`):
  m  = _root.attachMovie("menu", "m", 1) at (50,50)          -> root-attached
  m2 = h.attachMovie("menu", "m2", 1) where
       h = _root.createEmptyMovieClip("h", 2) at (200,50)    -> attached under a dynamic clip
  m3 = c.attachMovie("menu", "m3", 1) where c is a TIMELINE-placed empty sprite
       at (50,180) scaled 50% x; m3._x = 100 -> button spans x 100..150 on stage
                                                              -> attached under a timeline clip
Each button's condition actions trace `this + " <event>"` (`this` = the clip the
button lives in). input.json hovers/clicks m, then m2, then leaves.

Before s26 (w1-attached-button-dispatch) the CI modes (NO_GRAPHICS and
OFFSCREEN_RENDER) only walked the root display_list in ng_update_button_states,
so buttons inside attached clips (standalone display_obj, child_mc_cache) never
fired; only browser-WASM ran ng_update_button_states_attached.

Expected output: hand-derived from Flash semantics; ORACLE PENDING (Ruffle test
runner with input.json, see session26 w1-attached-button-dispatch report).

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
SETVAR = b'\x1d'


def doaction(a):
    return tag(12, a + b'\0')


SHOW = tag(1, b'')

# DefineShape 1: 100x100 px solid square at (0,0) (bounds + 4 straight edges).
def square_shape(sid, px, rgb):
    w = px * 20
    nb = (w).bit_length() + 1
    bits = '{:05b}'.format(nb) + ''.join(format(v & ((1 << nb) - 1), '0%db' % nb) for v in (0, w, 0, w))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
    body = struct.pack('<H', sid) + rect + b'\x01\x00' + bytes(rgb) + b'\x00'
    b = '0001' + '0000'                    # NumFillBits=1, NumLineBits=0
    b += '0' + '00011' + '00001' + '0' + '0' + '1'   # style change: FillStyle0 + MoveTo(0,0) nbits=1
    # (TypeFlag 0, NewStyles 0, LineStyle 0, FillStyle1 0, FillStyle0 1, MoveTo 1)
    b = '0001' + '0000' + '0' + '0' + '0' + '0' + '1' + '1' + '00001' + '0' + '0' + '1'
    n2 = nb
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        b += '1' + '1' + format(n2 - 2, '04b') + '1' + format(dx & ((1 << n2) - 1), '0%db' % n2) + format(dy & ((1 << n2) - 1), '0%db' % n2)
    b += '000000'
    b += '0' * ((8 - len(b) % 8) % 8)
    body += int(b, 2).to_bytes(len(b) // 8, 'big')
    return tag(2, body)


def trace_this(label):  # trace(this + label)
    return push('this') + GETVAR + push(label) + ADD2 + TRACE


# BUTTONCONDACTION flags (first byte): 0x01 IdleToOverUp, 0x02 OverUpToIdle,
# 0x04 OverUpToOverDown, 0x08 OverDownToOverUp.
CONDS = [(0x01, ' rollOver'), (0x02, ' rollOut'), (0x04, ' press'), (0x08, ' release')]


def button2(bid, shape_id):
    rec = bytes([0x0f]) + struct.pack('<HH', shape_id, 1) + b'\x00' + b'\x00'  # all 4 states, identity matrix + cxform
    recs = rec + b'\x00'
    acts = b''
    for i, (flag, label) in enumerate(CONDS):
        a = trace_this(label) + b'\x00'
        body = bytes([flag, 0]) + a
        size = 0 if i == len(CONDS) - 1 else 2 + len(body)
        acts += struct.pack('<H', size) + body
    # ActionOffset counts from the ActionOffset field itself to the first BUTTONCONDACTION.
    return tag(34, struct.pack('<HB', bid, 0) + struct.pack('<H', 2 + len(recs)) + recs + acts)


def place(depth, cid, name):
    return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))


def place_scaled(depth, cid, name, sx, tx, ty):  # PlaceObject2 with scale+translate matrix
    bits = '1' + '{:05b}'.format(20) + format(int(sx * 65536), '020b') + format(65536, '020b')
    bits += '0' + '{:05b}'.format(14) + format(tx * 20, '014b') + format(ty * 20, '014b')
    bits += '0' * ((8 - len(bits) % 8) % 8)
    mtx = int(bits, 2).to_bytes(len(bits) // 8, 'big')
    return tag(26, bytes([0x02 | 0x04 | 0x20]) + struct.pack('<HH', depth, cid) + mtx + s(name))


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


menu = sprite(3, [place(1, 2, 'btn')])
container = sprite(4, [b''])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('menu'))


def setprop(target, prop, val):  # target.prop = val
    return push(target) + GETVAR + push(prop, val) + SETMEM


root_f1 = doaction(
    push(1, 'm', 'menu', 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP
    + setprop('m', '_x', 50) + setprop('m', '_y', 50)
    + push('h', 2, 'h', 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLM + SETVAR
    + setprop('h', '_x', 200) + setprop('h', '_y', 50)
    + push(1, 'm2', 'menu', 3, 'h') + GETVAR + push('attachMovie') + CALLM + POP
    + push(1, 'm3', 'menu', 3, 'c') + GETVAR + push('attachMovie') + CALLM + POP
    + setprop('c.m3', '_x', 100)
    + push('attached') + TRACE + STOP)
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + square_shape(1, 100, (255, 0, 0))
        + button2(2, 1) + menu + container + exp + place_scaled(10, 4, 'c', 0.5, 50, 180) + root_f1 + SHOW + tag(0, b''))
nb = 15
bits = '{:05b}'.format(nb) + ''.join('{:015b}'.format(v) for v in (0, 8000, 0, 6000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, 1)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
