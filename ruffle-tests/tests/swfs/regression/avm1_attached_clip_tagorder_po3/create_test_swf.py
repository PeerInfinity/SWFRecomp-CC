#!/usr/bin/env python3
"""avm1_attached_clip_tagorder_po3: avm1_attached_clip_tagorder with every
place() emitted as PlaceObject3. tagPlaceObject3 delegates to tagPlaceObject2,
so this pins that the s24 tag-order attach init holds for PO3 too (s24
w2-attach-order-v8 measured it passing; landed as a fixture in s25).

Expected output: Ruffle exporter 0ddd12b6a --frames 8, byte-identical to
avm1_attached_clip_tagorder/output.txt
(SWFRecomp-CC-history:SWFRecompDocs/plans/session25-fanout-reports/w0-local-oracles/attach_tagorder_po3.ruffle-0ddd12b6a.txt).

Original fixture docstring follows.

avm1_attached_clip_tagorder: an attachMovie'd clip's frame-1 tags run in TAG
order on the attach tick -- a child placed BEFORE the clip's DoAction runs its
own frame 1 first.

Same clips as avm1_attached_clip_natural_timeline, with each attached clip's
frame 1 flipped to `PlaceObject(child); DoAction` (the s23 w2 attached-timeline
probe, `SWFRecomp-CC-history:SWFRecompDocs/plans/session23-fanout-reports/w2-attached-timeline-probe/make_probe_swf.py`,
md5 82368d06 for the root variant). Expected attach tick:
`kid anim f1, kid2 anim f1, s stopper f1, kid3 anim f1, m multi f1`.

Before s24 (w2-attach-order-v8) the CI modes ran the attached clip's own
DoAction first regardless of tag order: aq_dispatch_pending_attach_init replays
frame 1 in script-only mode (PlaceObject a no-op) and only afterwards
process_sprite_needs_init_public ran the children's frame 1. Now
ng_script_only_place (tag.c) runs a child's frame-1 init AT its PlaceObject
inside that replay. Browser-WASM's live attach arm is not covered (HOLD).

NON-ROOT variant (`_nonroot`): the clips are attached into a timeline-placed
container `c`.

Expected output: Ruffle exporter (local build, 0ddd12b6a) --frames 8 trace;
root and non-root variants are byte-identical in Ruffle
(SWFRecomp-CC-history:SWFRecompDocs/plans/session24-fanout-reports/w1-attach-order-oracle/).

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
    return tag(70, bytes([0x02|0x20, 0x00]) + struct.pack('<HH', depth, cid) + s(name))


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


HOST = 'c' if len(sys.argv) > 2 and sys.argv[2] == 'nonroot' else '_root'

anim = sprite(3, [doaction(trace_self(' anim f')) for _ in range(3)])
holder = sprite(2, [place(1, 3, 'kid')])  # 1-frame container, no script
stopper = sprite(4, [place(1, 3, 'kid2') + doaction(trace_self(' stopper f') + STOP)]
                 + [doaction(trace_self(' stopper f')) for _ in range(2)])
multi = sprite(5, [place(1, 3, 'kid3') + doaction(trace_self(' multi f'))]
               + [doaction(trace_self(' multi f')) for _ in range(2)])
container = sprite(6, [b''])  # only emitted for the non-root variant (oracle SWF bytes)
exp = tag(56, struct.pack('<H', 3) + struct.pack('<H', 2) + s('holder')
          + struct.pack('<H', 4) + s('stopper') + struct.pack('<H', 5) + s('multi'))


def attach(lib, name, depth):  # HOST.attachMovie(lib, name, depth); pop
    return push(depth, name, lib, 3, HOST) + GETVAR + push('attachMovie') + CALLM + POP


root_f1 = doaction(attach('holder', 'h', 1) + attach('stopper', 's', 2) + attach('multi', 'm', 3))
if HOST == 'c':
    root_f1 = place(10, 6, 'c') + root_f1
root_f2 = doaction(push('root f2') + TRACE)
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + anim + holder + stopper + multi
        + (container if HOST == 'c' else b'') + exp + root_f1 + SHOW + root_f2 + SHOW + doaction(STOP) + SHOW + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, 3)
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
