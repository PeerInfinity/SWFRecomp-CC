#!/usr/bin/env python3
"""avm1_attached_clip_natural_timeline: attachMovie'd clips run their REAL
timeline (frame tags + DoActions + nested children) every tick, in Ruffle's
newest-first exec-list order with the root last.

Pins (session 24, browser follow-up of s23 w2-attached-timeline `3cdde8be0`):
  * a 1-frame attached container (`holder`) and a stopped one (`stopper`,
    frame 1 stop()s) still animate their children (`kid`, `kid2`);
  * a playing attached clip (`multi`) loops its own 3 frames and its child's;
  * per tick: kid3, m, kid2, kid, then the root's frame script;
  * NON-ROOT variant (`_nonroot`): the same clips attached into a
    timeline-placed container `c`. In the CI modes ng_attachMovie also
    registers such a clip in c's display list as a lookup/render alias; before
    s24 c's own timeline walk advanced that alias's children a second time per
    tick (kid f1 -> f3). The alias is now flagged `attach_registration` and
    skipped by the walks.

Every attached clip's frame 1 has its DoAction BEFORE the PlaceObject of its
child. Ruffle runs frame-1 actions in TAG order on the attach tick (child
first when the PlaceObject comes first: oracle-checked in s24); we run the
attached clip's own frame-1 DoAction first regardless. This order keeps the
attach tick graded without depending on that open difference
(SWFRecompDocs/plans/session23-fanout-reports/browser-attached-timeline-report.md).

Expected output: Ruffle exporter (local build) --frames 8 trace; root and
non-root variants are byte-identical in Ruffle.

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


def trace_self(label):  # trace(this._name + label + this._currentframe)
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

anim = sprite(3, [doaction(trace_self(' anim f')) for _ in range(3)])
holder = sprite(2, [place(1, 3, 'kid')])  # 1-frame container, no script
stopper = sprite(4, [doaction(trace_self(' stopper f') + STOP) + place(1, 3, 'kid2')]
                 + [doaction(trace_self(' stopper f')) for _ in range(2)])
multi = sprite(5, [doaction(trace_self(' multi f')) + place(1, 3, 'kid3')]
               + [doaction(trace_self(' multi f')) for _ in range(2)])
container = sprite(6, [b''])
exp = tag(56, struct.pack('<H', 3) + struct.pack('<H', 2) + s('holder')
          + struct.pack('<H', 4) + s('stopper') + struct.pack('<H', 5) + s('multi'))


def attach(lib, name, depth):  # HOST.attachMovie(lib, name, depth); pop
    return push(depth, name, lib, 3, HOST) + GETVAR + push('attachMovie') + CALLM + POP


root_f1 = doaction(attach('holder', 'h', 1) + attach('stopper', 's', 2) + attach('multi', 'm', 3))
if HOST == 'c':
    root_f1 = place(10, 6, 'c') + root_f1
root_f2 = doaction(push('root f2') + TRACE)
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + anim + holder + stopper + multi
        + container + exp + root_f1 + SHOW + root_f2 + SHOW + doaction(STOP) + SHOW + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, 3)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
