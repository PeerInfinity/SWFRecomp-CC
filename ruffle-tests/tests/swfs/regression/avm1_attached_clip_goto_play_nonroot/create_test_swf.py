#!/usr/bin/env python3
"""avm1_attached_clip_goto_play: an attachMovie'd clip that is gotoAndPlay'd
shows the target frame now and plays target+1 on the NEXT tick, forward and
backward, without skipping or wrapping.

Pins (session 24): sprite_current_frame is the NEXT frame to run for an
attached root as for every display-list entry. Before s24 the attached-clip
pump (ng_attached_run_tree) read it as the SHOWN frame while ng_gotoFrameByMC
wrote target+1, so after `a.gotoAndPlay(4)` the next tick ran frame 1 (wrap
from the second-to-last frame) and after `a.gotoAndPlay(2)` it skipped frame
3. Fixed by ng_record_attached_playable starting attached roots at 1 and the
pump dropping its shown<->next conversion.

`a` is a 5-frame clip tracing `a f<N>` on every frame, stop() on frame 5.
Root: f1 attaches; f2 a.gotoAndPlay(4); f4 a.gotoAndPlay(2); f6 stop().
NON-ROOT variant (`_nonroot`): `a` attached into a timeline-placed container
`c` (same Ruffle output).

Expected output: Ruffle exporter (local build) --frames 9 trace.

Usage: create_test_swf.py <out.swf> [nonroot]
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


def trace_self(label):
    return (push('this') + GETVAR + push('_name') + GETMEM + push(label) + ADD2
            + push('this') + GETVAR + push('_currentframe') + GETMEM + ADD2 + TRACE)


def doaction(a):
    return tag(12, a + b'\0')


def place(depth, cid, name):
    return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


HOST = 'c' if len(sys.argv) > 2 and sys.argv[2] == 'nonroot' else '_root'
TARGET = 'a' if HOST == '_root' else HOST + '.a'


def call(target, meth, *args):  # target.meth(args); pop
    parts = target.split('.')
    code = push(*reversed(args), len(args), parts[0]) + GETVAR
    for p in parts[1:]:
        code += push(p) + GETMEM
    return code + push(meth) + CALLM + POP


g = sprite(2, [doaction(trace_self(' f')) for _ in range(4)] + [doaction(trace_self(' f') + STOP)])
container = sprite(6, [b''])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 2) + s('g'))
root = [place(10, 6, 'c') + doaction(call(HOST, 'attachMovie', 'g', 'a', 1) + push('root f1') + TRACE),
        doaction(push('root f2 goto') + TRACE + call(TARGET, 'gotoAndPlay', 4)),
        doaction(push('root f3') + TRACE),
        doaction(push('root f4 back') + TRACE + call(TARGET, 'gotoAndPlay', 2)),
        doaction(push('root f5') + TRACE),
        doaction(push('root f6') + TRACE + STOP)]
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + g + container + exp
        + b''.join(f + SHOW for f in root) + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, len(root))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
