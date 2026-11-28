#!/usr/bin/env python3
"""avm1_exec_order_attached_selfremove (variant `root`) / parked `sibling` variant:
AVM1 per-clip exec order — each clip's
enterFrame runs immediately before ITS OWN frame script, clips newest-first,
_root last (Ruffle avm1/runtime.rs::run_frame + movie_clip.rs::run_frame_avm1).

Pins the s26 n-exec-order lead (N's spawn particles `pfx0..3` that
removeMovieClip themselves on their last frame were observed by N's
_root.onEnterFrame one tick late). Clips:
  - `tl`  timeline-placed 4-frame sprite (root frame 1, before any attach)
  - `a`   attachMovie'd 3-frame `pfx` at root frame 1; frame 3 self-removes
  - `b`   attachMovie'd 3-frame `pfx` at root frame 2 (newer than `a`)
Each clip has an onEnterFrame tracing `<name> ef`; every pfx frame traces
`<name> fN`; `tl` frames trace `tl fN`. _root.onEnterFrame traces whether
a/b still exist; root frames trace `root fN`.

Expected output: Ruffle exporter (local build) --frames 8 trace.

Variants (argv[2]):
  root     (default; this regression test) — ONE attached clip `a` + _root.
           Locks the landed s26 n-exec-order fix: _root's onEnterFrame runs
           AFTER the child's queued frame script (so it never observes `a` on
           the tick `a` removes itself). Red before the fix (`root ef a=movieclip`
           on the removal tick), green after.
  sibling  the full shape (tl + a + b). Still FAILS after the fix: ours runs
           every child enterFrame before any child frame script, and timeline
           sprites' scripts before attached clips'; Ruffle interleaves per clip,
           newest first. Parked (SWFRecomp-CC-history:SWFRecompDocs/plans/n-exec-order-report.md §2).

Usage: create_test_swf.py <out.swf> [root|sibling]
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
SETMEM = b'\x4f'
GETMEM = b'\x4e'
ADD2 = b'\x47'
TRACE = b'\x26'
STOP = b'\x07'
POP = b'\x17'
CALLM = b'\x52'
TYPEOF = b'\x44'


def deffunc(body):  # anonymous DefineFunction (type 1), no params
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body


def doaction(a):
    return tag(12, a + b'\0')


def place(depth, cid, name):
    return tag(26, bytes([0x02 | 0x20]) + struct.pack('<HH', depth, cid) + s(name))


SHOW = tag(1, b'')


def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)


def tr_name(suffix):  # trace(this._name + suffix)
    return push('this') + GETVAR + push('_name') + GETMEM + push(suffix) + ADD2 + TRACE


def set_ef(target_path):  # <target>.onEnterFrame = function(){ trace(this._name+" ef") }
    return (push('_root') + GETVAR + (push(target_path) + GETMEM if target_path else b'')
            + push('onEnterFrame') + deffunc(tr_name(' ef')) + SETMEM)


pfx = sprite(3, [doaction(tr_name(' f1')), doaction(tr_name(' f2')),
                 doaction(tr_name(' f3 remove') + push('this') + GETVAR
                          + push(0, 'this') + GETVAR + push('removeMovieClip') + CALLM + POP + POP)])
tl = sprite(4, [doaction(tr_name(' f%d' % i)) for i in range(1, 5)])
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('pfx'))


def attach(lib, name, depth):
    return push(depth, name, lib, 3, '_root') + GETVAR + push('attachMovie') + CALLM + POP


root_ef_body = (push('root ef a=') + push('_root') + GETVAR + push('a') + GETMEM + TYPEOF + ADD2
                + push(' b=') + ADD2 + push('_root') + GETVAR + push('b') + GETMEM + TYPEOF + ADD2
                + TRACE)


def root_frame(n):
    return push('root f%d' % n) + TRACE


VARIANT = sys.argv[2] if len(sys.argv) > 2 else 'root'
SIB = VARIANT == 'sibling'
frames = [(place(5, 4, 'tl') if SIB else b'')
          + doaction(root_frame(1) + attach('pfx', 'a', 10) + set_ef('a') + (set_ef('tl') if SIB else b'')
                     + push('_root') + GETVAR + push('onEnterFrame')
                     + deffunc(root_ef_body) + SETMEM)]
frames.append(doaction(root_frame(2) + (attach('pfx', 'b', 11) + set_ef('b') if SIB else b'')))
for n in range(3, 6):
    frames.append(doaction(root_frame(n)))
frames.append(doaction(root_frame(6) + STOP))
body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + pfx + tl
        + exp + b''.join(f + SHOW for f in frames) + tag(0, b''))
nb = 13
bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hdr_rest = rect + struct.pack('<HH', 30 << 8, len(frames))
total = 8 + len(hdr_rest) + len(body)
open(sys.argv[1], 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)
