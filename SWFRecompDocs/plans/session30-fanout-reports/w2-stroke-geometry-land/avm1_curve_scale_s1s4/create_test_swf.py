#!/usr/bin/env python3
"""AVM1 twin of the s30 w1-stroke-geometry FP32 probe `curve_scale_s1s4`
(SWF 8, hand-assembled DoAction; no AS compiler in the cloud).

Purpose (LOCAL ORACLE REQUEST, s30 w2-stroke-geometry-land): decide whether the
AVM1 drawing-API flattener (`action.c` drawingFinalizePath /
drawingCmdWindingHitTest, lyon 0.1 px) should follow the AVM2 one to 0.01 px at
HIGH. Same 16 cells as the AS3 probe: widths {4, 16} x scales {1, 4} x the two
acid-shapes squiggles x translation {0, .3}; colour 0x49D0D7 on black, stage
900x700, 1 frame. Each cell traces its placement exactly like the AS3 probe.

    python3 create_test_swf.py            # writes test.swf next to this file
"""
import struct, os

def rect_bits(xmin, xmax, ymin, ymax):
    vals = [xmin, xmax, ymin, ymax]
    nb = max(v.bit_length() for v in vals) + 1
    bits = format(nb, '05b') + ''.join(format(v & ((1 << nb) - 1), '0%db' % nb) for v in vals)
    bits += '0' * (-len(bits) % 8)
    return bytes(int(bits[i:i+8], 2) for i in range(0, len(bits), 8))

def tag(code, body):
    if len(body) < 63:
        return struct.pack('<H', (code << 6) | len(body)) + body
    return struct.pack('<HI', (code << 6) | 63, len(body)) + body

def push(*vals):
    b = b''
    for v in vals:
        if isinstance(v, str):
            b += b'\x00' + v.encode() + b'\x00'
        elif isinstance(v, int):
            b += b'\x07' + struct.pack('<i', v)
        else:
            b += b'\x06' + struct.pack('<d', v)[4:] + struct.pack('<d', v)[:4]
    return b'\x96' + struct.pack('<H', len(b)) + b

GETVAR, SETVAR, CALLMETHOD, POP, SETMEMBER, TRACE, ADD2 = b'\x1c', b'\x1d', b'\x52', b'\x17', b'\x4f', b'\x26', b'\x47'

def call(objvar, method, *args):
    # args pushed last-first, then argc, then object, then name
    return push(*reversed(args)) + push(len(args)) + push(objvar) + GETVAR + push(method) + CALLMETHOD + POP

def fmt(v):
    s = repr(float(v))
    return s[:-2] if s.endswith('.0') else s

acts = b''
x, y, rowH = 10.0, 10.0, 0.0
depth = 1
for w in (4, 16):
    for s in (1, 4):
        for k in (0, 1):
            for f in (0, 0.3):
                name = 'c%d' % depth
                acts += push(depth, name, 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLMETHOD + POP
                acts += push('m', '_root') + GETVAR + push(name) + b'\x4e' + SETVAR   # m = _root[name]
                acts += call('m', 'lineStyle', w, 0x49D0D7)
                acts += call('m', 'moveTo', 0, 0)
                if k == 0:
                    acts += call('m', 'curveTo', 20, 0, 20, 20)
                    acts += call('m', 'curveTo', 10, 30, 0, 20)
                else:
                    acts += call('m', 'curveTo', 10, 30, 20, 0)
                bw, bh = 24 * s + w * s, 32 * s + w * s
                if x + bw > 900 - 10:
                    x = 10.0; y += rowH + 6; rowH = 0.0
                px, py = x + w * s / 2 + f, y + w * s / 2 + f
                for prop, val in (('_xscale', s * 100), ('_yscale', s * 100), ('_x', px), ('_y', py)):
                    acts += push('m') + GETVAR + push(prop, float(val)) + SETMEMBER
                acts += push('w=%d s=%d k=%d f=%s at %s,%s' % (w, s, k, fmt(f), fmt(px), fmt(py))) + TRACE
                x += bw + 6
                if bh > rowH: rowH = bh
                depth += 1
acts += push('bottom %s' % fmt(y + rowH)) + TRACE
acts += b'\x00'

body = rect_bits(0, 900 * 20, 0, 700 * 20) + struct.pack('<HH', 30 << 8, 1)
body += tag(69, struct.pack('<I', 0))            # FileAttributes (AVM1, no network)
body += tag(9, b'\x00\x00\x00')                   # SetBackgroundColor black
body += tag(12, acts)                             # DoAction
body += tag(1, b'') + tag(0, b'')
swf = b'FWS' + bytes([8]) + struct.pack('<I', 8 + len(body)) + body
out = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'test.swf')
open(out, 'wb').write(swf)
print(out, len(swf))
