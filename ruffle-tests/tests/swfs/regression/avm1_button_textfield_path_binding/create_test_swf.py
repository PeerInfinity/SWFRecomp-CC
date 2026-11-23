#!/usr/bin/env python3
"""avm1_button_textfield_path_binding: binding scope of EditText variables that
live inside a DefineButton2 state (s26 w2-attached-holder-render).

Ruffle edit_text.rs try_bind_text_field_variable climbs from the field's
parent past every AVM1 button, then resolves the variable path from that clip
(resolve_variable_path(parent, path)). Sprite `s` (root depth 1) holds button
`b`, whose UP state holds three EditTexts with initial text:
  "_parent.pv" = "P"  -> resolved from s: _parent = _root  -> _root.pv = "P"
  "pv2"        = "Q"  -> simple name, binds on s           -> s.pv2 = "Q"
  "_root.av"   = "A"  -> absolute path                     -> _root.av = "A"
With no existing variable, the field's non-empty text seeds the variable.
Before s26 the path branch ran actionGetVariable in the CURRENT context (the
button clip during its state function), so "_parent.pv" landed on s.

Expected output: predicted from Ruffle's source; ORACLE REQUESTED (Ruffle
exporter --trace-log, w2-attached-holder-render report).

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
        b += b'\x00' + s(it)
    return b'\x96' + struct.pack('<H', len(b)) + b


GETVAR, ADD2, TRACE, STOP = b'\x1c', b'\x47', b'\x26', b'\x07'
SHOW = tag(1, b'')


def sbits(v, n):
    return format(v & ((1 << n) - 1), '0%db' % n)


def rect(x0, x1, y0, y1):
    nb = max(abs(v).bit_length() for v in (x0, x1, y0, y1)) + 1
    bits = '{:05b}'.format(nb) + ''.join(sbits(v, nb) for v in (x0, x1, y0, y1))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')


def matrix_ty(ty):
    ty *= 20
    nb = abs(ty).bit_length() + 1
    bits = '00' + '{:05b}'.format(nb) + sbits(0, nb) + sbits(ty, nb)
    bits += '0' * ((8 - len(bits) % 8) % 8)
    return int(bits, 2).to_bytes(len(bits) // 8, 'big')


def square_shape(sid, px):
    w = px * 20
    nb = w.bit_length() + 1
    body = struct.pack('<H', sid) + rect(0, w, 0, w) + b'\x01\x00\xff\x00\x00' + b'\x00'
    b = '0001' + '0000' + '0' + '0' + '0' + '0' + '1' + '1' + '00001' + '0' + '0' + '1'
    for dx, dy in ((w, 0), (0, w), (-w, 0), (0, -w)):
        b += '1' + '1' + format(nb - 2, '04b') + '1' + sbits(dx, nb) + sbits(dy, nb)
    b += '000000'
    b += '0' * ((8 - len(b) % 8) % 8)
    return tag(2, body + int(b, 2).to_bytes(len(b) // 8, 'big'))


def edit_text(cid, var, text):
    # HasText | ReadOnly; no font (device default), no layout.
    return tag(37, struct.pack('<H', cid) + rect(0, 2000, 0, 400) + bytes([0x80 | 0x08, 0x00])
               + s(var) + s(text))


def button2(bid, hit_shape, recs_up):
    recs = bytes([0x08]) + struct.pack('<HH', hit_shape, 1) + b'\x00' + b'\x00'   # HIT
    for depth, cid, ty in recs_up:                                                # UP
        recs += bytes([0x01]) + struct.pack('<HH', cid, depth + 1) + matrix_ty(ty) + b'\x00'
    recs += b'\x00'
    return tag(34, struct.pack('<HB', bid, 0) + struct.pack('<H', 0) + recs)


def trace_expr(label, var):  # trace(label + var)
    return push(label, var) + GETVAR + ADD2 + TRACE


defs = (square_shape(1, 100) + edit_text(2, '_parent.pv', 'P') + edit_text(3, 'pv2', 'Q')
        + edit_text(4, '_root.av', 'A')
        + button2(5, 1, [(1, 2, 0), (2, 3, 25), (3, 4, 50)]))
# sprite s: button `b` at depth 1
sprite_s = tag(39, struct.pack('<HH', 6, 1) + tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', 1, 5) + s('b'))
               + SHOW + tag(0, b''))
f1 = tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', 1, 6) + s('s')) + SHOW
f2 = tag(12, trace_expr('_root.pv=', '_root.pv') + trace_expr('s.pv=', 's.pv')
         + trace_expr('s.pv2=', 's.pv2') + trace_expr('_root.av=', '_root.av') + STOP + b'\0') + SHOW
body = tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + defs + sprite_s + f1 + f2 + tag(0, b'')
hdr_rest = rect(0, 8000, 0, 6000) + struct.pack('<HH', 30 << 8, 2)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
