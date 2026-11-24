#!/usr/bin/env python3
"""avm1_exec_order_dynamic_eligible_mode: when does a clip created by a
script that runs AFTER the frame function (Phase-3 nested-sprite script /
stopped-root deferred _root.onEnterFrame / attach-init) first fire onEnterFrame?
swf.c (graphics) marked dynamic MCs eligible BEFORE that drain; swf_core.c after."""
import struct, sys
def tag(code, data):
    if len(data) < 63: return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data
def s(x): return x.encode() + b'\0'
def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str): b += b'\x00' + s(it)
        elif isinstance(it, int): b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b
GETVAR=b'\x1c'; SETVAR=b'\x1d'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'
STOP=b'\x07'; POP=b'\x17'; CALLM=b'\x52'; INC=b'\x50'; EQ2=b'\x49'; NOT=b'\x12'
def jif(off): return b'\x9d' + struct.pack('<Hh', 2, off)
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def doaction(a): return tag(12, a + b'\0')
def place(depth, cid, name): return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))
SHOW = tag(1, b'')
def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)
def tr_t(prefix):  # trace(prefix + _root.t)
    return push(prefix) + push('_root') + GETVAR + push('t') + GETMEM + ADD2 + TRACE
def create_with_ef(name, depth):
    # _root.createEmptyMovieClip(name, depth); _root[name].onEnterFrame = function(){trace(name+" ef t="+_root.t)}
    return (push(depth, name, 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLM + POP
            + push('_root') + GETVAR + push(name) + GETMEM + push('onEnterFrame')
            + deffunc(tr_t(name + ' ef t=')) + SETMEM)
def attach(lib, name, depth):
    return push(depth, name, lib, 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP
# inner (nested in outer): frame 2 script creates `e` (Phase-3 script)
inner = sprite(3, [doaction(tr_t('inner f1 t=')),
                   doaction(tr_t('inner f2 creates e t=') + create_with_ef('e', 6)),
                   doaction(tr_t('inner f3 t=')), doaction(tr_t('inner f4 t=') + STOP)])
outer = sprite(4, [place(1, 3, 'inner')])
# library clip `ai`: frame-1 (attach-init) script creates `g`
ai = sprite(5, [doaction(tr_t('ai f1 creates g t=') + create_with_ef('g', 9) + STOP)])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 5) + s('ai'))
# _root.onEnterFrame: t++; trace; if t==4 create d; if t==5 attach ai
def ifeq(n, body):
    cond = push('_root') + GETVAR + push('t') + GETMEM + push(n) + EQ2 + NOT
    return cond + jif(len(body)) + body
root_ef = (push('_root') + GETVAR + push('t') + push('_root') + GETVAR + push('t') + GETMEM + INC + SETMEM
           + tr_t('root ef t=') + ifeq(4, tr_t('root ef creates d t=') + create_with_ef('d', 7))
           + ifeq(6, tr_t('root ef attaches ai t=') + attach('ai', 'aiclip', 8)))
f1 = (place(1, 4, 'outer') + doaction(push('_root') + GETVAR + push('t', 0) + SETMEM + tr_t('root f1 t=')
      + push('_root') + GETVAR + push('onEnterFrame') + deffunc(root_ef) + SETMEM))
frames = [f1, doaction(tr_t('root f2 t=')), doaction(tr_t('root f3 stop t=') + STOP)]
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + inner + outer + ai + exp
        + b''.join(f + SHOW for f in frames) + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, len(frames))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
