#!/usr/bin/env python3
"""wasm probe attach_from_stopped_root_enterframe (s26 n-browser-pfx).

Browser-WASM twin of regression/avm1_attach_from_stopped_root_enterframe: a
STOPPED SWF6 root whose _root.onEnterFrame attachMovie's a 4-frame clip named
"pfx0" into a createEmptyMovieClip holder on its 2nd call; every pfx frame
traces, frame 4 removeMovieClip()s itself. Traces carry "PF:"; the handler
stops itself after c=8 so the browser trace is finite.

The NAME matters: browser-WASM used to flag attached "pfx*" clips
natural_oneshot (N's ParticleManager) and count them down outside the shared
attached-clip pump: no frame scripts, advanced a tick late and removed on wrap,
i.e. 2 ticks late (red: "root ef c=3 ... cf=1", no "pfx0 f2"). Named "p" it
passed before the fix. expected_trace.txt = Ruffle exporter --trace-log.

Rebuild: python3 create_test_swf.py test.swf && swfmill swf2xml test.swf test.xml
Variants (argv[2]): holder (default), root, holderloop / rootloop (2-frame
looping root), holdernostop (1-frame root without stop()).
"""
import struct, sys
def tag(code, data):
    if len(data) < 63: return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3f, len(data)) + data
def s(x): return x.encode() + b'\0'
def push(*items):
    b = b''
    for it in items:
        if isinstance(it, str): b += b'\x00' + s(it)
        else: b += b'\x07' + struct.pack('<i', it)
    return b'\x96' + struct.pack('<H', len(b)) + b
GETVAR=b'\x1c'; SETVAR=b'\x1d'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'
STOP=b'\x07'; POP=b'\x17'; CALLM=b'\x52'; TYPEOF=b'\x44'; EQ2=b'\x49'; NOT=b'\x12'
def iff(off): return b'\x9d' + struct.pack('<Hh', 2, off)
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def doaction(a): return tag(12, a + b'\0')
SHOW = tag(1, b'')
def sprite(cid, frames):
    return tag(39, struct.pack('<HH', cid, len(frames)) + b''.join(f + SHOW for f in frames) + tag(0, b''))
def tr_name(suffix):
    return push('PF: ') + push('this') + GETVAR + push('_name') + GETMEM + ADD2 + push(suffix) + ADD2 + TRACE
V = sys.argv[2] if len(sys.argv) > 2 else 'holder'
LOOP = 'loop' in V
NOSTOP = 'nostop' in V
V = V.replace('nostop','')
V = V.replace('loop','')
NF = 4
pf = [doaction(tr_name(' f%d' % i)) for i in range(1, NF)]
pf.append(doaction(tr_name(' f%d remove' % NF) + push(0, 'this') + GETVAR + push('removeMovieClip') + CALLM + POP))
pfx = sprite(3, pf)
exp = tag(56, struct.pack('<H', 1) + struct.pack('<H', 3) + s('pfx'))
def holder():  # _root.h or _root
    return push('_root') + GETVAR + (push('h') + GETMEM if V == 'holder' else b'')
attach = push(1, 'pfx0', 'pfx', 3) + holder() + push('attachMovie') + CALLM + POP
cnt = push('_root') + GETVAR + push('c') + GETMEM
stopef = push('PF: done') + TRACE + push('_root') + GETVAR + push('onEnterFrame', 0) + SETMEM
body = (push('_root') + GETVAR + push('c') + cnt + push(1) + ADD2 + SETMEM
        + cnt + push(2) + EQ2 + NOT + iff(len(attach)) + attach
        + push('PF: root ef c=') + cnt + ADD2 + push(' p=') + ADD2
        + holder() + push('pfx0') + GETMEM + TYPEOF + ADD2
        + push(' cf=') + ADD2 + holder() + push('pfx0') + GETMEM + push('_currentframe') + GETMEM + ADD2 + TRACE
        + cnt + push(8) + EQ2 + NOT + iff(len(stopef)) + stopef)
setup = (push('_root') + GETVAR + push('c', 0) + SETMEM
      + (push(5, 'h', 2, '_root') + GETVAR + push('createEmptyMovieClip') + CALLM + POP if V == 'holder' else b'')
      + push('_root') + GETVAR + push('onEnterFrame') + deffunc(body) + SETMEM + push('PF: root f1') + TRACE)
if LOOP:
    # if (_root.c == undefined) { setup }
    f1 = push('_root') + GETVAR + push('c') + GETMEM + TYPEOF + push('undefined') + EQ2 + NOT + iff(len(setup)) + setup
    frames = [doaction(f1), doaction(push('root f2') + TRACE)]
elif NOSTOP:
    frames = [doaction(setup)]
else:
    frames = [doaction(setup + STOP)]
bodyb = tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + pfx + exp + b''.join(f + SHOW for f in frames) + tag(0, b'')
bits = '{:05b}'.format(13) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
bits += '0' * ((8 - len(bits) % 8) % 8)
rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
hr = rect + struct.pack('<HH', 30 << 8, len(frames))
open(sys.argv[1], 'wb').write(b'FWS' + bytes([6]) + struct.pack('<I', 8 + len(hr) + len(bodyb)) + hr + bodyb)
