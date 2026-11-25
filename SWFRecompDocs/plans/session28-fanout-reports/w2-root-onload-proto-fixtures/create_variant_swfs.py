#!/usr/bin/env python3
"""s28 w2-root-onload-proto: Flash-request variants for the `proto onLoad _global`
call (Flash 32 direct --no-pin printed it before `proto onLoad _level0` for
avm1_root_onload_proto). Same raw-bytes builder as w1-drift's create_test_swfs.py.
Usage: create_variant_swfs.py <out_dir>   (writes <variant>/test.swf, SWF8, 3 frames)
  v1_own_and_proto : f1 defines MovieClip.prototype.onLoad AND this.onLoad.
  v2_proto_in_f2   : MovieClip.prototype.onLoad defined in root f2 (after the root load event).
  v3_global_onload : f1 defines _global.onLoad only (no proto, no own).
  v4_this_probe    : f1 defines MovieClip.prototype.onLoad tracing typeof this, this == _global,
                     this._name, this._target, this._parent, this == _level0, this.__proto__ == MovieClip.prototype.
  v5_swf6          : avm1_root_onload_proto rebuilt as SWF6 (v8-only quirk?).
  v6_define_function2 : as avm1_root_onload_proto but the handler is DefineFunction2
                     (preload this into a register) instead of DefineFunction."""
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
        elif isinstance(it, tuple) and it[0] == 'reg': b += b'\x04' + bytes([it[1]])
    return b'\x96' + struct.pack('<H', len(b)) + b
GETVAR=b'\x1c'; SETMEM=b'\x4f'; GETMEM=b'\x4e'; ADD2=b'\x47'; TRACE=b'\x26'; STOP=b'\x07'
TYPEOF=b'\x44'; EQ2=b'\x49'
def deffunc(body):
    d = s('') + struct.pack('<H', 0) + struct.pack('<H', len(body))
    return b'\x9b' + struct.pack('<H', len(d)) + d + body
def deffunc2(body):  # DefineFunction2, 2 registers, PreloadThis -> r1
    d = s('') + struct.pack('<H', 0) + bytes([2]) + struct.pack('<H', 0x0001) + struct.pack('<H', len(body))
    return b'\x8e' + struct.pack('<H', len(d)) + d + body
def tr(msg): return push(msg) + TRACE
def tr_this(prefix): return push(prefix, 'this') + GETVAR + ADD2 + TRACE
def doaction(a): return tag(12, a + b'\0')
SHOW = tag(1, b'')
def sprite(cid, frames):
    body = b''.join(f + SHOW for f in frames) + tag(0, b'')
    return tag(39, struct.pack('<HH', cid, len(frames)) + body)
def place(depth, cid, name):
    return tag(26, bytes([0x22]) + struct.pack('<HH', depth, cid) + s(name))
def movie(path, frames, defs=b'', ver=8):
    body = (tag(69, struct.pack('<I', 0)) if ver >= 8 else b'') + tag(9, b'\xff\xff\xff') + defs \
        + b''.join(f + SHOW for f in frames) + tag(0, b'')
    nb = 13
    bits = '{:05b}'.format(nb) + ''.join('{:013b}'.format(v) for v in (0, 4000, 0, 3000))
    bits += '0' * ((8 - len(bits) % 8) % 8)
    rect = int(bits, 2).to_bytes(len(bits) // 8, 'big')
    hdr_rest = rect + struct.pack('<HH', 30 << 8, len(frames))
    total = 8 + len(hdr_rest) + len(body)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    open(path, 'wb').write(b'FWS' + bytes([ver]) + struct.pack('<I', total) + hdr_rest + body)
def set_proto_onload(fn): return push('MovieClip') + GETVAR + push('prototype') + GETMEM + push('onLoad') + fn + SETMEM
out = sys.argv[1]
kid = sprite(2, [doaction(tr_this('f1 of ')), doaction(STOP)])
f3 = doaction(tr('root f3 stop') + STOP)
f2 = place(2, 2, 'b') + doaction(tr('root f2'))
# v1
f1 = place(1, 2, 'a') + doaction(tr('root f1') + set_proto_onload(deffunc(tr_this('proto onLoad ')))
                                  + push('this') + GETVAR + push('onLoad') + deffunc(tr_this('own onLoad ')) + SETMEM)
movie(f'{out}/v1_own_and_proto/test.swf', [f1, f2, f3], kid)
# v2
f1 = place(1, 2, 'a') + doaction(tr('root f1'))
f2b = place(2, 2, 'b') + doaction(tr('root f2') + set_proto_onload(deffunc(tr_this('proto onLoad '))))
movie(f'{out}/v2_proto_in_f2/test.swf', [f1, f2b, f3], kid)
# v3
f1 = place(1, 2, 'a') + doaction(tr('root f1') + push('_global') + GETVAR + push('onLoad')
                                  + deffunc(tr_this('global onLoad ')) + SETMEM)
movie(f'{out}/v3_global_onload/test.swf', [f1, f2, f3], kid)
# v4
def probe_body():
    b = tr_this('proto onLoad ')
    b += push('typeof this = ', 'this') + GETVAR + TYPEOF + ADD2 + TRACE
    b += push('this == _global: ', 'this') + GETVAR + push('_global') + GETVAR + EQ2 + ADD2 + TRACE
    b += push('this == _level0: ', 'this') + GETVAR + push('_level0') + GETVAR + EQ2 + ADD2 + TRACE
    for p in ('_name', '_target', '_parent', '_url'):
        b += push('this.' + p + ' = ', 'this') + GETVAR + push(p) + GETMEM + ADD2 + TRACE
    b += push('proto ok: ', 'this') + GETVAR + push('__proto__') + GETMEM + push('MovieClip') + GETVAR \
         + push('prototype') + GETMEM + EQ2 + ADD2 + TRACE
    return b
f1 = place(1, 2, 'a') + doaction(tr('root f1') + set_proto_onload(deffunc(probe_body())))
movie(f'{out}/v4_this_probe/test.swf', [f1, f2, f3], kid)
# v5 (SWF6 copy of avm1_root_onload_proto)
f1 = place(1, 2, 'a') + doaction(tr('root f1') + set_proto_onload(deffunc(tr_this('proto onLoad '))))
movie(f'{out}/v5_swf6/test.swf', [f1, f2, f3], kid, ver=6)
# v6 (DefineFunction2, this preloaded into r1)
body2 = push('proto onLoad ', ('reg', 1)) + ADD2 + TRACE
f1 = place(1, 2, 'a') + doaction(tr('root f1') + set_proto_onload(deffunc2(body2)))
movie(f'{out}/v6_define_function2/test.swf', [f1, f2, f3], kid)
