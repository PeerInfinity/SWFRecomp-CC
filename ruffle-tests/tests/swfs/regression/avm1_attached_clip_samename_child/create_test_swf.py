#!/usr/bin/env python3
"""avm1_attached_clip_samename_child: a nested child of an attachMovie'd clip
that shares its instance name with a clip elsewhere must not hijack (or leave
dangling) that other clip's display object.

Pins (s26 n-pixel-pass, ASan-pinned heap-use-after-free on N's episode-select
menu): the attached-clip pump (tag.c ng_attached_run_tree) advanced a nested
playing child inside a temporary 2-entry display list; the in-advance
exec_sprite_frame resolved the child's instance name GLOBALLY and bound that
clip's display_obj to the temporary, which was then freed. Here the global
hit is the timeline-placed `_root.kid` (child `inner`), and the advancing
clip is `_root.h.kid` (3 frames, no children). Every root frame reads
`_root.kid.inner` through a slash path and a dot path plus `_root.kid`'s
_currentframe (the in-advance _currentframe sync also resolved by global
name, so it ticked the wrong clip), and the attached kid's frame scripts
trace their own _target and _currentframe.

Expected output: Ruffle exporter (local build) --frames 8 trace.

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
ADD2 = b'\x47'
TRACE = b'\x26'
STOP = b'\x07'
POP = b'\x17'
CALLM = b'\x52'


def doaction(a):
    return tag(12, a + b'\0')


def place(depth, cid, name):
    return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


def trace_target(label):  # trace(this._target + label + this._currentframe)
    return (push('this') + GETVAR + push('_target') + GETMEM + push(label) + ADD2
            + push('this') + GETVAR + push('_currentframe') + GETMEM + ADD2 + TRACE)


inner = sprite(9, [b''])
root_kid = sprite(8, [place(1, 9, 'inner')])          # timeline-placed _root.kid
anim = sprite(3, [doaction(trace_target(' f')) for _ in range(3)])  # attached h.kid
holder = sprite(2, [place(1, 3, 'kid')])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 2) + s('holder'))


def attach(lib, name, depth):
    return push(depth, name, lib, 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP


def probe(n):
    return (push('r' + str(n) + ' slash=') + push('/kid/inner:_name') + GETVAR + ADD2 + TRACE
            + push('r' + str(n) + ' dot=') + push('_root') + GETVAR + push('kid') + GETMEM
            + push('inner') + GETMEM + push('_target') + GETMEM + ADD2 + TRACE
            + push('r' + str(n) + ' hkid=') + push('_root') + GETVAR + push('h') + GETMEM
            + push('kid') + GETMEM + push('_target') + GETMEM + ADD2 + TRACE
            + push('r' + str(n) + ' kidcf=') + push('_root') + GETVAR + push('kid') + GETMEM
            + push('_currentframe') + GETMEM + ADD2 + TRACE)


frames = [place(5, 8, 'kid') + doaction(attach('holder', 'h', 10) + probe(1))]
for n in range(2, 7):
    frames.append(doaction(probe(n)))
frames.append(doaction(STOP))
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + inner + root_kid + anim + holder
        + exp + b''.join(f + SHOW for f in frames) + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, len(frames))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
