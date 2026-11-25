#!/usr/bin/env python3
"""s28 w1-drift: where does the INITIAL root's load event (_root.onLoad) sit
relative to frame-1 children's construct/load/frame-1 actions?
Ruffle fa93ad79f (2026-11-24) moved it to right after the root's own frame-1
actions; SWFRecomp fires it once at the end of the first tagShowFrame.
Usage: create_test_swfs.py <fixtures_dir>   (writes <variant>/test.swf)
  avm1_root_onload_child_order: root f1 places `kid` (onClipEvent load +
      construct + enterFrame), root f1 DoAction defines this.onLoad;
      kid f1/f2 DoActions trace.
  avm1_root_onload_proto: root f1 DoAction defines MovieClip.prototype.onLoad
      (no own root onLoad); `a` placed in f1, `b` placed in f2."""
import struct, sys, os
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
GETVAR=b'\x1c'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'; STOP=b'\x07'
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def tr(msg): return push(msg) + TRACE
def tr_this(prefix):  # trace(prefix + this)
    return push(prefix, 'this') + GETVAR + ADD2 + TRACE
def doaction(a): return tag(12, a + b'\0')
SHOW = tag(1, b'')
def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)
def place(depth, cid, name, clip_events=None):
    flags = 0x02 | 0x20 | (0x80 if clip_events else 0)
    d = bytes([flags]) + struct.pack('<HH', depth, cid) + s(name)
    if clip_events:
        allf = 0
        recs = b''
        for f, acts in clip_events:
            allf |= f
            a = acts + b'\0'
            recs += struct.pack('<II', f, len(a)) + a
        d += struct.pack('<HI', 0, allf) + recs + struct.pack('<I', 0)
    return tag(26, d)
EV_LOAD = 0x01; EV_EF = 0x02; EV_CONSTRUCT = 0x00040000  # byte2 bit 0x04
def movie(path, frames, defs=b''):
    body = (tag(69, struct.pack('<I', 0)) + tag(9, b'\xff\xff\xff') + defs
            + b''.join(f + SHOW for f in frames) + tag(0, b''))
    nb = 13
    bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
    hdr_rest = rect + struct.pack('<HH', 30 << 8, len(frames))
    total = 8 + len(hdr_rest) + len(body)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, 'wb').write(b'FWS' + bytes([8]) + struct.pack('<I', total) + hdr_rest + body)

out = sys.argv[1]
# --- variant A ---
kid = sprite(2, [doaction(tr('kid f1')), doaction(tr('kid f2') + STOP)])
kid_ev = [(EV_CONSTRUCT, tr('kid construct')), (EV_LOAD, tr('kid load')), (EV_EF, tr('kid enterFrame'))]
f1 = (place(1, 2, 'kid', kid_ev)
      + doaction(tr('root f1') + push('this') + GETVAR + push('onLoad') + deffunc(tr('root onLoad')) + SETMEM))
movie(f'{out}/avm1_root_onload_child_order/test.swf',
      [f1, doaction(tr('root f2')), doaction(tr('root f3 stop') + STOP)], kid)
# --- variant B ---
kid = sprite(2, [doaction(tr_this('f1 of ')), doaction(STOP)])
f1 = (place(1, 2, 'a')
      + doaction(tr('root f1') + push('MovieClip') + GETVAR + push('prototype') + GETMEM
                 + push('onLoad') + deffunc(tr_this('proto onLoad ')) + SETMEM))
f2 = place(2, 2, 'b') + doaction(tr('root f2'))
movie(f'{out}/avm1_root_onload_proto/test.swf', [f1, f2, doaction(tr('root f3 stop') + STOP)], kid)
